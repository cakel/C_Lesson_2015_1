#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)
#define ARRAY_END (-1)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int find_count(int* array)
{
	int count = 0;
	if (array != NULL)
	{
		while (array[count] != ARRAY_END)
		{
			count++;
		}
	}

	return count;
}

int initialize_array(int** array)
{
	int count = 0, input = 0, index = 0, createSize = 0;

	printf("���� : ");
	scanf_s("%d", &count);

	if (count > 0)
	{
		createSize = sizeof(int) * (count + 1);	/* (int �� ũ��) * (���� + ARRAY_END) */
		if ((*array = malloc(createSize)) == NULL)
		{
			puts("malloc ������ ���� �߽��ϴ�.");
			return -1;
		}		
		
		memset(*array, 0, createSize);
		(*array)[count] = ARRAY_END;
	}
	else
	{
		puts("������ 0 ���� ū ���ڿ��� �մϴ�."); 
		return -1;	// �ٽ� �Է��ϰ� �Ѵ�.
	}

	while (index < count)
	{
		printf("%d ��° �ڿ��� �Է� : ", index + 1);
		scanf_s("%d", &input);
		if (input > 0)
		{
			(*array)[index] = input;
			index++;
		}
		else
		{
			puts("�ڿ����� �Է� �ٶ��ϴ�.");
		}
	}

	return 0;
}

int find_max(int* array)
{
	int count = find_count(array), index = 0, max = -1;

	if (array == NULL || count == 0)
	{
		printf("array �� NULL(0x%x) �Ǵ� count ���� (%d) �Դϴ�.", array, count);
		return max;
	}

	while (index < count)
	{
		max = MAX(max, array[index]);
		index++;
	}

	return max;
}

int find_min(int* array)
{
	int count = find_count(array), index = 0, min = -1;

	if (array == NULL || count == 0)
	{
		printf("array �� NULL(0x%x) �Ǵ� count ���� (%d) �Դϴ�.", array, count);
		return min;
	}

	min = array[0];

	while (index < count)
	{
		min = MIN(min, array[index]);
		index++;
	}

	return min;
}

void finalize_array(int** array)
{
	if (*array != NULL)
	{
		free(*array);
		*array = NULL;
	}
}

void print_array(int* array)
{
	int count = find_count(array);
	int startIndex = 0;

	if (array == NULL || count == 0)
	{
		printf("array ���� NULL(0x%x) �Ǵ� count ���� (%d) �Դϴ�", array, count);
		return;
	}

	printf("�Էµ� �� : ");
	while (startIndex < count)
	{
		printf("%d ", array[startIndex++]);
	}

	puts("");
}

void sort_array(int* array)
{
	int i = 0, j = 0, count = find_count(array), temp = 0;

	for (i = 0; i < count; i++)
	{
		for (j = i; j < count; j++)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}			
			
		}
	}
}

int main(void)
{
	int* array = 0;
	while (initialize_array(&array) != 0);
	print_array(array);	
	sort_array(array);
	print_array(array);
	printf("�ִ밪: %d\t�ּҰ� : %d\n", find_max(array), find_min(array));
	finalize_array(&array);
	return 0;
}