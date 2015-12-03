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
 *  File Name .............. TinyDynArray.c
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include "TinyDynArray.h"
#include "ArchitectureConfig.h"

/* ---------------------------------------------------------------------------
 * Static Interfaces
 * ---------------------------------------------------------------------------
 */

/* ---------------------------------------------------------------------------
 * Class Based Data
 * ---------------------------------------------------------------------------
 */
/* The TinyDynArray pool */
static struct TinyDynArray s_TinyDynArrays[_TinyDynArrayPoolSize];
struct TinyPool gs_TinyDynArrayPool = {NULL, 0, 0, 0, 0};

/* The TinyUntouchableDynArray pool */
static struct TinyUntouchableDynArray s_TinyUntouchableDynArrays[_TinyDynArrayPoolSize];
struct TinyPool gs_TinyUntouchableDynArrayPool = {NULL, 0, 0, 0, 0};

/* ---------------------------------------------------------------------------
 * Function for initializing the TinyDynArray.
 * NOTE: This function must be invoked on startup of the system function.
 * ---------------------------------------------------------------------------
 */
void initialize_TinyDynArray( void )
{
   /* Initialize the TinyDynArray pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_TinyDynArrays[_TinyDynArrayPoolSize - 1].header.poolElement;
      for (index = 0; index < _TinyDynArrayPoolSize; index++)
      {
         theElement            = &s_TinyDynArrays[index].header.poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      gs_TinyDynArrayPool.firstFreeElement      = &s_TinyDynArrays[0].header.poolElement;
      gs_TinyDynArrayPool.numberOfFreeElements  = _TinyDynArrayPoolSize;
      gs_TinyDynArrayPool.theCapacity           = _TinyDynArrayPoolSize;
      gs_TinyDynArrayPool.numberOfUsedElements  = 0;
      gs_TinyDynArrayPool.highWaterMark         = 0;
   }

   /* Initialize the TinyUntouchableDynArray pool */
   {
      unsigned long index;
      struct TinyPoolElement* theElement;
      struct TinyPoolElement* previousElement = &s_TinyUntouchableDynArrays[_TinyDynArrayPoolSize - 1].header.poolElement;
      for (index = 0; index < _TinyDynArrayPoolSize; index++)
      {
         theElement            = &s_TinyUntouchableDynArrays[index].header.poolElement;
         previousElement->next = theElement;
         theElement->previous  = previousElement;
         previousElement       = theElement;
      }
      gs_TinyUntouchableDynArrayPool.firstFreeElement      = &s_TinyUntouchableDynArrays[0].header.poolElement;
      gs_TinyUntouchableDynArrayPool.numberOfFreeElements  = _TinyDynArrayPoolSize;
      gs_TinyUntouchableDynArrayPool.theCapacity           = _TinyDynArrayPoolSize;
      gs_TinyUntouchableDynArrayPool.numberOfUsedElements  = 0;
      gs_TinyUntouchableDynArrayPool.highWaterMark         = 0;
   }
}

/* ---------------------------------------------------------------------------
 * Function for shutting down the TinyDynArray.
 * ---------------------------------------------------------------------------
 */
void shutdown_TinyDynArray( void )
{
}

/* ---------------------------------------------------------------------------
 * Function for allocating memory for a dynamic array.
 *
 * INPUT                DESCRIPTION
 * size_t               The size of the array elements,
 *                      as from the sizeof operator.
 * size_t               The number of elements in the array.
 *
 * RETURNS              DESCRIPTION
 * void*                Pointer to the dynamically allocated array pointer.
 * ---------------------------------------------------------------------------
 */
