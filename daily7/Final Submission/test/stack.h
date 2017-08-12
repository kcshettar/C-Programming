#include<stdio.h>
#include "status.h"

typedef void* STACK;

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
