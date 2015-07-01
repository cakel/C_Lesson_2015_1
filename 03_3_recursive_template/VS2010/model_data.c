#include "common.h"
#include "view_hotel.h"
#include "model_data.h"
#include <stdio.h>

struct HOTEL_UI HOTEL_UI_TBL[] =
{
	{HOTEL,							"Hotel Mode Operation",		1, DISABLE,		NULL},							// Hotel Mode Operation
	{HOTEL_VOL,						"Volume Policy",			2, DISABLE,		view_hotel_volume},				// - Volume
	{HOTEL_VOL_START,				"Start Volume",				3, 0,			view_hotel_volume_start},		// - Volume / Enable Start
	{HOTEL_VOL_MAXIMUM,				"Maximum Volume",			3, 100,			view_hotel_volume_maximum},		// - Volume / Enable Start / Start Volume
	{HOTEL_VOL_MINIMUM,				"Minimum Volume",			3, 0,			view_hotel_volume_minumum},		// - Volume / Minimum Volume
	{HOTEL_KEY,						"Key Management",			2, DISABLE,		view_hotel_key},				// - Key Management
	{HOTEL_KEY_IROPERATION,			"IR Operation",				3, NORMAL,		view_hotel_key_ir},				// - Key Management / IR Operation
	{HOTEL_KEY_LOCALKEYOPERATION,	"Local Key Operation",		3, NORMAL,		view_hotel_key_local},			// - Key Management / Local Key Operation
	{HOTEL_POWER,					"Power On Default",			2, DISABLE,		view_hotel_power},				// - Power On Default
	{HOTEL_POWER_INPUT,				"Input",					3, OFF,			view_hotel_input},				// - Power On Default / Input
	{HOTEL_POWER_AVSETTING,			"AV Setting",				3, OFF,			view_hotel_av},					// - Power On Default / AV Setting
};

struct HOTEL_MODEL HOTEL_DATABASE[] =
{
	{HOTEL,							0 },
	{HOTEL_VOL,						0 },
	{HOTEL_VOL_START,				0 },
	{HOTEL_VOL_MAXIMUM,				0 },
	{HOTEL_VOL_MINIMUM,				0 },
	{HOTEL_KEY,						0 },
	{HOTEL_KEY_IROPERATION,			0 },
	{HOTEL_KEY_LOCALKEYOPERATION,	0 },
	{HOTEL_POWER,					0 },
	{HOTEL_POWER_INPUT,				0 },
	{HOTEL_POWER_AVSETTING,			0 },
};

HOTEL_UI_T* hotel_getItemInformation(HOTEL_MENUITEM_T findItem)
{
	int index = 0, foundIndex = -1;
	for(index = 0; index <TBL_NUM(HOTEL_UI_TBL); index++)
	{
		if(HOTEL_UI_TBL[index].hotelMode_Index ==  findItem)
		{
			foundIndex = index;
			break;
		}
	}

	if(foundIndex != -1)
	{
		return &HOTEL_UI_TBL[foundIndex];
	}
	else
	{
		printf("%s():%d - Can't found itemName(%d)'s information", __FUNCTION__, __LINE__, findItem);
	}

	return NULL;
}

int hotel_getValue(HOTEL_MENUITEM_T hotelMode_Index)
{
	unsigned int searchIndex = 0;
	unsigned int found = false;

	for(searchIndex = 0 ; searchIndex < TBL_NUM(HOTEL_DATABASE); searchIndex++)
	{
		if(hotelMode_Index == HOTEL_DATABASE[searchIndex].key)
		{
			found = true;
			break;
		}
	}

	if(found)
	{
		return HOTEL_DATABASE[searchIndex].value;
	}
	else
	{
		printf("%s():%d - Finding (%d) Index Value was failed...", __FUNCTION__, __LINE__);
		return 0;
	}
}