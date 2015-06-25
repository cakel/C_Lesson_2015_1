#include <stdio.h>
#include "view_ui.h"
#include "model_data.h"
#include "model_file.h"
#include "string.h"

void view_displayMenu()
{
	puts("=========================");
	puts("1. Make a stack from File");
	puts("2. Write a file from Stack");
	puts("3. Display Stack");
	puts("4. Clear Stack");
	puts("5. Push a Number");
	puts("6. Pop a Number");
	puts("7. Make an Array from Stack");
	puts("8. Display the Converted Array.");
	puts("9. Do Bubblesort to Array");
	puts("10. Exit");
	puts("=========================");
}

void view_frontEnd(void)
{
	int selectedItem = 0;
	while (selectedItem != 10)
	{
		view_displayMenu();
		selectedItem = view_selectMenu();

		switch (selectedItem)
		{
			case 1:
				view_makeAStackFromFile();
				break;
			case 2:
				view_writeAFileFromStack();
				break;
			case 3:
				view_displayStack();
				break;
			case 4:
				view_clearStack();
				break;
			case 5:
				view_pushANumber();
				break;
			case 6:
				view_popANumber();
				break;
			case 7:
				view_makeAnArrayFromStack();
				break;
			case 8:
				view_displayArray();
				break;
			case 9:
				view_doBubbleSort();
				break;
			case 10:
				view_exit();
				break;
			default:
				break;
		}

	}

}

int view_selectMenu(void)
{
	int menuItem = 0;
	printf("Select the Menu : ");
	scanf_s("%d", &menuItem);
	fflush(stdin);
	return menuItem;
}

void view_makeAStackFromFile(void) /* 1 */
{
	char inputFile[255] = {0};
	FILE *fp = NULL;

	printf("Enter filename to read [default - stack.txt] : ");
	scanf_s("%s", inputFile, 255);

	if(strcmp(inputFile, "") == 0)
	{
		strncpy_s(inputFile, 255, "stack.txt", strlen("stack.txt"));
	}

	if(fopen_s(&fp, inputFile, "rt") == 0)
	{
		model_file_read(inputFile, fp);
		fclose(fp);
	}
	else
	{
		puts("read a file was failed...");
	}
}
void view_writeAFileFromStack(void) /* 2 */
{
	char inputFile[255] = {0};
	FILE *fp = NULL;

	printf("Enter filename to write [default - stack.txt] : ");
	scanf_s("%s", inputFile, 255);

	if(strcmp(inputFile, "") == 0)
	{
		strncpy_s(inputFile, 255, "stack.txt", strlen("stack.txt"));
	}

	if(fopen_s(&fp, inputFile, "wt") == 0)
	{
		model_file_write(inputFile, fp);
		fclose(fp);
	}
	else
	{
		puts("read a file was failed...");
	}
}

void view_displayStack(void) /* 3 */
{
	int i = 0;
	struct Node* printNode = model_stack_getTopNode();

	puts("Display Stack...");
	for (;printNode ;printNode = printNode->next)
	{
		printf("%d\n", printNode->number);
	}
}

void view_clearStack() /* 4 */
{
	int poppedValue = 0;

	while(model_stack_empty() != true)
	{
		model_stack_pop(&poppedValue);
	}
}
void view_pushANumber(void) /* 5 */
{
	int toBeEntered = 0;

	printf("Enter a number to be pushed : ");

	if(scanf_s("%d", &toBeEntered) != 0)
	{
		model_stack_push(toBeEntered);
	}
	else
	{
		puts("nothing to push");
	}

	fflush(stdin);
}
void view_popANumber(void) /* 6 */
{
	int bePoppedValue = 0;
	if(model_stack_pop(&bePoppedValue))
	{
		printf("Popped value was %d\n", bePoppedValue);
	}
	else
	{
		puts("pop failed...");
	}
}
void view_makeAnArrayFromStack(void) /* 7 */
{
	if(model_array_build() == true)
	{
		puts("build was success...");
	}
	else
	{
		puts("build was fail...");
	}
}
void view_displayArray(void) /* 8 */
{
	model_array_print();
}
void view_doBubbleSort(void) /* 9 */
{
	model_array_bubblesort();


}
void view_exit(void) /* 10 */
{
	// Do Nothing
}
