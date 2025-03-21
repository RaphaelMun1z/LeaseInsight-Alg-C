#ifndef TENANT_SERVICE_H
#define TENANT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllTenants();
Tenant *findTenantById(double id);
Tenant *findTenantByEmail(char email[]);
Tenant *findTenantByRg(char rg[]);
void createTenant(Tenant Tenant);

int isTenantAssociatedToContract(int tenantId, int contractId);

#endif