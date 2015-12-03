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
 *  File Name .............. TinyQueue.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyQueue.h"
#include "Win32_Mutex.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* The TinyQueueElement pool */
static struct TinyQueueElement s_TinyQueueElements[_TinyQueueElementPoolSize];
struct TinyPool s_TinyQueueElementPool = {NULL, 0, 0, 0, 0};

/* TinyQueueElement pool access semaphore for the TimerEvent dispatcher
   (this is for preventing TimerEvent deliveries during pool access) */
fastBool tinyQueueElementPoolIsAccessed = false;

/* ---------------------------------------------------------------------------
 * Function for initializing the TinyQueue.
 * NOTE: This function must be invoked on startup of the system function.
 * ---------------------------------------------------------------------------
 */
void initialize_TinyQueue( void )
{
   /* Indicate for the TimerEvent dispatcher that the
      TinyQueueElement pool is being accessed */
   tinyQueueElementPoolIsAccessed = true;

   /* Initialize the TinyQueueElement pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_TinyQueueElements[_TinyQueueElementPoolSize - 1].poolElement;
      for (index = 0; index < _TinyQueueElementPoolSize; index++)
      {
         theElement            = &s_TinyQueueElements[index].poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      s_TinyQueueElementPool.firstFreeElement      = &s_TinyQueueElements[0].poolElement;
      s_TinyQueueElementPool.numberOfFreeElements  = _TinyQueueElementPoolSize;
      s_TinyQueueElementPool.theCapacity           = _TinyQueueElementPoolSize;
      s_TinyQueueElementPool.numberOfUsedElements  = 0;
      s_TinyQueueElementPool.highWaterMark         = 0;
   }

   /* Indicate for the TimerEvent dispatcher that the
      TinyQueueElement pool no longer is accessed */
   tinyQueueElementPoolIsAccessed = false;
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the TinyQueue.
 * ---------------------------------------------------------------------------
 */
void shutdown_TinyQueue( void )
{
}

/* ### End of file TinyQueue.c ### */
