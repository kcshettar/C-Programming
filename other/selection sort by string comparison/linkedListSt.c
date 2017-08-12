#include <stdio.h>
#include <stdlib.h>
#include "linkedListSt.h"

pLinkedList linkedlistInitDefault()
{
	pLinkedList list = malloc(sizeof(LinkedList));
	list->front = NULL;
	list->iterator = NULL;
	list->size = 0;
	return list;
}

int linkedlistGetSize(pLinkedList list)
{
	return list->size;
}

void linkedlistAddNodeBack(pLinkedList list, Item item)
{
	if (list->front == NULL)
	{
		list->front = malloc(sizeof(Node));
		if (list->front != NULL)
		{
			list->front->next = NULL;
			list->front->item = item;
			list->size++;
		}
	}
	else
	{
		pNode current = list->front;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = malloc(sizeof(Node));
		if (current->next != NULL)
		{
			current->next->item = item;
			current->next->next = NULL;
			list->size++;
		}

	}

}


void linkedlistDestroy(pLinkedList *list)
{
	if ((*list) != NULL)
	{
		printf("list is not null\n");
		if ((*list)->front == NULL)
		{
			free((*list));
			(*list) = NULL;
		}
		else
		{
			printf("looping to delete all nodes\n");
			pNode current = (*list)->front;
			pNode next = (*list)->front;
			while (current != NULL)
			{
				printf("I am deleting here\n");
				next = current->next;
				free(current->item);//malloc item
				free(current);
				current = next;
			}
			printf("setting the list to null\n");
			free((*list));
			(*list) = NULL;
		}

	}

}


void linkedlistScanInit(pLinkedList list)
{
	int n;
	int i;
	Item tmp;
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		tmp = malloc(sizeof(char)*128);
		scanf("%s", tmp);
		linkedlistAddNodeBack(list, tmp);
		

	}

}

void linkedlistShow(pLinkedList list)
{
	pNode temp;
	temp = list->front;
	while (temp != NULL)
	{
		printf("%s\n", temp->item);
		temp = temp->next;
	}
}

void linkedlistSelectionSort(pLinkedList list)
{
	pNode head = list->front;
	pNode j;
	pNode k;
    Item tmp;
	for (j = head; j != NULL && j->next != NULL; j = j->next)
	{
		pNode min;
		min = j;
		for (k = j->next; k != NULL; k = k->next)
		{
			if (less(k->item,min->item) == -1)
				min = k;
		}
		if (min != j)
		{
			tmp = min->item;
			min->item = j->item;
			j->item = tmp;
		}
	}
	list->front = head;
}

int less(Item str1, Item str2)
{
	//str1 = malloc(sizeof(char) * 128);
	//str2 = malloc(sizeof(char) * 128);
	int i;

	for (i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		if (str1[i] < str2[i])
		{
			return -1;
		}
		else if (str1[i] > str2[i])
			return 1;
	}

	if ((str1[i] == '\0') && (str2[i] != '\0'))
	{
		return -1;
	}
	else if ((str1[i] != '\0') && (str2[i] == '\0'))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}