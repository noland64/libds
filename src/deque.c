#include <stdlib.h>
#include "deque.h"
#include "doubly_linked_list.h"
#include "errors.h"


// Deque is implemented using a DoublyLinkedList
// This enables O(1) time insertions, removals and lookups at either end.
struct Deque
{
    DoublyLinkedList* list;
    int size;
};

Deque* dequeCreate(void)
{
    Deque* deque = malloc(sizeof(Deque));
    if (deque == NULL) {
        return NULL;
    }
    deque->list = dllCreate();
    if (deque->list == NULL)
    {
        free(deque);
        return NULL;
    }
    deque->size = 0;
    return deque;
}

int dequeDestroy(Deque* deque)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    dllDestroy(deque->list);
    free(deque);
    return SUCCESS;
}

int dequePushLeft(Deque* deque, int val)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dllInsertLeft(deque->list, val);
    if (res == SUCCESS) {
        deque->size++;
    }
    return res;
}

int dequePushRight(Deque* deque, int val)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dllInsertRight(deque->list, val);
    if (res == SUCCESS) {
        deque->size++;
    }
    return res;
}

int dequePeekLeft(Deque* deque)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return dllGetLeft(deque->list);
}

int dequePeekRight(Deque* deque)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return dllGetRight(deque->list);
}

int dequePopLeft(Deque* deque)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dllPopLeft(deque->list);
    if (res != OUT_OF_BOUNDS_ERROR) {
        deque->size--;
    }
    return res;
}

int dequePopRight(Deque* deque)
{
    if (deque == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dllPopRight(deque->list);
    if (res != OUT_OF_BOUNDS_ERROR) {
        deque->size--;
    }
    return res;
}

int dequeSize(Deque* deque)
{
    if (deque == NULL) {
        return 0;
    }
    return deque->size;
}