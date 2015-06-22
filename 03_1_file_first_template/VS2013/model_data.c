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
	// Nothing to initialize (?)
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

	// Malloc a Node and push by data

	return success;
}
boolean			model_stack_pop(int* poppedValue)
{
	struct Node* topNode = getTopNode();
	boolean success = false;

	// Save a value to poppedValue from Top Node and free Top Node

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

	/*
	
	Stack
	1
	3
	2
	5
	0
	
	Array -> malloc with model_stack_count size -> 1 3 2 5 0
	*/

	return false;
}
boolean model_array_bubblesort(int** toBeSortedArray)
{
	// Parameter may be changed

	// 1 3 2 5 0 -> 0 1 2 3 5

	return false;
}
