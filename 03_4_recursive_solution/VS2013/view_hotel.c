#include <stdio.h>
#include <stdarg.h>
#include "model_data.h"
#include "common.h"

static unsigned displayedHotelModeOperation = false;

void view_hotel_displayDetails(HOTEL_MENUITEM_T item_list, ...)
{
	unsigned int i = 0;	
	HOTEL_MENUITEM_T nextUiItemIndex = HOTEL_END;
	HOTEL_UI_T *startUiItem = NULL, *nextUiItem = NULL;
	va_list va_item_list;
	va_start(va_item_list,item_list);

	startUiItem = hotel_getItemInformation(item_list);
	if (startUiItem != NULL && displayedHotelModeOperation == false)
	{
		// 첫 호출 때에만 부르는 Caller 의 정보만 출력, 이후 재귀 호출시 사용하지 않음
		displayedHotelModeOperation = true;
		printf("(%d)", startUiItem->hotelMode_Index);
		for(i = 0; i < startUiItem->hotelMode_level; i++)
			putchar('\t');

		printf("[%s]",		startUiItem->hotelMode_ItemName);
		printf("(%d)\n",	hotel_getValue(startUiItem->hotelMode_Index));
	}

	nextUiItemIndex = va_arg(va_item_list, HOTEL_MENUITEM_T);

	while(nextUiItemIndex != HOTEL_END)
	{
		nextUiItem = hotel_getItemInformation(nextUiItemIndex);
	
		if(nextUiItem != NULL)
		{
			printf("(%d)", nextUiItem->hotelMode_Index);
			for(i = 0; i < nextUiItem->hotelMode_level; i++)
				putchar('\t');

			printf("[%s]",		nextUiItem->hotelMode_ItemName);
			printf("(%d)\n",	hotel_getValue(nextUiItem->hotelMode_Index));

			if(nextUiItem->pfnSubMenuDisplayCallback != NULL)
			{
				nextUiItem->pfnSubMenuDisplayCallback();
			}
		}

		nextUiItemIndex = va_arg(va_item_list, HOTEL_MENUITEM_T);

	}

	va_end(va_item_list);
}

void view_hotel_setDisplayedHotelModeOperation(boolean value)
{
	displayedHotelModeOperation = value;
}

void view_hotel_volume(void){
	view_hotel_displayDetails(HOTEL_VOL,
		HOTEL_VOL_START, HOTEL_VOL_MAXIMUM, HOTEL_VOL_MINIMUM,
		HOTEL_END);	
}
void view_hotel_volume_start(void){
	//	No More Submenu to view
}
void view_hotel_volume_maximum(void){
	//	No More Submenu to view
}
void view_hotel_volume_minumum(void){
	//	No More Submenu to view
}
void view_hotel_key(void){
	view_hotel_displayDetails(HOTEL_KEY,
		HOTEL_KEY_IROPERATION, HOTEL_KEY_LOCALKEYOPERATION,
		HOTEL_END);
}
void view_hotel_key_ir(void){
	//	No More Submenu to view
}		
void view_hotel_key_local(void){
	//	No More Submenu to view
}
void view_hotel_power(void){
	view_hotel_displayDetails(HOTEL_POWER,
		HOTEL_POWER_INPUT, HOTEL_POWER_AVSETTING,
		HOTEL_END);
}
void view_hotel_input(void){
	//	No More Submenu to view
}
void view_hotel_av(void){
	//	No More Submenu to view
}		