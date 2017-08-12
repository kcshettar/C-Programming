/***********************************************************
Author: KIRAN C SHETTAR
Date: 02/27/2016
Effort: 077 hours
Purpose: Bit_flags with opaque objects
Interface proposal: We could add a function to fetch the data 
what all bit values are set and unset 
***********************************************************/
#include<stdlib.h>
#include "bitflags.h"


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    int i;
    Bit_flags* pBit_flags;
    pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    if(pBit_flags != NULL)
    {
        //intialization of size & capacity
        pBit_flags->size = 0;
        pBit_flags->capacity = pBit_flags->size + 1;
        pBit_flags->data = (int*)calloc(i, sizeof(int));		
        if (pBit_flags->data == NULL)//Worst case
        {
            free(pBit_flags);
            pBit_flags = NULL;
        }
    }
    return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    int* pTemp;
    int i;
    
    //Checking the size here
    if(flag_position >= pBit_flags->size)
    {
        pBit_flags->size = flag_position + 1;
    }
    
    //Checking the capacity here
    if(flag_position >= pBit_flags->capacity)
    {
        pTemp = (int*)malloc(sizeof(int)*pBit_flags->capacity * 2);
        if(pTemp == NULL)
        {
            return FAILURE;
        }
        for(i = 0; i < pBit_flags->size; i++)
        {
            pTemp[i] = pBit_flags->data[i];
        }
        free(pBit_flags->data);
        pBit_flags->data = pTemp;
        pBit_flags->capacity *= 32;
    }
    //setting the flag here
    //printf("Setting the flag to the number %d", flag_position);
    pBit_flags->data[flag_position/32] |= 1 << (flag_position % 32);
    return SUCCESS;
}
        
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    //printf("Success unset");
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    pBit_flags->data[flag_position/32] &= ~(1 << (flag_position%32));
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    return ((pBit_flags->data[flag_position / 32] &(1 << flag_position % 32))!= 0);
    
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags* )hBit_flags;
    return pBit_flags->size;   
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags* )hBit_flags;
    return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*) *phBit_flags;
    if(pBit_flags != NULL)
    {
	free(pBit_flags->data);
	free(pBit_flags);
    }
    *phBit_flags = NULL;
    printf("\nFlags are destroyed");
    return;
}