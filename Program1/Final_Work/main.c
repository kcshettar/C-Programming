#include <stdio.h>
#include <stdlib.h>
#include "bit_flag.h"
/*
 GRADER MAIN PROGRAM - 1
 PROJECT - 1
 */
int main(int argc, char* argv[]) 
{
    BIT_FLAGS hBit_flag = NULL;  //declaring the handle
    int i;
    int cap = 1;
        
    hBit_flag = bit_flags_init_number_of_bits(cap);
    bit_flags_set_flag(hBit_flag, 3);
    bit_flags_unset_flag(hBit_flag, 3);
    bit_flags_set_flag(hBit_flag, 5);
    bit_flags_unset_flag(hBit_flag, 5);
    //bit_flags_set_flag(hBit_flag, 10);
    //hBit_flag = bit_flags_init_number_of_bits(5); //initialization of the object
    if (hBit_flag == NULL)
    {
    	printf("Something terrible happened...\n");
    	exit(1);
    }
    
    for (i = 0;i < 1 ; i++)
    {
        printf("\nSize is : %d \nCapacity is : %d\n", bit_flags_get_size(hBit_flag),bit_flags_get_capacity(hBit_flag));
        if (bit_flags_set_flag(hBit_flag, rand()) == FAILURE)
        {
            printf("%d oops!\n", i);
            exit(1);
        }
    }
    
    for(i=31; i>=0; i--)
    {
        printf("%d", bit_flags_check_flag(hBit_flag, i));
        if(i%4 == 0)
        {
            //printf("%d", i);
        }
    }
    
    bit_flags_destroy(&hBit_flag);
    return 0;
}