/***********************************************************
Author: Kiran Shettar
Date: 01/29/2016
Effort: Almost 2 hours
Purpose: To understand the bit operations in C language
Use of Bit wise operators '&', '|', '<<', '~'  
***********************************************************/
#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
    unsigned int flag_holder = 0;
    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);
    display_32_flags(flag_holder);
    unset_flag(&flag_holder, 31);
    unset_flag(&flag_holder, 3);
    set_flag(&flag_holder, 9);
    display_32_flags(flag_holder);
return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position)
{
    (*flag_holder) |= 1 << (flag_position);
}

void unset_flag(unsigned int * flag_holder, int flag_position)
{
    (*flag_holder) &= ~(1 << (flag_position));
}

int check_flag(unsigned int flag_holder, int flag_position)
{
        if((flag_holder &(1 << flag_position))!=0)
        {
            return 1;
        }
    else
    return 0;
}

void display_32_flags(unsigned int flag_holder)
{
    int i;
    for(i=31; i>=0; i--)
    {
	printf("%d", check_flag(flag_holder, i));
    }
    printf("\n");
}

