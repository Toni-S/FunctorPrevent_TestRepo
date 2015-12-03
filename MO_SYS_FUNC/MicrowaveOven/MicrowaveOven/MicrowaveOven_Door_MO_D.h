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
 *  Executable UML Model "MicrowaveOven" using BridgePoint & TinyC.
 *
 *
 *  File Name .............. MicrowaveOven_Door_MO_D.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_DOOR_MO_D_H
#define MICROWAVEOVEN_DOOR_MO_D_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MicrowaveOven_TypeDefs.h"
#include "GenericEvent.h"
#include "TimerEvent.h"
#include "TinyList.h"
#include "TinyChain.h"
#include "TinyPool.h"
#include "MicrowaveOven_Oven_MO_O.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* Instance data structure for class 'Door' */
struct MicrowaveOven_Door_MO_D;
typedef struct MicrowaveOven_Door_MO_D MicrowaveOven_Door_MO_D;

struct MicrowaveOven_Door_MO_D
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_D;

   /* Characterizing attributes for this class */
   bool is_secure_MO_D;
   /* attribute DoorID  ### OPTIMIZED OUT ### */

   /* Relationship navigation extensions for this class */
   struct MicrowaveOven_Oven_MO_O* MO_O_DestNavPtr_R4_p;  /* For navigation ->MO_O[R4] */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_D1:'release' */
extern const struct GenericEvent MicrowaveOven_MO_D1_IE_Const;

/* Constant for event MO_D2:'close' */
extern const struct GenericEvent MicrowaveOven_MO_D2_IE_Const;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Door'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_D_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_D_IS1_1_Open = 1,
   MicrowaveOven_MO_D_IS2_2_Closed = 2,
   MicrowaveOven_MO_D_IS_NumberOfStates = 3
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_D;

/* Label for direct access to the 'Door' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_Door_MO_D MicrowaveOven_ClassInstances_MO_D[1];

/* Label for direct access to the 'Door' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_D;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_Door_MO_D* MicrowaveOven_ClassInstances_MO_D_start;
extern const struct MicrowaveOven_Door_MO_D* MicrowaveOven_ClassInstances_MO_D_end;

/* Chain holding all existing instances of class 'Door' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_D;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Door'. */
void MicrowaveOven__Initialize__MO_D( void );

/* Function for shutting down class 'Door'. */
void MicrowaveOven__Shutdown__MO_D( void );

/* Event Queue Info Function for class 'Door' */
unsigned long MicrowaveOven_EventQueueInfo_MO_D( void );

/* General Event Taker Function for class 'Door' */
void MicrowaveOven_TakeEvent_MO_D( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_DOOR_MO_D_H */
