#include <stdio.h>
#include "app_list.h"

void display_menu(void);
void search_by_name(APP* list);
void search_by_keyword(APP* list);
void print(APP* list);
void search_by_relavant_name(APP* list);
void exit_routine(void);

APP list[APP_NUMBER] = {
{"dictionary",	"word",		54},
{"circle",		"round",	41},
{"circus",		"game",		93},
{"calculator",	"math",		72},
{"calcium",		"vitamin",	10}};


int main() {
	int sel = -1;
	
	for(;;) {
		display_menu();
		fflush(stdin);
		
		while(1) {
			printf("> Select a number : ");
			scanf("%d", &sel);
			fflush(stdin);
			
			if(sel<0 || sel>4) {
				printf("Please input again...\n");
			} else {
				break;
			}
		}
		
		switch(sel) {
			case 0:
				exit_routine();
				break;
			case 1:
				search_by_name(list);
				break;
			case 2:
				search_by_keyword(list);
				break;
			case 3:
				search_by_relavant_name(list);
				break;
			case 4:
				print(list);
				break;
			default:
				break;
		}
		
		if(!sel)
			break;
	}

	return 0;
}

void display_menu(void){
	printf("[ Application List ]\n");
    printf("1. �̸����� App �˻� \n");
    printf("2. Ű����� App �˻� \n");
    printf("3. ���� �̸����� App �˻� (�̸� �� ���)\n");
    printf("4. ��ü ��� ��� (�켱���� ��)\n");
	printf("0. ����\n");
}

void search_by_name(APP* list){
	// ����ڿ��� �Է��� �޴´�
	char word_buf[MAX_WORD_BUFFER];
	printf("[ Search App by Name ]\n");

	fflush(stdin);
	printf("Input word : ");
	scanf("%s", word_buf);
	word_buf[MAX_WORD_BUFFER-1] = '\0';

	// App �̸��� ���Ѵ�.
	searchAppByName(word_buf, list);
}

void search_by_keyword(APP* list){
	// ����ڿ��� �Է��� �޴´�
	char word_buf[MAX_WORD_BUFFER];
	printf("[ Search App by Keyword ]\n");
	
	fflush(stdin);
	printf("Input word : ");
	scanf("%s", word_buf);
	word_buf[MAX_WORD_BUFFER-1] = '\0';

	// App �̸��� ���Ѵ�.
	searchAppByKeyword(word_buf, list);
}


void search_by_relavant_name(APP* list){
	// ����ڿ��� �Է��� �޴´�
	char word_buf[MAX_WORD_BUFFER];
	printf("[ Search App by Name ]\n");

	fflush(stdin);
	printf("Input word : ");
	scanf("%s", word_buf);
	word_buf[MAX_WORD_BUFFER-1] = '\0';

	// App �̸��� ���Ѵ�.
	searchAppByRelevantName(word_buf, list);
}

void print(APP* list){
	printf("[ Print App List by Score ]\n");
	printByPriority(list);
}

void exit_routine(void){
	int i=0;
}