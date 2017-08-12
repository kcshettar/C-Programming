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
#endif

