#include <stdlib.h>
#include <stdio.h>
#include "string.h"

STRING string_init_default_function(void)
{
  String* pString = (String*)malloc(sizeof(String));
  if(pString)
    {
      pString->capacity = 7;
      pString->size = 0;
      pString->char_arr = (char*) malloc(sizeof(char)*pString->capacity);
      if(!pString->char_arr)
	{
	  free(pString);
	  pString = NULL;
	}
    }
  return pString;
}

STRING string_init_c_string(char* str)
{
  int i = 0;
  String* pString = (String*)malloc(sizeof(String));
  if(pString)
    {
      while(str[i]!='\0')
	{
	  i++;
	}
      pString->capacity = i;
      pString->size = i-1;
      pString->char_arr = (char*) malloc(sizeof(char)*pString->capacity);
      if(!pString->char_arr)
	{
	  free(pString);
	  pString = NULL;
	}
      for(i = 0; i < pString->capacity; i++)
	{
	  pString->char_arr[i] = str[i];
	}
    }
  return pString;
}

int string_compare(STRING str1, STRING str2)
{
    String* Tstr1 = (String*)str1;
    String* Tstr2 = (String*)str2;
    int i = 0;
    
    while (Tstr1->char_arr[i] != '\0' && Tstr2->char_arr[i] != '\0')
    {
        
        if(Tstr1->char_arr[i] > Tstr2->char_arr[i])
        {
            i++;
            return 1;
        }
        else if(Tstr1->char_arr[i] < Tstr2->char_arr[i])
        {
            i++;
            return -1;
        }
        else if(Tstr1->char_arr[i] == Tstr2->char_arr[i])
        {
            i++;
        }
    }
   return 0;
}

void string_destroy(STRING* pPString)
{
  String* pString = (String*) *pPString;
  free(pString->char_arr);
  free(pString);
  *pPString = NULL;
}


