#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct LinkedList LinkedList;

// Create new linked list
LinkedList* linkedListCreate(size_t bytesPerElement);

// Destroy the linked list and free its memory
int linkedListDestroy(LinkedList* list);

// Insert value at index
int linkedListInsert(LinkedList* list, int index, void* value);

// Removes value at index
int linkedListRemove(LinkedList* list, int index);

// Returns value at index
int linkedListGet(LinkedList* list, int index, void* output);

// Removes and returns value at index
int linkedListPop(LinkedList* list, int index, void* output);

// Returns size of linked list
size_t linkedListSize(LinkedList* list);

#endif