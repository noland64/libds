#ifndef HEAP_H
#define HEAP_H
#include <stdbool.h>

typedef struct Heap Heap;

// Create and allocate memory for a heap
// The heap's ordering is based on the parameter isMinHeap
// Return newly created Heap, or NULL in the event of error
Heap* heapCreate(bool isMinHeap);

// Destroy heap and free allocated memory
// Return success/error code
int heapDestroy(Heap* heap);

// Push a value to the heap
// Return success/error code
int heapPush(Heap* heap, int val);

// Retrieve and remove the top value in the heap
// Return the value, or an error code
int heapPop(Heap* heap);

// Retrieve the top value in the heap
// Return the value, or an error code
int heapPeek(Heap* heap);

// Retrieve the size of the heap
// Return the value, or an error code
int heapSize(Heap* queue);

#endif