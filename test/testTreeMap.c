#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "errors.h"
#include "treeMap.h"
#include "node.h"

static void testCreate(void)
{
    TreeMap* map = treeMapCreate();
    assert(map != NULL);
    assert(treeMapSize(map) == 0);
    treeMapDestroy(map);
}

static void testDestroy(void)
{
    TreeMap* map = NULL;
    assert(treeMapDestroy(map) == NULL_OBJECT_ERROR);

    map = treeMapCreate();
    assert(treeMapDestroy(map) == SUCCESS);

    map = treeMapCreate();
    treeMapInsert(map, 0, 0);
    assert(treeMapDestroy(map) == SUCCESS);

    map = treeMapCreate();
    treeMapInsert(map, 0, 0);
    treeMapInsert(map, 1, 1);
    assert(treeMapDestroy(map) == SUCCESS);
}

static void testInsert(void)
{
    TreeMap* map = NULL;
    assert(treeMapInsert(map, 0, 0) == NULL_OBJECT_ERROR);

    map = treeMapCreate();
    assert(treeMapInsert(map, -1, 0) == SUCCESS);
    //printInOrder(map);
    assert(treeMapInsert(map, 0, 0) == SUCCESS);
    //printInOrder(map);

    assert(treeMapInsert(map, 1, 1) == SUCCESS);
    assert(treeMapInsert(map, 2, 2) == SUCCESS);
    assert(treeMapInsert(map, 3, 3) == SUCCESS);
    assert(treeMapInsert(map, 4, 11) == SUCCESS);
    assert(treeMapInsert(map, 5, 5) == SUCCESS);
    assert(treeMapInsert(map, 6, 6) == SUCCESS);
    assert(treeMapInsert(map, 7, 7) == SUCCESS);
    assert(treeMapInsert(map, 8, 8) == SUCCESS);
    assert(treeMapInsert(map, 9, 9) == SUCCESS);
    //printInOrder(map);
    assert(treeMapGet(map, 0) == 0);
    fprintf(stderr, "\nNUM: %d\n", treeMapGet(map, 4));
    assert(treeMapGet(map, 4) == 11);
    assert(treeMapGet(map, 9) == 9);

    assert(treeMapInsert(map, 5, 10) == SUCCESS);
    assert(treeMapGet(map, 5) == 10);

    treeMapDestroy(map);
}
/*
void testRemove(void)
{
    TreeMap* map = NULL;
    assert(treeMapRemove(map, 0) == NULL_OBJECT_ERROR);

    map = treeMapCreate();
    assert(treeMapRemove(map, 0) == OUT_OF_BOUNDS_ERROR);
    treeMapInsert(map, 0, 0);
    assert(treeMapRemove(map, -1) == OUT_OF_BOUNDS_ERROR);
    assert(treeMapRemove(map, 0) == SUCCESS);
    treeMapInsert(map, 0, 0);
    treeMapInsert(map, 1, 1);
    treeMapInsert(map, 2, 2);
    treeMapInsert(map, 3, 3);
    assert(treeMapRemove(map, 2) == SUCCESS);
    assert(treeMapSize(map) == 3);
    assert(treeMapGet(map, 2) == 3);

    treeMapDestroy(map);
}

void testPop(void)
{
    TreeMap* map = NULL;
    assert(treeMapPop(map, 0) == NULL_OBJECT_ERROR);

    map = treeMapCreate();
    assert(treeMapPop(map, 0) == OUT_OF_BOUNDS_ERROR);
    treeMapInsert(map, 0, 0);
    assert(treeMapPop(map, -1) == OUT_OF_BOUNDS_ERROR);
    assert(treeMapPop(map, 0) == 0);
    treeMapInsert(map, 0, 0);
    treeMapInsert(map, 1, 1);
    treeMapInsert(map, 2, 2);
    treeMapInsert(map, 3, 3);
    assert(treeMapPop(map, 2) == 2);
    assert(treeMapSize(map) == 3);
    assert(treeMapGet(map, 2) == 3);

    treeMapDestroy(map);
}
*/
void testGet(void)
{
    TreeMap* map = NULL;
    assert(treeMapGet(map, 0) == NULL_OBJECT_ERROR);

    map = treeMapCreate();
    assert(treeMapGet(map, 0) == OUT_OF_BOUNDS_ERROR);

    treeMapInsert(map, 0, 0);
    assert(treeMapGet(map, 0) == 0);

    treeMapInsert(map, 1, 1);
    assert(treeMapGet(map, 0) == 0);
    assert(treeMapGet(map, 1) == 1);

    treeMapDestroy(map);
}

/*
void testSize(void)
{
    TreeMap* map = NULL;
    assert(treeMapSize(map) == NULL_OBJECT_ERROR);

    map = treeMapCreate();
    assert(treeMapSize(map) == 0);

    treeMapInsert(map, 0, 0);
    assert(treeMapSize(map) == 1);

    treeMapInsert(map, 1, 1);
    assert(treeMapSize(map) == 2);

    treeMapRemove(map, 1);
    assert(treeMapSize(map) == 1);

    treeMapRemove(map, 0);
    assert(treeMapSize(map) == 0);

    treeMapRemove(map, 0);
    assert(treeMapSize(map) == 0);

    treeMapDestroy(map);
}
*/
int main(void)
{
    testCreate();
    testDestroy();
    testInsert();
    //testRemove();
    //testPop();
    testGet();
    //testSize();
    return 0;
}