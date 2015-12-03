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
 *  File Name .............. GenericEvent.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The GenericEvent is the top Structure for an Event instance.
 * ---------------------------------------------------------------------------
 */
#ifndef GENERICEVENT_H
#define GENERICEVENT_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "ArchitectureConfig.h"
#include "GlobalTypeDefs.h"
#include "TinyPool.h"
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The GenericEvent Structure */
struct GenericEvent;
typedef struct GenericEvent GenericEvent;

/* Event Taker function pointer type */
typedef void ( *EventTakerPtrType )( const struct GenericEvent* const event,
                                     void* eventData, const void* recipient );
/* Event data printer function pointer type */
typedef void ( *EventDataPrinterPtrType )( const void* eventData );

struct GenericEvent
{
/* The Event Code in bit 16-31 for identifying the event.
   The Event Type in bit  0-15 telling the type of event. */
   unsigned long eventCodeAndType;

/* Pointer to the event description text */
   const char** eventDescriptionText;

/* Pointer to the event data printout function */
   const EventDataPrinterPtrType* eventDataPrinter;

/* Default pointer to the recipient taker for the event.
   (used for sending pre-created events & incoming OSE/LPP signals) */
   EventTakerPtrType theEventTaker;

/* Pointer to the target eventQueue access semaphore.
   (also checked before delivery of Timer Events) */
   fastBool* queueIsAccessed;
};

/* Define assigner event indicator. */
#define IsAssignerEvent ((void*) -1)

/* Define creation event indicator. */
#define IsCreationEvent ((void*) -2)

/* Define cancelled timer event indicator. */
#define IsCancelledEvent ((void*) -3)

/* Define "is dumped to PMD" event indicator.
   (set by the PMD hook function when dumping queued events) */
#define IsEventDumpedToPMD ((void*) -4)

/* Define skipped event retrieval indicator. */
#define EventRetrievalSkipped ((struct GenericEvent *) -1)

/* Define direct event data access indicator for State Data Variable Array.
   (when state OAL access event data directly = not a common parameter set) */
#define DirectEventDataAccess ((void*) -1)

/* eventType enumerators: Defined for each event
   in the generated event constant declarations. */
enum
{
   TypeUndefined                     = 0x0000,

/* Indication that the event is directed to the own instance. */
   IsSelfDirected                    = 0x0001,  /* For setting a '1' into Bit 0 */

/* Indication that this is a polymorphic event. */
   IsPolymorphicEvent                = 0x0002,  /* For setting a '1' into Bit 1 */

/* Indication that this is a polymorphic event directed to the own instance. */
   IsPolymorphicSelfDirected         = 0x0003,  /* For setting a '1' into Bit 0 & Bit 1 */

/* Indication that this is a non-local event. (defined by a polymorphic event) */
   IsNonLocalEvent                   = 0x0004,  /* For setting a '1' into Bit 2 */

/* Indication that this is a non-local event directed to the own instance. */
   IsNonLocalSelfDirected            = 0x0005,  /* For setting a '1' into Bit 0 & Bit 2 */

/* For testing if the event is a polymorphic event or a non-local event.
   (used for bit masking by state machine on incoming events) */
   IsPolymorphicOrNonLocal           = 0x0006,  /* For masking Bit 1 & Bit 2 */

/* Indication that this is an event from an incoming OSE signal. */
   IsIncomingOSESignal               = 0x0010,  /* For setting a '1' into Bit 4 */

/* Indication that this is an event from an incoming LPP signal. */
   IsIncomingLPPSignal               = 0x0020   /* For setting a '1' into Bit 5 */
};

/* eventFlags enumerators: The main purpose of these flags is to keep
   track of when to _NOT_ deallocate memory for incoming event data.
   (for propagated polymorphic events and recurring timer events) */
