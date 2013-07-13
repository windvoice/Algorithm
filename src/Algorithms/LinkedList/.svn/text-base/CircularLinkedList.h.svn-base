//
//  CircleLinkList.h
//  Algorithms
//
//  Created by zhangfeng on 3/22/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef Algorithms_CircularLinkedList_h
#define Algorithms_CircularLinkedList_h

#include <stdlib.h>

typedef struct _CircularLinkedListItem
{
    void * data;
    struct _CircularLinkedListItem * next;
} CircularLinkedListItem;

typedef struct _CircularLinkedList
{
    int count;
    CircularLinkedListItem *head;
} CircularLinkedList;


void circularlist_init(CircularLinkedList *list);

void circularlist_destroy(CircularLinkedList *list);

//insert the data afert ITEM, if the element after ITEM is the head element, reset the head
int circularlist_insert(CircularLinkedList *list,CircularLinkedListItem *item, void *data);

//remove the element after ITEM, if the element after ITEM is the head element, reset the head
int circularlist_remove(CircularLinkedList *list,CircularLinkedListItem *item);

CircularLinkedListItem *circularlist_get(CircularLinkedList *list, int index);

void circularlist_print(CircularLinkedList *list);

#endif
