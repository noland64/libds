
#include <stdlib.h>
#include "queue.h"
#include "deque.h"
#include "errors.h"

struct Queue {
    Deque* deque;
    int size;
};

Queue* queueCreate(void)
{
    Queue* queue = malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->deque = dequeCreate();
    if (queue->deque == NULL) {
        return NULL;
    }
    queue->size = 0;
    return queue;
}

int queueDestroy(Queue* queue)
{
    if (queue == NULL) {
        return NULL_OBJECT_ERROR;
    }
    if (dequeDestroy(queue->deque) == NULL_OBJECT_ERROR) {
        return NULL_OBJECT_ERROR;
    }
    free(queue);
    return SUCCESS;
}

int queueEnqueue(Queue* queue, int val)
{
    if (queue == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dequePushLeft(queue->deque, val);
    if (res == SUCCESS) {
        queue->size++;
    }
    return res;
}

int queueDequeue(Queue* queue)
{
    if (queue == NULL) {
        return NULL_OBJECT_ERROR;
    }
    int res = dequePopRight(queue->deque);
    if (res != OUT_OF_BOUNDS_ERROR) {
        queue->size--;
    }
    return res;
}

int queuePeek(Queue* queue)
{
    if (queue == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return dequePeekRight(queue->deque);
}

int queueSize(Queue* queue)
{
    if (queue == NULL) {
        return NULL_OBJECT_ERROR;
    }
    return queue->size;
}