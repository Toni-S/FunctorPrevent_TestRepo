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
 *  File Name .............. MO_SYS_FUNC.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MO_SYS_FUNC.h"
#include "ArchitectureConfig.h"
#include "MicrowaveOven.h"
#include "MicrowaveOven_Beeper_MO_B.h"
#include "MicrowaveOven_Door_MO_D.h"
#include "MicrowaveOven_InternalLight_MO_IL.h"
#include "MicrowaveOven_MagnetronTube_MO_MT.h"
#include "MicrowaveOven_Oven_MO_O.h"
#include "MicrowaveOven_Turntable_MO_TRN.h"
#include "MicrowaveOven_TestSequences_MO_TS.h"
#include "Win32_JThread.h"
#include "Win32_Timer.h"
#include "Win32_Time.h"
#include "GenericEvent.h"
#include "TinyDynArray.h"
#include "TimerEvent.h"
#include "TinyChain.h"
#include "TinyVector.h"
#include "TinyQueue.h"
#include "TinyList.h"
#include <stdlib.h>          /* Definition of NULL, malloc and free */
#include <string.h>          /* Definition of memcpy */

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the MO_SYS_FUNC system function */
static void MO_SYS_FUNC_Initialize( void );

/* Function for linking an element for scheduling by the dispatcher. */
static void MO_SYS_FUNC_LinkIntoDispatcherSchedule( void );

/* Function for unlinking an element from scheduling by the dispatcher. */
static void MO_SYS_FUNC_UnlinkFromDispatcherSchedule( struct TinyScheduleElement* scheduleElement );

/* Event Dispatcher Run Function for system function 'MO_SYS_FUNC' */
static void MO_SYS_FUNC_Run( void );

/* Function for examining event queues for system-level dispatched classes */
static void MO_SYS_FUNC_ExamineSystemDispClassEventQueues( void );

/* ---------------------------------------------------------------------------
 * Class based data for MO_SYS_FUNC
 * ---------------------------------------------------------------------------
 */
/* Startup indication variable for system function MO_SYS_FUNC
   (the system function must be started before the individual domains) */
fastBool MO_SYS_FUNC_isStarted = false;

/* The MO_SYS_FUNC System-Level Dispatcher Thread Name */
/* (this is the generated name of the system function) */
static const char* MO_SYS_FUNC_DispatcherThreadName = "MO_SYS_FUNC";

/* Dispatcher thread control variable for system function MO_SYS_FUNC */
fastBool MO_SYS_FUNC_Running = false;

/* Dispatcher thread status variable for system function MO_SYS_FUNC */
fastBool MO_SYS_FUNC_Waiting = false;

/* Common Event Queue Access Semaphore for system-level dispatched classes
   (this variable is also checked before delivery of Timer Events) */
fastBool MO_SYS_FUNC_EventQueueIsAccessed = false;

/* Indication about work to do for system-level dispatched classes
   (number of queued signals to process for state machines) */
unsigned long MO_SYS_FUNC_QueuedSignals = 0;

/* Indication that a system-level dispatched class needs urgent scheduling
   (for incoming signals, != NULL means "needs to be scheduled right away") */
struct TinyScheduleElement* MO_SYS_FUNC_UrgentScheduleElement = NULL;

/* The MO_SYS_FUNC Dispatcher Schedule */
#define NumberOfSystemDispatched_MO_SYS_FUNC_Classes 7
static struct TinyScheduleElement MO_SYS_FUNC_ScheduleElements[ NumberOfSystemDispatched_MO_SYS_FUNC_Classes ];
static struct TinySchedule MO_SYS_FUNC_DispatcherSchedule = {NULL, 0, NULL, NULL, 0, NULL, 0, 0, 0};

/* The MO_SYS_FUNC System-Level Dispatcher Thread */
struct Win32_JThread MO_SYS_FUNC_EventDispatcherThread;

/* ---------------------------------------------------------------------------
 * Function for starting up the entire MO_SYS_FUNC system function
 * ---------------------------------------------------------------------------
 */
