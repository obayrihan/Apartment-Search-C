#ifndef HEADER2_H
#define HEADER2_H

#include "flat.h"


void SearchFlat(char name[], struct flat *flats, int n);
void BookFlat(struct flat *flats, int num, int n);
float CalculateRent(struct flat *flats, int month, int Numb, int n);

#endif
