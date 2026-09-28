#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include "errors.h"

typedef struct DynamicArray DynamicArray;

// Create a new DynamicArray for elements of size dataSize
// Returns a pointer to the newly created DynamicArray, or NULL if an error was encountered
DynamicArray* dynamicArrayCreate(size_t dataSize);

// Destroy the DynamicArray and free its memory
// Returns SUCCESS, or an appropriate error code
int dynamicArrayDestroy(DynamicArray* array);

// Insert data into the DynamicArray at index
// Accepts a pointer to the data to be inserted into the DynamicArray
// Returns SUCCESS, or an appropriate error code
int dynamicArrayInsert(DynamicArray* array, int index, const void* data);

// Remove data at the given index in the DynamicArray
// Returns SUCCESS, or an appropriate error code
int dynamicArrayRemove(DynamicArray* array, int index);

// Retrieve data at the given index in the DynamicArray
// Accepts a pointer to the buffer the data should be written to
// Returns SUCCESS, or an appropriate error code
int dynamicArrayGet(const DynamicArray* array, int index, void* buffer);

// Pop data at the given index in the DynamicArray
// Accepts a pointer to the buffer the data should be written to
// Returns SUCCESS, or an appropriate error code
int dynamicArrayPop(DynamicArray* array, int index, void* buffer);

// Retrieve the size of DynamicArray
// Accepts a pointer to the buffer the size should be written to
// Returns SUCCESS, or an appropriate error code
size_t dynamicArraySize(const DynamicArray* array);

// Replace existing data at the given index in the DynamicArray with given data
// Accepts a pointer to the data to be inserted into the DynamicArray
// Returns SUCCESS, or an appropriate error code
int dynamicArrayReplace(DynamicArray* array, int index, const void* data);

size_t dynamicArrayBytesPerElement(const DynamicArray* array);
#endif
