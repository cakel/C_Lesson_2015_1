#include <stdio.h>
#include "model_data.h"
#include "view_draw.h"
#include "view_hotel.h"
#include "common.h"

struct MENU_STRUCTURE MENU_STRUCTURE_TBL[] =
{
	{ SELECT_DISPLAY_FULL_DETAILS,		"Display Full Menu & Values",	view_displayFullDetails },
	{ SELECT_CHANGE_VALUE,				"Change Value",					view_changeValue },
	{ SELECT_DEFAULT_MENU_VALUES,		"Return to Default Values",		view_returnDefaultValues },
	{ SELECT_LOAD_MENU_VALUES,			"Load Values from File",		view_loadValuesFromFile },
	{ SELECT_SAVE_MENU_VALUES,			"Save Values to File",			view_saveValuesToFile },
	{ SELECT_EXIT,						"Exit",							view_exit},
};

void view_displayMenu()
{
	unsigned int menuIndex = 0;
	puts("============================");
	for(menuIndex = 0; menuIndex < TBL_NUM(MENU_STRUCTURE_TBL); menuIndex++)
	{
		printf("(%d)\t%s\n",	MENU_STRUCTURE_TBL[menuIndex].menuItem,
								MENU_STRUCTURE_TBL[menuIndex].menuString);
	}
	puts("============================");
}

MENU_ITEM_T view_selectTheMenu(void)
{
	int inputedCount			= 0;
	MENU_ITEM_T selectedMenu	= SELECT_UNKNOWN;

	printf("Select the Menu : ");
	inputedCount = scanf_s("%d", &selectedMenu);

	if(inputedCount == 0)
	{
		puts("Nothing Inputed...");
	}
	else
	{
		if(selectedMenu < SELECT_EXIT)
		{
			MENU_STRUCTURE_TBL[selectedMenu].fnCallback();
		}
	}
	
	fflush(stdin);
	return selectedMenu;
}

void view_displayFullDetails(void)
{
	puts("--");
	view_hotel_displayDetails(HOTEL,
		HOTEL_VOL, HOTEL_KEY, HOTEL_POWER,
		HOTEL_END);
	puts("--");
}

void view_goToTop(void)
{

}

void view_changeValue(void)
{
}

void view_returnDefaultValues(void)
{
}

void view_loadValuesFromFile(void)
{
}

void view_saveValuesToFile(void)
{
}

void view_exit(void)
{
}

