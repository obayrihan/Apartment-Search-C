#include <stdio.h>
#include "header3.h"

#include <string.h>

void writetofile(struct flat *flats) {
    FILE *output = fopen("flats.txt", "w");
    if (output == NULL) {
        printf("Error opening file\n");
        return;
    }
    fprintf(output, "%d;%d;%s;%s;%d;%s;%.2f\n",
            flats->number,
            flats->rooms,
            flats->name,
            flats->owner,
            flats->booked,
            flats->street,
            flats->rent);
    fclose(output);
}

void readfromfile(struct flat *flats) {
    FILE *input = fopen("flats.txt", "r");
    if (input == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[300];
    int booked = 0;
    if (fgets(line, 300, input) != NULL) {
        char *token = strtok(line, ";");
        int flag = 1;
        while (token != NULL) {
            if (flag == 1) {
                sscanf(token, "%d", &flats->number);
            } else if (flag == 2) {
                sscanf(token, "%d", &flats->rooms);
            } else if (flag == 3) {
                sscanf(token, "%s", flats->name, token);
            } else if (flag == 4) {
                strcpy(flats->owner, token);
            } else if (flag == 5) {
                sscanf(token, "%d", &booked);
                flats->booked = booked;
            } else if (flag == 6) {
                strcpy(flats->street, token);
            } else if (flag == 7) {
                sscanf(token, "%f", &flats->rent);
            }

            token = strtok(NULL, ";");
            flag++;
        }
    }
    fclose(input);
}
