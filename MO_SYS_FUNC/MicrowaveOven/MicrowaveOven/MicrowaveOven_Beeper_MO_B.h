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
 *  File Name .............. MicrowaveOven_Beeper_MO_B.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_BEEPER_MO_B_H
#define MICROWAVEOVEN_BEEPER_MO_B_H

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

/* Instance data structure for class 'Beeper' */
struct MicrowaveOven_Beeper_MO_B;
typedef struct MicrowaveOven_Beeper_MO_B MicrowaveOven_Beeper_MO_B;

struct MicrowaveOven_Beeper_MO_B
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_B;

   /* Characterizing attributes for this class */
   /* attribute BeeperID  ### OPTIMIZED OUT ### */
   struct TimerEvent* beeper_timer_MO_B;
   long beep_count_MO_B;
   /* attribute beeper_delay_over  ### OPTIMIZED OUT ### */

   /* Relationship navigation extensions for this class */
   struct MicrowaveOven_Oven_MO_O* MO_O_DestNavPtr_R3_p;  /* For navigation ->MO_O[R3] */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_B1:'start_beeping' */
extern const struct GenericEvent MicrowaveOven_MO_B1_IE_Const;

/* Constant for event MO_B2:'beep_delay_over' */
extern const struct GenericEvent MicrowaveOven_MO_B2_IE_Const;
/* (constant to use when self-directed signal) */
extern const struct GenericEvent MicrowaveOven_MO_B2_IE_Const_Self;

/* Constant for event MO_B3:'beeping_stopped' */
extern const struct GenericEvent MicrowaveOven_MO_B3_IE_Const;
/* (constant to use when self-directed signal) */
extern const struct GenericEvent MicrowaveOven_MO_B3_IE_Const_Self;

/* Constant for event MO_B4:'stop_beeping' */
extern const struct GenericEvent MicrowaveOven_MO_B4_IE_Const;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Beeper'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_B_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_B_IS1_1_Awaiting_Beeper_Request = 1,
   MicrowaveOven_MO_B_IS2_2_Beeping = 2,
   MicrowaveOven_MO_B_IS_NumberOfStates = 3
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_B;

/* Label for direct access to the 'Beeper' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_Beeper_MO_B MicrowaveOven_ClassInstances_MO_B[1];

/* Label for direct access to the 'Beeper' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_B;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_Beeper_MO_B* MicrowaveOven_ClassInstances_MO_B_start;
extern const struct MicrowaveOven_Beeper_MO_B* MicrowaveOven_ClassInstances_MO_B_end;

/* Chain holding all existing instances of class 'Beeper' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_B;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Beeper'. */
void MicrowaveOven__Initialize__MO_B( void );

/* Function for shutting down class 'Beeper'. */
void MicrowaveOven__Shutdown__MO_B( void );

/* Event Queue Info Function for class 'Beeper' */
unsigned long MicrowaveOven_EventQueueInfo_MO_B( void );

/* General Event Taker Function for class 'Beeper' */
void MicrowaveOven_TakeEvent_MO_B( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_BEEPER_MO_B_H */
