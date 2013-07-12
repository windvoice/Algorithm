//
//  Queue.h
//  Algorithms
//
//  Created by zhangfeng on 3/27/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef Algorithms_Queue_h
#define Algorithms_Queue_h

#include <stdlib.h>
#include "SingleLinkedList.h"

typedef SingleLinkedList Queue;

//initialize a queue
void queue_init(Queue *queue);

//destroies a queue
void queue_destroy(Queue *queue);

//queue a data item
void queue_enqueue(Queue *queue, void* data);

//remove and return the first item of the queue
void* queue_dequeue(Queue *queue);

#endif