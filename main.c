#include <stdio.h>
#include <stdlib.h>
#include "flat.h"
#include "header1.h"
#include "header2.h"
#include "header3.h"
int validate_int(const char *prompt, int *value) {
    while (1) {
        printf("%s", prompt);
        int result = scanf("%d", value);
        if (result == EOF) {
            return 0;
        }
        int choice;
        int hasExInput = 0;
        while ((choice = getchar()) != '\n' && choice != EOF) {
            hasExInput = 1;
        }

        if (result == 1 && hasExInput == 0) {
            return 1;
        }
        fprintf(stderr, " Error! Enter only one integer\n");

        if (choice == EOF) {
            return 0;
        }
    }
}


int main() {
    int choice = 0;
    int room;
    int num;
    int number;
    int months;
    char name[50];
    float rent;
    if (!validate_int("Enter number of flats: ", &num)) {
        return 1;
    }

    if (num<=0 || num>max_flats) {
        fprintf(stderr, "Invalid number of flats\n");
        return 1;
    }
    struct flat_node nodes[max_flats];
    struct flat_node *head = NULL;
    struct flat_node *tail = NULL;

    for (int i = 0; i < num; i++) {
        struct flat_node *node = &nodes[i];
        // printf("Enter flat number: ");   UNVALIDATED INPUT!
        // scanf("%d", &flats[i].number);
        if (!validate_int("Enter flat numbner: ", &node->flat.number)) {
            
            return 1;
        }

        // printf("Enter number of rooms: ");   UNVALIDATED INPUT!
        // scanf("%d", &flats[i].rooms);
        if (!validate_int("Enter number of rooms: ", &node->flat.rooms)) {
            
            return 1;
        }

        printf("Enter flat name: ");
        scanf("%s", node->flat.name);

        printf("Enter owner name: ");
        scanf("%s", node->flat.owner);

        printf("Enter street: ");
        scanf("%s", node->flat.street);

        printf("Enter rent: ");
        if (scanf("%f", &node->flat.rent)!=1) {
            fprintf(stderr, "Invalid rent\n");
            return 1;
        }
    node->flat.booked = false;
        node->next = NULL;
        if (head == NULL) {
            head = node;
        
        }else {
            tail->next = node;
        }
    tail = node;
    }
    while (choice != -1) {
        Menu();
        if (!validate_int("Enter Your Choice: ", &choice)) {
            break;
        }
        switch (choice) {
            case 1:
                // printf("Enter number of rooms: ");
                // scanf("%d", &room);
                if (!validate_int("Enter Number of Rooms: ", &room)) {
                    return 0;
                }

                DisplayFlats(room);


                for (struct flat_node *node = head; node != NULL; node = node->next) {
                    if (node->flat.rooms == room) {
                        DisplayAll(&node->flat,1);
                    }
                }
                break;

            case 2:
                for (struct flat_node *node = head; node != NULL; node = node->next) {
                    DisplayAll(&node->flat,1);
                }
                break;

            case 3:
                printf("Enter flat name: ");
                scanf("%s", name);
                for (struct flat_node *node = head; node != NULL; node = node->next) {
                    SearchFlat(name, &node->flat, 1);
                }

                break;

            case 4:

                if (!validate_int("Enter Flat Number: ", &number)) {
                    
                    return 0;
                }
                    for (struct flat_node *node = head; node != NULL; node = node->next) {
                        BookFlat(&node->flat, number,1 );
                    }
                break;

            case 5:

                if (!validate_int("Enter Flat Number: ", &number)) {
                    
                    return 0;
                }

                if (!validate_int("Enter Number of Months: ", &months)) {
                    
                    return 0;
                }
                float rent = 0.0;
                for (struct flat_node *node = head; node != NULL; node = node->next) {
                    if (node->flat.number == number) {
                        rent = CalculateRent(&node->flat, months, number, 1);
                        break;
                    }
                }
                printf("Total rent: %.2f\n", rent);
                break;

            case 6:
                writetofile(&head->flat);
                break;

            case 7:
                readfromfile(&head->flat);
                break;

            case -1:
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
