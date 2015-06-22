#include <stdio.h>
#include "model_data.h"
#include "common.h"
#include <stdlib.h>

static struct Node* top = NULL;

struct Node* getTopNode()
{
	return top;
}

void model_initialize(void)
{
	// Nothing to initialize
	return;
}

void model_finalize(void)
{
	// Free Stack

	// Free Array

	return;
}

// Stack
boolean		model_stack_push(int data)
{
	boolean success = false;
	struct Node* topNode = getTopNode();
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

		success = true;
	}
	else
	{
		newNode->next = topNode;
		topNode = newNode;

		success = true;
	}

	return success;
}
boolean			model_stack_pop(int* poppedValue)
{
	struct Node* topNode = getTopNode();
	struct Node* beFreedNode = NULL;
	boolean success = false;

	if (model_stack_empty() && poppedValue != NULL)
	{
		*poppedValue = topNode->number;
		beFreedNode = topNode;
		topNode = topNode->next;
		free(beFreedNode);
		success = true;
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
boolean model_array_build(int** resultArray)
{
	// Parameter may be changed
	return false;
}
boolean model_array_bubblesort(int** toBeSortedArray)
{
	// Parameter may be changed
	return false;
}
