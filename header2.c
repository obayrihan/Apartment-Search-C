#include "header2.h"

#include <stdio.h>
#include <stdbool.h>

#include "flat.h"

void SearchFlat(char name[], struct Flat *flats, int n) {
    for (int i = 0; i < n; i++) {
        if (flats[i].name == name) {
            printf("The %s flat has number %d", name, flats[i].number);
        }
    }
}

void BookFlat(struct Flat* flats, int num, int n) {
    for (int i = 0; i < n; i++) {
        if ((flats[i].number == num) && !flats[i].booked) {
            flats[i].booked = 0;
            printf("Flat %d booked.", num);
        }
    }
}

float CalculateRent(struct Flat* flats, int month, int Numb, int n) {
    for (int i = 0; i < n; i++) {
        if (flats[i].number == Numb) {
            return (float) month * flats[i].rent;
        }
    }
    return 0.0f;
}

