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
 *  File Name .............. TinyQueue.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyQueue is designed to hold a queue (vector) of state machine events.
 * The TinyQueueElement holds the event as a singly-linked list element.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYQUEUE_H
#define TINYQUEUE_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "ArchitectureConfig.h"
#include "GlobalTypeDefs.h"
#include "GenericEvent.h"
#include "TinyTrace.h"
#include "TinyPool.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The TinyQueueElement Structure */
struct TinyQueueElement;
typedef struct TinyQueueElement TinyQueueElement;

struct TinyQueueElement
{
/* The TinyPoolElement member for TinyQueueElement pool elements
   (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

/* Pointer to the queued event. */
   const struct GenericEvent* queuedEvent;

/* Pointer to the event data for the queued event.
   (pointer to the incoming OSE/LPP signal, when applicable) */
   void* eventData;

/* Reference to the recipient instance for the event.
   (= IsAssignerEvent    for assigner events, no recipient instance)
   (= IsCreationEvent    for creation events, no recipient instance)
   (= IsCancelledEvent   for cancelled timer events, no recipient instance)
   (= IsEventDumpedToPMD for events dumped to PMD by the hook function) */
   const void* recipient;

/* Pointer to the next element in the queue. */
   struct TinyQueueElement* next;
};

/* The TinyQueue Structure */
struct TinyQueue;
typedef struct TinyQueue TinyQueue;

