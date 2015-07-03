#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// Desc : Initializing a linked list
// Param : head - head pointer of linked list
// Return : None
void init_list(Node **head)
{
    *head = (Node*)malloc(sizeof(Node));
	(*head)->data = 0;
	(*head)->next = NULL;
}

// Desc : Making a new node contaning the employee
// Param : ep - menu to be contained
// Return : Node dynamically allocated
Node* new_node(Employee* ep)
{
    Node *tp;
    
    tp=(Node *)malloc(sizeof(Node));
    tp->data = ep;
    tp->next=NULL;
    
    return tp;
}

// Desc : Inserting node to list
// Param : head - head pointer of linked list, tp - node to be inserted
// Return : None
void insert_node(Node* head, Node *tp)
{

    // TODO: Write code here
	Node* toBeAppended = head->next;

	if(find_node(head, tp->data->emp_no) != NULL)
	{
		puts("이미 존재합니다.");
	}

	if(toBeAppended == NULL)
	{
		head->next = tp;
	}
	else
	{
		// Append
		while(toBeAppended->next != NULL)
		{
			toBeAppended = toBeAppended->next;
		}
		toBeAppended->next = tp;
	}
}

// Desc : Sorting the list
// Param : head - head pointer of linked list, tp - node to be sorted
// Return : None
void sort_list(Node *head)
{

    // TODO: Write code here
	int nodeCount = 0, i = 0, j = 0;
	Node* startNode = head, *secondNode = NULL;
	Employee *swapEmployee = NULL;

	while (startNode->next != NULL)
	{
		startNode = startNode->next;
		nodeCount++;
	}

	// Reset Node
	startNode = head->next;

	// Bubble Sort	
	for (i = 0; i < nodeCount - 1; i++)
	{
		for (j = 0;
			startNode != NULL && j < nodeCount - 1 - i;
			j++)
		{
			secondNode = startNode;

			while (secondNode->next)
			{
				if (strcmp(secondNode->data->emp_no, secondNode->next->data->emp_no) == 1)
				{
					swapEmployee = secondNode->data;
					secondNode->data = secondNode->next->data;
					secondNode->next->data = swapEmployee;
				}
				secondNode = secondNode->next;
			}
		}
	}
}

// Desc : Removing a node from list
// Param : head - head pointer of linked list, tp - node to be removed
// Return : None
void remove_node(Node* head, Node *tp)
{
    // TODO: Write code here
	Node* preNode = head, *searchNode = head->next;

	if (head == NULL || tp == NULL)
	{
		puts("Either head or tp is NULL");
	}
	// Head

	while (searchNode)
	{
		if (strcmp(searchNode->data->emp_no, tp->data->emp_no) == 0)
		{
			preNode->next = tp->next;
			free(tp);
			tp = NULL;
			break;
		}

		preNode		= searchNode;
		searchNode	= searchNode->next;
	}

}

// Desc : Finding the node in position of the index
// Param : head - head pointer of linked list, new_emp_no - employee number to find
// Return : Node contains new_emp_no, NULL if not found
Node *find_node(Node *head, char *new_emp_no)
{


    // TODO: Write code here
	Node* foundNode = NULL, *searchNode = head->next;

	while(searchNode != NULL)
	{
		if(strcmp(searchNode->data->emp_no, new_emp_no) == 0)
		{
			foundNode = searchNode;
			break;
		}
		searchNode = searchNode->next;
	}

	if(searchNode != NULL)
		return searchNode;
	else
		return NULL;
}

// Desc : Deallocate all the momory of list
// Param : head - head pointer of linked list
// Return : None
void deallocate_list(Node *head)
{
    // TODO: Write code here
	Node* toBeDeleted = head->next;

	while (head->next != NULL)
	{
		toBeDeleted	= head->next;
		head->next	= head->next->next;
		free(toBeDeleted);
	}

}

