#ifndef STACK_H
#define STACK_H

#define EMPTY_STACK_ERROR 1111

typedef struct Stack Stack;

// Create new stack
Stack* stack_create(void);
// Destroy the stack and free its memory
int stack_destroy(Stack* stack);
// Push value onto the stack
int stack_push(Stack* stack, int val);
// Pop the most recent value off the stack
int stack_pop(Stack* stack);
// Retrieve the most recent value added to the stack
int stack_peek(Stack* stack);
// Retrieve the size of the stack
size_t stack_size(Stack* stack);

#endif