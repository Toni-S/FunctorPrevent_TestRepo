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
 *  File Name .............. TinyDynArray.h
 *
 *  Model Compiler Design .. Toni Siljamäki
 *
 */

/* ---------------------------------------------------------------------------
 * The TinyDynArray defines dynamic array functions needed by the TinyC arch.
 * ---------------------------------------------------------------------------
 */
#ifndef TINYDYNARRAY_H
#define TINYDYNARRAY_H

#ifdef __cplusplus
extern "C" {
#endif

/* ---------------------------------------------------------------------------
 * Imported Interfaces, Types & Definitions
 * ---------------------------------------------------------------------------
 */
#include <string.h>             /* Definition of size_t */
#include "TinyPool.h"
#include <stdlib.h>
#include <stdio.h>

/* ---------------------------------------------------------------------------
 * Exported Types & Definitions
 * ---------------------------------------------------------------------------
 */
/* External memory deallocation function pointer type */
typedef void ( *ExtMemDeaFuncPtrType )( int memoryType, void* memory );

/* The TinyDynArrayHeader Structure */
struct TinyDynArrayHeader;
typedef struct TinyDynArrayHeader TinyDynArrayHeader;

struct TinyDynArrayHeader
{
/* The TinyPoolElement member for TinyDynArray pool elements
   (holding the doubly-linked list pointers for the pool) */
   struct TinyPoolElement poolElement;

/* UNTOUCHABLE ARRAY SECTION */

/* Indication if this is an untouchable array
   (not to be "touched", must have same fixed size) */
   fastBool isUntouchableArray;

/* Indication which type of external memory to later be
   deallocated when the array has been consumed */
   int memoryType;

/* Pointer to the external memory to be deallocated
   (NULL if there is no memory to deallocate) */
   void* memory;

/* Pointer to the function for deallocating
   this external memory */
   ExtMemDeaFuncPtrType deallocFunc;

/* COMMON ARRAY SECTION */

/* Indication if array is allocated on the heap
   (otherwise it is allocated in the pool) */
   fastBool isHeapAllocated;

/* Pointer to the dynamic array pointer */
   void* array;

/* Pointer to the allocated header+array */
   void* allocated_array;

/* Pointer to the user array, only used for checking that
   the "real" user array pointer has not been corrupted
   (e.g. by external code not using 2-step indirection) */
   void* user_array;

/* The current capacity of the array */
   size_t capacity;

/* The number of elements in the array */
   size_t elements;

/* The size of elements in the array */
   size_t element_size;
};

/* The TinyDynArrayPointer Structure */
struct TinyDynArrayPointer;
typedef struct TinyDynArrayPointer TinyDynArrayPointer;

struct TinyDynArrayPointer
{
/* NOTE: This is the pointer that dynamic array variables etc.
   are pointing at, as a pointer-to-a-pointer value. This also
   allows for the actual array to be allocated anywhere, in order
   to pave the way for "untouchable arrays" in external memory. */

/* Pointer to the user array */
   void* array;
};

/* The TinyDynArray Structure */
struct TinyDynArray;
typedef struct TinyDynArray TinyDynArray;

struct TinyDynArray
{
/* The TinyDynArray header */
   struct TinyDynArrayHeader header;

/* The TinyDynArray pointer */
   struct TinyDynArrayPointer pointer;

/* The actual array */
   char array[ _TinyDynArraySize * _TinyDynArrayElementSize ];
};

/* The TinyUntouchableDynArray Structure */
struct TinyUntouchableDynArray;
typedef struct TinyUntouchableDynArray TinyUntouchableDynArray;

struct TinyUntouchableDynArray
{
/* The TinyDynArray header */
   struct TinyDynArrayHeader header;

/* The TinyDynArray pointer */
   struct TinyDynArrayPointer pointer;
};

/* Define deleted [] array indicator. */
#if defined WIN32
   /* Use the same debug pointer value as in MSVC, so that
      we do not get any heap crash when debugging in MSVC. */
   #define IsDeletedTinyDynArray ((void*) 0xFEEEFEEE)
#else
   #define IsDeletedTinyDynArray ((void*) -1)
#endif

/* ---------------------------------------------------------------------------
 * Exported Interfaces
 * ---------------------------------------------------------------------------
 */
/* Function for initializing the TinyDynArray.
   NOTE: This function must be invoked on startup of the system function. */
void initialize_TinyDynArray( void );

/* Function for shutting down the TinyDynArray. */
void shutdown_TinyDynArray( void );

/* Function for allocating memory for a dynamic array. */
void *
TinyC_malloc_array( size_t element_size, size_t elements );

/* Function for allocating zero-initialized memory for a dynamic array. */
void *
TinyC_calloc_array( size_t element_size, size_t elements );

/* Function for retrieving the size of a dynamic array. */
__inlined__ size_t
TinyC_sizeof_array( void* array );

/* Function for releasing memory for a dynamic array. */
__inlined__ void
TinyC_free_array( void* array );

/* Function for size test of a dynamic array. */
__inlined__ void *
TinyC_touch_array( void* array, size_t element_size, size_t index );

/* Function for creating an untouchable "dynamic" array from external code.
   (any deallocation of array/message memory must be handled by external code) */
__inlined__ void *
TinyC_create_untouchable_array( int memoryType, void* memory, ExtMemDeaFuncPtrType deallocFunc,
                                void* array, size_t element_size, size_t elements );

/* Label for direct access to the TinyDynArray pool
   (for seizing pre-allocated TinyDynArray instances) */
extern struct TinyPool gs_TinyDynArrayPool;

/* Label for direct access to the TinyUntouchableDynArray pool
   (for seizing pre-allocated TinyUntouchableDynArray instances) */
extern struct TinyPool gs_TinyUntouchableDynArrayPool;

/* ---------------------------------------------------------------------------
 * Function for retrieving the size of a dynamic array.
 *
 * INPUT                DESCRIPTION
 * void*                Pointer to the dynamic array.
 *
 * RETURNS              DESCRIPTION
 * size_t               The size of the dynamic array.
 * ---------------------------------------------------------------------------
 */
__inlined__ size_t
TinyC_sizeof_array( void* array )
{
   /* Check if this array exist */
   if ( array != NULL )
   {
      /* Local variable declarations */
      TinyDynArrayHeader* header_p;
      TinyDynArrayPointer* pointer_p;

      header_p  = (TinyDynArrayHeader*) ( ((char*) array) - sizeof( TinyDynArrayHeader ) );
      pointer_p = (TinyDynArrayPointer*) array;

      /* Check that memory for this array not has been released */
      if ( header_p->array != IsDeletedTinyDynArray )
      {
         /* Check that this array has been allocated by TinyDynArray
            and that the user array pointer not has been corrupted
            (e.g. when not using 2-step indirection in external code) */
         if (( header_p->array == array ) && ( pointer_p->array == header_p->user_array ))
         {
            /* Return the number of elements in this array */
            return ( header_p->elements );
         }
         else
         {
            printf( "####### TinyDynArray::TinyC_sizeof_array called - This array is corrupt or not allocated by TinyDynArray\n" );
            return ( -1 );
         }
      }
      else
      {
         printf( "####### TinyDynArray::TinyC_sizeof_array called - Memory for this array has been released\n" );
         return ( 0 );
      }
   }
   else
   {
      return ( 0 );
   }
}

/* ---------------------------------------------------------------------------
 * Function for releasing memory for a dynamic array.
 *
 * INPUT                DESCRIPTION
 * void*                Pointer to the dynamic array.
 * ---------------------------------------------------------------------------
 */
__inlined__ void
TinyC_free_array( void* array )
{
   /* Check if this array exist */
   if ( array != NULL )
   {
      /* Local variable declarations */
      TinyDynArrayHeader* header_p;
      TinyDynArrayPointer* pointer_p;

      header_p  = (TinyDynArrayHeader*) ( ((char*) array) - sizeof( TinyDynArrayHeader ) );
      pointer_p = (TinyDynArrayPointer*) array;

      /* Check that memory for this array not already has been released */
      if ( header_p->array != IsDeletedTinyDynArray )
      {
         /* Check that this array has been allocated by TinyDynArray
            and that the user array pointer not has been corrupted
            (e.g. when not using 2-step indirection in external code) */
         if (( header_p->array == array ) && ( pointer_p->array == header_p->user_array ))
         {
            /* Get (backup) untouchable array info - in case of heap allocated header
               (can not access this info if heap memory for header is released) */
            fastBool isUntouchableArray      = header_p->isUntouchableArray;
            int memoryType                   = header_p->memoryType;
            void* memory                     = header_p->memory;
            ExtMemDeaFuncPtrType deallocFunc = header_p->deallocFunc;

            /* Prepare attributes for a deleted array */
            void* allocated_array     = header_p->allocated_array;
            header_p->array           = IsDeletedTinyDynArray;
            header_p->allocated_array = NULL;
            header_p->user_array      = IsDeletedTinyDynArray;
            header_p->elements        = 0;

            /* Clear the real user array pointer to prevent
               possible illegal access by external code */
            pointer_p->array = NULL; 

            /* Check if the array is allocated on the heap */
            if ( header_p->isHeapAllocated )
            {
               /* Release memory on the heap */
               free ( allocated_array );
            }
            else
            {
               /* Check if this is an untouchable array from external code */
               if ( isUntouchableArray )
               {
                  /* The TinyUntouchableDynArray instance is allocated in the pool */
                  returnPoolElement( &gs_TinyUntouchableDynArrayPool, &header_p->poolElement );
               }
               else
               {
                  /* The TinyDynArray instance is allocated in the pool */
                  returnPoolElement( &gs_TinyDynArrayPool, &header_p->poolElement );
               }
            }

            /* Check if this is an untouchable array from external code
               and external memory needs to be deallocated */
            if (( isUntouchableArray ) && ( memory ))
            {
               /* Call the function for deallocating this external memory */
               deallocFunc( memoryType, memory );
            }
         }
         else
         {
            /* Check if memory is allocated for this array */
            if ( header_p->allocated_array != NULL )
            {
               printf( "####### TinyDynArray::TinyC_free_array called - This array is corrupt or not allocated by TinyDynArray\n" );
            }
         }
      }
      else
      {
         printf( "####### TinyDynArray::TinyC_free_array called - Memory for this array has already been released\n" );
      }
   }
}

/* ---------------------------------------------------------------------------
 * Function for size test of a dynamic array.
 *
 * INPUT                DESCRIPTION
 * void*                Pointer to the dynamic array.
 *                      NULL means that the array must be created.
 *                      (memory for the array must be allocated)
 * size_t               The size of the array elements,
 *                      as from the sizeof operator.
 * size_t               The touched (indexed) element in the array.
 *
 * RETURNS              DESCRIPTION
 * void*                Pointer to the dynamically allocated array.
 *                      Pointer to the new array when reallocated & copied.
 * ---------------------------------------------------------------------------
 */
__inlined__ void *
TinyC_touch_array( void* array, size_t element_size, size_t index )
{
   /* Local variable declarations */
   void* touched_array = array;
   TinyDynArrayHeader* header_p;
   TinyDynArrayPointer* pointer_p;

   /* Check if this array exist */
   if ( array != NULL )
   {
      header_p  = (TinyDynArrayHeader*) ( ((char*) array) - sizeof( TinyDynArrayHeader ) );
      pointer_p = (TinyDynArrayPointer*) array;

      /* Check that memory for this array not has been released */
      if ( header_p->array != IsDeletedTinyDynArray )
      {
         /* Check that this array has been allocated by TinyDynArray
            and that the user array pointer not has been corrupted
            (e.g. when not using 2-step indirection in external code) */
         if (( header_p->array == array ) && ( pointer_p->array == header_p->user_array ))
         {
            /* Check if we are indexing out of array bounds */
            if ( index >= header_p->capacity )
            {
               /* Check that this not is an untouchable array from external code */
               if ( !(header_p->isUntouchableArray) )
               {
                  /* Allocate an array of the larger and needed size */
                  void *new_array = TinyC_malloc_array( header_p->element_size, (index + 1) );

                  printf( "####### TinyDynArray::TinyC_touch_array called - REALLOCATION - current size is = %d, needed size is = %d\n", header_p->elements, (index + 1) );

                  if ( new_array != NULL )
                  {
                     /* Get the pointers to the real arrays */
                     TinyDynArrayPointer* src_p  = (TinyDynArrayPointer*) array;
                     TinyDynArrayPointer* dest_p = (TinyDynArrayPointer*) new_array;

                     /* Copy the array content into the reallocated array */
                     (void) memcpy( dest_p->array, src_p->array, TinyC_sizeof_array( array ) * header_p->element_size );
                     TinyC_free_array( array );
                     touched_array = new_array;
                  }
                  else
                  {
                     touched_array = NULL;
                  }
               }
               else
               {
                  printf( "####### TinyDynArray::TinyC_touch_array called - Indexing out of array bounds of an external array - size is = %d, index is = %d\n", header_p->elements, index );
                  touched_array = NULL;
               }
            }
            else
            {
               /* Check if the number of actual elements in the array has increased */
               if ( index >= header_p->elements )
               {
                  /* Set the increased number of elements value */
                  header_p->elements = index + 1;
               }
            }
         }
         else
         {
            printf( "####### TinyDynArray::TinyC_touch_array called - This array is corrupt or not allocated by TinyDynArray\n" );
            touched_array = NULL;
         }
      }
      else
      {
         printf( "####### TinyDynArray::TinyC_touch_array called - Memory for this array has been released\n" );
         touched_array = NULL;
      }
   }
   else
   {
      /* Check if this is a TinyDynArray pool element sized array
         and that we don't try to allocate an array larger than the pool arrays */
      if (( element_size == _TinyDynArrayElementSize ) && ( index < _TinyDynArraySize ))
      {
         /* Try to seize a TinyDynArray instance in the pool for this newly created array */
         struct TinyDynArray* array = (struct TinyDynArray*) seizePoolElement( &gs_TinyDynArrayPool );

         /* Check if seizing a free pool element was successful */
         if ( array )
         {
            /* Define the TinyDynArrayHeader attributes */
            header_p  = (TinyDynArrayHeader*) array;
            pointer_p = (TinyDynArrayPointer*) ( ((char*) array) + sizeof( TinyDynArrayHeader ) );

            header_p->isUntouchableArray = false;
            header_p->memoryType         = 0;
            header_p->memory             = NULL;
            header_p->deallocFunc        = NULL;
            header_p->isHeapAllocated    = false;
            header_p->array              = pointer_p;
            header_p->allocated_array    = array;
            header_p->capacity           = _TinyDynArraySize;
            header_p->elements           = index + 1;
            header_p->element_size       = element_size;

            /* Define the TinyDynArrayPointer attributes */
            pointer_p->array = ((char*) pointer_p) + sizeof( TinyDynArrayPointer );

            /* Back up the user array pointer for runtime error checking
               (corrupted when not using 2-step indirection in external code) */
            header_p->user_array = pointer_p->array;

            /* Return the pointer to the array pointer */
            touched_array = &pointer_p->array;
         }
         else
         {
            /* Allocate memory for this newly created array */
            touched_array = TinyC_malloc_array( element_size, (index + 1) );
         }
      }
      else
      {
         /* Allocate memory for this newly created array */
         touched_array = TinyC_malloc_array( element_size, (index + 1) );
      }
   }

   return ( touched_array );
}

/* ---------------------------------------------------------------------------
 * Function for creating an untouchable "dynamic" array from external code.
 * (any deallocation of array/message memory must be handled by external code)
 *
 * NOTE:
 *
 * External code can call e.g the TinyC_touch_array function for creating a
 * dynamic array and pass it to generated code as a dynamic array, meaning
 * that the array can be "touched" again to change its size whenever needed.
 * This is all controlled from OAL generated code from the model.
 *
 * This may NOT AT ALL be what external code like generated code to do,
 * that is, change the size of the array passed to it from external code.
 *
 * External code often need to create "dynamic" arrays from arrays e.g. in
 * incoming messages from other external code, but where the ONLY thing dynamic
 * about it is that different messages can have different sized arrays,
 * like different sized byte streams in messages from some network.
 * (= create arrays with different number of valid elements)
 *
 * These array declarations in legacy OSE signal files are typically incomplete,
 * where the array is declared only as a pointer to a [1] sized array.
 *
 * The thing here is: Once this array has been created, it MUST continue to have
 * the same fixed size and is not allowed not be "touched" by OAL generated code.
 *
 * This means that we can simply copy the pointer pointing at the original
 * array and pass it to generated code as a dynamic [] array, thus eliminating
 * the need to copy the array content between two arrays.
 *
 * When creating and passing such an untouchable array it means that
 * generated code will not be able to "touch" the array to change it's size,
 * which happens for real dynamic [] arrays when indexing out of array bounds.
 *
 * Generated code will still believe that this is a dynamic [] array, and as
 * long as we don't index it out of array bounds everything will work just fine.
 *
 * IMPORTANT 1:
 *
 * When creating an untouchable array and simply copy the array pointer,
 * it may be the case that the real array itself is located in some piece of
 * memory that must de deallocated when the array has been consumed.
 * This memory could be some dynamically allocated buffer, an OSE signal etc.
 *
 * For this reason the external code also must provide a function for
 * deallocating this memory when the array has been consumed, and also
 * keep track of what type of memory that must be deallocated.
 *
 * This function will then be called from the TinyC_free_array function.
 *
 * IMPORTANT 2:
 *
 * When creating and/or accessing dynamic arrays in external code it is of
 * utmost importance to use a 2-step indirection when accessing these arrays.
 * Example for "by value" access     : (**myDynArray)[index] = 123;
 * Example for "by reference" access : (*(**myDynArray))[index] = 123;
 * When using a 1-step indirection, THE ARRAY POINTER WILL BE CORRUPTED !!!
 *
 * FINALLY:
 *
 * Using this function, any external code can create something which
 * generated code believes is a dynamic [] array, but where the actual array
 * has been allocated by some external code in some arbitrary memory.
 * The only restriction is that generated code can not (= is not allowed to)
 * alter the size of this array, so it can not be indexed out of array bounds.
 *
 *
 * INPUT                 DESCRIPTION
 * int                   The type of external memory to later be
 *                       deallocated when the array has been consumed.
 * void*                 Pointer to the external memory to be deallocated.
 *                       NULL if there is no memory to deallocate.
 * ExtMemDeaFuncPtrType  Pointer to the function for deallocating
 *                       this external memory.
 * void*                 Pointer to the untouchable array.
 * size_t                The size of the array elements,
 *                       as from the sizeof operator.
 * size_t                The number of elements in the array.
 *
 * RETURNS               DESCRIPTION
 * void*                 Pointer to the created untouchable array.
 * ---------------------------------------------------------------------------
 */
__inlined__ void *
TinyC_create_untouchable_array( int memoryType, void* memory, ExtMemDeaFuncPtrType deallocFunc,
                                void* array, size_t element_size, size_t elements )
{
   /* Local variable declarations */
   void* untouchable_array = NULL;
   TinyDynArrayHeader* header_p;
   TinyDynArrayPointer* pointer_p;

   /* Try to seize a TinyUntouchableDynArray instance in the pool for this newly created array */
   struct TinyUntouchableDynArray* untouchArray = (struct TinyUntouchableDynArray*) seizePoolElement( &gs_TinyUntouchableDynArrayPool );

   /* Check if seizing a free pool element was successful */
   if ( untouchArray )
   {
      /* Define the TinyDynArrayHeader attributes */
      header_p  = (TinyDynArrayHeader*) untouchArray;
      pointer_p = (TinyDynArrayPointer*) ( ((char*) untouchArray) + sizeof( TinyDynArrayHeader ) );

      header_p->isUntouchableArray = true;
      header_p->memoryType         = memoryType;
      header_p->memory             = memory;
      header_p->deallocFunc        = deallocFunc;
      header_p->isHeapAllocated    = false;
      header_p->array              = pointer_p;
      header_p->allocated_array    = untouchArray;
      header_p->capacity           = elements;
      header_p->elements           = elements;
      header_p->element_size       = element_size;

      /* Define the TinyDynArrayPointer attributes */
      pointer_p->array = array;

      /* Back up the user array pointer for runtime error checking
         (corrupted when not using 2-step indirection in external code) */
      header_p->user_array = pointer_p->array;

      /* Return the pointer to the array pointer */
      untouchable_array = &pointer_p->array;
   }
   else
   {
      /* Allocate memory for this newly created array */
      void* untouchArray = malloc( sizeof( TinyUntouchableDynArray ) );

      if ( untouchArray != NULL )
      {
         /* Define the TinyDynArrayHeader attributes */
         header_p  = (TinyDynArrayHeader*) untouchArray;
         pointer_p = (TinyDynArrayPointer*) ( ((char*) untouchArray) + sizeof( TinyDynArrayHeader ) );

         header_p->isUntouchableArray = true;
         header_p->memoryType         = memoryType;
         header_p->memory             = memory;
         header_p->deallocFunc        = deallocFunc;
         header_p->isHeapAllocated    = true;
         header_p->array              = pointer_p;
         header_p->allocated_array    = untouchArray;
         header_p->capacity           = elements;
         header_p->elements           = elements;
         header_p->element_size       = element_size;

         /* Define the TinyDynArrayPointer attributes */
         pointer_p->array = array;

         /* Back up the user array pointer for runtime error checking
            (corrupted when not using 2-step indirection in external code) */
         header_p->user_array = pointer_p->array;

         /* Return the pointer to the array pointer */
         untouchable_array = &pointer_p->array;
      }
      else
      {
         /* Heap allocation failed */
         untouchable_array = NULL;
      }
   }

   return ( untouchable_array );
}

#ifdef __cplusplus
}
#endif

#endif /* TINYDYNARRAY_H */
