#ifndef STATE_MANAGER_SERVICE_H
#define STATE_MANAGER_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

AuthUser *getAuthUser();
char* getAuthUserName();
void setAuthUser(char name[], AuthUser user);
void removeAuthUser();

#endif