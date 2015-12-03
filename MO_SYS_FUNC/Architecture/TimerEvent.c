/*  **************************************************************************
 *  **************************************************************************
 *  ***                                                                    ***
 *  ***            tt    UU    UU  MM    MM  LL                  CCCCCC    ***
 *  ***            tt    UU    UU  MMM  MMM  LL          >>     CCCCCCCC   ***
 *  ***   xx  xx  ttttt  UU    UU  MMMMMMMM  LL           >>>   CC    CC   ***
 *  ***   xx  xx  ttttt  UU    UU  MM MM MM  LL       >>>>>>>>  CC         ***
 *  ***     xx     tt    UU    UU  MM    MM  LL       >>>>>>>>  CC         ***
 *  ***     xx     tt    UU    UU  MM    MM  LL           >>>   CC    CC   ***
 *  ***   xx  xx   tttt  UUUUUUUU  MM    MM  LLLLLLLL    >>     CCCCCCCC   ***
 *  ***   xx  xx    ttt   UUUUUU   MM    MM  LLLLLLLL            CCCCCC    ***
 *  ***                                                                    ***
 *  **************************************************************************
 *  **************************************************************************
 *
 *  Do not edit this auto-generated file. This code has been generated for the
 *  Executable UML System Function "MO_SYS_FUNC" using BridgePoint & TinyC.
 *
 *
 *  File Name .............. TimerEvent.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TimerEvent.h"
#include "TinyQueue.h"
#include "ArchitectureConfig.h"
#include "TinySchedule.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* TimerEvent control variable */
fastBool s_TimerEventIsInitialized = false;

/* TimerEvent execution state variable */
fastBool s_TimerEventIsRunning = false;

/* TimerEvent queue access semaphore */
fastBool s_TimerEventQueueIsAccessed = false;

/* OS timer ID for the TimerEvent dispatcher */
struct Win32_Timer s_OSTimer = { 0, 0, NULL };

/* Initialize the chain holding all existing instances of TimerEvent */
struct TinyChain s_TimerEventInstances = {NULL, NULL, 0};

