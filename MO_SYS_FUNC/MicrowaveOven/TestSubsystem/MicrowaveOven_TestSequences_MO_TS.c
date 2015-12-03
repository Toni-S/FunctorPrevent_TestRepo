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
 *  File Name .............. MicrowaveOven_TestSequences_MO_TS.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MicrowaveOven_TestSequences_MO_TS.h"
#include "MicrowaveOven_Door_MO_D.h"
#include "MicrowaveOven_MagnetronTube_MO_MT.h"
#include "MicrowaveOven_Oven_MO_O.h"
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
/* Event Queue Polling Function for class 'Test Sequences'
   (to be called from the system-level dispatcher) */
void* MicrowaveOven_Poll_MO_TS( void );

/* Instance Event Processing Function for class 'Test Sequences' */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_TS( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient );

/* Action code for Instance State 1. 'Awaiting Test Sequence Initiation' */
static void MicrowaveOven_ISA1_Awaiting_Test_Sequence_Initiation_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData );

/* Action code for Instance State 2. 'Performing Test Sequence 1' */
static void MicrowaveOven_ISA2_Performing_Test_Sequence_1_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData );

/* Action code for Instance State 3. 'Performing Test Sequence 2' */
static void MicrowaveOven_ISA3_Performing_Test_Sequence_2_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData );

/* Action code for Instance State 4. 'Cooking Complete' */
static void MicrowaveOven_ISA4_Cooking_Complete_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
const char* MicrowaveOven_ClassName_MO_TS = "Test Sequences (MO_TS)";

