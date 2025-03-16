#ifndef TENANT_SERVICE_H
#define TENANT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllTenants();
Tenant* findTenantById(double id);
Tenant* findTenantByEmail(char email[]);
Tenant* findTenantByRg(char rg[]);
void signInTenant(TenantLogin credentials);
void createTenant(Tenant Tenant);

#endif