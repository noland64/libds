#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define TEST_SIZE 2048

struct Data {
    size_t foo;
    char bar;
};

int main(void)
{
    Stack* stack = NULL;

    // Check destroying empty stack returns correct error
    assert(stackDestroy(stack) == NULL_OBJECT_ERROR);

    stack = stackCreate(sizeof(struct Data));

    size_t testFoos[TEST_SIZE];
    char testBars[TEST_SIZE];

    // Push a bunch of random data
    struct Data pushedData;
    struct Data peekData;
    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check size correctly incrementing
        assert(stackSize(stack) == i);
        // Generate random test data and push to stack
        testFoos[i] = rand();
        testBars[i] = (char)(rand()%26 + 0x41);
        pushedData.foo = testFoos[i];
        pushedData.bar = testBars[i];
        stackPush(stack, &pushedData);
        // Check peek working correctly
        stackPeek(stack, &peekData);
        assert(peekData.foo == pushedData.foo);
        assert(peekData.bar == pushedData.bar);
    }
    // Pop the data and check for correct
    struct Data poppedData;
    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check size correctly decrementing
        assert(stackSize(stack) == TEST_SIZE-i);

        // Check popped data against array of pushed data
        stackPop(stack, &poppedData);
        assert(poppedData.foo == testFoos[TEST_SIZE - (i+1)]);
        assert(poppedData.bar == testBars[TEST_SIZE - (i+1)]);
    }

    // Check peeking an empty stack returns correct error
    assert(stackPeek(stack, &peekData) == OUT_OF_BOUNDS_ERROR);

    // Check popping an empty stack returns correct error
    assert(stackPop(stack, &poppedData) == OUT_OF_BOUNDS_ERROR);

    stackDestroy(stack);
    return 0;
}