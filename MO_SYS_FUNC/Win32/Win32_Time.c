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
 *  File Name .............. Win32_Time.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "Win32_Time.h"
#include <windows.h>
#include <winbase.h>          /* The windows base services */
                              /********************************************
                               ** NOTE: This requires kernel32.lib to   ***
                               **       be linked with the application. ***
                               ********************************************/

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* The Win32 System Time */
static SYSTEMTIME s_theWin32SystemTime = { 0, 0, 0, 0, 0, 0, 0, 0 };

/* ---------------------------------------------------------------------------
 * Function for retrieving the current date and time.
 * NOTE: This function must be invoked immediately before
 *       invoking the individual functions below.
 * ---------------------------------------------------------------------------
 */
void retrieveCurrentDateAndTime( void )
{
   GetLocalTime( &s_theWin32SystemTime );
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Year' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getYear( void ) */
unsigned short getYear( void )
{
   return (unsigned short) s_theWin32SystemTime.wYear;
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Month' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getMonth( void ) */
unsigned short getMonth( void )
{
   return (unsigned short) s_theWin32SystemTime.wMonth;
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Day' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getDay( void ) */
unsigned short getDay( void )
{
   return (unsigned short) s_theWin32SystemTime.wDay;
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Hour' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getHour( void ) */
unsigned short getHour( void )
{
   return (unsigned short) s_theWin32SystemTime.wHour;
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Minute' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getMinute( void ) */
unsigned short getMinute( void )
{
   return (unsigned short) s_theWin32SystemTime.wMinute;
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Second' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getSecond( void ) */
unsigned short getSecond( void )
{
   return (unsigned short) s_theWin32SystemTime.wSecond;
}

/* ---------------------------------------------------------------------------
 * Function for reading the 'Millisecond' retrieved above.
 * ---------------------------------------------------------------------------
 */
/* WORD getMillisecond( void ) */
unsigned short getMillisecond( void )
{
   return (unsigned short) s_theWin32SystemTime.wMilliseconds;
}

/* ### End of file Win32_Time.c ### */
