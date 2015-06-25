#ifndef _MODEL_DATA_H_
#define _MODEL_DATA_H

#include "common.h"

// Start, End
void model_initialize(void);
void model_finalize(void);

// Stack
boolean			model_stack_push(int);
int				model_stack_pop(int*);
boolean			model_stack_empty(void);
boolean			model_stack_full(void);
int				model_stack_count(void);
struct Node*	model_stack_getTopNode(void);


// Array and Sort
boolean		model_array_build(void);
boolean		model_array_bubblesort(void);
void		model_array_print(void);
void		model_array_clear(void);

// Stack
typedef struct Node;
typedef struct Node
{
	int number;
	struct Node* next;

} Node_T;

#endif