/***********************************************************
Author: Kiran Shettar
Date: 01/28/2016
Effort: Almost 3 hours
Purpose: To understand the bit operations in C language
//Use of Bit wise operators '&', '|', '<<' 
***********************************************************/
#include <stdio.h>

void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
   int flag_holder = 0;
   int i;
   set_flag(&flag_holder, 3);
   set_flag(&flag_holder, 16);
   set_flag(&flag_holder, 31);

   for(i=31; i>=0; i--)
   {
	printf("%d", check_flag(flag_holder, i));
	if(i%4 == 0)
	{
	   printf("%d", i);
	}
   }
	   printf("\n");
return 0;
}

void set_flag(int* flag_holder, int flag_position)
{
   int value;
   (*flag_holder) = value;
   value |= 1 << (flag_position);
}


int check_flag(int flag_holder, int flag_position)
{
   if((flag_holder &(1 << flag_position))!=0)
   {
	return 1;
   }
   else
   return 0;
}

