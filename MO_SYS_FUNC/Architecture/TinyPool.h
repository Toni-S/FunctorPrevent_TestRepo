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
 *  File Name .............. TinyPool.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyPool is designed to hold a vector of void* pointers.
 * The TinyPoolElement holds the pointer as a doubly-linked list element.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYPOOL_H
#define TINYPOOL_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "ArchitectureConfig.h"
#include "GlobalTypeDefs.h"
#include "Win32_JThread.h"
#include "Win32_Mutex.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/**************************************************************************
 * This TinyPoolElement is to be implemented as a struct member for pool  *
 * elements, holding the doubly-linked list pointers for the pool itself. *
 *                                                                        *
 * This TinyPoolElement member is to be placed as the FIRST member of all *
 * different pool element struct's to always align this member at the     *
 * same physical address as the pool element itself.                      *
 *                                                                        *
 **************************************************************************
 **************************************************************************
 *** This means that the TinyPoolElement member and the actual          ***
 *** pool element itself is located at the same physical address.       ***
 *** (unless the C code compiler behaves in a strange way)              ***
 **************************************************************************
 **************************************************************************
 *                                                                        *
 * The more proper way to arrange this would be to create a union of      *
 * all different pool element struct types. This has not been done yet.   *
 **************************************************************************/

/* The TinyPoolElement Structure */
struct TinyPoolElement;
typedef struct TinyPoolElement TinyPoolElement;

struct TinyPoolElement
{
/* Pointer to the next element in the pool.
   (= NULL when memory is allocated from the heap) */
   struct TinyPoolElement* next;

/* Pointer to the previous element in the pool.
   (= NULL when memory is allocated from the heap) */
   struct TinyPoolElement* previous;
};

/* The TinyPool Structure */
struct TinyPool;
typedef struct TinyPool TinyPool;

struct TinyPool
{
/* Pointer to the first free element in the pool. */
   struct TinyPoolElement* firstFreeElement;

/* Number of free elements in the pool. */
   unsigned long numberOfFreeElements;

/* The capacity of the pool. */
   unsigned long theCapacity;

/* Number of used elements of pool-element-type = Current Water Mark.
   (this includes number of elements allocated on the heap
    after an attempt to allocate a free element in the pool)  */
   unsigned long numberOfUsedElements;

/* The High Water Mark in number of used elements.
   (this can be used for fine tuning the size of the pool) */
   unsigned long highWaterMark;
};

/* Pool data element size definitions */
struct _Size16bytes_   { long dataElement[4]; };
struct _Size32bytes_   { long dataElement[8]; };
struct _Size64bytes_   { long dataElement[16]; };
struct _Size128bytes_  { long dataElement[32]; };
struct _Size256bytes_  { long dataElement[64]; };
struct _Size512bytes_  { long dataElement[128]; };
struct _Size1024bytes_ { long dataElement[256]; };
struct _Size2048bytes_ { long dataElement[512]; };
struct _Size4096bytes_ { long dataElement[1024]; };

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for seizing the first free element in the pool. */
__inlined__ void* seizePoolElement( struct TinyPool* self );

/* Function for returning a specific element to the pool. */
__inlined__ void returnPoolElement( struct TinyPool* self, struct TinyPoolElement* returnElement );

/* Function for reading the Current Water Mark in number of used elements. */
unsigned long getCurrentWaterMark( const struct TinyPool* self );

/* Function for reading the High Water Mark in number of used elements. */
unsigned long getHighWaterMark( const struct TinyPool* self );

