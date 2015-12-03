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
 *  File Name .............. TinyList.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyList is designed to hold a list (vector) of void* pointers.
 * The TinyListElement holds the pointer as a singly-linked list element.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYLIST_H
#define TINYLIST_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "ArchitectureConfig.h"
#include "GlobalTypeDefs.h"
#include "TinyChain.h"
#include "TinyTrace.h"
#include "TinyPool.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The TinyListElement Structure */
struct TinyListElement;
typedef struct TinyListElement TinyListElement;

struct TinyListElement
{
/* The TinyPoolElement member for TinyListElement pool elements
   (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

/* Pointer to the real list element. */
   void* element;

/* Pointer to the next element in the list. */
   struct TinyListElement* next;
};

/* The TinyListIterator Structure */
struct TinyListIterator;
typedef struct TinyListIterator TinyListIterator;

struct TinyListIterator
{
/* Pointer to the next iteration element in the list. */
   struct TinyListElement* nextIterationElement;
};

/* The TinyList Structure */
struct TinyList;
typedef struct TinyList TinyList;

struct TinyList
{
/* Pointer to the first element in the list. */
   struct TinyListElement* firstElement;

/* Pointer to the last element in the list. */
   struct TinyListElement* lastElement;

/* Number of elements in the list. */
   unsigned long numberOfElements;

/* Current capacity of the list. */
   unsigned long currentCapacity;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the TinyList.
   NOTE: This function must be invoked on startup of the system function. */
void initialize_TinyList( void );

/* Function for shutting down the TinyList. */
void shutdown_TinyList( void );

/* Function for preparing the iterator for iterating the list. */
__inlined__ void prepareListIteration( const struct TinyList* self,
                                       struct TinyListIterator* iterator );

/* Function for retrieving any element from the TinyList instance. */
__inlined__ void* getAnyListElement( const struct TinyList* self );

/* Function for retrieving the next iteration TinyList element. */
__inlined__ void* getNextListIterationElement( struct TinyListIterator* iterator );

/* Function for adding an "element" behind the last "element" in the list. */
__inlined__ void pushBackList( struct TinyList* self, void* element );

/* Function for checking if a specific "element" exists in the list. */
void* existsInList( const struct TinyList* self, void* testElement );

/* Function for searching and removing a specific "element" from the list. */
void searchRemoveListElement( struct TinyList* self, void* element );

/* Function for retrieving the number of elements in the list. */
__inlined__ unsigned long listSize( const struct TinyList* self );

/* Function for emptying a TinyList instance (while preserving its capacity). */
__inlined__ void emptyList( struct TinyList* self );

/* Function for emptying a TinyList instance fast (while preserving its capacity). */
__inlined__ void emptyListFast( struct TinyList* self );

/* Function for deleting the "self" TinyList content. */
__inlined__ void deleteListContent( struct TinyList* self );

/* Function for copying a sourceList instance into the "self" TinyList instance. */
void copyFromList( struct TinyList* self, const struct TinyList* sourceList );

/* Function for copying a sourceChain instance into the "self" TinyList instance. */
void copyFromChain( struct TinyList* self, const struct TinyChain* sourceChain );

/* Label for direct access to the TinyListElement pool
   (for seizing pre-allocated TinyListElement instances) */
extern struct TinyPool gs_TinyListElementPool;

/* ---------------------------------------------------------------------------
 * Function for preparing the iterator for iterating the list.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the source TinyList instance.
 * TinyListIterator*    The TinyListIterator instance used for iteration.
 *
 * OUTPUT               DESCRIPTION
 *                      The iterator is pointing at the first list
 *                      element to retrieve when iterating the list.
 * ---------------------------------------------------------------------------
 */
__inlined__ void prepareListIteration( const struct TinyList* self,
                                       struct TinyListIterator* iterator )
{
   iterator->nextIterationElement = self->firstElement;
}

/* ---------------------------------------------------------------------------
 * Function for retrieving any element from the TinyList instance.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the source TinyList instance.
 *
 * RETURNS              DESCRIPTION
 * void*                The pointer to the first element in the list.
 *                      If the list is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* getAnyListElement( const struct TinyList* self )
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
 * Function for retrieving the next iteration TinyList element.
 *
 * INPUT                DESCRIPTION
 * TinyListIterator*    The TinyListIterator instance used for iteration,
 *                      pointing at the list element to retrieve.
 *
 * OUTPUT               DESCRIPTION
 *                      The iterator is pointing at the next list element.
 *
 * RETURNS              DESCRIPTION
 * void*                The pointer by which the element is instansiated.
 *                      If nextIterationElement is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* getNextListIterationElement( struct TinyListIterator* iterator )
{
   struct TinyListElement* tempListElement = iterator->nextIterationElement;
   if (tempListElement != NULL)
   {
      iterator->nextIterationElement = tempListElement->next;
      return tempListElement->element;
   }
   else
   {
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for adding an "element" behind the last "element" in the list.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * void*                Pointer to the element pushed onto the list.
 * ---------------------------------------------------------------------------
 */
__inlined__ void pushBackList( struct TinyList* self, void* element )
{
   struct TinyListElement* newElement;

   /* Check if the target list is full (filled up to its capacity) */
   if ( self->numberOfElements == self->currentCapacity )
   {
      /* Try to seize a TinyListElement instance in the pool */
      newElement = (struct TinyListElement*) seizePoolElement( &gs_TinyListElementPool );

      /* Check if seizing a free pool element failed */
      if ( newElement == NULL )
      {
         /* Trace output: Pool is exhausted */
         infoTrace_PoolIsExhausted( "TinyListElement", gs_TinyListElementPool.highWaterMark, "pushBackList" );

         /* Allocate the TinyListElement instance on the heap */
         newElement = (struct TinyListElement*) malloc( sizeof(struct TinyListElement) );

         /* Check if memory allocation was successful */
         if ( newElement != NULL )
         {
            /* Indicate TinyListElement instance heap allocation */
            newElement->poolElement.next     = NULL;
            newElement->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if a list element is allocated */
      if ( newElement != NULL )
      {
         /* Check if this is the very first element */
         if (self->currentCapacity == 0)
         {
            newElement->next   = newElement;
            self->firstElement = newElement;
         }
         else
         {
           /* Add the newElement to the back of an already existing list */
            newElement->next        = self->firstElement;
            self->lastElement->next = newElement;
         }
         self->currentCapacity++;
      }
   }
   else
   {
      /* Check if this is the first element in an existing list */
      if (self->numberOfElements == 0)
      {
         newElement = self->firstElement;
      }
      else
      {
         newElement = self->lastElement->next;
      }
   }

   /* Check if a list element is allocated */
   if ( newElement != NULL )
   {
      /* Push the element onto the list */
      newElement->element = element;
      self->lastElement   = newElement;
      self->numberOfElements++;
   }
}

/* ---------------------------------------------------------------------------
 * Function for retrieving the number of elements in the list.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the source TinyList instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The number of elements stored in the list.
 * ---------------------------------------------------------------------------
 */
__inlined__ unsigned long listSize( const struct TinyList* self )
{
   return self->numberOfElements;
}

/* ---------------------------------------------------------------------------
 * Function for emptying a TinyList instance (while preserving its capacity).
 *
 * NOTE: This function should ONLY be invoked for instance set variables
 *       (lists) created as local variables in actions, and immediately
 *       before re-assigning an existing variable with a new instance set.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * ---------------------------------------------------------------------------
 */
__inlined__ void emptyList( struct TinyList* self )
{
   struct TinyListElement* listElement = self->firstElement;
   while (self->numberOfElements > 0)
   {
      /* Empty the TinyListElement instance */
      listElement->element = NULL;

      listElement = listElement->next;
      self->numberOfElements--;
   }
}

/* ---------------------------------------------------------------------------
 * Function for emptying a TinyList instance fast (while preserving its capacity).
 *
 * NOTE: This function should ONLY be invoked for instance set variables
 *       (lists) created as local variables in actions, and immediately
 *       before re-assigning an existing variable with a new instance set.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * ---------------------------------------------------------------------------
 */
__inlined__ void emptyListFast( struct TinyList* self )
{
   /* Empty the TinyList instance */
   self->numberOfElements = 0;
}

/* ---------------------------------------------------------------------------
 * Function for deleting the "self" TinyList content.
 *
 * NOTE: This function should ONLY be invoked for instance set variables (lists)
 *       created as local 'struct TinyList <name>' variables in action code,
 *       or as 'struct TinyList <name>' relationship navigation extensions,
 *       passing the address to the list variable (&<name>) as the 'self'
 *       argument (i.e. _not_ a list pointer value, which can be NULL).
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * ---------------------------------------------------------------------------
 */
__inlined__ void deleteListContent( struct TinyList* self )
{
   struct TinyListElement* deleteElement;
   struct TinyListElement* nextElement = self->firstElement;
   while (self->currentCapacity > 0)
   {
      deleteElement = nextElement;
      nextElement   = nextElement->next;

      /* Release memory for the TinyListElement instance */
      if (( deleteElement->poolElement.next     == NULL ) &&
          ( deleteElement->poolElement.previous == NULL ))
      {
         /* The TinyListElement instance is allocated on the heap */
         free( deleteElement );

         /* Decrease the number of used instances of pool-element-type.
            (memory is returned to where it was previously allocated) */
         gs_TinyListElementPool.numberOfUsedElements--;
      }
      else
      {
         /* The TinyListElement instance is allocated in the pool */
         returnPoolElement( &gs_TinyListElementPool, &deleteElement->poolElement );
      }

      self->currentCapacity--;
   }

   /* Clear the TinyList instance */
   self->firstElement     = NULL;
   self->lastElement      = NULL;
   self->numberOfElements = 0;
}

#ifdef __cplusplus
}
#endif

#endif /* TINYLIST_H */
