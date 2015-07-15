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
    printf("1. 이름으로 App 검색 \n");
    printf("2. 키워드로 App 검색 \n");
    printf("3. 유사 이름으로 App 검색 (이름 순 출력)\n");
    printf("4. 전체 목록 출력 (우선순위 순)\n");
	printf("0. 종료\n");
}

void search_by_name(APP* list){
	// 사용자에게 입력을 받는다
	char word_buf[MAX_WORD_BUFFER];
	printf("[ Search App by Name ]\n");

	fflush(stdin);
	printf("Input word : ");
	scanf("%s", word_buf);
	word_buf[MAX_WORD_BUFFER-1] = '\0';

	// App 이름과 비교한다.
	searchAppByName(word_buf, list);
}

void search_by_keyword(APP* list){
	// 사용자에게 입력을 받는다
	char word_buf[MAX_WORD_BUFFER];
	printf("[ Search App by Keyword ]\n");
	
	fflush(stdin);
	printf("Input word : ");
	scanf("%s", word_buf);
	word_buf[MAX_WORD_BUFFER-1] = '\0';

	// App 이름과 비교한다.
	searchAppByKeyword(word_buf, list);
}


void search_by_relavant_name(APP* list){
	// 사용자에게 입력을 받는다
	char word_buf[MAX_WORD_BUFFER];
	printf("[ Search App by Name ]\n");

	fflush(stdin);
	printf("Input word : ");
	scanf("%s", word_buf);
	word_buf[MAX_WORD_BUFFER-1] = '\0';

	// App 이름과 비교한다.
	searchAppByRelevantName(word_buf, list);
}

void print(APP* list){
	printf("[ Print App List by Score ]\n");
	printByPriority(list);
}

void exit_routine(void){
	int i=0;
}