/* ---------------------------------------------------------------------------
 * Function for seizing the first free element in the pool.
 *
 * INPUT                DESCRIPTION
 * TinyPool*            Pointer to the source TinyPool instance.
 *
 * RETURNS              DESCRIPTION
 * void*                Pointer to a seized (free) element in the pool.
 *                      If no elements are available (free), NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* seizePoolElement( struct TinyPool* self )
{
   /* Local variable declarations */
   struct TinyPoolElement* freeElement;
   void* seizedElement;

   /* Increase the number of used instances of pool-element-type.
      (increased even if we fail to allocate a free element and must
       allocate the element on the heap when returning from this function) */
   self->numberOfUsedElements++;

   /************************************************************************************************
    *** NOTE1: The High Water Mark for a pool is set ONLY below!  (= simplifies generated code)  ***
    ***                                                                                          ***
    *** NOTE2: The numberOfUsedElements increase above will not make sense for a class instance  ***
    *** pool where the defined pool size is the "max limit" (defined by mark) in the number of   ***
    *** instances for the class. (= no heap allocation will be made when pool is exhausted)      ***
    ***                                                                                          ***
    *** The High Water Mark for a pool is set ONLY below (simplifies generated code) but the     ***
    *** High Water Mark figure will not be valid for "max limit" sized pools. (= pointless)      ***
    ***                                                                                          ***
    *** The intended use for the High Water Mark is to print its value when heap allocation is   ***
    *** made, thus providing information on how to fine tune the size of the pool in question.   ***
    *** (= to which size the pool should be increased to improve memory allocation performance)  ***
    ************************************************************************************************/

   /* Check if a new High Water Mark is reached */
   if ( self->numberOfUsedElements > self->highWaterMark )
   {
      /* Register this new High Water Mark */
      self->highWaterMark = self->numberOfUsedElements;
   }

   /* Check if there is at least one free element in the pool */
   if ( self->numberOfFreeElements > 0 )
   {

      /* Get the first free element in the pool */
      freeElement = self->firstFreeElement;

      /* Point out the next element as the new "first free element" */
      self->firstFreeElement = freeElement->next;

      /* The number of free elements in the pool is reduced */
      self->numberOfFreeElements--;

      /*************************************************************************
      **************************************************************************
      *** The below means that the TinyPoolElement member and the actual     ***
      *** pool element itself is located at the same physical address.       ***
      *** (unless the C code compiler behaves in a strange way)              ***
      **************************************************************************
      *************************************************************************/

      /* Get the element to seize */
      seizedElement = freeElement;

   }
   else
   {
      /* THERE ARE NO FREE ELEMENTS TO SEIZE */

      /* Indicate failure to seize a free element by returning NULL */
      seizedElement = NULL;
   }

   /* Return the seized pool element */
   return seizedElement;
}

/* ---------------------------------------------------------------------------
 * Function for returning a specific element to the pool.
 *
 * INPUT                DESCRIPTION
 * TinyPool*            Pointer to the target TinyPool instance.
 * TinyPoolElement*     Pointer to the TinyPoolElement instance
 *                      containing the element to return.
 * ---------------------------------------------------------------------------
 */
__inlined__ void returnPoolElement( struct TinyPool* self, struct TinyPoolElement* returnElement )
{
   /* Decrease the number of used instances of pool-element-type.
      (memory is returned to where it was previously allocated) */
   self->numberOfUsedElements--;

   /* Check if the returned element already is pointed at
      as the first free element in the pool (next to be seized) */
   if ( returnElement != self->firstFreeElement )
   {
      /* Get the previous and next elements related to the element to return */
      struct TinyPoolElement* returnElement_previous = returnElement->previous;
      struct TinyPoolElement* returnElement_next     = returnElement->next;

      /* Get the first free element in the pool */
      struct TinyPoolElement* firstFreeElement = self->firstFreeElement;

      /* Declare variable for element preceding the first free element */
      struct TinyPoolElement* firstFreeElement_previous;

      /* Release the element to return from the chain link */
      returnElement_previous->next = returnElement_next;
      returnElement_next->previous = returnElement_previous;

      /* Get the element preceding the first free element */
      firstFreeElement_previous = firstFreeElement->previous;

      /* INSERT THE RETURNED ELEMENT BEFORE THE FIRST FREE ELEMENT: */

      /* Link the element before the first free element to the returned element */
      firstFreeElement_previous->next = returnElement;
      returnElement->previous         = firstFreeElement_previous;

      /* Link the first free element to the returned element */
      firstFreeElement->previous = returnElement;
      returnElement->next        = firstFreeElement;

      /* This is the element possible to seize next */
      self->firstFreeElement = returnElement;
   }

   /* The number of free elements in the pool is increased */
   self->numberOfFreeElements++;

}

#ifdef __cplusplus
}
#endif

#endif /* TINYPOOL_H */