void MO_SYS_FUNC_Startup( void )
{
   /* Invoke the GenericEvent initializer */
   initialize_GenericEvent();

   /* Invoke the TimerEvent initializer */
   initialize_TimerEvent();

   /* Invoke the Timer initializer */
   initialize_Timer();

   /* Invoke the TinyList initializer */
   initialize_TinyList();

   /* Invoke the TinyQueue initializer */
   initialize_TinyQueue();

   /* Invoke the TinyDynArray initializer */
   initialize_TinyDynArray();

   /* Invoke the TinyVector initializer */
   initialize_TinyVector();

   /* Invoke the system function initializer */
   MO_SYS_FUNC_Initialize();

   /* Invoke the thread instance vector initializer */
   initialize_ThreadInstanceVector();

   /* Indicate that system function MO_SYS_FUNC is started */
   MO_SYS_FUNC_isStarted = true;

   /* Startup the individual domains */
   MicrowaveOven_Startup();

   /* Start the system-level dispatcher thread */
   startThread( &MO_SYS_FUNC_EventDispatcherThread );

   /* Indicate that the scheduling request queue is not accessed (yet) */
   schedulingRequestQueueIsAccessed = false;

}

/* ---------------------------------------------------------------------------
 * Function for shutting down the entire MO_SYS_FUNC system function
 * ---------------------------------------------------------------------------
 */
void MO_SYS_FUNC_Shutdown( void )
{
   /* Shutdown the Timer */
   shutdown_Timer();

   /* Shutdown the TimerEvent and all active TimerEvent instances */
   shutdown_TimerEvent();

   /* Terminate the system-level dispatcher thread */
   MO_SYS_FUNC_Running = false;

   /* Check if the system-level dispatcher thread is waiting (suspended) */
   if ( MO_SYS_FUNC_Waiting )
   {
      /* Notify the system-level dispatcher thread */
      resumeThread( &MO_SYS_FUNC_EventDispatcherThread );
   }

   /* Shutdown the individual domains */
   MicrowaveOven_Shutdown();

   /* Shutdown the GenericEvent */
   shutdown_GenericEvent();

   /* Shutdown the TinyList */
   shutdown_TinyList();

   /* Shutdown the TinyQueue */
   shutdown_TinyQueue();

   /* Shutdown the TinyDynArray */
   shutdown_TinyDynArray();

   /* Shutdown the TinyVector */
   shutdown_TinyVector();
}

/* ---------------------------------------------------------------------------
 * Function for initializing the MO_SYS_FUNC system function
 * ---------------------------------------------------------------------------
 */
static void MO_SYS_FUNC_Initialize( void )
{
   /* Initialize the MO_SYS_FUNC Event Dispatcher Thread */
   MO_SYS_FUNC_EventDispatcherThread._runFunction        = MO_SYS_FUNC_Run;
   MO_SYS_FUNC_EventDispatcherThread._name               = MO_SYS_FUNC_DispatcherThreadName;
   MO_SYS_FUNC_EventDispatcherThread._stackSize          = _DefaultEventDispatcherStackSize;
   MO_SYS_FUNC_EventDispatcherThread._priority           = _NormalEventDispatcherPriority;
   MO_SYS_FUNC_EventDispatcherThread._isAlive            = false;
   MO_SYS_FUNC_EventDispatcherThread._handle             = NULL;
   MO_SYS_FUNC_EventDispatcherThread._id                 = 0;
   MO_SYS_FUNC_EventDispatcherThread._executingClassName = NULL;
   MO_SYS_FUNC_EventDispatcherThread._executingInstance  = NULL;

   /* Initialize the MO_SYS_FUNC Dispatcher Schedule */
   {
      unsigned long index;
      struct TinyScheduleElement* theElement;
      struct TinyScheduleElement* previousElement = &MO_SYS_FUNC_ScheduleElements[NumberOfSystemDispatched_MO_SYS_FUNC_Classes - 1];
      for (index = 0; index < NumberOfSystemDispatched_MO_SYS_FUNC_Classes; index++)
      {
         theElement = &MO_SYS_FUNC_ScheduleElements[index];
         theElement->theQueuePoller        = NULL;
         theElement->isLinkedForScheduling = false;
         theElement->nextInSchedule        = NULL;
         theElement->previousInSchedule    = NULL;
         previousElement->nextElement      = theElement;
         previousElement                   = theElement;
      }
   }
   MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule        = NULL;
   MO_SYS_FUNC_DispatcherSchedule.numberOfScheduledElements    = 0;
   MO_SYS_FUNC_DispatcherSchedule.firstRequestElement          = NULL;
   MO_SYS_FUNC_DispatcherSchedule.lastRequestElement           = NULL;
   MO_SYS_FUNC_DispatcherSchedule.numberOfSchedulingRequests   = 0;
   MO_SYS_FUNC_DispatcherSchedule.nextFreeElement              = &MO_SYS_FUNC_ScheduleElements[0];
   MO_SYS_FUNC_DispatcherSchedule.numberOfRegistrationFailures = 0;
   MO_SYS_FUNC_DispatcherSchedule.numberOfFreeElements         = NumberOfSystemDispatched_MO_SYS_FUNC_Classes;
   MO_SYS_FUNC_DispatcherSchedule.theCapacity                  = NumberOfSystemDispatched_MO_SYS_FUNC_Classes;

   /* Event queues not yet accessed for system-level dispatched classes */
   MO_SYS_FUNC_EventQueueIsAccessed = false;

   /* No work to do yet for system-level dispatched classes
      (number of queued signals to process for state machines) */
   MO_SYS_FUNC_QueuedSignals = 0;

   /* No urgent scheduling request yet */
   MO_SYS_FUNC_UrgentScheduleElement = NULL;

   /* Enable running dispatcher thread for system function MO_SYS_FUNC */
   MO_SYS_FUNC_Running = true;

   /* Not waiting dispatcher thread for system function MO_SYS_FUNC */
   MO_SYS_FUNC_Waiting = false;
}

