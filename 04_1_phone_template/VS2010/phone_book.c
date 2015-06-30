/**********************************************
* ��ũ�帮��Ʈ�� �̿��� ��ȭ��ȣ�� ���α׷�
* �ϵ� SW ���԰��� 21�� �ǽ����� ������
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

// ����ó ���� ����Ʈ�� ������ġ
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
            printf("\n* ���α׷��� �����մϴ�.\n");
            printf("* �����մϴ�.\n");
            exit(0);
            break;
        default:
            printf("# �߸��� ��ȣ�Դϴ�.\n");
            getch();
            break;
        }
    }

    return 0;
}

/**
 *  �Լ����� : �޴��� �����ϰ� ����ڷκ��� ������ �Է¹޾� ��ȯ�Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ����� �Է�
*/
int printMenu()
{
    int selNum = 0;

    printf(" =========<< �޴� >>========= \n");
    printf(" 1. ����ϱ� \n");
    printf(" 2. �����ϱ� \n");
    printf(" 3. �˻��ϱ� \n");
    printf(" 4. ��Ϻ��� \n");
    printf(" 5. �����ϱ� \n");

    printf(" ======>> insert number : ");
    scanf("%d", &selNum);
    fflush(stdin);

    return selNum;
}

/**
 *  �Լ����� : ���Ӱ� ������ ����ó ��带 ����Ʈ�� �߰��Ѵ�.
 *             ������ ��ϵ� ����ó��� ���Ͽ� ������ �̸�/��ȭ��ȣ�� ���ؼ��� ����� ����Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ����
*/
void addNewData(void)
{

    Person *curNode;                            // ����Ʈ���� ���� ���
    Person *preNode;                            // ����Ʈ���� �ٷ� ���� ���
    Person *newNode;                            // ���ο� ����ó ���
    char *upperNewStr;                          // �빮�ڷ� �����Ų ���ο� ����ó �̸�
    char *upperNodeStr;                         // �빮�ڷ� �����Ų ������ ����ó �̸�

    system("cls");

    printf(" =========<< ��� >>========= \n");

    // todo - ����ڷκ��� �̸�/��ȭ��ȣ�� �Է¹޾� ������ �˻��ϰ� �ùٸ� �Է��� ��� ����ó�� �ּҸ� ��ȯ


    // todo - ���Ŀ� ���� ���� �Է��� ������� ����� ��ҵȴ�.


    // todo - ������ ��ϵ� ����ó�� �̸��� ���� ���� �ľ�


    // todo - ������ ��ϵ� ����ó�� ��ȭ��ȣ�� ���� ���� �ľ�



    // todo - �̸��� �������� �����ϱ� ���� �̸��� �빮�ڷ� ����

    curNode = preNode = head;
    // todo - ���ڿ� �񱳸� ���� �̸��� ���������� �ǵ��� ������ ��ġ�� ����ó ��带 �����Ѵ�.


    // ���� �����ϴ� ����ó or ������ ������ ��ġ�� �����ϴ� ����ó
    if(curNode == NULL)
    {
        AppendNode(&head, newNode);
    }

    printf("\n# ����� �����߽��ϴ�.\n");
    free(upperNewStr);
    getch();
    return;
}

/**
 *  �Լ����� : ����ó�� �����Ѵ�. ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ�� �Է¹޾�
 *              ����Ʈ���� ����ó�� �˻��ϰ�, ������ ��� ����Ʈ���� �����ϰ� �����Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ����
*/
void deleteData(void)
{

    char str[20];                           // �̸� or ��ȭ��ȣ ����
    char yn;                                // ���� ���� ����
    Person *tNode;                          // ����Ʈ���� ���� ��ġ ����

	system("cls");

    printf(" =========<< ���� >>========= \n");
    // todo - ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޴´�.


    // todo - ����ڷκ��� �Է¹��� ���ڿ��� ���� ���� ����ó���� �˻��Ѵ�.


    // todo - ���� ���θ� �ľ��Ѵ�.


    // todo - 'y'�Է� �� �ش� ����ó�� ����Ʈ���� �����ϰ� �޸𸮸� ��ȯ�Ѵ�.


    getch();
}

