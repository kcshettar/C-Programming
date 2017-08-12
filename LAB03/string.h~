typedef void* STRING;

struct string 
{
    int capacity;
    int size;
    char* char_arr;
};

typedef struct string String;
typedef void* vPtr;

STRING string_init_default(int capacity);
STRING string_init_c_string(char* str);
void string_destroy(STRING* pPString);
int string_compare(STRING str1, STRING str2);
int string_get_size(STRING str1);
int string_get_capacity(STRING str1);
int string_extraction(FILE* file1, STRING str2);
int string_insertion(FILE* file2, STRING str2);
