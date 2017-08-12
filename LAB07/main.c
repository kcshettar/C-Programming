#include "vector_string.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  	String_Ptr result;
  	Vector_String_Ptr pV = vector_string_init_default();
 	String_Ptr var = string_init_c_string("abc");
  	//String_Ptr var1 = string_init_c_string("def");
	printf("Initial size: %d\n", vector_string_get_size(pV));
  	printf("Initial capacity: %d\n",vector_string_get_capacity(pV));
  	vector_string_push_back(pV, var);
  	//vector_string_push_back(pV, var1);
  	printf("vector_string_empty check: %d\n", vector_string_empty(pV));
 	printf("Present size:%d\n", vector_string_get_size(pV));
  	printf("Present capacity:%d\n",vector_string_get_capacity(pV));
  	result = *vector_string_at(pV,0);
  	printf("The element at index 0: %s\n", result->char_arr);
  	//result = *vector_string_at(pV,1);
  	//printf("The element at index 1: %s\n", result->char_arr);

  	vector_string_destroy(&pV);
  	printf("\n");
 	return 0;
}
