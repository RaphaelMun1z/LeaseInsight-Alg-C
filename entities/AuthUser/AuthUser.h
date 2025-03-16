#ifndef AUTH_USER_H
#define AUTH_USER_H

// DTOs
#include "../../dtos/dtos.h"

extern AuthUser *authUser;

void initAuthUser();
void freeAuthUser();

#endif