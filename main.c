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
                break;
            case 2:
                if(records != 0){
                    //free_llist(records);
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
                    fgets(input->patient_name, 50, stdin);
                    printf("Type gender of the patien (M/F): ");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%c", &(input->gender));
                    printf("Type the date of admission: ");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%i", &(input->admission_date));
                    printf("Type the date of birth: ");
                    fflush(stdout);
                    fflush(stdin);
                    scanf("%i", &(input->birth_date));
                    printf("Type the illnes: ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(input->illnes, 50, stdin);
                    printf("Type the addres(City): ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(input->city, 50, stdin);
                    printf("Type the blood type: ");
                    fflush(stdout);
                    fflush(stdin);
                    fgets(input->illnes, 2, stdin);
                    fflush(stdin);
                    add_record(records,input);
                }else{
                    printf("Please create a linked list first");
                    fflush(stdout);
                }
                break;
            case 5:
                break;
            case 6:
                break;
            case 7: {
                    char sub_option = ' ';
                    char input_name[50];
                    int input_date;
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
                            fgets(input_name, 50, stdin);
                            result = search_record_by_name(records, input_name);
                            break;
                        case 'b':
                            printf("\nType the date of birth of the patient: ");
                            fflush(stdout);
                            fflush(stdin);
                            scanf("%i", &input_date);
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
            case 8:
                break;
            case 9:
                break;
            case 10:
                printf("Ending the execution...");
                fflush(stdout);
                //todo free
                break;
            default:
                printf("\nInvalid option, please try again");
                fflush(stdout);
                break;
        }
    }while(menu_option != 10);

    //free_llist(records);
}
