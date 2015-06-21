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
		// Push �� ������ malloc �� �Ἥ �߰�

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
		// Pop �� ������ free �� ����
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