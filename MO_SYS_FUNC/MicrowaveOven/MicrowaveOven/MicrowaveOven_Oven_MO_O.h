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
 *  File Name .............. MicrowaveOven_Oven_MO_O.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_OVEN_MO_O_H
#define MICROWAVEOVEN_OVEN_MO_O_H

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
#include "MicrowaveOven_Beeper_MO_B.h"
#include "MicrowaveOven_Door_MO_D.h"
#include "MicrowaveOven_InternalLight_MO_IL.h"
#include "MicrowaveOven_MagnetronTube_MO_MT.h"
#include "MicrowaveOven_Turntable_MO_TRN.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* Instance data structure for class 'Oven' */
struct MicrowaveOven_Oven_MO_O;
typedef struct MicrowaveOven_Oven_MO_O MicrowaveOven_Oven_MO_O;

struct MicrowaveOven_Oven_MO_O
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_O;

   /* Characterizing attributes for this class */
   /* attribute OvenID  ### OPTIMIZED OUT ### */
   struct TimerEvent* oven_timer_MO_O;
   long remaining_cooking_time_MO_O;

   /* Referential attributes for this class */
   /* NOTE: ATTRIBUTES NOT GENERATED (READ ACCESS IS DISABLED THROUGH MARKING) */

   /* Relationship navigation extensions for this class */
   struct MicrowaveOven_MagnetronTube_MO_MT* MO_MT_DestNavPtr_R1_p;  /* For navigation ->MO_MT[R1] */
   struct MicrowaveOven_InternalLight_MO_IL* MO_IL_DestNavPtr_R2_p;  /* For navigation ->MO_IL[R2] */
   struct MicrowaveOven_Beeper_MO_B* MO_B_DestNavPtr_R3_p;  /* For navigation ->MO_B[R3] */
   struct MicrowaveOven_Door_MO_D* MO_D_DestNavPtr_R4_p;  /* For navigation ->MO_D[R4] */
   struct MicrowaveOven_Turntable_MO_TRN* MO_TRN_DestNavPtr_R5_p;  /* For navigation ->MO_TRN[R5] */
};

/* ---------------------------------------------------------------------------
 * Instance Event Data Structures
 * ---------------------------------------------------------------------------
 */
/* Event Data Structure for Instance Event MO_O8:'cooking_period' */
struct MicrowaveOven_MO_O8_IE_Data;
typedef struct MicrowaveOven_MO_O8_IE_Data MicrowaveOven_MO_O8_IE_Data;

struct MicrowaveOven_MO_O8_IE_Data
{
   _EDH_ _header_;
   long period;
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_O1:'initialise' */
extern const struct GenericEvent MicrowaveOven_MO_O1_IE_Const;

/* Constant for event MO_O3:'start_cooking' */
extern const struct GenericEvent MicrowaveOven_MO_O3_IE_Const;

/* Constant for event MO_O4:'cancel_cooking' */
extern const struct GenericEvent MicrowaveOven_MO_O4_IE_Const;

/* Constant for event MO_O2:'oven_initialised' */
extern const struct GenericEvent MicrowaveOven_MO_O2_IE_Const;

/* Constant for event MO_O5:'cooking_period_over' */
extern const struct GenericEvent MicrowaveOven_MO_O5_IE_Const;
/* (constant to use when self-directed signal) */
extern const struct GenericEvent MicrowaveOven_MO_O5_IE_Const_Self;

/* Constant for event MO_O6:'beeping_over' */
extern const struct GenericEvent MicrowaveOven_MO_O6_IE_Const;

/* Constant for event MO_O7:'oven_safe' */
extern const struct GenericEvent MicrowaveOven_MO_O7_IE_Const;
/* (constant to use when self-directed signal) */
extern const struct GenericEvent MicrowaveOven_MO_O7_IE_Const_Self;

/* Constant for event MO_O8:'cooking_period' */
extern const struct GenericEvent MicrowaveOven_MO_O8_IE_Const;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Oven'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_O_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_O_IS1_1_Awaiting_Cooking_Request = 1,
   MicrowaveOven_MO_O_IS2_2_Ensuring_Safe_to_Cook = 2,
   MicrowaveOven_MO_O_IS3_3_Cooking = 3,
   MicrowaveOven_MO_O_IS4_4_Cooking_Suspended = 4,
   MicrowaveOven_MO_O_IS5_5_Signalling_Cooking_Period_Over = 5,
   MicrowaveOven_MO_O_IS6_6_Assigning_Cooking_Period = 6,
   MicrowaveOven_MO_O_IS_NumberOfStates = 7
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_O;

/* Label for direct access to the 'Oven' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_Oven_MO_O MicrowaveOven_ClassInstances_MO_O[1];

/* Label for direct access to the 'Oven' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_O;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_Oven_MO_O* MicrowaveOven_ClassInstances_MO_O_start;
extern const struct MicrowaveOven_Oven_MO_O* MicrowaveOven_ClassInstances_MO_O_end;

/* Chain holding all existing instances of class 'Oven' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_O;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Oven'. */
void MicrowaveOven__Initialize__MO_O( void );

/* Function for shutting down class 'Oven'. */
void MicrowaveOven__Shutdown__MO_O( void );

/* Event Queue Info Function for class 'Oven' */
unsigned long MicrowaveOven_EventQueueInfo_MO_O( void );

/* General Event Taker Function for class 'Oven' */
void MicrowaveOven_TakeEvent_MO_O( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_OVEN_MO_O_H */
