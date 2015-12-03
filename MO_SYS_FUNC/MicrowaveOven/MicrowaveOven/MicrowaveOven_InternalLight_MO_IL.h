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
 *  File Name .............. MicrowaveOven_InternalLight_MO_IL.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_INTERNALLIGHT_MO_IL_H
#define MICROWAVEOVEN_INTERNALLIGHT_MO_IL_H

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

/* Instance data structure for class 'Internal Light' */
struct MicrowaveOven_InternalLight_MO_IL;
typedef struct MicrowaveOven_InternalLight_MO_IL MicrowaveOven_InternalLight_MO_IL;

struct MicrowaveOven_InternalLight_MO_IL
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_IL;

   /* Characterizing attributes for this class */
   /* attribute LightID  ### OPTIMIZED OUT ### */

   /* Relationship navigation extensions for this class */
   /* extension MO_O_DestNavPtr_R2_p  ### OPTIMIZED OUT ### */  /* For navigation ->MO_O[R2] */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_IL1:'switch_on' */
extern const struct GenericEvent MicrowaveOven_MO_IL1_IE_Const;

/* Constant for event MO_IL2:'switch_off' */
extern const struct GenericEvent MicrowaveOven_MO_IL2_IE_Const;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Internal Light'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_IL_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_IL_IS1_1_Off = 1,
   MicrowaveOven_MO_IL_IS2_2_On = 2,
   MicrowaveOven_MO_IL_IS_NumberOfStates = 3
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_IL;

/* Label for direct access to the 'Internal Light' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_InternalLight_MO_IL MicrowaveOven_ClassInstances_MO_IL[1];

/* Label for direct access to the 'Internal Light' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_IL;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_InternalLight_MO_IL* MicrowaveOven_ClassInstances_MO_IL_start;
extern const struct MicrowaveOven_InternalLight_MO_IL* MicrowaveOven_ClassInstances_MO_IL_end;

/* Chain holding all existing instances of class 'Internal Light' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_IL;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Internal Light'. */
void MicrowaveOven__Initialize__MO_IL( void );

/* Function for shutting down class 'Internal Light'. */
void MicrowaveOven__Shutdown__MO_IL( void );

/* Event Queue Info Function for class 'Internal Light' */
unsigned long MicrowaveOven_EventQueueInfo_MO_IL( void );

/* General Event Taker Function for class 'Internal Light' */
void MicrowaveOven_TakeEvent_MO_IL( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_INTERNALLIGHT_MO_IL_H */
