#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"
#include "array_vector_str.h"

#define SIZE 30

Vector_String_Ptr* load_array_vector_string(FILE * words)
{
	int i;
	String_Ptr pString = string_init_default();
	Vector_String_Ptr* dictionary = (Vector_String_Ptr*)malloc(sizeof(Vector_String_Ptr) * SIZE);
	
	if(dictionary == NULL)
	return NULL;

	for(i = 0; i < SIZE; i++)
	{
		dictionary[i] = vector_string_init_default();
	}
	
	/*If there is some data in the file then continue*/
	while(string_extraction(pString, words))
	{
		printf("%s\n", pString->char_arr);
		vector_string_push_back(dictionary[string_get_size(pString)], pString);
	}
	string_destroy(&pString);
	return dictionary;
}

void destroy_array_vector_string(Vector_String_Ptr ** pArray)
{
	int i;
	for(i = 0; i < SIZE; i++)
	{
		if((*pArray)[i] != NULL)
		{
			vector_string_destroy(&((*pArray)[i]));
		}
	}
	if((*pArray) != NULL)
	free(*pArray);
		
	*pArray = NULL;
	printf("Destroyed array vector string successfully");
}
