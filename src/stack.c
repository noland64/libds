#include <stdlib.h>
#include "stack.h"
#include "dynamicArray.h"
#include "errors.h"

struct Stack {
	DynamicArray* array;
};

Stack* stack_create(void)
{
	Stack* stack = malloc(sizeof(Stack));
	if (stack == NULL) {
		return NULL;
	}
	stack->array = dynamicArrayCreate();
	if (stack->array == NULL)
	{
		free(stack);
		return NULL;
	}
	return stack;
}

int stack_destroy(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	dynamicArrayDestroy(stack->array);
	free(stack);
	return 1;
}

int stack_push(Stack* stack, int val)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	return dynamicArrayInsert(stack->array, dynamicArraySize(stack->array), val);
}

int stack_pop(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	if (dynamicArraySize(stack->array) < 1)
		return EMPTY_STACK_ERROR;
	return dynamicArrayPop(stack->array, dynamicArraySize(stack->array)-1);
}

int stack_peek(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	if (dynamicArraySize(stack->array) < 1)
		return EMPTY_STACK_ERROR;
	return dynamicArrayGet(stack->array, dynamicArraySize(stack->array)-1);
}

size_t stack_size(Stack* stack)
{
	if (stack == NULL)
		return 0;
	return dynamicArraySize(stack->array);
}
