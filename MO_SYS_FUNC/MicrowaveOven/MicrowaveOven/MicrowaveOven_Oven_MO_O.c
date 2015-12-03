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
 *  File Name .............. MicrowaveOven_Oven_MO_O.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
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
/* Event Queue Polling Function for class 'Oven'
   (to be called from the system-level dispatcher) */
void* MicrowaveOven_Poll_MO_O( void );

/* Instance Event Processing Function for class 'Oven' */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_O( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient );

/* Action code for Instance State 1. 'Awaiting Cooking Request' */
static void MicrowaveOven_ISA1_Awaiting_Cooking_Request_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData );

/* Action code for Instance State 2. 'Ensuring Safe to Cook' */
static void MicrowaveOven_ISA2_Ensuring_Safe_to_Cook_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData );

/* Action code for Instance State 3. 'Cooking' */
static void MicrowaveOven_ISA3_Cooking_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData );

/* Action code for Instance State 4. 'Cooking Suspended' */
static void MicrowaveOven_ISA4_Cooking_Suspended_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData );

/* Action code for Instance State 5. 'Signalling Cooking Period Over' */
static void MicrowaveOven_ISA5_Signalling_Cooking_Period_Over_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData );

/* Action code for Instance State 6. 'Assigning Cooking Period' */
static void MicrowaveOven_ISA6_Assigning_Cooking_Period_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData );

/* Event data printout function for MO_O8:'cooking_period' */
static void print_MicrowaveOven_MO_O8_IE_Data( const void* eventData );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
const char* MicrowaveOven_ClassName_MO_O = "Oven (MO_O)";

