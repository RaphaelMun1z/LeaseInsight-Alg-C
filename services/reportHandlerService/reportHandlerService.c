#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Utils
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/enums/enums.h"

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
        fprintf(ptrArq, "Vencimento da mensalidade - dia do mês: %d\n", selectedContracts[ii].invoiceDueDate);

        char contractStatusStr[100];
        getContractStatus(selectedContracts[ii].contractStatus, contractStatusStr);
        fprintf(ptrArq, "Status do contrato: %s\n", contractStatusStr);

        fprintf(ptrArq, "Informações do inquilino:\n");
        fprintf(ptrArq, "\tCódigo do inquilino: %d\n", selectedContracts[ii].tenant.id);
        fprintf(ptrArq, "\tNome do inquilino: %s\n", selectedContracts[ii].tenant.name);
        fprintf(ptrArq, "\tRG do inquilino: %s\n", selectedContracts[ii].tenant.rg);
        fprintf(ptrArq, "\tE-mail do inquilino: %s\n", selectedContracts[ii].tenant.email);
        
        char tenantStatusStr[100];
        getTenantStatus(selectedContracts[ii].tenant.tenantStatus, tenantStatusStr);
        fprintf(ptrArq, "\tStatus do inquilino: %s\n", tenantStatusStr);
        
        fprintf(ptrArq, "Informações da propriedade:\n");
        fprintf(ptrArq, "\tCódigo da propriedade: %d\n", selectedContracts[ii].residence.id);
        fprintf(ptrArq, "\tEndereço da propriedade: %s, %d, %s, %s, %s, %s\n", selectedContracts[ii].residence.address.street, selectedContracts[ii].residence.address.number, selectedContracts[ii].residence.address.complement, selectedContracts[ii].residence.address.district, selectedContracts[ii].residence.address.city, selectedContracts[ii].residence.address.state);
        fprintf(ptrArq, "___\n");
    }
    
    printColorful("\nRelatório de contratos gerado com sucesso!\n\n", 2);
    
    fclose(ptrArq);
}