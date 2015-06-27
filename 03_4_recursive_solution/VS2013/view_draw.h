#ifndef _VIEW_DRAW_H_
#define _VIEW_DRAW_H_

typedef enum
{
	SELECT_DISPLAY_FULL_DETAILS,
	SELECT_GO_TO_TOP,
	SELECT_ENTER_ONE_DEPTH_MENU,
	SELECT_OUT_ONE_DEPTH_MENU,
	SELECT_CHANGE_VALUE,
	SELECT_DEFAULT_MENU_VALUES,
	SELECT_LOAD_MENU_VALUES,
	SELECT_SAVE_MENU_VALUES,
	SELECT_EXIT
} MENU_ITEM_T;

typedef struct MENU_STRUCTURE
{
	MENU_ITEM_T	menuItem;
	char*		menuString;
	void		(*fnCallback)(void);
} MENU_STRUCTURE_T;

void view_displayFullDetails(void);
void view_goToTop(void);
void view_enterOneDepthMenu(void);
void view_outOneDepthMenu(void);
void view_changeValue(void);
void view_returnDefaultValues(void);
void view_loadValuesFromFile(void);
void view_saveValuesToFile(void);
void view_exit(void);


#endif