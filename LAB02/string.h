typedef void* STRING;

STRING string_init_default_function(void);
STRING string_init_c_string(char* str);
void string_destory(STRING* pPString);
int string_compare(STRING str1, STRING str2);

struct string
{
  int capacity;
  int size;
  char* char_arr;
};

typedef struct string String;

