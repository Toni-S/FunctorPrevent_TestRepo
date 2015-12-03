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
 *  File Name .............. Win32_JThread.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The Win32_JThread implements Java-like threads for C on Win32.
 * ---------------------------------------------------------------------------
 */
#ifndef WIN32_JTHREAD_H
#define WIN32_JTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* #include <windows.h> */
#include "GlobalTypeDefs.h"
#include "ArchitectureConfig.h"

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* The definition for the default event dispatcher stack size */
#define _DefaultEventDispatcherStackSize 32768

/* The definition for the normal event dispatcher priority               */
/* #define _NormalEventDispatcherPriority   THREAD_PRIORITY_NORMAL (= 0) */
#define _NormalEventDispatcherPriority 0

/* The definition for the realtime event dispatcher priority                  */
/* #define _RealtimeEventDispatcherPriority THREAD_BASE_PRIORITY_LOWRT (= 15) */
#define _RealtimeEventDispatcherPriority 15

/* Thread Run Function pointer type. */
typedef void ( *RunFunctionPtrType )( void );

/* The Win32_JThread Structure */
struct Win32_JThread;
typedef struct Win32_JThread Win32_JThread;

struct Win32_JThread
{
/* Pointer to the function to be executed by the Win32 thread. */
   RunFunctionPtrType _runFunction;

/* Name of the Win32 thread. */
   const char* _name;

/* Stack size for the thread. */
/* DWORD _stackSize;          */
   unsigned long _stackSize;

/* Priority of the Win32 thread. */
   int _priority;

/* 'true' if the underlying Win32 thread has been started,
   'false' if it has terminated. */
   fastBool _isAlive;

/* Windows OS handle for the thread. */
/* HANDLE _handle;                   */
   void* _handle;

/* Windows OS id for the thread. */
/* DWORD _id;                    */
   unsigned long _id;

/* Pointer to a string stating the currently executing class name */
   const char* _executingClassName;

/* Reference to the currently executing state machine instance
   (= NULL for class-based state machines = single instance) */
   const void* _executingInstance;
};

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */

/* Create function for Win32_JThread. */
struct Win32_JThread* createThread( RunFunctionPtrType theRunFunction,
                                    const char* theName,
                                    unsigned long theStackSize,
                                    int thePriority,
                                    fastBool startTheThread );

/* Start execution of the thread. */
void startThread( struct Win32_JThread* self );

/* Stop execution of the thread. The thread can not be
   restarted after it is stopped with this function. */
void stopThread( struct Win32_JThread* self );

/* Exit the calling thread. */
void exitThread( void );

/* Function returning the id of current thread. */
/* DWORD currentThread( void );                 */
unsigned long currentThread( void );

/* Function returning the priority of the current thread. */
int currentThreadPrio( void );

/* Functions to pause and resume execution of the thread. */
void suspendThread( const struct Win32_JThread* self );
void resumeThread( const struct Win32_JThread* self );

/* Join causes the calling thread to wait for completion of
   execution of the thread associated with the object called. */
void joinThread( const struct Win32_JThread* self );

/* Returns 'true' if the thread has been started and not is terminated. */
fastBool threadIsAlive( const struct Win32_JThread* self );

/* Function for initializing the Win32_JThread instance vector. */
void initialize_ThreadInstanceVector( void );

/* Function for creating an "empty" Win32_JThread wrapper.
   (currently used only for the main thread during tests) */
struct Win32_JThread* createEmptyThreadWrapper( void );

/* Function for registering an application thread. */
void registerApplicationThread( struct Win32_JThread* self );

/* Function for registering the currently executing state machine. */
void registerCurrentStateMachine( const char* executingClassName,
                                  const void* executingInstance );

/* Function returning the class name for the executing state machine. */
const char* currentThread_ExecutingClassName( void );

/* Function returning the executing state machine instance. */
const void* currentThread_ExecutingInstance( void );

/* Suspend execution for a period of time. This function
   operate on the currently executing thread, not on the
   object the function is called in. */
void sleepThread( int ms );

/* Causes the currently executing thread to hand over the cpu to the
   next thread scheduled to execute. */
void yieldThread( void );

#ifdef __cplusplus
}
#endif

#endif /* WIN32_JTHREAD_H */
