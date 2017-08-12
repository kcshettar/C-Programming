/**********************************************************************
Program: Ferry Loading
Author: Kiran C Shettar
Date: 3/20/2016
Time spent: 12 hours
Purpose: Loading and Unloading cars in a single lane ferry across a river
***********************************************************************/

#include "queue.h"
#include "status.h"

int main(int argc, const char * argv[]) 
{
    int count;
    scanf("%d",&count);
    int i;
    for (i = 0; i < count; i++) 
    {
        int f_length;
        int num_cars;
        scanf("%d %d",&f_length,&num_cars);
        f_length *= 100;
        printf("Length of the ferry is = %d Total number of cars = %d\n",f_length,num_cars);

       	int j = 0;
        QUEUE hRightQueue = NULL;
        QUEUE hLeftQueue = NULL;
        hRightQueue = queue_init_default();
        hLeftQueue = queue_init_default();
        
        int STRING_SIZE = 20;
        int car_length;
        char line[STRING_SIZE];
        fgetc(stdin);
        
        while (j<num_cars && fgets(line, STRING_SIZE, stdin) != NULL) 
        {
            printf("%s",line);
            char* string_car_length = strtok(line, " ");
            char* string_car_position = strtok(NULL,"\n");
            car_length = (int)strtol(string_car_length, NULL, 10);
            if (!strcmp(string_car_position, "left")) 
            {
                hLeftQueue->enqueue(hLeftQueue,car_length);
            }
            else if (!strcmp(string_car_position, "right"))
            {
                hRightQueue->enqueue(hRightQueue,car_length);
           }
            j++;
        }
        printf("\n");
        printf("Left queue:");hLeftQueue->print(hLeftQueue);
        printf("Right queue:");hRightQueue->print(hRightQueue);
        hLeftQueue->destroy(&hLeftQueue);
        hRightQueue->destroy(&hRightQueue);

    }
    return 0;
}
