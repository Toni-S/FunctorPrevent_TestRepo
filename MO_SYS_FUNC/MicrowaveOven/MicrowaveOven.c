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
 *  File Name .............. MicrowaveOven.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MicrowaveOven.h"
#include "MicrowaveOven_Beeper_MO_B.h"
#include "MicrowaveOven_Door_MO_D.h"
#include "MicrowaveOven_InternalLight_MO_IL.h"
#include "MicrowaveOven_MagnetronTube_MO_MT.h"
#include "MicrowaveOven_Oven_MO_O.h"
#include "MicrowaveOven_Turntable_MO_TRN.h"
#include "MicrowaveOven_TestSequences_MO_TS.h"
#include "ArchitectureConfig.h"
#include "Win32_JThread.h"
#include "Win32_Timer.h"
#include "Win32_Time.h"
#include "GenericEvent.h"
#include "TimerEvent.h"
#include "TinyChain.h"
#include "TinyVector.h"
#include "TinyQueue.h"
#include "TinyList.h"
#include <stdlib.h>          /* Definition of NULL, malloc and free */
#include <string.h>          /* Definition of memcpy */

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the MicrowaveOven domain */
static void MicrowaveOven_Initialize( void );

/* ---------------------------------------------------------------------------
 * Class based data for MicrowaveOven
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Function for starting up the entire MicrowaveOven domain
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_Startup( void )
{
   /* Check that system function MO_SYS_FUNC is started */
   if ( MO_SYS_FUNC_isStarted )
   {
      /* Invoke the domain-level initializer */
      MicrowaveOven_Initialize();

      /* Invoke the class initializers */
      MicrowaveOven__Initialize__MO_B();
      MicrowaveOven__Initialize__MO_D();
      MicrowaveOven__Initialize__MO_IL();
      MicrowaveOven__Initialize__MO_MT();
      MicrowaveOven__Initialize__MO_O();
      MicrowaveOven__Initialize__MO_TRN();
      MicrowaveOven__Initialize__MO_TS();
   }
   else
   {
      /* THE SYSTEM FUNCTION MUST BE STARTED BEFORE THE INDIVIDUAL DOMAINS
         (the MO_SYS_FUNC_Startup function must be called first) */

      /* Trace output: System function not started */
      errorTrace_SystemFunctionNotStarted( "MO_SYS_FUNC", "MicrowaveOven" );
   }
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the entire MicrowaveOven domain
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_Shutdown( void )
{
   /* Shutdown the classes */
   MicrowaveOven__Shutdown__MO_B();
   MicrowaveOven__Shutdown__MO_D();
   MicrowaveOven__Shutdown__MO_IL();
   MicrowaveOven__Shutdown__MO_MT();
   MicrowaveOven__Shutdown__MO_O();
   MicrowaveOven__Shutdown__MO_TRN();
   MicrowaveOven__Shutdown__MO_TS();

}

/* ---------------------------------------------------------------------------
 * Function for initializing the MicrowaveOven domain
 * ---------------------------------------------------------------------------
 */
