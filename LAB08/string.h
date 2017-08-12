#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include "status.h"

/*handle to the struct string*/
typedef void* STRING;

typedef struct string 
{
	int capacity;
	int size;
	char* char_arr;
}String,*String_Ptr;

//typedef void* vPtr;
//Precondition: None
//Postcondition: returns a handle to a valid string object
String_Ptr string_init_default();

//Precondition: c_str is a c string to use to initialize the string object
//Postcondition: a hadnle to the string object
String_Ptr string_init_c_string(char* c_str);

//Precondition: phString is a pointer to a handle to the string object
//Postcondition: Returns SUCCESS if we successfully freed the
//memory, FAILURE otherwise
Status string_destroy(String_Ptr* phString);

//Precondition: hString1 and hString2 are handles to two different
//string objects to compare between them.
//Postcondition: 0 both strings are equal
//<0: the first character that does not match has a lower value in str1 than in str2
//>0: the first character that does not match has a higher value in str1 than in str2 
int string_compare(String_Ptr hString1, String_Ptr hString2);

//Precondition: hString is a handle to a string object
//Postcondition: the number of characters currently held by the string object
int string_get_size(String_Ptr hString);

//Precondition: hString is a handle to string object
//Postcondition: the maximum number of character the string object can hold
int string_get_capacity(String_Ptr hString);

//Precondition: hString is a handle to a string object, fp is a pointer to
//a file to read a string from
//Postcondition: SUCCESS if we successfully read a single string from the file,
//FAILURE if reached the EOF and string is still size zero
Status string_extraction(String_Ptr hString, FILE* fp);

//Precondition: hString is a handle to a string object, fp is a pointer to
//a file to write a string to
//Postcondition: SUCCESS if it successfully wrote into the FILE* and
//FAilure if it failed to do so
Status string_insertion(String_Ptr hString, FILE* fp);

//Precondition: hString is a handle to valid string object,
//item is a character to add to the end of the string
//Postcondition: return SUCCESS if the item is
//successfully added to the string.
//The end of the string refers to the current size of the string.
//If the string reached its maximum capacity, it., size == capacity,
//then the string needed to be resized to be able to add the new item
//Resize the string by doubling its capacity
//Return FAILURE if the string could not be resized
Status string_push_back(String_Ptr hString, char item);

//Precondition: hString is a handle to a valid string object
//Postcondition: Removes the last character in the string.
//Returns SUCCESS if the last character was successfully removed
//and FAILURE if the string was empty
Status string_pop_back(String_Ptr hString);

/*****LAB05*****/
//Precondition: hString is the handle to a valid String_Ptr object.
//Postcondition: Returns the address of the character located at the given
// index if the index is in bounds but otherwise returns NULL. This address
// is not usable as a c-string since the data is not NULL terminated and is
// intended to just provide access to the element at that index.
char* string_at(String_Ptr hString, int index);

//Precondition: hString is the handle to a valid String_Ptr object.
//Postcondition: Returns the address of the first element of the string object
// for use as a c-string. The resulting c-string is guaranteed to be NULL
// terminated and the memory is still maintained by the string object though
// the NULL is not actually counted as part of the string (in size).
char* string_c_str(String_Ptr hString);

/*****LAB06*****/
//Precondition: hResult and hAppend are handles to valid String objects.
//Postcondition: hResult is the handle of a string that contains the original
// hResult object followed by the hAppend object concatenated together. This
// function should guarantee no change to the hAppend object and return
// SUCCESS if they operation is successful and FAILURE if the hResult object
// is unable to accomodate the characters in the hAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.
Status string_concat(String_Ptr hResult, String_Ptr hAppend);

//Precondition: hString is the handle to a valid String object.
//Postcondition: Returns an enumerated type with value TRUE if the string
// is empty and FALSE otherwise.
Boolean string_empty(String_Ptr hString);

#endif //STRING_H_