/* ---------------------------------------------------------------------------
 * Function for registering the event queue polling function for an active class
 * ---------------------------------------------------------------------------
 */
struct TinyScheduleElement* MO_SYS_FUNC_RegisterQueuePoller( QueuePollerPtrType theQueuePoller, fastBool isPermanentlyLinked )
{
   return registerQueuePoller( &MO_SYS_FUNC_DispatcherSchedule, theQueuePoller, isPermanentlyLinked );
}

/* ---------------------------------------------------------------------------
 * Function for requesting a specific element for scheduling by the dispatcher
 * ---------------------------------------------------------------------------
 */
void MO_SYS_FUNC_RequestScheduling( struct TinyScheduleElement* requestElement )
{
   /* Set up the scheduling request queue access loop counter */
   unsigned int queueAccessLoopCounter = 2;

   /* Continue until the scheduling request queue access has been completed */
   do
   {

      /* Check that this scheduling request queue
         _not_ is being accessed by another thread */
      if ( !schedulingRequestQueueIsAccessed )
      {
         /* Indicate that the scheduling request queue is being accessed */
         schedulingRequestQueueIsAccessed = true;

         /* Check the number of active scheduling requests */
         if ( MO_SYS_FUNC_DispatcherSchedule.numberOfSchedulingRequests == 0 )
         {
            /* This is the first (only) element in request for scheduling */
            MO_SYS_FUNC_DispatcherSchedule.firstRequestElement = requestElement;
            requestElement->nextRequestElement = requestElement;
         }
         else
         {
            /* This is the next element in request for scheduling */
            MO_SYS_FUNC_DispatcherSchedule.lastRequestElement->nextRequestElement = requestElement;
         }
         MO_SYS_FUNC_DispatcherSchedule.lastRequestElement = requestElement;

         /* The number of scheduling requests has increased */
         MO_SYS_FUNC_DispatcherSchedule.numberOfSchedulingRequests++;

         /* Indicate that the scheduling request queue no longer is accessed */
         schedulingRequestQueueIsAccessed = false;

         /* Scheduling request queue access completed - Break out */
         /* break; (replaced by return statement below) */

         /* Job done: Return immediately */
         return;
      }
      else
      {
         /* Decrement the scheduling request queue access loop counter */
         queueAccessLoopCounter--;

         /* The scheduling request queue is perhaps being accessed by another thread
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

            /* Reset the scheduling request queue access loop counter */
            queueAccessLoopCounter = 2;
         }
      }

   } while (true);
}

/* ---------------------------------------------------------------------------
 * Function for linking an element for scheduling by the dispatcher.
 * ---------------------------------------------------------------------------
 */
