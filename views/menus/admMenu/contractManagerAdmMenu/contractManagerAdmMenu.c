#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../services/contractService/contractService.h"
#include "../../../../services/tenantService/tenantService.h"

int contractManagerAdmMenu(){
    int option;
    do{
        printColorful("Gerenciando contratos. Você pode: \n", 3);
        printColorful("1 -> Acessar todos contratos.\n", 5);
        printColorful("2 -> Acessar detalhes de um contrato pelo ID.\n", 5);
        printColorful("3 -> Acessar detalhes de um contrato pelo Status.\n", 5);
        printColorful("4 -> Acessar contratos pelo RG do Inquilino.\n", 5);
        printColorful("5 -> Alterar um contrato.\n", 5);
        printColorful("6 -> Remover um contrato.\n", 5);
        printColorful("7 -> Voltar.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 7){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 7);
    cleanScreen();
    return option;
}

void contractManagerAdmMenuChoose(){
    switch (contractManagerAdmMenu())
    {
        case 1:
        findAllContracts();
        contractManagerAdmMenuChoose();
        break;
        
        case 2:{
            int contractId;
            printColorful("Informe o ID do contrato: ", 3);
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

        case 3:{
            int contractStatus;

            do {
                cleanInputBuffer();
                printColorful("Status [1 - Ativo | 2 - Inativo | 3 - Pré-aprovado]: ", 5);
                scanf("%d", &contractStatus);
                
                if(contractStatus < 1 || contractStatus > 3){
                    cleanScreen();
                    printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (contractStatus < 1 || contractStatus > 3);
            
            findContractsByStatus(contractStatus);
            contractManagerAdmMenuChoose();
            break;
        }

        case 4:{
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
            
            findContractsByTenantRg(tenantRg);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 5:{
            int contractId;
            int contractStatus;
            
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            do {
                cleanInputBuffer();
                printColorful("Status [1 - Ativo | 2 - Inativo | 3 - Pré-aprovado]: ", 5);
                scanf("%d", &contractStatus);
                
                if(contractStatus < 1 || contractStatus > 3){
                    cleanScreen();
                    printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (contractStatus < 1 || contractStatus > 3);
            
            changeContractStatus(contractId, contractStatus);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 6: {
            int contractId;
            printColorful("Informe o ID do contrato: ", 3);
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
        
        case 7: {
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}