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
 *  File Name .............. TinyList.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyList.h"
#include "Win32_Mutex.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* The TinyListElement pool */
static struct TinyListElement s_TinyListElements[_TinyListElementPoolSize];
struct TinyPool gs_TinyListElementPool = {NULL, 0, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * Function for initializing the TinyList.
 * NOTE: This function must be invoked on startup of the system function.
 * ---------------------------------------------------------------------------
 */
void initialize_TinyList( void )
{
   /* Initialize the TinyListElement pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_TinyListElements[_TinyListElementPoolSize - 1].poolElement;
      for (index = 0; index < _TinyListElementPoolSize; index++)
      {
         theElement            = &s_TinyListElements[index].poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      gs_TinyListElementPool.firstFreeElement      = &s_TinyListElements[0].poolElement;
      gs_TinyListElementPool.numberOfFreeElements  = _TinyListElementPoolSize;
      gs_TinyListElementPool.theCapacity           = _TinyListElementPoolSize;
      gs_TinyListElementPool.numberOfUsedElements  = 0;
      gs_TinyListElementPool.highWaterMark         = 0;
   }
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the TinyList.
 * ---------------------------------------------------------------------------
 */
void shutdown_TinyList( void )
{
}

/* ---------------------------------------------------------------------------
 * Function for checking if a specific "element" exists in the list.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the source TinyList instance.
 * void*                The element to check.
 *
 * RETURNS              DESCRIPTION
 * void*                NULL is returned if element does not exist in list.
 *                      Otherwise the TinyListElement holding the "element"
 *                      is returned.
 * ---------------------------------------------------------------------------
 */
void* existsInList( const struct TinyList* self, void* testElement )
{
   unsigned long search;
   void* resultElement = NULL;
   struct TinyListElement* listElement = self->firstElement;
   for (search = 0; self->numberOfElements > search; search++)
   {
      /* Is this the element searched for? */
      if (testElement == listElement->element)
      {
         /* Get the TinyListElement to return and break out */
         resultElement = listElement;
         break;
      }
      listElement = listElement->next;
   }
   return resultElement;
}

/* ---------------------------------------------------------------------------
 * Function for searching and removing a specific "element" from the list.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * void*                Pointer to the element to remove.
 * ---------------------------------------------------------------------------
 */
void searchRemoveListElement( struct TinyList* self, void* element )
{
   /* Check that an element is specified */
   if ( element != NULL )
   {
      unsigned long search;
      struct TinyListElement* listElement = self->firstElement;

      /* Check if the element to remove is the first element in the list */
      if (element == listElement->element)
      {
         /* Clear the element in the list */
         listElement->element = NULL;

         /* Just move the pointer to the first element 1 step forward */
         self->firstElement = listElement->next;

         /* The number of elements in the list is reduced */
         self->numberOfElements--;
      }
      else
      {
         struct TinyListElement* prevListElement;

         /* Search for the element to remove */
         for (search = 1; self->numberOfElements > search; search++)
         {
            /* Get the previous and next list elements */
            prevListElement = listElement;
            listElement     = listElement->next;

            /* Is this the element searched for ? */
            if (element == listElement->element)
            {
               /* Clear the element in the list */
               listElement->element = NULL;

               /* Check if the element to remove is the last element in the list */
               if (listElement == self->lastElement)
               {
                  /* Just move the pointer to the last element 1 step backwards */
                  self->lastElement = prevListElement;
               }
               else
               {
                  /* Release the element to remove from the chain link */
                  prevListElement->next = listElement->next;

                  /* Link the element after the last to the removed element */
                  listElement->next = self->lastElement->next;

                  /* Link the last element to the removed element */
                  self->lastElement->next = listElement;
               }

               /* The number of elements in the list is reduced */
               self->numberOfElements--;

               /* Removal completed - break out */
               break;
            }
         }
      }
   }
}

/* ---------------------------------------------------------------------------
 * Function for copying a sourceList instance into the "self" TinyList instance.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * TinyList*            Pointer to the source TinyList instance.
 *
 * OUTPUT               DESCRIPTION
 *                      The sourceList is added to the "self" targetList.
 * ---------------------------------------------------------------------------
 */
void copyFromList( struct TinyList* self, const struct TinyList* sourceList )
{
   /* Local variable declarations */
   unsigned long index;
   unsigned long numberOfElements = sourceList->numberOfElements;
   struct TinyListElement* targetElement;  /* NOTE: Must be initialized to NULL if
                                              the debugging code below is enabled */

   /* Get the first source element to copy */
   struct TinyListElement* sourceElement = sourceList->firstElement;

   /* Copy the sourceList instance into into the "self" targetList instance */
   for (index = 0; index < numberOfElements; index++)
   {
      /* Check if the target list is full (filled up to its capacity) */
      if ( self->numberOfElements == self->currentCapacity )
      {
         /* Try to seize a TinyListElement instance in the pool */
         targetElement = (struct TinyListElement*) seizePoolElement( &gs_TinyListElementPool );

         /* Check if seizing a free pool element failed */
         if ( targetElement == NULL )
         {
            /* Trace output: Pool is exhausted */
            infoTrace_PoolIsExhausted( "TinyListElement", gs_TinyListElementPool.highWaterMark, "copyFromList" );

            /* Allocate the TinyListElement instance on the heap */
            targetElement = (struct TinyListElement*) malloc( sizeof(struct TinyListElement) );

            /* Check if memory allocation was successful */
            if ( targetElement != NULL )
            {
               /* Indicate TinyListElement instance heap allocation */
               targetElement->poolElement.next     = NULL;
               targetElement->poolElement.previous = NULL;
            }
            else
            {
               /* Trace output: Pool is exhausted, malloc failed */
               infoTrace_HeapAllocationFailed();
            }
         }

         /* Check if a list element is allocated */
         if ( targetElement != NULL )
         {
            /* Check if this is the very first element */
            if (self->currentCapacity == 0)
            {
               targetElement->next = targetElement;
               self->firstElement  = targetElement;
            }
            else
            {
               /* Add the targetElement to the back of an already existing list */
               targetElement->next     = self->firstElement;
               self->lastElement->next = targetElement;
            }
            self->currentCapacity++;
         }
      }
      else
      {
         if (self->numberOfElements == 0)  /* First in existing list? */
         {
            targetElement = self->firstElement;
         }
         else
         {
            targetElement = self->lastElement->next;
         }
      }

      /* Check if a list element is allocated */
      if ( targetElement != NULL )
      {
         /* Push the element onto the list */
         targetElement->element = sourceElement->element;
         self->lastElement      = targetElement;
         self->numberOfElements++;
      }

      /* Get the next source element to copy */
      sourceElement = sourceElement->next;
   }

/* 
   Empty over-capacity elements if necessary
   (to be used for list debugging purposes)
   (NOTE: In this case the targetElement must be initialized to NULL when declared)
   if (self->currentCapacity > self->numberOfElements)
   {
      / Check if there is a valid targetElement
      if ( targetElement != NULL )
      {
         for (index = self->numberOfElements; index < self->currentCapacity; index++)
         {
            targetElement          = targetElement->next;
            targetElement->element = NULL;
         }
      }
   }
 */
}

/* ---------------------------------------------------------------------------
 * Function for copying a sourceChain instance into the "self" TinyList instance.
 *
 * INPUT                DESCRIPTION
 * TinyList*            Pointer to the target TinyList instance.
 * TinyChain*           Pointer to the source TinyChain instance.
 *
 * OUTPUT               DESCRIPTION
 *                      The sourceChain is added to the "self" targetList.
 * ---------------------------------------------------------------------------
 */
void copyFromChain( struct TinyList* self, const struct TinyChain* sourceChain )
{
   /* Local variable declarations */
   void* element;
   unsigned long index;
   struct TinyChainIterator iterator;
   struct TinyListElement* targetElement = NULL;

   /* Prepare iteration of the sourceChain */
   prepareChainIteration(sourceChain, &iterator);

   /* Copy the sourceChain instance into into the "self" targetList instance */
   for (index = 0; index < chainSize(sourceChain); index++)
   {
      /* Get the source element to copy */
      element = getNextChainIterationElement(&iterator);

      /* Check if the target list is full (filled up to its capacity) */
      if ( self->numberOfElements == self->currentCapacity )
      {
         /* Try to seize a TinyListElement instance in the pool */
         targetElement = (struct TinyListElement*) seizePoolElement( &gs_TinyListElementPool );

         /* Check if seizing a free pool element failed */
         if ( targetElement == NULL )
         {
            /* Trace output: Pool is exhausted */
            infoTrace_PoolIsExhausted( "TinyListElement", gs_TinyListElementPool.highWaterMark, "copyFromChain" );

            /* Allocate the TinyListElement instance on the heap */
            targetElement = (struct TinyListElement*) malloc( sizeof(struct TinyListElement) );

            /* Check if memory allocation was successful */
            if ( targetElement != NULL )
            {
               /* Indicate TinyListElement instance heap allocation */
               targetElement->poolElement.next     = NULL;
               targetElement->poolElement.previous = NULL;
            }
            else
            {
               /* Trace output: Pool is exhausted, malloc failed */
               infoTrace_HeapAllocationFailed();
            }
         }

         /* Check if a list element is allocated */
         if ( targetElement != NULL )
         {
            /* Check if this is the very first element */
            if (self->currentCapacity == 0)
            {
               targetElement->next = targetElement;
               self->firstElement  = targetElement;
            }
            else
            {
               /* Add the targetElement to the back of an already existing list */
               targetElement->next     = self->firstElement;
               self->lastElement->next = targetElement;
            }
            self->currentCapacity++;
         }
      }
      else
      {
         if (self->numberOfElements == 0)  /* First in existing list? */
         {
            targetElement = self->firstElement;
         }
         else
         {
            targetElement = self->lastElement->next;
         }
      }

      /* Check if a list element is allocated */
      if ( targetElement != NULL )
      {
         /* Push the element onto the list */
         targetElement->element = element;
         self->lastElement      = targetElement;
         self->numberOfElements++;
      }
   }

/* 
    Empty over-capacity elements if necessary
   (to be used for list debugging purposes)
   if (self->currentCapacity > self->numberOfElements)
   {
      / Check if there is a valid list element to start from
      if ( targetElement != NULL )
      {
         for (index = self->numberOfElements; index < self->currentCapacity; index++)
         {
            targetElement          = targetElement->next;
            targetElement->element = NULL;
         }
      }
   }
 */
}

/* ### End of file TinyList.c ### */
