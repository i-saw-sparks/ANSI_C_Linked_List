#include "health_record.h"

int equal_name(health_record_t *self, char arg_name[50]) {
    int i = 0;
    while(self->patient_name[i] != '\n' && arg_name[i] != '\n'){
        if(self->patient_name[i] != arg_name[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int equal_city(health_record_t *self, char arg_city[50]) {
    int i = 0;
    while(self->city[i] != '\n' && arg_city[i] != '\n'){
        if(self->city[i] != arg_city[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int equal_illnes(health_record_t *self, char arg_illnes[50]) {
    int i = 0;
    while(self->illnes[i] != '\n' && arg_illnes[i] != '\n'){
        if(self->illnes[i] != arg_illnes[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

int equal_birthday(health_record_t *self, char arg_birthday[50]) {
    int i = 0;

    for(i =0 ; i<8; i++){
        if(self->birth_date[i] != arg_birthday[i]) {
            return 0;
        }
    }

    return 1;
}

void print_record(health_record_t *item) {
    if(item != 0) {
        printf("\nName: ");
        fflush(stdout);
        puts(item->patient_name);
        fflush(stdout);
        printf("Gender: ");
        fflush(stdout);
        puts(item->gender);
        fflush(stdout);
        printf("Admission date: ");
        fflush(stdout);
        puts(item->admission_date);
        fflush(stdout);
        printf("Birth date: ");
        fflush(stdout);
        puts(item->birth_date);
        fflush(stdout);
        printf("Illnes: ");
        fflush(stdout);
        puts(item->illnes);
        fflush(stdout);
        printf("Address(City): ");
        fflush(stdout);
        puts(item->city);
        fflush(stdout);
        printf("Blood Type: ");
        fflush(stdout);
        puts(item->blood_type);
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
    for (i = 0; i < 8; ++i) {
        item->birth_date[i] = ' ';
        item->admission_date[i]= ' ';
    }
    item->blood_type[0] = ' ';
    item->blood_type[1] = ' ';
    item->is_deleted = 0;

    item->gender[0] = ' ';
    item->gender[1] = ' ';
}






