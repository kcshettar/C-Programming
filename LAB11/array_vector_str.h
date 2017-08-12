#ifndef ARRAY_VECTOR_STR_H
#define ARRAY_VECTOR_STR_H

#include <stdio.h>
#include "vector_string.h"

/*****LAB08*****/
//typedef struct vector_string * Vector_String_Ptr;
//Precondition: words is a file that contains all the words
//in a dictionary up to length 29
//Postcondition: returns an array of pointer to a vector of strings
//The function will do the following:
//1. First, allocate memory of an array sufficient to
//hold 30 vector_string_ptr
//2. Loop through each entry in the array to allocate a 
//memory for each vector_string_ptr
//3. Extract all the strings from the file using the
//string_extract method (from the string object)
//4. Get the length of the string. Based on its length,
//add it to the corresponding vector. For example, if the
//word was hello, the length is 4. The you add the word
//hello to vector_string at index 4 in the array
Vector_String_Ptr* load_array_vector_string(FILE * words);

//Precondition: pArray is a pointer to an array of vector_string_ptr
//Postcondition: destroy the whole array, free the memory and 
//free the memory for each single vector_string_ptr inside the
//array, and then finally, set the array pointer to null.
void destroy_array_vector_string(Vector_String_Ptr ** pArray);

/*****LAB09*****/
Vector_String_Ptr * load_array_vector_string_of_size(FILE * words, int size);

/*****LAB10*****/
//Precondition:current_word_family, new_key and word are all handles to valid
//MY_STRING opaque objects. guess is an alphabetical character that can be either
//upper or lower case.
//Postcondition: Returns SUCCESS after replacing the string in new_key with the key
//value formed by considering the current word family, the word and the guess.
//Returns failure in the case of a resizing problem with the new_key string.
Status get_word_key_value(String_Ptr current_word_family, String_Ptr new_key, String_Ptr word, char guess);

#endif //ARRAY_VECTOR_STR_H