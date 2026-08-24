#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	DynamicArray* array = dynamic_array_create();
    printf("POP: %i\n", dynamic_array_pop(array, 0));
	dynamic_array_insert(array, 0, 0);
    dynamic_array_insert(array, 1, 1);
    dynamic_array_insert(array, 2, 2);
    dynamic_array_insert(array, 3, 3);
    dynamic_array_insert(array, 4, 4);
    dynamic_array_insert(array, 5, 5);
    for (int i = 0; i < dynamic_array_size(array); i++)
    {
        printf("%d ", dynamic_array_get(array, i));
    }
    printf("\n");

    dynamic_array_insert(array, 0, 6);
    dynamic_array_insert(array, 3, 7);
    for (int i = 0; i < dynamic_array_size(array); i++)
    {
        printf("%d ", dynamic_array_get(array, i));
    }
    printf("\n");
	printf("Size: %i\n", dynamic_array_size(array));
	printf("REMOVE: %i\n", dynamic_array_remove(array, 0));
    for (int i = 0; i < dynamic_array_size(array); i++)
    {
        printf("%d ", dynamic_array_get(array, i));
    }
    printf("\n");
	printf("REMOVE: %i\n", dynamic_array_remove(array, 4));
    for (int i = 0; i < dynamic_array_size(array); i++)
    {
        printf("%d ", dynamic_array_get(array, i));
    }
    printf("\n");
	printf("POP: %i\n", dynamic_array_pop(array, 3));
	for (int i = 0; i < dynamic_array_size(array); i++)
    {
        printf("%d ", dynamic_array_get(array, i));
    }
    printf("\n");
    printf("POP: %i\n", dynamic_array_pop(array, 5));
    printf("POP: %i\n", dynamic_array_pop(array, -1));
    printf("Size: %i\n", dynamic_array_size(array));
	dynamic_array_destroy(array);
    printf("POP: %i\n", dynamic_array_pop(array, 5));
}