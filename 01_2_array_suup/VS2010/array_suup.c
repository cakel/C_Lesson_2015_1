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
		puts("array 는 NULL pointer 입니다.");
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
		puts("array 는 NULL pointer 입니다.");
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
	printf("입력된 숫자 : ");
	print_array(array);

	sort_array(array);

	printf("정렬된 숫자 : ");
	print_array(array);

	printf("최대값: %d\n", find_max(array));
	printf("최소값: %d\n", find_min(array));
	finalize_array(&array);

	_CrtDumpMemoryLeaks();
}