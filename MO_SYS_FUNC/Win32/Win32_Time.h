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
 *  File Name .............. Win32_Time.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The Win32_Time is the API to the current date and time for Win32.
 * ---------------------------------------------------------------------------
 */
#ifndef WIN32_TIME_H
#define WIN32_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* #include <windows.h> */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for retrieving the current date and time.
   NOTE: This function must be invoked immediately before
         invoking the individual functions below. */
void retrieveCurrentDateAndTime( void );

/* Function for reading the 'Year' retrieved above. */
/* WORD getYear( void );                            */
unsigned short getYear( void );

/* Function for reading the 'Month' retrieved above. */
/* WORD getMonth( void );                            */
unsigned short getMonth( void );

/* Function for reading the 'Day' retrieved above. */
/* WORD getDay( void );                            */
unsigned short getDay( void );

/* Function for reading the 'Hour' retrieved above. */
/* WORD getHour( void );                            */
unsigned short getHour( void );

/* Function for reading the 'Minute' retrieved above. */
/* WORD getMinute( void );                            */
unsigned short getMinute( void );

/* Function for reading the 'Second' retrieved above. */
/* WORD getSecond( void );                            */
unsigned short getSecond( void );

/* Function for reading the 'Millisecond' retrieved above. */
/* WORD getMillisecond( void );                            */
unsigned short getMillisecond( void );

#ifdef __cplusplus
}
#endif

#endif /* WIN32_TIME_H */
