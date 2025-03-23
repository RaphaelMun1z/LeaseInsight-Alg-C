#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// DTOs
#include "../../dtos/dtos.h"

// Entities
#include "../../entities/Contract/Contract.h"

void generateContractsReport(Contract *selectedContracts, int itemsAmount, char dateFiltered[]){
    FILE *ptrArq;
    
    ptrArq = fopen("resources/reports/contracts_report.txt", "w");
    
    if(ptrArq == NULL){
        printColorful("Ocorreu um erro ao gerar relatório de contratos.\n", 1);
        return;
    }
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char currentDateTime[100];
    strftime(currentDateTime, sizeof(currentDateTime)-1, "%Y-%m-%d %H:%M:%S", t);
    
    fprintf(ptrArq, "======================================\n");
    fprintf(ptrArq, "===========  ");
    fprintf(ptrArq, "LEASEINSIGHT");
    fprintf(ptrArq, "  ===========\n");
    fprintf(ptrArq, "======================================\n");
    fprintf(ptrArq, "\nAdministração de locação de imóveis\n");
    fprintf(ptrArq, "Copyright © 2025 LeaseInsight. Todos os direitos reservados.\n");
    fprintf(ptrArq, "Desenvolvido por: Raphael e Ygor\n\n");

    fprintf(ptrArq, "Relatório de Contratos\n");
    fprintf(ptrArq, "Filtrado por Data Inicial: %s\n", dateFiltered);
    fprintf(ptrArq, "Data e Hora da Criação do Relatório: %s\n", currentDateTime);
    fprintf(ptrArq, "___________________________________________________________\n");
        
    for (int ii = 0; ii < itemsAmount; ii++){
        fprintf(ptrArq, "\nCódigo: %d\n", selectedContracts[ii].id);
        fprintf(ptrArq, "Início do contrato: %s\n", selectedContracts[ii].contractStartDate);
        fprintf(ptrArq, "Fim do contrato: %s\n", selectedContracts[ii].contractEndDate);
        fprintf(ptrArq, "Valor de locação: %.2f\n", selectedContracts[ii].defaultRentalValue);
        fprintf(ptrArq, "Invoice Due Date: %d\n", selectedContracts[ii].invoiceDueDate);
        fprintf(ptrArq, "Contract Status: %d\n", selectedContracts[ii].contractStatus);
        fprintf(ptrArq, "Tenant Status: %d\n", selectedContracts[ii].tenant.tenantStatus);
        fprintf(ptrArq, "Tenant RG: %s\n", selectedContracts[ii].tenant.rg);
        fprintf(ptrArq, "Residence ID: %d\n", selectedContracts[ii].residence.id);
        // fprintf(ptrArq, "Residence Address: %s\n", selectedContracts[ii].residence.id);
        fprintf(ptrArq, "___\n");
    }
    
    printColorful("\nRelatório de contratos gerado com sucesso!\n\n", 2);
    
    fclose(ptrArq);
}