#include <stdlib.h>
#include "dynamicArray.h"
#include "errors.h"

struct DynamicArray
{
    int* arr;
    int num_elems;
    int size;
};

// Create new dynamic array
DynamicArray* dynamicArrayCreate(void)
{
    DynamicArray* array = malloc(sizeof(DynamicArray));
    if (array == NULL) {
        return NULL;
    }
	array->arr = malloc(sizeof(int));
    if (array->arr == NULL)
    {
        free(array);
        return NULL;
    }
	array->size = 1;
	array->num_elems = 0;
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

int dynamicArrayReplace(DynamicArray* array, int index, int val)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= array->num_elems))
        return OUT_OF_BOUNDS_ERROR;
    array->arr[index] = val;
    return SUCCESS;
}

// Insert value at index
int dynamicArrayInsert(DynamicArray* array, int index, int val)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index > array->num_elems))
        return OUT_OF_BOUNDS_ERROR;

    // Double size of array if full
    if (array->num_elems == array->size)
    {
        array->size *= 2;
		array->arr = realloc(array->arr, sizeof(int) * array->size);
    }
    // Shift necessary elements right
    for (int i = array->num_elems; i > index; i--)
    {
        array->arr[i] = array->arr[i-1];
    }
    // Insert new element
    array->arr[index] = val;
    array->num_elems++;
    return 1;
}


// Removes value at index
int dynamicArrayRemove(DynamicArray* array, int index)
{
    // Check for proper input
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= array->num_elems))
        return OUT_OF_BOUNDS_ERROR;

    // Shift necessary items left
    for (int i = index; i < array->num_elems - 1; i++)
    {
        array->arr[i] = array->arr[i+1];
    }
    // Remove item
    array->num_elems--;

    // Shrink array if over half empty
	if ((array->size > 1) && (array->num_elems < (array->size / 4)))
	{
        array->size /= 2;
		array->arr = realloc(array->arr, sizeof(int) * array->size);
	}
    return 1;
}

// Returns value at index
int dynamicArrayGet(DynamicArray* array, int index)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= array->num_elems))
        return OUT_OF_BOUNDS_ERROR;
    return array->arr[index];
}

// Removes and returns value at index
int dynamicArrayPop(DynamicArray* array, int index)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= array->num_elems))
        return OUT_OF_BOUNDS_ERROR;
    int val = dynamicArrayGet(array, index);
    dynamicArrayRemove(array, index);
    return val;
}

// Returns size of array
int dynamicArraySize(DynamicArray* array)
{
    if (array == NULL)
        return NULL_OBJECT_ERROR;
    return array->num_elems;
}