#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app_list.h"

void searchAppByName(char* word_buf, APP* list)
{
	int i=0;
	int bFound = 0;
	for(i=0; i<APP_NUMBER; i++)
	{
		if(strcmp(word_buf, list[i].appName)==0)
		{
			//printf("App 이 검색되었습니다.\n");
			print_app(&(list[i]));
			printf("\n");
			bFound = 1;
			break;
		}
	}
	if(bFound == 0)
	{
		printf("Sorry, but there is no app with that name.\n");
	}
}

void searchAppByKeyword(char* word_buf, APP* list)
{
	int i=0;
	int bFound = 0;
	for(i=0; i<APP_NUMBER; i++)
	{
		if(strcmp(word_buf, list[i].appKeyword)==0)
		{
			//printf("App 이 검색되었습니다.\n");
			print_app(&(list[i]));
			printf("\n");
			bFound = 1;
			break;
		}
	}
	if(bFound == 0)
	{
		printf("Sorry, but there is no app with that keyword.\n");
	}
}

void printByPriority(APP* list)
{
	int i=0,j=0;
	int swapped = 1;
	APP* tmp = NULL;
	APP* listToSort[APP_NUMBER]={NULL,NULL,NULL,NULL,NULL};

	for(i=0; i<APP_NUMBER; i++)
	{
		listToSort[i] = &(list[i]);
	}

	// bubble sort
	while (swapped) {
		swapped = 0;
		j++;
		for (i = 0; i < APP_NUMBER - j; i++) {
			if (listToSort[i]->appPriority > listToSort[i + 1]->appPriority ) {
				tmp = listToSort[i];
				listToSort[i] = listToSort[i + 1];
				listToSort[i + 1] = tmp;
				swapped = 1;
			}
		}
	}
	for(i=0; i<APP_NUMBER; i++)
	{
		print_app((listToSort[i]));
		//printf("Priority: %d, Name: %s, Keyword: %s\n",listToSort[i]->appPriority,listToSort[i]->appName,listToSort[i]->appKeyword);
	}
	printf("\n");
}

void print_app(APP* appItem)
{
	printf("  Score: [%2d], Name: [%s], Keyword: [%s]\n",appItem->appPriority,appItem->appName,appItem->appKeyword);
}

void searchAppByRelevantName(char* word_buf, APP* list)
{
	int i=0,j=0;
	int nFound = 0;
	int swapped = 1;
	APP* tmp = NULL;
	APP *listAppNameRelevant[APP_NUMBER] = {NULL,};

	for(i=0; i<APP_NUMBER; i++)
	{
		if(strstr(list[i].appName, word_buf)!=NULL)
		{
			listAppNameRelevant[nFound] = &(list[i]);
			//printf("App 이 검색되었습니다.\n");
			//print_app(&(list[i]));
			//printf("\n");
			nFound++;
			//break;
		}
	}
	if(nFound == 0)
	{
		printf("Sorry, but there is no app with that name.\n");
	}
	else
	{
		// bubble sort
		while (swapped) {
			swapped = 0;
			j++;
			for (i = 0; i < nFound - j; i++) {
				if (strcmp(listAppNameRelevant[i]->appName , listAppNameRelevant[i + 1]->appName) > 0 ) {
					tmp = listAppNameRelevant[i];
					listAppNameRelevant[i] = listAppNameRelevant[i + 1];
					listAppNameRelevant[i + 1] = tmp;
					swapped = 1;
				}
			}
		}
		for(i=0; i<nFound; i++)
		{
			print_app((listAppNameRelevant[i]));
			//printf("Priority: %d, Name: %s, Keyword: %s\n",listToSort[i]->appPriority,listToSort[i]->appName,listToSort[i]->appKeyword);
		}
		printf("\n");

	}
}