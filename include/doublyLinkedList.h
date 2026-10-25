#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct DoublyLinkedList DoublyLinkedList;

// Create new linked list
DoublyLinkedList* dllCreate(size_t bytesPerElement);

// Destroy the linked list and free its memory
int dllDestroy(DoublyLinkedList* list);

// Insert value at index
int dllInsert(DoublyLinkedList* list, int index, void* value);
int dllInsertLeft(DoublyLinkedList* list, void* value);
int dllInsertRight(DoublyLinkedList* list, void* value);

// Removes value at index
int dllRemove(DoublyLinkedList* list, int index);
int dllRemoveLeft(DoublyLinkedList* list);
int dllRemoveRight(DoublyLinkedList* list);

// Returns value at index
int dllGet(DoublyLinkedList* list, int index, void* output);
int dllGetLeft(DoublyLinkedList* list, void* output);
int dllGetRight(DoublyLinkedList* list, void* output);

// Removes and returns value at index
int dllPop(DoublyLinkedList* list, int index, void* output);
int dllPopLeft(DoublyLinkedList* list, void* output);
int dllPopRight(DoublyLinkedList* list, void* output);

// Returns size of doubly linked list
size_t dll_size(DoublyLinkedList* list);


#endif