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
 *  File Name .............. TinyString.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyString.h"
#include "GlobalTypeDefs.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* Definition of the default tcString initialization & return value. */
const tcString _default_tcString_value = {""};

/* Definition of the stringRef to tcString conversion value.
   (first temporary fix for supporting this type of conversion,
    only single-threaded applications is supported and only a
    single parameter per statement can be converted) */
tcString _stringRef_to_tcString_value;

/* ---------------------------------------------------------------------------
 * Function for comparing two buffers.
 *
 * INPUT                DESCRIPTION
 * const void*          Pointer to the first buffer to compare.
 * const void*          Pointer to the second buffer to compare.
 *
 * RETURNS              DESCRIPTION
 * int                  The result of the buffer comparison:
 *                      < 0 if buffer1 is less than buffer2
 *                        0 if buffer1 is identical to buffer2
 *                      > 0 if buffer1 is greater than buffer2
 * ---------------------------------------------------------------------------
 */
int TinyC_memcmp( const void* buffer1, const void* buffer2, size_t count )
{
   /* Local variable declarations */
   int comparisonResult      = 0;        /* ...assuming identical buffers */
   unsigned int cursorCount  = count;
   const char* buffer1Cursor = buffer1;
   const char* buffer2Cursor = buffer2;

   /* Compare the two buffers */
   while ( cursorCount > 0 )
   {
      /* Check if the buffer content is different */
      if ( *buffer1Cursor != *buffer2Cursor )
      {
         /* Get the result of the buffer comparison */
         comparisonResult = (*buffer1Cursor - *buffer2Cursor);

         /* Comparison completed */
         break;
      }

      /* Step to the next character */
      buffer1Cursor++;
      buffer2Cursor++;
      cursorCount--;
   }

   /* Return the result of the comparison */
   return comparisonResult;
}

/* ---------------------------------------------------------------------------
 * Function for copying a buffer.
 * (by Kirill Fedoseev @ MERA)
 *
 * INPUT                DESCRIPTION
 * void*                Pointer to the destination buffer.
 * const void*          Pointer to the source buffer.
 *
 * OUTPUT               DESCRIPTION
 *                      The src buffer is copied to the dst buffer.
 * ---------------------------------------------------------------------------
 */
void TinyC_memcpy( void* dst, const void* src, size_t size )
{
   /* Local variable declarations */
   size_t i;
   size_t ll;

   unsigned char *bdst = (unsigned char*) dst;
   unsigned char *bsrc = (unsigned char*) src;
   unsigned long *ldst = (unsigned long*) dst;
   unsigned long *lsrc = (unsigned long*) src;

   /* Copy the main part */
   for (ll = (size >> 2), i = 0; i < ll; i++)
   {
      ldst [i] = lsrc [i];
   }

   /* Copy the tail part */
   switch (size % 4)
   {
   case 1:
      bdst [size - 1] = bsrc [size - 1];
      break;
   case 2:
      bdst [size - 1] = bsrc [size - 1];
      bdst [size - 2] = bsrc [size - 2];
      break;
   case 3:
      bdst [size - 1] = bsrc [size - 1];
      bdst [size - 2] = bsrc [size - 2];
      bdst [size - 3] = bsrc [size - 3];
   }
}

/* ---------------------------------------------------------------------------
 * Function for comparing two strings lexicographically.
 *
 * INPUT                DESCRIPTION
 * const char*          Pointer to the first string to compare.
 * const char*          Pointer to the second string to compare.
 *
 * RETURNS              DESCRIPTION
 * int                  The result of the string comparison:
 *                      < 0 if string1 is less than string2
 *                        0 if string1 is identical to string2
 *                      > 0 if string1 is greater than string2
 * ---------------------------------------------------------------------------
 */
int TinyC_strcmp( const char* string1, const char* string2 )
{
   /* Local variable declarations */
   const char* string1Cursor = string1;
   const char* string2Cursor = string2;

   /* Compare the two strings */
   while ( *string1Cursor == *string2Cursor )
   {
      /* Check if end of one string is reached
         (or if the string was empty on entry) */
      if ( *string1Cursor == 0 )
      {
         /* Comparison completed */
         break;
      }

      /* Step to the next character */
      string1Cursor++;
      string2Cursor++;
   }

   /* Return the result of the comparison */
   return (*string1Cursor - *string2Cursor);
}

