#include "list.h"

/**
 *  함수설명 : 전달된 이름과 전화번호를 이용해 연락처 노드를 생성한다.
 *  매개변수 : 이름(_pName), 전화번호(_pPhone)
 *  반환     : 새로운 연락처 노드
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
 *  함수설명 : 전달된 노드의 메모리를 반환한다.
 *  매개변수 : 삭제할 노드
 *  반환     : 없음
*/
void DeleteNode(Person *delNode)
{
    free(delNode->pName);
    free(delNode->pPhone);
    free(delNode);
}

/**
 *  함수설명 : 리스트의 끝부분에 노드를 추가한다.
 *  매개변수 : 리스트 헤드(head), 추가할 노드(newNode)
 *  반환     : 없음
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
 *  함수설명 : 현재노드의 다음 위치에 노드를 추가한다.
 *  매개변수 : 현재노드(curNode), 추가할 노드(newNode)
 *  반환     : 없음
*/
void InsertNode(Person *curNode, Person *newNode)
{
    newNode->nNode = curNode->nNode;
    curNode->nNode = newNode;
}

/**
 *  함수설명 : 리스트에서 해당 노드(remNode)를 제거한다.
 *  매개변수 : 리스트 헤드(head), 제거할 노드(remNode)
 *  반환     : 없음
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
 *  함수설명 : 리스트에서 해당 문자열이 포함된 연락처 노드를 검색한다.
 *  매개변수 : 리스트 헤드(head), 검색할 문자열(str)
 *  반환     : 없음
*/
Person *searchNode(Person **head, char *str)
{
    // todo
	if (*head == NULL)
		return NULL;

	Person* searchPerson = *head;

	while (searchPerson != NULL)
	{
		if (_stricmp(str, searchPerson->pPhone) == 0 ||	// 이름과 전화번호가 입력 받는 범위가 다르므로 같이 써도 됨
			_stricmp(str, searchPerson->pName) == 0		)
		{
			// Found
			break;
		}
		searchPerson = searchPerson->nNode;
	}

	return searchPerson;
}

/**
 *  함수설명 : 전달된 문자열의 알파벳을 모두 대문자로 바꾼다.
 *  매개변수 : 알파벳이 포함된 문자열
 *  반환     : 대분자로 변경된 문자열
*/
char *toUpperCase(char *str)
{
    // todo
	char* startPoint = str;

	while (str != NULL && *str != '\0')
	{
		if ('a' <= *str && *str <= 'z')
		{
			*str = 'A' + (*str - 'a');
		}
		str++;
	}

	return startPoint;
}
