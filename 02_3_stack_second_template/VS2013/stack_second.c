#include <stdio.h>
#include <stdlib.h>
#include "stack_second.h"

int stack_top = 0;

int push(int** stack, int numberToPush)
{
	int retValue = 0;

	if (isFull())
	{
		puts("Stack 이 다 찼습니다.");
	}
	else
	{
		// Push 할 내용을 malloc 을 써서 추가

		retValue = true;
	}

	return retValue;
}

int pop(int** stack)
{
	int numberToBePoped = 0;

	if (isEmpty())
	{
		puts("Stack 이 비었습니다");
	}
	else
	{
		// Pop 한 내용을 free 로 제거
	}
	
	return numberToBePoped;
}

void print_stack(int** stack)
{
	int i = 0;

	puts("== Stack 내용 출력 ==");
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
	return MAX_STACK_NUM <= stack_top;	//	명색상 NULL
}

int isEmpty()
{
	return stack_top <= 0;
}

void cleanStack(int** stack)
{
	printf("Memory 관리를 위해 남은 Stack 들을 pop() 으로 정리합니다...\n");
	while(!isEmpty())
	{
		pop(stack);
	}
}