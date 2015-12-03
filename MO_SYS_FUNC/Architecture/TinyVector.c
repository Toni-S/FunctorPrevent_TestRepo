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
 *  File Name .............. TinyVector.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyVector.h"
#include "ArchitectureConfig.h"
#include "Win32_Mutex.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* The TinyVectorElement pool */
static struct TinyVectorElement s_TinyVectorElements[_TinyVectorElementPoolSize];
struct TinyPool s_TinyVectorElementPool = {NULL, 0, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * Function for initializing the TinyVector.
 * NOTE: This function must be invoked on startup of the system function.
 * ---------------------------------------------------------------------------
 */
void initialize_TinyVector( void )
{
   /* Initialize the TinyVectorElement pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_TinyVectorElements[_TinyVectorElementPoolSize - 1].poolElement;
      for (index = 0; index < _TinyVectorElementPoolSize; index++)
      {
         theElement            = &s_TinyVectorElements[index].poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      s_TinyVectorElementPool.firstFreeElement      = &s_TinyVectorElements[0].poolElement;
      s_TinyVectorElementPool.numberOfFreeElements  = _TinyVectorElementPoolSize;
      s_TinyVectorElementPool.theCapacity           = _TinyVectorElementPoolSize;
      s_TinyVectorElementPool.numberOfUsedElements  = 0;
      s_TinyVectorElementPool.highWaterMark         = 0;
   }
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the TinyVector.
 * ---------------------------------------------------------------------------
 */
void shutdown_TinyVector( void )
{
}

/* ---------------------------------------------------------------------------
 * Function for retrieving and removing the first "element" in the vector.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the source TinyVector instance.
 *
 * RETURNS              DESCRIPTION
 * void*                Pointer to the element popped from the vector.
 *                      If the vector is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
void* popFrontVector( struct TinyVector* self )
{
   if (self->numberOfElements > 0)
   {
      void* tempElement           = self->firstElement->element;
      self->firstElement->element = NULL;
      self->firstElement          = self->firstElement->next;
      self->numberOfElements--;
      return tempElement;
   }
   else
   {
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for checking if a specific "element" exists in the vector.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the source TinyVector instance.
 * void*                The element to check.
 *
 * RETURNS              DESCRIPTION
 * void*                NULL is returned if element does not exist in vector.
 *                      Otherwise the TinyVectorElement holding the "element"
 *                      is returned. (use e.g as input to removeVectorElement)
 * ---------------------------------------------------------------------------
 */
void* existsInVector( const struct TinyVector* self, void* testElement )
{
   unsigned long search;
   void* resultElement = NULL;
   struct TinyVectorElement* vectorElement = self->firstElement;
   for (search = 0; self->numberOfElements > search; search++)
   {
      /* Is this the element searched for? */
      if (testElement == vectorElement->element)
      {
         /* Get the TinyVectorElement to return and break out */
         resultElement = vectorElement;
         break;
      }
      vectorElement = vectorElement->next;
   }
   return resultElement;
}

/* ---------------------------------------------------------------------------
 * Function for emptying a TinyVector instance (preserving its capacity).
 *
 * NOTE: This function should ONLY be invoked for instance set variables
 *       (vectors) created as local variables in actions, and immediately
 *       before re-assigning an existing variable with a new instance set.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the target TinyVector instance.
 * ---------------------------------------------------------------------------
 */
void emptyVector( struct TinyVector* self )
{
   struct TinyVectorElement* vectorElement = self->firstElement;
   while (self->numberOfElements > 0)
   {
      /* Empty the TinyVectorElement instance */
      vectorElement->element = NULL;

      vectorElement = vectorElement->next;
      self->numberOfElements--;
   }
}

/* ### End of file TinyVector.c ### */
