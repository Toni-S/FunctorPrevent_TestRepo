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
 *  File Name .............. MicrowaveOven_Turntable_MO_TRN.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_TURNTABLE_MO_TRN_H
#define MICROWAVEOVEN_TURNTABLE_MO_TRN_H

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

/* Instance data structure for class 'Turntable' */
struct MicrowaveOven_Turntable_MO_TRN;
typedef struct MicrowaveOven_Turntable_MO_TRN MicrowaveOven_Turntable_MO_TRN;

struct MicrowaveOven_Turntable_MO_TRN
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_TRN;

   /* Characterizing attributes for this class */
   /* attribute TurntableID  ### OPTIMIZED OUT ### */

   /* Relationship navigation extensions for this class */
   /* extension MO_O_DestNavPtr_R5_p  ### OPTIMIZED OUT ### */  /* For navigation ->MO_O[R5] */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_TRN1:'spin' */
extern const struct GenericEvent MicrowaveOven_MO_TRN1_IE_Const;

/* Constant for event MO_TRN2:'stop' */
extern const struct GenericEvent MicrowaveOven_MO_TRN2_IE_Const;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Turntable'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_TRN_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_TRN_IS1_1_Stationary = 1,
   MicrowaveOven_MO_TRN_IS2_2_Rotating = 2,
   MicrowaveOven_MO_TRN_IS_NumberOfStates = 3
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_TRN;

/* Label for direct access to the 'Turntable' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_Turntable_MO_TRN MicrowaveOven_ClassInstances_MO_TRN[1];

/* Label for direct access to the 'Turntable' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_TRN;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_Turntable_MO_TRN* MicrowaveOven_ClassInstances_MO_TRN_start;
extern const struct MicrowaveOven_Turntable_MO_TRN* MicrowaveOven_ClassInstances_MO_TRN_end;

/* Chain holding all existing instances of class 'Turntable' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_TRN;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Turntable'. */
void MicrowaveOven__Initialize__MO_TRN( void );

/* Function for shutting down class 'Turntable'. */
void MicrowaveOven__Shutdown__MO_TRN( void );

/* Event Queue Info Function for class 'Turntable' */
unsigned long MicrowaveOven_EventQueueInfo_MO_TRN( void );

/* General Event Taker Function for class 'Turntable' */
void MicrowaveOven_TakeEvent_MO_TRN( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_TURNTABLE_MO_TRN_H */
