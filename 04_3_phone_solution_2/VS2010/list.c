#include "list.h"

/**
 *  �Լ����� : ���޵� �̸��� ��ȭ��ȣ�� �̿��� ����ó ��带 �����Ѵ�.
 *  �Ű����� : �̸�(_pName), ��ȭ��ȣ(_pPhone)
 *  ��ȯ     : ���ο� ����ó ���
*/
Person *CreateNode(char *_pName, char *_pPhone)
{
    Person *newNode = (Person *)malloc(sizeof(Person));

    newNode->pName = _pName;
    newNode->pPhone = _pPhone;
    newNode->nNode = NULL;

    return newNode;
}

/**
 *  �Լ����� : ���޵� ����� �޸𸮸� ��ȯ�Ѵ�.
 *  �Ű����� : ������ ���
 *  ��ȯ     : ����
*/
void DeleteNode(Person *delNode)
{
    free(delNode->pName);
    free(delNode->pPhone);
    free(delNode);
}

/**
 *  �Լ����� : ����Ʈ�� ���κп� ��带 �߰��Ѵ�.
 *  �Ű����� : ����Ʈ ���(head), �߰��� ���(newNode)
 *  ��ȯ     : ����
*/
void AppendNode(Person **head, Person *newNode)
{
    Person *tempNode;
    if(*head == NULL)
    {
        *head = newNode;
    } else {
        tempNode = *head;

        while(tempNode->nNode != NULL)
        {
            tempNode = tempNode->nNode;
        }

        tempNode->nNode = newNode;
    }
}

/**
 *  �Լ����� : �������� ���� ��ġ�� ��带 �߰��Ѵ�.
 *  �Ű����� : ������(curNode), �߰��� ���(newNode)
 *  ��ȯ     : ����
*/
void InsertNode(Person *curNode, Person *newNode)
{
    newNode->nNode = curNode->nNode;
    curNode->nNode = newNode;
}

/**
 *  �Լ����� : ����Ʈ���� �ش� ���(remNode)�� �����Ѵ�.
 *  �Ű����� : ����Ʈ ���(head), ������ ���(remNode)
 *  ��ȯ     : ����
*/
void RemoveNode(Person **head, Person *remNode)
{
    Person *tempNode;

    if(*head == remNode)
    {
        *head = remNode->nNode;
    } else {
        tempNode = *head;

        while(tempNode != NULL && tempNode->nNode != remNode)
        {
            tempNode = tempNode->nNode;
        }

        if(tempNode != NULL)
        {
            tempNode->nNode = remNode->nNode;
        }
    }
}

/**
 *  �Լ����� : ����Ʈ���� �ش� ���ڿ��� ���Ե� ����ó ��带 �˻��Ѵ�.
 *  �Ű����� : ����Ʈ ���(head), �˻��� ���ڿ�(str)
 *  ��ȯ     : ����
*/
Person *searchNode(Person **head, char *str)
{
	Person* found = NULL, *startNode = *head;
	
	while(startNode != NULL)
	{
		if(	stricmp(startNode->pPhone, str) == 0 ||
			stricmp(startNode->pName, str) == 0)
		{
			found = startNode;
		}
		startNode = startNode->nNode;
	}

	return found;
}

/**
 *  �Լ����� : ���޵� ���ڿ��� ���ĺ��� ��� �빮�ڷ� �ٲ۴�.
 *  �Ű����� : ���ĺ��� ���Ե� ���ڿ�
 *  ��ȯ     : ����ڷ� ����� ���ڿ�
*/
char *toUpperCase(char *str)
{
    // todo
	char* orgStr = _strdup(str);
	char* startStr = orgStr;

	while(*orgStr != '\0')
	{
		if( 'a' <= *orgStr && *orgStr <= 'z')
		{
			*orgStr = 'A' + (*orgStr - 'a');
		}

		orgStr++;
	}

	return startStr;
}
