//
//  CircleLinkList.c
//  Algorithms
//
//  Created by zhangfeng on 3/22/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "CircularLinkedList.h"



void circularlist_init(CircularLinkedList *list)
{
    list->count = 0;
    list->head = NULL;
    
    return;
}

void circularlist_destroy(CircularLinkedList *list)
{
    while(list->count>0)
        circularlist_remove(list, NULL);
    
    return;
}

int circularlist_insert(CircularLinkedList *list, CircularLinkedListItem *item, void *data)
{
    CircularLinkedListItem *newItem;
    if((newItem = (CircularLinkedListItem *)malloc(sizeof(CircularLinkedListItem))) == NULL)
        return -1;
    
    newItem->data = data;
    
    if(list->count == 0)
    {
        list->head = newItem;
        newItem->next = newItem;
        return list->count++;
    }
    
    if(item == NULL)
    {
        //find the tail
        CircularLinkedListItem *tail = list->head->next;
        while(tail->next != list->head)
            tail = tail->next;
        
        tail->next = newItem;
        newItem->next = list->head;
    }
    else
    {
        if(item->next == list->head)
            list->head = newItem;
        
        newItem->next = item->next;
        item->next = newItem;
    }
    
    return list->count++;
}

int circularlist_remove(CircularLinkedList *list,CircularLinkedListItem *item)
{
    CircularLinkedListItem *oldItem;
    
    if(list->count == 0)
        return -1;
    
    if(list->count == 1)
    {
        oldItem = list->head;
        list->head = NULL;
        list->count = 0;
        
        return 0;
    }
    
    if(item == NULL)
    {
        oldItem = list->head->next;
        item = list->head;
        while(oldItem->next != list->head)
        {
            oldItem = oldItem->next;
            item = item->next;
        }
        
        item->next = oldItem->next;
    }
    else
    {
        oldItem = item->next;
        item->next = oldItem->next;
    }
    
    free(oldItem);
    return list->count--;
}


CircularLinkedListItem * circularlist_get(CircularLinkedList *list, int index)
{
    CircularLinkedListItem *current = list->head;
    while(index>0)
    {
        current = current->next;
        index--;
    }
    
    return current;
}

void circularlist_print(CircularLinkedList *list)
{
	CircularLinkedListItem *current;

    if(list->count==0 || list->head==NULL)
        printf("the list is empty!\n");
    else
    {
        printf("%d\n",*((int *)(list->head->data)));
        current = list->head->next;
        
        while(current!=list->head)
        {
            printf("%d\n",*((int *)(current->data)));
            current = current->next;
        }
    }
    printf("^ that is all items in this list!\n");
}