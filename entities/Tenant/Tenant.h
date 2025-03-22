#ifndef TENANT_H
#define TENANT_H

// DTOs
#include "../../dtos/dtos.h"

extern Tenant *tenants;
extern int registeredTenantsNumber;
extern int tenantsCurrentLimit;

void initTenants();
void allocateMoreSpaceTenant();
void allocateSpaceTenantForFile(int numberOfTenants);
void freeTenants();

#endif