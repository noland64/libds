#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct DynamicArray DynamicArray;

// Create new dynamic array
DynamicArray* dynamicArrayCreate(void);

// Destroy the dynamic array and free its memory
int dynamicArrayDestroy(DynamicArray* array);

// Insert value at index
int dynamicArrayInsert(DynamicArray* array, int index, int val);

// Removes value at index
int dynamicArrayRemove(DynamicArray* array, int index);

// Returns value at index
int dynamicArrayGet(DynamicArray* array, int index);

// Removes and returns value at index
int dynamicArrayPop(DynamicArray* array, int index);

// Returns size of array
int dynamicArraySize(DynamicArray* array);

int dynamicArrayReplace(DynamicArray* array, int index, int val);
/*
// Returns a string representing the elements of the array
char* DynamicArraystring(DynamicArray* array);
*/
#endif