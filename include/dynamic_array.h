#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define NULL_OBJECT_ERROR -7777
#define OUT_OF_BOUNDS_ERROR -8888

#include <stdbool.h>


typedef struct DynamicArray DynamicArray;

// Create new dynamic array
DynamicArray* dynamic_array_create();

// Destroy the dynamic array and free its memory
int dynamic_array_destroy(DynamicArray* array);

// Insert value at index
int dynamic_array_insert(DynamicArray* array, int index, int val);

// Removes value at index
int dynamic_array_remove(DynamicArray* array, int index);

// Returns value at index
int dynamic_array_get(DynamicArray* array, int index);

// Removes and returns value at index
int dynamic_array_pop(DynamicArray* array, int index);

// Returns size of array
int dynamic_array_size(DynamicArray* array);

/*
// Returns a string representing the elements of the array
char* dynamic_array_string(DynamicArray* array);
*/
#endif