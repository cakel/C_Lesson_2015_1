#include <stdio.h>
#include <stdarg.h>
#include "model_data.h"
#include "common.h"

void view_hotel_displayDetails(HOTEL_MENUITEM_T item_list, ...)
{
	unsigned int i = 0;
	static unsigned firstCall = false;
	HOTEL_MENUITEM_T nextUiItemIndex = HOTEL_END;
	HOTEL_UI_T *startUiItem = NULL, *nextUiItem = NULL;
	va_list va_item_list;
	va_start(va_item_list,item_list);

	startUiItem = hotel_getItemInformation(item_list);
	if(startUiItem != NULL && firstCall == false)
	{
		// 첫 호출 때에만 부르는 Caller 의 정보만 출력, 이후 재귀 호출시 사용하지 않음
		firstCall= true;
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
	firstCall= false;
}

void view_hotel_volume(void){
	view_hotel_displayDetails(HOTEL_VOL,
		HOTEL_VOL_START, HOTEL_VOL_MAXIMUM, HOTEL_VOL_MINIMUM,
		HOTEL_END);

}
void view_hotel_volume_start(void){
}
void view_hotel_volume_maximum(void){
}
void view_hotel_volume_minumum(void){
}
void view_hotel_key(void){
}
void view_hotel_key_ir(void){
}		
void view_hotel_key_local(void){
}
void view_hotel_power(void){
}
void view_hotel_input(void){
}
void view_hotel_av(void){
}		