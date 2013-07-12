//
//  QueueTest.c
//  Algorithms
//
//  Created by zhangfeng on 3/2/13.
//
//

#include <stdio.h>
#include "QueueTest.h"
#include "../../Linear/Queue.h"


int queue_test()
{
    Queue *queue;
    if((queue = (Queue *)malloc(sizeof(Queue)))==NULL)
        return -1;
    
    queue_init(queue);
    
    int a[6] = {36,76,23,90,21,25};
    
    printf("queue line up:");
    for(int i=0;i<6;i++)
    {
        queue_enqueue(queue, &a[i]);
        printf("%d,",a[i]);
    }
    printf("\n");
    
    printf("queue out: %d\n",*(int *)queue_dequeue(queue));
    printf("queue out: %d\n",*(int *)queue_dequeue(queue));
    printf("queue out: %d\n",*(int *)queue_dequeue(queue));
    printf("queue out: %d\n",*(int *)queue_dequeue(queue));
    printf("queue out: %d\n",*(int *)queue_dequeue(queue));
    printf("queue out: %d\n",*(int *)queue_dequeue(queue));
    
    return 0;
}