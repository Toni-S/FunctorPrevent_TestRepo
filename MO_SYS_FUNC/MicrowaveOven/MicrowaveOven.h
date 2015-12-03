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
 *  File Name .............. MicrowaveOven.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * DOMAIN FUNCTIONS DESCRIPTION:
 * These are the functions for domain 'MicrowaveOven'
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_H
#define MICROWAVEOVEN_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MO_SYS_FUNC.h"
#include "MicrowaveOven_TypeDefs.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for starting up the entire MicrowaveOven domain */
void MicrowaveOven_Startup( void );

/* Function for shutting down the entire MicrowaveOven domain */
void MicrowaveOven_Shutdown( void );

/* Domain Function 'StartCooking' */
void MicrowaveOven_StartCooking( void );

/* Domain Function 'CancelCooking' */
void MicrowaveOven_CancelCooking( void );

/* Domain Function 'SpecifyCookingPeriod' */
void MicrowaveOven_SpecifyCookingPeriod( long par_cookingPeriod );

/* Domain Function 'IncreasePower' */
void MicrowaveOven_IncreasePower( void );

/* Domain Function 'DecreasePower' */
void MicrowaveOven_DecreasePower( void );

/* Domain Function 'OpenDoor' */
void MicrowaveOven_OpenDoor( void );

/* Domain Function 'CloseDoor' */
void MicrowaveOven_CloseDoor( void );

/* Domain Function 'TestSequence1' */
void MicrowaveOven_TestSequence1( void );

/* Domain Function 'DefineOven' */
void MicrowaveOven_DefineOven( void );

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_H */
