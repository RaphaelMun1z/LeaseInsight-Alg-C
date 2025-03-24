#include <stdio.h>
#include <stdlib.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/Tenant/Tenant.h"
#include "../../entities/Owner/Owner.h"
#include "../../entities/Adm/Adm.h"
#include "../../entities/Contract/Contract.h"
#include "../../entities/Residence/Residence.h"

void saveTenantsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/tenants_data.bin", "wb");
    
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
    
    ptrArq = fopen("resources/data/tenants_data.bin", "rb");
    
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

void saveOwnersData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/owners_data.bin", "wb");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao salvar proprietários!\n", 1);
        system("pause");
        exit(1);
        return;
    }
    
    fwrite(owners, sizeof(Owner), registeredOwnersNumber, ptrArq);
    fclose(ptrArq);
}

void getOwnersData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/owners_data.bin", "rb");
    
    if(ptrArq == NULL){
        fclose(ptrArq);
        initOwners();
        return;
    }
    
    fseek(ptrArq, 0, SEEK_END);
    long fileSize = ftell(ptrArq);
    rewind(ptrArq);
    
    int numOwners = fileSize / sizeof(Owner);
    
    if (numOwners <= 0) {
        fclose(ptrArq);
        initOwners();
        return;
    }
    
    allocateSpaceOwnerForFile(numOwners);
    
    fread(owners, sizeof(Owner), numOwners, ptrArq);
    
    fclose(ptrArq);
}

void saveAdmsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/adms_data.bin", "wb");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao salvar administradores!\n", 1);
        system("pause");
        exit(1);
        return;
    }
    
    fwrite(adms, sizeof(Adm), registeredAdmsNumber, ptrArq);
    fclose(ptrArq);
}

void getAdmsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/adms_data.bin", "rb");
    
    if(ptrArq == NULL){
        fclose(ptrArq);
        initAdms();
        return;
    }
    
    fseek(ptrArq, 0, SEEK_END);
    long fileSize = ftell(ptrArq);
    rewind(ptrArq);
    
    int numAdms = fileSize / sizeof(Adm);
    
    if (numAdms <= 0) {
        fclose(ptrArq);
        initAdms();
        return;
    }
    
    allocateSpaceAdmForFile(numAdms);
    
    fread(adms, sizeof(Adm), numAdms, ptrArq);
    
    fclose(ptrArq);
}

void saveContractsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/contracts_data.bin", "wb");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao salvar contratos!\n", 1);
        system("pause");
        exit(1);
        return;
    }
    
    fwrite(contracts, sizeof(Contract), registeredContractsNumber, ptrArq);
    
    fclose(ptrArq);
}

void getContractsData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/contracts_data.bin", "rb");
    
    if(ptrArq == NULL){
        fclose(ptrArq);
        initContracts();
        return;
    }
    
    fseek(ptrArq, 0, SEEK_END);
    long fileSize = ftell(ptrArq);
    rewind(ptrArq);
    
    int numContracts = fileSize / sizeof(Contract);
    
    if (numContracts <= 0) {
        fclose(ptrArq);
        initContracts();
        return;
    }
    
    allocateSpaceContractForFile(numContracts);
    
    fread(contracts, sizeof(Contract), numContracts, ptrArq);
    
    fclose(ptrArq);
}

void saveResidencesData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/residences_data.bin", "wb");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao salvar propriedades!\n", 1);
        system("pause");
        exit(1);
        return;
    }
    
    fwrite(residences, sizeof(Residence), registeredResidencesNumber, ptrArq);
    fclose(ptrArq);
}

void getResidencesData(){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/data/residences_data.bin", "rb");
    
    if(ptrArq == NULL){
        fclose(ptrArq);
        initResidences();
        return;
    }
    
    fseek(ptrArq, 0, SEEK_END);
    long fileSize = ftell(ptrArq);
    rewind(ptrArq);
    
    int numResidences = fileSize / sizeof(Residence);
    
    if (numResidences <= 0) {
        fclose(ptrArq);
        initResidences();
        return;
    }
    
    allocateSpaceResidenceForFile(numResidences);
    
    fread(residences, sizeof(Residence), numResidences, ptrArq);
    
    fclose(ptrArq);
}