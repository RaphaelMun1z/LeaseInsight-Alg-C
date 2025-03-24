#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/enums/enums.h"

// Entities
#include "../../entities/GenericUser/GenericUser.h"
#include "../../entities/Tenant/Tenant.h"
#include "../../entities/Contract/Contract.h"

// Services
#include "../dataPersistenceService/dataPersistenceService.h"
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../userService/userService.h"
#include "../contractService/contractService.h"

void findAllTenants();
Tenant *findTenantById(int id);
Tenant *findTenantByEmail(char email[]);
Tenant *findTenantByRg(char rg[]);
void createTenant(Tenant Tenant);

void printTenant(Tenant t);
void printTenantByRg(char rg[]);
int tenantHasContract(int tenantId);
int isTenantAssociatedToContract(int tenantId, int contractId);

void findAllTenants(){
    if(registeredTenantsNumber == 0)
    return printColorful("Não há inquilinos registrados.\n", 4);
    
    for (int ii = 0; ii < registeredTenantsNumber; ii++){
        printTenant(tenants[ii]);
    }
}

Tenant *findTenantById(int id){
    for (int ii = 0; ii < registeredTenantsNumber; ii++){
        if(tenants[ii].id == id){
            return &tenants[ii];
        }
    }
    
    return NULL;
}

Tenant *findTenantByEmail(char email[]){
    for (int ii = 0; ii < registeredTenantsNumber; ii++){
        if(strcmp(tenants[ii].email, email) == 0){
            return &tenants[ii];
        }
    }
    
    return NULL;
}

Tenant *findTenantByRg(char rg[]){
    for (int ii = 0; ii < registeredTenantsNumber; ii++){
        if(strcmp(tenants[ii].rg, rg) == 0){
            return &tenants[ii];
        }
    }
    
    return NULL;
}

int tenantExistsByRg(char rg[]){
	return findTenantByRg(rg) == NULL ? 0 : 1;
}

void createTenant(Tenant tenant){
    if(userAlreadyRegistered(tenant.email) || findTenantByRg(tenant.rg) != NULL) return;

    if(findTenantByRg(tenant.rg) != NULL){
        printColorful("Usuário já cadastrado!\n", 1);
        return;
    }
    
    tenants[registeredTenantsNumber].id = registeredUsersNumber + 1;
    strcpy(tenants[registeredTenantsNumber].name, tenant.name);
    strcpy(tenants[registeredTenantsNumber].phone, tenant.phone);
    strcpy(tenants[registeredTenantsNumber].email, tenant.email);
    strcpy(tenants[registeredTenantsNumber].password, tenant.password);
    strcpy(tenants[registeredTenantsNumber].rg, tenant.rg);
    strcpy(tenants[registeredTenantsNumber].cpf, tenant.cpf);
    tenants[registeredTenantsNumber].tenantStatus = 1;
    registeredTenantsNumber++;
    registeredUsersNumber++;

    saveTenantsData();
    
    char tempName[100];
    strncpy(tempName, tenant.name, strcspn(tenant.name, "\n"));
    tempName[strcspn(tenant.name, "\n")] = '\0'; 
    
    char welcomeText[200];
    snprintf(welcomeText, sizeof(welcomeText), "\n%s, você foi registrado com sucesso, seja bem-vindo(a)!\n", tempName);
    printColorful(welcomeText, 2);
    
    if(registeredTenantsNumber == tenantsCurrentLimit)
    allocateMoreSpaceTenant();
    
    LoginCredentials credentials;
    strcpy(credentials.email, tenant.email);
    strcpy(credentials.password, tenant.password);
    
    signInUser(credentials);
}

void deleteTenant(char tenantRg[]){
    if(!tenantExistsByRg(tenantRg)){
		printColorful("Inquilino não encontrado.\n", 1);
		return;
	}

    if(tenantHasContract(findTenantByRg(tenantRg)->id)){
        printColorful("Inquilino possui contrato vinculado, não é possível deletar.\n", 1);
        return;
    }
	
	for (int ii = 0; ii < registeredTenantsNumber; ii++){
		if(strcmp(tenants[ii].rg, tenantRg) == 0){
			int indLastItemOfTenants = registeredTenantsNumber-1;
			tenants[ii] = tenants[indLastItemOfTenants];
			registeredTenantsNumber--;
            saveTenantsData();
			printColorful("Inquilino deletado com sucesso!\n", 2);
			return;
		}
	}

	return printColorful("Inquilino não encontrado.\n", 1);
}

void printTenant(Tenant t){
    printf("\nCódigo: %d", t.id);
    printf("\nNome: %s\n", t.name);
    printf("Telefone: %s\n", t.phone);
    printf("E-mail: %s\n", t.email);
    printf("RG: %s\n", t.rg);
    printf("CPF: %s\n", t.cpf);

    char tenantStatusStr[100];
    getTenantStatus(t.tenantStatus, tenantStatusStr);
    printf("Status: %s\n", tenantStatusStr);

    printf("\n____\n");
}

void printTenantByRg(char rg[]){
    Tenant *t = findTenantByRg(rg);

	if(t == NULL)
	return printColorful("Inquilino não encontrado.\n", 1);

	printTenant(*t);
}

int isTenantAssociatedToContract(int tenantId, int contractId){
    Contract *c = findContractById(contractId);
    
    if(c->tenantId != tenantId){
        return 0;
    }
    
    return 1;
}

void changeTenantStatus(char rg[], int status){
	if(!tenantExistsByRg(rg)){
		return printColorful("Inquilino não encontrado.\n", 1);
	}

	Tenant *t = findTenantByRg(rg);
	t->tenantStatus = status;
    saveTenantsData();
	printColorful("Inquilino atualizado com sucesso!\n", 2);
}

void changeTenantPhone(int tenantId, char newPhone[]){
    if(findTenantById(tenantId) == NULL){
		return printColorful("Inquilino não encontrado.\n", 1);
	}

	Tenant *t = findTenantById(tenantId);
	strcpy(t->phone, newPhone);
    saveTenantsData();

	printColorful("Inquilino atualizado com sucesso!\n", 2);
}

int tenantHasContract(int tenantId){
    for (int ii = 0; ii < registeredContractsNumber; ii++){
        if(contracts[ii].tenantId == tenantId){
            return 1;
        }
    }
    
    return 0;
}