struct TinyQueue
{
/* Pointer to the first element in the queue. */
   struct TinyQueueElement* firstElement;

/* Pointer to the last element in the queue. */
   struct TinyQueueElement* lastElement;

/* Number of elements pushed into in the queue. */
   unsigned long numberOfPushedElements;

/* Number of elements popped from the queue. */
   unsigned long numberOfPoppedElements;

/* Current capacity of the queue. */
   unsigned long currentCapacity;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the TinyQueue.
   NOTE: This function must be invoked on startup of the system function. */
void initialize_TinyQueue( void );

/* Function for shutting down the TinyQueue. */
void shutdown_TinyQueue( void );

/* Label for direct access to the TinyQueueElement pool
   (for seizing pre-allocated TinyQueueElement instances) */
extern struct TinyPool s_TinyQueueElementPool;

/* TinyQueueElement pool access semaphore for the TimerEvent dispatcher
   (this is for preventing TimerEvent deliveries during pool access) */
extern fastBool tinyQueueElementPoolIsAccessed;

/* Function for adding an event behind the last event in the queue. */
__inlined__ void pushBackQueue( struct TinyQueue* self,
                                const struct GenericEvent* pushedEvent,
                                void* eventData,
                                const void* recipient );

/* Function for retrieving and removing the first "element" in the queue. */
__inlined__ void popFrontQueue( struct TinyQueue* self,
                                const struct GenericEvent** poppedEvent,
                                void** eventData,
                                const void** recipient );

/* Function for retrieving the current capacity of the queue. */
__inlined__ unsigned long currentQueueCapacity( const struct TinyQueue* self );

/* ---------------------------------------------------------------------------
 * Function for adding an event behind the last event in the queue.
 *
 * INPUT                DESCRIPTION
 * TinyQueue*           Pointer to the target TinyQueue instance.
 * GenericEvent*        Pointer to the event to push onto the queue.
 * void*                Pointer to the event data for the event.
 * void*                Pointer to the recipient of the event.
 * ---------------------------------------------------------------------------
 */
__inlined__ void pushBackQueue( struct TinyQueue* self,
                                const struct GenericEvent* pushedEvent,
                                void* eventData,
                                const void* recipient )
{
   struct TinyQueueElement* newElement;
   unsigned long numberOfElementsInQueue;

   /* Get the number of elements in the target queue */
   numberOfElementsInQueue = self->numberOfPushedElements - self->numberOfPoppedElements;

   /* Check if the target queue is full (filled up to its capacity)
      (use >= operator in case of 'pushed' counter wrap-around) */
   if ( numberOfElementsInQueue >= self->currentCapacity )
   {
      /* Indicate for the TimerEvent dispatcher that the
         TinyQueueElement pool is being accessed */
      tinyQueueElementPoolIsAccessed = true;

      /* Try to seize a TinyQueueElement instance in the pool */
      newElement = (struct TinyQueueElement*) seizePoolElement( &s_TinyQueueElementPool );

      /* Indicate for the TimerEvent dispatcher that the
         TinyQueueElement pool no longer is accessed */
      tinyQueueElementPoolIsAccessed = false;

      /* Check if seizing a free pool element failed */
      if ( newElement == NULL )
      {
         /* Trace output: Pool is exhausted */
         infoTrace_PoolIsExhausted( "TinyQueueElement", s_TinyQueueElementPool.highWaterMark, "pushBackQueue" );

         /* Allocate the TinyQueueElement instance on the heap */
         newElement = (struct TinyQueueElement*) malloc( sizeof(struct TinyQueueElement) );

         /* Check if memory allocation was successful */
         if ( newElement != NULL )
         {
            /* Indicate TinyQueueElement instance heap allocation */
            newElement->poolElement.next     = NULL;
            newElement->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if a queue element is allocated */
      if ( newElement != NULL )
      {

         /* Check if this is the very first element */
         if ( self->currentCapacity == 0 )
         {
            newElement->next   = newElement;
            self->firstElement = newElement;
         }
         else
         {
            /* Add the newElement to the back of an already existing queue */
            newElement->next        = self->lastElement->next;
            self->lastElement->next = newElement;
         }
         self->currentCapacity++;

      }

   }
   else
   {
      /* Next free element in an already existing queue */
      newElement = self->lastElement->next;
   }

   /* Check if a queue element is allocated */
   if ( newElement != NULL )
   {
      /* Push the element onto the queue */
      newElement->queuedEvent = pushedEvent;
      newElement->eventData   = eventData;
      newElement->recipient   = recipient;
      self->lastElement       = newElement;
      self->numberOfPushedElements++;
   }
}

/* ---------------------------------------------------------------------------
 * Function for retrieving and removing the first "element" in the queue.
 *
 * INPUT                DESCRIPTION
 * TinyQueue*           Pointer to the source TinyQueue instance.
 *
 * OUTPUT               DESCRIPTION
 * GenericEvent**       Pointer to pointer to the event popped from the queue.
 *                      If the queue is empty, NULL is output
 *                      On skipped retrieval, EventRetrievalSkipped is output
 * void**               Pointer to pointer to the event data for the event.
 * void**               Pointer to pointer to the recipient of the event.
 * ---------------------------------------------------------------------------
 */
__inlined__ void popFrontQueue( struct TinyQueue* self,
                                const struct GenericEvent** poppedEvent,
                                void** eventData,
                                const void** recipient )
{
   /* Check if events are available for processing */
   if (self->numberOfPoppedElements != self->numberOfPushedElements)
   {
      /* Retrieve the element from the queue */
      struct TinyQueueElement* popElement = self->firstElement;

      /* Check if an element really has been retrieved */
      if (popElement->queuedEvent != NULL)
      {
         /* Output the popped event */
         (*poppedEvent) = popElement->queuedEvent;
         (*eventData)   = popElement->eventData;
         (*recipient)   = popElement->recipient;

         popElement->queuedEvent = NULL; /* This will prevent future, potential failure
                                            related to half-updated "pushed" counter
                                            (the counter update may get pre-empted) */
         self->firstElement = popElement->next;
         self->numberOfPoppedElements++;
      }
      else
      {
         /* Indicate that the event retrieval is skipped  */
         (*poppedEvent) = EventRetrievalSkipped;
      }
   }
   else
   {
      /* The queue is empty */
      (*poppedEvent) = NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for retrieving the current capacity of the queue.
 *
 * INPUT                DESCRIPTION
 * TinyQueue*           Pointer to the source TinyQueue instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The current capacity of the queue.
 * ---------------------------------------------------------------------------
 */
__inlined__ unsigned long currentQueueCapacity( const struct TinyQueue* self )
{
   return self->currentCapacity;
}

#ifdef __cplusplus
}
#endif

#endif /* TINYQUEUE_H */
