#include <stdio.h>
#include <stdlib.h>
#include "record_llist.h"


int main() {
    int menu_option = 0;
    record_llist_t* records = 0;
    do{
        printf("\n\nHealth record manager\n"
               "--------------------------------\n"
               "1) Read data\n"
               "2) Create linked list\n"
               "3) Sort data\n"
               "4) Add patient\n"
               "5) Update patient\n"
               "6) Delete patient\n"
               "7) Search for patients\n"
               "8) List patients\n"
               "9) Export medical report\n"
               "10) Exit\n");
        fflush(stdout);
        scanf("%i", &menu_option);

        switch(menu_option){
            case 1:
                if(records != 0) {
                    records = read_from_file(records);
                }else{
                    printf("Please create a linked list first");
                    fflush(stdout);
                }
                break;
            case 2:
                if(records != 0){
                    free_llist(records);
                    records = new_llist();
                }else {
                    records = new_llist();
                }
                break;
            case 3:
                if(records != 0) {
                    //sort_rcontainer(records);
                }else{
                    printf("Please create a linked list first");
                    fflush(stdout);
                }
                break;
            case 4:
                if(records != 0) {
                    health_record_t* input= (health_record_t*)malloc(sizeof(health_record_t));
                    init_record(input);
                    printf("\n\nType the name of the patient:");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->patient_name);
                    printf("Type gender of the patient (M/F): ");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->gender);
                    printf("Type the date of admission: ");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->admission_date);
                    printf("Type the date of birth: ");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->birth_date);
                    printf("Type the illnes: ");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->illnes);
                    printf("Type the addres(City): ");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->city);
                    printf("Type the blood type: ");
                    fflush(stdout);
                    fflush(stdin);
                    gets(input->blood_type);
                    fflush(stdin);
                    add_record(records,input);
                }else{
                    printf("Please create a linked list first");
                    fflush(stdout);
                }
                break;
            case 5: {
                health_record_t *result = 0;
                char input_name[50];
                printf("\n\nType the name of the patient you want to update:");
                fflush(stdout);
                fflush(stdin);
                fgets(input_name, 50, stdin);
                result = search_record_by_name(records, input_name);

                if(result == 0){
                    printf("\n\nPatient not found");
                }else{
                    printf("\n\nType the name of the patient:");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->patient_name, 51, stdin);
                    printf("Type gender of the patient (M/F): ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->gender, 2, stdin);
                    printf("Type the date of admission: ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->admission_date, 9, stdin);
                    printf("Type the date of birth: ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->birth_date, 9, stdin);
                    printf("Type the illnes: ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->illnes, 51, stdin);
                    printf("Type the addres(City): ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->city, 51, stdin);
                    printf("Type the blood type: ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(result->blood_type, 3, stdin);
                    fflush(stdin);
                }
                }
                break;
            case 6:{
                health_record_t *result = 0;
                char input_name[50];
                printf("\n\nType the name of the patient you want to update:");
                fflush(stdout);
                fflush(stdin);
                fgets(input_name, 50, stdin);
                result = search_record_by_name(records, input_name);

                if(result == 0){
                    printf("\n\nPatient not found");
                }else {
                    printf("\n\nPatient deleted");
                    result->is_deleted = 1;
                }
            }
                break;
            case 7: {
                    char sub_option = ' ';
                    char input_name[50];
                    char input_date[50];
                    health_record_t *result = 0;

                    printf("\na)Search by name"
                           "\nb)Search by date of birth"
                           "\nType an option: ");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%c", &sub_option);

                    switch(sub_option) {
                        case 'a':
                            printf("\nType the name of the patient: ");
                            fflush(stdout);
                            fflush(stdin);
                            fgets(input_name, 51, stdin);
                            result = search_record_by_name(records, input_name);
                            break;
                        case 'b':
                            printf("\nType the date of birth of the patient: ");
                            fflush(stdout);
                            fflush(stdin);
                            fgets(input_date, 9, stdin);
                            result = search_record_by_birth(records, input_date);
                            break;
                        default:
                            printf("\nInvalid option, try again");
                            fflush(stdout);
                            break;
                    }
                    print_record(result);
                }
                break;
            case 8:{
                char sub_option;
                lnode_t* aux=records->head;
                printf("a)list all patients\n"
                       "b)list patients by illnes\n"
                       "c)list patients by city\n"
                       "d)discharged\n"
                       "Type your option: ");
                fflush(stdout);
                fflush(stdin);
                scanf("%c", &sub_option);

                switch(sub_option){
                    case 'a':
                        while(aux != 0){
                            if(!(aux->item->is_deleted)) {
                                print_record(aux->item);
                                printf("\n");
                                fflush(stdout);
                            }
                            aux = aux->next;
                        }
                        break;
                    case 'b': {
                        char input_illnes[50];
                        printf("\nType the illnes: ");
                        fflush(stdout);
                        fflush(stdin);
                        fgets(input_illnes, 51, stdin);
                        while (aux != 0) {
                            if (!(aux->item->is_deleted) && equal_illnes(aux->item, input_illnes)) {
                                print_record(aux->item);
                                printf("\n");
                                fflush(stdout);
                            }
                            aux = aux->next;
                        }
                        }
                        break;
                    case 'c':{
                        char input_city[50];
                        printf("\nType the city: ");
                        fflush(stdout);
                        fflush(stdin);
                        fgets(input_city, 51, stdin);
                        while (aux != 0) {
                            if (!(aux->item->is_deleted) && equal_city(aux->item, input_city)) {
                                print_record(aux->item);
                                printf("\n");
                                fflush(stdout);
                            }
                            aux = aux->next;
                        }
                    }
                        break;
                    case 'd':
                        while(aux != 0){
                            if((aux->item->is_deleted)) {
                                print_record(aux->item);
                                printf("\n");
                                fflush(stdout);
                            }
                            aux = aux->next;
                        }
                        break;
                    default:
                        printf("\nInvalid option, try again");
                        fflush(stdout);
                        break;
                }
            }
                break;
            case 9:
                break;
            case 10:
                printf("Ending the execution...");
                fflush(stdout);
                break;
            default:
                printf("\nInvalid option, please try again");
                fflush(stdout);
                break;
        }
    }while(menu_option != 10);

    if(records != 0) {
        free_llist(records);
    }
}

