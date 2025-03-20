#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void signInAdm(LoginCredentials credentials, AuthUserResponse *userResponse);
void signInTenant(LoginCredentials credentials, AuthUserResponse *userResponse);
void signInOwner(LoginCredentials credentials, AuthUserResponse *userResponse);
void signInUser(LoginCredentials credentials);

#endif