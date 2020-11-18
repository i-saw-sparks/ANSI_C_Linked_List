
#ifndef PROJECT1_HEALTH_RECORD_H
#define PROJECT1_HEALTH_RECORD_H

#include <stdint.h>

typedef struct health_record{
    char patient_name[50], illnes[50], city[50], blood_type[2];
    char gender;
    int32_t admission_date, birth_date;
    uint8_t is_deleted;
}health_record_t;

void init_record(health_record_t*);
void update_record(health_record_t*);
void delete_record(health_record_t*);
int equal_name(health_record_t*, char*);


#endif //PROJECT1_HEALTH_RECORD_H
