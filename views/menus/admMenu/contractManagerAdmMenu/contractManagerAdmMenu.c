#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../../utils/enums/enums.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../../services/reportHandlerService/reportHandlerService.h"
#include "../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../services/contractService/contractService.h"
#include "../../../../services/tenantService/tenantService.h"

int contractManagerAdmMenu(){
    int option;
    do{
        printColorful("Gerenciando contratos. Você pode: \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Acessar todos contratos.\n", 5);
        printColorful("3 -> Acessar detalhes de um contrato pelo código.\n", 5);
        printColorful("4 -> Acessar detalhes de um contrato pelo Status.\n", 5);
        printColorful("5 -> Acessar contratos pelo RG do Inquilino.\n", 5);
        printColorful("6 -> Gerar relatório de contratos por Data Inicial.\n", 5);
        printColorful("7 -> Gerar relatório de contratos por Data de Fim.\n", 5);
        printColorful("8 -> Alterar um contrato.\n", 5);
        printColorful("9 -> Remover um contrato.\n", 5);
        
        printColorful("Escolha uma opção: ", 5);
        scanf("%d", &option);
        
        if(option < 1 || option > 9){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 9);
    cleanScreen();
    return option;
}

void contractManagerAdmMenuChoose(){
    switch (contractManagerAdmMenu())
    {
        case 1: {
            break;
        }

        case 2:
        findAllContracts();
        contractManagerAdmMenuChoose();
        break;
        
        case 3:{
            int contractId;
            printColorful("Informe o código do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            printContractById(contractId);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 4:{
            int contractStatus;
            
            do {
                cleanInputBuffer();
                getContractStatusOptions();
                scanf("%d", &contractStatus);
                
                if(contractStatus < 1 || contractStatus > 12){
                    cleanScreen();
                    printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (contractStatus < 1 || contractStatus > 12);
            
            findContractsByStatus(contractStatus);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 5:{
            char tenantRg[100];
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;
            
            Tenant *t = findTenantByRg(tenantRg);
            
            if(t == NULL){
                printColorful("Inquilino não encontrado.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            cleanInputBuffer();
            findContractsByTenantRg(tenantRg);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 6:{
            char startDate[11];
            
            cleanInputBuffer();
            printColorful("Informe a data inicial do contrato: ", 3);
            fgets(startDate, 11, stdin);
            startDate[strcspn(startDate, "\n")] = 0;

            int contractsAmount = getContractsAmountByStartDate(startDate);

            if(contractsAmount == 0){
                printColorful("Não foram encontrados contratos.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            Contract *foundContracts = calloc(contractsAmount, sizeof(Contract));
            findContractsByStartDate(startDate, foundContracts);

            char reportTitle[50];
            sprintf(reportTitle, "Data: %s", startDate);
            generateContractsReport(foundContracts, contractsAmount, reportTitle, "contracts_by_start_date_report");
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 7:{
            char endDate[11];
            
            cleanInputBuffer();
            printColorful("Informe a data final do contrato: ", 3);
            fgets(endDate, 11, stdin);
            endDate[strcspn(endDate, "\n")] = 0;

            int contractsAmount = getContractsAmountByEndDate(endDate);

            if(contractsAmount == 0){
                printColorful("Não foram encontrados contratos.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            Contract *foundContracts = calloc(contractsAmount, sizeof(Contract));
            findContractsByEndDate(endDate, foundContracts);

            char reportTitle[50];
            sprintf(reportTitle, "Data: %s", endDate);
            generateContractsReport(foundContracts, contractsAmount, reportTitle, "contracts_by_end_date_report");
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 8:{
            int contractId;
            int contractStatus;
            
            printColorful("Informe o código do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            do {
                cleanInputBuffer();
                getContractStatusOptions();
                scanf("%d", &contractStatus);
                
                if(contractStatus < 1 || contractStatus > 12){
                    cleanScreen();
                    printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (contractStatus < 1 || contractStatus > 12);
            
            changeContractStatus(contractId, contractStatus);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 9: {
            int contractId;
            printColorful("Informe o código do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            deleteContract(contractId);
            contractManagerAdmMenuChoose();
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}