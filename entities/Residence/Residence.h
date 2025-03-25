#ifndef RESIDENCE_H
#define RESIDENCE_H

// DTOs
#include "../../dtos/dtos.h"

extern Residence *residences;
extern int registeredResidencesNumber;
extern int residencesCurrentLimit;

void initResidences();
void allocateMoreSpaceResidence();
void deallocateSpaceResidence();
void allocateSpaceResidenceForFile(int numberOfResidences);
void freeResidences();

#endif