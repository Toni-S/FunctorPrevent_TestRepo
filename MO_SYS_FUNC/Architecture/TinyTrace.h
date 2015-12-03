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
 *  File Name .............. TinyTrace.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyTrace defines trace functions needed by the TinyC architecture
 * ---------------------------------------------------------------------------
 */
#ifndef TINYTRACE_H
#define TINYTRACE_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include <stddef.h>
#include "GlobalTypeDefs.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* ******************************
   *** SYSTEM FUNCTION TRACES ***
   ******************************
 */
/* Function for generating error trace "system function not started". */
void errorTrace_SystemFunctionNotStarted( const char* systemFunctionName, const char* domainName );

/* *************************************
   *** DISPATCHER INFORMATION TRACES ***
   *************************************
 */
/* Function for generating info trace "system dispatcher starts". */
void infoTrace_SystemDispatcherStarts( const char* processName, const char* threadName );

/* Function for generating info trace "system process running". */
void infoTrace_SystemProcessRunning( const char* processName, const char* threadName );

/* Function for generating info trace "system process terminated". */
void infoTrace_SystemProcessTerminated( const char* processName, const char* threadName );

/* ********************************
   *** MEMORY ALLOCATION TRACES ***
   ********************************
 */
/* Function for generating info trace "pool is exhausted". */
void infoTrace_PoolIsExhausted( const char* poolName, unsigned long highWaterMark, const char* functionName );

/* Function for generating info trace "class instance pool is exhausted". */
void infoTrace_ClassInstancePoolIsExhausted( const char* className, unsigned long highWaterMark );

/* Function for generating info trace "heap allocation failed". */
void infoTrace_HeapAllocationFailed( void );

/* Function for generating info trace "event data pool is exhausted". */
void infoTrace_EventDataPoolIsExhausted( unsigned long highWaterMark, size_t instanceSize );

/* Function for generating info trace "event data pool not identified". */
void infoTrace_EventDataPoolNotIdentified( size_t instanceSize );

/* ****************************
   *** STATE MACHINE TRACES ***
   ****************************
 */
/* Function for generating error trace "Event Cant Happen". */
void errorTrace_EventCantHappen( const char* smType, const char* eventName,
                                 const char* className, const char* stateName );

/* Function for generating info trace "Event Ignored". */
void infoTrace_EventIgnored( const char* smType, const char* eventName,
                             const char* className, const char* stateName );

/* Function for generating error trace "Destination state error". */
void errorTrace_DestinationStateError( const char* smType, unsigned int destState,
                                       unsigned int currentState, unsigned int eventCode,
                                       const char* className, const char* eventName );

/* Function for generating error trace "Event sent to deleted instance". */
void errorTrace_EventToDeletedInstance( const char* eventName, const char* className );

/* Function for generating error trace "Instance pointer (recipient) == NULL". */
void errorTrace_EventToNullRecipient( const char* eventName, const char* className );

/* Function for generating error trace "Incorrectly registered number of jobs". */
void errorTrace_IncorrectlyRegisteredNumberOfJobs( unsigned long actualJobs,
                                                   unsigned long registeredJobs );

/* ******************************
   *** ACTION LANGUAGE TRACES ***
   ******************************
 */
/* Function for generating error trace "Linking instances when pointer == NULL". */
void errorTrace_LinkingWhenInstancePointerIsNULL( const char* relationship );

/* Function for generating error trace "Unlinking instances when pointer == NULL". */
void errorTrace_UnlinkingWhenInstancePointerIsNULL( const char* relationship );

/* Function for generating error trace "Re-linking an already linked instance". */
void errorTrace_ReLinkingLinkedInstanceAcross( const char* className, const char* relationship );

/* Function for generating error trace "Re-linking already linked instances". */
void errorTrace_ReLinkingLinkedInstancesAcross( const char* className1, const char* className2, const char* relationship );

/* Function for generating error trace "Unlinking instances that are not linked". */
void errorTrace_UnlinkingNonLinkedInstancesAcross( const char* relationship );

/* Function for generating error trace "Deleting a linked instance". */
void errorTrace_DeletingInstanceWhenLinkedAcross( const char* className, const char* relationship );

/* Function for generating error trace "Delete instance pointer == NULL". */
void errorTrace_DeleteInstancePointerIsNULL( const char* className );

/* Function for generating error trace "Operation instance pointer == NULL". */
void errorTrace_OperationInstancePointerIsNULL( const char* operationName, const char* className );

/* Function for generating error trace "Attribute instance pointer == NULL". */
void errorTrace_AttributeInstancePointerIsNULL( const char* attributeName, const char* className );

/* ********************
   *** EVENT TRACES ***
   ********************
 */
/* Function for generating event trace "No Events Defined". */
void eventTrace_NoEventsDefined( const char* className );

/* Function for generating event trace "Dequeuing Event". */
void eventTrace_DequeuingEvent( const char* className, fastBool isInstanceBased,
                                const void* queuedEvent,
                                void* eventData, const void* recipient );

/* Function for generating event trace "Dequeuing In State". */
void eventTrace_DequeuingInState( const char* stateName );

/* Function for generating event trace "Going To State". */
void eventTrace_GoingToState( const char* stateName );

/* Function for generating event trace "Event Can't Happen". */
void eventTrace_EventCantHappen( void );

/* Function for generating event trace "Event Ignored". */
void eventTrace_EventIgnored( void );

/* Function for generating event trace "Fatal State/Event Error". */
void eventTrace_FatalStateEventError( void );

/* Function for generating event trace "Event Ignored - Has No Transitions". */
void eventTrace_EventIgnored_HasNoTransitions( void );

/* Function for generating event trace "Event Ignored - Has No States". */
void eventTrace_EventIgnored_HasNoStates( void );

/* Function for inserting a blank line into the trace log. */
void eventTrace_InsertBlankLine( void );

/* Function for generating event trace "Event Is Propagated". */
void eventTrace_EventIsPropagatedAcross( const char* relationship );

/* Function for generating event trace "Event Is NOT Propagated". */
void eventTrace_EventIsNotPropagated( void );

/* Function for generating event trace "as creation event". */
void eventTrace_CreatingInstance( void );

/* Function for generating event trace "Recipient Deleted". */
void eventTrace_RecipientDeleted( void );

/* Function for generating event trace "Recipient Is NULL". */
void eventTrace_RecipientIsNULL( void );

/* Function for generating event trace for a signed integer parameter. */
void eventTrace_SignedIntegerParameter( const char* parName, long parValue );

/* Function for generating event trace for an unsigned integer parameter. */
void eventTrace_UnsignedIntegerParameter( const char* parName, unsigned long parValue );

/* Function for generating event trace for a real parameter. */
void eventTrace_RealParameter( const char* parName, const double parValue );

/* Function for generating event trace for a string parameter. */
void eventTrace_StringParameter( const char* parName, const char* parValue );

/* Function for generating event trace for an unsupported parameter. */
void eventTrace_UnsupportedParameter( const char* parName, const char* arrayIndication, const char* parType );

#ifdef __cplusplus
}
#endif

#endif /* TINYTRACE_H */
