#include <stdlib.h>
#include "stack.h"
#include "dynamicArray.h"
#include "errors.h"

struct Stack {
	DynamicArray* array;
};

Stack* stackCreate(void)
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

int stackDestroy(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	dynamicArrayDestroy(stack->array);
	free(stack);
	return 1;
}

int stackPush(Stack* stack, int val)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	return dynamicArrayInsert(stack->array, dynamicArraySize(stack->array), val);
}

int stackPop(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	if (dynamicArraySize(stack->array) < 1)
		return EMPTY_STACK_ERROR;
	return dynamicArrayPop(stack->array, dynamicArraySize(stack->array)-1);
}

int stackPeek(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	if (dynamicArraySize(stack->array) < 1)
		return EMPTY_STACK_ERROR;
	return dynamicArrayGet(stack->array, dynamicArraySize(stack->array)-1);
}

int stackSize(Stack* stack)
{
	if (stack == NULL)
		return 0;
	return dynamicArraySize(stack->array);
}
