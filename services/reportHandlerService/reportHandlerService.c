#include <stdio.h>
#include <stdlib.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/Contract/Contract.h"

void generateContractsReport(Contract *selectedContracts, int itemsAmount){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/reports/contracts_report.txt", "w");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao gerar relatório de contratos.\n", 1);
        return;
    }
    
    fprintf(ptrArq, "=== Relatório de Contratos - Filtrado por Data Inicial: %s  ===\n", "teste 23/03/2025");
    
    for (int ii = 0; ii < itemsAmount; ii++){
        fprintf(ptrArq, "\nCódigo: %d\n", selectedContracts[ii].id);
        fprintf(ptrArq, "Contract Start Date: %s\n", selectedContracts[ii].contractStartDate);
        fprintf(ptrArq, "Contract End Date: %s\n", selectedContracts[ii].contractEndDate);
        fprintf(ptrArq, "Default Rental Value: %.2f\n", selectedContracts[ii].defaultRentalValue);
        fprintf(ptrArq, "Invoice Due Date: %d\n", selectedContracts[ii].invoiceDueDate);
        fprintf(ptrArq, "Contract Status: %d\n", selectedContracts[ii].contractStatus);
        fprintf(ptrArq, "Tenant Status: %d\n", selectedContracts[ii].tenant.tenantStatus);
        fprintf(ptrArq, "Tenant RG: %s\n", selectedContracts[ii].tenant.rg);
        fprintf(ptrArq, "Residence ID: %d\n", selectedContracts[ii].residence.id);
        // fprintf(ptrArq, "Residence Address: %s\n", selectedContracts[ii].residence.id);
        fprintf(ptrArq, "-----------------------------\n");
    }
    
    printColorful("\nRelatório de contratos gerado com sucesso!\n\n", 2);
    
    fclose(ptrArq);
}