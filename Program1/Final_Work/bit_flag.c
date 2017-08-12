/***********************************************************
	Author: <Wei Ma>
	Date: <10/4/2016>
	Effort: <More than one hour>
	Purpose: <using what we learnt in class to achieve the assignment>
    Interface proposal: <We can add a function that return the decimal number
	that showed as a binary array in my bit_flags struct. Because people usually 
	are familiar with the decimal number not binary number. 
	Function name: bit_flags_decimal_number
	Precondition: hBit_flags is a handle to a valid Bit_flags object.
	Postcondition: return the decimal number that showed in data array.>
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "bit_flag.h"

struct bit_flags
{
	int size;
	int capacity;
	int* data;
};
typedef struct bit_flags Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	int i;
	Bit_flags* pBit_flags;
	pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	if(pBit_flags == NULL)
	{
		free(pBit_flags);
		return NULL;
	}
	pBit_flags->size = number_of_bits;
	pBit_flags->capacity = number_of_bits+1;
	pBit_flags->data = (int*)malloc(sizeof(int)*pBit_flags->capacity);
	if(pBit_flags->data == NULL)
	{
		free(pBit_flags);
		return NULL;
	}
	for(i =0;i <= number_of_bits;i++)
	{
		pBit_flags->data[i] = 0;
	}
	return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	int i;
	int* temp;
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	if(flag_position >= pBit_flags->capacity)
	{
		temp = (int*)malloc(sizeof(int)*pBit_flags->capacity);
		if(temp == NULL)
		{
			printf("failed to malloc!");
			free(temp);
			return FAILURE;
		}
		for(i = 0;i < pBit_flags->capacity;i++)
			temp[i] = pBit_flags->data[i];
		free(pBit_flags->data);
		pBit_flags->capacity = flag_position+1;
		pBit_flags->data = (int*)malloc(sizeof(int)*pBit_flags->capacity);
		if(pBit_flags->data == NULL)
		{
			free(pBit_flags->data);
			return FAILURE;
		}
		for(i = pBit_flags->size; i <flag_position;i++)
			pBit_flags->data[i] = 0;
		for(i = 0;i <=pBit_flags->size;i++)
			pBit_flags->data[i] = temp[i];
		free(temp);
		pBit_flags->size = flag_position;
	}
	pBit_flags->data[flag_position] = 1;
	return SUCCESS;
}

Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	int i;
	int* temp;
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	if(flag_position >= pBit_flags->capacity)
	{
		temp = (int*)malloc(sizeof(int)*pBit_flags->capacity);
		if(temp == NULL)
		{
			printf("failed to malloc!");
			free(temp);
			return FAILURE;
		}
		for(i = 0;i < pBit_flags->capacity;i++)
			temp[i] = pBit_flags->data[i];
		free(pBit_flags->data);
		pBit_flags->capacity = flag_position+1;
		pBit_flags->data = (int*)malloc(sizeof(int)*pBit_flags->capacity);
		if(pBit_flags->data == NULL)
		{
			free(pBit_flags->data);
			return FAILURE;
		}
		for(i = pBit_flags->size; i <flag_position;i++)
			pBit_flags->data[i] = 0;
		for(i = 0;i <=pBit_flags->size;i++)
			pBit_flags->data[i] = temp[i];
		free(temp);
		pBit_flags->size = flag_position;
	}
	pBit_flags->data[flag_position] = 0;
	return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	if(flag_position < 0 || flag_position > pBit_flags->size)
	{
		return -1;
	}
	if(pBit_flags->data[flag_position] == 1)
		return 1;
	if(pBit_flags->data[flag_position] == 0)
		return 0;
}

int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*) hBit_flags;
	return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*) *phBit_flags;
	free(pBit_flags->data);
	free(pBit_flags);
	*phBit_flags = NULL;
}
