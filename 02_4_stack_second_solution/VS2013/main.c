#include "stack_second.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	int **new_stack = NULL;
	new_stack = (int**)malloc(sizeof(int*) * MAX_STACK_NUM);
	memset(new_stack, 0, MAX_STACK_NUM * sizeof(int*));	// 200개를 받을 수 있는 Pointer 배열

	push(new_stack, 10);
	push(new_stack, 20);
	push(new_stack, 30);
	push(new_stack, 40);
	push(new_stack, 50);
	push(new_stack, 60);

	print_stack(new_stack);
	
	pop(new_stack);
	pop(new_stack);
//	pop(new_stack);
//	pop(new_stack);
//	pop(new_stack);
//	pop(new_stack);
//	pop(new_stack);
//	pop(new_stack);

	cleanStack(new_stack);
	free(new_stack);

	return 0;
}