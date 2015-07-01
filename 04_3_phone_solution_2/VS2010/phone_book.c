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

    Person *curNode = NULL;                            // ����Ʈ���� ���� ���
    Person *preNode = NULL;                            // ����Ʈ���� �ٷ� ���� ���
    Person *newNode	= NULL;                            // ���ο� ����ó ���
    char *upperNewStr	= NULL;                          // �빮�ڷ� �����Ų ���ο� ����ó �̸�
    char *upperNodeStr	= NULL;                         // �빮�ڷ� �����Ų ������ ����ó �̸�
	char name[30] = {0};
	char phone[30] = {0};
	
    system("cls");

    printf(" =========<< ��� >>========= \n");

    // todo - ����ڷκ��� �̸�/��ȭ��ȣ�� �Է¹޾� ������ �˻��ϰ� �ùٸ� �Է��� ��� ����ó�� �ּҸ� ��ȯ
	newNode = inputData();

	// todo - ���Ŀ� ���� ���� �Է��� ������� ����� ��ҵȴ�.
	if(newNode == NULL)
	{
		puts("��Ͽ� ���� �߽��ϴ�.");
		return;
	}

    // todo - ������ ��ϵ� ����ó�� �̸��� ���� ���� �ľ�
	if(searchNode(&head, newNode->pName))
	{
		puts("�ߺ��� ����ó�Դϴ�.");
		DeleteNode(newNode);
		return;
	}

    // todo - ������ ��ϵ� ����ó�� ��ȭ��ȣ�� ���� ���� �ľ�
	

    // todo - �̸��� �������� �����ϱ� ���� �̸��� �빮�ڷ� ����
	upperNewStr = toUpperCase(newNode->pName);

    curNode = preNode = head;
    // todo - ���ڿ� �񱳸� ���� �̸��� ���������� �ǵ��� ������ ��ġ�� ����ó ��带 �����Ѵ�.

    // ���� �����ϴ� ����ó or ������ ������ ��ġ�� �����ϴ� ����ó
    if(curNode == NULL)
    {
        AppendNode(&head, newNode);
    }
	else
	{
		preNode = NULL;

		while(curNode != NULL)
		{
			upperNodeStr = toUpperCase(curNode->pName);

			if(strcmp(upperNewStr, upperNodeStr) == -1)
			{
				free(upperNodeStr);
				upperNodeStr = NULL;
				break;
			}

			free(upperNodeStr);
			upperNodeStr = NULL;

			preNode = curNode;
			curNode = curNode->nNode;
		}

		// ã�� �κ��� ù �κ�
		if(preNode == NULL)
		{
			newNode->nNode = head;
			head = newNode;
		}
		// ����
		else
		{
			InsertNode(preNode, newNode);
		}
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

	char str[20] = {0};                           // �̸� or ��ȭ��ȣ ����
    char yn = 0;                                // ���� ���� ����
    Person *tNode = NULL;                          // ����Ʈ���� ���� ��ġ ����
	Person *preNode = NULL, *sNode = head;
	system("cls");

    printf(" =========<< ���� >>========= \n");
    // todo - ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޴´�.

	printf("* ������ �̸� �Ǵ� ��ȭ��ȣ�� �Է��ϼ��� : ");
	gets(str);

    // todo - ����ڷκ��� �Է¹��� ���ڿ��� ���� ���� ����ó���� �˻��Ѵ�.
	tNode = searchNode(&head, str);

    // todo - ���� ���θ� �ľ��Ѵ�.
	if(tNode != NULL)
	{
		printf("* ������ �����Ͻðڽ��ϱ�? (y/n) ");
	
		// todo - 'y'�Է� �� �ش� ����ó�� ����Ʈ���� �����ϰ� �޸𸮸� ��ȯ�Ѵ�.
		scanf_s(" %c", &yn, 1);

		if(yn == 'y')
		{
			// �� ó��
			if(stricmp(tNode->pName, head->pName) == 0)
			{
				head = head->nNode;
				DeleteNode(tNode);
			}
			else
			{
				// �߰��� ��� ���� Node �� �˾� �� �� ������ ���� Node �� ���� �� ����
				while(sNode != NULL)
				{
					if(stricmp(sNode->pName, tNode->pName) == 0)
					{
						preNode->nNode = tNode->nNode;
						DeleteNode(tNode);
						break;
					}

					preNode = sNode;
					sNode = sNode->nNode;
				}
			}

			puts("* ������ �Ϸ� �Ǿ����ϴ�.");

		}
		else
		{
			puts("* ������ ��� �Ǿ����ϴ�.");
		}
	}
	else
	{
		puts("* ������ �׸��� �����ϴ�.");
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

	char str[20] = {0};                           // �̸� or ��ȭ��ȣ ����
    Person *tNode;                          // ����Ʈ���� ���� ��ġ ����

	system("cls");

    printf(" =========<< �˻� >>========= \n");
    // todo - ����ڷκ��� �̸� �Ǵ� ��ȭ��ȣ ������ �Է¹޴´�.

	printf("�̸� �Ǵ� ��ȭ��ȣ�� �Է��ϼ��� : ");
	gets(str);

    // todo - ����ڷκ��� �Է¹��� ���ڿ��� ���� ���� ����ó���� �˻��Ѵ�.
	tNode = searchNode(&head, str);

    // todo - �˻��� ���� ���
	if(tNode != NULL)
	{
        printf("* �̸�: %-20s ��ȭ��ȣ : %-20s\n", tNode->pName, tNode->pPhone);
	}
	else
	{
		puts("* �˻��� ������ �����ϴ�.");
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
	char name[30] = {0};                              // �̸� ����
	char phone[30] = {0};                             // ��ȭ��ȣ ����
    char *pName = NULL;                         // �̸� ���ڿ��� �ּ� ����
    char *pPhone = NULL;                        // ��ȭ��ȣ ���ڿ��� �ּ� ����
    Person *newNode = NULL;                     // ����ó ��� �ּ� ����

    // todo - �̸��� �Է¹ް� ������ �˻��Ѵ�.
	printf("�̸� : ");
	gets(name);
	
	printf("��ȭ��ȣ : ");
	scanf_s("%s", phone, 30);

    // todo - ��ȭ��ȣ�� �Է¹ް� ������ �˻��Ѵ�.
	if(verifyName(name) && verifyPhone(phone))
	{
		// todo - �����Ҵ� �� ���ڿ� ����
		pName = (char*)malloc(sizeof(char) * (strlen(name) + 1));
		strncpy(pName, name, strlen(name) + 1);
 
		pPhone = _strdup(phone);

		// todo - ����ó ��� ����
		newNode = CreateNode(pName, pPhone);

	}
	else // �Է� ����
	{
	}

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
