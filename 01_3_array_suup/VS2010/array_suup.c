#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include <string.h>
#include "array.h"

#define _CRTDBG_MAP_ALLOC

static int find_max(int *array)
{
	int result = 0;
	int i = 0;

	if(array == NULL)
	{
		puts("array �� NULL pointer �Դϴ�.");
	}

	for(i = 0 ; i < find_count(array); i++)
	{
		result = MAX(array[i], result);
	}

	return result;
}

static int find_min(int *array)
{
	int result = 0;
	int i = 0;

	if(array == NULL)
	{
		puts("array �� NULL pointer �Դϴ�.");
	}

	result = array[0];

	for(i = 0 ; i < find_count(array); i++)
	{
		result = MIN(array[i], result);
	}
	return result;
}

int main()
{
	int *array = NULL;
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG); // Get current flag
	flag |= _CRTDBG_LEAK_CHECK_DF; // Turn on leak-checking bit
	_CrtSetDbgFlag(flag); // Set flag to the new value

	initialize_array(&array);
	printf("�Էµ� ���� : ");
	print_array(array);

	sort_array(array);

	printf("���ĵ� ���� : ");
	print_array(array);

	printf("�ִ밪: %d\n", find_max(array));
	printf("�ּҰ�: %d\n", find_min(array));
	finalize_array(&array);

	_CrtDumpMemoryLeaks();
}