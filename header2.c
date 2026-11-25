#include "header2.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "flat.h"

void SearchFlat(char name[], struct flat *flats, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(flats[i].name, name) == 0) {
            printf("The %s flat has number %d\n", name, flats[i].number);
        }
    }
}

void BookFlat(struct flat* flats, int num, int n) {
    for (int i = 0; i < n; i++) {
        if ((flats[i].number == num) && !flats[i].booked) {
            flats[i].booked = true;
            printf("Flat %d booked.", num);
        }
    }
}

float CalculateRent(struct flat* flats, int month, int Numb, int n) {
    for (int i = 0; i < n; i++) {
        if (flats[i].number == Numb) {
            return (float) month * flats[i].rent;
        }
    }
    return 0.0f;
}

