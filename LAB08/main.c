#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"
#include "array_vector_str.h"

int main()
{
	//printf("\n******************************LAB06******************************");
	/*printf("\n");
	String_Ptr hString = NULL;
	String_Ptr hResult = NULL;
	String_Ptr hAppend = NULL;
	FILE* fp;*/
	
	/**************************************************/
	/***** Testing string_at and string_empty**********/
	/*hString = string_init_c_string("Hello World!");
	string_insertion(stdout,hString);
	printf("\nString size: %d\n", string_get_size(hString));
	printf("String inside hString: %s\n", string_c_str(hString));
	printf("The string has letter: %c at index: 10\n", *string_at(hString,10));
	printf("is the string empty:%d\n", string_empty(hString));
	printf("\n");*/

	/**************************************************/
	/****Testing string_extraction ,string_insertion***/
	//lab6
	/*********Testing string_concat********************/
	/*hResult = string_init_default();
	hAppend = string_init_default();
	fp = fopen("simple.txt", "r");
	while(string_extraction(fp, hAppend))
	{
		string_concat(hResult,hAppend);
		string_insertion(stdout,hResult);
		printf("\n");
	}
	printf("\n");//printf("\n");*/

	/****************************************************/
	/*********Testing empty and pop_back*****************/
	/*while(string_empty(hResult) == FALSE)
	{
		string_pop_back(hResult);
	}
	printf("The string after popping all characters:");
	string_insertion(stdout, hResult);
	printf("\nThe string size: %d", string_get_size(hResult));
	printf("\nis the string empty: %d", string_empty(hResult));
	printf("\n");printf("\n");*/

	/*********Testing destroy**********/
	/*string_destroy(&hResult);
	string_destroy(&hAppend);
	string_destroy(&hString);
	fclose(fp);

	printf("\n******************************LAB07******************************");
	printf("\n");
  	String_Ptr result;
  	Vector_String_Ptr pV = vector_string_init_default();
 	String_Ptr var = string_init_c_string("abc");
  	//String_Ptr var1 = string_init_c_string("def");
	printf("Initial size: %d\n", vector_string_get_size(pV));
  	printf("Initial capacity: %d\n",vector_string_get_capacity(pV));
  	vector_string_push_back(pV, var);
  	//vector_string_push_back(pV, var1);
  	printf("vector_string_empty check: %d\n", vector_string_empty(pV));
 	printf("Present size:%d\n", vector_string_get_size(pV));
  	printf("Present capacity:%d\n",vector_string_get_capacity(pV));
  	result = *vector_string_at(pV,0);
  	printf("The element at index 0: %s\n", result->char_arr);
  	/*For the second element*/
  	//result = *vector_string_at(pV,1);
  	//printf("The element at index 1: %s\n", result->char_arr);*/

	printf("\n******************************LAB08******************************");
	printf("\n");
  	int i;
  	FILE *words;
  	words = fopen("dictionary1.txt", "r");
	String_Ptr test = string_init_default();
	char* c;
	
	/*initialization of the array*/
	Vector_String_Ptr* vector = load_array_vector_string(words);
	destroy_array_vector_string(&vector);
  	printf("\n");
  	fclose(words);
 	return 0;
}