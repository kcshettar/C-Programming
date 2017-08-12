#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "vector_string.h"
#include "array_vector_str.h"

int main(int argc, const char * argv[])
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

	//printf("\n******************************LAB08******************************");
	/*printf("\n");
  	int i;
  	FILE *words;
  	words = fopen("dictionary1.txt", "r");
	String_Ptr test = string_init_default();
	char* c;*/
	/*initialization of the array*/
	/*Vector_String_Ptr* vector = load_array_vector_string(words);
	destroy_array_vector_string(&vector);
  	printf("\n");
  	fclose(words);
 	return 0;*/

  	//printf("\n******************************LAB08******************************");
  	//FILE *words;
  	//words = fopen("dictionary1.txt", "r");
  	//String_Ptr test = string_init_default();
	//char* c;
	/*initialization of the array*/
	//Vector_String_Ptr* vector = load_array_vector_string(words);
	//destroy_array_vector_string(&vector);

 	//printf("\n******************************LAB09******************************");
	/*printf("\n");
  	int i, j = 0, index = 0;
  	int length = 0;
  	int no_of_guesses = 0;
  	char input;
  	char c;

  	FILE *words;
  	words = fopen("dictionary1.txt", "r");
	
	printf("Enter the length of the word:");
	scanf("%d",&length);
	while (length < 2 || length == 23 || length == 25 || length == 26 || length == 27 || length > 29)
	{
		printf("There is no word of this length");
		printf("\nPlease try again\n");
		scanf("%d",&length);
	}*/

	/*Guesses you would like to try*/
	/*printf("Enter the number of guesses you need:");
	scanf("%d",&no_of_guesses);
	
	while(no_of_guesses < 1) 
	{
		printf("Number of guesses cannot be below zero");
		printf("Please try again\n");
		scanf("%d", &no_of_guesses);
	}*/

	/*number of guess greater than the selected length*/
	/*while(no_of_guesses > length)
	{
		printf("Number of guesses cannot be greater than the length of the word you have entered");
		printf("Please try again\n");
		scanf("%d", &no_of_guesses);
	}*/
	
	/*laod a string from the file for defined length from the user*/
	/*Vector_String_Ptr* hVectorString = load_array_vector_string_of_size(words, length);
    	
    while(vector_string_empty(hVectorString[index])) 
	{
		index--;
	}
	printf("The current word is %s\n",string_c_str(*vector_string_at(hVectorString[index], 0)));
	    
	String_Ptr hTemp = string_init_default();
		
	if(vector_string_empty(hVectorString[index]))
	printf("\nvector string at index number is empty2");
	int size = string_get_size(*vector_string_at(hVectorString[index], 0));
	    
	for(j = 0 ; j < size; j++)
	{
		string_push_back(hTemp, '-');
	}
	for(j = 0 ; j < size; j++)
	{
		printf("%c",string_c_str(hTemp)[j]);
	}
	printf("\n");
    
	while(no_of_guesses > 0) 
	{
		printf("Please guess a letter:");
		scanf(" %c", &c);
		for(j = 0 ; j < size; j++)
	  	{
	    	if(c == (string_c_str(*vector_string_at(hVectorString[index], 0)))[j])
	      	{
				string_insert_at_index(hTemp, j, c);
	      	}
	  	}
		if(string_compare(*vector_string_at(hVectorString[index], 0), hTemp) == 0)
		{
		    printf("\nCONGRATULATION..!! YOU WON THIS GAME..!!\n");
		    break;
		}
	
		for(j = 0 ; j < size; j++) 
		{
			if(string_c_str(hTemp)[j] != '-') 
			{
				printf("%c",string_c_str(hTemp)[j]);
			}
			else
			{
				printf("-");
			}
		}
		printf("\n");
		no_of_guesses--;
		
		if(no_of_guesses)
		{
		  	printf("\nYou have %d attempts left\n",no_of_guesses);
		}
		else
		{
		   	printf("\nSorry..!! Better Luck Next Time..!!\n");
		}
	}
    printf("\nSelected word is: %s\n", string_c_str(*vector_string_at(hVectorString[index], 0)));
    string_destroy(&hTemp);
    destroy_array_vector_string(&hVectorString);
	printf("\n");
  	printf("\nEND OF GAME\n");
}*/

	printf("\n******************************LAB10******************************");
	int j, index = 0;
    char string_word_family[7];
    char string_word[7];
    char guess;
    char input;
    printf("\n");
    
    FILE *words;
  	words = fopen("dictionary1.txt", "r");

	int length = 7;
	Vector_String_Ptr* hVectorString = load_array_vector_string_of_size(words, length);
    
    printf("Enter word for family: ");
    scanf("%s", string_word_family);
    printf("Enter word from the dictionary: ");
    scanf("%s", string_word);
    printf("Enter the guess: ");
    scanf(" %c", &guess);
    printf("You entered:\nWord familiy -> %s\nFrom dictionary -> %s\nGuess -> %c\n", string_word_family, string_word, guess);
    
    String_Ptr current_word_family = string_init_c_string(string_word_family);
    String_Ptr word = string_init_c_string(string_word);
    String_Ptr new_key = string_init_default();
    

    //printf("The current word is %s\n",string_c_str(*vector_string_at(hVectorString[index], 0)));

    if(get_word_key_value(current_word_family, new_key, word, guess) == SUCCESS)
	{
        printf("\nThe new key is: ");
        for(j = 0 ; j < string_get_size(word); j++)
	 	{
            printf("%c",string_c_str(new_key)[j]);
        }
        printf("\n");
    }

    string_destroy(&current_word_family);
    string_destroy(&word);
    string_destroy(&new_key); 

/*END OF LAB10*/
    fclose(words);
   	return 0;
}