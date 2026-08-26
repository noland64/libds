#ifndef STACK_H
#define STACK_H

#define EMPTY_STACK_ERROR 1111

typedef struct Stack Stack;

// Create new stack
Stack* stackCreate(void);
// Destroy the stack and free its memory
int stackDestroy(Stack* stack);
// Push value onto the stack
int stackPush(Stack* stack, int val);
// Pop the most recent value off the stack
int stackPop(Stack* stack);
// Retrieve the most recent value added to the stack
int stackPeek(Stack* stack);
// Retrieve the size of the stack
int stackSize(Stack* stack);

#endif