/* ---------------------------------------------------------------------------
 * Function for appending a source string to a destination string.
 *
 * INPUT                DESCRIPTION
 * char*                Pointer to the buffer for the output result.
 * const char*          Pointer to the string to append.
 *
 * OUTPUT               DESCRIPTION
 *                      The sourceString is appended to the destBuffer string.
 *
 * RETURNS              DESCRIPTION
 * char*                Pointer to the end-of-string mark in the destBuffer.
 *                      (can be used as input destBuffer in consecutive strcat)
 * ---------------------------------------------------------------------------
 */
char* TinyC_strcat( char* destBuffer, const char* sourceString )
{
   /* Local variable declarations */
   char* destCursor         = destBuffer;
   const char* sourceCursor = sourceString;

   /* Search the end of string in the destination buffer */
   while ( *destCursor != 0 )
   {
      /* Step to the next character */
      destCursor++;
   }

   /* Append the source string */
   while ( *sourceCursor != 0 )
   {
      /* Copy the character from the source string */
      *destCursor++ = *sourceCursor++;
   }

   /* Mark the end of the output string */
   *destCursor = 0;

   /* Return end-of-string mark location */
   return destCursor;
}

/* ---------------------------------------------------------------------------
 * Function for copying a source string to a destination string.
 *
 * INPUT                DESCRIPTION
 * char*                Pointer to the destination string.
 * const char*          Pointer to the string to append.
 *
 * OUTPUT               DESCRIPTION
 *                      The sourceString is copied to the destString.
 * ---------------------------------------------------------------------------
 */
void TinyC_strcpy( char* destString, const char* sourceString )
{
   /* Local variable declarations */
   long charCount           = _MaxStringCharacters;
   char* destCursor         = destString;
   const char* sourceCursor = sourceString;

   /* Copy the source string */
   while (( charCount > 0 ) && ( *sourceCursor != 0 ))
   {
      /* Copy the character from the source string */
      *destCursor++ = *sourceCursor++;

      /* One character copied */
      charCount--;
   }

   /* Mark the end of the output string */
   *destCursor = 0;
}

/* ---------------------------------------------------------------------------
 * Function for adding two strings.
 *
 * INPUT                DESCRIPTION
 *       char*          Pointer to the output result string.
 * const char*          Pointer to the first string to add.
 * const char*          Pointer to the second string to add.
 *
 * OUTPUT               DESCRIPTION
 *                      The sum of string1 and string2.
 *
 * RETURNS              DESCRIPTION
 * char*                Pointer to the resulting string.
 * ---------------------------------------------------------------------------
 */
char* TinyC_stradd( char* resultString, const char* string1, const char* string2 )
{
   /* Local variable declarations */
   long charCount           = _MaxStringCharacters;
   char* resultCursor       = resultString;
   const char* stringCursor = string1;

   /* Copy the first string */
   while (( charCount > 0 ) && ( *stringCursor != 0 ))
   {
      /* Copy the character from the first string */
      *resultCursor++ = *stringCursor++;

      /* One character copied */
      charCount--;
   }

   /* Get the second string */
   stringCursor = string2;

   /* Copy the second string */
   while (( charCount > 0 ) && ( *stringCursor != 0 ))
   {
      /* Copy the character from the first string */
      *resultCursor++ = *stringCursor++;

      /* One character copied */
      charCount--;
   }

   /* Mark the end of the output string */
   *resultCursor = 0;

   /* Return the resulting string */
   return resultString;
}

/* ---------------------------------------------------------------------------
 * Function for converting a stringRef or char* typed value to a tcString object.
 *
 * INPUT                DESCRIPTION
 *    tcString          The output result string object container.
 * const char*          Pointer to the stringRef or char* typed value.
 *
 * RETURNS              DESCRIPTION
 * tcString             The resulting string object.
 * ---------------------------------------------------------------------------
 */
tcString TinyC_StringRef2String( tcString destStringObject, const char* sourceStringRef )
{
   /* Local variable declarations */
   long charCount           = _MaxStringCharacters;
   char* destCursor         = destStringObject.stringValue;
   const char* sourceCursor = sourceStringRef;

   /* Copy the source string */
   while (( charCount > 0 ) && ( *sourceCursor != 0 ))
   {
      /* Copy the character from the source string */
      *destCursor++ = *sourceCursor++;

      /* One character copied */
      charCount--;
   }

   /* Mark the end of the output string */
   *destCursor = 0;

   /* Return the resulting string object */
   return destStringObject;
}

/* ### End of file TinyString.c ### */
