#include <stdio.h>
#include "common.h"
#include "model_file.h"
#include "model_data.h"
#include <stdlib.h>

boolean model_file_read(char* fileName, FILE* readFp)
{
	boolean success = false;

	if(readFp != NULL && model_file_buildStack(readFp) == true)
	{
		printf("make a stack from file[%s] was success\n", fileName);
	}
	else
	{
		printf("make a stack from file[%s] was failed\n", fileName);
	}

	return success;
}
boolean model_file_write(char* fileName,FILE* writeFp)
{
	boolean success = false;
	struct Node* stack = model_stack_getTopNode();

	if(writeFp == NULL)
	{
		puts("make a stack from file was failed");
		return success;
	}

	for(;stack;stack = stack->next)
	{
		fprintf(writeFp, "%d", stack->number);

		if(stack->next != NULL)
			fputc('\n',writeFp);
	}

	return success;
}
boolean model_file_buildStack(FILE* readFp)
{
	boolean success = false;
	char readBuffer[255] = {0};

	if(readFp != NULL)
	{
		while(fgets(readBuffer, 255, readFp) != 0)
		{
			model_stack_push(atoi(readBuffer));
		}

		success = true;
	}

	return success;
}
