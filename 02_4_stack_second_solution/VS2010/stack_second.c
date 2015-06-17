#include <stdio.h>
#include <stdlib.h>
#include "stack_second.h"

int stack_top = 0;

int push(int** stack, int numberToPush)
{
	int retValue = 0;

	if (isFull())
	{
		puts("Stack �� �� á���ϴ�.");
	}
	else
	{
		stack[stack_top] = (int*)malloc(sizeof(int) * 1);
		// stack[stack_top][0] = numberToPush;					// stack pointer �� stack_top ��(Row) �� ù��° �� (Column) Pointer �� ����Ŵ
		*(*(stack + stack_top))= numberToPush;
		printf("%s() - push(%d) -> stack[%d] malloc - 0x%x\n", __FUNCTION__, numberToPush, stack_top, stack[stack_top]);
		stack_top++;

		retValue = true;
	}

	return retValue;
}

int pop(int** stack)
{
	int numberToBePoped = 0;

	if (isEmpty())
	{
		puts("Stack �� ������ϴ�");
	}
	else
	{
		stack_top--;
		// numberToBePoped = stack[stack_top][0];
		numberToBePoped = *(*(stack+stack_top));

		printf("%s() - pop(%d) -> stack[%d] free - 0x%x\n", __FUNCTION__, numberToBePoped, stack_top, stack[stack_top]);
		free(stack[stack_top]);
		stack[stack_top] = NULL;
	}
	
	return numberToBePoped;
}

void print_stack(int** stack)
{
	int i = 0;

	puts("== Stack ���� ��� ==");
	puts("Top");
	
	for ( i = stack_top - 1; i >= 0; i--)
	{
		printf("|\t%d\t|\n", stack[i][0]);
		puts("-----------------");
	}
	puts("Bottom");
}

int isFull()
{
	return MAX_STACK_NUM <= stack_top;	//	����� NULL
}

int isEmpty()
{
	return stack_top <= 0;
}

void cleanStack(int** stack)
{
	printf("Memory ������ ���� ���� Stack ���� pop() ���� �����մϴ�...\n");
	while(!isEmpty())
	{
		pop(stack);
	}
}