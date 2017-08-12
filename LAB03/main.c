#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef void* STRING;

STRING string_init_default(int capacity);
STRING string_init_c_string(char* str);
void string_destroy(STRING* pPString);
int string_compare(STRING str1, STRING str2);
int string_get_size(STRING str);
int string_get_capacity(STRING str);
int string_extraction(FILE* file, STRING str1);
int string_insertion(FILE* file, STRING str2);

int main(int argc, char* argv[])
{
    int i = 0;

  STRING str2;
  int cap = 1;
  String* Tstr2 = (String*)str2;
  Tstr2 = string_init_default(cap);


	FILE* file1;
	FILE* file2;
  file1 = fopen("input.txt","r");
  file2 = fopen("output.txt","w+");

  string_extraction(file1, Tstr2);  
  printf("Characters read from file1 -> %s\n", Tstr2->char_arr);
  string_insertion(file2, Tstr2);

    printf("\nThe size of the String is = %d\n", string_get_size(Tstr2));
    printf("The capacity of the String is = %d\n", string_get_capacity(Tstr2));

  
  fclose(file1);
  fclose(file2);

string_destroy(&Tstr2);
  return 0;
}
