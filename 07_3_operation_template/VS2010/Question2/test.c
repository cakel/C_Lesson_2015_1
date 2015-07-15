#include <stdio.h>
#include "operation.h"

void display_menu(void);
void exit_routine(void);

int main() {
	int sel = -1;
	char buffer[INPUT_LENGTH];
	int isInputValid = INPUT_INVALID;
	Num Num1;
	Num Num2;
	Num NumResult[5];

	for(;;) {
		display_menu();
		fflush(stdin);		
		
		while(1) {
			isInputValid = getTwoInput(&Num1, &Num2);			
			
			if(isInputValid == INPUT_INVALID) {
				printf("Please input again...\n");
			} else {
				break;
			}
			
		}
		function1(&Num1, &Num2,	&(NumResult[0]));
		function2(&Num1, &Num2,	&(NumResult[1]));
		function3(&Num1, &Num2,	&(NumResult[2]));
		function4(&Num1, &Num2,	&(NumResult[3]));
		function5(&Num1, &Num2,	&(NumResult[4]));
		
		printResult(&Num1, &Num2, NumResult);
		
	}
	printf("종료합니다.\n");
	getchar();

	return 0;
}


void display_menu(void){
}



void exit_routine(void){
}