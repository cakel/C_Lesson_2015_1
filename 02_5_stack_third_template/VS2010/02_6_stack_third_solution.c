#include <stdio.h>
#include <stdlib.h>

typedef struct Node;

struct Node
{
	int Data;
	struct Node *next;
} Node_T;

struct Node* top;

void popStack()
{
	struct Node* tmp, *var = top;
	if(var == top)
	{
		top = top->next;
		free(var);
	} else
	{
		printf("Stack Empty\n");
	}
}

void push(int value)
{
	struct Node *temp;
	temp = (struct Node*)malloc(sizeof(*temp));
	temp->Data = value;

	if(top == NULL)
	{
		top = temp;
		top->next = NULL;
	}
	else
	{
		temp->next = top;
		top = temp;
	}
}

void display()
{
	struct Node *var = top;
	if(var != NULL)
	{
		printf("Elements are as :\n");
		while(var != NULL)
		{
			printf("\t%d\n", var->Data);
			var = var->next;
		}
	}
	puts("");
}

int main(void)
{
	int i = 0;
	struct Node *temp = NULL;
	top = NULL;

	puts("1. Push to Stack");
	puts("2. Pop from Stack");
	puts("3. Display data of Stack");
	puts("4. Exit\n");

	while(1)
	{
		printf("Choose Option : ");
		scanf_s("%d", &i);
		switch(i)
		{
			case 1:
			{
				int value;
				printf("Enter a number to push into Stack : ");
				scanf_s("%d", &value);
				push(value);
				display();
				break;
			}
			case 2:
			{
				popStack();
				display();
			}
			case 3:
			{
				display();
			}
			case 4:
			{
				while(top != NULL)
				{
					temp = top->next;
					free(top);
					top = temp;
				}
			}
		}
	}
}