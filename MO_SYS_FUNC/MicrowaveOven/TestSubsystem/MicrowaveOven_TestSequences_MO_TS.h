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
 *  File Name .............. MicrowaveOven_TestSequences_MO_TS.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * CLASS DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_TESTSEQUENCES_MO_TS_H
#define MICROWAVEOVEN_TESTSEQUENCES_MO_TS_H

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

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* Instance data structure for class 'Test Sequences' */
struct MicrowaveOven_TestSequences_MO_TS;
typedef struct MicrowaveOven_TestSequences_MO_TS MicrowaveOven_TestSequences_MO_TS;

struct MicrowaveOven_TestSequences_MO_TS
{
   /* The TinyPoolElement member for pool elements of this class
      (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

   /* The TinyChainElement member for the class instance chain
      (holding the doubly-linked list pointers for the chain) */
   struct TinyChainElement chainElement;

   /* The state variable for the instance-based state machine */
   unsigned char currentISMstate_MO_TS;

   /* Characterizing attributes for this class */
   /* attribute TestSeqID  ### OPTIMIZED OUT ### */
};

/* ---------------------------------------------------------------------------
 * Instance Event Constants
 * ---------------------------------------------------------------------------
 */
/* Constant for event MO_TS2:'perform_test_seq_1' */
extern const struct GenericEvent MicrowaveOven_MO_TS2_IE_Const;
/* (constant to use when self-directed signal) */
extern const struct GenericEvent MicrowaveOven_MO_TS2_IE_Const_Self;

/* Constant for event MO_TS3:'perform_test_seq_2' */
extern const struct GenericEvent MicrowaveOven_MO_TS3_IE_Const;

/* Constant for event MO_TS1:'initialize' */
extern const struct GenericEvent MicrowaveOven_MO_TS1_IE_Const;

/* Constant for event MO_TS4:'test_seq_complete' */
extern const struct GenericEvent MicrowaveOven_MO_TS4_IE_Const;
/* (constant to use when self-directed signal) */
extern const struct GenericEvent MicrowaveOven_MO_TS4_IE_Const_Self;

/* ---------------------------------------------------------------------------
 * Instance State Codes
 * ---------------------------------------------------------------------------
 */
/* Instance State (IS) Codes for class 'Test Sequences'
   (defined with no name to prevent declarations of this type) */
enum
{
   MicrowaveOven_MO_TS_IS_NonExisting = 0,  /* Additional state, entered when deleted */
   MicrowaveOven_MO_TS_IS1_1_Awaiting_Test_Sequence_Initiation = 1,
   MicrowaveOven_MO_TS_IS2_2_Performing_Test_Sequence_1 = 2,
   MicrowaveOven_MO_TS_IS3_3_Performing_Test_Sequence_2 = 3,
   MicrowaveOven_MO_TS_IS4_4_Cooking_Complete = 4,
   MicrowaveOven_MO_TS_IS_NumberOfStates = 5
};

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The modelled name of the current class
   (to use e.g for run-time tracing information) */
extern const char* MicrowaveOven_ClassName_MO_TS;

/* Label for direct access to the 'Test Sequences' class instance pool array
   (for quick lookup or direct access of class instance pool array e.g by legacy) */
extern struct MicrowaveOven_TestSequences_MO_TS MicrowaveOven_ClassInstances_MO_TS[1];

/* Label for direct access to the 'Test Sequences' class instance pool
   (for seizing pre-allocated class instances or test during quick lookup) */
extern struct TinyPool MicrowaveOven_ClassInstancePool_MO_TS;

/* Labels for access to valid start & end addresses for pool instances */
extern const struct MicrowaveOven_TestSequences_MO_TS* MicrowaveOven_ClassInstances_MO_TS_start;
extern const struct MicrowaveOven_TestSequences_MO_TS* MicrowaveOven_ClassInstances_MO_TS_end;

/* Chain holding all existing instances of class 'Test Sequences' */
extern struct TinyChain MicrowaveOven_InstanceChain_MO_TS;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Function for initializing class 'Test Sequences'. */
void MicrowaveOven__Initialize__MO_TS( void );

/* Function for shutting down class 'Test Sequences'. */
void MicrowaveOven__Shutdown__MO_TS( void );

/* Event Queue Info Function for class 'Test Sequences' */
unsigned long MicrowaveOven_EventQueueInfo_MO_TS( void );

/* General Event Taker Function for class 'Test Sequences' */
void MicrowaveOven_TakeEvent_MO_TS( const struct GenericEvent* const incomingEvent, void* eventData, const void* recipient );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_TESTSEQUENCES_MO_TS_H */