static void MO_SYS_FUNC_LinkIntoDispatcherSchedule( void )
{
   /* Declaration of local variables */
   struct TinyScheduleElement* nextElementToSchedule_previous;
   struct TinyScheduleElement* nextElementToSchedule;
   struct TinyScheduleElement* pendingElement;

   /* Set up the scheduling request queue access loop counter */
   unsigned int queueAccessLoopCounter = 2;

   /* Continue until the scheduling request queue access has been completed */
   do
   {

      /* Check that this scheduling request queue
         _not_ is being accessed by another thread */
      if ( !schedulingRequestQueueIsAccessed )
      {
         /* Indicate that the scheduling request queue is being accessed */
         schedulingRequestQueueIsAccessed = true;

         /* Get the pending element in request for scheduling */
         pendingElement = MO_SYS_FUNC_DispatcherSchedule.firstRequestElement;

         /* Get the next pending element in request for scheduling */
         MO_SYS_FUNC_DispatcherSchedule.firstRequestElement = pendingElement->nextRequestElement;

         /* The number of scheduling requests has decreased */
         MO_SYS_FUNC_DispatcherSchedule.numberOfSchedulingRequests--;

         /* Indicate that the scheduling request queue no longer is accessed */
         schedulingRequestQueueIsAccessed = false;

         /* Scheduling request queue access completed - Break out */
         break;
      }
      else
      {
         /* Decrement the scheduling request queue access loop counter */
         queueAccessLoopCounter--;

         /* The scheduling request queue is perhaps being accessed by another thread
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

            /* Reset the scheduling request queue access loop counter */
            queueAccessLoopCounter = 2;
         }
      }

   } while (true);

   /* LINK THIS EVENT QUEUE POLLER FUNCTION INTO THE DISPATCHER SCHEDULE */

   if ( MO_SYS_FUNC_DispatcherSchedule.numberOfScheduledElements == 0 )
   {
      /* THIS IS THE FIRST (ONLY) ELEMENT IN THE DISPATCHER SCHEDULE */

      /* Link the linked in element to itself */
      pendingElement->previousInSchedule = pendingElement;
      pendingElement->nextInSchedule     = pendingElement;

      /* The next element to schedule is the element just linked in */
      MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule = pendingElement;
   }
   else
   {
      /* Get the next element to schedule */
      nextElementToSchedule = MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule;

      /* Get the element preceding the next element to schedule */
      nextElementToSchedule_previous = nextElementToSchedule->previousInSchedule;

      /* Check if the schedule contained only a single element prior to this one */
      if ( MO_SYS_FUNC_DispatcherSchedule.numberOfScheduledElements == 1 )
      {
         /* The new next element to schedule (on exit) is the element just linked in
            (prevents the same poller method to be called consecutively) */
         MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule = pendingElement;
      }

      /* INSERT THE LINKED IN ELEMENT BEFORE THE NEXT ELEMENT TO SCHEDULE (ON ENTRY) */

      /* Link the element before the next element to schedule to the linked in element */
      nextElementToSchedule_previous->nextInSchedule = pendingElement;
      pendingElement->previousInSchedule = nextElementToSchedule_previous;

      /* Link the next element to schedule to the linked in element */
      nextElementToSchedule->previousInSchedule = pendingElement;
      pendingElement->nextInSchedule = nextElementToSchedule;
   }

   /* Indicate that this element now is linked for scheduling */
   pendingElement->isLinkedForScheduling = true;

   /* Set up the empty event queue access counter */
   pendingElement->emptyEventQueueAccessCounter = 10;

   /* The number of elements being scheduled has increased */
   MO_SYS_FUNC_DispatcherSchedule.numberOfScheduledElements++;
}

/* ---------------------------------------------------------------------------
 * Function for unlinking an element from scheduling by the dispatcher.
 * ---------------------------------------------------------------------------
 */
static void MO_SYS_FUNC_UnlinkFromDispatcherSchedule( struct TinyScheduleElement* scheduleElement )
{
   /* Register that an empty event queue was accessed */
   scheduleElement->emptyEventQueueAccessCounter--;

   /* Time to unlink this poller function from the schedule? */
   if ( !(scheduleElement->emptyEventQueueAccessCounter) )
   {
      /* Declaration of local variables */
      struct TinyScheduleElement* unlinkElement_previous;
      struct TinyScheduleElement* unlinkElement_next;

      /* UNLINK THIS EVENT QUEUE POLLER FUNCTION FROM THE DISPATCHER SCHEDULE */

      /* Indicate that this element no longer is linked for scheduling */
      scheduleElement->isLinkedForScheduling = false;

      /* Get the previous and next elements related to the element to unlink */
      unlinkElement_previous = scheduleElement->previousInSchedule;
      unlinkElement_next     = scheduleElement->nextInSchedule;

      /* Release the element to unlink from the chain link */
      unlinkElement_previous->nextInSchedule = unlinkElement_next;
      unlinkElement_next->previousInSchedule = unlinkElement_previous;

      /* The next element to schedule is the element after the unlinked element */
      MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule = unlinkElement_next;

      /* The number of elements being scheduled is decreased */
      MO_SYS_FUNC_DispatcherSchedule.numberOfScheduledElements--;
   }
   else
   {
      /* Get the next scheduled event queue poller function */
      MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule = scheduleElement->nextInSchedule;
   }
}

