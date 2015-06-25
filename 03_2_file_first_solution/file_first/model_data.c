#include <stdio.h>
#include "model_data.h"
#include "view_ui.h"
#include "common.h"
#include <stdlib.h>

static struct Node* top = NULL;
static int* array = NULL;

struct Node* model_stack_getTopNode()
{
	return top;
}

void model_initialize(void)
{
	top = NULL;
	array = NULL;
	// Nothing to initialize
	return;
}

void model_finalize(void)
{
	// Free Stack
	view_clearStack();

	// Free Array
	model_array_clear();

	return;
}

// Stack
boolean		model_stack_push(int data)
{
	boolean success = false;
	struct Node* topNode = model_stack_getTopNode();
	struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node) * 1));

	if (newNode == NULL)
	{
		puts("Failed to make a node...");
	}
	else if (model_stack_empty())
	{
		topNode = newNode;
		topNode->next = NULL;
		topNode->number = data;
		top = topNode;

		success = true;
	}
	else
	{
		newNode->next = top;
		newNode->number = data;
		top = newNode;
		// topNode = newNode;

		success = true;
	}

	return success;
}
boolean			model_stack_pop(int* poppedValue)
{
	// struct Node* topNode = getTopNode();
	struct Node* beFreedNode = NULL;
	boolean success = false;

	if (model_stack_empty() == false && poppedValue != NULL)
	{
		*poppedValue = top->number;
		beFreedNode = top;
		top = top->next;
		if(beFreedNode)
		{
			free(beFreedNode);
			beFreedNode = NULL;
		}
		success = true;

		puts("Pop success...");
	}

	return success;
}
boolean		model_stack_empty(void)
{
	return top == NULL;
}
boolean		model_stack_full(void)
{
	// Always false because Stack node is made from Heap memory
	return false;
}
int	model_stack_count(void)
{
	struct	Node* startNode = top;
	int		count = 0;

	while (startNode != NULL)
	{
		startNode = startNode->next;
		count++;
	}
	
	return count;
}

// Array and Sort
boolean model_array_build(void)
{
	boolean success = false;
	int i = 0;
	struct Node* node = model_stack_getTopNode();

	array = (int*) malloc(sizeof(int) * model_stack_count());

	if(array != NULL)
	{
		while(node != NULL)
		{
			array[i++] = node->number;
			node = node->next;
		}
		puts("make an array from stack was success...");

		success = true;
	}
	
	// Parameter may be changed
	return success;
}
boolean model_array_bubblesort(void)
{
	int maxCount = model_stack_count();
	int i,j, temp = 0;
	boolean success = false;
	if (array == NULL)
	{
		puts("not converted...");
		return success;
	}

	for(i = 0; i < maxCount - 1; i++)
	{
		for(j = 0; j < maxCount - 1 - i; j++)
		{
			if(array[j] > array[j+1])	// 오름차순
			{
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}

	success = true;

	return success;
}

void model_array_print(void)
{
	int maxIndex = model_stack_count();
	int i = 0;

	if(array == NULL)
	{
		puts("Array is not converted...");
		return;
	}

	for(i = 0; i < maxIndex; i++)
	{
		printf("%d ", array[i]);
	}

	puts("");
}

void model_array_clear(void)
{
	if(array != NULL)
	{
		free(array);
		array = NULL;
	}
}