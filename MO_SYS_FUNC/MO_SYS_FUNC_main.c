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
 *
 *  File Name .............. MO_SYS_FUNC_main.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * This is the hand-coded main() program for system function MO_SYS_FUNC.
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "MO_SYS_FUNC.h"
#include "MicrowaveOven.h"

#include "ArchitectureConfig.h"

#if defined _TargetOperatingSystemIs_Win32
   #include "Win32_JThread.h"
   #include "Win32_Time.h"
   #include <stdlib.h>
   #include <stdio.h>
#elif defined _TargetOperatingSystemIs_OSE
   #include "OSE_JThread.h"
   #include "OSE_Time.h"
   #if defined softOSE
      #include <stdio.h>
   #elif defined _TargetPlatformIs_Cello
      #include "cello_te_ose.h"
      #include "cello_te_trace.h"
   #endif
#elif defined _TargetOperatingSystemIs_Linux
   #include "Linux_JThread.h"
   #include "Linux_Time.h"
   #include <stdio.h>
#elif defined _TargetOperatingSystemIs_LPP
   #include "LPP_JThread.h"
   #include "LPP_Time.h"
   #include <stdio.h>
#elif defined _TargetOperatingSystemIs_nxtOSEK
   #include "nxtOSEK_JThread.h"
   #include "nxtOSEK_Time.h"
#endif

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* Executing class/instance information is needed when instrumentation code
   for Model Debugging is enabled or run-time event tracing is enabled. */
#if defined _EnableModelDebugMonitorCode || defined _RunTimeEventTracing
   #ifdef _ThreadingIsEnabled

      /* The name of the main program */
      static const char* mainProgramName = "main()";

      /* An <os>_JThread wrapper for the main program */
      #if defined _TargetOperatingSystemIs_Win32
         static struct Win32_JThread* mainWrapperThread = NULL;
      #elif defined _TargetOperatingSystemIs_OSE
         static struct OSE_JThread* mainWrapperThread = NULL;
      #elif defined _TargetOperatingSystemIs_Linux
         static struct Linux_JThread* mainWrapperThread = NULL;
      #elif defined _TargetOperatingSystemIs_LPP
         static struct LPP_JThread* mainWrapperThread = NULL;
      #elif defined _TargetOperatingSystemIs_nxtOSEK
         static struct nxtOSEK_JThread* mainWrapperThread = NULL;
      #endif

   #endif
#endif /* _EnableModelDebugMonitorCode || _RunTimeEventTracing */

/* ---------------------------------------------------------------------------
 * Main Program
 * ---------------------------------------------------------------------------
 */
#if defined _TargetOperatingSystemIs_Win32
int main( void )
#elif defined _TargetOperatingSystemIs_OSE
OS_PROCESS(MO_SYS_FUNC_main)
#elif defined _TargetOperatingSystemIs_Linux
int main( void )
#elif defined _TargetOperatingSystemIs_LPP
LPP_PROCESS(MO_SYS_FUNC_main)
#elif defined _TargetOperatingSystemIs_nxtOSEK
int main( void )
#endif
{
   /* Local variable declarations */
#ifdef _TargetOperatingSystemIs_Win32
   int quitChar;
#endif

   /* Print information about the application */
   printf(" \n");
   printf(" Starting the MicrowaveOven. (will run for 20 seconds)\n");
   printf(" The same procedure as in the sample model demo for the\n");
   printf(" Verifier in BridgePoint's 'Help' will be executed.\n");
   printf(" \n");
   printf(" \n");

   /* Default start trace output */
#ifdef _TargetOperatingSystemIs_OSE
   #if defined softOSE
   printf("### Starting MO_SYS_FUNC_main process\n");
   #elif defined _TargetPlatformIs_Cello
   INFO("### Starting MO_SYS_FUNC_main process");
   #endif
#endif

   /* Startup the MO_SYS_FUNC system function */
   MO_SYS_FUNC_Startup();

/* Executing class/instance information is needed when instrumentation code
   for Model Debugging is enabled or run-time event tracing is enabled. */
#if defined _EnableModelDebugMonitorCode || defined _RunTimeEventTracing
   #ifdef _ThreadingIsEnabled

   /* Create the <os>_JThread wrapper for the main program */
   mainWrapperThread = createEmptyThreadWrapper();

   /* Define the name of the currently executing Main Program */
   mainWrapperThread->_executingClassName = mainProgramName;
   mainWrapperThread->_executingInstance  = NULL;

   /* Define the <os> id for the currently executing thread */
   mainWrapperThread->_id = currentThread();

   /* Register the currently executing Main Program thread
      (enables printouts of main() as sender of events) */
   registerApplicationThread( mainWrapperThread );

   #endif
#endif /* _EnableModelDebugMonitorCode || _RunTimeEventTracing */

   /* Startup the application
      (call the application startup function/-s here) */
   MicrowaveOven_DefineOven();

   /* Launch the application
      (call the function that launches the application here) */
   MicrowaveOven_TestSequence1();

   /* Run the application for <number> seconds
      (only needed for test beds/programs) */
   sleepThread(20000);

   /* Shutdown the MO_SYS_FUNC system function
      (only needed for test beds/programs) */
   MO_SYS_FUNC_Shutdown();

#if defined _TargetOperatingSystemIs_Win32

   /* Wait for key stroke to quit */
   printf(" \n");
   printf(" Press <Enter> to quit.\n");
   quitChar = getchar();

   exit( 0 );

#elif defined _TargetOperatingSystemIs_OSE

   /* Default stop trace output */
   #if defined softOSE
   printf("### MO_SYS_FUNC_main process done\n");
   #elif defined _TargetPlatformIs_Cello
   INFO("### MO_SYS_FUNC_main process done");
   #endif

   /* Put the main process in a pending state */
   while (true)
   {
      const SIGSELECT any_signal[] = {0};
      union SIGNAL* anySignal = receive((SIGSELECT *) any_signal);
   }

#elif defined _TargetOperatingSystemIs_Linux

   exit( 0 );

#elif defined _TargetOperatingSystemIs_LPP

   LPP_killProcess( LPP_getPid() );

#elif defined _TargetOperatingSystemIs_nxtOSEK

   exit( 0 );

#endif
}

/* ### End of Main Program MO_SYS_FUNC_main ### */
