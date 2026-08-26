#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"
#include "dynamicArray.h"

struct Heap {
    DynamicArray* array;
    bool isMinHeap;
    int size;
};