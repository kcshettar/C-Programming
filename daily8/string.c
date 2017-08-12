#include "string.h"

struct string
{
    char* ch_data;
    int capacity;
    int size;
};
typedef struct string String;

String_Ptr string_init_default()
{
    String_Ptr pString = (String_Ptr)malloc(sizeof(String));
    if(pString)
    {
        pString->capacity = 20;
        pString->ch_data =(char*)malloc(sizeof(char)*(pString->capacity));
        pString->size = 0;
        if(pString->ch_data)
        {
            return pString;
        }
        else
        {
            free(pString);
            pString = NULL;
            printf("Memory allocation failed\n");
            return NULL;
        }
    }
    else
    {
        printf("Memory allocation failed for pString\n");
        return NULL;
    }
}

void string_destroy(String_Ptr* phString)
{
    String_Ptr pString = (String_Ptr) *phString;
    if (pString->ch_data != NULL) 
    {
        free(pString->ch_data);
    }
    if(pString!= NULL)
    {
        free(pString);
    }
    *phString = NULL;
    return;
}

Status string_insertion(String_Ptr hString, FILE * fp)
{
    if (hString == NULL) 
    {
        return FAILURE;
    }
    if( fp == NULL)
    {
        printf("File Not found\n");
        return FAILURE;
    }
    else
    {
        int i = 0;
        int ch = 0;
        for(i = 0; i < (hString->size); i++)
        {
            ch = (hString->ch_data[i]);
            if(fputc(ch, fp)==EOF)
            {printf("Error writing file\n");
                return FAILURE;
            }
            else
                continue;
        }
        return SUCCESS;
    }
}

void* string_make_temp(String_Ptr hString, unsigned int old_size)
{
    if (hString == NULL) 
    {
        return NULL;
    }
    char* temp =(char*)malloc((sizeof(char)*(hString->capacity)));
    int j;
    if(temp)
    {
        for(j = 0; j < old_size; j++) 
        {
            temp[j]= hString->ch_data[j];
        }
        return temp;
    }
    else
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
}

Status string_resize(String_Ptr hString)
{
    if (hString == NULL) 
    {
        return FAILURE;
    }
    hString->capacity *=2;//double capacity
    char* temp = string_make_temp(hString, hString->size);
    if(temp!= NULL)
    {
        free(hString ->ch_data);
        hString->ch_data= temp;
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

Status get_line(String_Ptr hString, FILE * fp)
{
    if (hString == NULL || fp == NULL) 
    {
        return FAILURE;
    }
    else
    {
        char c;
        while(fscanf(fp,"%c", &c)!=EOF) 
        {
            if(c == '\n')
            {
                break;
            }
            else
            {
                hString->ch_data[hString->size] = c;
                hString->size++;
                if(hString->size == hString->capacity)
                    {
                        if(string_resize(hString) == FAILURE)
                        {
                            return  FAILURE;
                    }
                }
            }
        }
        if (hString->size == 0)
        {
            return FAILURE;
        }
        else
        {
            return SUCCESS;
        }
    }
}

int is_palindrome(String_Ptr hString)
{
    if (hString == NULL) 
    {
        return 0;
    }
    int i = 0;
    int length = 0;
    char temp[hString->size];
    for (i = 0; i < hString->size; i++) 
    {
        if (isalpha(hString->ch_data[i])) 
        {
            temp[length] = toupper(hString->ch_data[i]);
            length++;
        }
    }
    hString->size = 0;
    int tail = length-1;
    int head = 0;
    for (head = 0; head < length/2; head++,tail--) 
    {
        if (temp[head] != temp[tail]) 
        {
            return 0;
        }
    }
    return 1;
}

void reset_size(String_Ptr hString)
{
    hString->size = 0;
}