/**
 *  �Լ����� : ����ó�� �˻��Ѵ�. ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޾�
 *              ����ó�� �˻��ϰ�, ������ ��� �ش� ����ó�� ���� ������ ����Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ����
*/
void searchData(void)
{

    char str[20];                           // �̸� or ��ȭ��ȣ ����
    Person *tNode;                          // ����Ʈ���� ���� ��ġ ����

	system("cls");

    printf(" =========<< �˻� >>========= \n");
    // todo - ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޴´�.

    // todo - ����ڷκ��� �Է¹��� ���ڿ��� ���� ���� ����ó���� �˻��Ѵ�.


    // todo - �˻��� ���� ���


    getch();
}

/**
 *  �Լ����� : ����ڰ� ����� ��� ����ó ������ ����Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ����
*/
void printData(void)
{
    int i;                                  // �ݺ��� ����
	Person *tNode;                          // ����Ʈ���� ���� ��ġ ����
    system("cls"); 

    printf(" =========<< ��� >>========= \n");
    printf("    �̸� \t\t ��ȭ��ȣ\n");
    for(i = 1, tNode = head ; tNode != NULL; i++)
    {
        printf("%02d. %-20s %-20s\n", i, tNode->pName, tNode->pPhone);
        tNode = tNode->nNode;
    }

    getch();
}

/**
 *  �Լ����� : ���α׷� ���� �� ����Ʈ���� ��� ����ó�� �����ϰ� �޸𸮸� ��ȯ�Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ����
*/
void exitProgram(void)
{
    Person *tNode;                          // ����Ʈ���� ���� ��ġ ����

    while(head != NULL)
    {
        tNode = head;
        RemoveNode(&head, tNode);
        DeleteNode(tNode);
    }
}

/**
 *  �Լ����� : ����ڷκ��� �̸� �� ��ȭ��ȣ�� �Է¹޾� ���� �˻縦 �����Ѵ�.
 *              ���ο� ����ó ��带 �����Ѵ�.
 *  �Ű����� : ����
 *  ��ȯ     : ���ο� ����ó ����� �ּ�
*/
Person *inputData(void)
{
    char name[30];                              // �̸� ����
    char phone[30];                             // ��ȭ��ȣ ����
    char *pName = NULL;                         // �̸� ���ڿ��� �ּ� ����
    char *pPhone = NULL;                        // ��ȭ��ȣ ���ڿ��� �ּ� ����
    Person *newNode = NULL;                     // ����ó ��� �ּ� ����

    // todo - �̸��� �Է¹ް� ������ �˻��Ѵ�.


    // todo - ��ȭ��ȣ�� �Է¹ް� ������ �˻��Ѵ�.


    // todo - �����Ҵ� �� ���ڿ� ����


    // todo - ����ó ��� ����

    return newNode;
}

/**
 *  �Լ����� : ���ڿ��� ���̸� �˻��Ѵ�.
 *              ���ĺ� �Ǵ� �������θ� �̷�����ִ� ���ڿ����� �˻��Ѵ�.
 *  �Ű����� : �̸�
 *  ��ȯ     : ����(0), ����(1)
*/
int verifyName(char *name)
{
    char *str = name;

    if(strlen(name) >= MAX_STRING_LENGTH)
    {
        printf("* ����� �̸��� �ʹ� ��ϴ�.\n");
        return 0;
    }

    while(*str)
    {
        if((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || *str == ' ')
        {
            str++;
        } else {
            printf("* �̸� ���Ŀ� ���� �ʽ��ϴ�.\n");
            return 0;
        }
    }

    return 1;
}

/**
 *  �Լ����� : ���ڿ��� ���̸� �˻��Ѵ�.
 *              �����θ� �̷�����ִ��� �˻��Ѵ�.
 *  �Ű����� : ��ȭ��ȣ
 *  ��ȯ     : ����(0), ����(1)
*/
int verifyPhone(char *phone)
{
    char *str = phone;

    if(strlen(phone) >= MAX_STRING_LENGTH)
    {
        printf("* ����� ��ȭ��ȣ�� �ʹ� ��ϴ�.\n");
        return 0;
    }

    while(*str)
    {
        if(*str >= '0' && *str <= '9')
        {
            str++;
        } else {
            printf("* ��ȭ��ȣ ���Ŀ� ���� �ʽ��ϴ�.\n");
            return 0;
        }
    }

    return 1;
}
