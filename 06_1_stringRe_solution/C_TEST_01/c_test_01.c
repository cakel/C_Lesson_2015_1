//
// 1. String Analyzer
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA_NUM 26 /* A~Z */
#define MAX_STR_LEN 200
#define MAX_WORD_COUNT 32

int is_valid_string(char* p_str);
char get_highfreq_letter(char* p_str);
int get_word_count(char *p_str);
void to_uppercase(char* p_src, char* pp_dest);

int main(void)
{
    char ch;
    char buffer[MAX_STR_LEN];
    char p_uppercase[MAX_STR_LEN];
    int word_num; 

	while (1)
    {
        printf("> Enter string : ");
        gets(buffer);

        if (is_valid_string(buffer))
			break;
        
        printf(":: Please type alphabet only!\n\n");
    }

    ch = get_highfreq_letter(buffer);
    printf("\n> The alphabet of the highest frequency : %c\n", ch);

    word_num = get_word_count(buffer);
    printf("> The number of words : %d\n", word_num);
    system("pause");
    return 0;
}

// Desc : Checking the string contains invalid character
// Param : p_str - string to check
// Return : 1 if the string does not contain invalid character, 0 otherwise
int is_valid_string(char* p_str)
{


	// TODO: Write code here
	int invalid = 0;
	if(p_str != NULL)
	{
		while(invalid == 0 && *p_str != '\0')
		{
			if(	('a' <= *p_str && *p_str <= 'z')	||
				('A' <= *p_str && *p_str <= 'Z')	||
				*p_str == ' ')
			{
				p_str++;
			}
			else
			{
				invalid = 1;
				break;
			}
		}
	}

	if(invalid == 1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// Desc : Getting the most frequently used letter in string
// Param : p_str - string
// Return : The most frequently used letter
char get_highfreq_letter(char* p_str)
{


    // TODO: Write code here
	unsigned int alphaBetTable[200] = {0};
	unsigned int maxCount = 0, maxIndex = 0, tableIndex = 0;
	char upperAlpha = 0;

	if(p_str == NULL)
	{
		return 0;
	}
	else
	{
		// Count alphabet
		while(*p_str != '\0')
		{
			to_uppercase(p_str, &upperAlpha);
			
			if(upperAlpha != ' ')
			{
				alphaBetTable[upperAlpha]++;
			}
			p_str++;
		}
		// Find Max

		for(tableIndex = 0; tableIndex < 200; tableIndex++)
		{
			if(alphaBetTable[tableIndex] > maxCount)
			{
				maxCount = alphaBetTable[tableIndex];
			}
		}

		for(tableIndex = 0; tableIndex < 200; tableIndex++)
		{
			if(alphaBetTable[tableIndex] == maxCount)
			{
				maxIndex = tableIndex;
				break;
			}
		}
	}

    return (char)maxIndex;
}

// Desc : Convert a string to uppercase
// Param : p_src - source string, p_dest - coverted string
// Return : None
void to_uppercase(char* p_src, char* p_dest)
{


    // TODO: Write code here
	if(p_src != NULL && p_dest != NULL)
	{
		if(	'a' <= *p_src && *p_src <= 'z')
		{
			*p_dest = 'A' + (*p_src - 'a');
		}
		else if(*p_src == ' ')
		{
			*p_dest = ' ';
		}
	}
}

// Desc : Duplication checking the string exists in string array
// Param : wp - string array, str - string to check
// Return : 1 if the str exists in wp, 0 otherwise
int dup_word(char **wp, char *str)
{   
    // TODO: Write code here
	if(wp != NULL && str != NULL)
	{
		while(*wp != NULL)
		{
			if(strcmp(*wp, str) == 0)
			{
				return 1;
			}
			else
			{
				*wp++;
			}
		}
	}

    return 0;
}

// Desc : Getting the number of word in string
// Param : p_str - string
// Return : the number of unduplicated word in case-insensitively
int get_word_count(char *p_str)
{
    int cnt = 0;
 
	// TODO: Write code here
	char* token = NULL, *nextContext = NULL;
	char* wp[200] = {0};
	unsigned int freeCount = 0;

	// tokenize
	if(p_str == NULL)
		return 0;

	token = strtok_s(p_str, " \n\r", &nextContext);
	// find dup
	while(token != NULL)
	{
		if(dup_word(wp,token) == 0)
		{
			wp[cnt] = _strdup(token);
			cnt++;
		}

		token = strtok_s(NULL, " \n\r", &nextContext);
	}

	for(freeCount = 0; freeCount < 200; freeCount++)
	{
		if(wp[freeCount] != NULL)
		{
			free(wp[freeCount]);
			wp[freeCount]++;
		}
	}

	// free(wp);

    return cnt;
}

