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
	int valid = 1;
	char* check_str = p_str;

	if(p_str == NULL)
	{
		valid = 0;
	}

	while(*check_str != '\0' && valid == 1)
	{
		if(	('a' <= *check_str && *check_str <= 'z') ||
			('A' <= *check_str && *check_str <= 'Z') ||
			(*check_str == ' ')	) 
		{
			check_str++;
		}
		else
		{
			valid = 0;
		}
	}

	if(valid == 0)
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
	int frequencyTable[200] = {0}, maxIndex = 0, maxFrequency = 0, i = 0;
	char toUpper = 0, retUpper = 0;
	char* s_str = p_str;

	while(s_str != NULL && *s_str != '\0')
	{
		toUpper = *s_str;
		to_uppercase(&toUpper, &retUpper);
		
		if(retUpper != ' ')
			frequencyTable[retUpper]++;
		
		s_str++;
	}

	// find Max Index
	for(i = 0; i < 200; i++)
	{
		if(frequencyTable[i] > maxFrequency)
		{
			maxIndex = i;
			maxFrequency = frequencyTable[i];
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
		if('a' <= *p_src && *p_src <= 'z')
		{
			*p_dest = 'A' + (*p_src - 'a');
		}
		else
		{
			*p_dest = *p_src;
		}
	}
}

// Desc : Duplication checking the string exists in string array
// Param : wp - string array, str - string to check
// Return : 1 if the str exists in wp, 0 otherwise
int dup_word(char **wp, char *str)
{

    // TODO: Write code here
	char** copyWp = wp;

	if(copyWp != NULL && str != NULL)
	{
		while(*copyWp != NULL)
		{
			if(stricmp(*copyWp, str) == 0)
				return 1;

			copyWp = copyWp + 1;
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
	char* wordList[50] = {0}, wordCount = 0;

	token = strtok_s(p_str, " \n\r", &nextContext);

	while(token != NULL)
	{
		if(dup_word(wordList, token) == 1)
		{
			// Duplicate
		}
		else
		{
			wordList[cnt++] = _strdup(token); 
		}

		token = strtok_s(NULL, " \n\r", &nextContext);
	}

    return cnt;
}

