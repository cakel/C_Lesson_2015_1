#include <stdio.h>
#define MAX(a, b) (a) > (b) ? a : b
#define MIN(a, b) (a) < (b) ? a : b
#define END_OF_ARRAY (-1)

// 배열을 초기화 하고 배열을 동적 할당형태로 생성 후 채움
void initialize_array(int* array)
{
	int count = 0, input = 0;
	int i = 1;
	
	printf("개수 : ");
	scanf("%d", &count);
	
	while(i <= count)
	{
		printf("%d번째 자연수 입력 : ", i++);
		scanf("%d", &input);
	}
}

// 배열을 구성하는 전체 개수 구하기
static int find_count(int* array)
{
	int count = 0;
	// -1 까지 찾음

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


// 선택 정렬하는 함수 작성
void sort_array(int *array)
{

}

void finalize_array(int *array)
{

}

// 수열을 출력하는 함수 작성
void print_array(int array[])
{

}

int main()
{
	int *array = NULL;
	initialize_array(array);
	print_array(array);
	sort_array(array);
	printf("최대값 : %d\n", find_max(array));
	printf("최소값 : %d\n", find_min(array));
	finalize_array(array);
	
}
