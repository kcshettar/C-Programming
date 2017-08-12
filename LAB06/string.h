#ifndef STRING_H_
#define STRING_H_
#include "status.h"

typedef void* STRING;

typedef struct string
{
	int capacity;
	int size;
	char* char_arr;
} String, *StringPtr;

typedef void* vPtr;
StringPtr string_init_default();
StringPtr string_init_c_string(char*);
Status string_destroy(StringPtr*);
int string_compare(StringPtr, StringPtr);
Status string_push_back(StringPtr hString, char item);
Status string_pop_back(StringPtr hString);
int string_get_size(StringPtr);
int string_get_capacity(StringPtr);
Status string_extraction(FILE*, StringPtr);
Status string_insertion(FILE*, StringPtr);

/*****LAB05*****/
//Precondition: hString is the handle to a valid String_Ptr object.
//Postcondition: Returns the address of the character located at the given
// index if the index is in bounds but otherwise returns NULL. This address
// is not usable as a c-string since the data is not NULL terminated and is
// intended to just provide access to the element at that index.
char* string_at(StringPtr hString, int index);

//Precondition: hString is the handle to a valid String_Ptr object.
//Postcondition: Returns the address of the first element of the string object
// for use as a c-string. The resulting c-string is guaranteed to be NULL
// terminated and the memory is still maintained by the string object though
// the NULL is not actually counted as part of the string (in size).
char* string_c_str(StringPtr hString);

/*****LAB06*****/
//Precondition: hResult and hAppend are handles to valid String objects.
//Postcondition: hResult is the handle of a string that contains the original
// hResult object followed by the hAppend object concatenated together. This
// function should guarantee no change to the hAppend object and return
// SUCCESS if they operation is successful and FAILURE if the hResult object
// is unable to accomodate the characters in the hAppend string perhaps
// because of a failed resize operation. On FAILURE, no change to either
// string should be made.
Status string_concat(StringPtr hResult, StringPtr hAppend);

//Precondition: hString is the handle to a valid String object.
//Postcondition: Returns an enumerated type with value TRUE if the string
// is empty and FALSE otherwise.
Boolean string_empty(StringPtr hString);


#endif

