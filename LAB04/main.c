#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "status.h"

//Simple.txt file includes the following sentence:
//The quick brown fox jumped over the lazy dogs.
//No spaces or newlines after that period
int main(int argc, char* argv[])
{
	StringPtr hString = NULL;
	FILE* fp;
	hString = string_init_default();
	fp = fopen("simple.txt", "r");
	printf("String size: %d \n\n", string_get_size(hString));
	printf("String capacity: %d \n\n", string_get_capacity(hString));
	while(string_extraction(fp,hString))
	{
		string_insertion(stdout,hString);
		printf("\n");
		if(fgetc(fp) == ' ')
		{
			printf("String size: %d\n", string_get_size(hString));
			printf("String capacity:%d \n", string_get_capacity(hString));
			printf("Found a space after the string\n");
		}
   }
   string_destroy(&hString);
   fclose(fp);
   return 0;
}
