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
 *  Executable UML Model "MicrowaveOven" using BridgePoint & TinyC.
 *
 *
 *  File Name .............. MicrowaveOven_InternalLight_MO_IL.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MicrowaveOven_InternalLight_MO_IL.h"
#include "MicrowaveOven.h"
#include "Win32_JThread.h"
#include "TinyQueue.h"
#include "Win32_Time.h"
#include <stdlib.h>          /* Definition of NULL, malloc and free */
#include <string.h>          /* Definition of memcpy */

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */
/* Event Queue Polling Function for class 'Internal Light'
   (to be called from the system-level dispatcher) */
void* MicrowaveOven_Poll_MO_IL( void );

/* Instance Event Processing Function for class 'Internal Light' */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_IL( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
const char* MicrowaveOven_ClassName_MO_IL = "Internal Light (MO_IL)";

/* Chain holding all existing instances of class 'Internal Light' */
struct TinyChain MicrowaveOven_InstanceChain_MO_IL = {NULL, NULL, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Queues
 * ---------------------------------------------------------------------------
 */
/* Event Queues for class 'Internal Light' */
static struct TinyQueue MicrowaveOven_EventQueue_MO_IL     = {NULL, NULL, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Dispatcher Variables
 * ---------------------------------------------------------------------------
 */
/* Pointer to the schedule element holding the event queue poller for this class */
static struct TinyScheduleElement* MicrowaveOven_ScheduleElement_MO_IL = NULL;

/* Scheduling request status variable for this class
   (this is for preventing multiple scheduling requests) */
static fastBool MicrowaveOven_SchedulingRequested_MO_IL = false;

/* ---------------------------------------------------------------------------
 * Instance Event & State Description Texts
 * ---------------------------------------------------------------------------
 */
/* Instance Event description texts for class 'Internal Light'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceEDT_MO_IL[2] =
{
   "MO_IL1:'switch_on'",
   "MO_IL2:'switch_off'"
};

/* Instance State description texts for class 'Internal Light'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceSDT_MO_IL[3] =
{
   "'NonExisting' (= deleted instance)",
   "'1. Off'",
   "'2. On'"
};

/* Instance Event Data Printer Array for class 'Internal Light'
   containing pointers to printout functions for event data signatures */
static const EventDataPrinterPtrType MicrowaveOven_InstanceEDPA_MO_IL[2] =
{
   (EventDataPrinterPtrType) NULL,  /* Event MO_IL1 has no event data */
   (EventDataPrinterPtrType) NULL   /* Event MO_IL2 has no event data */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Instance Event (IE) Codes for class 'Internal Light'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_IL1_IE_Code = 0,  /* Code for MO_IL1:'switch_on' */
   MicrowaveOven_MO_IL2_IE_Code = 1   /* Code for MO_IL2:'switch_off' */
};

/* Constant for event MO_IL1:'switch_on' */
const struct GenericEvent MicrowaveOven_MO_IL1_IE_Const =
      { (MicrowaveOven_MO_IL1_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_IL[0],
         &MicrowaveOven_InstanceEDPA_MO_IL[0],
         MicrowaveOven_TakeEvent_MO_IL,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_IL2:'switch_off' */
const struct GenericEvent MicrowaveOven_MO_IL2_IE_Const =
      { (MicrowaveOven_MO_IL2_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_IL[1],
         &MicrowaveOven_InstanceEDPA_MO_IL[1],
         MicrowaveOven_TakeEvent_MO_IL,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* ---------------------------------------------------------------------------
 * Instance State Event Matrix and Action Procedure Array(s)
 * ---------------------------------------------------------------------------
 */
/* Instance State Event Matrix (SEM) for class 'Internal Light'
   containing 'destination state' codes for all events in all states */
static const unsigned char MicrowaveOven_InstanceSEM_MO_IL[3][2] =
{
   /* Entries for additional state 'NonExisting'  (entered when deleted) */
   { EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 1 'Off' */
   { MicrowaveOven_MO_IL_IS2_2_On,
     EventIsIgnored },

   /* Entries for Instance State 2 'On' */
   { EventIsIgnored,
     MicrowaveOven_MO_IL_IS1_1_Off }
};

/* ---------------------------------------------------------------------------
 * Class Instance Pool
 * ---------------------------------------------------------------------------
 */
/* The 'Internal Light' class instance pool */
struct MicrowaveOven_InternalLight_MO_IL MicrowaveOven_ClassInstances_MO_IL[1];
struct TinyPool MicrowaveOven_ClassInstancePool_MO_IL = {NULL, 0, 0, 0, 0};

/* Labels for access to valid start & end addresses for pool instances.
   (the end address is slighly below the real end address of the pool array,
    but _not_ below the address of the last instance in the pool array) */
const struct MicrowaveOven_InternalLight_MO_IL* MicrowaveOven_ClassInstances_MO_IL_start =
            &MicrowaveOven_ClassInstances_MO_IL[0];
const struct MicrowaveOven_InternalLight_MO_IL* MicrowaveOven_ClassInstances_MO_IL_end = (const void*) ((unsigned long)
            &MicrowaveOven_ClassInstances_MO_IL[0] + sizeof(MicrowaveOven_ClassInstances_MO_IL) - sizeof(int));

/* ---------------------------------------------------------------------------
 * Function for initializing class 'Internal Light'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Initialize__MO_IL( void )
{
   /* Register the event queue polling function for this class */
   MicrowaveOven_ScheduleElement_MO_IL = MO_SYS_FUNC_RegisterQueuePoller( MicrowaveOven_Poll_MO_IL, false );

   /* Initialize the 'Internal Light' class instance pool */
   {
      struct TinyPoolElement* previousElement = &MicrowaveOven_ClassInstances_MO_IL[0].poolElement;
      struct TinyPoolElement* theElement      = &MicrowaveOven_ClassInstances_MO_IL[0].poolElement;
      previousElement->next = theElement;
      theElement->previous  = previousElement;
      previousElement       = theElement;
      MicrowaveOven_ClassInstancePool_MO_IL.firstFreeElement      = &MicrowaveOven_ClassInstances_MO_IL[0].poolElement;
      MicrowaveOven_ClassInstancePool_MO_IL.numberOfFreeElements  = 1;
      MicrowaveOven_ClassInstancePool_MO_IL.theCapacity           = 1;
      MicrowaveOven_ClassInstancePool_MO_IL.numberOfUsedElements  = 0;
      MicrowaveOven_ClassInstancePool_MO_IL.highWaterMark         = 0;
   }

}

/* ---------------------------------------------------------------------------
 * Function for shutting down class 'Internal Light'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Shutdown__MO_IL( void )
{
}

/* ---------------------------------------------------------------------------
 * Event Queue Info Function for class 'Internal Light'
 * ---------------------------------------------------------------------------
 */
unsigned long MicrowaveOven_EventQueueInfo_MO_IL( void )
{
   /* Local variable declarations */
   unsigned long numberOfEventQueueJobs;

   /* Get the jobs on the EventQueue */
   numberOfEventQueueJobs = MicrowaveOven_EventQueue_MO_IL.numberOfPushedElements -
                            MicrowaveOven_EventQueue_MO_IL.numberOfPoppedElements;

   /* Return the queued jobs for this class */
   return numberOfEventQueueJobs;
}

/* ---------------------------------------------------------------------------
 * General Event Taker Function for class 'Internal Light'
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_TakeEvent_MO_IL( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient )
{
   /* Check if a valid event was received */
   if ( incomingEvent != NULL )
   {
      /* Register the incomingEvent in the eventQueue */
      struct TinyQueue* theQueue = &MicrowaveOven_EventQueue_MO_IL;

      /* Set up the event queue access loop counter */
      unsigned int queueAccessLoopCounter = 2;

      /* Continue until the event queue access has been completed */
      do
      {

         /* Check that this event queue _not_ is being accessed by another thread */
         if ( !MO_SYS_FUNC_EventQueueIsAccessed )
         {
            /* Indicate that the event queue is being accessed */
            MO_SYS_FUNC_EventQueueIsAccessed = true;

            /* Deliver the incoming event to the own state machine
               (push it into the back of the target event queue) */
            pushBackQueue( theQueue, incomingEvent, eventData, recipient );

            /* Register this increased number of queued signals to
               process for system-level dispatched state machines */
            MO_SYS_FUNC_QueuedSignals++;

            /* Check if the event queue polling function not is linked for scheduling */
            if ( !(MicrowaveOven_ScheduleElement_MO_IL->isLinkedForScheduling) )
            {
               /* Check if scheduling of event queue polling not has been requested */
               if ( !MicrowaveOven_SchedulingRequested_MO_IL )
               {
                  /* Request scheduling of event queue polling by the dispatcher */
                  MO_SYS_FUNC_RequestScheduling( MicrowaveOven_ScheduleElement_MO_IL );

                  /* Indicate that scheduling of event queue polling is requested */
                  MicrowaveOven_SchedulingRequested_MO_IL = true;
               }
            }

            /* Indicate that the event queue no longer is accessed */
            MO_SYS_FUNC_EventQueueIsAccessed = false;

            /* Check if the dispatcher thread is waiting (suspended) */
            if ( MO_SYS_FUNC_Waiting )
            {
               /* Notify the dispatcher thread */
               resumeThread( &MO_SYS_FUNC_EventDispatcherThread );
            }

            /* Event queue access completed - Break out */
            /* break; (replaced by return statement below) */

            /* Job done: Return immediately */
            return;
         }
         else
         {
            /* Decrement the event queue access loop counter */
            queueAccessLoopCounter--;

            /* The event queue is perhaps being accessed by another thread
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

               /* Reset the event queue access loop counter */
               queueAccessLoopCounter = 2;
            }
         }

      } while (true);
   }
}

/* ---------------------------------------------------------------------------
 * Event Queue Polling Function for class 'Internal Light'
 * (to be called from the system-level dispatcher)
 * ---------------------------------------------------------------------------
 */
void* MicrowaveOven_Poll_MO_IL( void )
{
   /* Declaration of local queue poller variables */
   const struct GenericEvent* queue_evt = NULL;
   struct TinyQueueElement* popElement;
   void* theEventData = NULL;
   const void* theRecipient = NULL;

   /* Check if the event queue polling function has been linked for scheduling */
   if ( MicrowaveOven_ScheduleElement_MO_IL->isLinkedForScheduling )
   {
      /* Prepare for a future event queue polling request */
      MicrowaveOven_SchedulingRequested_MO_IL = false;
   }

   /* Indicate that the event queue is being accessed */
   MO_SYS_FUNC_EventQueueIsAccessed = true;

   /* Check if events are available for processing */
   if ( MicrowaveOven_EventQueue_MO_IL.numberOfPoppedElements !=
        MicrowaveOven_EventQueue_MO_IL.numberOfPushedElements )
   {
      /* Retrieve the event from the eventQueue */
      popElement   = MicrowaveOven_EventQueue_MO_IL.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_EventQueue_MO_IL.firstElement = popElement->next;
         MicrowaveOven_EventQueue_MO_IL.numberOfPoppedElements++;

         /* Register this decreased number of queued signals to
            process for system-level dispatched state machines */
         MO_SYS_FUNC_QueuedSignals--;
      }
      else
      {
         /* Indicate that the event retrieval is skipped */
         queue_evt = EventRetrievalSkipped;
      }
   }

   /* Indicate that the event queue no longer is accessed */
   MO_SYS_FUNC_EventQueueIsAccessed = false;

   /* Check if an event really has been retrieved */
   if ( queue_evt != NULL )
   {
      /* Check that event retrieval was not skipped */
      if ( queue_evt != EventRetrievalSkipped )
      {
         /* Process the instance event */
         MicrowaveOven_ProcInstEvent_MO_IL( queue_evt, theEventData, theRecipient );
      }
   }

   /* Return an indication if an event was dequeued or not.
      NULL is returned (by default) if the queues were empty. */
   return (void*) queue_evt;
}

/* ---------------------------------------------------------------------------
 * Instance Event Processing Function for class 'Internal Light'
 * ---------------------------------------------------------------------------
 */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_IL( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient )
{
   /* Check that this is not a cancelled timer event
      (release of event data memory may be needed) */
   if ( recipient != IsCancelledEvent )
   {
      /* Declare local variables */
      unsigned int eventCode;
      unsigned int currentState;
      unsigned int destState;

      /* Get the identification code for the event */
      eventCode = (unsigned int) (queue_evt->eventCodeAndType >> 16);

      /* Print information about the dequeuing of an event */
      eventTrace_DequeuingEvent( MicrowaveOven_ClassName_MO_IL,
                                 true, queue_evt, eventData, recipient );

      /* Check if there is a valid recipient */
      if ( recipient != NULL )
      {
         /* Get the 'Internal Light' target instance */
         struct MicrowaveOven_InternalLight_MO_IL* targetInst = (struct MicrowaveOven_InternalLight_MO_IL*) recipient;

         /* Get the current state for the target instance */
         currentState = (unsigned int) targetInst->currentISMstate_MO_IL;

         /* Get the destination state for the target instance */
         destState = (unsigned int) MicrowaveOven_InstanceSEM_MO_IL[currentState][eventCode];

         /* Register the currently executing state machine */
         registerCurrentStateMachine( MicrowaveOven_ClassName_MO_IL, recipient );

         /* CHECK THAT RECIPIENT INSTANCE NOT HAS BEEN DELETED */
         if ( currentState != MicrowaveOven_MO_IL_IS_NonExisting )
         {

            /* Check if the destination state is a valid state */
            if ( destState < MicrowaveOven_MO_IL_IS_NumberOfStates )
            {
               /* PROCESS THE EVENT */

               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_IL[currentState] );

               /* Print information about the destination state */
               eventTrace_GoingToState( MicrowaveOven_InstanceSDT_MO_IL[destState] );

               /* There are no Instance Transition Actions in this state machine */

               /* There are no Instance State Actions in this state machine */

               /* Check that the instance not has been deleted
                  during the execution of the state action code */
               if ( targetInst->currentISMstate_MO_IL != MicrowaveOven_MO_IL_IS_NonExisting )
               {
                  /* Set the new state for the target instance */
                  targetInst->currentISMstate_MO_IL = (unsigned char) destState;
               }
            }

            /* (there are no "can't happen" events for this state machine) */

            /* Check if this is an event that is "ignored" */
            else if ( destState == EventIsIgnored )
            {
               /* The received event is analyzed as "ignored" in current state */
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_IL[currentState] );
               eventTrace_EventIgnored();

               /* Trace output: Event Ignored */
               infoTrace_EventIgnored( "instance", MicrowaveOven_InstanceEDT_MO_IL[eventCode], MicrowaveOven_ClassName_MO_IL, MicrowaveOven_InstanceSDT_MO_IL[currentState] );
            }

            /* ...otherwise a fatal error has occurred */
            else
            {
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_IL[currentState] );

               /* A FATAL ERROR HAS OCCURRED WHEN HANDLING THIS EVENT
                  (destState error related to [currentState][eventCode] error) */
               eventTrace_FatalStateEventError();

               /* Trace output: Destination state error */
               errorTrace_DestinationStateError( "Instance", destState, currentState, eventCode, MicrowaveOven_ClassName_MO_IL, MicrowaveOven_InstanceEDT_MO_IL[eventCode] );
            }

         }
         else
         {
            /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
               (the 'recipient' of the event has been deleted) */

            /* Trace output: Event sent to deleted instance */
            errorTrace_EventToDeletedInstance( MicrowaveOven_InstanceEDT_MO_IL[eventCode], MicrowaveOven_ClassName_MO_IL );
            eventTrace_RecipientDeleted();
         }
      }
      else
      {
         /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
            (the 'recipient' of the event is == NULL) */

         /* Trace output: Instance pointer (recipient) == NULL */
         errorTrace_EventToNullRecipient( MicrowaveOven_InstanceEDT_MO_IL[eventCode], MicrowaveOven_ClassName_MO_IL );
         eventTrace_RecipientIsNULL();
      }
   }

   /* RELEASE MEMORY FOR THE EVENT DATA INSTANCE */

   /* Check if the incoming event has event data */
   if ( eventData )
   {
      /* Check that this is not a recurring timer event or a propagated event */
      if (!( ((_OEDH_*) eventData)->_header_.eventFlags & IsRecurringOrPropagated ))
      {
         /* Release memory for the event data instance */
         returnEventDataMemory( eventData );
      }
   }
}

/* ### End of File MicrowaveOven_InternalLight_MO_IL.c ### */
