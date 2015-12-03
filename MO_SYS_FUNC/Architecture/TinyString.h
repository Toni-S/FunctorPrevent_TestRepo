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
 *  File Name .............. TinyString.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyString defines string functions needed by the TinyC architecture
 * ---------------------------------------------------------------------------
 */
#ifndef TINYSTRING_H
#define TINYSTRING_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "ArchitectureConfig.h"
#include <string.h>          /* Definition of size_t */

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* Definition of the TinyC string type */
typedef struct tcString
{
   char stringValue[ _MaxStringLength ];

}  tcString;

/* Definition of the default tcString initialization & return value. */
extern const tcString _default_tcString_value;

/* Definition of the stringRef to tcString conversion value.
   (first temporary fix for supporting this type of conversion,
    only single-threaded applications is supported and only a
    single parameter per statement can be converted) */
extern tcString _stringRef_to_tcString_value;

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for comparing two buffers. */
int TinyC_memcmp( const void* buffer1, const void* buffer2, size_t count );

/* Function for copying a buffer.
   (by Kirill Fedoseev @ MERA) */
void TinyC_memcpy( void* dst, const void* src, size_t size );

/* Function for comparing two strings lexicographically. */
int TinyC_strcmp( const char* string1, const char* string2 );

/* Function for appending a source string to a destination string. */
char* TinyC_strcat( char* destBuffer, const char* sourceString );

/* Function for copying a source string to a destination string. */
void TinyC_strcpy( char* destString, const char* sourceString );

/* Function for adding two strings. */
char* TinyC_stradd( char* resultString, const char* string1, const char* string2 );

/* Function for converting a stringRef or char* typed value to a tcString object. */
tcString TinyC_StringRef2String( tcString destStringObject, const char* sourceStringRef );

#ifdef __cplusplus
}
#endif

#endif /* TINYSTRING_H */
