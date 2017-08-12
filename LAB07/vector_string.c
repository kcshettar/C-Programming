#include <stdio.h>
#include <stdlib.h>
#include "vector_string.h"
#include "string.h"


struct vector_string
{
  int size;
  int capacity;
  String_Ptr * data;
};
typedef struct vector_string Vector;

Vector_String_Ptr vector_string_init_default(void)
{
  Vector_String_Ptr pVector;
  
  pVector = (Vector_String_Ptr)malloc(sizeof(Vector));
  if(pVector != NULL)
    {
      pVector->size = 0;
      //initially, the vector is setup to hold only one element
      pVector->capacity = 1;
      pVector->data = (String_Ptr*)malloc(sizeof(String_Ptr)*pVector->capacity);
      //Check if memory correctly allocated
      if(pVector->data == NULL)
	{
	  free(pVector);
	  pVector = NULL;
	}
    }
  //Return the pointer to the vector (the memory address)
  return pVector;
}


void vector_string_destroy(Vector_String_Ptr * phVectorString)
{
   	int i;
   	//printf("Destroyed the string SUCCESS\n");
  	for(i=0;i!=(*phVectorString)->size;i++)
    string_destroy(&((*phVectorString)->data[i]));
 	if(*phVectorString!= NULL)
    {
      	if((*phVectorString)->data != NULL)
		{
	  		free((*phVectorString)->data);
		}
      	free(*phVectorString);
      	*phVectorString = NULL;
    }

}


Status vector_string_push_back(Vector_String_Ptr hVectorString, String_Ptr item)
{
	printf("Called vector_string_push_back\n");
  	String_Ptr * pTemp;
  	int i;
  	//Resizing
  	if(hVectorString->size >= hVectorString->capacity)
    {
      	int double_capacity = hVectorString->capacity * 2;
      	pTemp = malloc(sizeof(int)*double_capacity);
      	if(pTemp == NULL)
		{
	  		return FAILURE;
		}
      	else
		{
	  		for(i = 0 ; i < hVectorString->size; i++)
	    	{
	      		pTemp[i] = hVectorString->data[i];
	    	}
	  		free(hVectorString->data);
	  		hVectorString->data = pTemp;
	  		hVectorString->capacity *=2;
		}
    }
  	hVectorString->data[hVectorString->size] = item;
  	hVectorString->size++;
  	hVectorString->capacity++;
  	return SUCCESS;
}

String_Ptr* vector_string_at(Vector_String_Ptr hVectorString, int index)
{
  	if(index >= hVectorString->size || index < 0)
    {
      return NULL;
    }
  	return(&(hVectorString->data[index]));
}

int vector_string_get_size(Vector_String_Ptr hVectorString)
{
  	if(hVectorString != NULL)
    {
      	return hVectorString->size;
    }
    return -1;
}

int vector_string_get_capacity(Vector_String_Ptr hVectorString)
{
  	if(hVectorString != NULL)
    {
      	return hVectorString->capacity;
    }
  	return -1;
}

Boolean vector_string_empty(Vector_String_Ptr hVectorString)
{
  	if(hVectorString->size > 0)
    {
    	//printf("hVectorStringPresent\n");
      	return FALSE;
      	printf("\n\n");
      	printf("String is empty\n");
    }
  	return TRUE;
  	//printf("Not empty\n");
}