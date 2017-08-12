#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
typedef void* STACK;


enum status 
{ 
	FAILURE, SUCCESS 
};
typedef enum status Status;

STACK stack_init_default(void);

//top of the stack
char stack_top(STACK hStack);

//pop back
Status stack_pop_back(STACK hStack);

//push back
Status stack_push_back(STACK hStack, char item);

Status check_order(STACK hStack, FILE* file);

//Destroy the adress
void stack_destroy(STACK* phStack);


struct stack
{
	int size;
	int capacity;
	char* data;
};
typedef struct stack Stack;

STACK stack_init_default(void)
{
	Stack* pStack;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->size = 0;
		pStack->capacity = 1;
		pStack->data = (char*)malloc(sizeof(char)* pStack->capacity);
		if (pStack->data == NULL)
		{
			free(pStack);
			pStack = NULL;
		}
	}
	return pStack;
}

char stack_top(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	if(pStack->data == NULL)
	{
		return FAILURE;
	}
	return pStack->data[pStack->size - 1];
}

Status stack_pop_back(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	if (pStack->size <= 0)
	{
		return FAILURE;
	}
	pStack->size--;
	return SUCCESS;
}

Status stack_push_back(STACK hStack, char item)
{
	Stack* pStack = (Stack*)hStack;
	char* temp;
	int i;

	if (pStack->size >= pStack->capacity)
	{
		temp = (char*)malloc(sizeof(int) * pStack->capacity * 2);
		if (temp == NULL)
		{
			return FAILURE;
		}
		for (i = 0; i < pStack->size; i++)
		{
			temp[i] = pStack->data[i];
		}
		free(pStack->data);
		pStack->data = temp;
		pStack->capacity *= 2;
	}
	pStack->data[pStack->size] = item;
	pStack->size++;
	return SUCCESS;
}

Status check_order(STACK hStack, FILE* file)
{
	Stack* pStack = (Stack*)hStack;
	int check = 0;
	int number = 0;
	char c;
	char* temp;
	int i;
	int count = 0;
	int error = 0;

	check = fscanf(file, " %c", &c);
	printf("%c", c);
	stack_push_back(hStack, c);
	while (c != '\n' && check == 1)
	{
		if (pStack->size >= pStack->capacity)
		{
			temp = (char*)malloc(sizeof(int) * pStack->capacity * 2);
			if (temp == NULL)
			{
				return FAILURE;
			}
			for (i = 0; i < pStack->size; i++)
			{
				temp[i] = pStack->data[i];
			}
			free(pStack->data);
			pStack->data = temp;
			pStack->capacity *= 2;
		}
		check = fscanf(file, "%c", &c);

		printf("%c", c);
		if (c == stack_top(hStack))
		{
			stack_push_back(hStack, c);
			count++;
		}
		else if ((stack_top(hStack) == '(' && c == '{') || (stack_top(hStack) == '(' && c == '['))
		{
			stack_push_back(hStack, c);
			count++;
		}
		else if ((stack_top(hStack) == '{' && c == '(') || (stack_top(hStack) == '{' && c == '['))
		{
			stack_push_back(hStack, c);
			count++;
		}
		else if ((stack_top(hStack) == '[' && c == '(') || (stack_top(hStack) == '[' && c == '{'))
		{
			stack_push_back(hStack, c);
			count++;
		}
		else if ((stack_top(hStack) == '(' && c == ')') || (stack_top(hStack) == '{' && c == '}') || (stack_top(hStack) == '[' && c == ']'))
		{
			stack_pop_back(hStack);
		}
		else if ((stack_top(hStack) == '(' && c == '}') || (stack_top(hStack) == '(' && c == ']'))
		{

			error = 100;
		}
		else if ((stack_top(hStack) == '{' && c == ')') || (stack_top(hStack) == '{' && c == ']'))
		{

			error = 100;
		}
		else if ((stack_top(hStack) == '[' && c == ')') || (stack_top(hStack) == '[' && c == '}'))
		{
			error = 100;
		}
		else if ((stack_top(hStack) != '(') && (stack_top(hStack) != '{') && (stack_top(hStack) != '['))
		{
			stack_push_back(hStack, c);
			count++;
		}
		else if (count % 2 != 0)
		{
			error = 100;
		}
	}
	printf("\n");
	if (error == 100)
	{
		return FAILURE;
	}
	else
	{
		return SUCCESS;
	}

}

void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	free(pStack->data);
	free(pStack);
	*phStack = NULL;
	return;
}