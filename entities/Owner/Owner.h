#ifndef OWNER_H
#define OWNER_H

// DTOs
#include "../../dtos/dtos.h"

extern Owner *owners;
extern int registeredOwnersNumber;
extern int ownersCurrentLimit;

void initOwners();
void allocateMoreSpaceOwner();
void allocateSpaceOwnerForFile(int numberOfOwners);
void freeOwners();

#endif