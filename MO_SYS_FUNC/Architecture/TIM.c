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
 *  File Name .............. TIM.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TIM.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* Current clock & date not needed by this system function (no such code generated) */

/* ---------------------------------------------------------------------------
 * The timer_add_time bridge.
 *
 * INPUT                DESCRIPTION
 * long                 The additional delay time in microseconds.
 * TimerEvent*          Pointer to the TimerEvent instance.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the TimerEvent instance exists.
 * ---------------------------------------------------------------------------
 */
bool TIM_timer_add_time( long timeToAdd, const struct TimerEvent* theTimerEvent )
{
   /* Check if the timer event really exists */
   if ( theTimerEvent != NULL )
   {
      /* Add additional delay time for the timer event */
      return (bool) addTime_TimerEvent((struct TimerEvent*) theTimerEvent, (unsigned long) timeToAdd);
   }
   else
   {
      /* The timer event does not exist */
      return false;
   }
}

/* ---------------------------------------------------------------------------
 * The timer_cancel bridge.
 *
 * INPUT                DESCRIPTION
 * TimerEvent*          Pointer to the TimerEvent instance.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the TimerEvent instance exists.
 * ---------------------------------------------------------------------------
 */
bool TIM_timer_cancel( const struct TimerEvent* theTimerEvent )
{
   /* Check if the timer event really exists */
   if ( theTimerEvent != NULL )
   {
      /* Cancel the timer event */
      return (bool) cancel_TimerEvent((struct TimerEvent*) theTimerEvent);
   }
   else
   {
      /* The timer event does not exist */
      return false;
   }
}

/* ---------------------------------------------------------------------------
 * The timer_remaining_time bridge.
 *
 * INPUT                DESCRIPTION
 * TimerEvent*          Pointer to the TimerEvent instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The remaining time until the TimerEvent fires.
 *                      0 is returned if the TimerEvent does not exist.
 * ---------------------------------------------------------------------------
 */
unsigned long TIM_timer_remaining_time( const struct TimerEvent* theTimerEvent )
{
   /* Check if the timer event really exists */
   if ( theTimerEvent != NULL )
   {
      /* Retrieve remaining time until the timer event fires */
      return remainingTime_TimerEvent(theTimerEvent);
   }
   else
   {
      /* The timer event does not exist */
      return 0;
   }
}

/* ---------------------------------------------------------------------------
 * The timer_start bridge.
 *
 * INPUT                DESCRIPTION
 * GenericEvent*        Pointer to the event instance.
 * void*                Pointer to the event data.
 * void*                The recipient of the event.
 * long                 The delay time in microseconds.
 *
 * RETURNS              DESCRIPTION
 * TimerEvent*          Pointer to the created TimerEvent instance.
 *                      Returns NULL if the event to generate does not exist.
 * ---------------------------------------------------------------------------
 */
struct TimerEvent* TIM_timer_start( const struct GenericEvent* timerEvent,
                                    void* eventData,
                                    const void* recipient,
                                    long delayTime )
{
   /* Check if the event to generate really exists */
   if ( timerEvent != NULL )
   {
      /* Create a timer event (= single-shot timer) */
      return create_TimerEvent(timerEvent, eventData, recipient, (unsigned long) delayTime, false);
   }
   else
   {
      /* The event to generate does not exist */
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * The timer_start_recurring bridge.
 *
 * INPUT                DESCRIPTION
 * GenericEvent*        Pointer to the event instance.
 * void*                Pointer to the event data.
 * void*                The recipient of the event.
 * long                 The delay time in microseconds.
 *
 * RETURNS              DESCRIPTION
 * TimerEvent*          Pointer to the created TimerEvent instance.
 *                      Returns NULL if the event to generate does not exist.
 * ---------------------------------------------------------------------------
 */
struct TimerEvent* TIM_timer_start_recurring( const struct GenericEvent* timerEvent,
                                              void* eventData,
                                              const void* recipient,
                                              long delayTime )
{
   /* Check if the event to generate really exists */
   if ( timerEvent != NULL )
   {
      /* Create a recurring timer event (= periodic timer) */
      return create_TimerEvent(timerEvent, eventData, recipient, (unsigned long) delayTime, true);
   }
   else
   {
      /* The event to generate does not exist */
      return NULL;
   }
}

/* ### End of file TIM.c ### */
