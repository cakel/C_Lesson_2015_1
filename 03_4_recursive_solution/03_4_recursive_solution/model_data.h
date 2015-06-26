#ifndef _MODEL_DATA_H_
#define _MODEL_DATA_H_

typedef struct HOTELMODE_MENU_STRUCTURE
{
	char*				szMenuName;
	unsigned short		level;
	unsigned short		defaultValue;
	(void*)(fnCallback)(int toChange);
} HOTELMODE_MENU_STRUCTURE_T;

#endif