#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "errors.h"
#include "queue.h"

static void test_create(void)
{
    Queue* queue = queueCreate();
    assert(queue != NULL);
    assert(queueSize(queue) == 0);
    queueDestroy(queue);
}

static void test_destroy(void)
{
    Queue* queue = NULL;
    assert(queueDestroy(queue) == NULL_OBJECT_ERROR);

    queue = queueCreate();
    assert(queueDestroy(queue) == SUCCESS);

    queue = queueCreate();
    queueEnqueue(queue, 1);
    assert(queueDestroy(queue) == SUCCESS);

    queue = queueCreate();
    queueEnqueue(queue, 1);
    queueEnqueue(queue, 2);
    assert(queueDestroy(queue) == SUCCESS);
}

static void test_enqueue(void)
{
    Queue* queue = NULL;
    assert(queueEnqueue(queue, 0) == NULL_OBJECT_ERROR);

    queue = queueCreate();
    assert(queueEnqueue(queue, 0) == SUCCESS);
    assert(queueEnqueue(queue, 1) == SUCCESS);
    assert(queueEnqueue(queue, 2) == SUCCESS);

    assert(queueDequeue(queue) == 0);
    assert(queueDequeue(queue) == 1);
    assert(queueDequeue(queue) == 2);

    queueDestroy(queue);
}

void test_dequeue(void)
{
    Queue* queue = NULL;
    assert(queueDequeue(queue) == NULL_OBJECT_ERROR);

    queue = queueCreate();
    assert(queueDequeue(queue) == OUT_OF_BOUNDS_ERROR);

    queueEnqueue(queue, 0);
    assert(queueDequeue(queue) == 0);
    queueDestroy(queue);
}

void test_peek(void)
{
    Queue* queue = NULL;
    assert(queuePeek(queue) == NULL_OBJECT_ERROR);

    queue = queueCreate();
    assert(queuePeek(queue) == OUT_OF_BOUNDS_ERROR);

    queueEnqueue(queue, 0);
    assert(queuePeek(queue) == 0);

    queueEnqueue(queue, 1);
    assert(queuePeek(queue) == 0);

    queueDestroy(queue);
}

void test_size(void)
{
    Queue* queue = NULL;
    assert(queueSize(queue) == NULL_OBJECT_ERROR);

    queue = queueCreate();
    assert(queueSize(queue) == 0);

    queueEnqueue(queue, 0);
    assert(queueSize(queue) == 1);

    queueEnqueue(queue, 1);
    assert(queueSize(queue) == 2);

    queueDequeue(queue);
    assert(queueSize(queue) == 1);

    queueDequeue(queue);
    assert(queueSize(queue) == 0);

    queueDequeue(queue);
    assert(queueSize(queue) == 0);

    queueDestroy(queue);
}
int main(void)
{
    test_create();
    test_destroy();
    test_enqueue();
    test_dequeue();
    test_peek();
    test_size();
    return 0;
}