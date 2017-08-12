#include <stdlib.h>
#include "bit_flags.h"

struct bit_flags
{
	int size; //number of bits held
	int capacity;//number of bits that can be held
	int* data;
};

typedef struct bit_flags Bit_flags;


BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
	Bit_flags* pBit_flags;
	int number_of_ints;

	pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
	if (pBit_flags != NULL)
	{
		number_of_ints = (number_of_bits/(sizeof(int) * 8)) + 1;
		pBit_flags->data = (int*)calloc(number_of_ints, sizeof(int));
		if (pBit_flags == NULL)
		{
			free(pBit_flags);
			pBit_flags = NULL;
		}
		else
		{
			pBit_flags->size = number_of_bits;
			pBit_flags->capacity = number_of_ints * sizeof(int) * 8;
		}
	}
	return pBit_flags;
}

Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index;
	int position;
	int* temp;
	int i;
	int number_of_elements;
	unsigned int marker = 1;

	//determine the index
	index = flag_position / (sizeof(int) * 8);
	//find out if the index is in bounds and fix if needed
	if (flag_position >= pBit_flags->size) //out of bounds so size needs to change
	{
		if (flag_position >= pBit_flags->capacity) //needs a resize
		{
			temp = (int*)malloc(sizeof(int) * (index + 1));
			if (temp == NULL)
			{
				return FAILURE;
			}
			number_of_elements = (pBit_flags->size / (sizeof(int) * 8)) + 1;
			for (i = 0; i < number_of_elements; i++)
			{
				temp[i] = pBit_flags->data[i];
			}
			free(pBit_flags->data);
			pBit_flags->data = temp;
			pBit_flags->capacity = (index + 1) * (sizeof(int) * 8);
		}
		pBit_flags->size = flag_position + 1;
	}
	position = flag_position % (sizeof(int) * 8);
	//set flag
	marker <<= position;
	pBit_flags->data[index] |= marker;

	return SUCCESS;
}


Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index;
	int position;
	int* temp;
	int i;
	int number_of_elements;
	unsigned int marker = 1;

	//determine the index
	index = flag_position / (sizeof(int) * 8);
	//find out if the index is in bounds and fix if needed
	if (flag_position >= pBit_flags->size) //out of bounds so size needs to change
	{
		if (flag_position >= pBit_flags->capacity) //needs a resize
		{
			temp = (int*)malloc(sizeof(int) * (index + 1));
			if (temp == NULL)
			{
				return FAILURE;
			}
			number_of_elements = (pBit_flags->size / (sizeof(int) * 8)) + 1;
			for (i = 0; i < number_of_elements; i++)
			{
				temp[i] = pBit_flags->data[i];
			}
			free(pBit_flags->data);
			pBit_flags->data = temp;
			pBit_flags->capacity = (index + 1) * (sizeof(int) * 8);
		}
		pBit_flags->size = flag_position + 1;
	}
	position = flag_position % (sizeof(int) * 8);
	//set flag
	marker <<= position;
	marker = ~marker;
	pBit_flags->data[index] &= marker;

	return SUCCESS;
}


int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
	int index;
	int position;

	//find out if the index is out of bounds
	if (flag_position >= pBit_flags->size) //out of bounds
	{
		return -1;
	}
	//determine the index
	index = flag_position / (sizeof(int) * 8);
	position = flag_position % (sizeof(int) * 8);

	return (pBit_flags->data[index] >> position) & 1;	
}


int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

	return pBit_flags->size;
}


int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

	return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{
	Bit_flags* pBit_flags = (Bit_flags*)*phBit_flags;

	free(pBit_flags->data);
	free(pBit_flags);

	*phBit_flags = NULL;
	return;
}