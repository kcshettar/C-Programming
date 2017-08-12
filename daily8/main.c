/****************************************************
Program: Palindrome
Author: Kiran C Shettar
Date: 3/30/2016
Time spent: 2 days
Purpose: Check whether the given string is palindrome
*****************************************************/

#include "string.h"
int main(int argc, const char * argv[]) 
{
    String_Ptr hString = NULL;
    FILE* fp;
    hString = string_init_default();
    fp = fopen("simple.txt","r");
    while (get_line(hString, fp)) 
    {
        if(is_palindrome(hString))
        {
            printf("Yes\n");
        }
        else
        printf("No\n");
        reset_size(hString);
    }
    fclose(fp);
    string_destroy(&hString);
    fclose(stdout);    
    return 0;
}
