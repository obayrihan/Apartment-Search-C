#ifndef FLAT_H
#define FLAT_H

#include <stdbool.h>

struct flat {
    int number;
    int rooms;
    char name[50];
    char owner[50];
    bool booked;
    char street[50];
    float rent;
};
#endif