enum
{
   FlagsUndefined                    = 0x0000,

/* Indication that the timer event is to be recurring.
   (this is indicated automatically by the timer itself) */
   IsRecurringEvent                  = 0x0001,  /* For setting a '1' into Bit 0 */
   IsRecurringEvent_clear            = 0x7FFE,  /* For clearing this bit */

/* Indication that this is a propagated event. (sent to subtype state machine)
   (this is indicated automatically by the sending state machine itself) */
   IsPropagatedEvent                 = 0x0010,  /* For setting a '1' into Bit 4 */
   IsPropagatedEvent_clear           = 0x7FEF,  /* For clearing this bit */

/* For testing if the event is a recurring timer event
   or a propagated event. (sent to subtype state machine)
   (used for bit masking by state machine on release of memory) */
   IsRecurringOrPropagated           = 0x0011   /* For masking Bit 0 & Bit 4 */
};

/* Instance state action function pointer types. */
typedef void ( *InstanceStateActionPtrType )( void* self, const void* eventData );
typedef void ( *SingletonStateActionPtrType )( const void* eventData );

/* Assigner state action function pointer type. */
typedef void ( *AssignerStateActionPtrType )( const void* eventData );

/* Instance transition action function pointer types. */
typedef unsigned int ( *InstanceTransActionPtrType )( void* self, const void* eventData );
typedef unsigned int ( *SingletonTransActionPtrType )( const void* eventData );

/* Class-based transition action function pointer type. */
typedef unsigned int ( *AssignerTransActionPtrType )( const void* eventData );

/* Definition of event memory reuse enumerators
   (for use in state machinery and action code) */
enum
{
   NoEventMemoryReuse = 0,  /* No event memory reuse yet   */
   EventDataIsReused  = 1,  /* Event data memory is reused */
   OSESignalIsReused  = 2,  /* OSE signal memory is reused */
   LPPSignalIsReused  = 3   /* LPP signal memory is reused */
};

/* Definition of event handling enumerators.
   (for use in the generated state event matrix) */
enum
{
   NoTransitionExecuted = 252,  /* No transition executed for event indications below */
   EventIsPropagated    = 253,  /* For propagation of polymorphic & non-local events  */
   EventIsIgnored       = 254,  /* Event analyzed as 'Ignored' in current state       */
   EventCantHappen      = 255   /* Event analyzed as 'Cant Happen' in current state   */
};

/* The _EventDataHeader_ Structure */
struct _EventDataHeader_;
typedef struct _EventDataHeader_ _EDH_;
struct _EventDataHeader_
{
/* The TinyPoolElement member for event data pool elements
   (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

/* The size in bytes of this pool element */
/* size_t sizeInBytes; */
   unsigned short sizeInBytes;

/* Flags indicating the handling of the event */
   unsigned short eventFlags;

/* Indication if time information is available. */
   fastBool timeInformationAvailable;

/* The time the event was sent/fired. */
   unsigned short hour;
   unsigned short minute;
   unsigned short second;
   unsigned short millisecond;

/* Pointer to a string stating the sender class name. */
   const char* senderClassName;

/* Reference to the sender instance for the event.
   (= NULL for assigners, no sender instance) */
   const void* senderInstance;
};

/* Event Data Structure to use for events with no data
   (used during run-time tracing of events with no data)
   (also a helper struct when accessing the eventFlags) */
struct _OnlyEventDataHeader_;
typedef struct _OnlyEventDataHeader_ _OEDH_;
struct _OnlyEventDataHeader_
{
   _EDH_ _header_;
};

/* The PolyEventMapping Structure */
struct PolyEventMapping;
typedef struct PolyEventMapping PolyEventMapping;
struct PolyEventMapping
{
/* Pointer to the constant for the polymorphic event */
   const struct GenericEvent* incomingPolyEvent;

/* Pointer to the constant for the non-local event */
   const struct GenericEvent* nonLocalEvent;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the GenericEvent.
   NOTE: This function must be invoked on startup of the system function. */
void initialize_GenericEvent( void );

/* Function for shutting down the GenericEvent. */
void shutdown_GenericEvent( void );

/* Function for allocating memory for an event data instance. */
void* seizeEventDataMemory( size_t instanceSize );

/* Function for returning memory for an event data instance. */
void returnEventDataMemory( void* returnedInstance );

#ifdef __cplusplus
}
#endif

#endif /* GENERICEVENT_H */
