#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef void* STRING;

STRING string_init_default_function(void);
STRING string_init_c_string(char* str);
void string_destroy(STRING* pPString);
int string_compare(STRING str1, STRING str2);

int main(int argc, char* argv[])
{
  STRING str1 = string_init_c_string("GLaDOs");
  STRING str2 = string_init_c_string("GLaDOS2");
  printf("\nCompared! Result is: %d \n", string_compare(str1, str2));
  
  string_destroy(&str1);
  string_destroy(&str2);
  return 0;
}