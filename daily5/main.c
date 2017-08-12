/***********************************************************
Author: Kiran Shettar
Date: 02/05/2016
Effort: Almost 4 hours
Purpose: To understand the bit operations in C language
Use of Bit wise operators '&', '|', '<<', '~' 
and implementation of the daily 4 using the arrays 
***********************************************************/
#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder[]);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };
    
    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);
    display_flags(flag_holder, 5);
    printf("\n\n");
    
    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);

    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    flag_holder[5] |= 1 << (flag_position);
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    flag_holder[5] &= ~(1 << (flag_position));
}

int check_flag(unsigned int flag_holder[5], int flag_position)
{
        if((flag_holder[5] &(1 << flag_position))!=0)
        {
            return 1;
        }
    else
    return 0;
}
 
void display_32_flags_as_array(unsigned int flag_holder[])
{
    int i;              
    for(i=31; i>=0; i--)
    {
        
        printf("%d", check_flag(&flag_holder[5], i));
        if(i%4 == 0)
	{
	   //printf("%d", i);
	}
    }
    printf("\n");
}

void display_flags(unsigned int flag_holder[], int size)
{
    int i;
    int num;
    for(i=0; i<32; i++)
    {
        for(num=0; num<=6; num++)
        {
            printf("%d", check_flag(&flag_holder[num], i));
        }
    }
    printf("\n\n");
}