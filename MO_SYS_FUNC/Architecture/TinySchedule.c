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
 *  File Name .............. TinySchedule.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinySchedule.h"
#include "Win32_JThread.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* Scheduling request queue access indication for the TimerEvent Dispatcher
   (this semaphore prevents TimerEvent deliveries during scheduling requests) */
fastBool schedulingRequestQueueIsAccessed = false;

/* ---------------------------------------------------------------------------
 * Function for registering an event queue polling function.
 *
 * For active classes that are run by a system-level dispatcher,
 * the queue polling functions are expected to be registered one by one
 * during the start-up of the system function.
 *
 * INPUT                DESCRIPTION
 * TinySchedule*        Pointer to the source TinySchedule instance.
 * QueuePollerPtrType   The event queue polling function to register.
 * boolean              Indication if the active class is permanently
 *                      linked for scheduling.
 *
 * RETURNS              DESCRIPTION
 * TinyScheduleElement* Pointer to a seized (free) element in the schedule.
 *                      If no elements are available (free), NULL is returned.
 * ---------------------------------------------------------------------------
 */
struct TinyScheduleElement* registerQueuePoller( struct TinySchedule* self,
                                                 QueuePollerPtrType theQueuePoller,
                                                 fastBool isPermanentlyLinked )
{
   if ( self->numberOfFreeElements > 0 )
   {
      /* Get the next free schedule element */
      struct TinyScheduleElement* freeElement = self->nextFreeElement;

      /* Point out the next element as the new "next free schedule element" */
      self->nextFreeElement = freeElement->nextElement;

      /* Register the event queue polling function */
      freeElement->theQueuePoller = theQueuePoller;

      /* Indicate if this active class is permanently linked for scheduling */
      freeElement->isPermanentlyLinkedForScheduling = isPermanentlyLinked;

      /* Indicate that this active class is not yet linked for scheduling */
      freeElement->isLinkedForScheduling = false;

      /* Set up the empty event queue access counter */
      freeElement->emptyEventQueueAccessCounter = 10;

      /* Clear the scheduling pointers */
      freeElement->nextInSchedule     = NULL;
      freeElement->previousInSchedule = NULL;
      freeElement->nextRequestElement = NULL;

      /* The number of free schedule elements is reduced */
      self->numberOfFreeElements--;

      /* Return the seized schedule element */
      return freeElement;
   }
   else
   {
      /* Record this failure to seize a free schedule element */
      self->numberOfRegistrationFailures++;

      /* Indicate failure to seize a free schedule element by returning NULL */
      return NULL;
   }
}

/* ---------------------------------------------------------------------------
 * Function for requesting a specific element for scheduling by the dispatcher.
 *
 * NOTE: The Dispatcher Schedule instance must be synchronized if this function
 *       is called as a result of receiving an event from a different thread.
 *
 * INPUT                DESCRIPTION
 * TinySchedule*        Pointer to the target TinySchedule instance.
 * TinyScheduleElement* Pointer to the TinyScheduleElement instance
 *                      in request for scheduling.
 * ---------------------------------------------------------------------------
 */
void requestScheduling( struct TinySchedule* self, struct TinyScheduleElement* requestElement )
{
   /* Set up the scheduling request queue access loop counter */
   unsigned int queueAccessLoopCounter = 2;

   /* Continue until the scheduling request queue access has been completed */
   do
   {

      /* Check that this scheduling request queue
         _not_ is being accessed by another thread */
      if ( !schedulingRequestQueueIsAccessed )
      {
         /* Indicate that the scheduling request queue is being accessed */
         schedulingRequestQueueIsAccessed = true;

         /* Check the number of active scheduling requests */
         if ( self->numberOfSchedulingRequests == 0 )
         {
            /* This is the first (only) element in request for scheduling */
            self->firstRequestElement          = requestElement;
            requestElement->nextRequestElement = requestElement;
         }
         else
         {
            /* This is the next element in request for scheduling */
            self->lastRequestElement->nextRequestElement = requestElement;
         }
         self->lastRequestElement = requestElement;

         /* The number of scheduling requests has increased */
         self->numberOfSchedulingRequests++;

         /* Indicate that the scheduling request queue no longer is accessed */
         schedulingRequestQueueIsAccessed = false;

         /* Scheduling request queue access completed - Break out */
         /* break; (replaced by return statement below) */

         /* Job done: Return immediately */
         return;
      }
      else
      {
         /* Decrement the scheduling request queue access loop counter */
         queueAccessLoopCounter--;

         /* The scheduling request queue is perhaps being accessed by another thread
            that executes at a lower priority level than the current thread
            (do not yield a higher prio thread more than once) */
         if ( queueAccessLoopCounter )
         {
            /* Give processing time to other threads on same prio level (yield) */
            yieldThread();
         }
         else
         {
            /* Suspend execution for a short period of time */
            sleepThread( 1 );

            /* Reset the scheduling request queue access loop counter */
            queueAccessLoopCounter = 2;
         }
      }

   } while (true);
}

/* ---------------------------------------------------------------------------
 * Function for retrieving a pending scheduling request.
 *
 * INPUT                DESCRIPTION
 * TinySchedule*        Pointer to the target TinySchedule instance.
 *
 * RETURNS              DESCRIPTION
 * TinyScheduleElement* Pointer to a pending element in request for scheduling.
 *                      NULL is returned if no requests are available.
 * ---------------------------------------------------------------------------
 */
struct TinyScheduleElement* getPendingSchedulingRequest( struct TinySchedule* self )
{
   /* Local variable declarations */
   struct TinyScheduleElement* pendingElement = NULL;

   /* Set up the scheduling request queue access loop counter */
   unsigned int queueAccessLoopCounter = 2;

