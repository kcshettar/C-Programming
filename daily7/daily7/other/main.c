/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kcshe
 *
 * Created on February 26, 2016, 11:41 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

typedef int Boolean;
#define true 1
#define false 0

enum status 
{ 
    FAILURE, SUCCESS
};

typedef enum status Status;

struct node;
typedef struct node Node;
typedef Node* Node_ptr;

struct node
{
	int data;
	Node* next;
};


typedef void* STACK;
struct stack
{
	//Public
	Status(*push)(STACK hStack, int item);
	Status(*pop)(STACK hStack);
	int(*top)(STACK hStack, Status* pStatus_code);
	Boolean(*empty)(STACK hStack);
	void(*destroy)(STACK* phStack);

	//Private
	Node* head;
};

typedef struct stack Stack;


Status stack_push(STACK hStack, int item);
Status stack_pop(STACK hStack);
int stack_top(STACK hStack, Status* pStatus_code);
Boolean stack_empty(STACK hStack);
void stack_destroy(STACK* phStack);


STACK stack_init_default(void)
{
	Stack* pStack;

	pStack = (Stack*) malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->push = stack_push;
		pStack->pop = stack_pop;
		pStack->top = stack_top;
		pStack->empty = stack_empty;
		pStack->destroy = stack_destroy;
		pStack->head = NULL;
	}
	return (STACK) pStack;
}

Status stack_push(STACK hStack, int item)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;

	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}
	temp->data = item;
	temp->next = pStack->head;

	pStack->head = temp;

	return SUCCESS;
}

Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	if (pStack->head == NULL)
	{
		return FAILURE;
	}
	
	pStack->head = pStack->head->next; // ??
}

int stack_top(STACK hStack, Status* pStatus_code)
{
	Stack* pStack = (Stack*)hStack;

	if (pStack->head == NULL)
	{
		*pStatus_code = FAILURE;
		return -213423;
	}
	*pStatus_code = SUCCESS;
	return pStack->head->data;
}

Boolean stack_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	return (Boolean) (pStack->head == NULL);
}

void stack_destroy(STACK* phStack)
{
	return;
}

int main(int argc, char* arv[])
{
	STACK hStack = NULL;
	Status status;

        int item;
	hStack = stack_init_default();
	
        //if(hStack->stack_empty(hStack))
        if(hStack == NULL)
	{
		printf("Stack is empty\n");
	}
	
        //pStack->push = stack_push;
        //printf("enter the item");
        //scanf("%d", &item);
        
        //stack_push(hStack, item);
        /*
        //stack_push(hStack, 100);
	printf("The top of the stack is: %d\n", stack_top(hStack, &status));
	if (stack_empty(hStack))
	{
		printf("Stack is empty\n");
	}
	stack_pop(hStack);
	if(stack_empty(hStack))
	{
		printf("Stack is empty\n");
	}

	stack_destroy(&hStack);
        */
         return 0;
}
