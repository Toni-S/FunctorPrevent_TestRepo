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
 *  File Name .............. MicrowaveOven_MagnetronTube_MO_MT.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MicrowaveOven_MagnetronTube_MO_MT.h"
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
/* Event Queue Polling Function for class 'Magnetron Tube'
   (to be called from the system-level dispatcher) */
void* MicrowaveOven_Poll_MO_MT( void );

/* Instance Event Processing Function for class 'Magnetron Tube' */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_MT( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient );

/* Action code for Instance State 2. 'Reducing Output Power' */
static void MicrowaveOven_ISA2_Reducing_Output_Power_MO_MT( struct MicrowaveOven_MagnetronTube_MO_MT* self, const void* eventData );

/* Action code for Instance State 3. 'Raising Output Power' */
static void MicrowaveOven_ISA3_Raising_Output_Power_MO_MT( struct MicrowaveOven_MagnetronTube_MO_MT* self, const void* eventData );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
const char* MicrowaveOven_ClassName_MO_MT = "Magnetron Tube (MO_MT)";

/* Chain holding all existing instances of class 'Magnetron Tube' */
struct TinyChain MicrowaveOven_InstanceChain_MO_MT = {NULL, NULL, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Queues
 * ---------------------------------------------------------------------------
 */
/* Event Queues for class 'Magnetron Tube' */
static struct TinyQueue MicrowaveOven_EventQueue_MO_MT     = {NULL, NULL, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Dispatcher Variables
 * ---------------------------------------------------------------------------
 */
/* Pointer to the schedule element holding the event queue poller for this class */
static struct TinyScheduleElement* MicrowaveOven_ScheduleElement_MO_MT = NULL;

/* Scheduling request status variable for this class
   (this is for preventing multiple scheduling requests) */
static fastBool MicrowaveOven_SchedulingRequested_MO_MT = false;

/* ---------------------------------------------------------------------------
 * Instance Event & State Description Texts
 * ---------------------------------------------------------------------------
 */
/* Instance Event description texts for class 'Magnetron Tube'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceEDT_MO_MT[4] =
{
   "MO_MT1:'increase_power'",
   "MO_MT2:'decrease_power'",
   "MO_MT3:'power_on'",
   "MO_MT4:'power_off'"
};

/* Instance State description texts for class 'Magnetron Tube'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceSDT_MO_MT[5] =
{
   "'NonExisting' (= deleted instance)",
   "'1. Output Power Stable and OFF'",
   "'2. Reducing Output Power'",
   "'3. Raising Output Power'",
   "'4. Output Power Stable and ON'"
};

/* Instance Event Data Printer Array for class 'Magnetron Tube'
   containing pointers to printout functions for event data signatures */
static const EventDataPrinterPtrType MicrowaveOven_InstanceEDPA_MO_MT[4] =
{
   (EventDataPrinterPtrType) NULL,  /* Event MO_MT1 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_MT2 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_MT3 has no event data */
   (EventDataPrinterPtrType) NULL   /* Event MO_MT4 has no event data */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Instance Event (IE) Codes for class 'Magnetron Tube'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_MT1_IE_Code = 0,  /* Code for MO_MT1:'increase_power' */
   MicrowaveOven_MO_MT2_IE_Code = 1,  /* Code for MO_MT2:'decrease_power' */
   MicrowaveOven_MO_MT3_IE_Code = 2,  /* Code for MO_MT3:'power_on' */
   MicrowaveOven_MO_MT4_IE_Code = 3   /* Code for MO_MT4:'power_off' */
};

/* Constant for event MO_MT1:'increase_power' */
const struct GenericEvent MicrowaveOven_MO_MT1_IE_Const =
      { (MicrowaveOven_MO_MT1_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_MT[0],
         &MicrowaveOven_InstanceEDPA_MO_MT[0],
         MicrowaveOven_TakeEvent_MO_MT,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_MT2:'decrease_power' */
const struct GenericEvent MicrowaveOven_MO_MT2_IE_Const =
      { (MicrowaveOven_MO_MT2_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_MT[1],
         &MicrowaveOven_InstanceEDPA_MO_MT[1],
         MicrowaveOven_TakeEvent_MO_MT,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_MT3:'power_on' */
const struct GenericEvent MicrowaveOven_MO_MT3_IE_Const =
      { (MicrowaveOven_MO_MT3_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_MT[2],
         &MicrowaveOven_InstanceEDPA_MO_MT[2],
         MicrowaveOven_TakeEvent_MO_MT,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_MT4:'power_off' */
const struct GenericEvent MicrowaveOven_MO_MT4_IE_Const =
      { (MicrowaveOven_MO_MT4_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_MT[3],
         &MicrowaveOven_InstanceEDPA_MO_MT[3],
         MicrowaveOven_TakeEvent_MO_MT,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* ---------------------------------------------------------------------------
 * Instance State Event Matrix and Action Procedure Array(s)
 * ---------------------------------------------------------------------------
 */
/* Instance State Event Matrix (SEM) for class 'Magnetron Tube'
   containing 'destination state' codes for all events in all states */
static const unsigned char MicrowaveOven_InstanceSEM_MO_MT[5][4] =
{
   /* Entries for additional state 'NonExisting'  (entered when deleted) */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 1 'Output Power Stable and OFF' */
   { MicrowaveOven_MO_MT_IS3_3_Raising_Output_Power,
     MicrowaveOven_MO_MT_IS2_2_Reducing_Output_Power,
     MicrowaveOven_MO_MT_IS4_4_Output_Power_Stable_and_ON,
     EventIsIgnored },

   /* Entries for Instance State 2 'Reducing Output Power' */
   { MicrowaveOven_MO_MT_IS3_3_Raising_Output_Power,
     MicrowaveOven_MO_MT_IS2_2_Reducing_Output_Power,
     MicrowaveOven_MO_MT_IS4_4_Output_Power_Stable_and_ON,
     MicrowaveOven_MO_MT_IS1_1_Output_Power_Stable_and_OFF },

   /* Entries for Instance State 3 'Raising Output Power' */
   { MicrowaveOven_MO_MT_IS3_3_Raising_Output_Power,
     MicrowaveOven_MO_MT_IS2_2_Reducing_Output_Power,
     MicrowaveOven_MO_MT_IS4_4_Output_Power_Stable_and_ON,
     MicrowaveOven_MO_MT_IS1_1_Output_Power_Stable_and_OFF },

   /* Entries for Instance State 4 'Output Power Stable and ON' */
   { MicrowaveOven_MO_MT_IS3_3_Raising_Output_Power,
     MicrowaveOven_MO_MT_IS2_2_Reducing_Output_Power,
     EventIsIgnored,
     MicrowaveOven_MO_MT_IS1_1_Output_Power_Stable_and_OFF }
};

/* Instance State Actions Array (SAA) for class 'Magnetron Tube'
   containing pointers to actions for all Instance States */
static const InstanceStateActionPtrType MicrowaveOven_InstanceSAA_MO_MT[5] =
{
   (InstanceStateActionPtrType) NULL,  /* The additional state 'NonExisting' has no action procedure */
   (InstanceStateActionPtrType) NULL,  /* State 1. 'Output Power Stable and OFF' has no action procedure */
   (InstanceStateActionPtrType) MicrowaveOven_ISA2_Reducing_Output_Power_MO_MT,
   (InstanceStateActionPtrType) MicrowaveOven_ISA3_Raising_Output_Power_MO_MT,
   (InstanceStateActionPtrType) NULL   /* State 4. 'Output Power Stable and ON' has no action procedure */
};

/* ---------------------------------------------------------------------------
 * Class Instance Pool
 * ---------------------------------------------------------------------------
 */
/* The 'Magnetron Tube' class instance pool */
struct MicrowaveOven_MagnetronTube_MO_MT MicrowaveOven_ClassInstances_MO_MT[1];
struct TinyPool MicrowaveOven_ClassInstancePool_MO_MT = {NULL, 0, 0, 0, 0};

/* Labels for access to valid start & end addresses for pool instances.
   (the end address is slighly below the real end address of the pool array,
    but _not_ below the address of the last instance in the pool array) */
const struct MicrowaveOven_MagnetronTube_MO_MT* MicrowaveOven_ClassInstances_MO_MT_start =
            &MicrowaveOven_ClassInstances_MO_MT[0];
const struct MicrowaveOven_MagnetronTube_MO_MT* MicrowaveOven_ClassInstances_MO_MT_end = (const void*) ((unsigned long)
            &MicrowaveOven_ClassInstances_MO_MT[0] + sizeof(MicrowaveOven_ClassInstances_MO_MT) - sizeof(int));

/* ---------------------------------------------------------------------------
 * Function for initializing class 'Magnetron Tube'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Initialize__MO_MT( void )
{
   /* Register the event queue polling function for this class */
   MicrowaveOven_ScheduleElement_MO_MT = MO_SYS_FUNC_RegisterQueuePoller( MicrowaveOven_Poll_MO_MT, false );

   /* Initialize the 'Magnetron Tube' class instance pool */
   {
      struct TinyPoolElement* previousElement = &MicrowaveOven_ClassInstances_MO_MT[0].poolElement;
      struct TinyPoolElement* theElement      = &MicrowaveOven_ClassInstances_MO_MT[0].poolElement;
      previousElement->next = theElement;
      theElement->previous  = previousElement;
      previousElement       = theElement;
      MicrowaveOven_ClassInstancePool_MO_MT.firstFreeElement      = &MicrowaveOven_ClassInstances_MO_MT[0].poolElement;
      MicrowaveOven_ClassInstancePool_MO_MT.numberOfFreeElements  = 1;
      MicrowaveOven_ClassInstancePool_MO_MT.theCapacity           = 1;
      MicrowaveOven_ClassInstancePool_MO_MT.numberOfUsedElements  = 0;
      MicrowaveOven_ClassInstancePool_MO_MT.highWaterMark         = 0;
   }

}

/* ---------------------------------------------------------------------------
 * Function for shutting down class 'Magnetron Tube'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Shutdown__MO_MT( void )
{
}

/* ---------------------------------------------------------------------------
 * Event Queue Info Function for class 'Magnetron Tube'
 * ---------------------------------------------------------------------------
 */
unsigned long MicrowaveOven_EventQueueInfo_MO_MT( void )
{
   /* Local variable declarations */
   unsigned long numberOfEventQueueJobs;

   /* Get the jobs on the EventQueue */
   numberOfEventQueueJobs = MicrowaveOven_EventQueue_MO_MT.numberOfPushedElements -
                            MicrowaveOven_EventQueue_MO_MT.numberOfPoppedElements;

   /* Return the queued jobs for this class */
   return numberOfEventQueueJobs;
}

/* ---------------------------------------------------------------------------
 * General Event Taker Function for class 'Magnetron Tube'
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_TakeEvent_MO_MT( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient )
{
   /* Check if a valid event was received */
   if ( incomingEvent != NULL )
   {
      /* Register the incomingEvent in the eventQueue */
      struct TinyQueue* theQueue = &MicrowaveOven_EventQueue_MO_MT;

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
            if ( !(MicrowaveOven_ScheduleElement_MO_MT->isLinkedForScheduling) )
            {
               /* Check if scheduling of event queue polling not has been requested */
               if ( !MicrowaveOven_SchedulingRequested_MO_MT )
               {
                  /* Request scheduling of event queue polling by the dispatcher */
                  MO_SYS_FUNC_RequestScheduling( MicrowaveOven_ScheduleElement_MO_MT );

                  /* Indicate that scheduling of event queue polling is requested */
                  MicrowaveOven_SchedulingRequested_MO_MT = true;
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
 * Event Queue Polling Function for class 'Magnetron Tube'
 * (to be called from the system-level dispatcher)
 * ---------------------------------------------------------------------------
 */
void* MicrowaveOven_Poll_MO_MT( void )
{
   /* Declaration of local queue poller variables */
   const struct GenericEvent* queue_evt = NULL;
   struct TinyQueueElement* popElement;
   void* theEventData = NULL;
   const void* theRecipient = NULL;

   /* Check if the event queue polling function has been linked for scheduling */
   if ( MicrowaveOven_ScheduleElement_MO_MT->isLinkedForScheduling )
   {
      /* Prepare for a future event queue polling request */
      MicrowaveOven_SchedulingRequested_MO_MT = false;
   }

   /* Indicate that the event queue is being accessed */
   MO_SYS_FUNC_EventQueueIsAccessed = true;

   /* Check if events are available for processing */
   if ( MicrowaveOven_EventQueue_MO_MT.numberOfPoppedElements !=
        MicrowaveOven_EventQueue_MO_MT.numberOfPushedElements )
   {
      /* Retrieve the event from the eventQueue */
      popElement   = MicrowaveOven_EventQueue_MO_MT.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_EventQueue_MO_MT.firstElement = popElement->next;
         MicrowaveOven_EventQueue_MO_MT.numberOfPoppedElements++;

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
         MicrowaveOven_ProcInstEvent_MO_MT( queue_evt, theEventData, theRecipient );
      }
   }

   /* Return an indication if an event was dequeued or not.
      NULL is returned (by default) if the queues were empty. */
   return (void*) queue_evt;
}

/* ---------------------------------------------------------------------------
 * Instance Event Processing Function for class 'Magnetron Tube'
 * ---------------------------------------------------------------------------
 */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_MT( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient )
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
      eventTrace_DequeuingEvent( MicrowaveOven_ClassName_MO_MT,
                                 true, queue_evt, eventData, recipient );

      /* Check if there is a valid recipient */
      if ( recipient != NULL )
      {
         /* Get the 'Magnetron Tube' target instance */
         struct MicrowaveOven_MagnetronTube_MO_MT* targetInst = (struct MicrowaveOven_MagnetronTube_MO_MT*) recipient;

         /* Get the current state for the target instance */
         currentState = (unsigned int) targetInst->currentISMstate_MO_MT;

         /* Get the destination state for the target instance */
         destState = (unsigned int) MicrowaveOven_InstanceSEM_MO_MT[currentState][eventCode];

         /* Register the currently executing state machine */
         registerCurrentStateMachine( MicrowaveOven_ClassName_MO_MT, recipient );

         /* CHECK THAT RECIPIENT INSTANCE NOT HAS BEEN DELETED */
         if ( currentState != MicrowaveOven_MO_MT_IS_NonExisting )
         {

            /* Check if the destination state is a valid state */
            if ( destState < MicrowaveOven_MO_MT_IS_NumberOfStates )
            {
               /* PROCESS THE EVENT */

               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_MT[currentState] );

               /* Print information about the destination state */
               eventTrace_GoingToState( MicrowaveOven_InstanceSDT_MO_MT[destState] );

               /* There are no Instance Transition Actions in this state machine */

               /* Execute the Instance State Action */
               {
                  InstanceStateActionPtrType instanceStateAction = MicrowaveOven_InstanceSAA_MO_MT[destState];
                  if ( instanceStateAction )
                  { ( *instanceStateAction )( targetInst, NULL ); }
               }

               /* Check that the instance not has been deleted
                  during the execution of the state action code */
               if ( targetInst->currentISMstate_MO_MT != MicrowaveOven_MO_MT_IS_NonExisting )
               {
                  /* Set the new state for the target instance */
                  targetInst->currentISMstate_MO_MT = (unsigned char) destState;
               }
            }

            /* (there are no "can't happen" events for this state machine) */

            /* Check if this is an event that is "ignored" */
            else if ( destState == EventIsIgnored )
            {
               /* The received event is analyzed as "ignored" in current state */
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_MT[currentState] );
               eventTrace_EventIgnored();

               /* Trace output: Event Ignored */
               infoTrace_EventIgnored( "instance", MicrowaveOven_InstanceEDT_MO_MT[eventCode], MicrowaveOven_ClassName_MO_MT, MicrowaveOven_InstanceSDT_MO_MT[currentState] );
            }

            /* ...otherwise a fatal error has occurred */
            else
            {
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_MT[currentState] );

               /* A FATAL ERROR HAS OCCURRED WHEN HANDLING THIS EVENT
                  (destState error related to [currentState][eventCode] error) */
               eventTrace_FatalStateEventError();

               /* Trace output: Destination state error */
               errorTrace_DestinationStateError( "Instance", destState, currentState, eventCode, MicrowaveOven_ClassName_MO_MT, MicrowaveOven_InstanceEDT_MO_MT[eventCode] );
            }

         }
         else
         {
            /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
               (the 'recipient' of the event has been deleted) */

            /* Trace output: Event sent to deleted instance */
            errorTrace_EventToDeletedInstance( MicrowaveOven_InstanceEDT_MO_MT[eventCode], MicrowaveOven_ClassName_MO_MT );
            eventTrace_RecipientDeleted();
         }
      }
      else
      {
         /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
            (the 'recipient' of the event is == NULL) */

         /* Trace output: Instance pointer (recipient) == NULL */
         errorTrace_EventToNullRecipient( MicrowaveOven_InstanceEDT_MO_MT[eventCode], MicrowaveOven_ClassName_MO_MT );
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
 * Action code for Instance State 2. 'Reducing Output Power'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA2_Reducing_Output_Power_MO_MT( struct MicrowaveOven_MagnetronTube_MO_MT* self, const void* eventData )
{
   switch (self->current_power_output_MO_MT)
   {
      case MicrowaveOven_tube_wattage_med_low:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::low */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_low;

         break;
      }
      case MicrowaveOven_tube_wattage_medium:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::med_low */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_med_low;

         break;
      }
      case MicrowaveOven_tube_wattage_med_high:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::medium */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_medium;

         break;
      }
      case MicrowaveOven_tube_wattage_high:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::med_high */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_med_high;

         break;
      }
      default:
      {
         break;
      }
   }

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 3. 'Raising Output Power'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA3_Raising_Output_Power_MO_MT( struct MicrowaveOven_MagnetronTube_MO_MT* self, const void* eventData )
{
   switch (self->current_power_output_MO_MT)
   {
      case MicrowaveOven_tube_wattage_low:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::med_low */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_med_low;

         break;
      }
      case MicrowaveOven_tube_wattage_med_low:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::medium */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_medium;

         break;
      }
      case MicrowaveOven_tube_wattage_medium:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::med_high */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_med_high;

         break;
      }
      case MicrowaveOven_tube_wattage_med_high:
      {
         /* ASSIGN ATTRIBUTE self.current_power_output = tube_wattage::high */
         self->current_power_output_MO_MT = MicrowaveOven_tube_wattage_high;

         break;
      }
      default:
      {
         break;
      }
   }

}

/* ### End of File MicrowaveOven_MagnetronTube_MO_MT.c ### */
