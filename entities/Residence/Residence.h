#ifndef RESIDENCE_H
#define RESIDENCE_H

// DTOs
#include "../../dtos/dtos.h"

extern Residence *residences;
extern int residencesLength;

void initResidences();
void freeResidences();

#endif