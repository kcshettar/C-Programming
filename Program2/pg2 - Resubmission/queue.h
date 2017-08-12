#ifndef queue_h
#define queue_h
#include "status.h"

struct public_queue;
typedef struct public_queue Public_queue;
typedef Public_queue* QUEUE;

struct public_queue
{
    Status(*enqueue)(QUEUE hQueue, int item);
    Status(*service)(QUEUE hQueue);
    Boolean(*empty)(QUEUE hQueue);
    int(*front)(QUEUE hQueue, Status* pStatus);
    void(*destroy)(QUEUE* phQueue);
    void(*print)(QUEUE hQueue);
};

QUEUE queue_init_default(void);
Status queue_enqueue(QUEUE hQueue, int item);
Status queue_service(QUEUE hQueue);
Boolean queue_empty(QUEUE hQueue);
int queue_front(QUEUE hQueue, Status* pStatus);
void queue_destroy(QUEUE* phQueue);
void queue_print(QUEUE hQueue);

#endif