/* Chain holding all existing instances of class 'Test Sequences' */
struct TinyChain MicrowaveOven_InstanceChain_MO_TS = {NULL, NULL, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Queues
 * ---------------------------------------------------------------------------
 */
/* Event Queues for class 'Test Sequences' */
static struct TinyQueue MicrowaveOven_EventQueue_MO_TS     = {NULL, NULL, 0, 0, 0};
static struct TinyQueue MicrowaveOven_SelfEventQueue_MO_TS = {NULL, NULL, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Dispatcher Variables
 * ---------------------------------------------------------------------------
 */
/* Pointer to the schedule element holding the event queue poller for this class */
static struct TinyScheduleElement* MicrowaveOven_ScheduleElement_MO_TS = NULL;

/* Scheduling request status variable for this class
   (this is for preventing multiple scheduling requests) */
static fastBool MicrowaveOven_SchedulingRequested_MO_TS = false;

/* ---------------------------------------------------------------------------
 * Instance Event & State Description Texts
 * ---------------------------------------------------------------------------
 */
/* Instance Event description texts for class 'Test Sequences'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceEDT_MO_TS[4] =
{
   "MO_TS2:'perform_test_seq_1'",
   "MO_TS3:'perform_test_seq_2'",
   "MO_TS1:'initialize'",
   "MO_TS4:'test_seq_complete'"
};

/* Instance State description texts for class 'Test Sequences'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceSDT_MO_TS[5] =
{
   "'NonExisting' (= deleted instance)",
   "'1. Awaiting Test Sequence Initiation'",
   "'2. Performing Test Sequence 1'",
   "'3. Performing Test Sequence 2'",
   "'4. Cooking Complete'"
};

/* Instance Event Data Printer Array for class 'Test Sequences'
   containing pointers to printout functions for event data signatures */
static const EventDataPrinterPtrType MicrowaveOven_InstanceEDPA_MO_TS[4] =
{
   (EventDataPrinterPtrType) NULL,  /* Event MO_TS2 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_TS3 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_TS1 has no event data */
   (EventDataPrinterPtrType) NULL   /* Event MO_TS4 has no event data */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Instance Event (IE) Codes for class 'Test Sequences'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_TS2_IE_Code = 0,  /* Code for MO_TS2:'perform_test_seq_1' */
   MicrowaveOven_MO_TS3_IE_Code = 1,  /* Code for MO_TS3:'perform_test_seq_2' */
   MicrowaveOven_MO_TS1_IE_Code = 2,  /* Code for MO_TS1:'initialize' */
   MicrowaveOven_MO_TS4_IE_Code = 3   /* Code for MO_TS4:'test_seq_complete' */
};

/* Constant for event MO_TS2:'perform_test_seq_1' */
const struct GenericEvent MicrowaveOven_MO_TS2_IE_Const =
      { (MicrowaveOven_MO_TS2_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_TS[0],
         &MicrowaveOven_InstanceEDPA_MO_TS[0],
         MicrowaveOven_TakeEvent_MO_TS,
         &MO_SYS_FUNC_EventQueueIsAccessed };
/* (constant to use when self-directed signal) */
const struct GenericEvent MicrowaveOven_MO_TS2_IE_Const_Self =
      { (MicrowaveOven_MO_TS2_IE_Code << 16) +
         IsSelfDirected,
         &MicrowaveOven_InstanceEDT_MO_TS[0],
         &MicrowaveOven_InstanceEDPA_MO_TS[0],
         MicrowaveOven_TakeEvent_MO_TS,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_TS3:'perform_test_seq_2' */
const struct GenericEvent MicrowaveOven_MO_TS3_IE_Const =
      { (MicrowaveOven_MO_TS3_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_TS[1],
         &MicrowaveOven_InstanceEDPA_MO_TS[1],
         MicrowaveOven_TakeEvent_MO_TS,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_TS1:'initialize' */
const struct GenericEvent MicrowaveOven_MO_TS1_IE_Const =
      { (MicrowaveOven_MO_TS1_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_TS[2],
         &MicrowaveOven_InstanceEDPA_MO_TS[2],
         MicrowaveOven_TakeEvent_MO_TS,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_TS4:'test_seq_complete' */
const struct GenericEvent MicrowaveOven_MO_TS4_IE_Const =
      { (MicrowaveOven_MO_TS4_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_TS[3],
         &MicrowaveOven_InstanceEDPA_MO_TS[3],
         MicrowaveOven_TakeEvent_MO_TS,
         &MO_SYS_FUNC_EventQueueIsAccessed };
/* (constant to use when self-directed signal) */
const struct GenericEvent MicrowaveOven_MO_TS4_IE_Const_Self =
      { (MicrowaveOven_MO_TS4_IE_Code << 16) +
         IsSelfDirected,
         &MicrowaveOven_InstanceEDT_MO_TS[3],
         &MicrowaveOven_InstanceEDPA_MO_TS[3],
         MicrowaveOven_TakeEvent_MO_TS,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* ---------------------------------------------------------------------------
 * Instance State Event Matrix and Action Procedure Array(s)
 * ---------------------------------------------------------------------------
 */
/* Instance State Event Matrix (SEM) for class 'Test Sequences'
   containing 'destination state' codes for all events in all states */
static const unsigned char MicrowaveOven_InstanceSEM_MO_TS[5][4] =
{
   /* Entries for additional state 'NonExisting'  (entered when deleted) */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 1 'Awaiting Test Sequence Initiation' */
   { MicrowaveOven_MO_TS_IS2_2_Performing_Test_Sequence_1,
     MicrowaveOven_MO_TS_IS3_3_Performing_Test_Sequence_2,
     MicrowaveOven_MO_TS_IS1_1_Awaiting_Test_Sequence_Initiation,
     EventIsIgnored },

   /* Entries for Instance State 2 'Performing Test Sequence 1' */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_TS_IS4_4_Cooking_Complete },

   /* Entries for Instance State 3 'Performing Test Sequence 2' */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_TS_IS4_4_Cooking_Complete },

   /* Entries for Instance State 4 'Cooking Complete' */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored }
};

/* Instance State Actions Array (SAA) for class 'Test Sequences'
   containing pointers to actions for all Instance States */
static const InstanceStateActionPtrType MicrowaveOven_InstanceSAA_MO_TS[5] =
{
   (InstanceStateActionPtrType) NULL,  /* The additional state 'NonExisting' has no action procedure */
   (InstanceStateActionPtrType) MicrowaveOven_ISA1_Awaiting_Test_Sequence_Initiation_MO_TS,
   (InstanceStateActionPtrType) MicrowaveOven_ISA2_Performing_Test_Sequence_1_MO_TS,
   (InstanceStateActionPtrType) MicrowaveOven_ISA3_Performing_Test_Sequence_2_MO_TS,
   (InstanceStateActionPtrType) MicrowaveOven_ISA4_Cooking_Complete_MO_TS 
};

/* ---------------------------------------------------------------------------
 * Class Instance Pool
 * ---------------------------------------------------------------------------
 */
/* The 'Test Sequences' class instance pool */
struct MicrowaveOven_TestSequences_MO_TS MicrowaveOven_ClassInstances_MO_TS[1];
struct TinyPool MicrowaveOven_ClassInstancePool_MO_TS = {NULL, 0, 0, 0, 0};

/* Labels for access to valid start & end addresses for pool instances.
   (the end address is slighly below the real end address of the pool array,
    but _not_ below the address of the last instance in the pool array) */
const struct MicrowaveOven_TestSequences_MO_TS* MicrowaveOven_ClassInstances_MO_TS_start =
            &MicrowaveOven_ClassInstances_MO_TS[0];
const struct MicrowaveOven_TestSequences_MO_TS* MicrowaveOven_ClassInstances_MO_TS_end = (const void*) ((unsigned long)
            &MicrowaveOven_ClassInstances_MO_TS[0] + sizeof(MicrowaveOven_ClassInstances_MO_TS) - sizeof(int));

/* ---------------------------------------------------------------------------
 * Function for initializing class 'Test Sequences'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Initialize__MO_TS( void )
{
   /* Register the event queue polling function for this class */
   MicrowaveOven_ScheduleElement_MO_TS = MO_SYS_FUNC_RegisterQueuePoller( MicrowaveOven_Poll_MO_TS, false );

   /* Initialize the 'Test Sequences' class instance pool */
   {
      struct TinyPoolElement* previousElement = &MicrowaveOven_ClassInstances_MO_TS[0].poolElement;
      struct TinyPoolElement* theElement      = &MicrowaveOven_ClassInstances_MO_TS[0].poolElement;
      previousElement->next = theElement;
      theElement->previous  = previousElement;
      previousElement       = theElement;
      MicrowaveOven_ClassInstancePool_MO_TS.firstFreeElement      = &MicrowaveOven_ClassInstances_MO_TS[0].poolElement;
      MicrowaveOven_ClassInstancePool_MO_TS.numberOfFreeElements  = 1;
      MicrowaveOven_ClassInstancePool_MO_TS.theCapacity           = 1;
      MicrowaveOven_ClassInstancePool_MO_TS.numberOfUsedElements  = 0;
      MicrowaveOven_ClassInstancePool_MO_TS.highWaterMark         = 0;
   }

}

/* ---------------------------------------------------------------------------
 * Function for shutting down class 'Test Sequences'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Shutdown__MO_TS( void )
{
}

/* ---------------------------------------------------------------------------
 * Event Queue Info Function for class 'Test Sequences'
 * ---------------------------------------------------------------------------
 */
unsigned long MicrowaveOven_EventQueueInfo_MO_TS( void )
{
   /* Local variable declarations */
   unsigned long numberOfEventQueueJobs;

   /* Get the jobs on the EventQueue */
   numberOfEventQueueJobs = MicrowaveOven_EventQueue_MO_TS.numberOfPushedElements -
                            MicrowaveOven_EventQueue_MO_TS.numberOfPoppedElements;

   /* Get the jobs on the SelfEventQueue */
   numberOfEventQueueJobs += MicrowaveOven_SelfEventQueue_MO_TS.numberOfPushedElements -
                             MicrowaveOven_SelfEventQueue_MO_TS.numberOfPoppedElements;

   /* Return the queued jobs for this class */
   return numberOfEventQueueJobs;
}

/* ---------------------------------------------------------------------------
 * General Event Taker Function for class 'Test Sequences'
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_TakeEvent_MO_TS( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient )
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
         theQueue = &MicrowaveOven_SelfEventQueue_MO_TS;
      }
      else
      {
         /* Register the incomingEvent in the eventQueue */
         theQueue = &MicrowaveOven_EventQueue_MO_TS;
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
            if ( !(MicrowaveOven_ScheduleElement_MO_TS->isLinkedForScheduling) )
            {
               /* Check if scheduling of event queue polling not has been requested */
               if ( !MicrowaveOven_SchedulingRequested_MO_TS )
               {
                  /* Request scheduling of event queue polling by the dispatcher */
                  MO_SYS_FUNC_RequestScheduling( MicrowaveOven_ScheduleElement_MO_TS );

                  /* Indicate that scheduling of event queue polling is requested */
                  MicrowaveOven_SchedulingRequested_MO_TS = true;
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
 * Event Queue Polling Function for class 'Test Sequences'
 * (to be called from the system-level dispatcher)
 * ---------------------------------------------------------------------------
 */
void* MicrowaveOven_Poll_MO_TS( void )
{
   /* Declaration of local queue poller variables */
   const struct GenericEvent* queue_evt = NULL;
   struct TinyQueueElement* popElement;
   void* theEventData = NULL;
   const void* theRecipient = NULL;

   /* Check if the event queue polling function has been linked for scheduling */
   if ( MicrowaveOven_ScheduleElement_MO_TS->isLinkedForScheduling )
   {
      /* Prepare for a future event queue polling request */
      MicrowaveOven_SchedulingRequested_MO_TS = false;
   }

   /* Indicate that the event queue is being accessed */
   MO_SYS_FUNC_EventQueueIsAccessed = true;

   /* Check if self-directed events are available for processing */
   if ( MicrowaveOven_SelfEventQueue_MO_TS.numberOfPoppedElements !=
        MicrowaveOven_SelfEventQueue_MO_TS.numberOfPushedElements )
   {
      /* Retrieve the event from the selfEventQueue */
      popElement   = MicrowaveOven_SelfEventQueue_MO_TS.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_SelfEventQueue_MO_TS.firstElement = popElement->next;
         MicrowaveOven_SelfEventQueue_MO_TS.numberOfPoppedElements++;

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
   else if ( MicrowaveOven_EventQueue_MO_TS.numberOfPoppedElements !=
             MicrowaveOven_EventQueue_MO_TS.numberOfPushedElements )
   {
      /* Retrieve the event from the eventQueue */
      popElement   = MicrowaveOven_EventQueue_MO_TS.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_EventQueue_MO_TS.firstElement = popElement->next;
         MicrowaveOven_EventQueue_MO_TS.numberOfPoppedElements++;

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
         MicrowaveOven_ProcInstEvent_MO_TS( queue_evt, theEventData, theRecipient );
      }
   }

   /* Return an indication if an event was dequeued or not.
      NULL is returned (by default) if the queues were empty. */
   return (void*) queue_evt;
}

/* ---------------------------------------------------------------------------
 * Instance Event Processing Function for class 'Test Sequences'
 * ---------------------------------------------------------------------------
 */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_TS( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient )
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
      eventTrace_DequeuingEvent( MicrowaveOven_ClassName_MO_TS,
                                 true, queue_evt, eventData, recipient );

      /* Check if there is a valid recipient */
      if ( recipient != NULL )
      {
         /* Get the 'Test Sequences' target instance */
         struct MicrowaveOven_TestSequences_MO_TS* targetInst = (struct MicrowaveOven_TestSequences_MO_TS*) recipient;

         /* Get the current state for the target instance */
         currentState = (unsigned int) targetInst->currentISMstate_MO_TS;

         /* Get the destination state for the target instance */
         destState = (unsigned int) MicrowaveOven_InstanceSEM_MO_TS[currentState][eventCode];

         /* Register the currently executing state machine */
         registerCurrentStateMachine( MicrowaveOven_ClassName_MO_TS, recipient );

         /* CHECK THAT RECIPIENT INSTANCE NOT HAS BEEN DELETED */
         if ( currentState != MicrowaveOven_MO_TS_IS_NonExisting )
         {

            /* Check if the destination state is a valid state */
            if ( destState < MicrowaveOven_MO_TS_IS_NumberOfStates )
            {
               /* PROCESS THE EVENT */

               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_TS[currentState] );

               /* Print information about the destination state */
               eventTrace_GoingToState( MicrowaveOven_InstanceSDT_MO_TS[destState] );

               /* There are no Instance Transition Actions in this state machine */

               /* Execute the Instance State Action */
               {
                  InstanceStateActionPtrType instanceStateAction = MicrowaveOven_InstanceSAA_MO_TS[destState];
                  ( *instanceStateAction )( targetInst, NULL );
               }

               /* Check that the instance not has been deleted
                  during the execution of the state action code */
               if ( targetInst->currentISMstate_MO_TS != MicrowaveOven_MO_TS_IS_NonExisting )
               {
                  /* Set the new state for the target instance */
                  targetInst->currentISMstate_MO_TS = (unsigned char) destState;
               }
            }

            /* (there are no "can't happen" events for this state machine) */

            /* Check if this is an event that is "ignored" */
            else if ( destState == EventIsIgnored )
            {
               /* The received event is analyzed as "ignored" in current state */
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_TS[currentState] );
               eventTrace_EventIgnored();

               /* Trace output: Event Ignored */
               infoTrace_EventIgnored( "instance", MicrowaveOven_InstanceEDT_MO_TS[eventCode], MicrowaveOven_ClassName_MO_TS, MicrowaveOven_InstanceSDT_MO_TS[currentState] );
            }

            /* ...otherwise a fatal error has occurred */
            else
            {
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_TS[currentState] );

               /* A FATAL ERROR HAS OCCURRED WHEN HANDLING THIS EVENT
                  (destState error related to [currentState][eventCode] error) */
               eventTrace_FatalStateEventError();

               /* Trace output: Destination state error */
               errorTrace_DestinationStateError( "Instance", destState, currentState, eventCode, MicrowaveOven_ClassName_MO_TS, MicrowaveOven_InstanceEDT_MO_TS[eventCode] );
            }

         }
         else
         {
            /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
               (the 'recipient' of the event has been deleted) */

            /* Trace output: Event sent to deleted instance */
            errorTrace_EventToDeletedInstance( MicrowaveOven_InstanceEDT_MO_TS[eventCode], MicrowaveOven_ClassName_MO_TS );
            eventTrace_RecipientDeleted();
         }
      }
      else
      {
         /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
            (the 'recipient' of the event is == NULL) */

         /* Trace output: Instance pointer (recipient) == NULL */
         errorTrace_EventToNullRecipient( MicrowaveOven_InstanceEDT_MO_TS[eventCode], MicrowaveOven_ClassName_MO_TS );
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
 * Action code for Instance State 1. 'Awaiting Test Sequence Initiation'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA1_Awaiting_Test_Sequence_Initiation_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData )
{
   /* Local variable declarations */
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* GENERATE EVENT MO_TS2:'perform_test_seq_1' TO self */

   /* Get constant declaration for event MO_TS2:'perform_test_seq_1' */
   evt_2 = &MicrowaveOven_MO_TS2_IE_Const_Self;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = self;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_TS( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 2. 'Performing Test Sequence 1'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA2_Performing_Test_Sequence_1_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData )
{
   /* Local variable declarations */
   struct TimerEvent* terminate_timer;
   struct MicrowaveOven_Door_MO_D* door_p;
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   struct MicrowaveOven_Oven_MO_O* oven_p;
   const struct GenericEvent* finished = NULL;
   void* finished_data;
   const void* finished_recipient;

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step1_timer;
      const struct GenericEvent* release_door = NULL;
      void* release_door_data;
      const void* release_door_recipient;

      /* CREATE EVENT release_door OF MO_D1:'release' TO door */

      /* Get constant declaration for event MO_D1:'release' */
      release_door = &MicrowaveOven_MO_D1_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      release_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) release_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) release_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) release_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) release_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      release_door_recipient = door_p;

      /* ASSIGN VARIABLE step1_timer = TIM::timer_start( event_inst:release_door, microseconds:2000000 ) */
      step1_timer = TIM_timer_start(release_door, release_door_data, release_door_recipient, 2000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      release_door = NULL;

   }  /* END IF */

   /* SELECT ANY tube FROM INSTANCES OF CLASS Magnetron Tube */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Magnetron Tube */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_MT );

