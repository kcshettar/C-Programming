#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "status.h"

//Simple.txt file includes the following sentence:
//The quick brown fox jumped over the lazy dogs.
//No spaces or newlines after that period.
int main(int argc, char* argv[])
{
	StringPtr hString = NULL;
	FILE* fp;
	hString = string_init_default();
	fp = fopen("simple.txt", "r");

	/*Initial Size and capacity of the string
	printf("String size: %d \n\n", string_get_size(hString));
	printf("String capacity: %d \n\n", string_get_capacity(hString));*/

	while(string_extraction(fp,hString))
	{
		//string_insertion(stdout,hString);
		//printf("\n");
		if(fgetc(fp) == ' ')
		{
			/*Size & capacity of every string
			printf("String size: %d\n", string_get_size(hString));
			printf("String capacity:%d \n", string_get_capacity(hString));*/
			
			/*If there is a space found in the file*/
			/*printf("Found a space after the string\n");*/
		
			//printf("\n%d\n", *string_c_str(hString));
			
			/* Srting at Function Test */
			//*string_at(hString, 3) = 50;
			//printf("%d\n", *string_at(hString, 1));
   			//for (int i = 0; i < string_get_size(hString); ++i)
   			//{
   				/* code */
   				//string_insertion(stdout,hString);
   				//printf("%d\n", *string_at(hString, 0));
   				//-> Is at : 
   			//}
		}
		printf("\nThe character is '%c' and the address is : %d\n", *string_c_str(hString), *string_c_str(hString));
   	}
   	//string_insertion(stdout,hString);
   	printf("\n\n*****String at function*****\n");
   	
   	printf("The character is '%c'\n", *string_at(hString, 0));
   	printf("The character is '%c'\n", *string_at(hString, 1));
   	printf("The character is '%c'\n", *string_at(hString, 2));
   	printf("The character is '%c'\n", *string_at(hString, 3));
   	printf("The character is '%c'\n", *string_at(hString, 4));
	
	//printf("\n*****No more data in file*****\n");

   	//string_destroy(&hString);
   	fclose(fp);
   	return 0;
}