#ifndef OWNER_SERVICE_H
#define OWNER_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllOwners();
Owner *findOwnerById(int id);
Owner *findOwnerByEmail(char email[]);
void createOwner(Owner Owner);
void deleteOwner(int id); 

void printOwner(Owner o);
void printOwnerById(int id);
int ownerExistsById(int id);
void changeOwnerDetails(int id, char newName[]);

#endif