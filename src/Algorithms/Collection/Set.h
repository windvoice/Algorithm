//
//  Set.h
//  Algorithms
//
//  Created by zhangfeng on 4/4/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef Algorithms_CircularLinkedList_h
#define Algorithms_CircularLinkedList_h

#include <stdlib.h>
#include "SingleLinkedList.h"

typedef SingleLinkedList Set;

//initialize SET, set its match function
void set_init(Set *set, int (* match) (const void *key1,const void *key2));

//insert DATA into SET
int set_insert(Set *set, const void *data);

//remove the DATA element from the specified SET
int set_remove(Set *set, void **data);

//get the RESULT of union operation of SET1 and SET2
int set_union(Set *result, Set *set1, Set *set2);

//get the RESULT of intersection operation of SET1 and SET2
int set_intersection(Set *result, Set *set1, Set *set2);

//get the RESULT of difference operation of SET1 and SET2
int set_difference(Set *result, Set *set1,Set *set2);

//decide whether the specified DATA is a member of SET
int set_ismember(Set *set, const void *data);

//decide whether SET1 is a subset of SET2
int set_issubset(const Set *set1,const Set *set2);

//decide whether SET1 equals SET2
int set_isequal(const Set *set1, const Set *set2);

//define marco of destroy method of a set
#define set_destroy list_destroy

//define marco of size of the SET
#define set_size(set) ((set)->size)

#endif