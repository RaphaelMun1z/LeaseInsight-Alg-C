#ifndef AUTH_USER_H
#define AUTH_USER_H

// DTOs
#include "../../dtos/dtos.h"

extern AuthUser *authUser;

void initAuthUser();
void allocateAuthUserMemory(int id, int userType);
void setDefaultValuesToAuthUser(int id, int userType);
void freeAuthUser();

#endif