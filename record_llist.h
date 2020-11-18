#ifndef PROJECT1_RECORD_LLIST_H
#define PROJECT1_RECORD_LLIST_H

#include "health_record.h"

typedef struct lnode{
    struct lnode *next;
    health_record_t *item;
}lnode_t;

typedef struct record_llist{
    lnode_t *head;
    int16_t size;
}record_llist_t;

lnode_t* new_node(health_record_t*);
record_llist_t* new_llist();

void read_from_file(record_llist_t*);
void save_to_file(record_llist_t*);
void export_rcontainer_to_xml(record_llist_t*);

void sort_rcontainer(record_llist_t*);
health_record_t* search_record_by_name(record_llist_t*, char[]);
health_record_t* search_record_by_birth(record_llist_t*, int32_t);

void add_record(record_llist_t*, health_record_t*);

void free_llist(record_llist_t*);

#endif //PROJECT1_RECORD_LLIST_H
