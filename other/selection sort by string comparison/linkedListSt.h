typedef struct node Node, *pNode;
#include "item.h"

struct node
{
	Item item;
	pNode next;
};

struct linkedlist
{
	pNode front;
	int size;
	pNode iterator;
	//Could add here any other thing we need                                      
};

typedef struct linkedlist LinkedList, *pLinkedList;

pLinkedList linkedlistInitDefault();
int linkedlistGetSize(pLinkedList list);
void linkedlistAddNodeBack(pLinkedList list, Item item);
void linkedlistDestroy(pLinkedList *list);
void linkedlistScanInit(pLinkedList list);
void linkedlistShow(pLinkedList list);
void linkedlistSelectionSort(pLinkedList list);