/* The TimerEvent pool */
static struct TimerEvent s_TimerEvents[_TimerEventPoolSize];
struct TinyPool s_TimerEventPool = {NULL, 0, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * Function for initializing the TimerEvent.
 * NOTE: This function must be invoked before any TimerEvents can be sent.
 * ---------------------------------------------------------------------------
 */
void initialize_TimerEvent( void )
{
   /* The TimerEvent is not yet initialized */
   s_TimerEventIsInitialized = false;

   /* The TimerEvent is not yet running */
   s_TimerEventIsRunning = false;

   /* The TimerEvent queue is not yet being accessed */
   s_TimerEventQueueIsAccessed = false;

   /* No OS timer defined for the TimerEvent dispatcher yet */
   s_OSTimer.theTimerID          = 0;
   s_OSTimer.theDelayTime        = 0;
   s_OSTimer.theCallbackFunction = NULL;

   /* Initialize the TimerEvent instance chain */
   s_TimerEventInstances.firstElement     = NULL;
   s_TimerEventInstances.lastElement      = NULL;
   s_TimerEventInstances.numberOfElements = 0;

   /* Initialize the TimerEvent pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_TimerEvents[_TimerEventPoolSize - 1].poolElement;
      for (index = 0; index < _TimerEventPoolSize; index++)
      {
         theElement            = &s_TimerEvents[index].poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      s_TimerEventPool.firstFreeElement      = &s_TimerEvents[0].poolElement;
      s_TimerEventPool.numberOfFreeElements  = _TimerEventPoolSize;
      s_TimerEventPool.theCapacity           = _TimerEventPoolSize;
      s_TimerEventPool.numberOfUsedElements  = 0;
      s_TimerEventPool.highWaterMark         = 0;
   }

   /* Indicate that the TimerEvent is initialized */
   s_TimerEventIsInitialized = true;
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the TimerEvent and active TimerEvent instances
 * ---------------------------------------------------------------------------
 */
void shutdown_TimerEvent( void )
{
   /* Check if the TimerEvent is running */
   if ( s_TimerEventIsRunning )
   {
      /* Stop the periodic OS timer for the system-level TimerEvent dispatcher */
      stopPeriodicTimer( &s_OSTimer );

      /* Indicate that the TimerEvent no longer is running */
      s_TimerEventIsRunning = false;
   }

   /* NOTE: Must we delete all TimerEvent instances and
            deliver all events to the target state machines ???
      (remove all 'IsRecurringEvent' indications: eventFlags &= IsRecurringEvent_clear ???)
      (remove all 'isRecurringEvent' indications: isRecurringEvent = false ???) */
}

/* ---------------------------------------------------------------------------
 * System-level TimerEvent Dispatcher Function
 * (called upon expiration of the OS timer)
 * ---------------------------------------------------------------------------
 */
void TimerEvent_Dispatcher( void )
{
   /************************************************************************
    *** NOTE: Entering this dispatcher if a TimerEvent operation         ***
    *** has been interrupted by this high priority thread may lead       ***
    *** to a corruption of the TimerEvent queue.                         ***
    ***                                                                  ***
    *** If a TimerEvent operation is interrupted by this timer thread    ***
    *** (as indicated by semaphore) the dispatcher is __not__ entered.   ***
    ***                                                                  ***
    *** The result is that all active TimerEvents (delayed or periodic)  ***
    *** are delayed one extra timer tick period. This is a resonable     ***
    *** price to pay for this 'guard' that prevents deadlocks and        ***
    *** prevents corruption of the TimerEvent queue without any          ***
    *** additional performance costs.                                    ***
    ***                                                                  ***
    *** The TimerEvents are delivered just a little later, which         ***
    *** may not even be noticed in a system executing perhaps            ***
    *** hundreds of threads.                                             ***
    ************************************************************************/

   /* CHECK THAT A TimerEvent OPERATION NOT IS BEING INTERRUPTED */
   if ( !s_TimerEventQueueIsAccessed )
   {
      /* Declaration of local dispatcher variables */
      struct TinyChainElement* nextIterationElement;
      const struct GenericEvent* theEvent;
      struct TimerEvent* theTimerEvent;
      unsigned long chainIndex;
      void* theEventData;
      const void* theRecipient;

      /* Indicate that the TimerEvent queue is being accessed */
      s_TimerEventQueueIsAccessed = true;

      /* ITERATE THE TIMER EVENT INSTANCE CHAIN */
      nextIterationElement = s_TimerEventInstances.firstElement;
      for (chainIndex = 0; chainIndex < s_TimerEventInstances.numberOfElements; chainIndex++)
      {
         /* Get the next TimerEvent in the chain */
         theTimerEvent = (struct TimerEvent*) nextIterationElement->element;

         /* ...and prepare for the next iteration */
         nextIterationElement = nextIterationElement->next;

         /* Check if this TimerEvent still is "in flight" (time > 0) */
         if ( (theTimerEvent->remainingTime) )
         {
            /* Decrease the time left until this TimerEvent fires */
            theTimerEvent->remainingTime--;

            /* Continue with next iteration of the loop */
            continue;
         }
         else
         {

            /******************************************
             *** IT'S TIME TO FIRE THIS TIMER EVENT ***
             ******************************************/

            /* Get the event instance to be delivered */
            theEvent     = theTimerEvent->timerEvent;
            theEventData = theTimerEvent->eventData;
            theRecipient = theTimerEvent->recipient;

            /****************************************************************
             *** NOTE: Delivering the TimerEvent to the target            ***
             *** eventTaker if access of the target event queue in a      ***
             *** lower priority thread has been interrupted by this       ***
             *** high prioroty thread may lead to a corruption of the     ***
             *** target event queue.                                      ***
             ***                                                          ***
             *** If access of the target event queue is interrupted by    ***
             *** this timer thread, the TimerEvent is __not__ delivered.  ***
             ***                                                          ***
             *** The result is that the TimerEvent (delayed or periodic)  ***
             *** to deliver is delayed one extra timer tick period.       ***
             *** This is a resonable price to pay for this 'guard' that   ***
             *** prevents deadlocks and prevents corruption of the target ***
             *** event queue without any additional performance costs.    ***
             ***                                                          ***
             *** The TimerEvent is delivered just a little later, which   ***
             *** may not even be noticed in a system executing perhaps    ***
             *** hundreds of threads.                                     ***
             ****************************************************************/

            /* CHECK THAT THE TARGET EVENT QUEUE NOT IS BEING ACCESSED
               If the target event queue is accessed the delivery of
               this TimerEvent is postponed to the next timer tick.
               (The 'remainingTime' for the TimerEvent already is = 0.) */
            if ( !(*theEvent->queueIsAccessed) )
            {

               /************************************************************
                *** NOTE: The same discussion as above regarding the     ***
                *** protection of the target event queue is also valid   ***
                *** for the protection of the scheduling request queue   ***
                *** for the System-Level Dispatcher.                     ***
                ***                                                      ***
                *** If access of the scheduling request queue is         ***
                *** interrupted by this timer thread, the TimerEvent     ***
                *** is __not__ delivered.                                ***
                ***                                                      ***
                *** THIS IS ONLY APPLICABLE FOR SYSTEM FUNCTIONS WHERE   ***
                *** THE SYSTEM-LEVEL DISPATCHER IS NEEDED AND GENERATED. ***
                ************************************************************/

               /* CHECK THAT THE SCHEDULING REQUEST QUEUE NOT IS BEING ACCESSED
                  If the scheduling request queue is accessed the delivery of
                  this TimerEvent is postponed to the next timer tick.
                  (The 'remainingTime' for the TimerEvent already is = 0.) */
               if ( !schedulingRequestQueueIsAccessed )
               {

                  /********************************************************
                   *** NOTE: The same discussion as above is also valid ***
                   *** for the protection of the TinyQueueElement pool. ***
                   ***                                                  ***
                   *** If access of the TinyQueueElement pool is        ***
                   *** interrupted by this timer thread, the            ***
                   *** TimerEvent is __not__ delivered.                 ***
                   ********************************************************/

                  /* CHECK THAT THE TINY QUEUE ELEMENT POOL NOT IS BEING ACCESSED
                     If the TinyQueueElement pool is accessed the delivery of
                     this TimerEvent is postponed to the next timer tick.
                     (The 'remainingTime' for the TimerEvent already is = 0.) */
                  if ( !tinyQueueElementPoolIsAccessed )
                  {

                     /* Check if this is a recurring TimerEvent */
                     if ( theTimerEvent->isRecurringEvent )
                     {
                        /* Check if the event has data */
                        if ( theEventData )
                        {
                           /* Retrieve the current date and time */
                           retrieveCurrentDateAndTime();

                           /* Register the current time */
                           ((struct _EventDataHeader_*) theEventData)->hour        = (unsigned short) getHour();
                           ((struct _EventDataHeader_*) theEventData)->minute      = (unsigned short) getMinute();
                           ((struct _EventDataHeader_*) theEventData)->second      = (unsigned short) getSecond();
                           ((struct _EventDataHeader_*) theEventData)->millisecond = (unsigned short) getMillisecond();
                        }
                     }

                     /* CHECK IF THIS TIMER EVENT IS CANCELLED */
                     if ( theRecipient == IsCancelledEvent )
                     {
                        /* Check if the timer event has event data memory that must be released
                           (otherwise the timer event will simply vanish into binary space) */
                        if ( theEventData )
                        {
                           /* Deliver the cancelled TimerEvent for memory deallocation */
                           theEvent->theEventTaker( theEvent, theEventData, theRecipient );
                        }
                     }
                     else
                     {
                        /* Deliver the TimerEvent */
                        theEvent->theEventTaker( theEvent, theEventData, theRecipient );
                     }

                     /* Check if this is a recurring TimerEvent */
                     if ( theTimerEvent->isRecurringEvent )
                     {
                        /* THIS IS A RECURRING TIMER EVENT */

                        /* Reset the TimerEvent delay time */
                        theTimerEvent->remainingTime = theTimerEvent->delayTime;
                     }
                     else
                     {
                        /* THIS IS A SINGLE-SHOT TIMER EVENT
                           (or a cancelled recurring event) */

                        /* Remove the TimerEvent from the TimerEvent instance chain */
                        removeChainElement(&s_TimerEventInstances, &theTimerEvent->chainElement);

                        /* Indicate that the TimerEvent instance no longer is present in a chain */
                        theTimerEvent->chainElement.element = NULL;

                        /* Release memory for the TimerEvent instance */
                        if (( theTimerEvent->poolElement.next     == NULL ) &&
                            ( theTimerEvent->poolElement.previous == NULL ))
                        {
                           /* The TimerEvent instance is allocated on the heap */
                           free( theTimerEvent );

                           /* Decrease the number of used instances of pool-element-type.
                              (memory is returned to where it was previously allocated) */
                           s_TimerEventPool.numberOfUsedElements--;
                        }
                        else
                        {
                           /* The TimerEvent instance is allocated in the pool */
                           returnPoolElement( &s_TimerEventPool, &theTimerEvent->poolElement );
                        }

                        /* Check if this was the last active TimerEvent */
                        if ( s_TimerEventInstances.numberOfElements == 0 )
                        {
                           /* Stop the periodic OS timer for the system-level TimerEvent dispatcher */
                           stopPeriodicTimer( &s_OSTimer );

                           /* Indicate that the TimerEvent no longer is running */
                           s_TimerEventIsRunning = false;
                        }
                     }

                  }

               }

            }

         }
      }

      /* Indicate that the TimerEvent queue no longer is accessed */
      s_TimerEventQueueIsAccessed = false;
   }
}

/* ---------------------------------------------------------------------------
 * Function for killing all TimerEvent instances sent to a certain recipient.
 * (this function is called when a recipient is deleted)
 *
 * INPUT                DESCRIPTION
 * void*                Pointer to the recipient instance of the TimerEvents.
 * ---------------------------------------------------------------------------
 */
void kill_TimerEvents( const void* recipient )
{
   /* Local variable declarations */
   struct TinyChainElement* nextIterationElement;
   unsigned long chainIndex;
   struct TimerEvent* theTimerEvent;

   /* Set up the TimerEvent queue access loop counter */
   unsigned int queueAccessLoopCounter = 2;

   /* Continue until the TimerEvent operation has been completed */
   do
   {

      /* Check that a TimerEvent operation _not_ is being accessed by another thread */
      if ( !s_TimerEventQueueIsAccessed )
      {
         /* Indicate that the TimerEvent queue is being accessed */
         s_TimerEventQueueIsAccessed = true;

         /* ITERATE THE TIMER EVENT INSTANCE CHAIN */
         nextIterationElement = s_TimerEventInstances.firstElement;
         for (chainIndex = 0; chainIndex < s_TimerEventInstances.numberOfElements; chainIndex++)
         {
            /* Get the next TimerEvent in the chain */
            theTimerEvent = (struct TimerEvent*) nextIterationElement->element;

            /* ...and prepare for the next iteration */
            nextIterationElement = nextIterationElement->next;

            /* Check if this TimerEvent is to be killed */
            if ( theTimerEvent->recipient == recipient )
            {
               /* Check that this timer event not already is cancelled */
               if ( theTimerEvent->recipient != IsCancelledEvent )
               {
                  /* Check if the timer event has event data */
                  if ( theTimerEvent->eventData )
                  {
                     /* Indicate that this event is no longer a recurring event
                        (for the case that the event _is_ a recurring event) */
                     ((_OEDH_*) theTimerEvent->eventData)->_header_.eventFlags &= (unsigned long) IsRecurringEvent_clear;
                  }

                  /* Indicate that this timer event is cancelled */
                  theTimerEvent->recipient = IsCancelledEvent;

                  /* Set the remaining time for the cancelled TimerEvent to zero,
                     thus making it fire immediately (or as soon as possible) */
                  theTimerEvent->remainingTime = 0;

                  /* Indicate that the cancelled TimerEvent no longer is recurring
                     (for the case that the TimerEvent _is_ a recurring event)
                     thus making sure that it is removed from the TimerEvent
                     instance chain when it fires (= no longer exists) */
                  theTimerEvent->isRecurringEvent = false;
               }
            }
         }

         /* Indicate that the TimerEvent queue no longer is accessed */
         s_TimerEventQueueIsAccessed = false;

         /* TimerEvent operation completed - Break out */
         break;
      }
      else
      {
         /* Decrement the TimerEvent queue access loop counter */
         queueAccessLoopCounter--;

         /* A TimerEvent operation is perhaps being accessed by another thread
            that executes at a lower priority level than the current thread
            (do not yield a higher prio thread more than once) */
         if ( queueAccessLoopCounter )
         {
            /* Give processing time to other threads on same prio level (yield) */
            yieldThread();
         }
         else
         {
            /* Suspend execution for a short period of time */
            sleepThread( 1 );

            /* Reset the TimerEvent queue access loop counter */
            queueAccessLoopCounter = 2;
         }
      }

   } while (true);

}

/* ### End of file TimerEvent.c ### */
