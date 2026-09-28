#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>
#include "errors.h"

typedef struct Heap Heap;

// Create and allocate memory for a heap
// The heap's ordering is based on the callback function comparator
// Return newly created Heap, or NULL in the event of error
Heap* heapCreate(size_t dataSize, int (*comparator)(const void*, const void*));

// Destroy heap and free allocated memory
// Return success/error code
int heapDestroy(Heap* heap);

// Push data to the heap
// Accepts pointer to the data to be pushed
// Return success/error code
int heapPush(Heap* heap, const void* data);

// Retrieve and remove the top value in the heap
// Accepts a pointer to the buffer to write the result
// Return success/error code
int heapPop(Heap* heap, void* buffer);

// Retrieve the top value in the heap
// Accepts a pointer to the buffer to write the result
// Return success/error code
int heapPeek(const Heap* heap, void* buffer);

// Retrieve the size of the heap
// Accepts a pointer to the buffer to write the size to
// Return success/error code
size_t heapSize(const Heap* heap);

#endif
