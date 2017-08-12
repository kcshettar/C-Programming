/***********************************************************
Author: Kiran C Shettar
Date: 02/16/2015
Effort: 6 hours
Purpose: Bits with opaque objects, size and capacity
Interface Proposal: Searching the postion of the bit for an 
easier access
***********************************************************/

#include<stdlib.h>
#include "bitflags.h"

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    Bit_flags* pBit_flags;
    pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    if(pBit_flags != NULL)
    {
        pBit_flags->size = 0;
        pBit_flags->capacity = number_of_bits;
        pBit_flags->data = malloc(sizeof(int) * pBit_flags->capacity);		
        if (pBit_flags->data == NULL)//not good
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
    //(pBit_flags) |= 1 << (flag_position);
    //if there is not enough room then... make it bigger
    if(pBit_flags->size >= pBit_flags->capacity)
    {
	pTemp = (int*)malloc(sizeof(int)*pBit_flags->capacity * 2);
	if (pTemp == NULL)
	{
            return FAILURE;
	}
	else 
	{
            for (i = 0; i < pBit_flags->size; i++)
            {
                pTemp[i] = pBit_flags->data[i];
            }
            free(pBit_flags->data);
            pBit_flags->data = pTemp;
            pBit_flags->capacity *= 2;
	}
    }
    //put the item in.
    pBit_flags->data[pBit_flags->size] = flag_position;
    pBit_flags->size++;
    return SUCCESS;
}
        
Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    if(hBit_flags!=NULL && flag_position>=0)
    {
        //(hBit_flags) &= ~(1 << (flag_position));
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    //Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    if((hBit_flags &&(1 << flag_position))!=0 && flag_position>=0)
    {
        return 0;
    }
    else
        return -1;    
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