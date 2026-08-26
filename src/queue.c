
#include <stdlib.h>
#include "queue.h"
#include "deque.h"
#include "errors.h"

struct Queue {
    Deque* deque;
    int size;
};