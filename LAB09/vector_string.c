#include <stdio.h>
#include <stdlib.h>
#include "status.h"
#include "string.h"
#include "vector_string.h"

typedef struct vector_string 
{
	int size;
	int capacity;
	String_Ptr * data;
}Vector_String, *Vector_String_Ptr; 

Vector_String_Ptr vector_string_init_default(void)
{
	Vector_String_Ptr hVectorString = (Vector_String_Ptr)malloc(sizeof(Vector_String));

	if(hVectorString == NULL)
	return NULL;

	hVectorString->size = 0;
	hVectorString->capacity = 1;
	hVectorString->data = (String_Ptr*)malloc(sizeof(String_Ptr)*hVectorString->capacity);
    //check if memory correctly allocated
    if(hVectorString->data == NULL)
	{
	  	free(hVectorString);
	  	hVectorString = NULL;
	}
	return hVectorString;
}

void vector_string_destroy(Vector_String_Ptr * phVectorString)
{
	int i;
	for(i = 0; i < (*phVectorString)->size; i++)
	{
		if((*phVectorString)->data[i] != NULL)
		string_destroy(&((*phVectorString)->data[i]));
	}
	
	if((*phVectorString)->data != NULL)
	free((*phVectorString)->data);
	if(*phVectorString != NULL)
	free(*phVectorString);
}

Status vector_string_push_back(Vector_String_Ptr hVectorString, String_Ptr item)
{
	String_Ptr* temp = NULL;
	int i, j;
	
	if(hVectorString != NULL)
	{
		if(hVectorString->size == hVectorString->capacity)
		{
			if(hVectorString->capacity == 0)
			hVectorString->capacity = 1;
			else
			hVectorString->capacity *= 2;

			if(vector_string_empty(hVectorString) == TRUE)
			{
				hVectorString->data[0] = string_init_c_string(string_c_str(item));
				hVectorString->size++;
			}
			else
			{
				temp = malloc(sizeof(String_Ptr) * hVectorString->capacity);
				
				for(i = 0; i < hVectorString->size; i++)
				{
					temp[i] = hVectorString->data[i];
				}

				free(hVectorString->data);
				hVectorString->data = temp;
				hVectorString->data[hVectorString->size] = string_init_c_string(string_c_str(item));
				hVectorString->size++;
			}
		}
		else
		{
			hVectorString->data[hVectorString->size] = string_init_c_string(string_c_str(item));
			hVectorString->size++;
		}
		return SUCCESS;
	}
	else
	return FAILURE;
}

int vector_string_get_size(Vector_String_Ptr hVectorString)
{
	if(hVectorString != NULL)
	return hVectorString->size;
	else
	return 0;
}

int vector_string_get_capacity(Vector_String_Ptr hVectorString)
{
	if(hVectorString != NULL)
	return hVectorString->capacity;
	else
	return 0;
}

Boolean vector_string_empty(Vector_String_Ptr hVectorString)
{
	if(hVectorString == NULL || hVectorString->size == 0)
	return TRUE;
	else
	return FALSE;
}

String_Ptr* vector_string_at(Vector_String_Ptr hVectorString, int index)
{
	if(hVectorString == NULL || index < 0 || index >= hVectorString->size)
	return NULL;
	else
	return (&(hVectorString->data[index]));
}