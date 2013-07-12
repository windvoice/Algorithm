//
//  Stack.c
//  Algorithms
//
//  Created by zhangfeng on 3/27/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

//initialize a stack
void stack_init(Stack *stack)
{
    stack->head = NULL;
    stack->count = 0;
}

//pop the top element on the stack
void* stack_pop(Stack *stack)
{
    void *data = stack->count==0?NULL:stack->head->data;
    
    singlelist_remove(stack, NULL);
    
    return data;
}

//push an element into stack
void stack_push(Stack *stack, void* data)
{
    singlelist_insert(stack, NULL, data);
}

//destroy the stack
void stack_destroy(Stack *stack)
{
    singlelist_destroy(stack);
}