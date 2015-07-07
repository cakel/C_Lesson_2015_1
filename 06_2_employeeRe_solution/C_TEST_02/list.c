#include "list.h"
#include <stdlib.h>
#include <string.h>


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
	Node* toBeInserted = NULL;

	if(head == NULL || tp == NULL)
		return;

	toBeInserted = head->next;

	if(head->next == NULL)
	{
		head->next = tp;
	}
	else
	{
		while(toBeInserted->next != NULL)
		{
			toBeInserted = toBeInserted->next;
		}

		toBeInserted->next = tp;
	}
}

// Desc : Sorting the list
// Param : head - head pointer of linked list, tp - node to be sorted
// Return : None
void sort_list(Node *head)
{
	

    // TODO: Write code here
	Node* startNode		= head->next, *compareNode = NULL;
	Employee* swapData	= NULL;
	
	if(head->next == NULL)
		return;

	for(startNode = head->next; startNode != NULL; startNode = startNode->next)
	{
		for(compareNode = startNode; compareNode != NULL; compareNode = compareNode->next)
		{
			if(strcmp(startNode->data->emp_no, compareNode->data->emp_no) == 1)
			{
				swapData = startNode->data;
				startNode->data = compareNode->data;
				compareNode->data = swapData;
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
	Node* toBefreedNode = head, *toBeRemovedNode = NULL;

	if(head == NULL || tp == NULL)
		return;

	toBeRemovedNode = head;

	if(strcmp(head->next->data->emp_no, tp->data->emp_no) == 0)
	{
		toBefreedNode = head->next;
		head->next = head->next->next;
		free(toBefreedNode);
	}
	else
	{
		while(toBeRemovedNode->next != NULL)
		{
			if(strcmp(	toBeRemovedNode->next->data->emp_no,
						tp->data->emp_no) == 0)
			{
				break;
			}

			toBeRemovedNode = toBeRemovedNode->next;
		}

		toBefreedNode = toBeRemovedNode->next;
		toBeRemovedNode->next = toBeRemovedNode->next->next;

		if(toBefreedNode->data->name != NULL)
			free(toBefreedNode->data->name);

		if(toBefreedNode->data != NULL)
			free(toBefreedNode->data);
		
		free(toBefreedNode);
	}
}

// Desc : Finding the node in position of the index
// Param : head - head pointer of linked list, new_emp_no - employee number to find
// Return : Node contains new_emp_no, NULL if not found
Node *find_node(Node *head, char *new_emp_no)
{


    // TODO: Write code here
	Node* findNode = head->next;

	while(findNode != NULL)
	{
		if(strcmp(findNode->data->emp_no, new_emp_no) == 0)
		{
			break;
		}

		findNode = findNode->next;
	}

	if(findNode != NULL)
	{
		return findNode;
	}
	else
	{
		return NULL;
	}
}

// Desc : Deallocate all the momory of list
// Param : head - head pointer of linked list
// Return : None
void deallocate_list(Node *head)
{
    
    // TODO: Write code here
	Node* toBeFreedNode = NULL;

	while(head->next != NULL)
	{
		if(head->next->data->name != NULL)
		{
			free(head->next->data->name);
			head->next->data->name = NULL;
	
		}

		if(head->next->data != NULL)
		{
			free(head->next->data);
			head->next->data = NULL;
		}

		toBeFreedNode = head->next;
		head->next = head->next->next;

		free(toBeFreedNode);
		
	}

	if(head != NULL)
		free(head);

}

