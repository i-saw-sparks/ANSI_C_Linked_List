#include <stdio.h>
#include "record_llist.h"

int main() {
    int menu_option = 0;
    record_llist_t* records;
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
        scanf("%i", &menu_option);

        switch(menu_option){
            case 1:
                break;
            case 2:
                records = new_llist();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                printf("Ending the execution...");
                //todo free
                break;
            default:
                printf("\nInvalid option, please try again");
                break;
        }
    }while(menu_option != 10);
}
