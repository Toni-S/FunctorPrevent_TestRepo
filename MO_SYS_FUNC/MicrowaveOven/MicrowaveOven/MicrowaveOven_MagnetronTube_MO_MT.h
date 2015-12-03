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
 *  File Name .............. MicrowaveOven_MagnetronTube_MO_MT.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_MAGNETRONTUBE_MO_MT_H
#define MICROWAVEOVEN_MAGNETRONTUBE_MO_MT_H

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

/* Instance data structure for class 'Magnetron Tube' */
struct MicrowaveOven_MagnetronTube_MO_MT;
typedef struct MicrowaveOven_MagnetronTube_MO_MT MicrowaveOven_MagnetronTube_MO_MT;

struct MicrowaveOven_MagnetronTube_MO_MT
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_MT;

   /* Characterizing attributes for this class */
   /* attribute TubeID  ### OPTIMIZED OUT ### */
   long current_power_output_MO_MT;

   /* Relationship navigation extensions for this class */
   /* extension MO_O_DestNavPtr_R1_p  ### OPTIMIZED OUT ### */  /* For navigation ->MO_O[R1] */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_MT1:'increase_power' */
extern const struct GenericEvent MicrowaveOven_MO_MT1_IE_Const;

/* Constant for event MO_MT2:'decrease_power' */
extern const struct GenericEvent MicrowaveOven_MO_MT2_IE_Const;

/* Constant for event MO_MT3:'power_on' */
extern const struct GenericEvent MicrowaveOven_MO_MT3_IE_Const;

/* Constant for event MO_MT4:'power_off' */
extern const struct GenericEvent MicrowaveOven_MO_MT4_IE_Const;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Magnetron Tube'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_MT_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_MT_IS1_1_Output_Power_Stable_and_OFF = 1,
   MicrowaveOven_MO_MT_IS2_2_Reducing_Output_Power = 2,
   MicrowaveOven_MO_MT_IS3_3_Raising_Output_Power = 3,
   MicrowaveOven_MO_MT_IS4_4_Output_Power_Stable_and_ON = 4,
   MicrowaveOven_MO_MT_IS_NumberOfStates = 5
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_MT;

/* Label for direct access to the 'Magnetron Tube' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_MagnetronTube_MO_MT MicrowaveOven_ClassInstances_MO_MT[1];

/* Label for direct access to the 'Magnetron Tube' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_MT;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_MagnetronTube_MO_MT* MicrowaveOven_ClassInstances_MO_MT_start;
extern const struct MicrowaveOven_MagnetronTube_MO_MT* MicrowaveOven_ClassInstances_MO_MT_end;

/* Chain holding all existing instances of class 'Magnetron Tube' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_MT;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Magnetron Tube'. */
void MicrowaveOven__Initialize__MO_MT( void );

/* Function for shutting down class 'Magnetron Tube'. */
void MicrowaveOven__Shutdown__MO_MT( void );

/* Event Queue Info Function for class 'Magnetron Tube' */
unsigned long MicrowaveOven_EventQueueInfo_MO_MT( void );

/* General Event Taker Function for class 'Magnetron Tube' */
void MicrowaveOven_TakeEvent_MO_MT( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_MAGNETRONTUBE_MO_MT_H */
