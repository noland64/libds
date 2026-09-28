#include <stdlib.h>
#include "stack.h"
#include "dynamicArray.h"
#include "errors.h"

struct Stack {
	DynamicArray* array;
};

Stack* stackCreate(size_t bytesPerElement)
{
	Stack* stack = malloc(sizeof(Stack));
	if (stack == NULL) {
		return NULL;
	}
	stack->array = dynamicArrayCreate(bytesPerElement);
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

int stackPush(Stack* stack, const void* data)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
    size_t arraySize = dynamicArraySize(stack->array);
	return dynamicArrayInsert(stack->array, arraySize, data);
}

int stackPop(Stack* stack, void* outputBuffer)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
    size_t arraySize = dynamicArraySize(stack->array);
	if (arraySize < 1)
		return OUT_OF_BOUNDS_ERROR;
	return dynamicArrayPop(stack->array, arraySize - 1, outputBuffer);
}

int stackPeek(const Stack* stack, void* outputBuffer)
{
	if (stack == NULL) {
		return NULL_OBJECT_ERROR;
    }
    size_t arraySize = dynamicArraySize(stack->array);
    if (arraySize < 1) {
        return OUT_OF_BOUNDS_ERROR;
    }
	return dynamicArrayGet(stack->array, arraySize - 1, outputBuffer);
}

size_t stackSize(const Stack* stack)
{
	if (stack == NULL) {
		return NULL_OBJECT_ERROR;
    }
	return dynamicArraySize(stack->array);
}
