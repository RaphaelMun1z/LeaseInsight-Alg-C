#ifndef OWNER_SERVICE_H
#define OWNER_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllOwners();
Owner *findOwnerById(double id);
Owner *findOwnerByEmail(char email[]);
void createOwner(Owner Owner);

#endif