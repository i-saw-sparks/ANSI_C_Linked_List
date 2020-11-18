#include "record_llist.h"
#include "health_record.h"

#include <stdio.h>
#include <stdlib.h>

record_llist_t *new_llist() {
    record_llist_t *list;
    list = (record_llist_t *) malloc(sizeof(record_llist_t));

    if (list == NULL) {
        printf("new_llist(): Insufficient memory");
        fflush(stdout);
        return NULL;
    }
    list->size = 0;
    list->head = 0;
}

lnode_t *new_node(health_record_t *item) {
    lnode_t *node;
    node = (lnode_t *) malloc(sizeof(lnode_t));

    if (node == NULL) {
        printf("new_node(): Insufficient memory");
        fflush(stdout);
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
    lnode_t *aux = list->head;

    while (aux != 0) {
        if (equal_name(aux->item, name)) {
            return aux->item;
        }

        aux = aux->next;
    }

    return NULL;
}

health_record_t *search_record_by_birth(record_llist_t *list, char *birth_date) {
    lnode_t *aux = list->head;

    while (aux != 0) {
        if (equal_birthday(aux->item, birth_date)) {
            return aux->item;
        }
        aux = aux->next;
    }

    return NULL;
}

void free_llist(record_llist_t *list) {
    lnode_t *aux = list->head;
    while (aux != 0) {
        list->head = list->head->next;
        free(aux->item);
        free(aux);
        aux = list->head;
    }
}

record_llist_t* read_from_file(record_llist_t *self) {
    FILE *file;
    int i = 0, cat = 0;
    char c_inp;

    free_llist(self);
    self = new_llist();

    file = fopen("patients.txt", "r");
    if (file) {
        health_record_t *input = (health_record_t *) malloc(sizeof(health_record_t));
        while ((c_inp = getc(file)) != EOF) {
            if (c_inp == '#') {
                i = 0;
                cat++;
            }else if (c_inp == '\n') {
                add_record(self, input);
                input = (health_record_t *) malloc(sizeof(health_record_t));
                cat = 0;
                i=0;
            } else {
                switch (cat) {
                    case 0:
                        input->patient_name[i] = c_inp;
                        break;
                    case 1:
                        input->gender[i] = c_inp;
                        break;
                    case 2:
                        input->admission_date[i] = c_inp;
                        break;
                    case 3:
                        input->birth_date[i] = c_inp;
                        break;
                    case 4:
                        input->illnes[i] = c_inp;
                        break;
                    case 5:
                        input->city[i] = c_inp;
                        break;
                    case 6:
                        input->blood_type[i] = c_inp;
                        break;
                    default:
                        fclose(file);
                        return self;
                }
                i++;
            }
        }
        add_record(self, input);
        fclose(file);
    } else {
        printf("\nFile patients.txt not found");
        fflush(stdout);
    }
    return self;
}

void export_rcontainer_to_xml(record_llist_t *self) {
    FILE *xml;
    xml = fopen("Report.xml", "w");
    lnode_t* aux = self->head;

    if(xml == 0){
        printf("\nexport_rcontainer_to_xml Error");
        fflush(stdout);
        return;
    }

    while(aux != 0) {
        fputs("<patient>\n", xml);
        fputs("\t<name>", xml);
        fputs(aux->item->patient_name, xml);
        fputs("</name>\n", xml);
        fputs("\t<gender>", xml);
        fputs(aux->item->gender, xml);
        fputs("</gender>\n", xml);
        fputs("\t<admissionDate value=\"", xml);
        fputs(aux->item->admission_date, xml);
        fputs("\" />\n", xml);
        fputs("\t<birthDate value=\"", xml);
        fputs(aux->item->birth_date, xml);
        fputs("\" />\n", xml);
        fputs("\t<diagnosis>", xml);
        fputs(aux->item->illnes, xml);
        fputs("</diagnosis>\n", xml);
        fputs("\t<city>", xml);
        fputs(aux->item->city, xml);
        fputs("</city>\n", xml);
        fputs("\t<bloodType>", xml);
        fputs(aux->item->blood_type, xml);
        fputs("</bloodType>\n", xml);
        fputs("</patient>\n", xml);
        aux = aux->next;
    }
    fclose(xml);
}










