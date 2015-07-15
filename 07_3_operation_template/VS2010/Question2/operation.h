#ifndef _OPERATION_H_
#define _OPERATION_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_BUFFER (128)
#define INPUT_LENGTH (41)

typedef enum INPUT_VALIDITY {
	INPUT_INVALID = 0, 
	INPUT_VALID
} INPUT_VALIDITY_T;

typedef struct tagNum
{
    char input[INPUT_LENGTH];   // 변수 선언 필요..
    int dummy;  // dummy 파일
}Num;

int getTwoInput(Num* numInput1, Num* numInput2);

void function1(Num* num1, Num* num2, Num* numResult);
void function2(Num* num1, Num* num2, Num* numResult);
void function3(Num* num1, Num* num2, Num* numResult);
void function4(Num* num1, Num* num2, Num* numResult);
void function5(Num* num1, Num* num2, Num* numResult);
void printResult(Num* num1, Num* num2, Num* numResult);

void plus(Num* num1, Num* num2, Num* numResult);
void append(Num* num1, Num* num2, Num* numResult);
void reverse(Num* num1, Num* numResult);
void combination1(Num* num1, Num* num2, Num* numResult);
void combination2(Num* num1, Num* num2, Num* numResult);

#endif
