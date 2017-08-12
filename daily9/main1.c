/*************************************************************************
Program: QUICK SORT
Author: KIRAN C SHETTAR
Date: 04/07/2016
Time spent: 06 hours
Purpose: The purpose of this program is to implement quick sort, swapping 
the elements, and the partitioning
**************************************************************************/

#include<stdio.h>

int partition(int a[], int low, int high);
void swap(int a[], int left, int right);
void quicksort(int a[], int low, int high);

int main(int argc, char* argv[])
{
 	int a[50], i, n;
	/*Works for all the test cases:
	1. Sorted order - Ascending
 	2. Sorted order - Descending
	3. Unsorted array - Random inputs
	*/
 	printf("\nEnter number of elements to sort -> "); 
 	//How many elements to sort?
 	scanf("%d", &n);

 	printf("\nEnter the elements to sort:\n");
 	//Elements to sort
 	for(i=0; i<n; i++)
  	scanf ("%d", &a[i]);

 	printf("\nYou have entered the following elements to sort:\n");
 	for(i=0; i<n; i++)
  	printf("%d\t", a[i]);
 	printf("\n");
 	printf("\n");
 	printf("Calling quicksort");
 	quicksort(a,0,n-1);

 	printf("\nThe sorted elements in the array using quicksort is:\n");
 	for(i=0; i<n; i++)
  	printf("%d\t", a[i]);
 	printf("\n");
 	return 0;
}

void swap(int a[], int left, int right)
{
	//Swap the elements here
	int temp;
 	temp = a[left];
 	a[left] = a[right];
 	a[right] = temp; 
}
 
void quicksort(int a[], int low, int high)
{
 	//int pivot;
 	//Termination condition..!! 
 	if(high > low)
 	{
 		//pivot is the index of the element where pivot is present
  		int pivot = partition(a, low, high);
  		quicksort(a, low, pivot-1);
  		quicksort(a, pivot+1, high);
 	}
}

int partition(int a[], int low, int high)
{
 	int left, right;
 	int pivot_item;
 	//We assume that the first element in the array is the pivot
 	int pivot = left = low;
 	pivot_item = a[low];
 	right = high;
 	while(left < right) 
 	{
  		//When the left item is less than pivot increment the pointer left 
  		while(a[left] <= pivot_item) 
   		left++;
   		//When the right item is greater than pivot decrement the pointer right
  		while(a[right] > pivot_item) 
   		right--;

   		//swap condition
  		if(left < right) 
   		swap(a,left,right);
 	}
 	//Final position of the pivot is right
 	a[low] = a[right];
 	a[right] = pivot_item;
 	return right;
}