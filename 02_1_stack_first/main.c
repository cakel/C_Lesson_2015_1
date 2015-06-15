#include "stack_first.h"

int main(void)
{
	push(10);
	push(20);
	push(30);
	print_stack();
	pop();
	pop();
	pop();
	pop();

	return 0;
}