#ifndef STACK_H
#define STACK_H

#include "errors.h"

typedef struct Stack Stack;

// Create a new stack for elements of size dataSize
// Returns a pointer to the newly created Stack, or NULL if an error was encountered
Stack* stackCreate(size_t bytesPerElement);

// Destroy the Stack and free its memory
// Returns SUCCESS, or an appopriate error code
int stackDestroy(Stack* stack);

// Push data onto the Stack
// Accepts a pointer to the data to pushed to the Stack
// Returns SUCCESS, or an appropriate error code
int stackPush(Stack* stack, const void* data);

// Pop the most recent data off the Stack
// Accepts a pointer to the buffer the data should be written to
// Returns SUCCESS, or an appropriate error code
int stackPop(Stack* stack, void* outputBuffer);

// Retrieve the most recent data added to the Stack
// Accepts a pointer to the buffer the data should be written to
// Returns SUCCESS, or an appropriate error code
int stackPeek(const Stack* stack, void* outputBuffer);

// Retrieve the size of the Stack
// Accepts a pointer to the buffer the size should be written to
// Returns SUCCESS, or an appropriate error code
size_t stackSize(const Stack* stack);

#endif
