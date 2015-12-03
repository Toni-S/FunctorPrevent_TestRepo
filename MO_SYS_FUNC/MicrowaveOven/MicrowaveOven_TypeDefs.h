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
 *  File Name .............. MicrowaveOven_TypeDefs.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * ENUMERATION & STRUCTURED TYPES DESCRIPTION:
 * These are the enumeration & structured types for domain 'MicrowaveOven'
 * ---------------------------------------------------------------------------
 */
#ifndef MICROWAVEOVEN_TYPEDEFS_H
#define MICROWAVEOVEN_TYPEDEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MO_SYS_FUNC_SysTypeDefs.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/******************************************************
 *** ENUMERATION DATA TYPES DEFINED FOR THIS DOMAIN ***
 ******************************************************/

/* Declaration of enumeration type 'tube_wattage' */
typedef enum _MicrowaveOven_tube_wattage
{
   MicrowaveOven_tube_wattage_high = 0,
   MicrowaveOven_tube_wattage_low = 1,
   MicrowaveOven_tube_wattage_med_high = 2,
   MicrowaveOven_tube_wattage_med_low = 3,
   MicrowaveOven_tube_wattage_medium = 4

}  MicrowaveOven_tube_wattage;

#ifdef __cplusplus
}
#endif

#endif /* MICROWAVEOVEN_TYPEDEFS_H */
