#include <stdlib.h>
#include "stack.h"
#include "dynamic_array.h"
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
	stack->array = dynamic_array_create();
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
	dynamic_array_destroy(stack->array);
	free(stack);
	return 1;
}

int stack_push(Stack* stack, int val)
{	
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	return dynamic_array_insert(stack->array, dynamic_array_size(stack->array), val);
}

int stack_pop(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	if (dynamic_array_size(stack->array) < 1)
		return EMPTY_STACK_ERROR;
	return dynamic_array_pop(stack->array, dynamic_array_size(stack->array)-1);
}	

int stack_peek(Stack* stack)
{
	if (stack == NULL)
		return NULL_OBJECT_ERROR;
	if (dynamic_array_size(stack->array) < 1)
		return EMPTY_STACK_ERROR;
	return dynamic_array_get(stack->array, dynamic_array_size(stack->array)-1);	
}

size_t stack_size(Stack* stack)
{
	if (stack == NULL)
		return 0;
	return dynamic_array_size(stack->array);
}
