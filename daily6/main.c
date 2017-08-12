/**********************************************************************
Program: Reversing the LinkedList
Author: Kiran C Shettar
Date: 02/19/2016
Time spent: 1 hour
Purpose: The purpose of this program is to reverse a given linked list
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
    int data;
    Node* next;
};

//declare your function here.
Node* reverse(Node* head); 

int main(int argc, char* argv[])
{
    Node* head = NULL;
    int i;
    Node* temp;
    
    //set up a test list with values 9->8->7->...->0
    for (i = 0; i < 10; i++)
    {
    	temp = (Node*)malloc(sizeof(Node));
    	if (temp == NULL)
    	{
            printf("out of memory?\n");
            exit(1);
	}
	temp->data = i;
	temp->next = head;
	head = temp;
    }

    //call your function to reverse the list (should work for any list given the head node).
    head = reverse(head);

    //print the reversed list.
    temp = head;
    while (temp != NULL)
    {
    	printf("%d\n", temp->data);
    	temp = temp->next;
    }
    return 0;
}

//Define your function here
Node* reverse(Node* head) 
{
    Node* new_head = NULL;//creating a local head
    while (head)
    {
        //swapping the values here
        Node* next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}