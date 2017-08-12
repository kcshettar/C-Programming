#include<stdio.h>
#include<stdlib.h>

int main()
{
   int i,j,count,k=0;
   int **ptr;
   ptr=(int **)malloc(sizeof(int*)*20);
   
	for(i=0; i<20; i++)
    	ptr[i]=(int *)malloc(sizeof(int)*30);
	
	for(i=0; i<20; i++)
	{
	   count=k;
	   for(j=0; j<30 ;j++)
	   {
		ptr[i][j]=count++;
		printf("%d",ptr[i][j]);
		//printf("i = %d ; j = %d\n",i,j);
	   }
	   printf("\n");
	   k++;
	}
return 0;
}
