
#include <stdlib.h>
#include "queue.h"
#include "deque.h"
#include "errors.h"

struct Queue {
    Deque* deque;
    size_t size;
};

Queue* queueCreate(size_t bytesPerElement)
{
    Queue* queue = malloc(sizeof(Queue));
    if (!queue)
        return NULL;
    queue->deque = dequeCreate(bytesPerElement);
    if (!queue->deque)
    {
        free(queue);
        return NULL;
    }
    queue->size = 0;
    return queue;
}

int queueDestroy(Queue* queue)
{
    if (!queue)
        return NULL_OBJECT_ERROR;
    int status = dequeDestroy(queue->deque);
    if (status != SUCCESS)
        return status;
    free(queue);
    return SUCCESS;
}

int queueEnqueue(Queue* queue, void* value)
{
    if (!queue)
        return NULL_OBJECT_ERROR;
    int res = dequePushLeft(queue->deque, value);
    if (res == SUCCESS)
        queue->size++;
    return res;
}

int queueDequeue(Queue* queue, void* output)
{
    if (!queue)
        return NULL_OBJECT_ERROR;
    int res = dequePopRight(queue->deque, output);
    if (res == SUCCESS)
        queue->size--;
    return res;
}

int queuePeek(Queue* queue, void* output)
{
    if (!queue)
        return NULL_OBJECT_ERROR;
    return dequePeekRight(queue->deque, output);
}

size_t queueSize(Queue* queue)
{
    if (queue == NULL)
        return 0;
    return queue->size;
}