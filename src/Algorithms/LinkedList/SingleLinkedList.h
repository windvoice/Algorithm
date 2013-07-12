//
//  LinkList.h
//  Algorithms
//
//  Created by zhangfeng on 3/16/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef Algorithms_SingleLinkedList_h
#define Algorithms_SingleLinkedList_h

#include <stdlib.h>

//definetion of linked list item
typedef struct _SingleLinkedListItem
{
    void *data;
    struct _SingleLinkedListItem *next;
} SingleLinkedListItem;

//definetion of linked list itself
typedef struct _SingleLinkedList
{
    int count;
    SingleLinkedListItem *head;
    int (*match)(const void *key1, const void *key2);
} SingleLinkedList;

//initialize a link list
void singlelist_init(SingleLinkedList *list);

//insert the DATA after the provided ITEM
int singlelist_insert(SingleLinkedList *list, SingleLinkedListItem *item, const void *data);

//remove the provided ITEM
int singlelist_remove(SingleLinkedList *list, SingleLinkedListItem *item);

//get the item at INDEX position of the list
SingleLinkedListItem *singlelist_get(SingleLinkedList *list,int index);

//get the length of the list
int singlelist_count(SingleLinkedList *list);

//destroy the linked list
void singlelist_destroy(SingleLinkedList *list);

void singlelist_print();

#endif