static void MicrowaveOven_Initialize( void )
{
}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'StartCooking'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_StartCooking( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_Oven_MO_O* oven_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* SELECT ANY oven FROM INSTANCES OF CLASS Oven */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Oven */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_O );

      oven_p = (struct MicrowaveOven_Oven_MO_O*) instance;
   }

   /* GENERATE EVENT MO_O3:'start_cooking' TO oven */

   /* Get constant declaration for event MO_O3:'start_cooking' */
   evt_2 = &MicrowaveOven_MO_O3_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = oven_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_O( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'CancelCooking'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_CancelCooking( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_Oven_MO_O* oven_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* SELECT ANY oven FROM INSTANCES OF CLASS Oven */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Oven */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_O );

      oven_p = (struct MicrowaveOven_Oven_MO_O*) instance;
   }

   /* GENERATE EVENT MO_O4:'cancel_cooking' TO oven */

   /* Get constant declaration for event MO_O4:'cancel_cooking' */
   evt_2 = &MicrowaveOven_MO_O4_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = oven_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_O( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'SpecifyCookingPeriod'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_SpecifyCookingPeriod( long par_cookingPeriod )
{
   /* Local variable declarations */
   long timePeriod;
   struct MicrowaveOven_Oven_MO_O* oven_p;
   const struct GenericEvent* evt_2;
   MicrowaveOven_MO_O8_IE_Data* evt_2_data;
   const void* evt_2_recipient;

   /* ASSIGN VARIABLE timePeriod = 1000000 * param.cookingPeriod */
   timePeriod = 1000000 * par_cookingPeriod;

   /* SELECT ANY oven FROM INSTANCES OF CLASS Oven */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Oven */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_O );

      oven_p = (struct MicrowaveOven_Oven_MO_O*) instance;
   }

   /* GENERATE EVENT MO_O8:'cooking_period' TO oven */

   /* Get constant declaration for event MO_O8:'cooking_period' */
   evt_2 = &MicrowaveOven_MO_O8_IE_Const;

   /* Allocate memory for the event data instance */
   evt_2_data = (MicrowaveOven_MO_O8_IE_Data*) seizeEventDataMemory( sizeof(MicrowaveOven_MO_O8_IE_Data) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = oven_p;
   /* ### DEFINE THE EVENT DATA ### */
   evt_2_data->period = timePeriod;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_O( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'IncreasePower'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_IncreasePower( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* SELECT ANY tube FROM INSTANCES OF CLASS Magnetron Tube */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Magnetron Tube */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_MT );

      tube_p = (struct MicrowaveOven_MagnetronTube_MO_MT*) instance;
   }

   /* GENERATE EVENT MO_MT1:'increase_power' TO tube */

   /* Get constant declaration for event MO_MT1:'increase_power' */
   evt_2 = &MicrowaveOven_MO_MT1_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = tube_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_MT( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'DecreasePower'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_DecreasePower( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* SELECT ANY tube FROM INSTANCES OF CLASS Magnetron Tube */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Magnetron Tube */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_MT );

      tube_p = (struct MicrowaveOven_MagnetronTube_MO_MT*) instance;
   }

   /* GENERATE EVENT MO_MT2:'decrease_power' TO tube */

   /* Get constant declaration for event MO_MT2:'decrease_power' */
   evt_2 = &MicrowaveOven_MO_MT2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = tube_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_MT( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'OpenDoor'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_OpenDoor( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_Door_MO_D* door_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* GENERATE EVENT MO_D1:'release' TO door */

   /* Get constant declaration for event MO_D1:'release' */
   evt_2 = &MicrowaveOven_MO_D1_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = door_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_D( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'CloseDoor'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_CloseDoor( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_Door_MO_D* door_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* SELECT ANY door FROM INSTANCES OF CLASS Door */
   {
      void* instance;

      /* Select the 'ANY' from instances of class Door */
      instance = getAnyChainElement( &MicrowaveOven_InstanceChain_MO_D );

      door_p = (struct MicrowaveOven_Door_MO_D*) instance;
   }

   /* GENERATE EVENT MO_D2:'close' TO door */

   /* Get constant declaration for event MO_D2:'close' */
   evt_2 = &MicrowaveOven_MO_D2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = door_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_D( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'TestSequence1'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_TestSequence1( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_TestSequences_MO_TS* testSequence_p;
   const struct GenericEvent* evt_2;
   void* evt_2_data;
   const void* evt_2_recipient;

   /* CREATE INSTANCE testSequence OF CLASS Test Sequences (MO_TS) */
   {
      /* Try to seize a Test Sequences instance in the pool */
      struct MicrowaveOven_TestSequences_MO_TS* newInstance = (struct MicrowaveOven_TestSequences_MO_TS*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_TS );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_TS, MicrowaveOven_ClassInstancePool_MO_TS.highWaterMark );

         /* Allocate the Test Sequences instance on the heap */
         newInstance = (struct MicrowaveOven_TestSequences_MO_TS*) malloc( sizeof(struct MicrowaveOven_TestSequences_MO_TS) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Test Sequences instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute TestSeqID  ### OPTIMIZED OUT ### */

         /* Set the Test Sequences instance start state */
         newInstance->currentISMstate_MO_TS = MicrowaveOven_MO_TS_IS1_1_Awaiting_Test_Sequence_Initiation;

         /* Register the created instance in the Test Sequences instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_TS, &newInstance->chainElement );
      }

      /* Assign the created instance of class Test Sequences */
      testSequence_p = newInstance;
   }

   /* GENERATE EVENT MO_TS2:'perform_test_seq_1' TO testSequence */

   /* Get constant declaration for event MO_TS2:'perform_test_seq_1' */
   evt_2 = &MicrowaveOven_MO_TS2_IE_Const;
   /* Allocate event data memory for event tracing purposes only */
   evt_2_data = seizeEventDataMemory( sizeof(struct _OnlyEventDataHeader_) );
   /* Clear the event handling flags */
   ((_OEDH_*) evt_2_data)->_header_.eventFlags = FlagsUndefined;
   ((_OEDH_*) evt_2_data)->_header_.timeInformationAvailable = false;
   ((_OEDH_*) evt_2_data)->_header_.senderClassName = currentThread_ExecutingClassName();
   ((_OEDH_*) evt_2_data)->_header_.senderInstance = currentThread_ExecutingInstance();
   evt_2_recipient = testSequence_p;

   /* Deliver the event to the target state machine */
   MicrowaveOven_TakeEvent_MO_TS( evt_2, evt_2_data, evt_2_recipient );

}

/* ---------------------------------------------------------------------------
 * Action code for Domain Function 'DefineOven'
 *
 * DOMAIN FUNCTION DESCRIPTION FROM MODEL:
 * (description not generated/available)
 * ---------------------------------------------------------------------------
 */
void MicrowaveOven_DefineOven( void )
{
   /* Local variable declarations */
   struct MicrowaveOven_Oven_MO_O* mo_p;
   struct MicrowaveOven_MagnetronTube_MO_MT* tube_p;
   struct MicrowaveOven_InternalLight_MO_IL* light_p;
   struct MicrowaveOven_Beeper_MO_B* beeper_p;
   struct MicrowaveOven_Door_MO_D* door_p;
   struct MicrowaveOven_Turntable_MO_TRN* turntable_p;

   /* CREATE INSTANCE mo OF CLASS Oven (MO_O) */
   {
      /* Try to seize a Oven instance in the pool */
      struct MicrowaveOven_Oven_MO_O* newInstance = (struct MicrowaveOven_Oven_MO_O*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_O );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_O, MicrowaveOven_ClassInstancePool_MO_O.highWaterMark );

         /* Allocate the Oven instance on the heap */
         newInstance = (struct MicrowaveOven_Oven_MO_O*) malloc( sizeof(struct MicrowaveOven_Oven_MO_O) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Oven instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute OvenID  ### OPTIMIZED OUT ### */
         newInstance->oven_timer_MO_O = NULL;
         newInstance->remaining_cooking_time_MO_O = 0;

         /* Set the Oven instance start state */
         newInstance->currentISMstate_MO_O = MicrowaveOven_MO_O_IS1_1_Awaiting_Cooking_Request;

         /* Initialize referential attribute data in the created instance */
         /* attribute TubeID  ### OPTIMIZED OUT ### */
         /* attribute LightID  ### OPTIMIZED OUT ### */
         /* attribute BeeperID  ### OPTIMIZED OUT ### */
         /* attribute DoorID  ### OPTIMIZED OUT ### */
         /* attribute TurntableID  ### OPTIMIZED OUT ### */

         /* Initialize the relationship navigation extensions */
         newInstance->MO_MT_DestNavPtr_R1_p = NULL;
         newInstance->MO_IL_DestNavPtr_R2_p = NULL;
         newInstance->MO_B_DestNavPtr_R3_p = NULL;
         newInstance->MO_D_DestNavPtr_R4_p = NULL;
         newInstance->MO_TRN_DestNavPtr_R5_p = NULL;

         /* Register the created instance in the Oven instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_O, &newInstance->chainElement );
      }

      /* Assign the created instance of class Oven */
      mo_p = newInstance;
   }

   /* ASSIGN ATTRIBUTE mo.remaining_cooking_time = 0 */
   mo_p->remaining_cooking_time_MO_O = 0;

   /* CREATE INSTANCE tube OF CLASS Magnetron Tube (MO_MT) */
   {
      /* Try to seize a Magnetron Tube instance in the pool */
      struct MicrowaveOven_MagnetronTube_MO_MT* newInstance = (struct MicrowaveOven_MagnetronTube_MO_MT*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_MT );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_MT, MicrowaveOven_ClassInstancePool_MO_MT.highWaterMark );

         /* Allocate the Magnetron Tube instance on the heap */
         newInstance = (struct MicrowaveOven_MagnetronTube_MO_MT*) malloc( sizeof(struct MicrowaveOven_MagnetronTube_MO_MT) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Magnetron Tube instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute TubeID  ### OPTIMIZED OUT ### */
         newInstance->current_power_output_MO_MT = MicrowaveOven_tube_wattage_high;

         /* Set the Magnetron Tube instance start state */
         newInstance->currentISMstate_MO_MT = MicrowaveOven_MO_MT_IS1_1_Output_Power_Stable_and_OFF;

         /* Initialize the relationship navigation extensions */
         /* extension MO_O_DestNavPtr_R1_p  ### OPTIMIZED OUT ### */

         /* Register the created instance in the Magnetron Tube instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_MT, &newInstance->chainElement );
      }

      /* Assign the created instance of class Magnetron Tube */
      tube_p = newInstance;
   }

   /* RELATE mo TO tube ACROSS R1 */
   {
      /* First check if the two instances have valid references */
      if ((mo_p != NULL) && (tube_p != NULL))
      {
         /* CHECK THAT THE INSTANCES ARE UNLINKED BEFORE LINKING THEM */

         /* Check that the Oven instance not already is linked across R1 */
         if ( mo_p->MO_MT_DestNavPtr_R1_p )
         {
            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_O, "R1" );
         }
         /* Assign the referential attributes that formalize relationship R1 */
         /* attribute TubeID  ### OPTIMIZED OUT ### */

         /* LINK THE TWO INSTANCES ACROSS RELATIONSHIP R1 */
         mo_p->MO_MT_DestNavPtr_R1_p = tube_p;
      }
      else
      {
         /* An attempt to link instances with NULL pointer (analysis error) */

         /* Trace output: Linking instances when pointer == NULL */
         errorTrace_LinkingWhenInstancePointerIsNULL( "R1" );
      }
   }

   /* ASSIGN ATTRIBUTE tube.current_power_output = tube_wattage::high */
   tube_p->current_power_output_MO_MT = MicrowaveOven_tube_wattage_high;

   /* CREATE INSTANCE light OF CLASS Internal Light (MO_IL) */
   {
      /* Try to seize a Internal Light instance in the pool */
      struct MicrowaveOven_InternalLight_MO_IL* newInstance = (struct MicrowaveOven_InternalLight_MO_IL*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_IL );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_IL, MicrowaveOven_ClassInstancePool_MO_IL.highWaterMark );

         /* Allocate the Internal Light instance on the heap */
         newInstance = (struct MicrowaveOven_InternalLight_MO_IL*) malloc( sizeof(struct MicrowaveOven_InternalLight_MO_IL) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Internal Light instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute LightID  ### OPTIMIZED OUT ### */

         /* Set the Internal Light instance start state */
         newInstance->currentISMstate_MO_IL = MicrowaveOven_MO_IL_IS1_1_Off;

         /* Initialize the relationship navigation extensions */
         /* extension MO_O_DestNavPtr_R2_p  ### OPTIMIZED OUT ### */

         /* Register the created instance in the Internal Light instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_IL, &newInstance->chainElement );
      }

      /* Assign the created instance of class Internal Light */
      light_p = newInstance;
   }

   /* RELATE mo TO light ACROSS R2 */
   {
      /* First check if the two instances have valid references */
      if ((mo_p != NULL) && (light_p != NULL))
      {
         /* CHECK THAT THE INSTANCES ARE UNLINKED BEFORE LINKING THEM */

         /* Check that the Oven instance not already is linked across R2 */
         if ( mo_p->MO_IL_DestNavPtr_R2_p )
         {
            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_O, "R2" );
         }
         /* Assign the referential attributes that formalize relationship R2 */
         /* attribute LightID  ### OPTIMIZED OUT ### */

         /* LINK THE TWO INSTANCES ACROSS RELATIONSHIP R2 */
         mo_p->MO_IL_DestNavPtr_R2_p = light_p;
      }
      else
      {
         /* An attempt to link instances with NULL pointer (analysis error) */

         /* Trace output: Linking instances when pointer == NULL */
         errorTrace_LinkingWhenInstancePointerIsNULL( "R2" );
      }
   }

   /* CREATE INSTANCE beeper OF CLASS Beeper (MO_B) */
   {
      /* Try to seize a Beeper instance in the pool */
      struct MicrowaveOven_Beeper_MO_B* newInstance = (struct MicrowaveOven_Beeper_MO_B*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_B );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_B, MicrowaveOven_ClassInstancePool_MO_B.highWaterMark );

         /* Allocate the Beeper instance on the heap */
         newInstance = (struct MicrowaveOven_Beeper_MO_B*) malloc( sizeof(struct MicrowaveOven_Beeper_MO_B) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Beeper instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute BeeperID  ### OPTIMIZED OUT ### */
         newInstance->beeper_timer_MO_B = NULL;
         newInstance->beep_count_MO_B = 0;
         /* attribute beeper_delay_over  ### OPTIMIZED OUT ### */

         /* Set the Beeper instance start state */
         newInstance->currentISMstate_MO_B = MicrowaveOven_MO_B_IS1_1_Awaiting_Beeper_Request;

         /* Initialize the relationship navigation extensions */
         newInstance->MO_O_DestNavPtr_R3_p = NULL;

         /* Register the created instance in the Beeper instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_B, &newInstance->chainElement );
      }

      /* Assign the created instance of class Beeper */
      beeper_p = newInstance;
   }

   /* RELATE mo TO beeper ACROSS R3 */
   {
      /* First check if the two instances have valid references */
      if ((mo_p != NULL) && (beeper_p != NULL))
      {
         /* CHECK THAT THE INSTANCES ARE UNLINKED BEFORE LINKING THEM */

         /* Check that the Oven instance not already is linked across R3 */
         if ( mo_p->MO_B_DestNavPtr_R3_p )
         {
            /* Auto-unlink the Oven instance from its
               opposite Beeper instance across R3 */
            mo_p->MO_B_DestNavPtr_R3_p->MO_O_DestNavPtr_R3_p = NULL;

            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_O, "R3" );
         }
         /* Check that the Beeper instance not already is linked across R3 */
         if ( beeper_p->MO_O_DestNavPtr_R3_p )
         {
            /* Auto-unlink the Beeper instance from its
               opposite Oven instance across R3 */
            beeper_p->MO_O_DestNavPtr_R3_p->MO_B_DestNavPtr_R3_p = NULL;

            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_B, "R3" );
         }
         /* Assign the referential attributes that formalize relationship R3 */
         /* attribute BeeperID  ### OPTIMIZED OUT ### */

         /* LINK THE TWO INSTANCES ACROSS RELATIONSHIP R3 */
         mo_p->MO_B_DestNavPtr_R3_p = beeper_p;
         beeper_p->MO_O_DestNavPtr_R3_p = mo_p;
      }
      else
      {
         /* An attempt to link instances with NULL pointer (analysis error) */

         /* Trace output: Linking instances when pointer == NULL */
         errorTrace_LinkingWhenInstancePointerIsNULL( "R3" );
      }
   }

   /* CREATE INSTANCE door OF CLASS Door (MO_D) */
   {
      /* Try to seize a Door instance in the pool */
      struct MicrowaveOven_Door_MO_D* newInstance = (struct MicrowaveOven_Door_MO_D*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_D );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_D, MicrowaveOven_ClassInstancePool_MO_D.highWaterMark );

         /* Allocate the Door instance on the heap */
         newInstance = (struct MicrowaveOven_Door_MO_D*) malloc( sizeof(struct MicrowaveOven_Door_MO_D) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Door instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute DoorID  ### OPTIMIZED OUT ### */
         newInstance->is_secure_MO_D = false;

         /* Set the Door instance start state */
         newInstance->currentISMstate_MO_D = MicrowaveOven_MO_D_IS1_1_Open;

         /* Initialize the relationship navigation extensions */
         newInstance->MO_O_DestNavPtr_R4_p = NULL;

         /* Register the created instance in the Door instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_D, &newInstance->chainElement );
      }

      /* Assign the created instance of class Door */
      door_p = newInstance;
   }

   /* RELATE mo TO door ACROSS R4 */
   {
      /* First check if the two instances have valid references */
      if ((mo_p != NULL) && (door_p != NULL))
      {
         /* CHECK THAT THE INSTANCES ARE UNLINKED BEFORE LINKING THEM */

         /* Check that the Oven instance not already is linked across R4 */
         if ( mo_p->MO_D_DestNavPtr_R4_p )
         {
            /* Auto-unlink the Oven instance from its
               opposite Door instance across R4 */
            mo_p->MO_D_DestNavPtr_R4_p->MO_O_DestNavPtr_R4_p = NULL;

            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_O, "R4" );
         }
         /* Check that the Door instance not already is linked across R4 */
         if ( door_p->MO_O_DestNavPtr_R4_p )
         {
            /* Auto-unlink the Door instance from its
               opposite Oven instance across R4 */
            door_p->MO_O_DestNavPtr_R4_p->MO_D_DestNavPtr_R4_p = NULL;

            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_D, "R4" );
         }
         /* Assign the referential attributes that formalize relationship R4 */
         /* attribute DoorID  ### OPTIMIZED OUT ### */

         /* LINK THE TWO INSTANCES ACROSS RELATIONSHIP R4 */
         mo_p->MO_D_DestNavPtr_R4_p = door_p;
         door_p->MO_O_DestNavPtr_R4_p = mo_p;
      }
      else
      {
         /* An attempt to link instances with NULL pointer (analysis error) */

         /* Trace output: Linking instances when pointer == NULL */
         errorTrace_LinkingWhenInstancePointerIsNULL( "R4" );
      }
   }

   /* ASSIGN ATTRIBUTE door.is_secure = false */
   door_p->is_secure_MO_D = false;

   /* CREATE INSTANCE turntable OF CLASS Turntable (MO_TRN) */
   {
      /* Try to seize a Turntable instance in the pool */
      struct MicrowaveOven_Turntable_MO_TRN* newInstance = (struct MicrowaveOven_Turntable_MO_TRN*) seizePoolElement( &MicrowaveOven_ClassInstancePool_MO_TRN );

      /* Check if seizing a free pool element failed */
      if ( newInstance == NULL )
      {
         /* Trace output: Class instance pool is exhausted */
         infoTrace_ClassInstancePoolIsExhausted( MicrowaveOven_ClassName_MO_TRN, MicrowaveOven_ClassInstancePool_MO_TRN.highWaterMark );

         /* Allocate the Turntable instance on the heap */
         newInstance = (struct MicrowaveOven_Turntable_MO_TRN*) malloc( sizeof(struct MicrowaveOven_Turntable_MO_TRN) );

         /* Check if memory allocation was successful */
         if ( newInstance != NULL )
         {
            /* Indicate Turntable instance heap allocation */
            newInstance->poolElement.next     = NULL;
            newInstance->poolElement.previous = NULL;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }

      /* Check if memory for the new instance was successfully allocated */
      if ( newInstance != NULL )
      {
         /* Set up this new instance */
         newInstance->chainElement.element = newInstance;

         /* Initialize the characterizing attributes in the created instance */
         /* attribute TurntableID  ### OPTIMIZED OUT ### */

         /* Set the Turntable instance start state */
         newInstance->currentISMstate_MO_TRN = MicrowaveOven_MO_TRN_IS1_1_Stationary;

         /* Initialize the relationship navigation extensions */
         /* extension MO_O_DestNavPtr_R5_p  ### OPTIMIZED OUT ### */

         /* Register the created instance in the Turntable instance chain */
         pushBackChain( &MicrowaveOven_InstanceChain_MO_TRN, &newInstance->chainElement );
      }

      /* Assign the created instance of class Turntable */
      turntable_p = newInstance;
   }

   /* RELATE mo TO turntable ACROSS R5 */
   {
      /* First check if the two instances have valid references */
      if ((mo_p != NULL) && (turntable_p != NULL))
      {
         /* CHECK THAT THE INSTANCES ARE UNLINKED BEFORE LINKING THEM */

         /* Check that the Oven instance not already is linked across R5 */
         if ( mo_p->MO_TRN_DestNavPtr_R5_p )
         {
            /* Trace output: Re-linking an already linked instance (= broken link) */
            errorTrace_ReLinkingLinkedInstanceAcross( MicrowaveOven_ClassName_MO_O, "R5" );
         }
         /* Assign the referential attributes that formalize relationship R5 */
         /* attribute TurntableID  ### OPTIMIZED OUT ### */

         /* LINK THE TWO INSTANCES ACROSS RELATIONSHIP R5 */
         mo_p->MO_TRN_DestNavPtr_R5_p = turntable_p;
      }
      else
      {
         /* An attempt to link instances with NULL pointer (analysis error) */

         /* Trace output: Linking instances when pointer == NULL */
         errorTrace_LinkingWhenInstancePointerIsNULL( "R5" );
      }
   }

}

/* ### End of File MicrowaveOven.c ### */
