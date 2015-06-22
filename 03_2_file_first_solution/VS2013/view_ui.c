#include <stdio.h>
#include "view_ui.h"
#include "model_data.h"

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

}
void view_writeAFileFromStack(void) /* 2 */
{

}

void view_displayStack(void) /* 3 */
{
	puts("Display Stack...");
	struct Node* topNode = getTopNode();
	for (int i = 0; i < model_stack_count(); i++)
	{
		printf("%d\n", topNode);
	}
}

void view_clearStack() /* 4 */
{

}
void view_pushANumber(void) /* 5 */
{
	int toBeEntered = 0;

}
void view_popANumber(void) /* 6 */
{

}
void view_makeAnArrayFromStack(void) /* 7 */
{

}
void view_displayArray(void) /* 8 */
{

}
void view_doBubbleSort(void) /* 9 */
{

}
void view_exit(void) /* 10 */
{
	// Do Nothing
}
