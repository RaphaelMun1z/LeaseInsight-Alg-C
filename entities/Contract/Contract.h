#ifndef CONTRACT_H
#define CONTRACT_H

// DTOs
#include "../../dtos/dtos.h"

extern Contract *contracts;
extern int contractsLength;

void initContracts();
void freeContracts();

#endif