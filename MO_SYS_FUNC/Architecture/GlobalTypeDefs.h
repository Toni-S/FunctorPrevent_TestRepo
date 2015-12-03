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
 *  File Name .............. GlobalTypeDefs.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * This file contains type definitions that are global to the system.
 * ---------------------------------------------------------------------------
 */
#ifndef GLOBALTYPEDEFS_H
#define GLOBALTYPEDEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "time.h"
#include "TinyString.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* Define the keyword to use for inline */
#if defined WIN32
   #define __inlined__ __inline

#elif defined __DCC__
   /* #define __inlined__ __inline__ */ /* FlexeLint do not understand __inline__       */
   #define __inlined__ INLINE           /* INLINE is defined by Cello build environment */

#elif defined __GNUC__
   #define __inlined__ static inline

#elif defined _TMS320C6X                /* Proposed solution for the DPP platform */
   #define __inlined__ inline

#elif defined __arm__                   /* Proposed solution e.g for the ARM Cortex-M3 platform */
   #define __inlined__ __inline

#elif defined MAKE_WITH_LPP             /* Proposed solution for LPP */
   #define __inlined__ static inline

#else  /* all other compilers */
   #define __inlined__ __inline__
#endif

/* Definition of boolean data type
   (valid when not compiled as C++ code) */
#ifndef __cplusplus

   /* Undefine 'bool' when needed */
   #ifdef bool
   #undef bool
   #endif

   /* Undefine 'false' when needed */
   #ifdef false
   #undef false
   #endif

   /* Undefine 'true' when needed */
   #ifdef true
   #undef true
   #endif

   /* Definition of C-version boolean data type */
   typedef unsigned char bool;
   #define false 0
   #define true  1
/* typedef enum bool
   {
      false = 0,
      true  = 1

   }  bool; */

#endif

/* Definition of a fast C-version boolean data type to use for semaphores and
   status variables to get shorter read/modify/write cycles = faster execution.
   (variables of type int are one machine-type word in length) */
typedef int fastBool;

/* OSE/nxtOSEK specific integer types. (as defined in osetypes.h/mytypes.h) */
typedef unsigned long  int    U32;
typedef unsigned short int    U16;
typedef unsigned       char    U8;
typedef          long  int    S32;
typedef          short int    S16;
typedef   signed       char    S8;

/* Definition of date data type.       (time in seconds since 1970) */
typedef time_t _date_;

/* Definition of timestamp data type.  (timestamp in clock ticks) */
typedef unsigned long _timestamp_;

#ifdef __cplusplus
}
#endif

#endif /* GLOBALTYPEDEFS_H */
