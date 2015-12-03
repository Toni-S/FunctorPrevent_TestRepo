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
 *  File Name .............. Win32_JThread.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "Win32_JThread.h"

/* According to Microsoft Developer Network we should define the
   _WIN32_WINNT as 0x0400 or later to use function SwitchToThread. */
#ifndef _WIN32_WINNT
   #define _WIN32_WINNT 0x0400
#endif

#include <windows.h>
#include <winbase.h>
#include <stdlib.h>           /* Definition of NULL, malloc and free */

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */
/* C-style static function to pass to the OSes thread spawner. */
static DWORD WINAPI ThreadProc_Runner( struct Win32_JThread* self );

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* Include the TinyVector definitions here */
#include "TinyVector.h"

/* Class name to use when the current Win32_JThread can not be found */
static const char* _ExecutingClassUnavailable = "(class name not available)";

/* Initialize the vector holding all executing instances of Win32_JThread */
static struct TinyVector s_ExecutingThreadInstances = {NULL, NULL, 0, 0};

/* The definition for the thread vector pool size. */
#define _ThreadVectorPoolSize 256

/* The ThreadVectorElement pool */
static struct TinyVectorElement s_ThreadVectorElements[_ThreadVectorPoolSize];
static struct TinyPool s_ThreadVectorElementPool = {NULL, 0, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * Create function for Win32_JThread.
 *
 * INPUT                  DESCRIPTION
 * RunFunctionPtrType     "C-style" static function to execute by the thread.
 * char*                  The name of the thread.
 * unsigned long          The stack size for the thread.
 * int                    The priority of the thread.
 * boolean                Indication to start the thread when created.
 *
 * RETURNS                DESCRIPTION
 * Win32_JThread*         Pointer to the created Win32_JThread instance.
 *                        NULL is returned if the instance was not created.
 * ---------------------------------------------------------------------------
 */
struct Win32_JThread* createThread( RunFunctionPtrType theRunFunction,
                                    const char* theName,
                                    unsigned long theStackSize,
                                    int thePriority,
                                    fastBool startTheThread )
{
   /* Allocate memory for the Win32_JThread instance */
   struct Win32_JThread* newInstance = (struct Win32_JThread*) malloc( sizeof(struct Win32_JThread) );

   /* Check if memory for the new instance was successfully allocated */
   if (newInstance != NULL)
   {
      newInstance->_runFunction        = theRunFunction;
      newInstance->_name               = theName;
      newInstance->_stackSize          = theStackSize;
      newInstance->_priority           = thePriority;
      newInstance->_isAlive            = false;
      newInstance->_executingClassName = NULL;
      newInstance->_executingInstance  = NULL;

      /* Check if the thread is to be started */
      if ( startTheThread )
      {
         /* Start the thread immediately when created
            (may be necessary for constant threads) */
         startThread(newInstance);
      }
   }

   /* Return the newly created Win32_JThread instance */
   return newInstance;
}

/* ---------------------------------------------------------------------------
 * This is a static function to pass to the OSes thread creator, which
 * can not use a virtual, dynamically resolved C++ function.
 * This runner function calls the run() function specified by the
 * Win32_JThread instance 'self', which starts execution of the thread.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 *
 * RETURNS              DESCRIPTION
 * DWORD                Thread exit value (always 0).
 * ---------------------------------------------------------------------------
 */
static DWORD WINAPI ThreadProc_Runner( struct Win32_JThread* self )
{
   /* Execute the function given to us, if the run function wasn't overloaded. */
   if ( self->_runFunction )
   {
      /* Call the function specified by the Win32_JThread instance */
      self->_runFunction();
   }

   return 0;
}

/* ---------------------------------------------------------------------------
 * Start execution of the thread.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 * ---------------------------------------------------------------------------
 */
void startThread( struct Win32_JThread* self )
{
   /* Spawn the Win32 thread */
   if(!(self->_handle = CreateThread(NULL, ((DWORD) self->_stackSize),
       (LPTHREAD_START_ROUTINE)(ThreadProc_Runner), self, 0, &((DWORD) self->_id))))
   {
      /* Error handler */
   }
   else
   {
      /* Set the priority of the new thread */
      if (!(SetThreadPriority((HANDLE) self->_handle, self->_priority)))
      {
         /* Error handler */
      }
      else
      {
         /* Indicate that the Win32_JThread is alive (running) */
         self->_isAlive = true;
      }
   }

   /* Insert code for global thread book-keeping here. */

   /* Register the application thread */
   registerApplicationThread( self );
}

/* ---------------------------------------------------------------------------
 * Stop execution of the thread. The thread can not be
 * restarted after it is stopped with this function.
 * NOTE: The status of the thread is assumed to be "STILL_ACTIVE".
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 * ---------------------------------------------------------------------------
 */
void stopThread( struct Win32_JThread* self )
{
   /* Set the "executing" flag to 'false'. */
   self->_isAlive = false;

   /* Insert global book-keeping here. */

   /* Terminate the Win32 thread */
   if (!(TerminateThread((HANDLE) self->_handle, STILL_ACTIVE)))
   {
      /* Error handler */
   }
}

/* ---------------------------------------------------------------------------
 * Exit the calling thread.
 * NOTE: The status of the thread is assumed to be "STILL_ACTIVE".
 * ---------------------------------------------------------------------------
 */
void exitThread( void )
{
   /* Terminate the calling Win32 thread */
   ExitThread( STILL_ACTIVE );
}

/* ---------------------------------------------------------------------------
 * Function returning the id of current thread.
 * ---------------------------------------------------------------------------
 */
/* DWORD currentThread( void ) */
unsigned long currentThread( void )
{
   /* Return id of current thread */
   return (unsigned long) GetCurrentThreadId();
}

/* ---------------------------------------------------------------------------
 * Function returning the priority of the current thread.
 * ---------------------------------------------------------------------------
 */
int currentThreadPrio( void )
{
   /* Return prio of current thread */
   return GetThreadPriority(GetCurrentThread());
}

/* ---------------------------------------------------------------------------
 * Pause execution of the thread until the thread
 * is awakened by the resume function.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 * ---------------------------------------------------------------------------
 */
void suspendThread( const struct Win32_JThread* self )
{
   /* Suspend the Win32 thread */
   DWORD previousSuspendCount = SuspendThread((HANDLE) self->_handle);
}

/* ---------------------------------------------------------------------------
 * Resume a thread previously paused with the suspend function.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 * ---------------------------------------------------------------------------
 */
void resumeThread( const struct Win32_JThread* self )
{
   /* Resume the Win32 thread */
   DWORD previousSuspendCount = ResumeThread((HANDLE) self->_handle);
}

/* ---------------------------------------------------------------------------
 * Suspend the caller until the thread of the called object terminates.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 * ---------------------------------------------------------------------------
 */
void joinThread( const struct Win32_JThread* self )
{
   WaitForSingleObject((HANDLE) self->_handle, INFINITE);
}

/* ---------------------------------------------------------------------------
 * Check if thread is running or not. Returns 'true' if the
 * thread has been started and not is terminated.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 *
 * RETURNS              DESCRIPTION
 * boolean              Indication if the thread is running or not.
 * ---------------------------------------------------------------------------
 */
fastBool threadIsAlive( const struct Win32_JThread* self )
{
   return self->_isAlive;
}

/* ---------------------------------------------------------------------------
 * Function for initializing the Win32_JThread instance vector.
 * ---------------------------------------------------------------------------
 */
void initialize_ThreadInstanceVector( void )
{
   /* Initialize the Win32_JThread instance vector */
   s_ExecutingThreadInstances.firstElement     = NULL;
   s_ExecutingThreadInstances.lastElement      = NULL;
   s_ExecutingThreadInstances.numberOfElements = 0;
   s_ExecutingThreadInstances.currentCapacity  = 0;

   /* Initialize the ThreadVectorElement pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_ThreadVectorElements[_ThreadVectorPoolSize - 1].poolElement;
      for (index = 0; index < _ThreadVectorPoolSize; index++)
      {
         theElement            = &s_ThreadVectorElements[index].poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      s_ThreadVectorElementPool.firstFreeElement     = &s_ThreadVectorElements[0].poolElement;
      s_ThreadVectorElementPool.numberOfFreeElements = _ThreadVectorPoolSize;
      s_ThreadVectorElementPool.theCapacity          = _ThreadVectorPoolSize;
      s_ThreadVectorElementPool.numberOfUsedElements = 0;
      s_ThreadVectorElementPool.highWaterMark        = 0;
   }
}

/* ---------------------------------------------------------------------------
 * Function for creating an "empty" Win32_JThread wrapper.
 * (currently used only for the main thread during tests)
 * ---------------------------------------------------------------------------
 */
struct Win32_JThread* createEmptyThreadWrapper( void )
{
   /* Return an "empty" Win32_JThread */
   return createThread( NULL, "", 0, 0, false );
}

/* ---------------------------------------------------------------------------
 * Function for registering an application thread.
 *
 * INPUT                DESCRIPTION
 * Win32_JThread*       Pointer to the Win32_JThread instance.
 * ---------------------------------------------------------------------------
 */
void registerApplicationThread( struct Win32_JThread* self )
{
   /* Register the application thread in the thread instance vector
      (by doing so - also indicate that the thread instance exists) */
   (void) pushBackVector(&s_ExecutingThreadInstances, self, &s_ThreadVectorElementPool);
}

/* ---------------------------------------------------------------------------
 * Function for registering the currently executing state machine.
 *
 * INPUT                DESCRIPTION
 * const char*          The name of the class for the executing state machine
 * void*                The instance of the class for the state machine
 * ---------------------------------------------------------------------------
 */
void registerCurrentStateMachine( const char* executingClassName,
                                  const void* executingInstance )
{
   /* Local variable declarations */
   struct TinyVectorElement* nextIterationElement;
   struct Win32_JThread* theThread;
   unsigned long vectorIndex;

   /* Get the Windows OS id for the currenly executing thread */
   unsigned long currentThreadID = (unsigned long) GetCurrentThreadId();

   /* ITERATE THE THREAD INSTANCE VECTOR */
   nextIterationElement = s_ExecutingThreadInstances.firstElement;
   for (vectorIndex = 0; vectorIndex < s_ExecutingThreadInstances.numberOfElements; vectorIndex++)
   {
      /* Get the next thread in the vector */
      theThread = (struct Win32_JThread*) nextIterationElement->element;

      /* ...and prepare for the next iteration */
      nextIterationElement = nextIterationElement->next;

      /* Check if this is the Win32_JThread for the current OS thread */
      if ( theThread->_id == currentThreadID )
      {
         /* Register the currently executing state machine */
         theThread->_executingClassName = executingClassName;
         theThread->_executingInstance  = executingInstance;

         /* Thread operation completed - Break out */
         break;
      }
   }
}

/* ---------------------------------------------------------------------------
 * Function returning the class name for the executing state machine.
 *
 * RETURNS              DESCRIPTION
 * const char*          State machine class name executing in current thread.
 * ---------------------------------------------------------------------------
 */
const char* currentThread_ExecutingClassName( void )
{
   /* Local variable declarations */
   struct TinyVectorElement* nextIterationElement;
   struct Win32_JThread* theThread;
   unsigned long vectorIndex;

   /* Prepare the return variable */
   const char* theExecutingClassName = _ExecutingClassUnavailable;

   /* Get the Windows OS id for the currenly executing thread */
   unsigned long currentThreadID = (unsigned long) GetCurrentThreadId();

   /* ITERATE THE THREAD INSTANCE VECTOR */
   nextIterationElement = s_ExecutingThreadInstances.firstElement;
   for (vectorIndex = 0; vectorIndex < s_ExecutingThreadInstances.numberOfElements; vectorIndex++)
   {
      /* Get the next thread in the vector */
      theThread = (struct Win32_JThread*) nextIterationElement->element;

      /* ...and prepare for the next iteration */
      nextIterationElement = nextIterationElement->next;

      /* Check if this is the Win32_JThread for the current OS thread */
      if ( theThread->_id == currentThreadID )
      {
         /* Get the class name for the executing state machine */
         theExecutingClassName = theThread->_executingClassName;

         /* Thread operation completed - Break out */
         break;
      }
   }

   /* Return the executing class name */
   return theExecutingClassName;
}

/* ---------------------------------------------------------------------------
 * Function returning the executing state machine instance.
 *
 * RETURNS              DESCRIPTION
 * void*                State machine instance executing in current thread.
 * ---------------------------------------------------------------------------
 */
const void* currentThread_ExecutingInstance( void )
{
   /* Local variable declarations */
   struct TinyVectorElement* nextIterationElement;
   struct Win32_JThread* theThread;
   unsigned long vectorIndex;

   /* Prepare the return variable */
   const void* theExecutingInstance = NULL;

   /* Get the Windows OS id for the currenly executing thread */
   unsigned long currentThreadID = (unsigned long) GetCurrentThreadId();

   /* ITERATE THE THREAD INSTANCE VECTOR */
   nextIterationElement = s_ExecutingThreadInstances.firstElement;
   for (vectorIndex = 0; vectorIndex < s_ExecutingThreadInstances.numberOfElements; vectorIndex++)
   {
      /* Get the next thread in the vector */
      theThread = (struct Win32_JThread*) nextIterationElement->element;

      /* ...and prepare for the next iteration */
      nextIterationElement = nextIterationElement->next;

      /* Check if this is the Win32_JThread for the current OS thread */
      if ( theThread->_id == currentThreadID )
      {
         /* Get the executing state machine instance */
         theExecutingInstance = theThread->_executingInstance;

         /* Thread operation completed - Break out */
         break;
      }
   }

   /* Return the executing instance */
   return theExecutingInstance;
}

/* ---------------------------------------------------------------------------
 * Suspend execution of the currently executing thread for a period of time.
 *
 * INPUT                DESCRIPTION
 * int                  Time to sleep, in milliseconds.
 * ---------------------------------------------------------------------------
 */
void sleepThread( int ms )
{
   Sleep(ms);
}

/* ---------------------------------------------------------------------------
 * Immediately switch from the currently running thread to the next thread
 * scheduled to execute.
 * ---------------------------------------------------------------------------
 */
void yieldThread( void )
{
   /* If one reads the windows MSDN documentation, it is easy to believe
      that SwitchToThread() is a better choice. This might be the case,
      but the function is unsupported in everything but NT4.0. (No support
      by Windows/Windows CE, and it fails to build on windows 2000. */
	
   /* The same documentation states that 
      "A thread can relinquish the remainder of its time slice by calling 
      this (the Sleep) function with a sleep time of zero milliseconds",
      which is exactly what we want. Sleep() is portable over all windows versions. */

   /* For function SwitchToThread the MSDN documentation says:
      "Causes the calling thread to yield execution to another thread that is
       ready to run on the current processor. The operating system selects the
       next thread to be executed.", which is exactly what we want here!
      (_WIN32_WINNT must be defined as 0x0400 or later to use SwitchToThread) */

   /*  When testing this, is looks that SwitchToThread is doing a better job
       in yielding the executing thread (= faster) than Sleep(0) does. */

   if ( !(SwitchToThread()) )
   {
      /* No other threads ready to execute. Use Sleep instead. */
      Sleep(0);
   }
}

/* ### End of file Win32_JThread.c ### */
