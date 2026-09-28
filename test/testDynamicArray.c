#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"
#include "dynamicArray.h"


#define TEST_SIZE 2048

struct Data {
    size_t foo;
    char bar;
};

int main(void)
{
    printf("Testing Stack...\n");

    DynamicArray* array = NULL;

    // Check destroying empty array returns correct error
    assert(dynamicArrayDestroy(array) == NULL_OBJECT_ERROR);

    array = dynamicArrayCreate(sizeof(struct Data));

    size_t testFoos[TEST_SIZE];
    char testBars[TEST_SIZE];

    // Insert a bunch of random data
    struct Data pushedData;
    struct Data peekData;
    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check size correctly incrementing
        assert(dynamicArraySize(array) == i);
        // Generate random test data and push to stack
        testFoos[i] = rand();
        testBars[i] = (char)(rand()%26 + 0x41);
        pushedData.foo = testFoos[i];
        pushedData.bar = testBars[i];
        dynamicArrayInsert(array, i, &pushedData);
        // Check peek working correctly
        dynamicArrayGet(array, i, &peekData);
        assert(peekData.foo == pushedData.foo);
        assert(peekData.bar == pushedData.bar);
    }
    // Pop the data and check for correct
    struct Data fetchedData;
    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check fetched data against array of pushed data
        dynamicArrayGet(array, i, &fetchedData);
        assert(fetchedData.foo == testFoos[i]);
        assert(fetchedData.bar == testBars[i]);
    }
    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check popped data against array of pushed data
        dynamicArrayPop(array, TEST_SIZE - (i+1), &fetchedData);
        assert(fetchedData.foo == testFoos[TEST_SIZE - (i+1)]);
        assert(fetchedData.bar == testBars[TEST_SIZE - (i+1)]);
    }

    // Check getting from an empty stack returns correct error
    assert(dynamicArrayGet(array, 0, &fetchedData) == OUT_OF_BOUNDS_ERROR);

    // Check removing from an empty array returns correct error
    assert(dynamicArrayRemove(array, 0) == OUT_OF_BOUNDS_ERROR);

    // Check popping from an empty stack returns correct error
    assert(dynamicArrayPop(array, 0, &fetchedData) == OUT_OF_BOUNDS_ERROR);


    dynamicArrayDestroy(array);
    printf("All Stack tests passed!\n");
    return 0;
}