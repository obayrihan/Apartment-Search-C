#include <stdio.h>
#include <stdlib.h>
#include "flat.h"
#include "header1.h"
#include "header2.h"
#include "header3.h"

int main() {
    int choice = 0;
    int room;
    int num;
    int number;
    int months;
    char name[50];
    float rent;
    printf("Please enter number of flats: ");
    scanf("%d", &num);

    if (num <= 0) {
        return 1;
    }
    struct flat *flats = malloc(sizeof(struct flat) * num);

    if (flats == NULL) {
        return 1;
    }
    for (int i = 0; i < num; i++) {
        printf("Enter flat number: ");
        scanf("%d", &flats[i].number);

        printf("Enter number of rooms: ");
        scanf("%d", &flats[i].rooms);

        printf("Enter flat name: ");
        scanf("%s", flats[i].name);

        printf("Enter owner name: ");
        scanf("%s", flats[i].owner);

        printf("Enter street: ");
        scanf("%s", flats[i].street);

        printf("Enter rent: ");
        scanf("%f", &flats[i].rent);

        flats[i].booked = false;
    }
    while (choice != -1) {
        Menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number of rooms: ");
                scanf("%d", &room);

                DisplayFlats(room);

                for (int i = 0; i < num; i++) {
                    if (flats[i].rooms == room) {
                        DisplayAll(&flats[i], 1);
                    }
                }
                break;

            case 2:
                DisplayAll(flats, num);
                break;

            case 3:
                printf("Enter flat name: ");
                scanf("%s", name);

                SearchFlat(name, flats, num);
                break;

            case 4:
                printf("Enter flat number: ");
                scanf("%d", &number);

                BookFlat(flats, number, num);
                break;

            case 5:
                printf("Enter flat number: ");
                scanf("%d", &number);

                printf("Enter number of months: ");
                scanf("%d", &months);

                rent = CalculateRent(flats, months, number, num);

                printf("Total rent: %.2f\n", rent);
                break;

            case 6:
                writetofile(flats);
                break;

            case 7:
                readfromfile(flats);
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
