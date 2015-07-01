#include <stdio.h>
#include "model_data.h"
#include "view_draw.h"
#include "view_hotel.h"
#include "common.h"
#include <string.h>
#include <stdlib.h>

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
	view_hotel_setDisplayedHotelModeOperation(false);
	puts("---");
	// Recursive from top level to last level
	view_hotel_displayDetails(HOTEL,
		HOTEL_VOL, HOTEL_KEY, HOTEL_POWER,
		HOTEL_END);
	puts("---");
}

void view_changeValue(void)
{
	unsigned int	index			= 0;
	unsigned int	tryToChange		= 0;
	HOTEL_UI_T*		selectedUiItem	= NULL;
	printf("Which index do you want to change ? : ");

	if (scanf_s("%d", &index) == 0)
	{
		puts("No number index is inputed...");
	}
	else
	{
		if (	index < HOTEL_END &&
			(	selectedUiItem = hotel_getItemInformation(index)) != NULL)
		{
			printf("(%d)[%s] Change value from (%d) to : ", 
					selectedUiItem->hotelMode_Index,
					selectedUiItem->hotelMode_ItemName,
					hotel_getValue(selectedUiItem->hotelMode_Index));
			if (scanf_s("%d", &tryToChange) == 0)
			{
				puts("No number value is inputed...");
			}
			else
			{
				if (hotel_setValue(selectedUiItem->hotelMode_Index, tryToChange) == true)
				{
					printf("Changing value(%d) is success\n", tryToChange);
				}
			}
		}
	}
}

void view_returnDefaultValues(void)
{
	HOTEL_MENUITEM_T index = HOTEL;
	for (index = 0; index < HOTEL_END; index++)
	{
		hotel_setValue(index, hotel_getItemInformation(index)->hotelMode_defaultValue);
	}
	
	puts("Default Value restored...");
}

void view_loadValuesFromFile(void)
{
	HOTEL_MENUITEM_T index = HOTEL;
	FILE *fp = NULL;
	char readBuf[255] = { 0 };
	char* tok = NULL, *nextContent = NULL;
	unsigned int value = 0;
	if (fopen_s(&fp, "hotel_data.txt", "rt") != 0)
	{
		puts("Opening hotel_data.txt is error");
	}
	else
	{
		while (fgets(readBuf, 255, fp) != NULL)
		{
			tok = strtok_s(readBuf, ",\n\r", &nextContent);
			index = atoi(tok);

			tok = strtok_s(NULL, ",\n\r", &nextContent);
			value = atoi(tok);

			hotel_setValue(index, value);
		}

		puts("Reading hotel_data.txt is successful");
	}
}

void view_saveValuesToFile(void)
{
	HOTEL_MENUITEM_T index = HOTEL;
	FILE *fp = NULL;
	if (fopen_s(&fp, "hotel_data.txt", "wt") != 0)
	{
		puts("Opening hotel_data.txt is error");
	}
	else
	{
		for (index = HOTEL; index < HOTEL_END; index++)
		{
			fprintf(fp, "%d,%d", index, hotel_getValue(index));

			if (index != HOTEL_END - 1)
			{
				fputc('\n', fp);
			}
		}
		fclose(fp);
		puts("Saving hotel_data.txt is successful");
	}

}

void view_exit(void)
{
}

