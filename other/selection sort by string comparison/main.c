/**********************************************************************
Program:	<Selection sort>
Author:	<Jinhong Cui>
Date:		<10/28/2016>
Time spent:	<180minutes>
Purpose:   	Implement the selection sort algorithm using a linked list.
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linkedListSt.h"



int main(void)
{
	pLinkedList list = linkedlistInitDefault();
	linkedlistScanInit(list);
	printf("before selection sort:\n");
	linkedlistShow(list);
	linkedlistSelectionSort(list);
	printf("after selection sort:\n");
	linkedlistShow(list);
	linkedlistDestroy(&list);
	return 0;
}
