#include "header1.h"

#include <stdio.h>
#include <stdbool.h>
#include "flat.h"
void Menu();
void DisplayFlats(int room);
void DisplayAll(struct Flat *flats, int num);



void Menu() {
    printf("1. Display Flats\n");
    printf("2. Display All\n");
    printf("3. Search Flat\n");
    printf("4. Book Flat\n");
    printf("5. Calculate Rent\n");
    printf("6. Write to File\n");
    printf("7. Read from File\n");
    printf("-1. Exit Menu \n")
}

void DisplayFlats(int room) {
    printf("Rooms: %d\n",room);
}
void DisplayAll(struct Flat *flats, int num) {
    int i;
    for (i = 0 ; i < num ; i++) {
        printf("%d %d %s %s %d %s %.2f\n",
            flats[i].number,
            flats[i].rooms,
            flats[i].name,
            flats[i].owner,
            flats[i].booked,
            flats[i].street,
            flats[i].rent);
    }
}

