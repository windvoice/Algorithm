//
//  LinkList.c
//  Algorithms
//
//  Created by zhangfeng on 3/16/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"


//initialize a list
void singlelist_init(SingleLinkedList *list)
{
    list->count = 0;
    list->head = NULL;
    return;
}

//insert the DATA after the provided ITEM
int singlelist_insert(SingleLinkedList *list, SingleLinkedListItem *item, const void *data)
{
    SingleLinkedListItem *newItem;
    if((newItem = (SingleLinkedListItem*)malloc(sizeof(SingleLinkedListItem))) == NULL)
        return -1;
    
    newItem->data = data;
    newItem->next = NULL;
    
    //if the ITEM is not provided, insert the data to the head of the list 
    if(item == NULL)
    {
        newItem->next = list->head;
        list->head = newItem;
    }
    else//if the ITEM is provided, put the data after the ITEM and set the data's next item as the previously ITEM's next item
    {
        SingleLinkedListItem *temp = item->next;
        item->next = newItem;
        newItem->next = temp;
        free(temp);
    }
    
    return ++list->count;
}

int singlelist_remove(SingleLinkedList *list, SingleLinkedListItem *item)
{
    //if the list is empty, just return
    if(list->count<=0)
        return  0;
    
    SingleLinkedListItem *oldItem;
    
    //if the item is not specified, remove the first element
    if(item == NULL)
    {
        oldItem = list->head;
        list->head = list->head->next;
    }
    else //if the item is specified, remove the next item. as a result, the behavior of this function will be a little wired, because if 
        //there is only 1 element left, it can not remove the next.
    {
        if(item->next==NULL)
            return -1;
        
        oldItem = item->next;
        item->next = item->next->next;
    }
    
    free(oldItem);
    return --list->count;
}

int singlelist_count(SingleLinkedList *list)
{
    int count=0;
    if(list->head==NULL)
        return 0;
    else
    {
        SingleLinkedListItem *current = list->head;
        while(current!=NULL)
            count++;
    }
    return count;
}

SingleLinkedListItem *singlelist_get(SingleLinkedList *list,int index)
{
    if(index<0 || index>=list->count)
        return NULL;
    
    if(list->count == 1)
        return list->head;
    
    SingleLinkedListItem *current = list->head;
    while(index!=0)
    {
        current = current->next;
        index--;
    }

    return current;
}


void singlelist_destroy(SingleLinkedList *list)
{
    while(list->count > 0)
        singlelist_remove(list, NULL);

    return;
}


void singlelist_print(SingleLinkedList *list)
{
    if(list->count==0 || list->head==NULL)
        printf("the list is empty!\n");
    else
    {
        SingleLinkedListItem *current = list->head;
        
        while(current!=NULL)
        {
            printf("%d\n",*((int *)(current->data)));
            current = current->next;
        }
    }
    printf("^ that is all items in this list!\n");
}


