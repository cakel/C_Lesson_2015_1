#include <stdio.h>
#include "stack_first.h"

int stack[MAX_STACK_NUM] = { 0 };
int stack_top = 0;

int push(int numberToPush)
{
	int retValue = 0;

	if (isFull())
	{
		puts("Stack �� �� á���ϴ�.");
	}
	else
	{
		stack[stack_top++] = numberToPush;

		retValue = true;
	}

	return retValue;
}

int pop(void)
{
	int numberToBePoped = 0;

	if (isEmpty())
	{
		puts("Stack �� ������ϴ�");
	}
	else
	{
		numberToBePoped = stack[--stack_top];
	}
	
	return numberToBePoped;
}

void print_stack(void)
{
	int i = 0;

	puts("== Stack ���� ��� ==");
	puts("Top");
	
//	for (int i = 0; i < stack_top; i++)
	for ( i = stack_top - 1; i >= 0; i--)
	{
		printf("|\t%d\t|\n", stack[i]);
		puts("-----------------");
	}
	puts("Bottom");
}

int isFull()
{
	return MAX_STACK_NUM <= stack_top;
}

int isEmpty()
{
	return stack_top <= 0;
}
