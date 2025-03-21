#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

Tenant *tenants;
int registeredTenantsNumber = 0;
int tenantsCurrentLimit;
const int incrementAmount = 5;

void initTenants() {
    tenantsCurrentLimit = 15;
    tenants = (Tenant *) calloc(tenantsCurrentLimit, sizeof(Tenant));
    
    if (tenants == NULL) {
        printf("[LOG] Erro ao alocar memória para 'tenants'!\n");
        return;
    }

    printf("[LOG] Memória padrão alocada para 'tenants'\n");
}

void allocateSpaceTenantForFile(int numberOfTenants){
    registeredTenantsNumber = numberOfTenants;
    tenantsCurrentLimit = ((numberOfTenants / 5) + 1) * 5;

    tenants = (Tenant *) calloc(tenantsCurrentLimit, sizeof(Tenant));
    
    if (tenants == NULL) {
        printf("[LOG] Erro ao alocar memória para 'tenants'!\n");
        return;
    }

    printf("[LOG] Memória alocada para 'tenants' com base nos %d registros do arquivo!\n", numberOfTenants);
}

void allocateMoreSpaceTenant(){
    tenantsCurrentLimit += incrementAmount;
    
    Tenant *temp = realloc(tenants, sizeof(Tenant) * tenantsCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'tenants'!\n");
        tenantsCurrentLimit -= incrementAmount;
        return;
    }
    
    tenants = temp;
    printf("[LOG] Mais memória alocada para 'tenants'\n");
}

void freeTenants(){
    free(tenants);
    tenants = NULL;
}