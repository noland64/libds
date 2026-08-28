#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "errors.h"
#include "heap.h"
#include "stdio.h"

static void testCreate(void)
{
    Heap* heap = heapCreate(true);
    assert(heap != NULL);
    assert(heapSize(heap) == 0);

    heap = heapCreate(false);
    assert(heap != NULL);
    assert(heapSize(heap) == 0);
    heapDestroy(heap);
}

static void testDestroy(void)
{
    Heap* heap = NULL;
    assert(heapDestroy(heap) == NULL_OBJECT_ERROR);

    heap = heapCreate(true);
    assert(heapDestroy(heap) == SUCCESS);

    heap = heapCreate(true);
    heapPush(heap, 1);
    assert(heapDestroy(heap) == SUCCESS);

    heap = heapCreate(false);
    heapPush(heap, 1);
    assert(heapDestroy(heap) == SUCCESS);

    heap = heapCreate(true);
    heapPush(heap, 1);
    heapPush(heap, 2);
    assert(heapDestroy(heap) == SUCCESS);

    heap = heapCreate(false);
    heapPush(heap, 1);
    heapPush(heap, 2);
    assert(heapDestroy(heap) == SUCCESS);
}

static void testPush(void)
{
    Heap* heap = NULL;
    assert(heapPush(heap, 0) == NULL_OBJECT_ERROR);

    heap = heapCreate(true);
    assert(heapPush(heap, 2) == SUCCESS);
    assert(heapPush(heap, 1) == SUCCESS);
    assert(heapPush(heap, 3) == SUCCESS);

    assert(heapPop(heap) == 1);
    assert(heapPop(heap) == 2);
    assert(heapPop(heap) == 3);

    heapDestroy(heap);

    heap = heapCreate(false);
    assert(heapPush(heap, 2) == SUCCESS);
    assert(heapPush(heap, 1) == SUCCESS);
    assert(heapPush(heap, 3) == SUCCESS);

    assert(heapPop(heap) == 3);
    assert(heapPop(heap) == 2);
    assert(heapPop(heap) == 1);

    heapDestroy(heap);

    heap = heapCreate(false);
    for (int i = 0; i < 1000; i++)
    {
        heapPush(heap, rand());
    }

    int max = heapPeek(heap);
    for (int i = 999; i > -1; i--)
    {
        int popped = heapPop(heap);
        assert(popped <= max);
        max = popped;
    }
    heapDestroy(heap);
}

void testPop(void)
{
    Heap* heap = NULL;
    assert(heapPop(heap) == NULL_OBJECT_ERROR);

    heap = heapCreate(true);
    assert(heapPop(heap) == OUT_OF_BOUNDS_ERROR);

    heapPush(heap, 0);
    assert(heapPop(heap) == 0);
    heapDestroy(heap);
}

void testPeek(void)
{
    Heap* heap = NULL;
    assert(heapPeek(heap) == NULL_OBJECT_ERROR);

    heap = heapCreate(true);
    assert(heapPeek(heap) == OUT_OF_BOUNDS_ERROR);

    heapPush(heap, 0);
    assert(heapPeek(heap) == 0);

    heapPush(heap, 1);
    assert(heapPeek(heap) == 0);

    heapPush(heap, -1);
    assert(heapPeek(heap) == -1);

    heapDestroy(heap);

    heap = heapCreate(false);
    assert(heapPeek(heap) == OUT_OF_BOUNDS_ERROR);

    heapPush(heap, 0);
    assert(heapPeek(heap) == 0);

    heapPush(heap, 1);
    assert(heapPeek(heap) == 1);

    heapPush(heap, -1);
    assert(heapPeek(heap) == 1);

    heapPop(heap);
    assert(heapPeek(heap) == 0);

    heapDestroy(heap);
}

void testSize(void)
{
    Heap* heap = NULL;
    assert(heapSize(heap) == NULL_OBJECT_ERROR);

    heap = heapCreate(true);
    assert(heapSize(heap) == 0);

    heapPush(heap, 0);
    assert(heapSize(heap) == 1);

    heapPush(heap, 1);
    assert(heapSize(heap) == 2);

    heapPop(heap);
    assert(heapSize(heap) == 1);

    heapPop(heap);
    assert(heapSize(heap) == 0);

    heapPop(heap);
    assert(heapSize(heap) == 0);

    heapDestroy(heap);
}
int main(void)
{
    testCreate();
    testDestroy();
    testPush();
    testPop();
    testPeek();
    testSize();
    return 0;
}