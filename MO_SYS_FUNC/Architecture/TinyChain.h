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
 *  File Name .............. TinyChain.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyChain is designed to hold a chain of void* pointers.
 * The TinyChainElement holds the pointer as a doubly-linked list element.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYCHAIN_H
#define TINYCHAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "GlobalTypeDefs.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/****************************************************************************************
 * NOTE1: A TinyChainElement IS EXPECTED TO BE IMPLEMENTED AS A DEFAULT MEMBER OF THE   *
 *        STRUCT IMPLEMENTING OBJECTS TO BE CHAINED IN RUNTIME, SUCH AS TimerEvent's    *
 *        OR THE STRUCT FOR MODELLED CLASSES WHICH __NOT__ HAVE PRE-EXISTING INSTANCES. *
 *                                                                                      *
 * NOTE2: THE element MEMBER IS EXPECTED TO BE ASSIGNED RIGHT AFTER THE MEMORY HAS BEEN *
 *        ALLOCATED FOR THE OBJECT TO BE CHAINED.                                       *
 ****************************************************************************************/

/* The TinyChainElement Structure */
struct TinyChainElement;
typedef struct TinyChainElement TinyChainElement;

struct TinyChainElement
{
/* Pointer to the real chain element.
   (= NULL when not present in a chain) */
   void* element;

/* Pointer to the next element in the chain. */
   struct TinyChainElement* next;

/* Pointer to the previous element in the chain. */
   struct TinyChainElement* previous;
};

/* The TinyChainIterator Structure */
struct TinyChainIterator;
typedef struct TinyChainIterator TinyChainIterator;

struct TinyChainIterator
{
/* Pointer to the next iteration element in the chain. */
   struct TinyChainElement* nextIterationElement;
};

/* The TinyChain Structure */
struct TinyChain;
typedef struct TinyChain TinyChain;

