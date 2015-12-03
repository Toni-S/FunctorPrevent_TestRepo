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
 *  File Name .............. TIM.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * This file implements the pre-defined External Entity named Time (TIM).
 * ---------------------------------------------------------------------------
 */
#ifndef TIM_H
#define TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "GenericEvent.h"
#include "TimerEvent.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Current clock & date not needed by this system function (no such code generated) */

/* The timer_add_time bridge. */
bool TIM_timer_add_time( long timeToAdd, const struct TimerEvent* theTimerEvent );

/* The timer_cancel bridge. */
bool TIM_timer_cancel( const struct TimerEvent* theTimerEvent );

/* The timer_remaining_time bridge. */
unsigned long TIM_timer_remaining_time( const struct TimerEvent* theTimerEvent );

/* The timer_reset_time bridge. */
__inlined__ bool TIM_timer_reset_time( long delayTime, const struct TimerEvent* theTimerEvent );

/* The timer_start bridge. */
struct TimerEvent* TIM_timer_start( const struct GenericEvent* timerEvent,
                                    void* eventData,
                                    const void* recipient,
                                    long delayTime );

/* The timer_start_recurring bridge. */
struct TimerEvent* TIM_timer_start_recurring( const struct GenericEvent* timerEvent,
                                              void* eventData,
                                              const void* recipient,
                                              long delayTime );

/* ---------------------------------------------------------------------------
 * The timer_reset_time bridge.
 *
 * INPUT                DESCRIPTION
 * long                 The new delay time in microseconds.
 * TimerEvent*          Pointer to the TimerEvent instance.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the TimerEvent instance exists.
 * ---------------------------------------------------------------------------
 */
__inlined__ bool TIM_timer_reset_time( long delayTime, const struct TimerEvent* theTimerEvent )
{
   /* Check if the timer event really exists */
   if ( theTimerEvent != NULL )
   {
      /* Set new delay time for the timer event */
      return (bool) setNewDelayTime_TimerEvent((struct TimerEvent*) theTimerEvent, (unsigned long) delayTime);
   }
   else
   {
      /* The timer event does not exist */
      return false;
   }
}

#ifdef __cplusplus
}
#endif

#endif /* TIM_H */
