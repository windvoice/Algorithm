//
//  Queue.c
//  Algorithms
//
//  Created by zhangfeng on 3/27/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"



void queue_init(Queue *queue)
{
    queue->count = 0;
    queue->head = NULL;
}

void queue_destroy(Queue *queue)
{
    singlelist_destroy(queue);
}

void queue_enqueue(Queue *queue, void* data)
{
    singlelist_insert(queue, NULL, data);
}

void* queue_dequeue(Queue *queue)
{
    SingleLinkedListItem * tail = queue->head;
    int count = queue->count-2;
    
    while(tail!=NULL && count>0)
    {
        tail = tail->next;
        count--;
    }
    
    
    return tail==NULL?NULL:tail->data;
}