struct TinyChain
{
/* Pointer to the first element in the chain. */
   struct TinyChainElement* firstElement;

/* Pointer to the last element in the chain. */
   struct TinyChainElement* lastElement;

/* Number of elements in the chain. */
   unsigned long numberOfElements;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for preparing the iterator for iterating the chain. */
__inlined__ void prepareChainIteration( const struct TinyChain* self,
                                        struct TinyChainIterator* iterator );

/* Function for retrieving any element from the TinyChain instance. */
__inlined__ void* getAnyChainElement( const struct TinyChain* self );

/* Function for retrieving the next iteration TinyChain element. */
__inlined__ void* getNextChainIterationElement( struct TinyChainIterator* iterator );

/* Function for adding an "element" behind the last "element" in the chain. */
__inlined__ void pushBackChain( struct TinyChain* self, struct TinyChainElement* chainElement );

/* Function for removing a specific "element" from the chain. */
__inlined__ void removeChainElement( struct TinyChain* self, struct TinyChainElement* chainElement );

/* Function for retrieving the number of elements in the chain. */
__inlined__ unsigned long chainSize( const struct TinyChain* self );

/* ---------------------------------------------------------------------------
 * Function for preparing the iterator for iterating the chain.
 *
 * INPUT                DESCRIPTION
 * TinyChain*           Pointer to the source TinyChain instance.
 * TinyChainIterator*   The TinyChainIterator instance used for iteration.
 *
 * OUTPUT               DESCRIPTION
 *                      The iterator is pointing at the first chain
 *                      element to retrieve when iterating the chain.
 * ---------------------------------------------------------------------------
 */
__inlined__ void prepareChainIteration( const struct TinyChain* self,
                                        struct TinyChainIterator* iterator )
{
   iterator->nextIterationElement = self->firstElement;
}

/* ---------------------------------------------------------------------------
 * Function for retrieving any element from the TinyChain instance.
 *
 * INPUT                DESCRIPTION
 * TinyChain*           Pointer to the source TinyChain instance.
 *
 * RETURNS              DESCRIPTION
 * void*                The pointer to the first element in the chain.
 *                      If the chain is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* getAnyChainElement( const struct TinyChain* self )
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
 * Function for retrieving the next iteration TinyChain element.
 *
 * INPUT                DESCRIPTION
 * TinyChainIterator*   The TinyChainIterator instance used for iteration,
 *                      pointing at the chain element to retrieve.
 *
 * OUTPUT               DESCRIPTION
 *                      The iterator is pointing at the next chain element.
 *
 * RETURNS              DESCRIPTION
 * void*                The pointer by which the element is instansiated.
 *                      If nextIterationElement is empty, NULL is returned.
 * ---------------------------------------------------------------------------
 */
__inlined__ void* getNextChainIterationElement( struct TinyChainIterator* iterator )
{
   struct TinyChainElement* tempChainElement = iterator->nextIterationElement;
   if (tempChainElement != NULL)
   {
      iterator->nextIterationElement = tempChainElement->next;
      return tempChainElement->element;
   }
   else
   {
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for adding an "element" behind the last "element" in the chain.
 *
 * INPUT                DESCRIPTION
 * TinyChain*           Pointer to the target TinyChain instance.
 * TinyChainElement*    Pointer to the TinyChainElement for the
 *                      real chain element pushed onto the chain.
 * ---------------------------------------------------------------------------
 */
__inlined__ void pushBackChain( struct TinyChain* self, struct TinyChainElement* chainElement )
{
   /* Check if this is the very first element */
   if (self->numberOfElements == 0)
   {
      chainElement->next     = chainElement;
      chainElement->previous = chainElement;
      self->firstElement     = chainElement;
   }
   else
   {
      /* Add the chainElement to the back of an already existing chain */
      chainElement->next           = self->firstElement;
      chainElement->previous       = self->lastElement;
      self->firstElement->previous = chainElement;
      self->lastElement->next      = chainElement;
   }

   /* Push the element onto the chain */
   self->lastElement = chainElement;
   self->numberOfElements++;
}

/* ---------------------------------------------------------------------------
 * Function for removing a specific "element" from the chain.
 *
 * INPUT                DESCRIPTION
 * TinyChain*           Pointer to the target TinyChain instance.
 * TinyChainElement*    Pointer to the TinyChainElement instance
 *                      containing the element to remove.
 * ---------------------------------------------------------------------------
 */
__inlined__ void removeChainElement( struct TinyChain* self, struct TinyChainElement* chainElement )
{
   /* Check that a chainElement is specified */
   if ( chainElement != NULL )
   {
      struct TinyChainElement* removeElement = chainElement;

      /* Check if the element to remove is the first element in the chain */
      if (removeElement == self->firstElement)
      {
         /* Move the pointer to the first element 1 step forward */
         self->firstElement = self->firstElement->next;
      }
      /* Check if the element to remove is the last element in the chain */
      else if (removeElement == self->lastElement)
      {
         /* Move the pointer to the last element 1 step backwards */
         self->lastElement = self->lastElement->previous;
      }

      /* Release the element to remove from the chain link */
      removeElement->previous->next = removeElement->next;
      removeElement->next->previous = removeElement->previous;

      /* The number of elements in the chain is reduced */
      self->numberOfElements--;

      /* Check if this was the last element in the chain */
      if ( self->numberOfElements == 0 )
      {
         /* Clear the chain */
         self->firstElement = NULL;
         self->lastElement  = NULL;
      }
   }
}

/* ---------------------------------------------------------------------------
 * Function for retrieving the number of elements in the chain.
 *
 * INPUT                DESCRIPTION
 * TinyChain*           Pointer to the source TinyChain instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The number of elements stored in the chain.
 * ---------------------------------------------------------------------------
 */
__inlined__ unsigned long chainSize( const struct TinyChain* self )
{
   return self->numberOfElements;
}

#ifdef __cplusplus
}
#endif

#endif /* TINYCHAIN_H */
