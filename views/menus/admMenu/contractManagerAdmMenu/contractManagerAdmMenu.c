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
#include "../../../../services/ContractService/ContractService.h"

int contractManagerAdmMenu(){
    int option;
    do{
        printColorful("Gerenciando contratos. Você pode: \n", 3);
        printColorful("1 -> Acessar todos contratos.\n", 5);
        printColorful("2 -> Acessar detalhes de um contrato.\n", 5);
        printColorful("3 -> Alterar um contrato.\n", 5);
        printColorful("4 -> Remover um contrato.\n", 5);
        printColorful("5 -> Voltar.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 5){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 5);
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
            double contractId;
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%lf", &contractId);
            
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
            double contractId;
            int contractStatus;
            
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%lf", &contractId);
            
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
        
        case 4: {
            double contractId;
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%lf", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerAdmMenuChoose();
                return;
            }
            
            deleteContract(contractId);
            contractManagerAdmMenuChoose();
            break;
        }
        
        case 5: {
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}