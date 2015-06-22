#include "model_data.h"
#include "view_ui.h"

int main()
{
	model_initialize();
	view_frontEnd();
	model_finalize();
}