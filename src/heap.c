#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "heap.h"
#include "dynamicArray.h"
#include "errors.h"
#include <stdio.h>

struct Heap {
    DynamicArray* array;
    int (*comparator)(const void*, const void*);
    size_t size;
};

// Create and allocate memory for a heap
// The heap's ordering is based on the parameter isMinHeap
// Return newly created Heap, or NULL in the event of error
Heap* heapCreate(size_t dataSize, int (*comparator)(const void*, const void*))
{
    Heap* heap = malloc(sizeof(Heap));
    if (heap == NULL) {
        return NULL;
    }
    heap->array = dynamicArrayCreate(dataSize);
    if (heap->array == NULL)
    {
        free(heap);
        return NULL;
    }
    // Insert blank cell for easier indexing
    void* blankData = calloc(1, dataSize);
    if (dynamicArrayInsert(heap->array, 0, blankData) != SUCCESS)
    {
        heapDestroy(heap);
        free(blankData);
        return NULL;
    }
    free(blankData);
    heap->comparator = comparator;
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
/*
static bool compare(int x, int y, bool isLess)
{
    if (isLess) {
        return x < y;
    }
    return x > y;
}
*/
static int sink(Heap* heap, int index)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    while (index*2 <= heap->size)
    {
        size_t arrDataSize = dynamicArrayBytesPerElement(heap->array);
        void* val = malloc(arrDataSize);
        void* leftVal = malloc(arrDataSize);
        void* rightVal = malloc(arrDataSize);
        dynamicArrayGet(heap->array, index, val);
        dynamicArrayGet(heap->array, (index*2), leftVal);
        dynamicArrayGet(heap->array, (index*2)+1, rightVal);

        if (dynamicArrayGet(heap->array, (index*2)+1, rightVal) == OUT_OF_BOUNDS_ERROR) {
            memcpy(rightVal, leftVal, arrDataSize);
        }

        void* swapVal = leftVal;
        size_t swapIndex = index * 2;

        if (heap->comparator(rightVal, leftVal) > 0)
        {
            swapVal = rightVal;
            swapIndex += 1;
        }
        if (heap->comparator(swapVal, val) > 0)
        {
            dynamicArrayReplace(heap->array, index, swapVal);
            dynamicArrayReplace(heap->array, swapIndex, val);
            index = swapIndex;
        }
        else {
            index = swapIndex;
        }
        free(val);
        free(leftVal);
        free(rightVal);
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
        size_t arrDataSize = dynamicArrayBytesPerElement(heap->array);
        void* parentVal = malloc(arrDataSize);
        void* childVal = malloc(arrDataSize);
        dynamicArrayGet(heap->array, index/2, parentVal);
        dynamicArrayGet(heap->array, index, childVal);
        if (heap->comparator(childVal, parentVal) > 0)
        {
            dynamicArrayReplace(heap->array, index, parentVal);
            dynamicArrayReplace(heap->array, index/2, childVal);
            index /= 2;
        }
        else {
            index /= 2;
        }
        free(parentVal);
        free(childVal);
    }
    return SUCCESS;
}

// Push a value to the heap
// Return success/error code
int heapPush(Heap* heap, const void* data)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dynamicArrayInsert(heap->array, heap->size + 1, data);
    if (res != SUCCESS) {
        return res;
    }
    heap->size++;
    swim(heap, heap->size);
    return SUCCESS;
}

// Retrieve and remove the top value in the heap
// Return the value, or an error code
int heapPop(Heap* heap, void* buffer)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    if (heap->size == 0) {
        return OUT_OF_BOUNDS_ERROR;
    }
    size_t arrDataSize = dynamicArrayBytesPerElement(heap->array);
    // Write top value to buffer
    dynamicArrayGet(heap->array, 1, buffer);
    // Copy final heap element to temporary storage
    void* lastElem = malloc(arrDataSize);
    dynamicArrayGet(heap->array, heap->size, lastElem);
    dynamicArrayReplace(heap->array, 1, lastElem);
    free(lastElem);
    // Decrement heap size and sink top element
    heap->size--;
    sink(heap, 1);
    return SUCCESS;
}

// Retrieve the top value in the heap
// Return the value, or an error code
int heapPeek(const Heap* heap, void* buffer)
{
    if (heap == NULL) {
        return NULL_OBJECT_ERROR;
    }
    if (heap->size == 0) {
        return OUT_OF_BOUNDS_ERROR;
    }
    // Write top value to buffer
    dynamicArrayGet(heap->array, 1, buffer);
    return SUCCESS;
}

// Retrieve the size of the heap
// Return the value, or an error code
size_t heapSize(const Heap* heap)
{
    if (!heap) {
        return 0;
    }
    return heap->size;
}