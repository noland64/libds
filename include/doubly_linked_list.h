#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct DoublyLinkedList DoublyLinkedList;

// Create new linked list
DoublyLinkedList* dllCreate(void);

// Destroy the linked list and free its memory
int dllDestroy(DoublyLinkedList* list);

// Insert value at index
int dllInsert(DoublyLinkedList* list, int index, int val);
int dllInsertLeft(DoublyLinkedList* list, int val);
int dllInsertRight(DoublyLinkedList* list, int val);

// Removes value at index
int dllRemove(DoublyLinkedList* list, int index);
int dllRemoveLeft(DoublyLinkedList* list);
int dllRemoveRight(DoublyLinkedList* list);

// Returns value at index
int dllGet(DoublyLinkedList* list, int index);
int dllGetLeft(DoublyLinkedList* list);
int dllGetRight(DoublyLinkedList* list);

// Removes and returns value at index
int dllPop(DoublyLinkedList* list, int index);
int dllPopLeft(DoublyLinkedList* list);
int dllPopRight(DoublyLinkedList* list);

// Returns size of doubly linked list
size_t dll_size(DoublyLinkedList* list);


#endif