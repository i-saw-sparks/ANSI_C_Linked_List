#include "health_record.h"

int equal_name(health_record_t *self, char arg_name[50]) {
    int i = 0;
    while(self->patient_name[i] != '\n'){
        if(self->patient_name[i] != arg_name[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

void delete_record(health_record_t *item) {
    item->is_deleted = 1;
}

void print_record(health_record_t *item) {
    if(item != 0) {
        printf("\nName: ");
        fflush(stdout);
        fputs(item->patient_name, stdout);
        fflush(stdout);
        printf("Gender: ");
        fputs(item->gender, stdout);
        fflush(stdout);
        printf("\nDate of admission: %i\n", item->admission_date);
        fflush(stdout);
        printf("Date of birth: %i\n", item->birth_date);
        fflush(stdout);
        printf("Illnes: ");
        fflush(stdout);
        fputs(item->illnes, stdout);
        fflush(stdout);
        printf("Address(City): ");
        fflush(stdout);
        fputs(item->city, stdout);
        fflush(stdout);
        printf("Blood Type: ");
        fflush(stdout);
        fputs(item->blood_type, stdout);
        fflush(stdout);
    }else{
        printf("\nPatient not found");
        fflush(stdout);
    }
}

void init_record(health_record_t *item) {
    int i;
    for (i = 0; i < 50; ++i) {
        item->patient_name[i] = ' ';
        item->illnes[i] = ' ';
        item->city[i] = ' ';
    }
    item->blood_type[0] = ' ';
    item->blood_type[1] = ' ';
    item->is_deleted = 0;
    item->birth_date = 0;
    item->admission_date = 0;
    item->gender[0] = ' ';
}