      tube_p = (struct MicrowaveOven_MagnetronTube_MO_MT*) instance;
   }

   /* if (not_empty tube) */
   if ((tube_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step2_timer;
      const struct GenericEvent* lower_power = NULL;
      void* lower_power_data;
      const void* lower_power_recipient;

      /* CREATE EVENT lower_power OF MO_MT2:'decrease_power' TO tube */

      /* Get constant declaration for event MO_MT2:'decrease_power' */
      lower_power = &MicrowaveOven_MO_MT2_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      lower_power_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) lower_power_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) lower_power_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) lower_power_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) lower_power_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      lower_power_recipient = tube_p;

      /* ASSIGN VARIABLE step2_timer = TIM::timer_start( event_inst:lower_power, microseconds:3000000 ) */
      step2_timer = TIM_timer_start(lower_power, lower_power_data, lower_power_recipient, 3000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      lower_power = NULL;

   }  /* END IF */

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step3_timer;
      const struct GenericEvent* close_door = NULL;
      void* close_door_data;
      const void* close_door_recipient;

      /* CREATE EVENT close_door OF MO_D2:'close' TO door */

      /* Get constant declaration for event MO_D2:'close' */
      close_door = &MicrowaveOven_MO_D2_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      close_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) close_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) close_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) close_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) close_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      close_door_recipient = door_p;

      /* ASSIGN VARIABLE step3_timer = TIM::timer_start( event_inst:close_door, microseconds:4000000 ) */
      step3_timer = TIM_timer_start(close_door, close_door_data, close_door_recipient, 4000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      close_door = NULL;

   }  /* END IF */

   /* SELECT ANY oven FROM INSTANCES OF CLASS Oven */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Oven */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_O );

      oven_p = (struct MicrowaveOven_Oven_MO_O*) instance;
   }

   /* if (not_empty oven) */
   if ((oven_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step4a_timer;
      struct TimerEvent* step4b_timer;
      const struct GenericEvent* cooking_time = NULL;
      void* cooking_time_data;
      const void* cooking_time_recipient;
      const struct GenericEvent* start = NULL;
      void* start_data;
      const void* start_recipient;

      /* CREATE EVENT cooking_time OF MO_O8:'cooking_period' TO oven */

      /* Get constant declaration for event MO_O8:'cooking_period' */
      cooking_time = &MicrowaveOven_MO_O8_IE_Const;

      /* Allocate memory for the event data instance */
      cooking_time_data = seizeEventDataMemory( sizeof(MicrowaveOven_MO_O8_IE_Data) );
      /* Clear the event handling flags */
      ((_OEDH_*) cooking_time_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) cooking_time_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) cooking_time_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) cooking_time_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      cooking_time_recipient = oven_p;
      /* ### DEFINE THE EVENT DATA ### */
      ((MicrowaveOven_MO_O8_IE_Data*) cooking_time_data)->period = 10000000;

      /* ASSIGN VARIABLE step4a_timer = TIM::timer_start( event_inst:cooking_time, microseconds:5000000 ) */
      step4a_timer = TIM_timer_start(cooking_time, cooking_time_data, cooking_time_recipient, 5000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      cooking_time = NULL;

      /* CREATE EVENT start OF MO_O3:'start_cooking' TO oven */

      /* Get constant declaration for event MO_O3:'start_cooking' */
      start = &MicrowaveOven_MO_O3_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      start_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) start_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) start_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) start_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) start_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      start_recipient = oven_p;

      /* ASSIGN VARIABLE step4b_timer = TIM::timer_start( event_inst:start, microseconds:5000001 ) */
      step4b_timer = TIM_timer_start(start, start_data, start_recipient, 5000001);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      start = NULL;

   }  /* END IF */

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step5_timer;
      const struct GenericEvent* release_door = NULL;
      void* release_door_data;
      const void* release_door_recipient;

      /* CREATE EVENT release_door OF MO_D1:'release' TO door */

      /* Get constant declaration for event MO_D1:'release' */
      release_door = &MicrowaveOven_MO_D1_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      release_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) release_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) release_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) release_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) release_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      release_door_recipient = door_p;

      /* ASSIGN VARIABLE step5_timer = TIM::timer_start( event_inst:release_door, microseconds:15000000 ) */
      step5_timer = TIM_timer_start(release_door, release_door_data, release_door_recipient, 15000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      release_door = NULL;

   }  /* END IF */

   /* CREATE EVENT finished OF MO_TS4:'test_seq_complete' TO self */

   /* Get constant declaration for event MO_TS4:'test_seq_complete' */
   finished = &MicrowaveOven_MO_TS4_IE_Const_Self;
   /* Allocate event data memory for event tracing purposes only */
   finished_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) finished_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) finished_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) finished_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) finished_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   finished_recipient = self;

   /* ASSIGN VARIABLE terminate_timer = TIM::timer_start( event_inst:finished, microseconds:30000000 ) */
   terminate_timer = TIM_timer_start(finished, finished_data, finished_recipient, 30000000);

   /* Clear the pre-created event reference when delivered
      (prevents sending the same event multiple times) */
   finished = NULL;

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 3. 'Performing Test Sequence 2'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA3_Performing_Test_Sequence_2_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData )
{
   /* Local variable declarations */
   struct TimerEvent* terminate_timer;
   struct MicrowaveOven_Door_MO_D* door_p;
   struct MicrowaveOven_Oven_MO_O* oven_p;
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   const struct GenericEvent* finished = NULL;
   void* finished_data;
   const void* finished_recipient;

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step1_timer;
      const struct GenericEvent* release_door = NULL;
      void* release_door_data;
      const void* release_door_recipient;

      /* CREATE EVENT release_door OF MO_D1:'release' TO door */

      /* Get constant declaration for event MO_D1:'release' */
      release_door = &MicrowaveOven_MO_D1_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      release_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) release_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) release_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) release_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) release_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      release_door_recipient = door_p;

      /* ASSIGN VARIABLE step1_timer = TIM::timer_start( event_inst:release_door, microseconds:2000000 ) */
      step1_timer = TIM_timer_start(release_door, release_door_data, release_door_recipient, 2000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      release_door = NULL;

   }  /* END IF */

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step2_timer;
      const struct GenericEvent* close_door = NULL;
      void* close_door_data;
      const void* close_door_recipient;

      /* CREATE EVENT close_door OF MO_D2:'close' TO door */

      /* Get constant declaration for event MO_D2:'close' */
      close_door = &MicrowaveOven_MO_D2_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      close_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) close_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) close_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) close_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) close_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      close_door_recipient = door_p;

      /* ASSIGN VARIABLE step2_timer = TIM::timer_start( event_inst:close_door, microseconds:4000000 ) */
      step2_timer = TIM_timer_start(close_door, close_door_data, close_door_recipient, 4000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      close_door = NULL;

   }  /* END IF */

   /* SELECT ANY oven FROM INSTANCES OF CLASS Oven */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Oven */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_O );

      oven_p = (struct MicrowaveOven_Oven_MO_O*) instance;
   }

   /* if (not_empty oven) */
   if ((oven_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step3a_timer;
      struct TimerEvent* step3b_timer;
      const struct GenericEvent* cooking_time = NULL;
      void* cooking_time_data;
      const void* cooking_time_recipient;
      const struct GenericEvent* start = NULL;
      void* start_data;
      const void* start_recipient;

      /* CREATE EVENT cooking_time OF MO_O8:'cooking_period' TO oven */

      /* Get constant declaration for event MO_O8:'cooking_period' */
      cooking_time = &MicrowaveOven_MO_O8_IE_Const;

      /* Allocate memory for the event data instance */
      cooking_time_data = seizeEventDataMemory( sizeof(MicrowaveOven_MO_O8_IE_Data) );
      /* Clear the event handling flags */
      ((_OEDH_*) cooking_time_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) cooking_time_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) cooking_time_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) cooking_time_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      cooking_time_recipient = oven_p;
      /* ### DEFINE THE EVENT DATA ### */
      ((MicrowaveOven_MO_O8_IE_Data*) cooking_time_data)->period = 15000000;

      /* ASSIGN VARIABLE step3a_timer = TIM::timer_start( event_inst:cooking_time, microseconds:5000000 ) */
      step3a_timer = TIM_timer_start(cooking_time, cooking_time_data, cooking_time_recipient, 5000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      cooking_time = NULL;

      /* CREATE EVENT start OF MO_O3:'start_cooking' TO oven */

      /* Get constant declaration for event MO_O3:'start_cooking' */
      start = &MicrowaveOven_MO_O3_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      start_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) start_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) start_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) start_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) start_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      start_recipient = oven_p;

      /* ASSIGN VARIABLE step3b_timer = TIM::timer_start( event_inst:start, microseconds:5000001 ) */
      step3b_timer = TIM_timer_start(start, start_data, start_recipient, 5000001);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      start = NULL;

   }  /* END IF */

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step4_timer;
      const struct GenericEvent* release_door = NULL;
      void* release_door_data;
      const void* release_door_recipient;

      /* CREATE EVENT release_door OF MO_D1:'release' TO door */

      /* Get constant declaration for event MO_D1:'release' */
      release_door = &MicrowaveOven_MO_D1_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      release_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) release_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) release_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) release_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) release_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      release_door_recipient = door_p;

      /* ASSIGN VARIABLE step4_timer = TIM::timer_start( event_inst:release_door, microseconds:6000000 ) */
      step4_timer = TIM_timer_start(release_door, release_door_data, release_door_recipient, 6000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      release_door = NULL;

   }  /* END IF */

   /* SELECT ANY tube FROM INSTANCES OF CLASS Magnetron Tube */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Magnetron Tube */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_MT );

      tube_p = (struct MicrowaveOven_MagnetronTube_MO_MT*) instance;
   }

   /* if (not_empty tube) */
   if ((tube_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step5a_timer;
      struct TimerEvent* step5b_timer;
      const struct GenericEvent* lower_power = NULL;
      void* lower_power_data;
      const void* lower_power_recipient;

      /* CREATE EVENT lower_power OF MO_MT2:'decrease_power' TO tube */

      /* Get constant declaration for event MO_MT2:'decrease_power' */
      lower_power = &MicrowaveOven_MO_MT2_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      lower_power_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) lower_power_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) lower_power_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) lower_power_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) lower_power_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      lower_power_recipient = tube_p;

      /* ASSIGN VARIABLE step5a_timer = TIM::timer_start( event_inst:lower_power, microseconds:3000000 ) */
      step5a_timer = TIM_timer_start(lower_power, lower_power_data, lower_power_recipient, 3000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      lower_power = NULL;

      /* ASSIGN VARIABLE step5b_timer = TIM::timer_start( event_inst:lower_power, microseconds:3000001 ) */
      step5b_timer = TIM_timer_start(lower_power, lower_power_data, lower_power_recipient, 3000001);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      lower_power = NULL;

   }  /* END IF */

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* if (not_empty door) */
   if ((door_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step6_timer;
      const struct GenericEvent* close_door = NULL;
      void* close_door_data;
      const void* close_door_recipient;

      /* CREATE EVENT close_door OF MO_D2:'close' TO door */

      /* Get constant declaration for event MO_D2:'close' */
      close_door = &MicrowaveOven_MO_D2_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      close_door_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) close_door_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) close_door_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) close_door_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) close_door_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      close_door_recipient = door_p;

      /* ASSIGN VARIABLE step6_timer = TIM::timer_start( event_inst:close_door, microseconds:9000000 ) */
      step6_timer = TIM_timer_start(close_door, close_door_data, close_door_recipient, 9000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      close_door = NULL;

   }  /* END IF */

   /* SELECT ANY oven FROM INSTANCES OF CLASS Oven */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Oven */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_O );

      oven_p = (struct MicrowaveOven_Oven_MO_O*) instance;
   }

   /* if (not_empty oven) */
   if ((oven_p != NULL))
   {
      /* Local variable declarations */
      struct TimerEvent* step7_timer;
      const struct GenericEvent* restart = NULL;
      void* restart_data;
      const void* restart_recipient;

      /* CREATE EVENT restart OF MO_O3:'start_cooking' TO oven */

      /* Get constant declaration for event MO_O3:'start_cooking' */
      restart = &MicrowaveOven_MO_O3_IE_Const;
      /* Allocate event data memory for event tracing purposes only */
      restart_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
      /* Clear the event handling flags */
      ((_OEDH_*) restart_data)->_header_.eventFlags = FlagsUndefined;
      ((_OEDH_*) restart_data)->_header_.timeInformationAvailable = false;
      ((_OEDH_*) restart_data)->_header_.senderClassName = currentThread_ExecutingClassName();
      ((_OEDH_*) restart_data)->_header_.senderInstance = currentThread_ExecutingInstance();
      restart_recipient = oven_p;

      /* ASSIGN VARIABLE step7_timer = TIM::timer_start( event_inst:restart, microseconds:10000000 ) */
      step7_timer = TIM_timer_start(restart, restart_data, restart_recipient, 10000000);

      /* Clear the pre-created event reference when delivered
         (prevents sending the same event multiple times) */
      restart = NULL;

   }  /* END IF */

   /* CREATE EVENT finished OF MO_TS4:'test_seq_complete' TO self */

   /* Get constant declaration for event MO_TS4:'test_seq_complete' */
   finished = &MicrowaveOven_MO_TS4_IE_Const_Self;
   /* Allocate event data memory for event tracing purposes only */
   finished_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) finished_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) finished_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) finished_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) finished_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   finished_recipient = self;

   /* ASSIGN VARIABLE terminate_timer = TIM::timer_start( event_inst:finished, microseconds:30000000 ) */
   terminate_timer = TIM_timer_start(finished, finished_data, finished_recipient, 30000000);

   /* Clear the pre-created event reference when delivered
      (prevents sending the same event multiple times) */
   finished = NULL;

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 4. 'Cooking Complete'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA4_Cooking_Complete_MO_TS( struct MicrowaveOven_TestSequences_MO_TS* self, const void* eventData )
{

   /* INVOKE THE APPLICATION SHUTDOWN FUNCTION */
   MO_SYS_FUNC_Shutdown();

}

/* ### End of File MicrowaveOven_TestSequences_MO_TS.c ### */