/* Chain holding all existing instances of class 'Oven' */
struct TinyChain MicrowaveOven_InstanceChain_MO_O = {NULL, NULL, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Queues
 * ---------------------------------------------------------------------------
 */
/* Event Queues for class 'Oven' */
static struct TinyQueue MicrowaveOven_EventQueue_MO_O     = {NULL, NULL, 0, 0, 0};
static struct TinyQueue MicrowaveOven_SelfEventQueue_MO_O = {NULL, NULL, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * State Machine Event Dispatcher Variables
 * ---------------------------------------------------------------------------
 */
/* Pointer to the schedule element holding the event queue poller for this class */
static struct TinyScheduleElement* MicrowaveOven_ScheduleElement_MO_O = NULL;

/* Scheduling request status variable for this class
   (this is for preventing multiple scheduling requests) */
static fastBool MicrowaveOven_SchedulingRequested_MO_O = false;

/* ---------------------------------------------------------------------------
 * Instance Event & State Description Texts
 * ---------------------------------------------------------------------------
 */
/* Instance Event description texts for class 'Oven'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceEDT_MO_O[8] =
{
   "MO_O1:'initialise'",
   "MO_O3:'start_cooking'",
   "MO_O4:'cancel_cooking'",
   "MO_O2:'oven_initialised'",
   "MO_O5:'cooking_period_over'",
   "MO_O6:'beeping_over'",
   "MO_O7:'oven_safe'",
   "MO_O8:'cooking_period'"
};

/* Instance State description texts for class 'Oven'
   (for use e.g. during run-time tracing of dequeued events) */
static const char* MicrowaveOven_InstanceSDT_MO_O[7] =
{
   "'NonExisting' (= deleted instance)",
   "'1. Awaiting Cooking Request'",
   "'2. Ensuring Safe to Cook'",
   "'3. Cooking'",
   "'4. Cooking Suspended'",
   "'5. Signalling Cooking Period Over'",
   "'6. Assigning Cooking Period'"
};

/* Instance Event Data Printer Array for class 'Oven'
   containing pointers to printout functions for event data signatures */
static const EventDataPrinterPtrType MicrowaveOven_InstanceEDPA_MO_O[8] =
{
   (EventDataPrinterPtrType) NULL,  /* Event MO_O1 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_O3 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_O4 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_O2 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_O5 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_O6 has no event data */
   (EventDataPrinterPtrType) NULL,  /* Event MO_O7 has no event data */
   (EventDataPrinterPtrType) print_MicrowaveOven_MO_O8_IE_Data
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Instance Event (IE) Codes for class 'Oven'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_O1_IE_Code = 0,  /* Code for MO_O1:'initialise' */
   MicrowaveOven_MO_O3_IE_Code = 1,  /* Code for MO_O3:'start_cooking' */
   MicrowaveOven_MO_O4_IE_Code = 2,  /* Code for MO_O4:'cancel_cooking' */
   MicrowaveOven_MO_O2_IE_Code = 3,  /* Code for MO_O2:'oven_initialised' */
   MicrowaveOven_MO_O5_IE_Code = 4,  /* Code for MO_O5:'cooking_period_over' */
   MicrowaveOven_MO_O6_IE_Code = 5,  /* Code for MO_O6:'beeping_over' */
   MicrowaveOven_MO_O7_IE_Code = 6,  /* Code for MO_O7:'oven_safe' */
   MicrowaveOven_MO_O8_IE_Code = 7   /* Code for MO_O8:'cooking_period' */
};

/* Constant for event MO_O1:'initialise' */
const struct GenericEvent MicrowaveOven_MO_O1_IE_Const =
      { (MicrowaveOven_MO_O1_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[0],
         &MicrowaveOven_InstanceEDPA_MO_O[0],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O3:'start_cooking' */
const struct GenericEvent MicrowaveOven_MO_O3_IE_Const =
      { (MicrowaveOven_MO_O3_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[1],
         &MicrowaveOven_InstanceEDPA_MO_O[1],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O4:'cancel_cooking' */
const struct GenericEvent MicrowaveOven_MO_O4_IE_Const =
      { (MicrowaveOven_MO_O4_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[2],
         &MicrowaveOven_InstanceEDPA_MO_O[2],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O2:'oven_initialised' */
const struct GenericEvent MicrowaveOven_MO_O2_IE_Const =
      { (MicrowaveOven_MO_O2_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[3],
         &MicrowaveOven_InstanceEDPA_MO_O[3],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O5:'cooking_period_over' */
const struct GenericEvent MicrowaveOven_MO_O5_IE_Const =
      { (MicrowaveOven_MO_O5_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[4],
         &MicrowaveOven_InstanceEDPA_MO_O[4],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };
/* (constant to use when self-directed signal) */
const struct GenericEvent MicrowaveOven_MO_O5_IE_Const_Self =
      { (MicrowaveOven_MO_O5_IE_Code << 16) +
         IsSelfDirected,
         &MicrowaveOven_InstanceEDT_MO_O[4],
         &MicrowaveOven_InstanceEDPA_MO_O[4],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O6:'beeping_over' */
const struct GenericEvent MicrowaveOven_MO_O6_IE_Const =
      { (MicrowaveOven_MO_O6_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[5],
         &MicrowaveOven_InstanceEDPA_MO_O[5],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O7:'oven_safe' */
const struct GenericEvent MicrowaveOven_MO_O7_IE_Const =
      { (MicrowaveOven_MO_O7_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[6],
         &MicrowaveOven_InstanceEDPA_MO_O[6],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };
/* (constant to use when self-directed signal) */
const struct GenericEvent MicrowaveOven_MO_O7_IE_Const_Self =
      { (MicrowaveOven_MO_O7_IE_Code << 16) +
         IsSelfDirected,
         &MicrowaveOven_InstanceEDT_MO_O[6],
         &MicrowaveOven_InstanceEDPA_MO_O[6],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* Constant for event MO_O8:'cooking_period' */
const struct GenericEvent MicrowaveOven_MO_O8_IE_Const =
      { (MicrowaveOven_MO_O8_IE_Code << 16) +
         TypeUndefined,
         &MicrowaveOven_InstanceEDT_MO_O[7],
         &MicrowaveOven_InstanceEDPA_MO_O[7],
         MicrowaveOven_TakeEvent_MO_O,
         &MO_SYS_FUNC_EventQueueIsAccessed };

/* ---------------------------------------------------------------------------
 * Instance State Data Signature Structures & Variables
 * ---------------------------------------------------------------------------
 */
/* No State Data Signature Structure declarations are needed
   (state actions are accessing incoming event data directly) */

/* Instance State Data Variable Array (SDVA) for class 'Oven'
   containing pointers to all Instance Event Data Variables */
static const void* MicrowaveOven_InstanceSDVA_MO_O[7] =
{
   NULL,  /* The additional state 'NonExisting' does not exist */
   NULL,  /* There is no event data access in state 1. 'Awaiting Cooking Request' */
   NULL,  /* There is no event data access in state 2. 'Ensuring Safe to Cook' */
   NULL,  /* There is no event data access in state 3. 'Cooking' */
   NULL,  /* There is no event data access in state 4. 'Cooking Suspended' */
   NULL,  /* There is no event data access in state 5. 'Signalling Cooking Period Over' */
   DirectEventDataAccess   /* State 6. 'Assigning Cooking Period' receives incoming event data directly */
};

/* ---------------------------------------------------------------------------
 * Instance State Event Matrix and Action Procedure Array(s)
 * ---------------------------------------------------------------------------
 */
/* Instance State Event Matrix (SEM) for class 'Oven'
   containing 'destination state' codes for all events in all states */
static const unsigned char MicrowaveOven_InstanceSEM_MO_O[7][8] =
{
   /* Entries for additional state 'NonExisting'  (entered when deleted) */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 1 'Awaiting Cooking Request' */
   { EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_O_IS6_6_Assigning_Cooking_Period },

   /* Entries for Instance State 2 'Ensuring Safe to Cook' */
   { EventIsIgnored,
     MicrowaveOven_MO_O_IS2_2_Ensuring_Safe_to_Cook,
     MicrowaveOven_MO_O_IS1_1_Awaiting_Cooking_Request,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_O_IS3_3_Cooking,
     EventIsIgnored },

   /* Entries for Instance State 3 'Cooking' */
   { EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_O_IS4_4_Cooking_Suspended,
     EventIsIgnored,
     MicrowaveOven_MO_O_IS5_5_Signalling_Cooking_Period_Over,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 4 'Cooking Suspended' */
   { EventIsIgnored,
     MicrowaveOven_MO_O_IS2_2_Ensuring_Safe_to_Cook,
     MicrowaveOven_MO_O_IS1_1_Awaiting_Cooking_Request,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 5 'Signalling Cooking Period Over' */
   { EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_O_IS1_1_Awaiting_Cooking_Request,
     EventIsIgnored,
     EventIsIgnored,
     MicrowaveOven_MO_O_IS1_1_Awaiting_Cooking_Request,
     EventIsIgnored,
     EventIsIgnored },

   /* Entries for Instance State 6 'Assigning Cooking Period' */
   { EventIsIgnored,
     MicrowaveOven_MO_O_IS2_2_Ensuring_Safe_to_Cook,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored,
     EventIsIgnored }
};

/* Instance State Actions Array (SAA) for class 'Oven'
   containing pointers to actions for all Instance States */
static const InstanceStateActionPtrType MicrowaveOven_InstanceSAA_MO_O[7] =
{
   (InstanceStateActionPtrType) NULL,  /* The additional state 'NonExisting' has no action procedure */
   (InstanceStateActionPtrType) MicrowaveOven_ISA1_Awaiting_Cooking_Request_MO_O,
   (InstanceStateActionPtrType) MicrowaveOven_ISA2_Ensuring_Safe_to_Cook_MO_O,
   (InstanceStateActionPtrType) MicrowaveOven_ISA3_Cooking_MO_O,
   (InstanceStateActionPtrType) MicrowaveOven_ISA4_Cooking_Suspended_MO_O,
   (InstanceStateActionPtrType) MicrowaveOven_ISA5_Signalling_Cooking_Period_Over_MO_O,
   (InstanceStateActionPtrType) MicrowaveOven_ISA6_Assigning_Cooking_Period_MO_O 
};

/* ---------------------------------------------------------------------------
 * Class Instance Pool
 * ---------------------------------------------------------------------------
 */
/* The 'Oven' class instance pool */
struct MicrowaveOven_Oven_MO_O MicrowaveOven_ClassInstances_MO_O[1];
struct TinyPool MicrowaveOven_ClassInstancePool_MO_O = {NULL, 0, 0, 0, 0};

/* Labels for access to valid start & end addresses for pool instances.
   (the end address is slighly below the real end address of the pool array,
    but _not_ below the address of the last instance in the pool array) */
const struct MicrowaveOven_Oven_MO_O* MicrowaveOven_ClassInstances_MO_O_start =
            &MicrowaveOven_ClassInstances_MO_O[0];
const struct MicrowaveOven_Oven_MO_O* MicrowaveOven_ClassInstances_MO_O_end = (const void*) ((unsigned long)
            &MicrowaveOven_ClassInstances_MO_O[0] + sizeof(MicrowaveOven_ClassInstances_MO_O) - sizeof(int));

/* ---------------------------------------------------------------------------
 * Function for initializing class 'Oven'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Initialize__MO_O( void )
{
   /* Register the event queue polling function for this class */
   MicrowaveOven_ScheduleElement_MO_O = MO_SYS_FUNC_RegisterQueuePoller( MicrowaveOven_Poll_MO_O, false );

   /* Initialize the 'Oven' class instance pool */
   {
      struct TinyPoolElement* previousElement = &MicrowaveOven_ClassInstances_MO_O[0].poolElement;
      struct TinyPoolElement* theElement      = &MicrowaveOven_ClassInstances_MO_O[0].poolElement;
      previousElement->next = theElement;
      theElement->previous  = previousElement;
      previousElement       = theElement;
      MicrowaveOven_ClassInstancePool_MO_O.firstFreeElement      = &MicrowaveOven_ClassInstances_MO_O[0].poolElement;
      MicrowaveOven_ClassInstancePool_MO_O.numberOfFreeElements  = 1;
      MicrowaveOven_ClassInstancePool_MO_O.theCapacity           = 1;
      MicrowaveOven_ClassInstancePool_MO_O.numberOfUsedElements  = 0;
      MicrowaveOven_ClassInstancePool_MO_O.highWaterMark         = 0;
   }

}

/* ---------------------------------------------------------------------------
 * Function for shutting down class 'Oven'.
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven__Shutdown__MO_O( void )
{
}

/* ---------------------------------------------------------------------------
 * Event Queue Info Function for class 'Oven'
 * ---------------------------------------------------------------------------
 */
unsigned long MicrowaveOven_EventQueueInfo_MO_O( void )
{
   /* Local variable declarations */
   unsigned long numberOfEventQueueJobs;

   /* Get the jobs on the EventQueue */
   numberOfEventQueueJobs = MicrowaveOven_EventQueue_MO_O.numberOfPushedElements -
                            MicrowaveOven_EventQueue_MO_O.numberOfPoppedElements;

   /* Get the jobs on the SelfEventQueue */
   numberOfEventQueueJobs += MicrowaveOven_SelfEventQueue_MO_O.numberOfPushedElements -
                             MicrowaveOven_SelfEventQueue_MO_O.numberOfPoppedElements;

   /* Return the queued jobs for this class */
   return numberOfEventQueueJobs;
}

/* ---------------------------------------------------------------------------
 * General Event Taker Function for class 'Oven'
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_TakeEvent_MO_O( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient )
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
         theQueue = &MicrowaveOven_SelfEventQueue_MO_O;
      }
      else
      {
         /* Register the incomingEvent in the eventQueue */
         theQueue = &MicrowaveOven_EventQueue_MO_O;
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
            if ( !(MicrowaveOven_ScheduleElement_MO_O->isLinkedForScheduling) )
            {
               /* Check if scheduling of event queue polling not has been requested */
               if ( !MicrowaveOven_SchedulingRequested_MO_O )
               {
                  /* Request scheduling of event queue polling by the dispatcher */
                  MO_SYS_FUNC_RequestScheduling( MicrowaveOven_ScheduleElement_MO_O );

                  /* Indicate that scheduling of event queue polling is requested */
                  MicrowaveOven_SchedulingRequested_MO_O = true;
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
 * Event Queue Polling Function for class 'Oven'
 * (to be called from the system-level dispatcher)
 * ---------------------------------------------------------------------------
 */
void* MicrowaveOven_Poll_MO_O( void )
{
   /* Declaration of local queue poller variables */
   const struct GenericEvent* queue_evt = NULL;
   struct TinyQueueElement* popElement;
   void* theEventData = NULL;
   const void* theRecipient = NULL;

   /* Check if the event queue polling function has been linked for scheduling */
   if ( MicrowaveOven_ScheduleElement_MO_O->isLinkedForScheduling )
   {
      /* Prepare for a future event queue polling request */
      MicrowaveOven_SchedulingRequested_MO_O = false;
   }

   /* Indicate that the event queue is being accessed */
   MO_SYS_FUNC_EventQueueIsAccessed = true;

   /* Check if self-directed events are available for processing */
   if ( MicrowaveOven_SelfEventQueue_MO_O.numberOfPoppedElements !=
        MicrowaveOven_SelfEventQueue_MO_O.numberOfPushedElements )
   {
      /* Retrieve the event from the selfEventQueue */
      popElement   = MicrowaveOven_SelfEventQueue_MO_O.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_SelfEventQueue_MO_O.firstElement = popElement->next;
         MicrowaveOven_SelfEventQueue_MO_O.numberOfPoppedElements++;

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
   else if ( MicrowaveOven_EventQueue_MO_O.numberOfPoppedElements !=
             MicrowaveOven_EventQueue_MO_O.numberOfPushedElements )
   {
      /* Retrieve the event from the eventQueue */
      popElement   = MicrowaveOven_EventQueue_MO_O.firstElement;
      queue_evt    = popElement->queuedEvent;
      theEventData = popElement->eventData;
      theRecipient = popElement->recipient;

      /* Check if an event really has been retrieved */
      if ( queue_evt != NULL )
      {
         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         MicrowaveOven_EventQueue_MO_O.firstElement = popElement->next;
         MicrowaveOven_EventQueue_MO_O.numberOfPoppedElements++;

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
         MicrowaveOven_ProcInstEvent_MO_O( queue_evt, theEventData, theRecipient );
      }
   }

   /* Return an indication if an event was dequeued or not.
      NULL is returned (by default) if the queues were empty. */
   return (void*) queue_evt;
}

/* ---------------------------------------------------------------------------
 * Instance Event Processing Function for class 'Oven'
 * ---------------------------------------------------------------------------
 */
__inlined__ void MicrowaveOven_ProcInstEvent_MO_O( const struct GenericEvent* const queue_evt, void* eventData, const void* recipient )
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
      eventTrace_DequeuingEvent( MicrowaveOven_ClassName_MO_O,
                                 true, queue_evt, eventData, recipient );

      /* Check if there is a valid recipient */
      if ( recipient != NULL )
      {
         /* Get the 'Oven' target instance */
         struct MicrowaveOven_Oven_MO_O* targetInst = (struct MicrowaveOven_Oven_MO_O*) recipient;

         /* Get the current state for the target instance */
         currentState = (unsigned int) targetInst->currentISMstate_MO_O;

         /* Get the destination state for the target instance */
         destState = (unsigned int) MicrowaveOven_InstanceSEM_MO_O[currentState][eventCode];

         /* Register the currently executing state machine */
         registerCurrentStateMachine( MicrowaveOven_ClassName_MO_O, recipient );

         /* CHECK THAT RECIPIENT INSTANCE NOT HAS BEEN DELETED */
         if ( currentState != MicrowaveOven_MO_O_IS_NonExisting )
         {

            /* Check if the destination state is a valid state */
            if ( destState < MicrowaveOven_MO_O_IS_NumberOfStates )
            {
               /* PROCESS THE EVENT */

               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_O[currentState] );

               /* Print information about the destination state */
               eventTrace_GoingToState( MicrowaveOven_InstanceSDT_MO_O[destState] );

               /* There are no Instance Transition Actions in this state machine */

               /* Execute the Instance State Action */
               {
                  InstanceStateActionPtrType instanceStateAction = MicrowaveOven_InstanceSAA_MO_O[destState];
                  const void* commonStateParameterSet = MicrowaveOven_InstanceSDVA_MO_O[destState];
                  if ( commonStateParameterSet == DirectEventDataAccess )
                  {
                     /* This state action access the incoming event data directly */
                     commonStateParameterSet = (const void*) eventData;
                  }
                  ( *instanceStateAction )( targetInst, commonStateParameterSet );
               }

               /* Check that the instance not has been deleted
                  during the execution of the state action code */
               if ( targetInst->currentISMstate_MO_O != MicrowaveOven_MO_O_IS_NonExisting )
               {
                  /* Set the new state for the target instance */
                  targetInst->currentISMstate_MO_O = (unsigned char) destState;
               }
            }

            /* (there are no "can't happen" events for this state machine) */

            /* Check if this is an event that is "ignored" */
            else if ( destState == EventIsIgnored )
            {
               /* The received event is analyzed as "ignored" in current state */
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_O[currentState] );
               eventTrace_EventIgnored();

               /* Trace output: Event Ignored */
               infoTrace_EventIgnored( "instance", MicrowaveOven_InstanceEDT_MO_O[eventCode], MicrowaveOven_ClassName_MO_O, MicrowaveOven_InstanceSDT_MO_O[currentState] );
            }

            /* ...otherwise a fatal error has occurred */
            else
            {
               /* Print information about the current state */
               eventTrace_DequeuingInState( MicrowaveOven_InstanceSDT_MO_O[currentState] );

               /* A FATAL ERROR HAS OCCURRED WHEN HANDLING THIS EVENT
                  (destState error related to [currentState][eventCode] error) */
               eventTrace_FatalStateEventError();

               /* Trace output: Destination state error */
               errorTrace_DestinationStateError( "Instance", destState, currentState, eventCode, MicrowaveOven_ClassName_MO_O, MicrowaveOven_InstanceEDT_MO_O[eventCode] );
            }

         }
         else
         {
            /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
               (the 'recipient' of the event has been deleted) */

            /* Trace output: Event sent to deleted instance */
            errorTrace_EventToDeletedInstance( MicrowaveOven_InstanceEDT_MO_O[eventCode], MicrowaveOven_ClassName_MO_O );
            eventTrace_RecipientDeleted();
         }
      }
      else
      {
         /* THE RECIPIENT INSTANCE DOES NOT EXIST!!!
            (the 'recipient' of the event is == NULL) */

         /* Trace output: Instance pointer (recipient) == NULL */
         errorTrace_EventToNullRecipient( MicrowaveOven_InstanceEDT_MO_O[eventCode], MicrowaveOven_ClassName_MO_O );
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
 * Action code for Instance State 1. 'Awaiting Cooking Request'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA1_Awaiting_Cooking_Request_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData )
{
   /* Local variable declarations */
   struct MicrowaveOven_Beeper_MO_B* beeper_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* ASSIGN ATTRIBUTE self.remaining_cooking_time = 0 */
   self->remaining_cooking_time_MO_O = 0;

   /* SELECT ONE beeper RELATED BY self->MO_B[R3] */

   /* ### Navigate across relationship R3 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Beeper instance related across R3 */
      beeper_p = self->MO_B_DestNavPtr_R3_p;
   }

   /* GENERATE EVENT MO_B4:'stop_beeping' TO beeper */

   /* Get constant declaration for event MO_B4:'stop_beeping' */
   evt_2 = &MicrowaveOven_MO_B4_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = beeper_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_B( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 2. 'Ensuring Safe to Cook'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA2_Ensuring_Safe_to_Cook_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData )
{
   if ((self->remaining_cooking_time_MO_O != 0))
   {
      /* Local variable declarations */
      struct MicrowaveOven_Door_MO_D* door_p;

      /* SELECT ONE door RELATED BY self->MO_D[R4] */

      /* ### Navigate across relationship R4 ### */
      {  /* (select one RTO related by RGO inst) */

         /* Select the Door instance related across R4 */
         door_p = self->MO_D_DestNavPtr_R4_p;
      }

      if ((door_p->is_secure_MO_D == true))
      {
         /* Local variable declarations */
         const struct GenericEvent* evt_2;
         void* evt_2_data;
         const void* evt_2_recipient;

         /* GENERATE EVENT MO_O7:'oven_safe' TO self */

         /* Get constant declaration for event MO_O7:'oven_safe' */
         evt_2 = &MicrowaveOven_MO_O7_IE_Const_Self;
         /* Allocate event data memory for event tracing purposes only */
         evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
         /* Clear the event handling flags */
         ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
         ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
         ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
         ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
         evt_2_recipient = self;

         /* Deliver the event to the target state machine */
         MicrowaveOven_TakeEvent_MO_O( evt_2, evt_2_data, evt_2_recipient );

      }  /* END IF */

   }  /* END IF */

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 3. 'Cooking'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA3_Cooking_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData )
{
   /* Local variable declarations */
   struct MicrowaveOven_InternalLight_MO_IL* light_p;
   struct MicrowaveOven_Turntable_MO_TRN* turntable_p;
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   const struct GenericEvent* cooking_over = NULL;
   void* cooking_over_data;
   const void* cooking_over_recipient;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;
   const struct GenericEvent* evt_3;
   void* evt_3_data;
   const void* evt_3_recipient;
   const struct GenericEvent* evt_4;
   void* evt_4_data;
   const void* evt_4_recipient;

   /* CREATE EVENT cooking_over OF MO_O5:'cooking_period_over' TO self */

   /* Get constant declaration for event MO_O5:'cooking_period_over' */
   cooking_over = &MicrowaveOven_MO_O5_IE_Const_Self;
   /* Allocate event data memory for event tracing purposes only */
   cooking_over_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) cooking_over_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) cooking_over_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) cooking_over_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) cooking_over_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   cooking_over_recipient = self;

   /* ASSIGN ATTRIBUTE self.oven_timer = TIM::timer_start( event_inst:cooking_over, microseconds:self.remaining_cooking_time ) */
   self->oven_timer_MO_O = TIM_timer_start(cooking_over, cooking_over_data, cooking_over_recipient, self->remaining_cooking_time_MO_O);

   /* Clear the pre-created event reference when delivered
      (prevents sending the same event multiple times) */
   cooking_over = NULL;

   /* SELECT ONE light RELATED BY self->MO_IL[R2] */

   /* ### Navigate across relationship R2 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Internal Light instance related across R2 */
      light_p = self->MO_IL_DestNavPtr_R2_p;
   }

   /* GENERATE EVENT MO_IL1:'switch_on' TO light */

   /* Get constant declaration for event MO_IL1:'switch_on' */
   evt_2 = &MicrowaveOven_MO_IL1_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = light_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_IL( evt_2, evt_2_data, evt_2_recipient );

   /* SELECT ONE turntable RELATED BY self->MO_TRN[R5] */

   /* ### Navigate across relationship R5 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Turntable instance related across R5 */
      turntable_p = self->MO_TRN_DestNavPtr_R5_p;
   }

   /* GENERATE EVENT MO_TRN1:'spin' TO turntable */

   /* Get constant declaration for event MO_TRN1:'spin' */
   evt_3 = &MicrowaveOven_MO_TRN1_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_3_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_3_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_3_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_3_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_3_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_3_recipient = turntable_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_TRN( evt_3, evt_3_data, evt_3_recipient );

   /* SELECT ONE tube RELATED BY self->MO_MT[R1] */

   /* ### Navigate across relationship R1 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Magnetron Tube instance related across R1 */
      tube_p = self->MO_MT_DestNavPtr_R1_p;
   }

   /* GENERATE EVENT MO_MT3:'power_on' TO tube */

   /* Get constant declaration for event MO_MT3:'power_on' */
   evt_4 = &MicrowaveOven_MO_MT3_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_4_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_4_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_4_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_4_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_4_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_4_recipient = tube_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_MT( evt_4, evt_4_data, evt_4_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 4. 'Cooking Suspended'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA4_Cooking_Suspended_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData )
{
   /* Local variable declarations */
   bool cancelled;
   struct MicrowaveOven_InternalLight_MO_IL* light_p;
   struct MicrowaveOven_Turntable_MO_TRN* turntable_p;
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;
   const struct GenericEvent* evt_3;
   void* evt_3_data;
   const void* evt_3_recipient;
   const struct GenericEvent* evt_4;
   void* evt_4_data;
   const void* evt_4_recipient;

   /* ASSIGN ATTRIBUTE self.remaining_cooking_time = TIM::timer_remaining_time( timer_inst_ref:self.oven_timer ) */
   self->remaining_cooking_time_MO_O = TIM_timer_remaining_time(self->oven_timer_MO_O);

   /* ASSIGN VARIABLE cancelled = TIM::timer_cancel( timer_inst_ref:self.oven_timer ) */
   cancelled = TIM_timer_cancel(self->oven_timer_MO_O);

   /* SELECT ONE light RELATED BY self->MO_IL[R2] */

   /* ### Navigate across relationship R2 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Internal Light instance related across R2 */
      light_p = self->MO_IL_DestNavPtr_R2_p;
   }

   /* GENERATE EVENT MO_IL2:'switch_off' TO light */

   /* Get constant declaration for event MO_IL2:'switch_off' */
   evt_2 = &MicrowaveOven_MO_IL2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = light_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_IL( evt_2, evt_2_data, evt_2_recipient );

   /* SELECT ONE turntable RELATED BY self->MO_TRN[R5] */

   /* ### Navigate across relationship R5 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Turntable instance related across R5 */
      turntable_p = self->MO_TRN_DestNavPtr_R5_p;
   }

   /* GENERATE EVENT MO_TRN2:'stop' TO turntable */

   /* Get constant declaration for event MO_TRN2:'stop' */
   evt_3 = &MicrowaveOven_MO_TRN2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_3_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_3_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_3_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_3_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_3_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_3_recipient = turntable_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_TRN( evt_3, evt_3_data, evt_3_recipient );

   /* SELECT ONE tube RELATED BY self->MO_MT[R1] */

   /* ### Navigate across relationship R1 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Magnetron Tube instance related across R1 */
      tube_p = self->MO_MT_DestNavPtr_R1_p;
   }

   /* GENERATE EVENT MO_MT4:'power_off' TO tube */

   /* Get constant declaration for event MO_MT4:'power_off' */
   evt_4 = &MicrowaveOven_MO_MT4_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_4_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_4_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_4_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_4_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_4_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_4_recipient = tube_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_MT( evt_4, evt_4_data, evt_4_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 5. 'Signalling Cooking Period Over'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA5_Signalling_Cooking_Period_Over_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData )
{
   /* Local variable declarations */
   struct MicrowaveOven_Beeper_MO_B* beeper_p;
   struct MicrowaveOven_InternalLight_MO_IL* light_p;
   struct MicrowaveOven_Turntable_MO_TRN* turntable_p;
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;
   const struct GenericEvent* evt_3;
   void* evt_3_data;
   const void* evt_3_recipient;
   const struct GenericEvent* evt_4;
   void* evt_4_data;
   const void* evt_4_recipient;
   const struct GenericEvent* evt_5;
   void* evt_5_data;
   const void* evt_5_recipient;

   /* SELECT ONE beeper RELATED BY self->MO_B[R3] */

   /* ### Navigate across relationship R3 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Beeper instance related across R3 */
      beeper_p = self->MO_B_DestNavPtr_R3_p;
   }

   /* GENERATE EVENT MO_B1:'start_beeping' TO beeper */

   /* Get constant declaration for event MO_B1:'start_beeping' */
   evt_2 = &MicrowaveOven_MO_B1_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = beeper_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_B( evt_2, evt_2_data, evt_2_recipient );

   /* SELECT ONE light RELATED BY self->MO_IL[R2] */

   /* ### Navigate across relationship R2 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Internal Light instance related across R2 */
      light_p = self->MO_IL_DestNavPtr_R2_p;
   }

   /* GENERATE EVENT MO_IL2:'switch_off' TO light */

   /* Get constant declaration for event MO_IL2:'switch_off' */
   evt_3 = &MicrowaveOven_MO_IL2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_3_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_3_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_3_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_3_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_3_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_3_recipient = light_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_IL( evt_3, evt_3_data, evt_3_recipient );

   /* SELECT ONE turntable RELATED BY self->MO_TRN[R5] */

   /* ### Navigate across relationship R5 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Turntable instance related across R5 */
      turntable_p = self->MO_TRN_DestNavPtr_R5_p;
   }

   /* GENERATE EVENT MO_TRN2:'stop' TO turntable */

   /* Get constant declaration for event MO_TRN2:'stop' */
   evt_4 = &MicrowaveOven_MO_TRN2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_4_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_4_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_4_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_4_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_4_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_4_recipient = turntable_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_TRN( evt_4, evt_4_data, evt_4_recipient );

   /* SELECT ONE tube RELATED BY self->MO_MT[R1] */

   /* ### Navigate across relationship R1 ### */
   {  /* (select one RTO related by RGO inst) */

      /* Select the Magnetron Tube instance related across R1 */
      tube_p = self->MO_MT_DestNavPtr_R1_p;
   }

   /* GENERATE EVENT MO_MT4:'power_off' TO tube */

   /* Get constant declaration for event MO_MT4:'power_off' */
   evt_5 = &MicrowaveOven_MO_MT4_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_5_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_5_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_5_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_5_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_5_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_5_recipient = tube_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_MT( evt_5, evt_5_data, evt_5_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Instance State 6. 'Assigning Cooking Period'
 *
 * STATE ACTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_ISA6_Assigning_Cooking_Period_MO_O( struct MicrowaveOven_Oven_MO_O* self, const void* eventData )
{
   /* Retrieve the received event data
      (state action access event data directly) */
   struct MicrowaveOven_MO_O8_IE_Data* rcvd_evt = (struct MicrowaveOven_MO_O8_IE_Data*) eventData;

   /* ASSIGN ATTRIBUTE self.remaining_cooking_time = rcvd_evt.period */
   self->remaining_cooking_time_MO_O = rcvd_evt->period;

}

/* ---------------------------------------------------------------------------
 * Event data printout function for MO_O8:'cooking_period'
 * ---------------------------------------------------------------------------
 */
static void print_MicrowaveOven_MO_O8_IE_Data( const void* eventData )
{
   /* Get the event data to print out */
   struct MicrowaveOven_MO_O8_IE_Data* theEventData = (struct MicrowaveOven_MO_O8_IE_Data*) eventData;

   /* Printout event data item 'period' of type 'long' */
   eventTrace_SignedIntegerParameter( "period", theEventData->period );
}

/* ### End of File MicrowaveOven_Oven_MO_O.c ### */
