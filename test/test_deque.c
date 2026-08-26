#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "errors.h"
#include "deque.h"

static void test_create(void)
{
    Deque* deque = dequeCreate();
    assert(deque != NULL);
    assert(dequeSize(deque) == 0);
    assert(dequeDestroy(deque) == SUCCESS);
}

static void test_destroy(void)
{
    Deque* deque = NULL;
    assert(dequeDestroy(deque) == NULL_OBJECT_ERROR);

    deque = dequeCreate();
    assert(dequeDestroy(deque) == SUCCESS);

    deque = dequeCreate();
    dequePushLeft(deque, 1);
    dequePushLeft(deque, 2);
    dequePushRight(deque, 3);
    dequePushRight(deque, 4);
    assert(dequeDestroy(deque) == SUCCESS);
}

static void test_push(void)
{
    Deque* deque = NULL;
    assert(dequePushLeft(deque, 1) == NULL_OBJECT_ERROR);
    assert(dequePushRight(deque, 1) == NULL_OBJECT_ERROR);

    deque = dequeCreate();

    assert(dequePushLeft(deque, 1) == SUCCESS);
    assert(dequePeekLeft(deque) == 1);
    assert(dequePeekRight(deque) == 1);

    assert(dequePushLeft(deque, 2) == SUCCESS);
    assert(dequePeekLeft(deque) == 2);
    assert(dequePeekRight(deque) == 1);

    assert(dequePushLeft(deque, 3) == SUCCESS);
    assert(dequePeekLeft(deque) == 3);
    assert(dequePeekRight(deque) == 1);

    assert(dequePushRight(deque, 4) == SUCCESS);
    assert(dequePeekLeft(deque) == 3);
    assert(dequePeekRight(deque) == 4);

    assert(dequePushRight(deque, 5) == SUCCESS);
    assert(dequePeekLeft(deque) == 3);
    assert(dequePeekRight(deque) == 5);

    assert(dequeDestroy(deque) == SUCCESS);
    deque = dequeCreate();

    assert(dequePushRight(deque, 1) == SUCCESS);
    assert(dequePeekLeft(deque) == 1);
    assert(dequePeekRight(deque) == 1);

    assert(dequePushRight(deque, 1) == SUCCESS);
    assert(dequePeekRight(deque) == 1);

    assert(dequePushRight(deque, 2) == SUCCESS);
    assert(dequePeekLeft(deque) == 1);
    assert(dequePeekRight(deque) == 2);

    assert(dequeDestroy(deque) == SUCCESS);
}

static void test_pop(void)
{
    Deque* deque = NULL;
    assert(dequePopLeft(deque) == NULL_OBJECT_ERROR);
    assert(dequePopRight(deque) == NULL_OBJECT_ERROR);

    deque = dequeCreate();

    assert(dequePushLeft(deque, 1) == SUCCESS);
    assert(dequePopLeft(deque) == 1);

    assert(dequePushLeft(deque, 1) == SUCCESS);
    assert(dequePopRight(deque) == 1);

    assert(dequePushLeft(deque, 1) == SUCCESS);
    assert(dequePushRight(deque, 2) == SUCCESS);
    assert(dequePushRight(deque, 3) == SUCCESS);

    assert(dequePopLeft(deque) == 1);
    assert(dequePopRight(deque) == 3);
    assert(dequePopRight(deque) == 2);

    assert(dequeDestroy(deque) == SUCCESS);
}

static void test_size(void)
{
    Deque* deque = NULL;
    assert(dequeSize(deque) == 0);

    deque = dequeCreate();
    dequePushLeft(deque, 1);
    assert(dequeSize(deque) == 1);

    dequePushLeft(deque, 2);
    assert(dequeSize(deque) == 2);

    dequePushRight(deque, 3);
    assert(dequeSize(deque) == 3);

    dequePopLeft(deque);
    assert(dequeSize(deque) == 2);

    dequePopLeft(deque);
    assert(dequeSize(deque) == 1);

    dequePopLeft(deque);
    assert(dequeSize(deque) == 0);

    dequePopLeft(deque);
    assert(dequeSize(deque) == 0);

    dequePopRight(deque);
    assert(dequeSize(deque) == 0);

    dequeDestroy(deque);
}

int main(void)
{
    test_create();
    test_destroy();
    test_push();
    test_pop();
    test_size();

    fprintf(stderr, "PASSED ALL TESTS\n");
    return 0;
}