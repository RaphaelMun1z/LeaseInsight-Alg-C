#ifndef RESIDENCE_H
#define RESIDENCE_H

// DTOs
#include "../../dtos/dtos.h"

extern Residence *residences;
extern int residencesLength;
extern int residencesCurrentLimit;

void initResidences();
void allocateMoreSpaceResidence();
void freeResidences();

#endif