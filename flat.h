#ifndef FLAT_H
#define FLAT_H
#define max_flats 100

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

struct flat_node {
    struct flat flat;
    struct flat_node *next;
};
struct flat_list {
    struct flat_node *head;
    struct flat_node *tail;
};
#endif
