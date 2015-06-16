#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"

// �迭�� �ʱ�ȭ �ϰ� �迭�� ���� �Ҵ� ���·� ���� ��ä��
void initialize_array(int** array)
{
	int count = 0, input = 0;
	int i = 0;

	printf("����: ");
	scanf("%d", &count);

	if((*array = (int*)malloc((count + 1) * sizeof(int))) == NULL)
	{
		puts("malloc �� �����߽��ϴ�.");
	}
	memset(*array, 0, sizeof(count + 1));

	while(i < count)
	{
		printf("%d��° �ڿ����Է�: ", i + 1);
		scanf("%d", &input);

		if(input > 0)
		{
			(*array)[i] = input;
			i++;
		}
		else
		{
			puts("�ڿ��� �Է��� �ؾ��մϴ�.");
		}

	}

	(*array)[i] = END_OF_ARRAY;

	return;

}

// �迭�������ϴ���ü�������ϱ�
int find_count(int* array)
{
	int count = 0;
	// -1 ����ã��
	while(array[count] != END_OF_ARRAY)
	{
		count++;
	}

	return count;
}


// ���������ϴ��Լ��ۼ�
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

// ����������ϴ��Լ��ۼ�
void print_array(int array[])
{
	unsigned int i = 0;
	if(array == NULL)
	{
		puts("NULL Pointer �Դϴ�.");
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