/* ---------------------------------------------------------------------------
 * Event Dispatcher Run Function for system function 'MO_SYS_FUNC'
 * ---------------------------------------------------------------------------
 */
static void MO_SYS_FUNC_Run( void )
{
   /* Declaration of local dispatcher variables */
   unsigned int dispatcherThreadSuspendCounter;
   struct TinyScheduleElement* scheduleElement;
   const struct GenericEvent* queue_evt;
   QueuePollerPtrType theQueuePoller;
   unsigned int schedulingCounter;
   unsigned int loopCounter;
   fastBool eventHasBeenDispatched;

   /* Set up the dispatcher thread suspend counter */
   dispatcherThreadSuspendCounter = 3;

   /* Trace output: System dispatcher starts */
   infoTrace_SystemDispatcherStarts( "MO_SYS_FUNC", MO_SYS_FUNC_DispatcherThreadName );

   /* Set the maximum number of consecutive state machines (active classes)
      to schedule for before yield (switching to another thread) */
   schedulingCounter = _MaxConsecutiveActiveClassesToSchedule;

   /* No events dispatched yet */
   eventHasBeenDispatched = false;

   do
   {

      /* Check if event queue poller functions are in request for scheduling */
      if ( MO_SYS_FUNC_DispatcherSchedule.numberOfSchedulingRequests > 0 )
      {
         /* Link event queue poller function into the dispatcher schedule */
         MO_SYS_FUNC_LinkIntoDispatcherSchedule();
      }

      /* Check if there are events to process for system-level dispatched state machines */
      if ( MO_SYS_FUNC_QueuedSignals )
      {
         /* Update the dispatcher thread suspend counter */
         dispatcherThreadSuspendCounter = 3;

         /* Check if there is an urgent scheduling request */
         if ( MO_SYS_FUNC_UrgentScheduleElement )
         {
            /* Get the urgent element to schedule */
            scheduleElement = MO_SYS_FUNC_UrgentScheduleElement;
         }
         else
         {
            /* Check if there are any elements being scheduled */
            if ( MO_SYS_FUNC_DispatcherSchedule.numberOfScheduledElements )
            {
               /* Get the next element in the schedule */
               scheduleElement = MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule;
            }
            else
            {
               /* There are no elements being scheduled */
               scheduleElement = NULL;
            }
         }

         /* Check if a valid element to schedule was found */
         if ( scheduleElement != NULL )
         {
            /* Set the maximum number of consecutive events to dispatch */
            loopCounter = _MaxConsecutiveEventsToDispatch;

            /* Get the scheduled event queue poller function */
            theQueuePoller = scheduleElement->theQueuePoller;

            /* ENTER THE EVENT QUEUE POLLER LOOP */
            do
            {
               /* Call the scheduled event queue poller function */
               queue_evt = theQueuePoller();

               /* Check if the polled queues were empty (no event was dispatched) */
               if ( queue_evt == NULL )
               {
                  /* The event queue was empty - Break out of this loop */
                  break;
               }
               else
               {
                  /* The event queues has been polled once (event was dispatched) */
                  loopCounter--;

                  /* Indicate that an event has been dispatched */
                  eventHasBeenDispatched = true;
               }

            } while ( loopCounter > 0 );

            /* Check if the polled queues were empty (no event was dispatched)
               and that this active class not is permanently linked for scheduling */
            if (( !scheduleElement->isPermanentlyLinkedForScheduling ) &&
                ( loopCounter == _MaxConsecutiveEventsToDispatch ))
            {
               /* Unlink event queue poller function from the dispatcher schedule */
               MO_SYS_FUNC_UnlinkFromDispatcherSchedule( scheduleElement );
            }
            else
            {
               /* Set up the empty event queue access counter */
               scheduleElement->emptyEventQueueAccessCounter = 10;

               /* Check if this was an urgent scheduling request */
               if ( MO_SYS_FUNC_UrgentScheduleElement )
               {
                  /* Clear this urgent request */
                  MO_SYS_FUNC_UrgentScheduleElement = NULL;
               }
               else
               {
                  /* Check if the last scheduled element is linked for scheduling
                     (if NOT is was scheduled as an "urgent" or "leader" element) */
                  if ( scheduleElement->isLinkedForScheduling )
                  {
                     /* Get the next scheduled event queue poller function */
                     MO_SYS_FUNC_DispatcherSchedule.nextElementToSchedule = scheduleElement->nextInSchedule;
                  }
               }
            }
         }

         /* One state machine scheduled */
         schedulingCounter--;

         /* Check if maximum number of consecutive state machines has been scheduled */
         if ( schedulingCounter == 0 )
         {
            /* Check if no events were dispatched */
            if ( !eventHasBeenDispatched )
            {
               /* Examine event queues for system-level dispatched classes */
               MO_SYS_FUNC_ExamineSystemDispClassEventQueues();
            }

            /* Give processing time to other threads on same prio level (yield) */
            yieldThread();

            /* Set the maximum number of consecutive state machines to schedule */
            schedulingCounter = _MaxConsecutiveActiveClassesToSchedule;

            /* No new events dispatched yet */
            eventHasBeenDispatched = false;
         }
      }
      else
      {
         /* ALL EVENT QUEUES IN ACTIVE CLASSES RUN BY
            THIS SYSTEM-LEVEL DISPATCHER ARE EMPTIED
            (no events to process for state machines) */

         /* Decrement the dispatcher thread suspend counter */
         dispatcherThreadSuspendCounter--;

         /* Check if it's time to suspend this thread */
         if ( dispatcherThreadSuspendCounter )
         {
            /* Give this thread one more chance before we suspend it:
               Give processing time to other threads on same prio level (yield) */
            yieldThread();
         }
         else
         {
            /* SUSPEND THIS THREAD AND WAIT FOR INCOMING EVENTS */

            /* Indicate that the system-level dispatcher thread is waiting */
            MO_SYS_FUNC_Waiting = true;

            /* Await next incoming event (wait/suspend) */
            suspendThread( &MO_SYS_FUNC_EventDispatcherThread );

            /* Indicate that the system-level dispatcher thread no longer is waiting */
            MO_SYS_FUNC_Waiting = false;

            /* Update the dispatcher thread suspend counter */
            dispatcherThreadSuspendCounter = 3;
         }

         /* Set the maximum number of consecutive state machines to schedule */
         schedulingCounter = _MaxConsecutiveActiveClassesToSchedule;

         /* No new events dispatched yet */
         eventHasBeenDispatched = false;
      }

   } while ( MO_SYS_FUNC_Running );

   /* Suspend this system-level dispatcher thread (await termination) */
   do
   {
      /* Suspend this system-level dispatcher thread */
      suspendThread( &MO_SYS_FUNC_EventDispatcherThread );

   } while (true);
}

