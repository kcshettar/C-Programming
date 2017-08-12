#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"
#include "status.h"

String_Ptr string_init_default()
{
	int capacity=2;
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
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

String_Ptr string_init_c_string(char* s)
{
	int len;
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
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

int string_get_size(String_Ptr p)
{
	int len;
	return p->size;
}

int string_get_capacity(String_Ptr p)
{
	int len;
	return p->capacity;
}

int string_compare(String_Ptr str1, String_Ptr str2)
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

/*
Status string_extraction(FILE* file, String_Ptr str)
{
    char c;
    char* copy;
    int i=0;
	int len;
    int doublecap =0;

	while(fscanf(file, "%c", &c) != -1) 
   	{
   		if (isspace(c) && i!=0)
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
					printf("No copy\n");
	        		return FAILURE;
	      		}
	      		else
	      		{
	      			for(i=0;i< str->size;i++)
            		{
              			copy[i]= str->char_arr[i];
           			}
        			free(str->char_arr);
       				str->char_arr = (char*)malloc(sizeof(char)*doublecap);
       				for(i=0;i< str->size;i++)
            		{
              			str->char_arr[i]= copy[i];
           			}
 					//str->char_arr = copy;
        			str->capacity*= 2;
					for (len = 0; str->char_arr[len] != '\0'; len++);
					str->size=len+1;
	      		}	
	      		free(copy);
	      	
	      	}
	       	str->size = i+1;
      		str->char_arr[i] = c;
        	i++;
        }
	}
	str->char_arr[str->size] = '\0';
    if(i == 0)
    	return FAILURE;
   	//check extraction
   	//printf("%s\n", str->char_arr);
    return SUCCESS;
}

Status string_insertion(FILE* file, String_Ptr str)
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

*/
Status string_pop_back(String_Ptr hString)
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


Status string_push_back(String_Ptr hString, char item)
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


char* string_at(String_Ptr hString, int index)
{
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));

	int i;
	if(index > hString->size)
    {
    	printf("No string is present\n");
      	return NULL;
    }
    return (&hString->char_arr[index]);
}

char* string_c_str(String_Ptr hString)
{
	String_Ptr pString = (String_Ptr)malloc(sizeof(String));
	return hString->char_arr;
}

Boolean string_empty(String_Ptr hString)
{
	/*Check if there is no string present in the file*/
	if(hString == NULL)
    {
    	//printf("Nothing in file\n");
    	return TRUE;
    	printf("\n\n");
    }

  	if(hString->size <= 0)
    {
    	//printf("NothingPresent\n");
      	return TRUE;
    	printf("\n\n");
    }
	hString->size--;
	//printf("STRING present\n");
  	return FALSE;
}

Status string_concat(String_Ptr hResult, String_Ptr hAppend)
{
  	int i=0;
  	int j,k,g = 0;
  	char c;
  	char* copy;
  	int len;
  	int doublecap =0;

  	if(hResult->size+hAppend->size >= hResult->capacity)
    {
      	/*REALLOCATION*/
      	doublecap= hResult->capacity *2 ;
        copy = (char*)malloc(sizeof(char)*doublecap);
      	if(copy == NULL)
		{
	  		return FAILURE;
		}
      	else
		{
	  		for(i=0;i< hResult->size+1;i++)
	    	{
	      		copy[i]= hResult->char_arr[i];
	    	}
	  		free(hResult->char_arr);
			hResult->char_arr= (char*)malloc(sizeof(char)*doublecap);	
			for(i=0;i< hResult->size+1;i++)
	    	{
	       		hResult->char_arr[i]=copy[i];
	     	}
	  		hResult->capacity*= 2;
	  	}
      
        if(hResult->char_arr=='\0')
		{
	  		for(i=0;hAppend->char_arr[i]!='\0';i++)
	    	hResult->char_arr[i]=hAppend->char_arr[i];
		}
     	else
		{
	 		for(i=0;hResult->char_arr[i]!='\0';i++);
	  		if (hResult->size!=0) 
	    	{
	      		hResult->char_arr[i]=' ';
	      		hResult->size++;
	      		i++;
	    	}
	  		k=i; 
	  		for(g=0;hAppend->char_arr[g]!='\0';g++)
	    	{
	      		hResult->char_arr[k+g]=hAppend->char_arr[g];
	      		hResult->size++;
	      	}
		}
     	free(copy);
    }
  	
  	else
    {
        for(i=0;hResult->char_arr[i]!='\0';i++);
      	if (hResult->size!=0)  
      	{
			hResult->char_arr[i]=' ';
			hResult->size++;
			i++;
      	}
      	k=i; 
      	for(g=0;hAppend->char_arr[g]!='\0';g++)
		{
	  		hResult->char_arr[k+g]=hAppend->char_arr[g];
	  		hResult->size++;
	  	}
    }
}


Status string_destroy(String_Ptr* pPString) 
{
	if((*pPString)->char_arr != NULL)
	{
		(*pPString)->char_arr = NULL;
	}
	free((*pPString)->char_arr);
	free((*pPString));
	pPString = NULL;
	printf("Successful destoryed the string");
}