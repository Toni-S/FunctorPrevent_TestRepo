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
 *  File Name .............. Win32_Timer.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The Win32_Timer implements a timer for C on Win32
 * using the Win32 multimedia timer services.
 * ---------------------------------------------------------------------------
 */
#ifndef WIN32_TIMER_H
#define WIN32_TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* #include <windows.h> */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The Win32_Timer Structure */
struct Win32_Timer;
typedef struct Win32_Timer Win32_Timer;

/* Callback function pointer type */
typedef void ( *CallbackFuncPtrType )( void );

struct Win32_Timer
{
/* Win32 timer ID.  */
/* UINT theTimerID; */
   unsigned int theTimerID;

/* The delay time in milliseconds. */
/* UINT theDelayTime;              */
   unsigned int theDelayTime;

/* Pointer to function to be called once when timer expires. */
   CallbackFuncPtrType theCallbackFunction;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the Win32_Timer. */
void initialize_Timer( void );

/* Function for shutting down the Win32_Timer. */
void shutdown_Timer( void );

/* Function for starting a single-shot timer. */
void startSingleShotTimer( struct Win32_Timer* self,
/*                         UINT delayTime, */
                           unsigned int delayTime,
                           CallbackFuncPtrType callbackFunction );

/* Function for stopping a single-shot timer. */
void stopSingleShotTimer( struct Win32_Timer* self );

/* Function for starting a periodic timer. */
void startPeriodicTimer( struct Win32_Timer* self,
/*                       UINT delayTime, */
                         unsigned int delayTime,
                         CallbackFuncPtrType callbackFunction );

/* Function for stopping a periodic timer. */
void stopPeriodicTimer( const struct Win32_Timer* self );

#ifdef __cplusplus
}
#endif

#endif /* WIN32_TIMER_H */
