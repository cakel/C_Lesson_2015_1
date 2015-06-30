/**********************************************
* 링크드리스트를 이용한 전화번호부 프로그램
* 일등 SW 신입과정 21기 실습강사 어유경
* Solution
***********************************************/

#include "list.h"

int printMenu(void);
void addNewData(void);
void deleteData(void);
void searchData(void);
void updateData(void);
void printData(void);
void exitProgram(void);

Person* inputData(void);
int verifyName(char*);
int verifyPhone(char*);

// 연락처 저장 리스트의 시작위치
Person *head;

int main()
{
    int mSelect = 0;

    while(1)
    {
        system("cls");
        mSelect = printMenu();

        switch(mSelect)
        {
        case ADD_INFO:
            addNewData();
            break;
        case DELETE_INFO:
            deleteData();
            break;
        case SEARCH_INFO:
            searchData();
            break;
        case PRINT_INFO:
            printData();
            break;
        case EXIT_PROCESS:
            exitProgram();
            printf("\n* 프로그램을 종료합니다.\n");
            printf("* 감사합니다.\n");
            exit(0);
            break;
        default:
            printf("# 잘못된 번호입니다.\n");
            getch();
            break;
        }
    }

    return 0;
}

/**
 *  함수설명 : 메뉴를 제공하고 사용자로부터 정수를 입력받아 반환한다.
 *  매개변수 : 없음
 *  반환     : 사용자 입력
*/
int printMenu()
{
    int selNum = 0;

    printf(" =========<< 메뉴 >>========= \n");
    printf(" 1. 등록하기 \n");
    printf(" 2. 삭제하기 \n");
    printf(" 3. 검색하기 \n");
    printf(" 4. 목록보기 \n");
    printf(" 5. 종료하기 \n");

    printf(" ======>> insert number : ");
    scanf("%d", &selNum);
    fflush(stdin);

    return selNum;
}

/**
 *  함수설명 : 새롭게 생성된 연락처 노드를 리스트에 추가한다.
 *             기존에 등록된 연락처들과 비교하여 동일한 이름/전화번호에 대해서는 등록을 취소한다.
 *  매개변수 : 없음
 *  반환     : 없음
*/
void addNewData(void)
{

    Person *curNode;                            // 리스트상의 현재 노드
    Person *preNode;                            // 리스트상의 바로 직전 노드
    Person *newNode;                            // 새로운 연락처 노드
    char *upperNewStr;                          // 대문자로 변경시킨 새로운 연락처 이름
    char *upperNodeStr;                         // 대문자로 변경시킨 기존의 연락처 이름

    system("cls");

    printf(" =========<< 등록 >>========= \n");

    // todo - 사용자로부터 이름/전화번호를 입력받아 형식을 검사하고 올바른 입력일 경우 연락처의 주소를 반환


    // todo - 형식에 맞지 않은 입력이 있을경우 등록이 취소된다.


    // todo - 기존에 등록된 연락처의 이름과 동일 여부 파악


    // todo - 기존에 등록된 연락처의 전화번호과 동일 여부 파악



    // todo - 이름을 기준으로 정렬하기 위해 이름을 대문자로 변경

    curNode = preNode = head;
    // todo - 문자열 비교를 통해 이름이 오름차순이 되도록 적절한 위치에 연락처 노드를 삽입한다.


    // 최초 증록하는 연락처 or 정렬의 마지막 위치에 존재하는 연락처
    if(curNode == NULL)
    {
        AppendNode(&head, newNode);
    }

    printf("\n# 등록을 성공했습니다.\n");
    free(upperNewStr);
    getch();
    return;
}

/**
 *  함수설명 : 연락처를 삭제한다. 사용자로부터 이름 또는 전화번호를 입력받아
 *              리스트에서 연락처를 검색하고, 존재할 경우 리스트에서 제거하고 삭제한다.
 *  매개변수 : 없음
 *  반환     : 없음
*/
void deleteData(void)
{

    char str[20];                           // 이름 or 전화번호 저장
    char yn;                                // 삭제 여부 저장
    Person *tNode;                          // 리스트상의 현재 위치 저장

	system("cls");

    printf(" =========<< 삭제 >>========= \n");
    // todo - 사용자로부터 이름 또는 전화번호 정보를 입력받는다.


    // todo - 사용자로부터 입력받은 문자열에 대해 기존 연락처에서 검색한다.


    // todo - 삭제 여부를 파악한다.


    // todo - 'y'입력 시 해당 연락처를 리스트에서 제거하고 메모리를 반환한다.


    getch();
}

