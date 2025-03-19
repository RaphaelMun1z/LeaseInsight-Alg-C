#ifndef STATE_MANAGER_SERVICE_H
#define STATE_MANAGER_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

AuthUser *getAuthUser();
char* getAuthUserName();
void setAuthUser(AuthUserResponse userResponse);
void logoutAuthUser();

#endif