#ifndef _APP_LIST_H_
#define _APP_LIST_H_

#define MAX_WORD_BUFFER (128)

#define APP_NUMBER (5)
#define KEYWORD_NUMBER (5)

typedef struct tagAPP{
    char *appName;
    char *appKeyword;
    int appPriority;
}APP;

void searchAppByName(char* word_buf, APP* list);
void searchAppByKeyword(char* word_buf, APP* list);
void printByPriority(APP* list);
void searchAppByRelevantName(char* word_buf, APP* list);
void print_app(APP* appItem);
#endif
