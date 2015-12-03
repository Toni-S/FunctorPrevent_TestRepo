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
 *  File Name .............. GenericEvent.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "GenericEvent.h"
#include "TinyTrace.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */

/* The 16 byte event data pool */
static struct _Size16bytes_ s_EventDataElements_Size16bytes[_EventData16BytePoolSize];
static struct TinyPool s_EventDataPool_Size16bytes = {NULL, 0, 0, 0, 0};

/* The 32 byte event data pool */
static struct _Size32bytes_ s_EventDataElements_Size32bytes[_EventData32BytePoolSize];
static struct TinyPool s_EventDataPool_Size32bytes = {NULL, 0, 0, 0, 0};

/* The 64 byte event data pool */
static struct _Size64bytes_ s_EventDataElements_Size64bytes[_EventData64BytePoolSize];
static struct TinyPool s_EventDataPool_Size64bytes = {NULL, 0, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * Function for initializing the GenericEvent.
 * NOTE: This function must be invoked on startup of the system function.
 * ---------------------------------------------------------------------------
 */
void initialize_GenericEvent( void )
{
   /* Initialize the 16 byte event data pool */
   {
      unsigned long index;
      struct _Size16bytes_* theEventData = &s_EventDataElements_Size16bytes[_EventData16BytePoolSize - 1];
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
      for (index = 0; index < _EventData16BytePoolSize; index++)
      {
         theEventData = &s_EventDataElements_Size16bytes[index];
         theElement   = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
         /* Additional dummy (void*) cast to keep FlexeLint quiet (not generate Info 740) */
         ((struct _EventDataHeader_*) ((void*) theEventData))->sizeInBytes = 16;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      theEventData = &s_EventDataElements_Size16bytes[0];
      s_EventDataPool_Size16bytes.firstFreeElement      = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
      s_EventDataPool_Size16bytes.numberOfFreeElements  = _EventData16BytePoolSize;
      s_EventDataPool_Size16bytes.theCapacity           = _EventData16BytePoolSize;
      s_EventDataPool_Size16bytes.numberOfUsedElements  = 0;
      s_EventDataPool_Size16bytes.highWaterMark         = 0;
   }

   /* Initialize the 32 byte event data pool */
   {
      unsigned long index;
      struct _Size32bytes_* theEventData = &s_EventDataElements_Size32bytes[_EventData32BytePoolSize - 1];
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
      for (index = 0; index < _EventData32BytePoolSize; index++)
      {
         theEventData = &s_EventDataElements_Size32bytes[index];
         theElement   = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
         /* Additional dummy (void*) cast to keep FlexeLint quiet (not generate Info 740) */
         ((struct _EventDataHeader_*) ((void*) theEventData))->sizeInBytes = 32;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      theEventData = &s_EventDataElements_Size32bytes[0];
      s_EventDataPool_Size32bytes.firstFreeElement      = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
      s_EventDataPool_Size32bytes.numberOfFreeElements  = _EventData32BytePoolSize;
      s_EventDataPool_Size32bytes.theCapacity           = _EventData32BytePoolSize;
      s_EventDataPool_Size32bytes.numberOfUsedElements  = 0;
      s_EventDataPool_Size32bytes.highWaterMark         = 0;
   }

   /* Initialize the 64 byte event data pool */
   {
      unsigned long index;
      struct _Size64bytes_* theEventData = &s_EventDataElements_Size64bytes[_EventData64BytePoolSize - 1];
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
      for (index = 0; index < _EventData64BytePoolSize; index++)
      {
         theEventData = &s_EventDataElements_Size64bytes[index];
         theElement   = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
         /* Additional dummy (void*) cast to keep FlexeLint quiet (not generate Info 740) */
         ((struct _EventDataHeader_*) ((void*) theEventData))->sizeInBytes = 64;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      theEventData = &s_EventDataElements_Size64bytes[0];
      s_EventDataPool_Size64bytes.firstFreeElement      = &((struct _EventDataHeader_*) ((void*) theEventData))->poolElement;
      s_EventDataPool_Size64bytes.numberOfFreeElements  = _EventData64BytePoolSize;
      s_EventDataPool_Size64bytes.theCapacity           = _EventData64BytePoolSize;
      s_EventDataPool_Size64bytes.numberOfUsedElements  = 0;
      s_EventDataPool_Size64bytes.highWaterMark         = 0;
   }

}

/* ---------------------------------------------------------------------------
 * Function for shutting down the GenericEvent.
 * ---------------------------------------------------------------------------
 */
void shutdown_GenericEvent( void )
{
}

/* ---------------------------------------------------------------------------
 * Function for allocating memory for an event data instance.
 * ---------------------------------------------------------------------------
 */
void* seizeEventDataMemory( size_t instanceSize )
{
   /* Local variable declarations */
   void* seizedInstance;
   struct TinyPool* eventDataPool;

   /* Identify the size of the event data instance to allocate */
   switch ( instanceSize )
   {
      case 0:  /* Event data instance size = 0 bytes */
      {
         /* It's not possible to allocate 0 bytes of memory !!! */
         eventDataPool = NULL;

         break;
      }
      case 1:  /* Event data instance size = 1 byte */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 2:  /* Event data instance size = 2 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 3:  /* Event data instance size = 3 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 4:  /* Event data instance size = 4 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 5:  /* Event data instance size = 5 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 6:  /* Event data instance size = 6 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 7:  /* Event data instance size = 7 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 8:  /* Event data instance size = 8 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 9:  /* Event data instance size = 9 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 10:  /* Event data instance size = 10 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 11:  /* Event data instance size = 11 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 12:  /* Event data instance size = 12 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 13:  /* Event data instance size = 13 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 14:  /* Event data instance size = 14 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 15:  /* Event data instance size = 15 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 16:  /* Event data instance size = 16 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size16bytes;

         break;
      }
      case 17:  /* Event data instance size = 17 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 18:  /* Event data instance size = 18 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 19:  /* Event data instance size = 19 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 20:  /* Event data instance size = 20 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 21:  /* Event data instance size = 21 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 22:  /* Event data instance size = 22 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 23:  /* Event data instance size = 23 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 24:  /* Event data instance size = 24 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 25:  /* Event data instance size = 25 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 26:  /* Event data instance size = 26 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 27:  /* Event data instance size = 27 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 28:  /* Event data instance size = 28 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 29:  /* Event data instance size = 29 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 30:  /* Event data instance size = 30 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 31:  /* Event data instance size = 31 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 32:  /* Event data instance size = 32 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size32bytes;

         break;
      }
      case 33:  /* Event data instance size = 33 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 34:  /* Event data instance size = 34 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 35:  /* Event data instance size = 35 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 36:  /* Event data instance size = 36 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 37:  /* Event data instance size = 37 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 38:  /* Event data instance size = 38 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 39:  /* Event data instance size = 39 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 40:  /* Event data instance size = 40 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 41:  /* Event data instance size = 41 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 42:  /* Event data instance size = 42 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 43:  /* Event data instance size = 43 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 44:  /* Event data instance size = 44 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 45:  /* Event data instance size = 45 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 46:  /* Event data instance size = 46 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 47:  /* Event data instance size = 47 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 48:  /* Event data instance size = 48 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 49:  /* Event data instance size = 49 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 50:  /* Event data instance size = 50 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 51:  /* Event data instance size = 51 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 52:  /* Event data instance size = 52 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 53:  /* Event data instance size = 53 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 54:  /* Event data instance size = 54 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 55:  /* Event data instance size = 55 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 56:  /* Event data instance size = 56 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 57:  /* Event data instance size = 57 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 58:  /* Event data instance size = 58 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 59:  /* Event data instance size = 59 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 60:  /* Event data instance size = 60 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 61:  /* Event data instance size = 61 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 62:  /* Event data instance size = 62 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 63:  /* Event data instance size = 63 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      case 64:  /* Event data instance size = 64 bytes */
      {
         /* Get the event data pool to allocate memory from */
         eventDataPool = &s_EventDataPool_Size64bytes;

         break;
      }
      default:
      {
         /* CHECK MEMORY ALLOCATIONS FOR SIZES > 64 BYTES */

         if ( instanceSize < 129 )        /* Size 65-128 bytes ? */
         {
            /* This event data pool is not declared */
            eventDataPool = NULL;
         }
         else if ( instanceSize < 257 )   /* Size 129-256 bytes ? */
         {
            /* This event data pool is not declared */
            eventDataPool = NULL;
         }
         else if ( instanceSize < 513 )   /* Size 257-512 bytes ? */
         {
            /* This event data pool is not declared */
            eventDataPool = NULL;
         }
         else if ( instanceSize < 1025 )  /* Size 513-1024 bytes ? */
         {
            /* This event data pool is not declared */
            eventDataPool = NULL;
         }
         else if ( instanceSize < 2049 )  /* Size 1025-2048 bytes ? */
         {
            /* This event data pool is not declared */
            eventDataPool = NULL;
         }
         else if ( instanceSize < 4097 )  /* Size 2049-4096 bytes ? */
         {
            /* This event data pool is not declared */
            eventDataPool = NULL;
         }
         else
         {
            /* The event data instance size to allocate is > 4096 bytes */
            eventDataPool = NULL;
         }
      }
   }

   /* Check if a proper event data pool has been idendified */
   if ( eventDataPool != NULL )
   {
      /* Try to seize an event data instance in the pool */
      seizedInstance = seizePoolElement( eventDataPool );

      /* Check if seizing a free pool element failed */
      if ( seizedInstance == NULL )
      {
         /* Trace output: Event Data Pool is exhausted */
         infoTrace_EventDataPoolIsExhausted( eventDataPool->highWaterMark, instanceSize );

         /* Allocate the event data instance on the heap */
         seizedInstance = malloc( instanceSize );

         /* Check if memory allocation was successful */
         if ( seizedInstance != NULL )
         {
            /* Indicate event data instance heap allocation */
            ((struct _EventDataHeader_*) seizedInstance)->poolElement.next     = NULL;
            ((struct _EventDataHeader_*) seizedInstance)->poolElement.previous = NULL;

            /* Indicate the size of the allocated instance */
            ((struct _EventDataHeader_*) seizedInstance)->sizeInBytes = instanceSize;
         }
         else
         {
            /* Trace output: Pool is exhausted, malloc failed */
            infoTrace_HeapAllocationFailed();
         }
      }
   }
   else
   {
      /* Trace output: Pool not identified */
      infoTrace_EventDataPoolNotIdentified( instanceSize );

      /* Allocate the event data instance on the heap */
      seizedInstance = malloc( instanceSize );

      /* Check if memory allocation was successful */
      if ( seizedInstance != NULL )
      {
         /* Indicate event data instance heap allocation */
         ((struct _EventDataHeader_*) seizedInstance)->poolElement.next     = NULL;
         ((struct _EventDataHeader_*) seizedInstance)->poolElement.previous = NULL;

         /* Indicate the size of the allocated instance */
         ((struct _EventDataHeader_*) seizedInstance)->sizeInBytes = instanceSize;
      }
      else
      {
         /* Trace output: Pool not identified, malloc failed */
         infoTrace_HeapAllocationFailed();
      }
   }

   /* Return the seized GenericEvent instance */
   return seizedInstance;
}

/* ---------------------------------------------------------------------------
 * Function for returning memory for an event data instance.
 * ---------------------------------------------------------------------------
 */
void returnEventDataMemory( void* returnedInstance )
{
   /* Local variable declarations */
   struct TinyPool* eventDataPool;

   /* Get the size of the poolElement to return */
   unsigned long sizeInBytes = ((struct _EventDataHeader_*) returnedInstance)->sizeInBytes;

   /* Get the possible poolElement to return */
   struct TinyPoolElement* returnElement = &((struct _EventDataHeader_*) returnedInstance)->poolElement;

   /* Release memory for the event data structure instance */
   if (( returnElement->next != NULL ) && ( returnElement->previous != NULL ))
   {
      /* The Event Data instance is allocated in a pool */

      /* Identify the size of the event data instance to return */
      switch ( sizeInBytes )
      {
         case 16:  /* Event data instance size = 16 bytes */
         {
            /* Get the event data pool to allocate memory from */
            eventDataPool = &s_EventDataPool_Size16bytes;

            break;
         }
         case 32:  /* Event data instance size = 32 bytes */
         {
            /* Get the event data pool to allocate memory from */
            eventDataPool = &s_EventDataPool_Size32bytes;

            break;
         }
         case 64:  /* Event data instance size = 64 bytes */
         {
            /* Get the event data pool to allocate memory from */
            eventDataPool = &s_EventDataPool_Size64bytes;

            break;
         }
         case 128:  /* Event data instance size = 128 bytes */
         {
            /* Do nothing when event data pool not is declared
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;

            break;
         }
         case 256:  /* Event data instance size = 256 bytes */
         {
            /* Do nothing when event data pool not is declared
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;

            break;
         }
         case 512:  /* Event data instance size = 512 bytes */
         {
            /* Do nothing when event data pool not is declared
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;

            break;
         }
         case 1024:  /* Event data instance size = 1024 bytes */
         {
            /* Do nothing when event data pool not is declared
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;

            break;
         }
         case 2048:  /* Event data instance size = 2048 bytes */
         {
            /* Do nothing when event data pool not is declared
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;

            break;
         }
         case 4096:  /* Event data instance size = 4096 bytes */
         {
            /* Do nothing when event data pool not is declared
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;

            break;
         }
         default:
         {
            /* Do nothing when instance size not was identified
               (NOTE: An exception should be thrown here.) */
            eventDataPool = NULL;
         }
      }

      /* Check if a proper event data pool has been idendified */
      if ( eventDataPool != NULL )
      {
         /* Return the event data instance to the pool */
         returnPoolElement( eventDataPool, returnElement );

         /* Job done: Return immediately */
         return;
      }
   }
   else
   {
      /* The event data instance is allocated on the heap */
      free( returnedInstance );

      /* Check in which event data pool a memory allocation attempt was made */
      if ( sizeInBytes < 17 )        /* Size 1-16 bytes ? */
      {
         /* Get the event data pool in which memory allocation attempt was made */
         eventDataPool = &s_EventDataPool_Size16bytes;
      }
      else if ( sizeInBytes < 33 )   /* Size 17-32 bytes ? */
      {
         /* Get the event data pool in which memory allocation attempt was made */
         eventDataPool = &s_EventDataPool_Size32bytes;
      }
      else if ( sizeInBytes < 65 )   /* Size 33-64 bytes ? */
      {
         /* Get the event data pool in which memory allocation attempt was made */
         eventDataPool = &s_EventDataPool_Size64bytes;
      }
      else if ( sizeInBytes < 129 )   /* Size 65-128 bytes ? */
      {
         /* This event data pool is not declared */
         eventDataPool = NULL;
      }
      else if ( sizeInBytes < 257 )   /* Size 129-256 bytes ? */
      {
         /* This event data pool is not declared */
         eventDataPool = NULL;
      }
      else if ( sizeInBytes < 513 )   /* Size 257-512 bytes ? */
      {
         /* This event data pool is not declared */
         eventDataPool = NULL;
      }
      else if ( sizeInBytes < 1025 )  /* Size 513-1024 bytes ? */
      {
         /* This event data pool is not declared */
         eventDataPool = NULL;
      }
      else if ( sizeInBytes < 2049 )  /* Size 1025-2048 bytes ? */
      {
         /* This event data pool is not declared */
         eventDataPool = NULL;
      }
      else if ( sizeInBytes < 4097 )  /* Size 2049-4096 bytes ? */
      {
         /* This event data pool is not declared */
         eventDataPool = NULL;
      }
      else
      {
         /* The event data instance size to allocate is > 4096 bytes */
         eventDataPool = NULL;
      }

      /* Check if a proper event data pool has been idendified */
      if ( eventDataPool != NULL )
      {
         /* Decrease the number of used instances of pool-element-type.
            (memory is returned to where it was previously allocated) */
         eventDataPool->numberOfUsedElements--;
      }
   }
}

/* ### End of file GenericEvent.c ### */
