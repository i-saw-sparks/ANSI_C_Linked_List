#include "health_record.h"

int equal_name(health_record_t *self, char *arg_name) {
    int i;
    for (i = 0; i < 50; ++i) {
        if(self->patient_name[i] != arg_name[i]) {
            return 0;
        }
    }
    return 1;
}