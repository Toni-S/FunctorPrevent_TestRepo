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
 *  File Name .............. Win32_Timer.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "Win32_Timer.h"
#include <windows.h>
#include <mmsystem.h>         /* The multimedia timer services */
                              /*******************************************
                               *** NOTE: This requires winmm.lib to be ***
                               ***       linked with the application.  ***
                               *******************************************/

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */
/* Win32-timer-event callback function.
   (referred to as the TimeProc function callback function in MSVC help) */
static void CALLBACK TimeProc_CallbackFunction( UINT uID, UINT uMsg,
                                                DWORD dwUser,  
                                                DWORD dw1, DWORD dw2 );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Function for initializing the Win32_Timer.
 * ---------------------------------------------------------------------------
 */
void initialize_Timer( void )
{
   /* Nothing needs to be done. */
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the Win32_Timer.
 * ---------------------------------------------------------------------------
 */
void shutdown_Timer( void )
{
   /* Nothing needs to be done. */
}

/* ---------------------------------------------------------------------------
 * Function for starting a single-shot timer.
 *
 * INPUT                DESCRIPTION
 * Win32_Timer*         Pointer to the Win32_Timer instance.
 * UINT                 The delay time in milliseconds.
 * CallbackFuncPtrType  Address of function to call once on timer expiration.
 * ---------------------------------------------------------------------------
 */
void startSingleShotTimer( struct Win32_Timer* self,
/*                         UINT delayTime, */
                           unsigned int delayTime,
                           CallbackFuncPtrType callbackFunction )
{
   /* Set the minimum Win32-timer-event timer resolution to 1 ms */
   if ( timeBeginPeriod( 1 ) == TIMERR_NOERROR )
   {
      /* Define the delay time for the timer */
      self->theDelayTime = delayTime;

      /* Define the function to call when timer expires */
      self->theCallbackFunction = callbackFunction;

      /* Start the single-shot timer */
      self->theTimerID = timeSetEvent((UINT) delayTime, 0, TimeProc_CallbackFunction, (DWORD) self, (TIME_ONESHOT + TIME_CALLBACK_FUNCTION));
      if ( !self->theTimerID )
      {
         /* Error handler */
      }
   }
   else
   {
      /* Error handler */
   }
}

/* ---------------------------------------------------------------------------
 * Function for stopping a single-shot timer.
 *
 * INPUT                DESCRIPTION
 * Win32_Timer*         Pointer to the Win32_Timer instance.
 * ---------------------------------------------------------------------------
 */
void stopSingleShotTimer( struct Win32_Timer* self )
{
   /* Stop the Win32 timer event */
   if ( timeKillEvent((UINT) self->theTimerID) != TIMERR_NOERROR )
   {
      /* Error handler */
   }
   if ( timeEndPeriod( 1 ) != TIMERR_NOERROR )
   {
      /* Error handler */
   }
}

/* ---------------------------------------------------------------------------
 * Function for starting a periodic timer.
 *
 * INPUT                DESCRIPTION
 * Win32_Timer*         Pointer to the Win32_Timer instance.
 * UINT                 The delay time in milliseconds.
 * CallbackFuncPtrType  Address of function to call once on timer expiration.
 * ---------------------------------------------------------------------------
 */
void startPeriodicTimer( struct Win32_Timer* self,
/*                       UINT delayTime, */
                         unsigned int delayTime,
                         CallbackFuncPtrType callbackFunction )
{
   /* Set the minimum Win32-timer-event timer resolution to 1 ms */
   if ( timeBeginPeriod( 1 ) == TIMERR_NOERROR )
   {
      /* Define the delay time for the timer */
      self->theDelayTime = delayTime;

      /* Define the function to call when timer expires */
      self->theCallbackFunction = callbackFunction;

      /* Start the periodic timer */
      self->theTimerID = timeSetEvent((UINT) delayTime, 0, TimeProc_CallbackFunction, (DWORD) self, (TIME_PERIODIC + TIME_CALLBACK_FUNCTION));
      if ( !self->theTimerID )
      {
         /* Error handler */
      }
   }
   else
   {
      /* Error handler */
   }
}

/* ---------------------------------------------------------------------------
 * Function for stopping a periodic timer.
 *
 * INPUT                DESCRIPTION
 * Win32_Timer*         Pointer to the Win32_Timer instance.
 * ---------------------------------------------------------------------------
 */
void stopPeriodicTimer( const struct Win32_Timer* self )
{
   /* Stop the Win32 timer event */
   if ( timeKillEvent((UINT) self->theTimerID) != TIMERR_NOERROR )
   {
      /* Error handler */
   }
   if ( timeEndPeriod( 1 ) != TIMERR_NOERROR )
   {
      /* Error handler */
   }
}

/* ---------------------------------------------------------------------------
 * Win32-timer-event callback function.
 * (referred to as the TimeProc function callback function in MSVC help)
 *
 * INPUT                DESCRIPTION (according to MSVC help)
 * UINT uID             Identifier of the timer event.
 * UINT uMsg            Reserved; do not use.
 * DWORD dwUser         User instance data supplied to the dwUser parameter
 *                      of timeSetEvent.
 * DWORD dw1            Reserved; do not use.
 * DWORD dw2            Reserved; do not use.
 * ---------------------------------------------------------------------------
 */
static void CALLBACK TimeProc_CallbackFunction( UINT uID, UINT uMsg,
                                                DWORD dwUser,  
                                                DWORD dw1, DWORD dw2 )
{
   /* Call the real callback function for this Win32_Timer instance */
   ((struct Win32_Timer*) dwUser)->theCallbackFunction();
}

/* ### End of file Win32_Timer.c ### */
