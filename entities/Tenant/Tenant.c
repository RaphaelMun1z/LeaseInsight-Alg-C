#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char rg[13]; // PK
    char cpf[15];
    int tenantStatus;
    char dateOfBirth[11]; 
    char registrationDate[11];
} Tenant;

Tenant *tenants;

void initTenants() {
    tenants = (Tenant *) calloc(5, sizeof(Tenant));

    if (tenants == NULL) {
        printf("[LOG] Erro ao alocar memória para 'tenants'!\n");
    }
}

void freeTenants(){
    free(tenants);
}