   /* Continue until the scheduling request queue access has been completed */
   do
   {

      /* Check that this scheduling request queue
         _not_ is being accessed by another thread */
      if ( !schedulingRequestQueueIsAccessed )
      {
         /* Indicate that the scheduling request queue is being accessed */
         schedulingRequestQueueIsAccessed = true;

         /* Check the number of active scheduling requests */
         if (self->numberOfSchedulingRequests > 0)
         {
            /* Get the pending element in request for scheduling */
            pendingElement = self->firstRequestElement;

            /* Get the next pending element in request for scheduling */
            self->firstRequestElement = pendingElement->nextRequestElement;

            /* The number of scheduling requests has decreased */
            self->numberOfSchedulingRequests--;
         }

         /* Indicate that the scheduling request queue no longer is accessed */
         schedulingRequestQueueIsAccessed = false;

         /* Scheduling request queue access completed - Break out */
         break;
      }
      else
      {
         /* Decrement the scheduling request queue access loop counter */
         queueAccessLoopCounter--;

         /* The scheduling request queue is perhaps being accessed by another thread
            that executes at a lower priority level than the current thread
            (do not yield a higher prio thread more than once) */
         if ( queueAccessLoopCounter )
         {
            /* Give processing time to other threads on same prio level (yield) */
            yieldThread();
         }
         else
         {
            /* Suspend execution for a short period of time */
            sleepThread( 1 );

            /* Reset the scheduling request queue access loop counter */
            queueAccessLoopCounter = 2;
         }
      }

   } while (true);

   /* Return the pending element in request for scheduling */
   return pendingElement;
}

/* ---------------------------------------------------------------------------
 * Function for linking a specific element into the dispatcher schedule.
 *
 * INPUT                DESCRIPTION
 * TinySchedule*        Pointer to the target TinySchedule instance.
 * TinyScheduleElement* Pointer to the TinyScheduleElement instance
 *                      to link for scheduling.
 * ---------------------------------------------------------------------------
 */
void linkScheduleElement( struct TinySchedule* self, struct TinyScheduleElement* linkElement )
{
   if ( self->numberOfScheduledElements == 0 )
   {
      /* THIS IS THE FIRST (ONLY) ELEMENT IN THE DISPATCHER SCHEDULE */

      /* Link the linked in element to itself */
      linkElement->previousInSchedule = linkElement;
      linkElement->nextInSchedule     = linkElement;

      /* The next element to schedule is the element just linked in */
      self->nextElementToSchedule = linkElement;
   }
   else
   {
      /* Get the next element to schedule */
      struct TinyScheduleElement* nextElementToSchedule = self->nextElementToSchedule;

      /* Get the element preceding the next element to schedule */
      struct TinyScheduleElement* nextElementToSchedule_previous = nextElementToSchedule->previousInSchedule;

      /* Check if the schedule contained only a single element prior to this one */
      if ( self->numberOfScheduledElements == 1 )
      {
         /* The new next element to schedule (on exit) is the element just linked in
            (prevents the same poller function to be called consecutively) */
         self->nextElementToSchedule = linkElement;
      }

      /* INSERT THE LINKED IN ELEMENT BEFORE THE NEXT ELEMENT TO SCHEDULE (ON ENTRY) */

      /* Link the element before the next element to schedule to the linked in element */
      nextElementToSchedule_previous->nextInSchedule = linkElement;
      linkElement->previousInSchedule = nextElementToSchedule_previous;

      /* Link the next element to schedule to the linked in element */
      nextElementToSchedule->previousInSchedule = linkElement;
      linkElement->nextInSchedule = nextElementToSchedule;
   }

   /* Indicate that this element now is linked for scheduling */
   linkElement->isLinkedForScheduling = true;

   /* Set up the empty event queue access counter */
   linkElement->emptyEventQueueAccessCounter = 10;

   /* The number of elements being scheduled has increased */
   self->numberOfScheduledElements++;
}

/* ---------------------------------------------------------------------------
 * Function for unlinking a specific element from the dispatcher schedule.
 *
 * INPUT                DESCRIPTION
 * TinySchedule*        Pointer to the target TinySchedule instance.
 * TinyScheduleElement* Pointer to the TinyScheduleElement instance
 *                      to unlink from scheduling.
 * ---------------------------------------------------------------------------
 */
void unlinkScheduleElement( struct TinySchedule* self, struct TinyScheduleElement* unlinkElement )
{
   /* Get the previous and next elements related to the element to unlink */
   struct TinyScheduleElement* unlinkElement_previous = unlinkElement->previousInSchedule;
   struct TinyScheduleElement* unlinkElement_next     = unlinkElement->nextInSchedule;

   /* Indicate that this element no longer is linked for scheduling */
   unlinkElement->isLinkedForScheduling = false;

   /* Release the element to unlink from the chain link */
   unlinkElement_previous->nextInSchedule = unlinkElement_next;
   unlinkElement_next->previousInSchedule = unlinkElement_previous;

   /* Check if the element next for scheduling is the unlinked element */
   if ( self->nextElementToSchedule == unlinkElement )
   {
      /* The next element to schedule is the element after the unlinked element */
      self->nextElementToSchedule = unlinkElement_next;
   }

   /* The number of elements being scheduled has decreased */
   self->numberOfScheduledElements--;
}

/* ---------------------------------------------------------------------------
 * Function for reading the number of schedule element seizure failures
 * when attempting to register an event queue poller function.
 *
 * INPUT                DESCRIPTION
 * TinySchedule*        Pointer to the source TinySchedule instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        Number of schedule element seizure failures.
 * ---------------------------------------------------------------------------
 */
unsigned long getNumberOfRegistrationFailures( const struct TinySchedule* self )
{
   return self->numberOfRegistrationFailures;
}

/* ### End of file TinySchedule.c ### */
