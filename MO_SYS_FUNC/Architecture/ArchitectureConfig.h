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
 *  File Name .............. ArchitectureConfig.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Architecture configuration definitions for system function 'MO_SYS_FUNC'
 * ---------------------------------------------------------------------------
 */
#ifndef ARCHITECTURECONFIG_H
#define ARCHITECTURECONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* The definition for the target platform. */
#define _TargetOperatingSystemIs_Win32
#define _TargetPlatformIs_Undefined

/* Indicate that the system function is single-threaded. */
#define _SystemFunctionIsSingleThreaded

/* Indicate that threading is enabled (= not disabled via mark). */
#define _ThreadingIsEnabled

/* Indicate that run-time event tracing is enabled. */
#define _RunTimeEventTracing

/* The maximum number of consecutive active classes to schedule for the
   system-level dispatcher. (before switching to the next thread/process) */
#define _MaxConsecutiveActiveClassesToSchedule 10

/* The maximum number of consecutive events to dispatch for an active class. */
#define _MaxConsecutiveEventsToDispatch 100

/* The definitions for the OS timer control (tick interval in milliseconds). */
#define _TimerTickInterval 10
#define _TimerTimeDivisor (_TimerTickInterval * 1000)
#define _TimerTimeRoundOff (_TimerTimeDivisor / 2)

/* The maximum length of a modelled string (including null delimiter). */
#define _MaxStringLength 32
/* The maximum length of a modelled string (excluding null delimiter). */
#define _MaxStringCharacters 31

/* The definitions for the event data pool sizes. */
#define _EventData16BytePoolSize 10
#define _EventData32BytePoolSize 30  /* Elements for Event Tracing added */
#define _EventData64BytePoolSize 10

/* The definition for the TimerEvent pool size. */
#define _TimerEventPoolSize 10

/* The definition for the TinyVectorElement pool size. */
#define _TinyVectorElementPoolSize 20

/* The definition for the TinyQueueElement pool size. */
#define _TinyQueueElementPoolSize 10

/* The definition for the TinyListElement pool size. */
#define _TinyListElementPoolSize 20

/* The definitions for the TinyDynArray pool size. */
#define _TinyDynArrayPoolSize 32
#define _TinyDynArraySize 32
#define _TinyDynArrayElementSize 1

#ifdef __cplusplus
}
#endif

#endif /* ARCHITECTURECONFIG_H */
