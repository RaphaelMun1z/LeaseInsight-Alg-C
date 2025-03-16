#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Tenant/Tenant.h"

void findAllTenants(){
    if(registeredTenantsNumber == 0)
    return printColorful("Não há inquilinos registrados.\n", 4);
    
    for (int ii = 0; ii < registeredTenantsNumber; ii++){
        printf("\nNome: %s\n", tenants[ii].name);
        printf("Telefone: %s\n", tenants[ii].phone);
        printf("E-mail: %s\n", tenants[ii].email);
        printf("RG: %s\n", tenants[ii].rg);
        printf("CPF: %s\n", tenants[ii].cpf);
        printf("Status: %d\n", tenants[ii].tenantStatus);
        printf("Data de Nascimento: %s\n", tenants[ii].dateOfBirth);
        printf("Data de Registro: %s\n", tenants[ii].registrationDate);
        printf("\n____\n");
    }
}

int findTenantByRg(char rg[]){
    for (int ii = 0; ii < registeredTenantsNumber; ii++){
        if(strcmp(tenants[ii].rg, rg) == 0){
            return 1;
        }
    }
    
    return -1;
}

void createTenant(Tenant tenant){
    if(findTenantByRg(tenant.rg) != -1)
    return printColorful("Inquilino já cadastrado!\n", 1);
    
    strcpy(tenants[registeredTenantsNumber].name, tenant.name);
    strcpy(tenants[registeredTenantsNumber].phone, tenant.phone);
    strcpy(tenants[registeredTenantsNumber].email, tenant.email);
    strcpy(tenants[registeredTenantsNumber].password, tenant.password);
    strcpy(tenants[registeredTenantsNumber].rg, tenant.rg);
    strcpy(tenants[registeredTenantsNumber].cpf, tenant.cpf);
    tenants[registeredTenantsNumber].tenantStatus = 1;
    strcpy(tenants[registeredTenantsNumber].dateOfBirth, tenant.dateOfBirth);
    strcpy(tenants[registeredTenantsNumber].registrationDate, "15/03/2025");
    registeredTenantsNumber++;
    
    char tempName[100];
    strncpy(tempName, tenant.name, strcspn(tenant.name, "\n"));
    tempName[strcspn(tenant.name, "\n")] = '\0'; 
    
    char welcomeText[200];
    snprintf(welcomeText, sizeof(welcomeText), "\n%s, você foi registrado com sucesso, seja bem-vindo(a)!\n", tempName);
    printColorful(welcomeText, 2);
    
    if(registeredTenantsNumber == tenantsCurrentLimit)
    allocateMoreSpaceTenant();
}