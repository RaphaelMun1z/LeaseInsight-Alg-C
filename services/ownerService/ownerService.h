#ifndef OWNER_SERVICE_H
#define OWNER_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllOwners();
Owner *findOwnerById(double id);
Owner *findOwnerByEmail(char email[]);
void createOwner(Owner Owner);
void deleteOwner(double id); 

void printOwner(Owner o);
void printOwnerById(double id);
int ownerExistsById(double id);
void changeOwnerDetails(double id, char newName[]);

#endif