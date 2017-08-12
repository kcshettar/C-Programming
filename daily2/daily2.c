/**********************************************************
Author: Kiran C Shettar
Date: 01/24/2016
Effort: An hour
Puropse: To understand the operation of left 
shift binary operator using a for loop for incrementation
**********************************************************/
#include<stdio.h>

int main()
{
//declaration of unsigned integer 'x' and initialising it to 1
	unsigned int x = 1;
//declaration of other variables
	int i = 0;
	int j = 0;
//for loop that prints out iteration number starting 
//from zero, a colon, and the value of 'x' on a single line
	for(i = 0; i < 32; i++)
	{
		if(x == 0)
		{
			printf("Loop Exited as the value of x is zero");
			return 0;
		}
		else
		{
			//use of left shift operator
			//to shift the value of 'x' 
			//by 1 bit to left 
			printf("%d: %u\n", i, x << j);
			j++;
		}
	}
return (0);
}
