//
//  StackTest.c
//  Algorithms
//
//  Created by zhangfeng on 3/2/13.
//
//

#include <stdio.h>
#include "StackTest.h"
#include "../../Linear/Stack.h"

int stack_test()
{
    int a[6] = {36,76,23,90,21,25};
	int i=0;

    Stack *stack;
    if((stack = (Stack *)malloc(sizeof(stack)))==NULL)
        return  -1;    
    
    stack_init(stack);
    
    printf("stack push:");
    for(i=0;i<6;i++)
    {
        stack_push(stack,&a[i]);
        printf("%d,",a[i]);
    }
    printf("\n");
    
    printf("stack pop: %d\n",*(int *)stack_pop(stack));
    printf("stack pop: %d\n",*(int *)stack_pop(stack));
    printf("stack pop: %d\n",*(int *)stack_pop(stack));
    printf("stack pop: %d\n",*(int *)stack_pop(stack));
    printf("stack pop: %d\n",*(int *)stack_pop(stack));
    printf("stack pop: %d\n",*(int *)stack_pop(stack));
    
    return 0;
}