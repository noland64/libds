#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct DoublyLinkedList DoublyLinkedList;

// Create new linked list
DoublyLinkedList* doubly_linked_list_create(void);

// Destroy the linked list and free its memory
int doubly_linked_list_destroy(DoublyLinkedList* list);

// Insert value at index
int doubly_linked_list_insert(DoublyLinkedList* list, int index, int val);

// Removes value at index
int doubly_linked_list_remove(DoublyLinkedList* list, int index);

// Returns value at index
int doubly_linked_list_get(DoublyLinkedList* list, int index);

// Removes and returns value at index
int doubly_linked_list_pop(DoublyLinkedList* list, int index);

// Returns size of doubly linked list
size_t doubly_linked_list_size(DoublyLinkedList* list);


#endif