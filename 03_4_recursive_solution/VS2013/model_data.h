#ifndef _MODEL_DATA_H_
#define _MODEL_DATA_H_
#include "common.h"

typedef enum
{
	HOTEL,
	HOTEL_VOL,
	HOTEL_VOL_START,
	HOTEL_VOL_MAXIMUM,
	HOTEL_VOL_MINIMUM,
	HOTEL_KEY,
	HOTEL_KEY_IROPERATION,
	HOTEL_KEY_LOCALKEYOPERATION,
	HOTEL_POWER,
	HOTEL_POWER_INPUT,
	HOTEL_POWER_AVSETTING,
	HOTEL_END
}	HOTEL_MENUITEM_T;


typedef struct HOTEL_UI {
	HOTEL_MENUITEM_T	hotelMode_Index;
	char*				hotelMode_ItemName;
	unsigned int		hotelMode_level;
	unsigned int		hotelMode_defaultValue;
	void				(*pfnSubMenuDisplayCallback)(void);

} HOTEL_UI_T;

typedef struct HOTEL_MODEL {
	HOTEL_MENUITEM_T	key;
	unsigned int		value;
} HOTEL_MODEL_T;

HOTEL_UI_T* hotel_getItemInformation(HOTEL_MENUITEM_T findItem);
int hotel_getValue(HOTEL_MENUITEM_T hotelMode_Index);
boolean hotel_setValue(HOTEL_MENUITEM_T hotelMode_Index, unsigned int toChangeValue);


#endif