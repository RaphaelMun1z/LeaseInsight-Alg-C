#include <stdio.h>
#include <stdlib.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/Tenant/Tenant.h"

void saveTenantsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/tenants_data.bin", "wb");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao salvar inquilinos!\n", 1);
        system("pause");
        exit(1);
        return;
    }
    
    fwrite(tenants, sizeof(Tenant), registeredTenantsNumber, ptrArq);
    fclose(ptrArq);
}

void getTenantsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/tenants_data.bin", "rb");
    
    if(ptrArq == NULL){
        fclose(ptrArq);
        initTenants();
        return;
    }
    
    fseek(ptrArq, 0, SEEK_END);
    long fileSize = ftell(ptrArq);
    rewind(ptrArq);
    
    int numTenants = fileSize / sizeof(Tenant);
    
    if (numTenants <= 0) {
        fclose(ptrArq);
        initTenants();
        return;
    }
    
    allocateSpaceTenantForFile(numTenants);
    
    fread(tenants, sizeof(Tenant), numTenants, ptrArq);
    
    fclose(ptrArq);
}