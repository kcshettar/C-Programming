#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "status.h"

STRING string_init_default(int capacity)
{
  String* pString = (String*)malloc(sizeof(String));
  if (pString == NULL) 
    {
		printf("Alloc memory of pString is failed.\n");
		exit(1);
	}
  	else
    {
      	pString->capacity = capacity;
      	pString->size = 0;
      	pString->char_arr = (char*) malloc(sizeof(char)*pString->capacity);
      	if(!pString->char_arr)
		{
	  		free(pString);
	  		pString = NULL;
		}
    }
  	return pString;
}

STRING string_init_c_string(char* str) 
{
	int len;
	String* pString = (String*)malloc(sizeof(String));
	if (pString == NULL) 
        {
		printf("Alloc memory of pString is failed.\n");
		exit(1);
	}
	for (len = 0; str[len] != '\0'; len++);
	pString->capacity = len+1;
	pString->size = len;
	pString->char_arr = (char*)malloc(sizeof(char) * pString->size);
	if (pString->char_arr == NULL) 
        {
		printf("Alloc memory of pString->char_arr is failed.\n");
		exit(1);
	}
	for (len = 0; len <= pString->capacity; len++) 
        {
		pString->char_arr[len] = str[len];
	}
	return pString;
}

int string_compare(STRING str1, STRING str2)
{
    String* Tstr1 = (String*)str1;
    String* Tstr2 = (String*)str2;
    int i = 0;
    
    while (Tstr1->char_arr[i] != '\0' && Tstr2->char_arr[i] != '\0')
    {
        
        if(Tstr1->char_arr[i] > Tstr2->char_arr[i])
        {
            i++;
            return 1;
        }
        else if(Tstr1->char_arr[i] < Tstr2->char_arr[i])
        {
            i++;
            return -1;
        }
        else if(Tstr1->char_arr[i] == Tstr2->char_arr[i])
        {
            i++;
        }
    }
   return 0;
}


void string_destroy(STRING* pPString)
{
	String* pString = (String*) *pPString;
  	printf("\nString present %s\n", pString->char_arr);
  	free(pString->char_arr);
	free(pString);
  	*pPString = NULL;
  	printf("Successfully destroyed the string\n");
}

int string_get_size(STRING str)
{
    String* pString = (String*)str;
    return pString->size;
}

int string_get_capacity(STRING str)
{
    String* pString = (String*)str;
    return pString->capacity;
}

int string_extraction(FILE* file1, STRING str2)
{
	printf("\nExtraction called\n");
    char c;
    char* copy;
    int i=0;
	int len;
    int doublecap =0;
    String* Tstr2 = (String*)str2;
	printf("Reading character by character\n");
	while (fscanf(file1, "%c", &c) != -1)
   	{
   		if (c != ' ' )   	
   		{
    		Tstr2->size = i;
			if(Tstr2->size >= Tstr2->capacity)
    		{
    			doublecap= Tstr2->capacity *2 ;
       			copy = (char*)malloc(sizeof(char)*doublecap);
      			if(copy == NULL)
				{
					printf("Failure\n");
        			return FAILURE;
      			}	   	
       		}
       		Tstr2->size = i+1;
    		Tstr2->char_arr[i] = c;
            i++;
        }
        else
        {
          	printf("There is a space found in the file1\n");
          	break;
    	}
		free(copy);
    }
    return SUCCESS;
}

/*
lab04
for(i=0;i< str->size+1;i++)
        	{
          		copy[i]= str->char_arr[i];
        	}
        	free(str->char_arr);
        	free(str->char_arr);
       		str->char_arr = copy;
        	str->capacity*= 2;
			for (len = 0; str->char_arr[len] != '\0'; len++);
			//str->size=len+1;
			*/

int string_insertion(FILE* file2, STRING str2)
{
	printf("Insertion called\n");
	int i, ch;
	String* Tstr2 = (String*)str2;
	printf("Characters that will be stored in file2 -> %s\n", Tstr2->char_arr);
	for(i=0;i < Tstr2->size; i++)
	{
		ch = (int)(Tstr2->char_arr[i]);
		if(fputc(ch, file2) == -1)
		return FAILURE;
	}
	//printf("\nStoring in output -> %s\n", Tstr2->char_arr);
	return SUCCESS; 	
}