/**
 *  함수설명 : 연락처를 검색한다. 사용자로부터 이름 또는 전화번호 정보를 입력받아
 *              연락처를 검색하고, 존재할 경우 해당 연락처에 대한 정보를 출력한다.
 *  매개변수 : 없음
 *  반환     : 없음
*/
void searchData(void)
{

    char str[20];                           // 이름 or 전화번호 저장
    Person *tNode;                          // 리스트상의 현재 위치 저장

	system("cls");

    printf(" =========<< 검색 >>========= \n");
    // todo - 사용자로부터 이름 또는 전화번호 정보를 입력받는다.

    // todo - 사용자로부터 입력받은 문자열에 대해 기존 연락처에서 검색한다.


    // todo - 검색된 내용 출력


    getch();
}

/**
 *  함수설명 : 사용자가 등록한 모든 연락처 정보를 출력한다.
 *  매개변수 : 없음
 *  반환     : 없음
*/
void printData(void)
{
    int i;                                  // 반복문 변수
	Person *tNode;                          // 리스트상의 현재 위치 저장
    system("cls"); 

    printf(" =========<< 출력 >>========= \n");
    printf("    이름 \t\t 전화번호\n");
    for(i = 1, tNode = head ; tNode != NULL; i++)
    {
        printf("%02d. %-20s %-20s\n", i, tNode->pName, tNode->pPhone);
        tNode = tNode->nNode;
    }

    getch();
}

/**
 *  함수설명 : 프로그램 종료 전 리스트상의 모든 연락처를 제거하고 메모리를 반환한다.
 *  매개변수 : 없음
 *  반환     : 없음
*/
void exitProgram(void)
{
    Person *tNode;                          // 리스트상의 현재 위치 저장

    while(head != NULL)
    {
        tNode = head;
        RemoveNode(&head, tNode);
        DeleteNode(tNode);
    }
}

/**
 *  함수설명 : 사용자로부터 이름 및 전화번호를 입력받아 형식 검사를 진행한다.
 *              새로운 연락처 노드를 생성한다.
 *  매개변수 : 없음
 *  반환     : 새로운 연락처 노드의 주소
*/
Person *inputData(void)
{
    char name[30];                              // 이름 저장
    char phone[30];                             // 전화번호 저장
    char *pName = NULL;                         // 이름 문자열의 주소 저장
    char *pPhone = NULL;                        // 전화번호 문자열의 주소 저장
    Person *newNode = NULL;                     // 연락처 노드 주소 저장

    // todo - 이름을 입력받고 형식을 검사한다.


    // todo - 전화번호를 입력받고 형식을 검사한다.


    // todo - 동적할당 및 문자열 복사


    // todo - 연락처 노드 생성

    return newNode;
}

/**
 *  함수설명 : 문자열의 길이를 검사한다.
 *              알파벳 또는 공백으로만 이루어져있는 문자열인지 검사한다.
 *  매개변수 : 이름
 *  반환     : 실패(0), 성공(1)
*/
int verifyName(char *name)
{
    char *str = name;

    if(strlen(name) >= MAX_STRING_LENGTH)
    {
        printf("* 등록한 이름이 너무 깁니다.\n");
        return 0;
    }

    while(*str)
    {
        if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || *str == ' ')
        {
            str++;
        } else {
            printf("* 이름 형식에 맞지 않습니다.\n");
            return 0;
        }
    }

    return 1;
}

/**
 *  함수설명 : 문자열의 길이를 검사한다.
 *              정수로만 이루어져있는지 검사한다.
 *  매개변수 : 전화번호
 *  반환     : 실패(0), 성공(1)
*/
int verifyPhone(char *phone)
{
    char *str = phone;

    if(strlen(phone) >= MAX_STRING_LENGTH)
    {
        printf("* 등록한 전화번호가 너무 깁니다.\n");
        return 0;
    }

    while(*str)
    {
        if(*str >= '0' && *str <= '9')
        {
            str++;
        } else {
            printf("* 전화번호 형식에 맞지 않습니다.\n");
            return 0;
        }
    }

    return 1;
}
