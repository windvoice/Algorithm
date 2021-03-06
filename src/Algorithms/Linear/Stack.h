//
//  Stack.h
//  Algorithms
//
//  Created by zhangfeng on 3/27/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef Algorithms_Stack_h
#define Algorithms_Stack_h

#include <stdlib.h>
#include "../LinkedList/SingleLinkedList.h"

typedef SingleLinkedList Stack;

//initialize a stack
void stack_init(Stack *stack);

//pop the top element on the stack
void* stack_pop(Stack *stack);

//push an element into stack
void stack_push(Stack *stack, void* data);

//destroy the stack
void stack_destroy(Stack *stack);

#endif