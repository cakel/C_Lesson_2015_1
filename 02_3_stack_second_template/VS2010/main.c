#include "stack_second.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int **new_stack = NULL;

	push(new_stack, 10);
	push(new_stack, 20);
	push(new_stack, 30);
	push(new_stack, 40);
	push(new_stack, 50);
	push(new_stack, 60);

	print_stack(new_stack);
	
	pop(new_stack);
	pop(new_stack);

	cleanStack(new_stack);

	if(new_stack != NULL)
		free(new_stack);

	return 0;
}