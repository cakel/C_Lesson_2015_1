#include <stdio.h>
#define MAX(a, b) (a) > (b) ? a : b
#define MIN(a, b) (a) < (b) ? a : b
#define END_OF_ARRAY (-1)

// �迭�� �ʱ�ȭ �ϰ� �迭�� ���� �Ҵ����·� ���� �� ä��
void initialize_array(int* array)
{
	int count = 0, input = 0;
	int i = 1;
	
	printf("���� : ");
	scanf("%d", &count);
	
	while(i <= count)
	{
		printf("%d��° �ڿ��� �Է� : ", i++);
		scanf("%d", &input);
	}
}

// �迭�� �����ϴ� ��ü ���� ���ϱ�
static int find_count(int* array)
{
	int count = 0;
	// -1 ���� ã��

	return count;
}

static int find_max(int *array)
{
	int result = 0;

	return result;
}

static int find_min(int *array)
{
	int result = 0;

	return result;
}


// ���� �����ϴ� �Լ� �ۼ�
void sort_array(int *array)
{

}

void finalize_array(int *array)
{

}

// ������ ����ϴ� �Լ� �ۼ�
void print_array(int array[])
{

}

int main()
{
	int *array = NULL;
	initialize_array(array);
	print_array(array);
	sort_array(array);
	printf("�ִ밪 : %d\n", find_max(array));
	printf("�ּҰ� : %d\n", find_min(array));
	finalize_array(array);
	
}
