#include "view_draw.h"

void startApplication(void)
{
	MENU_ITEM_T menuItem = SELECT_UNKNOWN;
	while (menuItem != SELECT_EXIT)
	{
		view_displayMenu();
		menuItem = view_selectTheMenu();
	}	
}

int main()
{
	startApplication();	
}