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
	
	/*data extraction from file*/
	while(string_extraction(pString, words))
	{
		vector_string_push_back(dictionary[string_get_size(pString)], pString);
		/*print the data from the file*/
		//printf("%s\n", pString->char_arr);
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
	printf("\nDestroyed array vector string successfully");
}

Vector_String_Ptr * load_array_vector_string_of_size(FILE * words, int size)
{
    if (words == NULL)
 	{
        printf("Invalid file\n");
        return NULL;
    }
    String_Ptr pString = NULL;
    pString = string_init_default();
    Vector_String_Ptr* vector_array = (Vector_String_Ptr*)malloc(sizeof(Vector_String_Ptr)*31);
    int i;
    int array_index = 0;
    if (vector_array)
 	{
        for (i = 0; i < 30; i++)
 		{
            vector_array[i] =  vector_string_init_default();
        }

        while (string_extraction(pString, words))
        {
            if (string_get_size(pString) != size)
            {
                continue;
            }
        
            vector_string_push_back(vector_array[array_index++], pString);
            if (array_index == size)

 			{
                break;
            }
        }
        string_destroy(&pString);
        return vector_array;
    }
    return NULL;
}