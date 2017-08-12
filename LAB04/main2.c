#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "status.h"

int main(int argc, char* argv[])
{
	StringPtr hString = NULL;
	hString = string_init_c_string("Hello World!");
	string_extraction(stdout,hString);
	printf("\n");
	printf("Hello World!\n");
	printf("String size: %d \n\n", string_get_size(hString));
	printf("String size: %d \n\n", string_get_capacity(hString));
	
	string_push_back(hString, ' ');
	string_push_back(hString, 'N');
	string_push_back(hString, 'e');
	string_push_back(hString, 'W');
	string_extraction(stdout,hString);
	printf("\n");
	printf("Hello World!NeW\n");
	printf("String size: %d \n\n", string_get_size(hString));
	printf("String size: %d \n\n", string_get_capacity(hString));
	
	string_pop_back(hString);
	string_extraction(stdout,hString);	
	printf("\n");
	printf("Hello World!Ne\n");
	printf("String size: %d \n\n", string_get_size(hString));
	string_pop_back(hString);
	string_pop_back(hString);	
	string_pop_back(hString);
	string_extraction(stdout,hString);
	printf("\n");
	printf("Hello World!\n");
	printf("String size: %d \n", string_get_size(hString));
	string_destroy(&hString);
	return 0;
}