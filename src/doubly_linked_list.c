#include <stdlib.h>
#include "doubly_linked_list.h"
#include "node.h"
#include "errors.h"

struct DoublyLinkedList
{
    DoubleNode* head;
    DoubleNode* tail;
    size_t size;
};

// Create new doubly linked list
DoublyLinkedList* doubly_linked_list_create(void)
{
    DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Destroy the doubly linked list and free its memory
int doubly_linked_list_destroy(DoublyLinkedList* list)
{
    if (list == NULL) {
        return NULL_OBJECT_ERROR;
    }
    DoubleNode* node = list->head;
    while (node != NULL)
    {
        DoubleNode* next = node->next;
        double_node_destroy(node);
        node = next;
    }
    free(list);
    return SUCCESS;
}

static DoubleNode* node_at_index(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL;
    if ((index < 0) || (index >= list->size))
        return NULL;
    DoubleNode* node;
    if (index < (list->size - 1) / 2)
    {
        node = list->head;
        for (int i = 0; i < index; i++)
            node = node->next;
    }
    else
    {
        node = list->tail;
        for (int i = list->size - 1; i > index; i--)
            node = node->prev;
    }
    return node;
}

static DoubleNode* unlink_node(DoublyLinkedList* list, int index)
{
    if (list == NULL) {
        return NULL;
    }
    if ((index < 0) || (index >= list->size)) {
        return NULL;
    }
    DoubleNode* removed = node_at_index(list, index);
    if (list->head == list->tail)
    {
        list->head = list->tail = NULL;
    }
    else if (removed == list->head)
    {
        list->head = (list->head)->next;
        (list->head)->prev = NULL;
    }
    else if (removed == list->tail)
    {
        list->tail = (list->tail)->prev;
        (list->tail)->next = NULL;
    }
    else
    {
        (removed->prev)->next = removed->next;
        (removed->next)->prev = removed->prev;
    }
    list->size--;
    return removed;
}

// Insert value at index
int doubly_linked_list_insert(DoublyLinkedList* list, int index, int val)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index > list->size))
        return OUT_OF_BOUNDS_ERROR;

    DoubleNode* newNode = double_node_create(val, NULL, NULL);
    if (newNode == NULL)
        return MEMORY_ERROR;

    // List is empty, intitialise head and tail with new node
    if (list->size == 0) {
        list->head = list->tail = newNode;
    }
    // Insert at beginning of list
    else if (index == 0)
    {
        // Point newNode to head
        newNode->next = list->head;
        // Point old head prev back to newNode
        (list->head)->prev = newNode;
        // Update list head pointer
        list->head = newNode;
    }
    // Insert at end of list
    else if (index == list->size)
    {
        // Point newNode prev to tail
        newNode->prev = list->tail;
        // Point tail node next to newNode
        (list->tail)->next = newNode;
        // Update list tail pointer
        list->tail = newNode;
    }
    // Insert middle of list
    else
    {
        DoubleNode* prevNode = node_at_index(list, index - 1);
        DoubleNode* nextNode = prevNode->next;
        // Point newNode at correct nodes
        newNode->prev = prevNode;
        newNode->next = nextNode;
        // Update old nodes to point at newNode
        prevNode->next = newNode;
        nextNode->prev = newNode;
    }
    list->size++;
    return SUCCESS;
}

// Removes value at index
int doubly_linked_list_remove(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    DoubleNode* removed = unlink_node(list, index);
    double_node_destroy(removed);
    return SUCCESS;
}

// Returns value at index
int doubly_linked_list_get(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    return node_at_index(list, index)->val;
}

// Removes and returns value at index
int doubly_linked_list_pop(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    DoubleNode* removed = unlink_node(list, index);
    int val = removed->val;
    double_node_destroy(removed);
    return val;
}

// Returns size of doubly linked list
size_t doubly_linked_list_size(DoublyLinkedList* list)
{
    if (list == NULL)
        return 0;

    return list->size;
}