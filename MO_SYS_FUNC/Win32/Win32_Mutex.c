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
 *  File Name .............. Win32_Mutex.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "Win32_Mutex.h"
#include <windows.h>
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Function for creating a mutex.
 *
 * RETURNS              DESCRIPTION
 * Win32_Mutex*         Pointer to the created Win32_Mutex instance.
 * ---------------------------------------------------------------------------
 */
struct Win32_Mutex* createMutex( void )
{
   /* Allocate memory for the Win32_Mutex instance */
   struct Win32_Mutex* newMutex = (struct Win32_Mutex*) malloc( sizeof(struct Win32_Mutex) );

   /* Check if memory for the new instance was successfully allocated */
   if (newMutex != NULL)
   {
      /* Create the mutex handle */
      newMutex->theMutexHandle = CreateMutex(NULL, FALSE, NULL);

      /* NOTE: The line below can be used for semaphores */
      /* newMutex->theMutexHandle = CreateSemaphore(NULL, 1, 1, NULL); */
   }

   return newMutex;
}

/* ---------------------------------------------------------------------------
 * Function for deleting a mutex.
 *
 * INPUT                DESCRIPTION
 * Win32_Mutex*         Pointer to the Win32_Mutex instance.
 * ---------------------------------------------------------------------------
 */
void deleteMutex( struct Win32_Mutex* self )
{
   /* Close the mutex handle */
   if ( !(CloseHandle((HANDLE) self->theMutexHandle)) )
   {
      /* Error handler */
   }

   /* Release memory for the Win32_Mutex instance */
   free( self );
}

/* ---------------------------------------------------------------------------
 * NOTE: The lockMutex function should be defined as an inlined function
 *       to improve application execution performance, but this would mean
 *       that windows.h must be included from the header file, which then
 *       lead to extremely long compilation times for the application.
 *
 *       For that reason lockMutex is not (yet) an inlined function.
 * ---------------------------------------------------------------------------
 * Function for locking the mutex.
 *
 * INPUT                DESCRIPTION
 * Win32_Mutex*         Pointer to the Win32_Mutex instance.
 * ---------------------------------------------------------------------------
 */
void lockMutex( const struct Win32_Mutex* self )
{
   /* Wait forever to acquire ownership of the mutex */
   if ( WaitForSingleObject((HANDLE) self->theMutexHandle, INFINITE) == WAIT_FAILED )
   {
      /* Error handler */
   }
}

/* ---------------------------------------------------------------------------
 * NOTE: The unlockMutex function should be defined as an inlined function
 *       to improve application execution performance, but this would mean
 *       that windows.h must be included from the header file, which then
 *       lead to extremely long compilation times for the application.
 *
 *       For that reason unlockMutex is not (yet) an inlined function.
 * ---------------------------------------------------------------------------
 * Function for unlocking the mutex.
 *
 * INPUT                DESCRIPTION
 * Win32_Mutex*         Pointer to the Win32_Mutex instance.
 * ---------------------------------------------------------------------------
 */
void unlockMutex( const struct Win32_Mutex* self )
{
   /* Release ownership of the mutex */
   if ( !(ReleaseMutex((HANDLE) self->theMutexHandle)) )
   {
      /* Error handler */
   }

   /* NOTE: The line below can be used for semaphores */
   /* if ( !(ReleaseSemaphore((HANDLE) self->theMutexHandle, 1, NULL)) ) */
}

/* ### End of file Win32_Mutex.c ### */
