#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define ADD_INFO            1
#define DELETE_INFO         2
#define SEARCH_INFO         3
#define PRINT_INFO          4
#define EXIT_PROCESS        5

#define MAX_STRING_LENGTH   20

// 연락처 정보 저장 구조체
typedef struct Person_T Person;
typedef struct Person_T
{
    char *pName;                    // 이름
    char *pPhone;                   // 전화번호
    Person *nNode;           // 노드 연결
} Person;

// 리스트 관련 함수
Person *CreateNode(char *, char *);
void DeleteNode(Person *);
void AppendNode(Person **, Person *);
void InsertNode(Person *, Person *);
void RemoveNode(Person **, Person *);
Person *searchNode(Person **, char*);

//문자열 처리
char *toUpperCase(char*);

#endif // LIST_H_INCLUDED
