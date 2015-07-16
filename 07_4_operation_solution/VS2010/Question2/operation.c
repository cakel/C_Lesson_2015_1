#include "operation.h"


int getTwoInput(Num* numInput1, Num* numInput2)
{
	char buffer1[MAX_WORD_BUFFER] = {0,};
	char buffer2[MAX_WORD_BUFFER] = {0,};
	
	char buffer1nonzero[MAX_WORD_BUFFER] = {0,};
	char buffer2nonzero[MAX_WORD_BUFFER] = {0,};
	
	int i_buffer1=0;
	int i_buffer2=0;

	memset(numInput1->input, 0x00, INPUT_LENGTH);
	memset(numInput2->input, 0x00, INPUT_LENGTH);

	printf("Input two numbers :");
	
	scanf("%s %s", &buffer1, &buffer2);
	if(strlen(buffer1)>20 || strlen(buffer2)>20)
	{
		printf("Max digit is 20. Try again.\n\n");
		return INPUT_INVALID;
	}
	else
	{
		// deleting initial '0' value from numInput1
		for(i_buffer1=0; i_buffer1<MAX_WORD_BUFFER-1; i_buffer1++)
		{
			if(*(buffer1+i_buffer1)=='0' && *(buffer1+i_buffer1+1)!='0')
				break;
		}		
		if(i_buffer1==MAX_WORD_BUFFER-1)
		{
			strncpy(buffer1nonzero, buffer1, strlen(buffer1));
		}
		else
		{
			strncpy(buffer1nonzero, buffer1+i_buffer1+1, strlen(buffer1+i_buffer1+1));
		}
		
		// deleting initial '0' value from numInput2
		for(i_buffer2=0; i_buffer2<MAX_WORD_BUFFER-1; i_buffer2++)
		{
			if(*(buffer2+i_buffer2)=='0' && *(buffer2+i_buffer2+1)!='0')
				break;
		}		
		if(i_buffer2==MAX_WORD_BUFFER-1)
		{
			strncpy(buffer2nonzero, buffer2, strlen(buffer2));
		}
		else
		{
			strncpy(buffer2nonzero, buffer2+i_buffer2+1, strlen(buffer2+i_buffer2+1));
		}

		strncpy(numInput1->input, buffer1nonzero, strlen(buffer1nonzero));
		strncpy(numInput2->input, buffer2nonzero, strlen(buffer2nonzero));
		return INPUT_VALID;
	}
}

void function1(Num* num1, Num* num2, Num* numResult)
{
	plus(num1, num2, numResult);
}
void function2(Num* num1, Num* num2, Num* numResult)
{
	append(num1, num2, numResult);
}
void function3(Num* num1, Num* num2, Num* numResult)
{
	reverse(num1, numResult);
}
void function4(Num* num1, Num* num2, Num* numResult)
{
	
	//(123 + 123) @ (!248) = 246842
	int i=0;
	Num numTemp[2];
	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	for(i=0; i<2; i++)
	{
		memset(numTemp[i].input, 0x00, INPUT_LENGTH);
	}

	plus(num1, num1, &(numTemp[0]));
	reverse(num2, &(numTemp[1]));
	append(&(numTemp[0]), &(numTemp[1]), numResult);

}

void function5(Num* num1, Num* num2, Num* numResult)
{
	//!(123 @ 248) + (!123 @ !248) = 1164163
	int i=0;
	Num numTemp[5];
	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	for(i=0; i<5; i++)
	{
		memset(numTemp[i].input, 0x00, INPUT_LENGTH);
	}

	append(num1, num2, &(numTemp[0]));
	reverse(&(numTemp[0]), &(numTemp[1]));
	reverse(num1, &(numTemp[2]));
	reverse(num2, &(numTemp[3]));
	append(&(numTemp[2]), &(numTemp[3]), &(numTemp[4]));
	plus(&(numTemp[1]), &(numTemp[4]), numResult);
}


void plus(Num* num1, Num* num2, Num* numResult)
{
	unsigned long int iNumber1 = atoi(num1->input);
	unsigned long int iNumber2 = atoi(num2->input);
	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	itoa (iNumber1+iNumber2,numResult->input,10);

	//printf("%s + %s = %s\n",num1->input, num2->input, numResult->input);
}


void append(Num* num1, Num* num2, Num* numResult)
{	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	strcat(numResult->input, num1->input);
	strcat(numResult->input, num2->input);

	//printf("%s @ %s = %s\n",num1->input, num2->input, numResult->input);
}

void reverse(Num* num1, Num* numResult)
{
	int i=0;
	int NUM_LENGTH = strlen(num1->input);
	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	for(i=0; i<NUM_LENGTH ; i++)
	{
		numResult->input[i] = num1->input[NUM_LENGTH-1-i];
	}
	//printf("!%s = %s\n",num1->input, numResult->input);
}

void combination1(Num* num1, Num* num2, Num* numResult)
{
	//(123 + 123) @ (!248) = 246842
	int i=0;
	Num numTemp[2];
	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	for(i=0; i<2; i++)
	{
		memset(numTemp[i].input, 0x00, INPUT_LENGTH);
	}

	plus(num1, num1, &(numTemp[0]));
	reverse(num2, &(numTemp[1]));
	append(&(numTemp[0]), &(numTemp[1]), numResult);

	//printf("(%s + %s) @ (!%s) = %s\n",num1->input, num1->input, num2->input, numResult->input);
}


void combination2(Num* num1, Num* num2, Num* numResult)
{
	//!(123 @ 248) + (!123 @ !248) = 1164163
	int i=0;
	Num numTemp[5];
	
	memset(numResult->input, 0x00, INPUT_LENGTH);

	for(i=0; i<5; i++)
	{
		memset(numTemp[i].input, 0x00, INPUT_LENGTH);
	}

	append(num1, num2, &(numTemp[0]));
	reverse(&(numTemp[0]), &(numTemp[1]));
	reverse(num1, &(numTemp[2]));
	reverse(num2, &(numTemp[3]));
	append(&(numTemp[2]), &(numTemp[3]), &(numTemp[4]));
	plus(&(numTemp[1]), &(numTemp[4]), numResult);

	//printf("!(%s @ %s) + (!%s @ !%s) = %s\n",num1->input, num2->input, num1->input, num2->input, numResult->input);
}

void printResult(Num* num1, Num* num2, Num* numResult)
{
	printf("(1. ADD         ) %s + %s = %s\n",num1->input, num2->input, numResult[0].input);
	printf("(2. APPEND      ) %s @ %s = %s\n",num1->input, num2->input, numResult[1].input);
	printf("(3. REVERSE     ) !%s = %s\n",num1->input, numResult[2].input);
	printf("(4. COMBINATION1) (%s + %s) @ (!%s) = %s\n",num1->input, num1->input, num2->input, numResult[3].input);
	printf("(5. COMBINATION2) !(%s @ %s) + (!%s @ !%s) = %s\n",num1->input, num2->input, num1->input, num2->input, numResult[4].input);
	printf("\n");
}