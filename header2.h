#ifndef HEADER2_H
#define HEADER2_H

struct flat;

void SearchFlat(char name[], struct Flat *flats, int n);
void BookFlat(struct flat *flats, int num, int n);
float CalculateRent(struct Flat *flats, int month, int Numb, int n);

#endif
