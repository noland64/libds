#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct LinkedList LinkedList;

// Create new linked list
LinkedList* linked_list_create(void);

// Destroy the linked list and free its memory
int linked_list_destroy(LinkedList* list);

// Insert value at index
int linked_list_insert(LinkedList* list, int index, int val);

// Removes value at index
int linked_list_remove(LinkedList* list, int index);

// Returns value at index
int linked_list_get(LinkedList* list, int index);

// Removes and returns value at index
int linked_list_pop(LinkedList* list, int index);

// Returns size of array
size_t linked_list_size(LinkedList* list);

#endif