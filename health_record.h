
#ifndef PROJECT1_HEALTH_RECORD_H
#define PROJECT1_HEALTH_RECORD_H

#include <stdint.h>
#include <stdio.h>

typedef struct health_record{
    char patient_name[50], illnes[50], city[50], blood_type[3], gender[2];
    char admission_date[9], birth_date[9];
    int is_deleted;
}health_record_t;

void init_record(health_record_t*);
int equal_name(health_record_t*, char[]);
int equal_city(health_record_t*, char[]);
int equal_illnes(health_record_t*, char[]);
int equal_birthday(health_record_t*, char[]);
void print_record(health_record_t*);


#endif //PROJECT1_HEALTH_RECORD_H
