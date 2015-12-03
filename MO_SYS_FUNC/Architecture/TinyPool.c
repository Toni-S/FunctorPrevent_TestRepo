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
 *  Executable UML System Function "MO_SYS_FUNC" using BridgePoint & TinyC.
 *
 *
 *  File Name .............. TinyPool.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyPool.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Function for reading the Current Water Mark in number of used elements.
 *
 * INPUT                DESCRIPTION
 * TinyPool*            Pointer to the source TinyPool instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The Current Water Mark in number of used elements.
 * ---------------------------------------------------------------------------
 */
unsigned long getCurrentWaterMark( const struct TinyPool* self )
{
   return self->numberOfUsedElements;
}

/* ---------------------------------------------------------------------------
 * Function for reading the High Water Mark in number of used elements.
 *
 * INPUT                DESCRIPTION
 * TinyPool*            Pointer to the source TinyPool instance.
 *
 * RETURNS              DESCRIPTION
 * unsigned long        The High Water Mark in number of used elements.
 * ---------------------------------------------------------------------------
 */
unsigned long getHighWaterMark( const struct TinyPool* self )
{
   return self->highWaterMark;
}

/* ### End of file TinyPool.c ### */
