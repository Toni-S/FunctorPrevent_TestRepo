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
 *  File Name .............. TinySchedule.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinySchedule is designed to hold a vector of void* pointers.
 * The TinyScheduleElement holds the pointer as a doubly-linked list element.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYSCHEDULE_H
#define TINYSCHEDULE_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "GlobalTypeDefs.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* Event queue poller function pointer type. */
typedef void* ( *QueuePollerPtrType )( void );

/* The TinyScheduleElement Structure */
struct TinyScheduleElement;
typedef struct TinyScheduleElement TinyScheduleElement;

struct TinyScheduleElement
{
/* Registered event queue polling function. */
   QueuePollerPtrType theQueuePoller;

/* Indication if the active class is linked for scheduling or not. */
   fastBool isLinkedForScheduling;

/* Indication if the active class is permanently linked for scheduling. */
   fastBool isPermanentlyLinkedForScheduling;

/* Counter for number of times an empty event queue is accessed
   before unlinking this polling function from the schedule. */
   unsigned int emptyEventQueueAccessCounter;

/* Pointer to the next element in the schedule. */
   struct TinyScheduleElement* nextInSchedule;

/* Pointer to the previous element in the schedule. */
   struct TinyScheduleElement* previousInSchedule;

/* Pointer to the next element in request for scheduling. */
   struct TinyScheduleElement* nextRequestElement;

/* Pointer to the next free schedule element to seize. */
   struct TinyScheduleElement* nextElement;
};

/* The TinySchedule Structure */
struct TinySchedule;
typedef struct TinySchedule TinySchedule;

struct TinySchedule
{
/* Pointer to the next element to schedule by the dispatcher. */
   struct TinyScheduleElement* nextElementToSchedule;

/* Current number of linked elements being scheduled by the dispatcher. */
   unsigned long numberOfScheduledElements;

/* Pointer to the first element in request for scheduling. */
   struct TinyScheduleElement* firstRequestElement;

/* Pointer to the last element in request for scheduling. */
   struct TinyScheduleElement* lastRequestElement;

/* The number of elements in request for scheduling by the dispatcher. */
   unsigned long numberOfSchedulingRequests;

/* Pointer to the next free schedule element to seize (during start-up). */
   struct TinyScheduleElement* nextFreeElement;

/* Number of free element seizure failures (when no free element to seize). */
   unsigned long numberOfRegistrationFailures;

/* Number of free schedule elements. */
   unsigned long numberOfFreeElements;

/* The capacity of the schedule. */
   unsigned long theCapacity;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Scheduling request queue access indication for the TimerEvent Dispatcher
   (this semaphore prevents TimerEvent deliveries during scheduling requests) */
extern fastBool schedulingRequestQueueIsAccessed;

/* Function for registering an event queue polling function. */
struct TinyScheduleElement* registerQueuePoller( struct TinySchedule* self,
                                                 QueuePollerPtrType theQueuePoller,
                                                 fastBool isPermanentlyLinked );

/* Function for requesting a specific element for scheduling by the dispatcher. */
void requestScheduling( struct TinySchedule* self, struct TinyScheduleElement* requestElement );

/* Function for retrieving a pending scheduling request. */
struct TinyScheduleElement* getPendingSchedulingRequest( struct TinySchedule* self );

/* Function for linking a specific element into the dispatcher schedule. */
void linkScheduleElement( struct TinySchedule* self, struct TinyScheduleElement* linkElement );

/* Function for unlinking a specific element from the dispatcher schedule. */
void unlinkScheduleElement( struct TinySchedule* self, struct TinyScheduleElement* unlinkElement );

/* Function for reading the number of schedule element seizure failures
   when attempting to register an event queue poller function. */
unsigned long getNumberOfRegistrationFailures( const struct TinySchedule* self );

#ifdef __cplusplus
}
#endif

#endif /* TINYSCHEDULE_H */
