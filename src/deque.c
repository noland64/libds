#include <stdlib.h>
#include "deque.h"
#include "doublyLinkedList.h"
#include "errors.h"


// Deque is implemented using a DoublyLinkedList
// This enables O(1) time insertions, removals and lookups at either end.
struct Deque
{
    DoublyLinkedList* list;
    size_t bytesPerElement;
    size_t size;
};

Deque* dequeCreate(size_t bytesPerElement)
{
    Deque* deque = malloc(sizeof(Deque));
    if (deque == NULL)
        return NULL;
    deque->list = dllCreate(bytesPerElement);
    if (deque->list == NULL)
    {
        free(deque);
        return NULL;
    }
    deque->bytesPerElement = bytesPerElement;
    deque->size = 0;
    return deque;
}

int dequeDestroy(Deque* deque)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    dllDestroy(deque->list);
    free(deque);
    return SUCCESS;
}

int dequePushLeft(Deque* deque, void* value)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    int res = dllInsertLeft(deque->list, value);
    if (res == SUCCESS)
        deque->size++;
    return res;
}

int dequePushRight(Deque* deque, void* value)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    int res = dllInsertRight(deque->list, value);
    if (res == SUCCESS)
        deque->size++;
    return res;
}

int dequePeekLeft(Deque* deque, void* output)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    return dllGetLeft(deque->list, output);
}

int dequePeekRight(Deque* deque, void* output)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    return dllGetRight(deque->list, output);
}

int dequePopLeft(Deque* deque, void* output)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    int res = dllPopLeft(deque->list, output);
    if (res == SUCCESS)
        deque->size--;
    return res;
}

int dequePopRight(Deque* deque, void* output)
{
    if (deque == NULL)
        return NULL_OBJECT_ERROR;
    int res = dllPopRight(deque->list, output);
    if (res == SUCCESS)
        deque->size--;
    return res;
}

size_t dequeSize(Deque* deque)
{
    if (deque == NULL)
        return 0;
    return deque->size;
}