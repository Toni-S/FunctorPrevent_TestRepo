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
 *  File Name .............. MicrowaveOven_Beeper_MO_B.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MicrowaveOven_Beeper_MO_B.h"
#include "TIM.h"
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
/* Event Queue Polling Function for class 'Beeper'
   (to be called from the system-level dispatcher) */
void* MicrowaveOven_Poll_MO_B( void );

/* Instance Event Processing Function for class 'Beeper' */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_B( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient );

/* Action code for Instance State 1. 'Awaiting Beeper Request' */
static void MicrowaveOven_ISA1_Awaiting_Beeper_Request_MO_B( struct MicrowaveOven_Beeper_MO_B* self, const void* eventData );

/* Action code for Instance State 2. 'Beeping' */
static void MicrowaveOven_ISA2_Beeping_MO_B( struct MicrowaveOven_Beeper_MO_B* self, const void* eventData );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
const char* MicrowaveOven_ClassName_MO_B = "Beeper (MO_B)";

/* Chain holding all existing instances of class 'Beeper' */
struct TinyChain MicrowaveOven_InstanceChain_MO_B = {NULL, NULL, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Queues
 * ---------------------------------------------------------------------------
 */
/* Event Queues for class 'Beeper' */
static struct TinyQueue MicrowaveOven_EventQueue_MO_B     = {NULL, NULL, 0, 0, 0};
static struct TinyQueue MicrowaveOven_SelfEventQueue_MO_B = {NULL, NULL, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Dispatcher Variables
 * ---------------------------------------------------------------------------
 */
/* Pointer to the schedule element holding the event queue poller for this class */
static struct TinyScheduleElement* MicrowaveOven_ScheduleElement_MO_B = NULL;

/* Scheduling request status variable for this class
   (this is for preventing multiple scheduling requests) */
static fastBool MicrowaveOven_SchedulingRequested_MO_B = false;

/* ---------------------------------------------------------------------------
 * Instance Event & State Description Texts
 * ---------------------------------------------------------------------------
 */
/* Instance Event description texts for class 'Beeper'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceEDT_MO_B[4] =
{
   "MO_B1:'start_beeping'",
   "MO_B2:'beep_delay_over'",
   "MO_B3:'beeping_stopped'",
   "MO_B4:'stop_beeping'"
};

/* Instance State description texts for class 'Beeper'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceSDT_MO_B[3] =
{
   "'NonExisting' (= deleted instance)",
   "'1. Awaiting Beeper Request'",
   "'2. Beeping'"
};

/* Instance Event Data Printer Array for class 'Beeper'
   containing pointers to printout functions for event data signatures */
static const EventDataPrinterPtrType MicrowaveOven_InstanceEDPA_MO_B[4] =
{
   (EventDataPrinterPtrType) NULL,  /* Event MO_B1 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_B2 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_B3 has no event data */
   (EventDataPrinterPtrType) NULL   /* Event MO_B4 has no event data */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Instance Event (IE) Codes for class 'Beeper'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_B1_IE_Code = 0,  /* Code for MO_B1:'start_beeping' */
   MicrowaveOven_MO_B2_IE_Code = 1,  /* Code for MO_B2:'beep_delay_over' */
   MicrowaveOven_MO_B3_IE_Code = 2,  /* Code for MO_B3:'beeping_stopped' */
   MicrowaveOven_MO_B4_IE_Code = 3   /* Code for MO_B4:'stop_beeping' */
};

/* Constant for event MO_B1:'start_beeping' */
const struct GenericEvent MicrowaveOven_MO_B1_IE_Const =
      { (MicrowaveOven_MO_B1_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_B[0],
         &MicrowaveOven_InstanceEDPA_MO_B[0],
         MicrowaveOven_TakeEvent_MO_B,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_B2:'beep_delay_over' */
const struct GenericEvent MicrowaveOven_MO_B2_IE_Const =
      { (MicrowaveOven_MO_B2_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_B[1],
         &MicrowaveOven_InstanceEDPA_MO_B[1],
         MicrowaveOven_TakeEvent_MO_B,
         &MO_SYS_FUNC_EventQueueIsAccessed };
/* (constant to use when self-directed signal) */
const struct GenericEvent MicrowaveOven_MO_B2_IE_Const_Self =
      { (MicrowaveOven_MO_B2_IE_Code << 16) +
         IsSelfDirected,
         &MicrowaveOven_InstanceEDT_MO_B[1],
         &MicrowaveOven_InstanceEDPA_MO_B[1],
         MicrowaveOven_TakeEvent_MO_B,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_B3:'beeping_stopped' */
const struct GenericEvent MicrowaveOven_MO_B3_IE_Const =
      { (MicrowaveOven_MO_B3_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_B[2],
         &MicrowaveOven_InstanceEDPA_MO_B[2],
         MicrowaveOven_TakeEvent_MO_B,
         &MO_SYS_FUNC_EventQueueIsAccessed };
/* (constant to use when self-directed signal) */
const struct GenericEvent MicrowaveOven_MO_B3_IE_Const_Self =
      { (MicrowaveOven_MO_B3_IE_Code << 16) +
         IsSelfDirected,
         &MicrowaveOven_InstanceEDT_MO_B[2],
         &MicrowaveOven_InstanceEDPA_MO_B[2],
         MicrowaveOven_TakeEvent_MO_B,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_B4:'stop_beeping' */
const struct GenericEvent MicrowaveOven_MO_B4_IE_Const =
      { (MicrowaveOven_MO_B4_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_B[3],
         &MicrowaveOven_InstanceEDPA_MO_B[3],
         MicrowaveOven_TakeEvent_MO_B,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* ---------------------------------------------------------------------------
 * Instance State Event Matrix and Action Procedure Array(s)
 * ---------------------------------------------------------------------------
 */
/* Instance State Event Matrix (SEM) for class 'Beeper'
   containing 'destination state' codes for all events in all states */
static const unsigned char MicrowaveOven_InstanceSEM_MO_B[3][4] =
{
   /* Entries for additional state 'NonExisting'  (entered when deleted) */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 1 'Awaiting Beeper Request' */
   { MicrowaveOven_MO_B_IS2_2_Beeping,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 2 'Beeping' */
   { EventIsIgnored,
     MicrowaveOven_MO_B_IS2_2_Beeping,
     MicrowaveOven_MO_B_IS1_1_Awaiting_Beeper_Request,
     MicrowaveOven_MO_B_IS1_1_Awaiting_Beeper_Request }
};

/* Instance State Actions Array (SAA) for class 'Beeper'
   containing pointers to actions for all Instance States */
static const InstanceStateActionPtrType MicrowaveOven_InstanceSAA_MO_B[3] =
{
   (InstanceStateActionPtrType) NULL,  /* The additional state 'NonExisting' has no action procedure */
   (InstanceStateActionPtrType) MicrowaveOven_ISA1_Awaiting_Beeper_Request_MO_B,
   (InstanceStateActionPtrType) MicrowaveOven_ISA2_Beeping_MO_B 
};

/* ---------------------------------------------------------------------------
 * Class Instance Pool
 * ---------------------------------------------------------------------------
 */
/* The 'Beeper' class instance pool */
struct MicrowaveOven_Beeper_MO_B MicrowaveOven_ClassInstances_MO_B[1];
struct TinyPool MicrowaveOven_ClassInstancePool_MO_B = {NULL, 0, 0, 0, 0};

/* Labels for access to valid start & end addresses for pool instances.
   (the end address is slighly below the real end address of the pool array,
    but _not_ below the address of the last instance in the pool array) */
const struct MicrowaveOven_Beeper_MO_B* MicrowaveOven_ClassInstances_MO_B_start =
            &MicrowaveOven_ClassInstances_MO_B[0];
const struct MicrowaveOven_Beeper_MO_B* MicrowaveOven_ClassInstances_MO_B_end = (const void*) ((unsigned long)
            &MicrowaveOven_ClassInstances_MO_B[0] + sizeof(MicrowaveOven_ClassInstances_MO_B) - sizeof(int));

/* ---------------------------------------------------------------------------
 * Function for initializing class 'Beeper'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Initialize__MO_B( void )
{
   /* Register the event queue polling function for this class */
   MicrowaveOven_ScheduleElement_MO_B = MO_SYS_FUNC_RegisterQueuePoller( MicrowaveOven_Poll_MO_B, false );

   /* Initialize the 'Beeper' class instance pool */
   {
      struct TinyPoolElement* previousElement = &MicrowaveOven_ClassInstances_MO_B[0].poolElement;
      struct TinyPoolElement* theElement      = &MicrowaveOven_ClassInstances_MO_B[0].poolElement;
      previousElement->next = theElement;
      theElement->previous  = previousElement;
      previousElement       = theElement;
      MicrowaveOven_ClassInstancePool_MO_B.firstFreeElement      = &MicrowaveOven_ClassInstances_MO_B[0].poolElement;
      MicrowaveOven_ClassInstancePool_MO_B.numberOfFreeElements  = 1;
      MicrowaveOven_ClassInstancePool_MO_B.theCapacity           = 1;
      MicrowaveOven_ClassInstancePool_MO_B.numberOfUsedElements  = 0;
      MicrowaveOven_ClassInstancePool_MO_B.highWaterMark         = 0;
   }

}

/* ---------------------------------------------------------------------------
 * Function for shutting down class 'Beeper'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Shutdown__MO_B( void )
{
}

/* ---------------------------------------------------------------------------
 * Event Queue Info Function for class 'Beeper'
 * ---------------------------------------------------------------------------
 */
unsigned long MicrowaveOven_EventQueueInfo_MO_B( void )
{
   /* Local variable declarations */
   unsigned long numberOfEventQueueJobs;

   /* Get the jobs on the EventQueue */
   numberOfEventQueueJobs = MicrowaveOven_EventQueue_MO_B.numberOfPushedElements -
                            MicrowaveOven_EventQueue_MO_B.numberOfPoppedElements;

   /* Get the jobs on the SelfEventQueue */
   numberOfEventQueueJobs += MicrowaveOven_SelfEventQueue_MO_B.numberOfPushedElements -
                             MicrowaveOven_SelfEventQueue_MO_B.numberOfPoppedElements;

   /* Return the queued jobs for this class */
   return numberOfEventQueueJobs;
}

/* ---------------------------------------------------------------------------
 * General Event Taker Function for class 'Beeper'
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_TakeEvent_MO_B( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient )
{
   /* Check if a valid event was received */
   if ( incomingEvent != NULL )
   {
      /* Declaration of local event taker variables */
      struct TinyQueue* theQueue;

      /* Set up the event queue access loop counter */
      unsigned int queueAccessLoopCounter = 2;

      /* Check if the incoming event is self-directed */
      if ( incomingEvent->eventCodeAndType & IsSelfDirected )
      {
         /* Register the incomingEvent in the selfEventQueue */
         theQueue = &MicrowaveOven_SelfEventQueue_MO_B;
      }
      else
      {
         /* Register the incomingEvent in the eventQueue */
         theQueue = &MicrowaveOven_EventQueue_MO_B;
      }

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
            if ( !(MicrowaveOven_ScheduleElement_MO_B->isLinkedForScheduling) )
            {
               /* Check if scheduling of event queue polling not has been requested */
               if ( !MicrowaveOven_SchedulingRequested_MO_B )
               {
                  /* Request scheduling of event queue polling by the dispatcher */
                  MO_SYS_FUNC_RequestScheduling( MicrowaveOven_ScheduleElement_MO_B );

                  /* Indicate that scheduling of event queue polling is requested */
                  MicrowaveOven_SchedulingRequested_MO_B = true;
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
 * Event Queue Polling Function for class 'Beeper'
 * (to be called from the system-level dispatcher)
 * ---------------------------------------------------------------------------
 */
void* MicrowaveOven_Poll_MO_B( void )
{
   /* Declaration of local queue poller variables */
   const struct GenericEvent* queue_evt = NULL;
   struct TinyQueueElement* popElement;
   void* theEventData = NULL;
   const void* theRecipient = NULL;

   /* Check if the event queue polling function has been linked for scheduling */
   if ( MicrowaveOven_ScheduleElement_MO_B->isLinkedForScheduling )
   {
      /* Prepare for a future event queue polling request */
      MicrowaveOven_SchedulingRequested_MO_B = false;
   }

   /* Indicate that the event queue is being accessed */
   MO_SYS_FUNC_EventQueueIsAccessed = true;

   /* Check if self-directed events are available for processing */
   if ( MicrowaveOven_SelfEventQueue_MO_B.numberOfPoppedElements !=
        MicrowaveOven_SelfEventQueue_MO_B.numberOfPushedElements )
   {
      /* Retrieve the event from the selfEventQueue */
      popElement   = MicrowaveOven_SelfEventQueue_MO_B.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_SelfEventQueue_MO_B.firstElement = popElement->next;
         MicrowaveOven_SelfEventQueue_MO_B.numberOfPoppedElements++;

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
   /* Check if events are available for processing */
   else if ( MicrowaveOven_EventQueue_MO_B.numberOfPoppedElements !=
             MicrowaveOven_EventQueue_MO_B.numberOfPushedElements )
   {
      /* Retrieve the event from the eventQueue */
      popElement   = MicrowaveOven_EventQueue_MO_B.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_EventQueue_MO_B.firstElement = popElement->next;
         MicrowaveOven_EventQueue_MO_B.numberOfPoppedElements++;

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
         MicrowaveOven_ProcInstEvent_MO_B( queue_evt, theEventData, theRecipient );
      }
   }

   /* Return an indication if an event was dequeued or not.
      NULL is returned (by default) if the queues were empty. */
   return (void*) queue_evt;
}

/* ---------------------------------------------------------------------------
 * Instance Event Processing Function for class 'Beeper'
 * ---------------------------------------------------------------------------
 */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_B( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient )
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
      eventTrace_DequeuingEvent( MicrowaveOven_ClassName_MO_B,
                                 true, queue_evt, eventData, recipient );

      /* Check if there is a valid recipient */
      if ( recipient != NULL )
      {
         /* Get the 'Beeper' target instance */
         struct MicrowaveOven_Beeper_MO_B* targetInst = (struct MicrowaveOven_Beeper_MO_B*) recipient;

         /* Get the current state for the target instance */
         currentState = (unsigned int) targetInst->currentISMstate_MO_B;

         /* Get the destination state for the target instance */
         destState = (unsigned int) MicrowaveOven_InstanceSEM_MO_B[currentState][eventCode];

         /* Register the currently executing state machine */
         registerCurrentStateMachine( MicrowaveOven_ClassName_MO_B, recipient );

         /* CHECK THAT RECIPIENT INSTANCE NOT HAS BEEN DELETED */
         if ( currentState != MicrowaveOven_MO_B_IS_NonExisting )
         {

            /* Check if the destination state is a valid state */
            if ( destState < MicrowaveOven_MO_B_IS_NumberOfStates )
            {
               /* PROCESS THE EVENT */

               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_B[currentState] );

               /* Print information about the destination state */
               eventTrace_GoingToState( MicrowaveOven_InstanceSDT_MO_B[destState] );

               /* There are no Instance Transition Actions in this state machine */

               /* Execute the Instance State Action */
               {
                  InstanceStateActionPtrType instanceStateAction = MicrowaveOven_InstanceSAA_MO_B[destState];
                  ( *instanceStateAction )( targetInst, NULL );
               }

               /* Check that the instance not has been deleted
                  during the execution of the state action code */
               if ( targetInst->currentISMstate_MO_B != MicrowaveOven_MO_B_IS_NonExisting )
               {
                  /* Set the new state for the target instance */
                  targetInst->currentISMstate_MO_B = (unsigned char) destState;
               }
            }

            /* (there are no "can't happen" events for this state machine) */

            /* Check if this is an event that is "ignored" */
            else if ( destState == EventIsIgnored )
            {
               /* The received event is analyzed as "ignored" in current state */
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_B[currentState] );
               eventTrace_EventIgnored();

               /* Trace output: Event Ignored */
               infoTrace_EventIgnored( "instance", MicrowaveOven_InstanceEDT_MO_B[eventCode], MicrowaveOven_ClassName_MO_B, MicrowaveOven_InstanceSDT_MO_B[currentState] );
            }

            /* ...otherwise a fatal error has occurred */
            else
            {
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_B[currentState] );

               /* A FATAL ERROR HAS OCCURRED WHEN HANDLING THIS EVENT
                  (destState error related to [currentState][eventCode] error) */
               eventTrace_FatalStateEventError();

               /* Trace output: Destination state error */
               errorTrace_DestinationStateError( "Instance", destState, currentState, eventCode, MicrowaveOven_ClassName_MO_B, MicrowaveOven_InstanceEDT_MO_B[eventCode] );
            }

         }
         else
         {
            /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
               (the 'recipient' of the event has been deleted) */

            /* Trace output: Event sent to deleted instance */
            errorTrace_EventToDeletedInstance( MicrowaveOven_InstanceEDT_MO_B[eventCode], MicrowaveOven_ClassName_MO_B );
            eventTrace_RecipientDeleted();
         }
      }
      else
      {
         /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
            (the 'recipient' of the event is == NULL) */

         /* Trace output: Instance pointer (recipient) == NULL */
         errorTrace_EventToNullRecipient( MicrowaveOven_InstanceEDT_MO_B[eventCode], MicrowaveOven_ClassName_MO_B );
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

/* ---------------------------------------------------------------------------
 * Action code for Instance State 1. 'Awaiting Beeper Request'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA1_Awaiting_Beeper_Request_MO_B( struct MicrowaveOven_Beeper_MO_B* self, const void* eventData )
{
   /* Local variable declarations */
   bool cancelled_timer;

   /* ASSIGN ATTRIBUTE self.beep_count = 0 */
   self->beep_count_MO_B = 0;

   /* ASSIGN VARIABLE cancelled_timer = TIM::timer_cancel( timer_inst_ref:self.beeper_timer ) */
   cancelled_timer = TIM_timer_cancel(self->beeper_timer_MO_B);

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 2. 'Beeping'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA2_Beeping_MO_B( struct MicrowaveOven_Beeper_MO_B* self, const void* eventData )
{
   switch (self->beep_count_MO_B)
   {
      case 0:
      {
         /* Local variable declarations */
         const struct GenericEvent* delay_over = NULL;
         void* delay_over_data;
         const void* delay_over_recipient;

         /* CREATE EVENT delay_over OF MO_B2:'beep_delay_over' TO self */

         /* Get constant declaration for event MO_B2:'beep_delay_over' */
         delay_over = &MicrowaveOven_MO_B2_IE_Const_Self;
         /* Allocate event data memory for event tracing purposes only */
         delay_over_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
         /* Clear the event handling flags */
         ((_OEDH_*) delay_over_data)->_header_.eventFlags = FlagsUndefined;
         ((_OEDH_*) delay_over_data)->_header_.timeInformationAvailable = false;
         ((_OEDH_*) delay_over_data)->_header_.senderClassName = currentThread_ExecutingClassName();
         ((_OEDH_*) delay_over_data)->_header_.senderInstance = currentThread_ExecutingInstance();
         delay_over_recipient = self;

         /* ASSIGN ATTRIBUTE self.beeper_timer = TIM::timer_start( event_inst:delay_over, microseconds:100000 ) */
         self->beeper_timer_MO_B = TIM_timer_start(delay_over, delay_over_data, delay_over_recipient, 100000);

         /* Clear the pre-created event reference when delivered
            (prevents sending the same event multiple times) */
         delay_over = NULL;

         break;
      }
      case 4:
      {
         /* Local variable declarations */
         struct MicrowaveOven_Oven_MO_O* oven_p;
         const struct GenericEvent* evt_2;
         void* evt_2_data;
         const void* evt_2_recipient;
         const struct GenericEvent* evt_3;
         void* evt_3_data;
         const void* evt_3_recipient;

         /* GENERATE EVENT MO_B3:'beeping_stopped' TO self */

         /* Get constant declaration for event MO_B3:'beeping_stopped' */
         evt_2 = &MicrowaveOven_MO_B3_IE_Const_Self;
         /* Allocate event data memory for event tracing purposes only */
         evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
         /* Clear the event handling flags */
         ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
         ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
         ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
         ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
         evt_2_recipient = self;

         /* Deliver the event to the target state machine */
         MicrowaveOven_TakeEvent_MO_B( evt_2, evt_2_data, evt_2_recipient );

         /* SELECT ONE oven RELATED BY self->MO_O[R3] */

         /* ### Navigate across relationship R3 ### */
         {  /* (select one RGO related by RTO inst) */

            /* Select the Oven instance related across R3 */
            oven_p = self->MO_O_DestNavPtr_R3_p;
         }

         /* GENERATE EVENT MO_O6:'beeping_over' TO oven */

         /* Get constant declaration for event MO_O6:'beeping_over' */
         evt_3 = &MicrowaveOven_MO_O6_IE_Const;
         /* Allocate event data memory for event tracing purposes only */
         evt_3_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
         /* Clear the event handling flags */
         ((_OEDH_*) evt_3_data)->_header_.eventFlags = FlagsUndefined;
         ((_OEDH_*) evt_3_data)->_header_.timeInformationAvailable = false;
         ((_OEDH_*) evt_3_data)->_header_.senderClassName = currentThread_ExecutingClassName();
         ((_OEDH_*) evt_3_data)->_header_.senderInstance = currentThread_ExecutingInstance();
         evt_3_recipient = oven_p;

         /* Deliver the event to the target state machine */
         MicrowaveOven_TakeEvent_MO_O( evt_3, evt_3_data, evt_3_recipient );

         break;
      }
      default:
      {
         /* Local variable declarations */
         const struct GenericEvent* delay_over = NULL;
         void* delay_over_data;
         const void* delay_over_recipient;

         /* CREATE EVENT delay_over OF MO_B2:'beep_delay_over' TO self */

         /* Get constant declaration for event MO_B2:'beep_delay_over' */
         delay_over = &MicrowaveOven_MO_B2_IE_Const_Self;
         /* Allocate event data memory for event tracing purposes only */
         delay_over_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
         /* Clear the event handling flags */
         ((_OEDH_*) delay_over_data)->_header_.eventFlags = FlagsUndefined;
         ((_OEDH_*) delay_over_data)->_header_.timeInformationAvailable = false;
         ((_OEDH_*) delay_over_data)->_header_.senderClassName = currentThread_ExecutingClassName();
         ((_OEDH_*) delay_over_data)->_header_.senderInstance = currentThread_ExecutingInstance();
         delay_over_recipient = self;

         /* ASSIGN ATTRIBUTE self.beeper_timer = TIM::timer_start( event_inst:delay_over, microseconds:100000 ) */
         self->beeper_timer_MO_B = TIM_timer_start(delay_over, delay_over_data, delay_over_recipient, 100000);

         /* Clear the pre-created event reference when delivered
            (prevents sending the same event multiple times) */
         delay_over = NULL;

         break;
      }
   }
   /* ASSIGN ATTRIBUTE self.beep_count = self.beep_count + 1 */
   self->beep_count_MO_B++;

}

/* ### End of File MicrowaveOven_Beeper_MO_B.c ### */