void *
TinyC_malloc_array( size_t element_size, size_t elements )
{
   /* NOTE: Do we need to align the element_size on an even 16/32/64 bit boundary ??? */

   if (( element_size > 0 ) && ( elements > 0 ))
   {
      /* Allocate the array on the heap */
      void* array = malloc( sizeof( TinyDynArrayHeader ) + sizeof( TinyDynArrayPointer ) + (element_size * elements) );

      if ( array != NULL )
      {
         /* Local variable declarations */
         TinyDynArrayHeader* header_p;
         TinyDynArrayPointer* pointer_p;

         /* Define the TinyDynArrayHeader attributes */
         header_p  = (TinyDynArrayHeader*) array;
         pointer_p = (TinyDynArrayPointer*) ( ((char*) array) + sizeof( TinyDynArrayHeader ) );

         header_p->isUntouchableArray = false;
         header_p->memoryType         = 0;
         header_p->memory             = NULL;
         header_p->deallocFunc        = NULL;
         header_p->isHeapAllocated    = true;
         header_p->array              = pointer_p;
         header_p->allocated_array    = array;
         header_p->capacity           = elements;
         header_p->elements           = elements;
         header_p->element_size       = element_size;

         /* Define the TinyDynArrayPointer attributes */
         pointer_p->array = ((char*) pointer_p) + sizeof( TinyDynArrayPointer );

         /* Back up the user array pointer for runtime error checking
            (corrupted when not using 2-step indirection in external code) */
         header_p->user_array = pointer_p->array;

         /* Return the pointer to the array pointer */
         return ( &pointer_p->array );
      }
      else
      {
         return ( NULL );
      }
   }
   else
   {
      return ( NULL );
   }
}

/* ---------------------------------------------------------------------------
 * Function for allocating zero-initialized memory for a dynamic array.
 *
 * INPUT                DESCRIPTION
 * size_t               The size of the array elements,
 *                      as from the sizeof operator.
 * size_t               The number of elements in the array.
 *
 * RETURNS              DESCRIPTION
 * void*                Pointer to the dynamically allocated array pointer.
 * ---------------------------------------------------------------------------
 */
void *
TinyC_calloc_array( size_t element_size, size_t elements )
{
   /* NOTE: Do we need to align the element_size on an even 16/32/64 bit boundary ??? */

   if (( element_size > 0 ) && ( elements > 0 ))
   {
      /* Check the additional number of elements that must be
         allocated to hold the TinyDynArrayHeader + TinyDynArrayPointer */
      void* array;
      size_t additional_elements = 1;
      if ( (sizeof( TinyDynArrayHeader ) + sizeof( TinyDynArrayPointer )) > element_size )
      {
         /* Calculate the required number of additional elements
            (the simplest way, may cost slightly more in memory for odd element_size's) */
         additional_elements = ( (sizeof( TinyDynArrayHeader ) + sizeof( TinyDynArrayPointer )) / element_size ) + 1;

         /* NOTE: Do we need to align the (additional_elements * element_size) on an even 16/32/64 bit boundary ??? */
      }

      /* Allocate the array on the heap */
      array = calloc( (elements + additional_elements), element_size );

      if ( array != NULL )
      {
         /* Local variable declarations */
         TinyDynArrayHeader* header_p;
         TinyDynArrayPointer* pointer_p;

         /* Get the dynamic array for the user */
         void* dynamic_array = ((char*) array) + (additional_elements * element_size);

         /* Define the TinyDynArrayHeader attributes */
         header_p  = (TinyDynArrayHeader*) array;
         pointer_p = (TinyDynArrayPointer*) ( ((char*) array) + sizeof( TinyDynArrayHeader ) );

         header_p->isUntouchableArray = false;
         header_p->memoryType         = 0;
         header_p->memory             = NULL;
         header_p->deallocFunc        = NULL;
         header_p->isHeapAllocated    = true;
         header_p->array              = pointer_p;
         header_p->allocated_array    = array;
         header_p->capacity           = elements;
         header_p->elements           = elements;
         header_p->element_size       = element_size;

         /* Define the TinyDynArrayPointer attributes */
         pointer_p->array = dynamic_array;

         /* Back up the user array pointer for runtime error checking
            (corrupted when not using 2-step indirection in external code) */
         header_p->user_array = pointer_p->array;

         /* Return the pointer to the array pointer */
         return ( &pointer_p->array );
      }
      else
      {
         return ( NULL );
      }
   }
   else
   {
      return ( NULL );
   }
}

/* ### End of file TinyDynArray.c ### */
