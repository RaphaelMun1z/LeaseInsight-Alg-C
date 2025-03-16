#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char phone[16];
    char email[255];
    char password[100];
    char rg[13]; // PK
    char cpf[15];
    int tenantStatus;
    char dateOfBirth[11]; 
    char registrationDate[11];
} Tenant;

Tenant *tenants;
int registeredTenantsNumber = 0;
int tenantsCurrentLimit = 5;

void initTenants() {
    tenants = (Tenant *) calloc(5, sizeof(Tenant));
    
    if (tenants == NULL) {
        printf("[LOG] Erro ao alocar memória para 'tenants'!\n");
    }
}

void allocateMoreSpaceTenant(){
    tenantsCurrentLimit += 5;
    
    Tenant *temp = realloc(tenants, sizeof(Tenant) * tenantsCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'tenants'!\n");
        tenantsCurrentLimit -= 5;
        return;
    }
    
    tenants = temp;
}

void freeTenants(){
    free(tenants);
}