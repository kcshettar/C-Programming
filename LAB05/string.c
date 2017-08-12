#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "status.h"

StringPtr string_init_default()
{
	int capacity=2;
	StringPtr pString = (StringPtr)malloc(sizeof(String));
	if(pString == NULL)
	{
		printf("Alloc memory of pString is failed..\n");
		exit(1);
	}
	else
	{
		pString->capacity = capacity;
		pString->size = 0;
		pString->char_arr = (char*)malloc(sizeof(char)*pString->capacity);
		if(!pString->char_arr)
		{
			printf("Alloc memory of pString->char_arr is failed.\n");
			exit(1);
		}
	}
	return pString;
}

StringPtr string_init_c_string(char* s)
{
	int len;
	StringPtr pString = (StringPtr)malloc(sizeof(String));
	if(pString == NULL) 
	{
		printf("Alloc memory of pString is failed\n");
		exit(1);
	}
	for(len = 0; s[len] != '\0'; len++);
	pString->capacity = len+1;
	pString->size = len;
    pString->char_arr = (char*)malloc(sizeof(char) * pString->size);
	if(pString->char_arr == NULL) 
	{
		printf("Alloc memory of pString->char_arr is failed\n");
		exit(1);
	}
	for(len = 0; len <= pString->capacity; len++) 
	{
		pString->char_arr[len] = s[len];
	}
	return pString;
}

Status string_destroy(StringPtr* pPString) 
{
	if((*pPString)->char_arr != NULL)
	{
		(*pPString)->char_arr = NULL;
	}
	free((*pPString)->char_arr);
	free((*pPString));
	pPString = NULL;
	printf("Successful destoryed the string\n");
}

int string_get_size(StringPtr p)
{
	int len;
	return p->size;
}

int string_get_capacity(StringPtr p)
{
	int len;
	return p->capacity;
}

int string_compare(StringPtr str1, StringPtr str2)
{
	int i=0;
  	while(str1->char_arr[i] !='\0'&& str2->char_arr[i]!='\0')
    {
    	if(str1->char_arr[i]==str2->char_arr[i])
		{
	  		i++;
		}
    	else if((str1->char_arr[i])<(str2->char_arr[i]))
		{
	  		printf("String 2 is greater\n");
	  		return -1;
		}
    	else if((str1->char_arr[i])>(str2->char_arr[i]))
		{
	  		printf("String1 is greater\n");
	  		return 1;
		}
    }
	printf("Strings matched\n");	
	return 0;   
 }

Status string_extraction(FILE* file, StringPtr str)
{
    char c;
    char* copy;
    int i=0;
	int len;
    int doublecap =0;
    
	while(fscanf(file, "%c", &c) != -1) 
   	{
   		if (isspace(c))
    	{
    		ungetc(c,file);
       		break;
    	}
    
   		if (c != ' ') 
		{
			str->size = i;
    		if(str->size >= str->capacity)
			{
				doublecap= str->capacity *2 ;
		    	copy = (char*)malloc(sizeof(char)*doublecap);
	      		if(copy == NULL)
				{
	        		return FAILURE;
	      		}
	      		else
	      		{
	      			for(i=0;i< str->size+1;i++)
            		{
              			copy[i]= str->char_arr[i];
           			}
        			free(str->char_arr);
       				str->char_arr = (char*)malloc(sizeof(char)*doublecap);
 				str->char_arr = copy;
        			str->capacity*= 2;
					for (len = 0; str->char_arr[len] != '\0'; len++);
					str->size=len+1;
	      		}	
	      	}
	       	str->size = i+1;
      		str->char_arr[i] = c;
        	i++;
        }
	//free(copy);
    }
    if(i == 0)
    return FAILURE;
   	
    return SUCCESS;
}

Status string_insertion(FILE* file, StringPtr str)
{
	int i, ch;
	for (i = 0; i < str->size; i++) 
	{
		ch = (int)(str->char_arr[i]);
		if(fputc(ch, file) == -1)
		return FAILURE;
		else
		continue;
	}
	return SUCCESS;
}

/*
Status string_pop_back(StringPtr hString)
{
  	if(hString == NULL)
    {
    	return FAILURE;
    }
  	if(hString->size <= 0)
    {
      	return FAILURE;
    }
	hString->size--;
  	return SUCCESS;
}


Status string_push_back(StringPtr hString, char item)
{
  	char* pTemp;
  	int i;
  	//If the array is filled with elements
  	if(hString->size >= hString->capacity)
    {
      	//doubling the capacity
      	int double_capacity = hString->capacity * 2;
      	pTemp = malloc(sizeof(int)*double_capacity);
      	if(pTemp == NULL)
		{
	  		return FAILURE;
		}
      	else
		{
	  		//Copying the data from the old array to the new array
	  		for(i = 0 ; i < hString->size; i++)
	    	{
	      		pTemp[i] = hString->char_arr[i];
	    	}
	  		//Do not need the old array, free the memory
	  		free(hString->char_arr);
	  		hString->char_arr = pTemp;
	  		//Increasing the capacity of the vector
	  		hString->capacity *=2;
		}
	}
  	//Adding the item to the end of the data array
  	hString->char_arr[hString->size] = item;
  	//increasing the size after adding the item
  	hString->size++;
  	//Successfully added the item and return
  	return SUCCESS;
}
*/

char* string_at(StringPtr hString, int index)
{
	StringPtr pString = (StringPtr)malloc(sizeof(String));

	int i;
	if(index > hString->size)
    {
    	printf("No string is present\n");
      	return NULL;
    }
    return (&hString->char_arr[index]);
}

char* string_c_str(StringPtr hString)
{
	StringPtr pString = (StringPtr)malloc(sizeof(String));
	return hString->char_arr;
}