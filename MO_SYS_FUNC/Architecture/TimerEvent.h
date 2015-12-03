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
 *  File Name .............. TimerEvent.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TimerEvent is used for Timer Events (delayed Events)
 * ---------------------------------------------------------------------------
 */
#ifndef TIMEREVENT_H
#define TIMEREVENT_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "GlobalTypeDefs.h"
#include "GenericEvent.h"
#include "TinyChain.h"
#include "TinyPool.h"
#include "Win32_Time.h"
#include "TinyTrace.h"
#include "Win32_Timer.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The TimerEvent Structure */
struct TimerEvent;
typedef struct TimerEvent TimerEvent;

struct TimerEvent
{
/* The TinyPoolElement member for TimerEvent pool elements
   (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

/* The TinyChainElement member for the TimerEvent instance chain
   (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

/* The GenericEvent instance to be delivered. */
   const struct GenericEvent* timerEvent;

/* The data for the event to be delivered. */
   void* eventData;

/* The recipient of the event to be delivered.
   (set to IsCancelledEvent when cancelled or killed) */
   const void* recipient;

/* The TimerEvent delay time in milliseconds.
   (for update of remainingTime when recurring event fires) */
   unsigned long delayTime;

/* The remaining TimerEvent time in milliseconds. */
   unsigned long remainingTime;

/* Indication if the TimerEvent is to be recurring. */
   fastBool isRecurringEvent; 
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the TimerEvent.
   NOTE: This function must be invoked before any TimerEvents can be sent. */
void initialize_TimerEvent( void );

/* Function for shutting down the TimerEvent and active TimerEvent instances. */
void shutdown_TimerEvent( void );

/* TimerEvent control variable */
extern fastBool s_TimerEventIsInitialized;

/* TimerEvent execution state variable */
extern fastBool s_TimerEventIsRunning;

/* TimerEvent queue access semaphore */
extern fastBool s_TimerEventQueueIsAccessed;

/* OS timer ID for the TimerEvent dispatcher */
extern struct Win32_Timer s_OSTimer;

/* Label for direct access to the TimerEventPool instance chain
   (for registering newly created TimerEvent instances) */
extern struct TinyChain s_TimerEventInstances;

/* Label for direct access to the TimerEventPool pool
   (for seizing pre-allocated TimerEvent instances) */
extern struct TinyPool s_TimerEventPool;

/* System-level TimerEvent Dispatcher Function
   (called upon expiration of the OS timer) */
void TimerEvent_Dispatcher( void );

/* Function for creating a TimerEvent instance. */
__inlined__ struct TimerEvent* create_TimerEvent( const struct GenericEvent* timerEvent,
                                                  void* eventData,
                                                  const void* recipient,
                                                  unsigned long delayTime,
                                                  fastBool isRecurring );

/* Function for setting a new delay time for a TimerEvent instance. */
__inlined__ fastBool setNewDelayTime_TimerEvent( struct TimerEvent* self, unsigned long delayTime );

/* Function for adding additional delay time for a TimerEvent instance. */
__inlined__ fastBool addTime_TimerEvent( struct TimerEvent* self, unsigned long timeToAdd );

/* Function for retrieving the remaining time until a TimerEvent fires. */
__inlined__ unsigned long remainingTime_TimerEvent( const struct TimerEvent* self );

/* Function for cancelling a TimerEvent instance. */
__inlined__ fastBool cancel_TimerEvent( struct TimerEvent* self );

/* Function for killing all TimerEvent instances sent to a certain recipient.
   (this function is called when a recipient is deleted) */
void kill_TimerEvents( const void* recipient );

/* ---------------------------------------------------------------------------
 * Function for creating a TimerEvent instance.
 *
 * INPUT                DESCRIPTION
 * GenericEvent*        Pointer to the event instance.
 * void*                Pointer to the event data.
 * void*                The recipient of the event.
 * unsigned long        The delay time in microseconds.
 * boolean              Indication if the timer event is to be recurring.
 *
 * RETURNS              DESCRIPTION
 * TimerEvent*          Pointer to the created TimerEvent instance.
 *                      NULL is returned if an instance can not be created.
 * ---------------------------------------------------------------------------
 */
__inlined__ struct TimerEvent* create_TimerEvent( const struct GenericEvent* timerEvent,
                                                  void* eventData,
                                                  const void* recipient,
                                                  unsigned long delayTime,
                                                  fastBool isRecurring )
{
   /* Local variable declarations */
   struct TimerEvent* newInstance = NULL;

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

         /* Check that the TimerEvent is initialized  */
         if ( s_TimerEventIsInitialized )
         {
            /* Try to seize a TimerEvent instance in the pool */
            newInstance = (struct TimerEvent*) seizePoolElement( &s_TimerEventPool );

            /* Check if seizing a free pool element failed */
            if ( newInstance == NULL )
            {
               /* Trace output: Pool is exhausted */
               infoTrace_PoolIsExhausted( "TimerEvent", s_TimerEventPool.highWaterMark, "create_TimerEvent" );

               /* Allocate the TimerEvent instance on the heap */
               newInstance = (struct TimerEvent*) malloc( sizeof(struct TimerEvent) );

               /* Check if memory allocation was successful */
               if ( newInstance != NULL )
               {
                  /* Indicate TimerEvent instance heap allocation */
                  newInstance->poolElement.next     = NULL;
                  newInstance->poolElement.previous = NULL;
               }
               else
               {
                  /* Trace output: Pool is exhausted, malloc failed */
                  infoTrace_HeapAllocationFailed();
               }
            }

            /* Check if memory for the new instance was successfully allocated */
            if ( newInstance != NULL )
            {
               /* Set up this TimerEvent instance */
               newInstance->chainElement.element = newInstance;
               newInstance->timerEvent           = timerEvent;
               newInstance->eventData            = eventData;
               newInstance->recipient            = recipient;
               newInstance->delayTime            = ((delayTime + _TimerTimeRoundOff) / _TimerTimeDivisor);  /* Timer in ticks */
               newInstance->remainingTime        = newInstance->delayTime;
               newInstance->isRecurringEvent     = isRecurring;

               /* Check if this is a recurring event */
               if ( isRecurring )
               {
                  /* Check if the timer event has event data */
                  if ( eventData )
                  {
                     /* Indicate that this is a recurring event */
                     ((_OEDH_*) newInstance->eventData)->_header_.eventFlags |= (unsigned long) IsRecurringEvent;
                  }

                  /* Check if the number of ticks is greater than 0
                     (i.e. if the delay time not is a single timer tick) */
                  if ( newInstance->delayTime )
                  {
                     /* Decrease the number of ticks used for updating remainingTime
                        (one tick has passed the next time remainingTime is checked) */
                     newInstance->delayTime--;
                  }
               }

               /* Check if the timer event has event data */
               if ( eventData )
               {
                  /* Retrieve the current date and time */
                  retrieveCurrentDateAndTime();

                  /* Register the current time */
                  ((struct _EventDataHeader_*) eventData)->hour        = (unsigned short) getHour();
                  ((struct _EventDataHeader_*) eventData)->minute      = (unsigned short) getMinute();
                  ((struct _EventDataHeader_*) eventData)->second      = (unsigned short) getSecond();
                  ((struct _EventDataHeader_*) eventData)->millisecond = (unsigned short) getMillisecond();

                  /* Indicate that time information is available */
                  ((struct _EventDataHeader_*) eventData)->timeInformationAvailable = true;
               }

               /* Register the created instance in the TimerEvent instance chain
                  (by doing so - also indicate that the TimerEvent instance exists) */
               pushBackChain(&s_TimerEventInstances, &newInstance->chainElement);

               /* Check if the TimerEvent is _not_ running */
               if ( !s_TimerEventIsRunning )
               {
                  /* Start the periodic OS timer for the system-level TimerEvent dispatcher */
                  startPeriodicTimer( &s_OSTimer, _TimerTickInterval, TimerEvent_Dispatcher );

                  /* Indicate that the TimerEvent is running */
                  s_TimerEventIsRunning = true;
               }

            }

         }
         else
         {
            /* NOT POSSIBLE TO CREATE TIMER EVENT - DEALLOCATE MEMORY IF NEEDED */

            /* Check if the incoming event has event data */
            if ( eventData )
            {
               /* Release memory for the event data instance */
               returnEventDataMemory( eventData );
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

   /* Return the created TimerEvent instance
      (or return NULL if creation failed) */
   return newInstance;
}

/* ---------------------------------------------------------------------------
 * Function for setting a new delay time for a TimerEvent instance.
 *
 * INPUT                DESCRIPTION
 * TimerEvent*          Pointer to the TimerEvent instance.
 * unsigned long        The new delay time in microseconds.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the TimerEvent instance exists.
 * ---------------------------------------------------------------------------
 */
__inlined__ fastBool setNewDelayTime_TimerEvent( struct TimerEvent* self, unsigned long delayTime )
{
   /* Local variable declarations */
   fastBool instanceExists = false;

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

         /* Check if the TimerEvent instance exists in the instance chain */
         if ( self->chainElement.element != NULL )
         {
            /* Check that this timer event not is cancelled */
            if ( self->recipient != IsCancelledEvent )
            {
               /* Set the new delay time for this TimerEvent instance */
               self->delayTime     = ((delayTime + _TimerTimeRoundOff) / _TimerTimeDivisor);  /* Timer in ticks */
               self->remainingTime = self->delayTime;

               /* Indicate that this TimerEvent instance exists */
               instanceExists = true;
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

   return instanceExists;
}

/* ---------------------------------------------------------------------------
 * Function for adding additional delay time for a TimerEvent instance.
 *
 * INPUT                DESCRIPTION
 * TimerEvent*          Pointer to the TimerEvent instance.
 * unsigned long        The additional delay time in microseconds.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the TimerEvent instance exists.
 * ---------------------------------------------------------------------------
 */
__inlined__ fastBool addTime_TimerEvent( struct TimerEvent* self, unsigned long timeToAdd )
{
   /* Local variable declarations */
   fastBool instanceExists = false;

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

         /* Check if the TimerEvent instance exists in the instance chain */
         if ( self->chainElement.element != NULL )
         {
            /* Check that this timer event not is cancelled */
            if ( self->recipient != IsCancelledEvent )
            {
               /* Set the new delay time for this TimerEvent instance */
               self->delayTime     += ((timeToAdd + _TimerTimeRoundOff) / _TimerTimeDivisor);  /* Timer in ticks */
               self->remainingTime += ((timeToAdd + _TimerTimeRoundOff) / _TimerTimeDivisor);  /* Timer in ticks */

               /* Indicate that this TimerEvent instance exists */
               instanceExists = true;
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

   return instanceExists;
}

/* ---------------------------------------------------------------------------
 * Function for retrieving the remaining time until a TimerEvent fires.
 *
 * INPUT                DESCRIPTION
 * TimerEvent*          Pointer to the TimerEvent instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        Remaining time in microseconds until the event fires.
 *                      0 is returned if the TimerEvent does not exist.
 * ---------------------------------------------------------------------------
 */
__inlined__ unsigned long remainingTime_TimerEvent( const struct TimerEvent* self )
{
   /* Local variable declarations */
   unsigned long remainingTime = 0;

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

         /* Check if the TimerEvent instance exists in the instance chain */
         if ( self->chainElement.element != NULL )
         {
            /* Get the remaining time until the TimerEvent fires */
            remainingTime = (self->remainingTime * _TimerTimeDivisor);  /* Time in microseconds */
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

   return remainingTime;
}

/* ---------------------------------------------------------------------------
 * Function for cancelling a TimerEvent instance.
 *
 * INPUT                DESCRIPTION
 * TimerEvent*          Pointer to the TimerEvent instance.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the TimerEvent instance exists.
 * ---------------------------------------------------------------------------
 */
__inlined__ fastBool cancel_TimerEvent( struct TimerEvent* self )
{
   /* Local variable declarations */
   fastBool instanceExists = false;

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

         /* Check if the TimerEvent instance exists in the instance chain */
         if ( self->chainElement.element != NULL )
         {
            /* Check that this timer event not already is cancelled */
            if ( self->recipient != IsCancelledEvent )
            {
               /* Check if the timer event has event data */
               if ( self->eventData )
               {
                  /* Indicate that this event is no longer a recurring event
                     (for the case that the event _is_ a recurring event) */
                  ((_OEDH_*) self->eventData)->_header_.eventFlags &= (unsigned long) IsRecurringEvent_clear;
               }

               /* Indicate that this timer event is cancelled */
               self->recipient = IsCancelledEvent;

               /* Set the remaining time for the cancelled TimerEvent to zero,
                  thus making it fire immediately (or as soon as possible) */
               self->remainingTime = 0;

               /* Indicate that the cancelled TimerEvent no longer is recurring
                  (for the case that the TimerEvent _is_ a recurring event)
                  thus making sure that it is removed from the TimerEvent
                  instance chain when it fires (= no longer exists) */
               self->isRecurringEvent = false;

               /* Indicate that this TimerEvent instance exists */
               instanceExists = true;
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

   /* Return indication if the TimerEvent to cancel really exists */
   return instanceExists;
}

#ifdef __cplusplus
}
#endif

#endif /* TIMEREVENT_H */
