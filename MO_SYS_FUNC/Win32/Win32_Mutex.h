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
 *  File Name .............. Win32_Mutex.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The Win32_Mutex implements a mutex for C on Win32.
 * ---------------------------------------------------------------------------
 */
#ifndef WIN32_MUTEX_H
#define WIN32_MUTEX_H

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
/* The Win32_Mutex Structure */
struct Win32_Mutex;
typedef struct Win32_Mutex Win32_Mutex;

struct Win32_Mutex
{
/* Win32 Mutex Handle.    */
/* HANDLE theMutexHandle; */
   void* theMutexHandle;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for creating a mutex. */
struct Win32_Mutex* createMutex( void );

/* Function for deleting a mutex. */
void deleteMutex( struct Win32_Mutex* self );

/* Function for locking the mutex. */
void lockMutex( const struct Win32_Mutex* self );

/* Function for unlocking the mutex. */
void unlockMutex( const struct Win32_Mutex* self );

#ifdef __cplusplus
}
#endif

#endif /* WIN32_MUTEX_H */
