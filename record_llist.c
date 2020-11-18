#include "record_llist.h"
#include "health_record.h"

#include <stdio.h>
#include <stdlib.h>

record_llist_t* new_llist(){
    record_llist_t *list;
    list = (record_llist_t*)malloc(sizeof(record_llist_t));

    if(list == NULL){
        printf("new_llist(): Insufficient memory");
        return NULL;
    }
    list->size = 0;
    list->head = 0;
}

lnode_t* new_node(health_record_t *item) {
    lnode_t *node;
    node = (lnode_t *) malloc (sizeof (lnode_t));

    if (node == NULL) {
        printf("new_node(): Insufficient memory");
        return NULL;
    }

    node->item = item;
    node->next = 0;
    return node;
}

void add_record(record_llist_t *list, health_record_t *item) {
    lnode_t *node;
    node = new_node(item);

    node->next = list->head;
    list->head = node;
    (list->size)++;
}

health_record_t *search_record_by_name(record_llist_t *list, char name[50]) {
    lnode_t* aux = list->head;

    while(aux != 0){
        if(equal_name(aux->item, name)){
            return aux->item;
        }
    }

    return NULL;
}


void delete_record(health_record_t *item) {
    item->is_deleted = 1;
}





