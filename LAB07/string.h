#ifndef STRING_H_
#define STRING_H_
#include "status.h"

typedef void* STRING;

typedef struct string
{
	int capacity;
	int size;
	char* char_arr;
} String, *String_Ptr;

typedef void* vPtr;
String_Ptr string_init_default();
String_Ptr string_init_c_string(char*);
Status string_destroy(String_Ptr*);
int string_compare(String_Ptr, String_Ptr);
Status string_push_back(String_Ptr hString, char item);
Status string_pop_back(String_Ptr hString);
int string_get_size(String_Ptr);
int string_get_capacity(String_Ptr);
//Status string_extraction(FILE*, String_Ptr);
//Status string_insertion(FILE*, String_Ptr);

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

#endif