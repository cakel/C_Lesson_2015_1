#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

// 배열을 초기화 하고 배열을 동적 할당 형태로 생성 후채움
void initialize_array(int** array)
{
	int count = 0, input = 0;
	int i = 0;

	printf("개수: ");
	scanf("%d", &count);

	if((*array = (int*)malloc((count + 1) * sizeof(int))) == NULL)
	{
		puts("malloc 에 실패했습니다.");
	}
	memset(*array, 0, sizeof(count + 1));

	while(i < count)
	{
		printf("%d번째 자연수입력: ", i + 1);
		scanf("%d", &input);

		if(input > 0)
		{
			(*array)[i] = input;
			i++;
		}
		else
		{
			puts("자연수 입력을 해야합니다.");
		}

	}

	(*array)[i] = END_OF_ARRAY;

	return;

}

// 배열을구성하는전체개수구하기
int find_count(int* array)
{
	int count = 0;
	// -1 까지찾음
	while(array[count] != END_OF_ARRAY)
	{
		count++;
	}

	return count;
}


// 선택정렬하는함수작성
void sort_array(int *array)
{
	int i = 0, j = 0, temp = 0;
	for(i = 0 ; i < find_count(array); i++)
	{
		for(j = i; j < find_count(array); j++)
		{
			if(array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

void finalize_array(int **array)
{
	if(*array != NULL)
	{
		free(*array);
		*array = NULL;
	}
}

// 수열을출력하는함수작성
void print_array(int array[])
{
	unsigned int i = 0;
	if(array == NULL)
	{
		puts("NULL Pointer 입니다.");
		return;
	}

	while(array[i] != END_OF_ARRAY)
	{
		printf("%d ", array[i]);
		i++;
	}

	puts("");

	return;
}
