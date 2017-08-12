#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "status.h"

String_Ptr string_init_default()
{
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
	
	if(pString == NULL)
	{
      	printf("Alloc memory of pString is failed.\n");
    	exit(1);
    }
	
	pString->capacity = 2;
	pString->size = 0;
	pString->char_arr = (char*)malloc(sizeof(char)*pString->capacity);
  	if(pString->char_arr == NULL)
    {
      	printf("Alloc memory of pString->char_arr is failed.\n");
      	exit(1);
    }
	return pString;
}

String_Ptr string_init_c_string(char* c_str)
{
	int len;
	int i = 0;
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
	
	if(pString == NULL)
	{
      	printf("Alloc memory of pString is failed.\n");
      	exit(1);
    }
	
	for(len = 0; c_str[len] != '\0'; len++);
  	pString->capacity = len+1;
  	pString->size = len;
  	pString->char_arr = (char*)malloc(sizeof(char) * pString->capacity);
  	if(pString->char_arr == NULL) 
    {
      	printf("Alloc memory of pString->char_arr is failed.\n");
      	exit(1);
    }
  	for(len = 0; len < pString->size; len++) 
    {
    	pString->char_arr[len] = c_str[len];
    }
	return pString;
}

Status string_destroy(String_Ptr* phString)
{	
	if((*phString)->char_arr != NULL)
	free((*phString)->char_arr);
	else
	return FAILURE;
	
	if(*phString != NULL)
	free(*phString);
	else
	return FAILURE;

	*phString = NULL;
	return SUCCESS;
}

int string_compare(String_Ptr hString1, String_Ptr hString2)
{
	int i = 0;
	while(hString1->char_arr[i] != '\0' && hString2->char_arr[i] != '\0')
	{
		if(hString1->char_arr[i] != hString2->char_arr[i])
		{
			break;
		}
		i++;
	}
	return hString1->char_arr[i] - hString2->char_arr[i];
}

int string_get_size(String_Ptr hString)
{
	return hString->size;
}

int string_get_capacity(String_Ptr hString)
{
	return hString->capacity;
}

Status string_extraction(String_Ptr hString, FILE* fp)
{
	int i = 0, j;
	char c;
	char* temp = NULL;
	hString->size = 0;
	
	if(hString->char_arr == NULL)
	hString->char_arr = malloc(sizeof(char) * hString->capacity);
	
	if(hString->char_arr == NULL)
	return FAILURE;

	c = fgetc(fp);

	while(isspace(c) && c != EOF)
	{
		c = fgetc(fp);
	}
	
	if(c == EOF)
	{
		return FAILURE;
	}
	
	while(c != EOF && !isspace(c))
	{
		hString->char_arr[i++] = c;
		hString->size++;
		
		if(hString->size == hString->capacity)
		{
			hString->capacity *= 2;
			temp = (char*)malloc(sizeof(char) * hString->capacity);
			
			if(temp == NULL)
			return FAILURE;

			for(j = 0; j < i; j++)
			{
				temp[j] = hString->char_arr[j];
			}
			
			free(hString->char_arr);
			hString->char_arr = temp;
		}
		c = fgetc(fp);
	}
	
	if(isspace(c))
	{
		ungetc(c, fp);
	}
	hString->char_arr[i] = '\0';
	return SUCCESS;
}

Status string_insertion(String_Ptr hString, FILE* fp)
{
	int i;
	for(i = 0; i < hString->size; i++)
	{
		if(fputc(hString->char_arr[i], fp) == EOF)
		return FAILURE;
	}
	return SUCCESS;
}

Status string_push_back(String_Ptr hString, char item)
{
  	char* temp = NULL;
  	int j;
 	hString->char_arr[hString->size] = item;
  	hString->size++;

  	if(hString->size == hString->capacity)
  	{
	    temp = (char*)malloc(sizeof(char) * hString->capacity);
		hString->capacity *= 2;
		
		if(temp == NULL)
		return FAILURE;

		for(j = 0; j < hString->size; j++)
		{
			temp[j] = hString->char_arr[j];
		}
		free(hString->char_arr);
		hString->char_arr = malloc(sizeof(char) * hString->capacity);
			
		for(j = 0; j < hString->size; j++)
		{
			hString->char_arr[j] = temp[j];
		}
		free(temp);
		temp = NULL;
	}
  	hString->char_arr[hString->size] = '\0';
	return SUCCESS;
}

Status string_pop_back(String_Ptr hString)
{
  	if(hString != NULL && hString->char_arr != NULL)
    {
      	hString->char_arr[hString->size] = '\0';
      	hString->size--;
    }
  	else
    return FAILURE;
	return SUCCESS;
}

char* string_at(String_Ptr hString, int index)
{
  	if(hString != NULL && hString->char_arr != NULL && index >= 0 && index < hString->size)
    return &(hString->char_arr[index]);
  	else
    return NULL;
}

char* string_c_str(String_Ptr hString)
{
	if(hString->char_arr==NULL)
    return NULL;
  	else 
	hString->char_arr[hString->size] = '\0';
    return hString->char_arr;
}

Status string_concat(String_Ptr hResult, String_Ptr hAppend)
{
	int i, j;
	char* temp = NULL;
	
	if(string_get_size(hResult) != 0)
	{
		temp = malloc(sizeof(char) * (string_get_size(hResult) + string_get_size(hAppend) + 2));
		if(temp == NULL)
		return FAILURE;
	}
	else
	{
		temp = malloc(sizeof(char) * (string_get_size(hResult) + string_get_size(hAppend) + 1));
		if(temp == NULL)
		return FAILURE;
	}
	
	for(i = 0; i < string_get_size(hResult); i++)
	{
		temp[i] = *string_at(hResult, i);
	}
	
	if(string_get_size(hResult) != 0)
	{
		temp[i] = ' ';
		i++;
		hResult->size++;
	}
	
	hResult->size = string_get_size(hResult) + string_get_size(hAppend);
	hResult->capacity = string_get_size(hResult) + 1;
	
	for(i, j = 0; j < string_get_size(hAppend); j++, i++)
	{
		temp[i] = *string_at(hAppend, j);
	}
	
	temp[i] = '\0';
	free(hResult->char_arr);
	hResult->char_arr = temp;
	return SUCCESS;
}

Boolean string_empty(String_Ptr hString)
{
	if (hString == NULL || hString->char_arr == NULL || hString->size == 0)
	return TRUE;
	else
	return FALSE;
}

Status string_insert_at_index(String_Ptr hString, int index, char item)
{
    if(hString == NULL)
 	{
        return FAILURE;
    }
    if(index > hString->size) 
	{
        printf("OUT OF BOUNDS");
        return FAILURE;
    }
    hString->char_arr[index] = item;
    return SUCCESS;
}