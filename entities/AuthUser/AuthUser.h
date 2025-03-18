#ifndef AUTH_USER_H
#define AUTH_USER_H

// DTOs
#include "../../dtos/dtos.h"

extern AuthUser *authUser;

void initAuthUser();
void allocateAuthUserMemory(double id, int userType);
void setDefaultValuesToAuthUser(double id, int userType);
void freeAuthUser();

#endif