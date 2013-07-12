//
//  DoublyLinkList.h
//  Algorithms
//
//  Created by zhangfeng on 3/22/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef Algorithms_DoublyLinkedList_h
#define Algorithms_DoublyLinkedList_h

#include <stdlib.h>

//definition of doubly link list item
typedef struct _DoublyLinkedListItem
{
    void * data;
    struct _DoublyLinkedListItem *previous;
    struct _DoublyLinkedListItem *next;
} DoublyLinkedListItem;

//definition of doubly link list, be aware that doubly link list must have the element tail to make it possible to go through the list 
//from the end to the head
//if a list has just one element, its head is also its tail. 
//the only element's previous property points to NULL and next points to NULL
typedef struct _DoublyLinkedList
{
    int count;
    DoublyLinkedListItem *head;
    DoublyLinkedListItem *tail;
} DoublyLinkedList;

//initializes a doubly link list
void doublylist_init(DoublyLinkedList *list);

//destroy a doubly link list
void doublylist_destroy(DoublyLinkedList *list);

//insert an item with DATA data afert ITEM, if <parameter>ITEM</paremeter> is not specified, append the new item to the tail of the list
int doublylist_insert(DoublyLinkedList *list,DoublyLinkedListItem *item,void * data);

//insert an item with DATA data before ITEM, if ITEM is not specified, insert the new item before the head element
int doublylist_insert_before(DoublyLinkedList *list,DoublyLinkedListItem *item,void * data);

//remove the ITEM from the list
int doublylist_remove(DoublyLinkedList *list,DoublyLinkedListItem *item);

//remove the item before ITEM from the list, and set DATA as the removed item's data
int doublylist_remove_before(DoublyLinkedList *list,DoublyLinkedListItem *item);

//get an item from the LIST as position of INDEX
DoublyLinkedListItem * doublylinklist_get(DoublyLinkedList *list, int index);

void doublylist_print(DoublyLinkedList *list);

#endif