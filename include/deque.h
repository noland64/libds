#ifndef DEQUE_H
#define DEQUE_H

typedef struct Deque Deque;

// dequeCreate(void)
// Create and allocate memory for new Deque
// Return newly created Deque, or NULL in the event of error
Deque* dequeCreate(void);

// dequeDestroy(Deque* deque)
// Destroy deque and free allocated memory
// Return success/error code
int dequeDestroy(Deque* deque);

// dequePushLeft(Deque* deque, int val)
// Pushes the parameter val to the left side of the Deque in O(1) time
// Returns success/error code
int dequePushLeft(Deque* deque, int val);

// dequePushRight(Deque* deque, int val)
// Pushes the parameter val to the right side of the Deque in O(1) time
// Returns success/error code
int dequePushRight(Deque* deque, int val);

// dequePeekLeft(Deque* deque)
// Retrieve the leftmost element of the Deque in O(1) time
// Returns the value, or an error code
int dequePeekLeft(Deque* deque);

// dequePeekRight(Deque* deque)
// Retrieve the rightmost element of the Deque in O(1) time
// Returns the value, or an error code
int dequePeekRight(Deque* deque);

// dequePopLeft(Deque* deque)
// Retrieve and remove the leftmost element of the Deque in O(1) time
// Returns the value, or an error code
int dequePopLeft(Deque* deque);

// dequePopRight(Deque* deque)
// Retrieve and remove the rightmost element of the Deque in O(1) time
// Returns the value, or an error code
int dequePopRight(Deque* deque);

// dequeSize(Deque* deque)
// Retrieve the number of elements in the deque in O(1) time
// Returns the size, or an error code
int dequeSize(Deque* deque);

#endif