#ifndef TENANT_SERVICE_H
#define TENANT_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllTenants();
Tenant *findTenantById(int id);
Tenant *findTenantByEmail(char email[]);
Tenant *findTenantByRg(char rg[]);
void createTenant(Tenant Tenant);
void deleteTenant(char tenantRg[]);

void printTenant(Tenant t);
void printTenantByRg(char rg[]);
int tenantExistsByRg(char rg[]);
int isTenantAssociatedToContract(int tenantId, int contractId);
void changeTenantStatus(char rg[], int status);
void changeTenantPhone(int tenantId, char newPhone[]);

#endif