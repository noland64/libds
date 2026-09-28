#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include "heap.h"
#include <stdlib.h>

#define TEST_SIZE 2048

struct Data {
    size_t foo;
    char bar;
};


// Example min comparator for struct Data
int comparator(const void* data1, const void* data2)
{
    if (((struct Data*) data1)->foo < ((struct Data*) data2)->foo) {
        return 1;
    }
    if (((struct Data*) data1)->foo > ((struct Data*) data2)->foo) {
        return -1;
    }
    return 0;
}

int main(void)
{
    Heap* heap = NULL;

    // Check destroying empty heap returns correct error
    assert(heapDestroy(heap) == NULL_OBJECT_ERROR);

    heap = heapCreate(sizeof(struct Data), &comparator);

    size_t testFoos[TEST_SIZE];
    char testBars[TEST_SIZE];

    // Push a bunch of random data
    struct Data pushedData;
    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check size correctly incrementing
        assert(heapSize(heap) == i);
        // Generate random test data and push to heap
        testFoos[i] = rand();
        testBars[i] = (char)(rand()%26 + 0x41);
        pushedData.foo = testFoos[i];
        pushedData.bar = testBars[i];
        heapPush(heap, &pushedData);
    }
    // Pop the data and check for correct ordering
    struct Data poppedData;
    struct Data peekData;
    heapPeek(heap, &peekData);

    for (size_t i = 0; i < TEST_SIZE; i++)
    {
        // Check size correctly decrementing
        assert(heapSize(heap) == TEST_SIZE-i);

        // Check popped data against is correctly ordered
        heapPop(heap, &poppedData);
        assert(poppedData.foo >= peekData.foo);
        peekData = poppedData;
    }

    // Check peeking an empty heap returns correct error
    assert(heapPeek(heap, &peekData) == OUT_OF_BOUNDS_ERROR);

    // Check popping an empty heap returns correct error
    assert(heapPop(heap, &poppedData) == OUT_OF_BOUNDS_ERROR);

    heapDestroy(heap);
    return 0;
}