#include <stdlib.h>
#include "linked_list.h"
#include "node.h"
#include "errors.h"

struct LinkedList
{
    Node* head;
    size_t size;
};

// Create new linked list
LinkedList* linked_list_create(void)
{
    LinkedList* list = malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Destroy the linked list and free its memory
int linked_list_destroy(LinkedList* list)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;

    while (list->size > 0)
        linked_list_remove(list, 0);
    free(list);
    return 1;
}

static Node* node_at_index(LinkedList* list, int index)
{
    if (list == NULL)
        return NULL;
    if ((index < 0) || (index >= list->size))
        return NULL;
    Node* node = list->head;
    for (int i = 0; i < index; i++)
        node = node->next;
    return node;
}

// Insert value at index
int linked_list_insert(LinkedList* list, int index, int val)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index > list->size))
        return OUT_OF_BOUNDS_ERROR;

    Node* prev = node_at_index(list, index - 1);
    if (prev == NULL)
        list->head = node_create(val, list->head);
    else
        prev->next = node_create(val, prev->next);
    list->size++;
    return 1;
}

// Removes value at index
int linked_list_remove(LinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    // Traverse list to find node at index
    Node* prev = node_at_index(list, index - 1);
    Node* removed = list->head;
    if (prev == NULL)
        list->head = (list->head)->next;
    else
    {
        removed = prev->next;
        prev->next = (prev->next)->next;
    }
    list->size--;
    // Free the allocated memory for node at index
    node_destroy(removed);
    return 1;
}

// Returns value at index
int linked_list_get(LinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    return node_at_index(list, index)->val;
}

// Removes and returns value at index
int linked_list_pop(LinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    // Traverse list to find node at index
    Node* prev = node_at_index(list, index - 1);
    Node* removed = list->head;
    if (prev == NULL)
        list->head = (list->head)->next;
    else
    {
        removed = prev->next;
        prev->next = (prev->next)->next;
    }
    list->size--;
    int val = removed->val;
    // Free the allocated memory for node at index
    node_destroy(removed);
    return val;
}

// Returns number of elements in list
size_t linked_list_size(LinkedList* list)
{
    if (list == NULL)
        return 0;

    return list->size;
}