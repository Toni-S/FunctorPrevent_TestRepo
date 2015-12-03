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
 *  File Name .............. TinyTrace.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyTrace.h"
#include "Win32_Time.h"
#include "GenericEvent.h"
#include <stdio.h>

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* ******************************
   *** SYSTEM FUNCTION TRACES ***
   ******************************
 */
/* ---------------------------------------------------------------------------
 * Function for generating error trace "system function not started".
 * ---------------------------------------------------------------------------
 */
void errorTrace_SystemFunctionNotStarted( const char* systemFunctionName, const char* domainName )
{
   /* Trace output: System function not started */
   printf("### NOTE: System function %s must be started before domain %s (system function startup not called)%s", systemFunctionName, domainName, "\n");
}

/* *************************************
   *** DISPATCHER INFORMATION TRACES ***
   *************************************
 */
/* ---------------------------------------------------------------------------
 * Function for generating info trace "system dispatcher starts".
 * ---------------------------------------------------------------------------
 */
void infoTrace_SystemDispatcherStarts( const char* processName, const char* threadName )
{
   /* Default dispatcher start trace output */
   printf("### System function %s process %s dispatcher starts\n", processName, threadName);
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "system process running".
 * ---------------------------------------------------------------------------
 */
void infoTrace_SystemProcessRunning( const char* processName, const char* threadName )
{
   /* Default dispatcher running trace output */
   printf("### System function %s process %s is running\n", processName, threadName);
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "system process terminated".
 * ---------------------------------------------------------------------------
 */
void infoTrace_SystemProcessTerminated( const char* processName, const char* threadName )
{
   /* Default dispatcher terminatation trace output */
   printf("### System function %s process %s is terminated\n", processName, threadName);
}

/* ********************************
   *** MEMORY ALLOCATION TRACES ***
   ********************************
 */
/* ---------------------------------------------------------------------------
 * Function for generating info trace "pool is exhausted".
 * ---------------------------------------------------------------------------
 */
void infoTrace_PoolIsExhausted( const char* poolName, unsigned long highWaterMark, const char* functionName )
{
   /* Trace output: Pool is exhausted */
   printf("### %s pool is exhausted - High Water Mark is %d - allocation on heap in %s\n", poolName, highWaterMark, functionName);
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "class instance pool is exhausted".
 * ---------------------------------------------------------------------------
 */
void infoTrace_ClassInstancePoolIsExhausted( const char* className, unsigned long highWaterMark )
{
   /* Trace output: Class instance pool is exhausted */
   printf("### ClassInstancePool for '%s' is exhausted - High Water Mark is %d - allocation on heap in 'create'\n", className, highWaterMark);
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "heap allocation failed".
 * ---------------------------------------------------------------------------
 */
void infoTrace_HeapAllocationFailed( void )
{
   /* Trace output: Heap allocation failed */
   printf("### Heap allocation failed (malloc)\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "event data pool is exhausted".
 * ---------------------------------------------------------------------------
 */
void infoTrace_EventDataPoolIsExhausted( unsigned long highWaterMark, size_t instanceSize )
{
   /* Trace output: Event data pool is exhausted */
   printf("### Event data pool is exhausted - High Water Mark is %d - size %d allocated on heap in seizeEventDataMemory\n", highWaterMark, instanceSize);
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "event data pool not identified".
 * ---------------------------------------------------------------------------
 */
void infoTrace_EventDataPoolNotIdentified( size_t instanceSize )
{
   /* Trace output: Event data pool not identified */
   printf("### Event data pool not identified - size %d allocated on heap in seizeEventDataMemory\n", instanceSize);
}

/* ****************************
   *** STATE MACHINE TRACES ***
   ****************************
 */
/* ---------------------------------------------------------------------------
 * Function for generating error trace "Event Cant Happen".
 * ---------------------------------------------------------------------------
 */
void errorTrace_EventCantHappen( const char* smType, const char* eventName,
                                 const char* className, const char* stateName )
{
}

/* ---------------------------------------------------------------------------
 * Function for generating info trace "Event Ignored".
 * ---------------------------------------------------------------------------
 */
void infoTrace_EventIgnored( const char* smType, const char* eventName,
                             const char* className, const char* stateName )
{
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Destination state error".
 * ---------------------------------------------------------------------------
 */
void errorTrace_DestinationStateError( const char* smType, unsigned int destState,
                                       unsigned int currentState, unsigned int eventCode,
                                       const char* className, const char* eventName )
{
   /* Trace output: Destination state error */
   printf("### FATAL ERROR: %s destState=%d error related to [currentState=%d][eventCode=%d] error in class '%s' (event %s is ignored)%s", smType, destState, currentState, eventCode, className, eventName, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Event sent to deleted instance".
 * ---------------------------------------------------------------------------
 */
void errorTrace_EventToDeletedInstance( const char* eventName, const char* className )
{
   /* Trace output: Event sent to deleted instance */
   printf("### Instance event %s is sent to a deleted instance of class '%s'%s", eventName, className, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Instance pointer (recipient) == NULL".
 * ---------------------------------------------------------------------------
 */
void errorTrace_EventToNullRecipient( const char* eventName, const char* className )
{
   /* Trace output: Instance pointer (recipient) == NULL */
   printf("### Instance event %s in class '%s' is received with a recipient pointer == NULL  (empty reference)%s", eventName, className, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Incorrectly registered number of jobs".
 * ---------------------------------------------------------------------------
 */
void errorTrace_IncorrectlyRegisteredNumberOfJobs( unsigned long actualJobs,
                                                   unsigned long registeredJobs )
{
   /* Trace output: Incorrectly registered number of jobs */
   printf("### System-level dispatcher - Incorrect No of Jobs: actual = %d, registered = %d%s", actualJobs, registeredJobs, "\n");
}

/* ******************************
   *** ACTION LANGUAGE TRACES ***
   ******************************
 */
/* ---------------------------------------------------------------------------
 * Function for generating error trace "Linking instances when pointer == NULL".
 * ---------------------------------------------------------------------------
 */
void errorTrace_LinkingWhenInstancePointerIsNULL( const char* relationship )
{
   /* Trace output: Linking instances when pointer == NULL */
   printf("### Instances are linked across %s but a pointer == NULL (empty reference)%s", relationship, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Unlinking instances when pointer == NULL".
 * ---------------------------------------------------------------------------
 */
void errorTrace_UnlinkingWhenInstancePointerIsNULL( const char* relationship )
{
   /* Trace output: Unlinking instances when pointer == NULL */
   printf("### Instances are unlinked across %s but a pointer == NULL (empty reference)%s", relationship, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Re-linking an already linked instance".
 * ---------------------------------------------------------------------------
 */
void errorTrace_ReLinkingLinkedInstanceAcross( const char* className, const char* relationship )
{
   /* Trace output: Re-linking an already linked instance (= broken link) */
   printf("### Already linked instance of class '%s' is re-linked across %s (= broken link)%s", className, relationship, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Re-linking already linked instances".
 * ---------------------------------------------------------------------------
 */
void errorTrace_ReLinkingLinkedInstancesAcross( const char* className1, const char* className2, const char* relationship )
{
   /* Trace output: Re-linking already linked instances */
   printf("### Already linked instances of class '%s' and '%s' are re-linked across %s%s", className1, className2, relationship, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Unlinking instances that are not linked".
 * ---------------------------------------------------------------------------
 */
void errorTrace_UnlinkingNonLinkedInstancesAcross( const char* relationship )
{
   /* Trace output: Unlinking instances that are not linked */
   printf("### Unlinking non-linked class instances across %s (can also be NULL pointers)%s", relationship, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Deleting a linked instance".
 * ---------------------------------------------------------------------------
 */
void errorTrace_DeletingInstanceWhenLinkedAcross( const char* className, const char* relationship )
{
   /* Trace output: Deleting a linked instance (= broken link) */
   printf("### Deleting instance of class '%s' when linked across %s (= broken link)%s", className, relationship, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Delete instance pointer == NULL".
 * ---------------------------------------------------------------------------
 */
void errorTrace_DeleteInstancePointerIsNULL( const char* className )
{
   /* Trace output: Delete instance pointer == NULL */
   printf("### Deleting instance of class '%s' but pointer == NULL (empty reference)%s", className, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Operation instance pointer == NULL".
 * ---------------------------------------------------------------------------
 */
void errorTrace_OperationInstancePointerIsNULL( const char* operationName, const char* className )
{
   /* Trace output: Operation instance pointer == NULL */
   printf("### Operation %s in class '%s' invoked with an instance pointer == NULL  (empty reference)%s", operationName, className, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating error trace "Attribute instance pointer == NULL".
 * ---------------------------------------------------------------------------
 */
void errorTrace_AttributeInstancePointerIsNULL( const char* attributeName, const char* className )
{
   /* Trace output: Attribute instance pointer == NULL */
   printf("### Attribute '%s' in class '%s' accessed with instance pointer == NULL  (empty reference)%s", attributeName, className, "\n");
}

/* ********************
   *** EVENT TRACES ***
   ********************
 */
/* ---------------------------------------------------------------------------
 * Function for generating event trace "No Events Defined".
 * ---------------------------------------------------------------------------
 */
void eventTrace_NoEventsDefined( const char* className )
{
   /* Retrieve the current date and time */
   retrieveCurrentDateAndTime();

   /* Print information about the dequeuing of an event */
   printf(" TIME %02u%s%02u%s%02u%s%03u%s", getHour(), ":", getMinute(), ":", getSecond(), ".", getMillisecond(), "\n");
   printf(" %s - Class Based State Machine\n", className);
   printf("     Dequeuing a received event\n");
   printf("     *** State Machine Does Not Define Any Events - Event Ignored ***\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Dequeuing Event".
 * ---------------------------------------------------------------------------
 */
void eventTrace_DequeuingEvent( const char* className, fastBool isInstanceBased,
                                const void* queuedEvent,
                                void* eventData, const void* recipient )
{
   /* Get the queued event */
   const struct GenericEvent* const queue_evt = (const struct GenericEvent*) queuedEvent;

   /* Retrieve only the header part of the incoming event data
      (may contain time & sender info when event tracing is enabled) */
   _OEDH_* _oedh_ = (_OEDH_*) eventData;

   /* Get the name of the sender class */
   const char* senderName = "???";
   /* Check that event data was defined (otherwise, perhaps, sent from hand-written code) */
   if ( _oedh_ != NULL )
   {
      /* Get the name from the event data header */
      senderName = _oedh_->_header_.senderClassName;
   }

   /* Retrieve the current date and time */
   retrieveCurrentDateAndTime();

   /* Print information about the dequeued event */
   printf(" TIME %02u%s%02u%s%02u%s%03u%s", getHour(), ":", getMinute(), ":", getSecond(), ".", getMillisecond(), "\n");

   /* Check if this is an instance based state machine */
   if ( isInstanceBased )
   {
      /* Check if the received event is a creation event */
      if ( recipient == IsCreationEvent )
      {
         printf(" %s - Instance Based State Machine (creator)\n", className);
      }
      else
      {
         printf(" %s - Instance Based State Machine (addr:%#x%s", className, (unsigned long) recipient, ")\n");
      }
   }
   else
   {
      /* This is a class based state machine */
      printf(" %s - Class Based State Machine\n", className);
   }


   /* Check that event data was defined (otherwise, perhaps, sent from hand-written code) */
   if ( _oedh_ != NULL )
   {
      /* Check if time information is available for this event
         (not available for incoming OSE signals) */
      if ( !(queue_evt->eventCodeAndType & IsIncomingOSESignal) && (_oedh_->_header_.timeInformationAvailable) )
      {
         /* Check if this is a recurring event */
         if ( _oedh_->_header_.eventFlags & IsRecurringEvent )
         {
            /* Print information about the recurring event and the time it was fired */
            printf("     Dequeuing event %s%s%02u%s%02u%s%02u%s%03u%s", (*queue_evt->eventDescriptionText), " (PERIODIC - fired ", _oedh_->_header_.hour, ":", _oedh_->_header_.minute, ":", _oedh_->_header_.second, ".", _oedh_->_header_.millisecond, ")\n");
         }
         else
         {
            /* Print information about the delayed event and the time it was sent */
            printf("     Dequeuing event %s%s%02u%s%02u%s%02u%s%03u%s", (*queue_evt->eventDescriptionText), " (DELAYED - sent ", _oedh_->_header_.hour, ":", _oedh_->_header_.minute, ":", _oedh_->_header_.second, ".", _oedh_->_header_.millisecond, ")\n");
         }
      }
      else
      {
         /* No time information is available for this event */
         printf("     Dequeuing event %s%s", (*queue_evt->eventDescriptionText), "\n");
      }
   }
   else
   {
      /* No time information is available for this event */
      printf("     Dequeuing event %s%s", (*queue_evt->eventDescriptionText), "\n");
   }

   /* Check if this is an instance based state machine */
   if ( isInstanceBased )
   {
      /* Check that event data was defined (otherwise, perhaps, sent from hand-written code) */
      if ( _oedh_ != NULL )
      {
         /* Remove the time information indication
            (for the case that the event is propagated) */
         _oedh_->_header_.timeInformationAvailable = false;
      }
   }

   /* Print the event data, when such data is available */
   if ( eventData )
   {
      /* Check that a printout function is defined for this event data */
      if ( (*queue_evt->eventDataPrinter) != NULL )
      {
         /* Call the printout function for this event data */
         ( (*queue_evt->eventDataPrinter) )( eventData );
      }
   }

   /* Check if this is NOT an incoming OSE signal */
   if ( !(queue_evt->eventCodeAndType & IsIncomingOSESignal) )
   {
      /* Check that event data was defined (otherwise, perhaps, sent from hand-written code) */
      if ( _oedh_ != NULL )
      {
         /* Check if the sender is instance or class based */
         if ( _oedh_->_header_.senderInstance == NULL )
         {
            /* Print information about the class based sender state machine */
            printf("     sent by %s%s", senderName, " - Class Based State Machine\n");
         }
         else
         {
            /* Print information about the instance based sender state machine */
            if ( _oedh_->_header_.eventFlags & IsPropagatedEvent )
            {
               /* This polymorphic event has been propagated by the "sender" */
               printf("     propagated by %s%s%#x%s", senderName, " - Instance Based State Machine (addr:", (unsigned long) _oedh_->_header_.senderInstance, ")\n");
            }
            else
            {
               /* This event is generated by the sender */
               printf("     sent by %s%s%#x%s", senderName, " - Instance Based State Machine (addr:", (unsigned long) _oedh_->_header_.senderInstance, ")\n");
            }
         }
      }
      else
      {
         /* Print information about the sender state machine */
         printf("     sent by %s%s", senderName, "\n");
      }
   }
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Dequeuing In State".
 * ---------------------------------------------------------------------------
 */
void eventTrace_DequeuingInState( const char* stateName )
{
   /* Print information about the current state */
   printf("     Dequeuing in state %s%s", stateName, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Going To State".
 * ---------------------------------------------------------------------------
 */
void eventTrace_GoingToState( const char* stateName )
{
   /* Print information about the destination state */
   printf("     going to state     %s%s", stateName, "\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Event Can't Happen".
 * ---------------------------------------------------------------------------
 */
void eventTrace_EventCantHappen( void )
{
   printf("     *** Event Can't Happen ***\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Event Ignored".
 * ---------------------------------------------------------------------------
 */
void eventTrace_EventIgnored( void )
{
   printf("     *** Event Ignored ***\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Fatal State/Event Error".
 * ---------------------------------------------------------------------------
 */
void eventTrace_FatalStateEventError( void )
{
   printf("     *** Fatal State/Event Error - Event Ignored ***\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Event Ignored - Has No Transitions".
 * ---------------------------------------------------------------------------
 */
void eventTrace_EventIgnored_HasNoTransitions( void )
{
   /* This state machine has no transitions */
   printf("     *** Event Ignored *** (this state machine has no transitions)\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Event Ignored - Has No States".
 * ---------------------------------------------------------------------------
 */
void eventTrace_EventIgnored_HasNoStates( void )
{
   /* This state machine has no states */
   printf("     *** Event Ignored *** (this state machine has no states)\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for inserting a blank line into the trace log.
 * ---------------------------------------------------------------------------
 */
void eventTrace_InsertBlankLine( void )
{
   /* Just insert a blank line... */
   printf("\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Event Is Propagated".
 * ---------------------------------------------------------------------------
 */
void eventTrace_EventIsPropagatedAcross( const char* relationship )
{
   /* The received event is propagated to a subtype state machine */
   printf("     *** Event Is Propagated Across Relationship %s ***\n", relationship);
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Event Is NOT Propagated".
 * ---------------------------------------------------------------------------
 */
void eventTrace_EventIsNotPropagated( void )
{
   /* The received event is NOT propagated to a subtype state machine */
   printf("     *** The event is NOT propagated! (no related subtype state machine) ***\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "as creation event".
 * ---------------------------------------------------------------------------
 */
void eventTrace_CreatingInstance( void )
{
   /* Print information about the creation event */
   printf("     as a creation event - the target instance just created\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Recipient Deleted".
 * ---------------------------------------------------------------------------
 */
void eventTrace_RecipientDeleted( void )
{
   printf("     *** Recipient Instance Is Deleted - Event Ignored ***\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace "Recipient Is NULL".
 * ---------------------------------------------------------------------------
 */
void eventTrace_RecipientIsNULL( void )
{
   printf("     *** Recipient Instance Is NULL - Event Ignored ***\n\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace for a signed integer parameter.
 * ---------------------------------------------------------------------------
 */
void eventTrace_SignedIntegerParameter( const char* parName, long parValue )
{
   printf("           parameter %s = %d%s%#x%s", parName, parValue, "  (", (unsigned) parValue, ")\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace for an unsigned integer parameter.
 * ---------------------------------------------------------------------------
 */
void eventTrace_UnsignedIntegerParameter( const char* parName, unsigned long parValue )
{
   printf("           parameter %s = %u%s%#x%s", parName, parValue, "  (", (unsigned) parValue, ")\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace for a real parameter.
 * ---------------------------------------------------------------------------
 */
void eventTrace_RealParameter( const char* parName, const double parValue )
{
   printf("           parameter %s = %f%s", parName, parValue, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace for a string parameter.
 * ---------------------------------------------------------------------------
 */
void eventTrace_StringParameter( const char* parName, const char* parValue )
{
   printf("           parameter %s = %s%s", parName, parValue, "\n");
}

/* ---------------------------------------------------------------------------
 * Function for generating event trace for an unsupported parameter.
 * ---------------------------------------------------------------------------
 */
void eventTrace_UnsupportedParameter( const char* parName, const char* arrayIndication, const char* parType )
{
   printf("           parameter %s : %stype '%s' not supported for printout\n", parName, arrayIndication, parType);
}

/* ### End of file TinyTrace.c ### */
