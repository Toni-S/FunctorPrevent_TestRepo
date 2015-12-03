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
 *  File Name .............. TinyVector.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyVector is designed to hold a vector of void* pointers.
 * The TinyVectorElement holds the pointer as a doubly-linked list element.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYVECTOR_H
#define TINYVECTOR_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "GlobalTypeDefs.h"
#include "TinyTrace.h"
#include "TinyPool.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The TinyVectorElement Structure */
struct TinyVectorElement;
typedef struct TinyVectorElement TinyVectorElement;

struct TinyVectorElement
{
/* The TinyPoolElement member for TinyVectorElement pool elements
   (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

/* Pointer to the real vector element. */
   void* element;

/* Pointer to the next element in the vector. */
   struct TinyVectorElement* next;

/* Pointer to the previous element in the vector. */
   struct TinyVectorElement* previous;
};

/* The TinyVectorIterator Structure */
struct TinyVectorIterator;
typedef struct TinyVectorIterator TinyVectorIterator;

struct TinyVectorIterator
{
/* Pointer to the next iteration element in the vector. */
   struct TinyVectorElement* nextIterationElement;
};

/* The TinyVector Structure */
struct TinyVector;
typedef struct TinyVector TinyVector;

struct TinyVector
{
/* Pointer to the first element in the vector. */
   struct TinyVectorElement* firstElement;

/* Pointer to the last element in the vector. */
   struct TinyVectorElement* lastElement;

/* Number of elements in the vector. */
   unsigned long numberOfElements;

/* Current capacity of the vector. */
   unsigned long currentCapacity;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the TinyVector.
   NOTE: This function must be invoked on startup of the system function. */
void initialize_TinyVector( void );

/* Function for shutting down the TinyVector. */
void shutdown_TinyVector( void );

/* Function for preparing the iterator for iterating the vector. */
__inlined__ void prepareVectorIteration( const struct TinyVector* self,
                                         struct TinyVectorIterator* iterator );

/* Function for retrieving any element from the TinyVector instance. */
__inlined__ void* getAnyVectorElement( const struct TinyVector* self );

/* Function for retrieving the next iteration TinyVector element. */
__inlined__ void* getNextVectorIterationElement( struct TinyVectorIterator* iterator );

/* Label for direct access to the TinyVectorElement pool
   (for seizing pre-allocated TinyVectorElement instances) */
extern struct TinyPool s_TinyVectorElementPool;

/* Function for adding an "element" behind the last "element" in the vector. */
__inlined__ void* pushBackVector( struct TinyVector* self, void* element, struct TinyPool* pool );

/* Function for retrieving and removing the first "element" in the vector. */
void* popFrontVector( struct TinyVector* self );

/* Function for checking if a specific "element" exists in the vector. */
void* existsInVector( const struct TinyVector* self, void* testElement );

/* Function for retrieving the number of elements in the vector. */
__inlined__ unsigned long vectorSize( const struct TinyVector* self );

/* Function for emptying a TinyVector instance (preserving its capacity). */
void emptyVector( struct TinyVector* self );

/* Function for removing a specific "element" from the vector. */
__inlined__ void removeVectorElement( struct TinyVector* self, void* vectorElement );

/* ---------------------------------------------------------------------------
 * Function for preparing the iterator for iterating the vector.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the source TinyVector instance.
 * TinyVectorIterator*  The TinyVectorIterator instance used for iteration.
 *
 * OUTPUT               DESCRIPTION
 *                      The iterator is pointing at the first vector
 *                      element to retrieve when iterating the vector.
 * ---------------------------------------------------------------------------
 */
__inlined__ void prepareVectorIteration( const struct TinyVector* self,
                                         struct TinyVectorIterator* iterator )
{
   iterator->nextIterationElement = self->firstElement;
}

/* ---------------------------------------------------------------------------
 * Function for retrieving any element from the TinyVector instance.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the source TinyVector instance.
 *
 * RETURNS              DESCRIPTION
 * void*                The pointer to the first element in the vector.
 *                      If the vector is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* getAnyVectorElement( const struct TinyVector* self )
{
   if (self->numberOfElements > 0)
   {
      return self->firstElement->element;
   }
   else
   {
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for retrieving the next iteration TinyVector element.
 *
 * INPUT                DESCRIPTION
 * TinyVectorIterator*  The TinyVectorIterator instance used for iteration,
 *                      pointing at the vector element to retrieve.
 *
 * OUTPUT               DESCRIPTION
 *                      The iterator is pointing at the next vector element.
 *
 * RETURNS              DESCRIPTION
 * void*                The pointer by which the element is instansiated.
 *                      If nextIterationElement is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* getNextVectorIterationElement( struct TinyVectorIterator* iterator )
{
   struct TinyVectorElement* tempVectorElement = iterator->nextIterationElement;
   if (tempVectorElement != NULL)
   {
      iterator->nextIterationElement = tempVectorElement->next;
      return tempVectorElement->element;
   }
   else
   {
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for adding an "element" behind the last "element" in the vector.
 *
 * NOTE: This function supports seizure of TinyVectorElement instances
 *       from an arbitrary pool. The main reason for this is that the
 *       TimerEvent.c has its own pool of TinyVector elements.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the target TinyVector instance.
 * void*                Pointer to the element pushed onto the vector.
 * TinyPool*            Pointer to the TinyVectorElement pool from which to
 *                      seize a pre-allocated TinyVectorElement instance.
 *
 * RETURNS              DESCRIPTION
 * void*                Pointer to the TinyVectorElement instance into which
 *                      the input element is stored (used on remove element).
 * ---------------------------------------------------------------------------
 */
__inlined__ void* pushBackVector( struct TinyVector* self, void* element, struct TinyPool* pool )
{
   struct TinyVectorElement* newElement;

   /* Check if the target vector is full (filled up to its capacity) */
   if (self->numberOfElements == self->currentCapacity)
   {
      /* Try to seize a TinyVectorElement instance in the pool */
      newElement = (struct TinyVectorElement*) seizePoolElement( pool );

      /* Check if seizing a free pool element failed */
      if ( newElement == NULL )
      {
         /* Trace output: Pool is exhausted */
         infoTrace_PoolIsExhausted( "TinyVectorElement", pool->highWaterMark, "pushBackVector" );

         /* Allocate the TinyVectorElement instance on the heap */
         newElement = (struct TinyVectorElement*) malloc( sizeof(struct TinyVectorElement) );

         /* Check if memory allocation was successful */
         if ( newElement != NULL )
         {
            /* Indicate TinyVectorElement instance heap allocation */
            newElement->poolElement.next     = NULL;
            newElement->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if a vector element is allocated */
      if ( newElement != NULL )
      {
         /* Check if this is the very first element */
         if (self->currentCapacity == 0)
         {
            newElement->next     = newElement;
            newElement->previous = newElement;
            self->firstElement   = newElement;
         }
         else
         {
            /* Add the newElement to the back of an already existing vector */
            newElement->next             = self->firstElement;
            newElement->previous         = self->lastElement;
            self->firstElement->previous = newElement;
            self->lastElement->next      = newElement;
         }
         self->currentCapacity++;
      }
   }
   else
   {
      /* Check if this is the first element in an existing vector */
      if (self->numberOfElements == 0)
      {
         newElement = self->firstElement;
      }
      else
      {
         newElement = self->lastElement->next;
      }
   }

   /* Check if a vector element is allocated */
   if ( newElement != NULL )
   {
      /* Push the element onto the vector */
      newElement->element = element;
      self->lastElement   = newElement;
      self->numberOfElements++;
   }

   return newElement;
}

/* ---------------------------------------------------------------------------
 * Function for removing a specific "element" from the vector.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the target TinyVector instance.
 * void*                Pointer to the TinyVectorElement instance (returned
 *                      e.g. from push back) containing the element to remove.
 * ---------------------------------------------------------------------------
 */
__inlined__ void removeVectorElement( struct TinyVector* self, void* vectorElement )
{
   /* Check that a vectorElement is specified */
   if ( vectorElement != NULL )
   {
      struct TinyVectorElement* removeElement = (TinyVectorElement*) vectorElement;
      removeElement->element                  = NULL;

      /* Check if the element to remove is the first element in the vector */
      if (removeElement == self->firstElement)
      {
         /* Just move the pointer to the first element 1 step forward */
         self->firstElement = self->firstElement->next;
      }
      /* Check if the element to remove is the last element in the vector */
      else if (removeElement == self->lastElement)
      {
         /* Just move the pointer to the last element 1 step backwards */
         self->lastElement = self->lastElement->previous;
      }
      else
      {
         /* Release the element to remove from the chain link */
         removeElement->previous->next = removeElement->next;
         removeElement->next->previous = removeElement->previous;

         /* Link the element after the last to the removed element */
         removeElement->next               = self->lastElement->next;
         self->lastElement->next->previous = removeElement;

         /* Link the last element to the removed element */
         removeElement->previous = self->lastElement;
         self->lastElement->next = removeElement;
      }

      /* The number of elements in the vector is reduced */
      self->numberOfElements--;
   }
}

/* ---------------------------------------------------------------------------
 * Function for retrieving the number of elements in the vector.
 *
 * INPUT                DESCRIPTION
 * TinyVector*          Pointer to the source TinyVector instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The number of elements stored in the vector.
 * ---------------------------------------------------------------------------
 */
__inlined__ unsigned long vectorSize( const struct TinyVector* self )
{
   return self->numberOfElements;
}

#ifdef __cplusplus
}
#endif

#endif /* TINYVECTOR_H */
