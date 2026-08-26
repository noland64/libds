#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "errors.h"
#include "dynamicArray.h"

static void testCreate(void)
{
    DynamicArray* array = dynamicArrayCreate();
    assert(array != NULL);
    assert(dynamicArraySize(array) == 0);
    dynamicArrayDestroy(array);
}

static void testDestroy(void)
{
    DynamicArray* array = NULL;
    assert(dynamicArrayDestroy(array) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate();
    assert(dynamicArrayDestroy(array) == SUCCESS);

    array = dynamicArrayCreate();
    dynamicArrayInsert(array, 0, 0);
    assert(dynamicArrayDestroy(array) == SUCCESS);

    array = dynamicArrayCreate();
    dynamicArrayInsert(array, 0, 0);
    dynamicArrayInsert(array, 1, 1);
    assert(dynamicArrayDestroy(array) == SUCCESS);
}

static void testInsert(void)
{
    DynamicArray* array = NULL;
    assert(dynamicArrayInsert(array, 0, 0) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate();
    assert(dynamicArrayInsert(array, -1, 0) == OUT_OF_BOUNDS_ERROR);

    assert(dynamicArrayInsert(array, 0, 0) == SUCCESS);
    assert(dynamicArrayInsert(array, 1, 1) == SUCCESS);
    assert(dynamicArrayInsert(array, 2, 2) == SUCCESS);
    assert(dynamicArrayInsert(array, 3, 3) == SUCCESS);
    assert(dynamicArrayInsert(array, 4, 4) == SUCCESS);
    assert(dynamicArrayInsert(array, 5, 5) == SUCCESS);
    assert(dynamicArrayInsert(array, 6, 6) == SUCCESS);
    assert(dynamicArrayInsert(array, 7, 7) == SUCCESS);
    assert(dynamicArrayInsert(array, 8, 8) == SUCCESS);
    assert(dynamicArrayInsert(array, 9, 9) == SUCCESS);

    assert(dynamicArrayGet(array, 0) == 0);
    assert(dynamicArrayGet(array, 4) == 4);
    assert(dynamicArrayGet(array, 9) == 9);

    assert(dynamicArrayInsert(array, 5, 10) == SUCCESS);
    assert(dynamicArrayGet(array, 5) == 10);

    dynamicArrayDestroy(array);
}

void testRemove(void)
{
    DynamicArray* array = NULL;
    assert(dynamicArrayRemove(array, 0) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate();
    assert(dynamicArrayRemove(array, 0) == OUT_OF_BOUNDS_ERROR);
    dynamicArrayInsert(array, 0, 0);
    assert(dynamicArrayRemove(array, -1) == OUT_OF_BOUNDS_ERROR);
    assert(dynamicArrayRemove(array, 0) == SUCCESS);
    dynamicArrayInsert(array, 0, 0);
    dynamicArrayInsert(array, 1, 1);
    dynamicArrayInsert(array, 2, 2);
    dynamicArrayInsert(array, 3, 3);
    assert(dynamicArrayRemove(array, 2) == SUCCESS);
    assert(dynamicArraySize(array) == 3);
    assert(dynamicArrayGet(array, 2) == 3);

    dynamicArrayDestroy(array);
}

void testPop(void)
{
    DynamicArray* array = NULL;
    assert(dynamicArrayPop(array, 0) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate();
    assert(dynamicArrayPop(array, 0) == OUT_OF_BOUNDS_ERROR);
    dynamicArrayInsert(array, 0, 0);
    assert(dynamicArrayPop(array, -1) == OUT_OF_BOUNDS_ERROR);
    assert(dynamicArrayPop(array, 0) == 0);
    dynamicArrayInsert(array, 0, 0);
    dynamicArrayInsert(array, 1, 1);
    dynamicArrayInsert(array, 2, 2);
    dynamicArrayInsert(array, 3, 3);
    assert(dynamicArrayPop(array, 2) == 2);
    assert(dynamicArraySize(array) == 3);
    assert(dynamicArrayGet(array, 2) == 3);

    dynamicArrayDestroy(array);
}

void testGet(void)
{
    DynamicArray* array = NULL;
    assert(dynamicArrayGet(array, 0) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate();
    assert(dynamicArrayGet(array, 0) == OUT_OF_BOUNDS_ERROR);

    dynamicArrayInsert(array, 0, 0);
    assert(dynamicArrayGet(array, 0) == 0);

    dynamicArrayInsert(array, 1, 1);
    assert(dynamicArrayGet(array, 0) == 0);
    assert(dynamicArrayGet(array, 1) == 1);

    dynamicArrayDestroy(array);
}

void testSize(void)
{
    DynamicArray* array = NULL;
    assert(dynamicArraySize(array) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate();
    assert(dynamicArraySize(array) == 0);

    dynamicArrayInsert(array, 0, 0);
    assert(dynamicArraySize(array) == 1);

    dynamicArrayInsert(array, 1, 1);
    assert(dynamicArraySize(array) == 2);

    dynamicArrayRemove(array, 1);
    assert(dynamicArraySize(array) == 1);

    dynamicArrayRemove(array, 0);
    assert(dynamicArraySize(array) == 0);

    dynamicArrayRemove(array, 0);
    assert(dynamicArraySize(array) == 0);

    dynamicArrayDestroy(array);
}
int main(void)
{
    testCreate();
    testDestroy();
    testInsert();
    testRemove();
    testPop();
    testGet();
    testSize();
    return 0;
}