//
//  DoublyLinkList.c
//  Algorithms
//
//  Created by zhangfeng on 3/22/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "DoublyLinkedList.h"


//initializes a doubly link list
void doublylist_init(DoublyLinkedList *list)
{
    list->count = 0;
    list->head = NULL;
    list->tail = NULL;
    
    return;
}

//destroy a doubly link list
void doublylist_destroy(DoublyLinkedList *list)
{
    while(list->count > 0)
        doublylist_remove(list, NULL);
    
    return;
}


//insert an item with DATA data afert ITEM, if ITEM is not specified, append the new item to the tail of the list
int doublylist_insert(DoublyLinkedList *list, DoublyLinkedListItem *item,void * data)
{
    DoublyLinkedListItem *newItem;
    if((newItem = (DoublyLinkedListItem *)malloc(sizeof(DoublyLinkedListItem)))==NULL)
        return -1;
    
    newItem->data = data;
    newItem->previous = NULL;
    newItem->next = NULL;
    
    //if the list has no item yet, ITEM paremeter will not be considered, just set the head and the tail element and count plus 1
    if(list->count == 0)
    {
        list->head = newItem;
        list->tail = newItem;
        return list->count++;
    }
    
    // if the list has more than one element, ITEM paremeter will be considered
    // if the ITEM parameter is not specified, append the new item to the tail of the list
    if(item == NULL)
    {
        list->tail->next = newItem;
        newItem->previous = list->tail;
        list->tail = newItem;
    }
    else // if the ITEM parameter is specified, insert the new item after the ITEM
    {
        if(item->next != NULL) // make sure the next item of the ITEM is not null
        {
            item->next->previous = newItem;
            newItem->next = item->next->previous;
            newItem->previous = item;
            item->next = newItem;
        }
        else // if the next item of the ITEM is null, it means that the ITEM is tail, process as append to tail
        {
            item->next = newItem;
            newItem->previous = item;
            list->tail = newItem;
        }
    }
    
    return list->count ++;
}

//insert an item with DATA data before ITEM, if ITEM is not specified, insert the new item before the head element
int doublylist_insert_before(DoublyLinkedList *list,DoublyLinkedListItem *item,void * data)
{
    DoublyLinkedListItem *newItem;
    if((newItem = (DoublyLinkedListItem *)malloc(sizeof(DoublyLinkedListItem)))==NULL)
        return -1;
    
    newItem->data = data;
    newItem->previous = NULL;
    newItem->next = NULL;
    
    //if the list has no item yet, ITEM paremeter will not be considered, just set the head and the tail element and count plus 1
    if(list->count == 0)
    {
        list->head = newItem;
        list->tail = newItem;
        return list->count++;
    }
    
    if(item == NULL)
    {
        list->head->previous = newItem;
        newItem->next = list->head;
        list->head = newItem;
    }
    else
    {
        if(item->previous != NULL)
        {
            newItem->previous = item->previous;
            newItem->next = item;
            item->previous->next = newItem;
            item->previous = newItem;
        }
        else
        {
            item->previous = newItem;
            newItem->next = item;
            list->head = newItem;
        }
    }
    
    return list->count ++;
}


//remove the ITEM from the list
int doublylist_remove(DoublyLinkedList *list,DoublyLinkedListItem *item)
{
    if(list->count == 0)
        return -1;
    
    if(list->count == 1)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->count = 0;
        return 0;
    }
    
    //if the ITEM is not specified, remove the tail element
    if(item == NULL)
    {
        list->tail->previous->next = NULL;
        list->tail = list->tail->previous;
    }
    else
    {
        if(item->previous == NULL)
        {
            item->next->previous = NULL;
            list->head = item->next;
        }
        else if(item->next == NULL)
        {
            item->previous->next = NULL;
            list->tail = item->previous;
        }
        else
        {
            item->next->previous = item->previous;
            item->previous->next = item->next;
        }
        
        free(item);
    }
    
    return list->count--;
}

//remove the item before ITEM from the list, and set DATA as the removed item's data
int doublylist_remove_before(DoublyLinkedList *list,DoublyLinkedListItem *item)
{
    if(list->count == 0)
        return -1;
    
    if(list->count == 1)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->count = 0;
        return 0;
    }
    
    //if the ITEM is not specified, remove the head element
    if(item == NULL)
    {
        list->head->next->previous = NULL;
        list->head = list->head->next;
    }
    else
    {
        if(item->previous == NULL)
        {
            item->next->previous = NULL;
            list->head = item->next;
        }
        else if(item->previous->previous == NULL)
        {
            list->head = item;
            item->previous = NULL;
        }
        else
        {
            item->previous->previous->next = item;
            item->previous = item->previous->previous;
        }
    }
    
    return list->count--;
}

//get an item from the LIST as position of INDEX
DoublyLinkedListItem * doublylist_get(DoublyLinkedList *list, int index)
{
	DoublyLinkedListItem *current;

    if(index<0 || index>=list->count)
        return NULL;
    
    current = (index > list->count/2 ? list->tail : list->head);
    
    if(current == list->head)
    {
        while(index-- > 0)
            current = current->next;
    }
    else
    {
        while(index++ < list->count - 1)
            current = current->previous;
    }
    
    return current;
}

void doublylist_print(DoublyLinkedList *list)
{
    if(list->count == 0)
    {
        printf("the doubly link list is empty!\n");
    }
    else
    {
        DoublyLinkedListItem *current = list->head;
        while(current!=NULL)
        {
            printf("%d\n",*((int *)(current->data)));
            current = current->next;
        }
    }
    
    printf("print doubly link list finished.\n");
    
    return;
}
