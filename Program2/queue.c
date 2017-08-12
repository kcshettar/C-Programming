#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node Node;

struct node
{
    int data;
    Node* next;
    Node* prev;
};

struct queue
{
    int front;
    int back;
    int size;
    
    Node* head;
    Node* tail;
};
typedef struct queue Queue;

//init
QUEUE queue_init_default(void)
{
    Queue* pQueue = NULL;
    
    pQueue = (Queue*) malloc(sizeof(Queue));
    if (pQueue != NULL)
    {
		pQueue->front = 0; //queue is empty
		pQueue->back = 0; //location of next item
        pQueue->size = 0;
        pQueue->head = NULL;
        pQueue->tail = NULL;
    }
    return pQueue;
}

//enqueue
Status queue_enqueue(QUEUE hQueue, int item)
{
    Queue* pQueue = (Queue*) hQueue;
    Node* temp;
    
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        return FAILURE;
    }
    temp->data = item;
    temp->prev = pQueue->tail;
    temp->next = pQueue->head;
    
    pQueue->tail = pQueue->head;
    pQueue->head = temp;
    pQueue->size++;
    
    return SUCCESS;
}

//service
Status queue_service(QUEUE hQueue) //pop_front
{
    Queue* pQueue = (Queue*) hQueue;
    Node* temp;
    
    if(pQueue->head == NULL)
    {
        return FAILURE;
    }
    temp = pQueue->head;
    pQueue->head = pQueue->head->next;
    free(temp);
    pQueue->size --;
    return SUCCESS;
}

//empty
Boolean queue_empty(QUEUE hQueue)
{
    Queue* pQueue = (Queue*) hQueue;
    pQueue->size = 0;
    return (Boolean)(pQueue->head == NULL);
}

//front
int queue_front(QUEUE hQueue, Status* pStatus_code)
{
    Queue* pQueue = (Queue*) hQueue;
    if (pQueue->head == NULL) //Queue is empty
    {
        if (pStatus_code != NULL)
        {
            *pStatus_code = FAILURE;
        }
        
        return -3434234;
    }
    
    if (pStatus_code != NULL)
    {
        *pStatus_code = SUCCESS;
    }
    
    return pQueue->head->data;
}

int queue_get_size(QUEUE hQueue)
{
    Queue* pQueue = (Queue*) hQueue;
    return pQueue->size;
    
}

//destroy
void queue_destroy(QUEUE* phQueue)
{
    Queue* pQueue = (Queue*) *phQueue;
    Node* temp;
    
    temp = pQueue->head;
    while (temp != NULL)
    {
        pQueue->head = pQueue->head->next;
        free(temp);
        temp = pQueue->head;
    }
    
    free(pQueue);
    *phQueue = NULL;
    return;
}