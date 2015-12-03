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
 *  File Name .............. MO_SYS_FUNC.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * SYSTEM FUNCTION DESCRIPTION:
 * These are the functions for system function 'MO_SYS_FUNC'
 * ---------------------------------------------------------------------------
 */
#ifndef MO_SYS_FUNC_H
#define MO_SYS_FUNC_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MO_SYS_FUNC_SysTypeDefs.h"
#include "TinySchedule.h"
#include "TinyDynArray.h"
#include "TinyTrace.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for starting up the entire MO_SYS_FUNC system function */
void MO_SYS_FUNC_Startup( void );

/* Function for shutting down the entire MO_SYS_FUNC system function */
void MO_SYS_FUNC_Shutdown( void );

/* Startup indication variable for system function MO_SYS_FUNC
   (the system function must be started before the individual domains) */
extern fastBool MO_SYS_FUNC_isStarted;

/* Dispatcher thread control variable for system function MO_SYS_FUNC */
extern fastBool MO_SYS_FUNC_Running;

/* Dispatcher thread status variable for system function MO_SYS_FUNC */
extern fastBool MO_SYS_FUNC_Waiting;

/* Common Event Queue Access Semaphore for system-level dispatched classes
   (this variable is also checked before delivery of Timer Events) */
extern fastBool MO_SYS_FUNC_EventQueueIsAccessed;

/* Indication about work to do for system-level dispatched classes
   (number of queued signals to process for state machines) */
extern unsigned long MO_SYS_FUNC_QueuedSignals;

/* Indication that a system-level dispatched class needs urgent scheduling
   (for incoming signals, != NULL means "needs to be scheduled right away") */
extern struct TinyScheduleElement* MO_SYS_FUNC_UrgentScheduleElement;

/* The MO_SYS_FUNC System-Level Dispatcher Thread */
extern struct Win32_JThread MO_SYS_FUNC_EventDispatcherThread;

/* Function for registering the event queue polling function for an active class */
struct TinyScheduleElement* MO_SYS_FUNC_RegisterQueuePoller( QueuePollerPtrType theQueuePoller, fastBool isPermanentlyLinked );

/* Function for requesting a specific element for scheduling by the dispatcher */
void MO_SYS_FUNC_RequestScheduling( struct TinyScheduleElement* requestElement );

#ifdef __cplusplus
}
#endif

#endif /* MO_SYS_FUNC_H */
