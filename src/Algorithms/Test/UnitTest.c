//
//  Test.c
//  Algorithms
//
//  Created by zhangfeng on 3/2/13.
//
//

#include "UnitTest.h"
#include "Linear/StackTest.h"
#include "Linear/QueueTest.h"


int runTest(){
    printf("unit test begin..\n");
    _test_run();
    printf("unit test end\n");
    return 0;
}

void _test_run(){
    stack_test();
    queue_test();
}