#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "node.h"
#include "errors.h"

struct LinkedList
{
    Node* head;
    size_t size;
    size_t bytesPerElement;
};

// Create new linked list
LinkedList* linkedListCreate(size_t bytesPerElement)
{
    LinkedList* list = malloc(sizeof(LinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    list->bytesPerElement = bytesPerElement;
    return list;
}

// Destroy the linked list and free its memory
int linkedListDestroy(LinkedList* list)
{
    if (list == NULL) {
        return NULL_OBJECT_ERROR;
    }
    Node* node = list->head;
    while (node)
    {
        Node* next = node->next;
        nodeDestroy(node);
        node = next;
    }
    free(list);
    return SUCCESS;
}

static Node* nodeAtIndex(LinkedList* list, int index)
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
int linkedListInsert(LinkedList* list, int index, void* value)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index > list->size))
        return OUT_OF_BOUNDS_ERROR;

    Node* prev = nodeAtIndex(list, index - 1);
    if (prev == NULL)
        list->head = nodeCreate(value, list->bytesPerElement, list->head);
    else
        prev->next = nodeCreate(value, list->bytesPerElement, prev->next);
    list->size++;
    return SUCCESS;
}

// Removes value at index
int linkedListRemove(LinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    // Traverse list to find node at index
    Node* prev = nodeAtIndex(list, index - 1);
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
    nodeDestroy(removed);
    return SUCCESS;
}

// Returns value at index
int linkedListGet(LinkedList* list, int index, void* output)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;
    void* value = nodeAtIndex(list, index)->value;
    memcpy(output, (char*) value, list->bytesPerElement);
    return SUCCESS;
}

// Removes and returns value at index
int linkedListPop(LinkedList* list, int index, void* output)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    // Traverse list to find node at index
    Node* prev = nodeAtIndex(list, index - 1);
    Node* removed = list->head;
    if (prev == NULL)
        list->head = (list->head)->next;
    else
    {
        removed = prev->next;
        prev->next = (prev->next)->next;
    }
    list->size--;
    // Copy the result to the output buffer
    void* value = removed->value;
    memcpy(output, (char*) value, list->bytesPerElement);
    // Free the allocated memory for node at index
    nodeDestroy(removed);
    return SUCCESS;
}

// Returns number of elements in list
size_t linkedListSize(LinkedList* list)
{
    if (list == NULL)
        return 0;
    return list->size;
}