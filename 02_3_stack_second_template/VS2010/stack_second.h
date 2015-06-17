#define true	(1)
#define false	(0)
#define	MAX_STACK_NUM	200

int push(int** stack, int numberToPush);
int pop(int** stack);
void print_stack(int** stack);
int isFull(void);
int isEmpty(void);
void cleanStack(int** stack);