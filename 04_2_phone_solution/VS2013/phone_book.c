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
		fflush(stdin);

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
	fflush(stdin);
	
	printf(" =========<< ��� >>========= \n");

    // todo - ����ڷκ��� �̸�/��ȭ��ȣ�� �Է¹޾� ������ �˻��ϰ� �ùٸ� �Է��� ��� ����ó�� �ּҸ� ��ȯ
	newNode = inputData();

    // todo - ���Ŀ� ���� ���� �Է��� ������� ����� ��ҵȴ�.
	if (newNode == NULL)
	{
		puts("���Ŀ� ���� �ʾ� ����� ��� �˴ϴ�");
		return;
	}

    // todo - ������ ��ϵ� ����ó�� �̸��� ���� ���� �ľ�

    // todo - ������ ��ϵ� ����ó�� ��ȭ��ȣ�� ���� ���� �ľ�
	if ( head != NULL &&	// ù Node �� �߰��� ���� ���
		(curNode = searchNode(&head, newNode->pName)) != NULL &&
		!strcmp(curNode->pPhone, newNode->pPhone))
	{
		puts("�̹� �����ϴ� ����ó �Դϴ�.");
		DeleteNode(newNode);
		return;
	}
	
    // todo - �̸��� �������� �����ϱ� ���� �̸��� �빮�ڷ� ����
	upperNewStr = _strdup(newNode->pName);
	upperNewStr = toUpperCase(upperNewStr);

    curNode = head;
	preNode = NULL;
    // todo - ���ڿ� �񱳸� ���� �̸��� ���������� �ǵ��� ������ ��ġ�� ����ó ��带 �����Ѵ�.
	while (	(	curNode != NULL ) &&
			(	upperNodeStr = _strdup(curNode->pName))		&&
			(	upperNodeStr = toUpperCase(upperNodeStr))	&&
			(	strcmp(upperNewStr, upperNodeStr) > 0)		)
	{
		preNode = curNode;
		curNode = curNode->nNode;	// Go Next
		
		if (upperNodeStr != NULL)
		{
			free(upperNodeStr);
			upperNodeStr = NULL;
		}
	}

    // ���� �����ϴ� ����ó or ������ ������ ��ġ�� �����ϴ� ����ó
    if(curNode == NULL)
    {
        AppendNode(&head, newNode);
    }
	else if (preNode == NULL)
	{
		newNode->nNode = head;
		head = newNode;
	}
	else
	{
		InsertNode(preNode, newNode);
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
	Person *preNode = head;

	system("cls");
	fflush(stdin);

    printf(" =========<< ���� >>========= \n");
    // todo - ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޴´�.
	printf("������ �̸� �Ǵ� ��ȭ��ȣ�� �Է����ּ��� : ");

    // todo - ����ڷκ��� �Է¹��� ���ڿ��� ���� ���� ����ó���� �˻��Ѵ�.
	if (scanf_s("%s", str, 20) != 0)
	{
		tNode = searchNode(&head, str);
	}

    // todo - ���� ���θ� �ľ��Ѵ�.
	if (tNode != NULL)
	{
		printf("�����Ͻðڽ��ϱ�? (y/n)");

		scanf_s(" %c", &yn, 1);

		// todo - 'y'�Է� �� �ش� ����ó�� ����Ʈ���� �����ϰ� �޸𸮸� ��ȯ�Ѵ�.
		if (yn == 'y')
		{
			if (stricmp(head->pName,	tNode->pName) == 0 ||
				stricmp(head->pPhone,	tNode->pPhone) == 0)
			{
				// ������ Node �� �ֻ��� Head
				// Head Node �� ���� Node �� Head �� ����Ų��.
				head = head->nNode;
			}
			else
			{
				// ���� Node �� ã��
				while (preNode->nNode != NULL &&
					stricmp(preNode->nNode->pName, tNode->pName) != 0 ||
					stricmp(preNode->nNode->pPhone, tNode->pPhone) != 0)
				{
					preNode = preNode->nNode;
				}

				preNode->nNode = tNode->nNode;
			}


			DeleteNode(tNode);
			puts("������ �Ϸ� �Ǿ����ϴ�.");
		}
	}
	else
	{
		puts("�˻��� �׸��� �����ϴ�.");
	}
	



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
	fflush(stdin);
	
	printf(" =========<< �˻� >>========= \n");
    // todo - ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޴´�.
	printf("�˻��� �̸� �Ǵ� ��ȭ��ȣ�� �Է����ּ��� : ");

	// todo - ����ڷκ��� �Է¹��� ���ڿ��� ���� ���� ����ó���� �˻��Ѵ�.
	if (scanf_s("%s", str, 20) != 0)
	{
		tNode = searchNode(&head, str);
	}

    // todo - �˻��� ���� ���
	if (tNode != NULL)
	{
		printf("�̸� \t\t ��ȭ��ȣ\n");
		printf("%-20s %-20s\n", tNode->pName, tNode->pPhone);
		tNode = tNode->nNode;
	}
	else
	{
		puts("ã�� �׸��� �����ϴ�.");
	}

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
	printf("�̸� : ");
	scanf_s("%s", name, 30);

	if (verifyName(name) == 0)
	{
		puts("�̸��� �߸� �Ǿ����ϴ�.");
		return NULL;
	}

    // todo - ��ȭ��ȣ�� �Է¹ް� ������ �˻��Ѵ�.
	printf("��ȭ ��ȣ : ");
	scanf_s("%s", phone, 30);

	if (verifyPhone(phone) == 0)
	{
		puts("��ȭ ��ȣ�� �߸� �Ǿ����ϴ�.");
		return NULL;
	}

    // todo - �����Ҵ� �� ���ڿ� ����
	pName	= _strdup(name);
	pPhone	= _strdup(phone);

    // todo - ����ó ��� ����
	newNode = CreateNode(pName, pPhone);

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
*/;
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
