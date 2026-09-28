#include <stdlib.h>
#include <string.h>
#include "dynamicArray.h"
#include "errors.h"

struct DynamicArray
{
    void* arr;
    size_t capacity;
    size_t size;
    size_t bytesPerElement;
};

// Create new dynamic array
DynamicArray* dynamicArrayCreate(size_t bytesPerElement)
{
    if (bytesPerElement == 0) {
        return NULL;
    }
    DynamicArray* array = malloc(sizeof(DynamicArray));
    if (array == NULL) {
        return NULL;
    }
    array->arr = malloc(bytesPerElement);
    if (array->arr == NULL)
    {
        free(array);
        return NULL;
    }
    array->capacity = 1;
    array->size = 0;
    array->bytesPerElement = bytesPerElement;
    return array;
}

// Destroy the dynamic array and free its memory
int dynamicArrayDestroy(DynamicArray* array)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    free(array->arr);
    free(array);
    return 1;
}

int dynamicArrayReplace(DynamicArray* array, int index, const void* data)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || ((size_t) index >= array->size))
        return OUT_OF_BOUNDS_ERROR;
    size_t byteOffset = index * array->bytesPerElement;
    memcpy((char*) array->arr + byteOffset, data, array->bytesPerElement);
    return SUCCESS;
}

// Insert value at index
int dynamicArrayInsert(DynamicArray* array, int index, const void* data)
{
    if ((!array) || (!data))
        return NULL_OBJECT_ERROR;
    if ((index < 0) || ((size_t) index > array->size))
        return OUT_OF_BOUNDS_ERROR;

    // Double size of array if full
    if (array->size == array->capacity)
    {
        array->capacity *= 2;
        array->arr = realloc(array->arr, array->bytesPerElement * array->capacity);
    }
    // Shift necessary elements right
    size_t byteOffset = array->size * array->bytesPerElement;
    for (size_t i = array->size; i > (size_t) index; i--)
    {
        mempcpy((char*) array->arr + byteOffset,
                (char*) array->arr + byteOffset - array->bytesPerElement,
                array->bytesPerElement);
        byteOffset -= array->bytesPerElement;
    }
    // Insert new element
    memcpy((char*) array->arr + byteOffset, data, array->bytesPerElement);
    array->size++;
    return SUCCESS;
}


// Removes value at index
int dynamicArrayRemove(DynamicArray* array, int index)
{
    // Check for proper input
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || ((size_t) index >= array->size))
        return OUT_OF_BOUNDS_ERROR;

    // Shift necessary items left
    for (size_t i = (size_t) index; i < array->size - 1; i++)
    {
        size_t byteOffset = i * array->bytesPerElement;
        memcpy((char*) array->arr + byteOffset,
               (char*) array->arr + byteOffset + array->bytesPerElement,
               array->bytesPerElement);
    }
    // Remove item
    array->size--;

    // Shrink array if over half empty
    if ((array->capacity > 1) && (array->size < (array->capacity / 4)))
    {
        array->capacity /= 2;
        array->arr = realloc(array->arr, array->bytesPerElement * array->capacity);
    }
    return 1;
}

// Returns value at index
int dynamicArrayGet(const DynamicArray* array, int index, void* buffer)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || ((size_t) index >= array->size))
        return OUT_OF_BOUNDS_ERROR;
    size_t byteOffset = (size_t) index * array->bytesPerElement;
    memcpy(buffer, (char*) array->arr + byteOffset, array->bytesPerElement);
    return SUCCESS;
}

// Removes and returns value at index
int dynamicArrayPop(DynamicArray* array, int index, void* buffer)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || ((size_t) index >= array->size))
        return OUT_OF_BOUNDS_ERROR;
    dynamicArrayGet(array, index, buffer);
    dynamicArrayRemove(array, index);
    return SUCCESS;
}

// Returns size of array
size_t dynamicArraySize(const DynamicArray* array)
{
    if (array == NULL)
        return 0;
    return array->size;
}

size_t dynamicArrayBytesPerElement(const DynamicArray* array)
{
    if (!array) {
        return 0;
    }
    return array->bytesPerElement;
}
