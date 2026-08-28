#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"
#include "dynamicArray.h"
#include "errors.h"
#include <stdio.h>
struct Heap {
    DynamicArray* array;
    bool isMinHeap;
    int size;
};

// Create and allocate memory for a heap
// The heap's ordering is based on the parameter isMinHeap
// Return newly created Heap, or NULL in the event of error
Heap* heapCreate(bool isMinHeap)
{
    Heap* heap = malloc(sizeof(heap));
    if (heap == NULL) {
        return NULL;
    }
    heap->array = dynamicArrayCreate();
    if (heap->array == NULL)
    {
        free(heap);
        return NULL;
    }
    // Insert blank cell for easier indexing
    if (dynamicArrayInsert(heap->array, 0, 0) != SUCCESS)
    {
        heapDestroy(heap);
        return NULL;
    }
    heap->isMinHeap = isMinHeap;
    heap->size = 0;
    return heap;
}

// Destroy heap and free allocated memory
// Return success/error code
int heapDestroy(Heap* heap)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    if (heap->array != NULL) {
        dynamicArrayDestroy(heap->array);
    }
    free(heap);
    return SUCCESS;
}

static bool compare(int x, int y, bool isLess)
{
    if (isLess) {
        return x < y;
    }
    return x > y;
}

static int sink(Heap* heap, int index)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    while (index*2 <= heap->size)
    {
        int val = dynamicArrayGet(heap->array, index);
        int leftVal = dynamicArrayGet(heap->array, index*2);
        int rightVal = dynamicArrayGet(heap->array, (index*2) + 1);

        if (rightVal == OUT_OF_BOUNDS_ERROR) {
            rightVal = leftVal;
        }

        int swapVal = leftVal;
        int swapIndex = index * 2;

        if (compare(rightVal, leftVal, heap->isMinHeap))
        {
            swapVal = rightVal;
            swapIndex += 1;
        }
        if (compare(swapVal, val, heap->isMinHeap))
        {
            dynamicArrayReplace(heap->array, index, swapVal);
            dynamicArrayReplace(heap->array, swapIndex, val);
            index = swapIndex;
        }
        else {
            break;
        }
    }
    return SUCCESS;
}

static int swim(Heap* heap, int index)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    while (index > 1)
    {
        int parentVal = dynamicArrayGet(heap->array, index/2);
        int childVal = dynamicArrayGet(heap->array, index);
        if (compare(childVal, parentVal, heap->isMinHeap))
        {
            dynamicArrayReplace(heap->array, index, parentVal);
            dynamicArrayReplace(heap->array, index/2, childVal);
            index /= 2;
        }
        else {
            break;
        }

    }
    return SUCCESS;
}

// Push a value to the heap
// Return success/error code
int heapPush(Heap* heap, int val)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dynamicArrayInsert(heap->array, heap->size + 1, val);
    if (res != SUCCESS) {
        return res;
    }
    heap->size++;
    swim(heap, heap->size);
    return SUCCESS;
}

// Retrieve and remove the top value in the heap
// Return the value, or an error code
int heapPop(Heap* heap)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    if (heap->size == 0) {
        return OUT_OF_BOUNDS_ERROR;
    }
    int popped = dynamicArrayGet(heap->array, 1);
    dynamicArrayReplace(heap->array, 1, dynamicArrayPop(heap->array, heap->size));
    heap->size--;
    sink(heap, 1);
    return popped;
}

// Retrieve the top value in the heap
// Return the value, or an error code
int heapPeek(Heap* heap)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    if (heap->size == 0) {
        return OUT_OF_BOUNDS_ERROR;
    }
    return dynamicArrayGet(heap->array, 1);
}


// Retrieve the size of the heap
// Return the value, or an error code
int heapSize(Heap* heap)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return heap->size;
}