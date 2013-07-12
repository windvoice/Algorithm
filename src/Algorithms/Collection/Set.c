//
//  Set.c
//  Algorithms
//
//  Created by zhangfeng on 4/4/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Set.h"
#include "SingleLinkedList.h"

void set_init(Set *set, int (* match) (const void *key1,const void *key2))
{
    singlelist_init(set);
    set->match = match;
}

int set_insert(Set *set, const void *data)
{
    if(set_ismember(set, data))
        return 1;
    else
    {
        SingleLinkedListItem *last = singlelist_get(set, singlelist_count(set)-1);
        singlelist_insert(set, last, data);
        return 0;
    }
}

int set_remove(Set *set, void **data)
{ 
}


int set_ismember(Set *set, const void *data)
{
    SingleLinkedListItem *current = set->head;
    
    while (current!=NULL) {
        if(set->match(current->data, data))
            return 1;
        
        current = current->next;
    }
    
    return -1;
}