/* ---------------------------------------------------------------------------
 * Function for examining event queues for system-level dispatched classes
 * ---------------------------------------------------------------------------
 */
static void MO_SYS_FUNC_ExamineSystemDispClassEventQueues( void )
{
   /* Local variable declarations */
   unsigned long numberOfEventQueueJobs = 0;

   /* Get the sum of all Event Queue jobs (= queued events)
      from all the system-level dispatched classes */
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_B();
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_D();
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_IL();
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_MT();
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_O();
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_TRN();
   numberOfEventQueueJobs += MicrowaveOven_EventQueueInfo_MO_TS();

   /* Check if the retrieved number of event queue jobs is different from
      the registered work to do for system-level dispatched classes */
   if ( numberOfEventQueueJobs != MO_SYS_FUNC_QueuedSignals )
   {
      /* Trace output: Incorrectly registered number of jobs */
      errorTrace_IncorrectlyRegisteredNumberOfJobs( numberOfEventQueueJobs, MO_SYS_FUNC_QueuedSignals );

      /* Set the retrieved number of event queue jobs as the
         amount of work for system-level dispatched classes */
      MO_SYS_FUNC_QueuedSignals = numberOfEventQueueJobs;
   }
}

/* ### End of File MO_SYS_FUNC.c ### */
