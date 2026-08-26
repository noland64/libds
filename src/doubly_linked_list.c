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

DoublyLinkedList* dllCreate(void)
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

int dllDestroy(DoublyLinkedList* list)
{
    if (list == NULL) {
        return NULL_OBJECT_ERROR;
    }
    DoubleNode* node = list->head;
    while (node != NULL)
    {
        DoubleNode* next = node->next;
        doubleNodeDestroy(node);
        node = next;
    }
    free(list);
    return SUCCESS;
}

static DoubleNode* nodeAtIndex(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL;
    if ((index < 0) || (index >= list->size))
        return NULL;
    DoubleNode* node;
    if (index < (list->size - 1) / 2)
    {
        node = list->head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
    }
    else
    {
        node = list->tail;
        for (int i = list->size - 1; i > index; i--) {
            node = node->prev;
        }
    }
    return node;
}

static DoubleNode* unlinkNode(DoublyLinkedList* list, int index)
{
    if (list == NULL) {
        return NULL;
    }
    if ((index < 0) || (index >= list->size)) {
        return NULL;
    }
    DoubleNode* removed = nodeAtIndex(list, index);
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

int dllInsert(DoublyLinkedList* list, int index, int val)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index > list->size))
        return OUT_OF_BOUNDS_ERROR;

    DoubleNode* newNode = doubleNodeCreate(val, NULL, NULL);
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
        DoubleNode* prevNode = nodeAtIndex(list, index - 1);
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

int dllInsertLeft(DoublyLinkedList* list, int val)
{
    return dllInsert(list, 0, val);
}

int dllInsertRight(DoublyLinkedList* list, int val)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    return dllInsert(list, list->size, val);
}

// Removes value at index
int dllRemove(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    DoubleNode* removed = unlinkNode(list, index);
    doubleNodeDestroy(removed);
    return SUCCESS;
}

int dllRemoveLeft(DoublyLinkedList* list)
{
    return dllRemove(list, 0);
}

int dllRemoveRight(DoublyLinkedList* list)
{
    if (list == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return dllRemove(list, list->size - 1);
}

// Returns value at index
int dllGet(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    return nodeAtIndex(list, index)->val;
}

int dllGetLeft(DoublyLinkedList* list)
{
    return dllGet(list, 0);
}

int dllGetRight(DoublyLinkedList* list)
{
    if (list == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return dllGet(list, list->size - 1);
}

// Removes and returns value at index
int dllPop(DoublyLinkedList* list, int index)
{
    if (list == NULL)
        return NULL_OBJECT_ERROR;
    if ((index < 0) || (index >= list->size))
        return OUT_OF_BOUNDS_ERROR;

    DoubleNode* removed = unlinkNode(list, index);
    int val = removed->val;
    doubleNodeDestroy(removed);
    return val;
}

int dllPopLeft(DoublyLinkedList* list)
{
    return dllPop(list, 0);
}

int dllPopRight(DoublyLinkedList* list)
{
    if (list == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return dllPop(list, list->size - 1);
}

// Returns size of doubly linked list
size_t dllSize(DoublyLinkedList* list)
{
    if (list == NULL)
        return 0;

    return list->size;
}