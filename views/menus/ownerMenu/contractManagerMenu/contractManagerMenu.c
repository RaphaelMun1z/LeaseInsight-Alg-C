#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Controllers
#include "../../../../controllers/registerContractController/registerContractController.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../services/ContractService/ContractService.h"

int contractManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando contratos. Você pode: \n", 3);
        printColorful("1 -> Acessar meus contratos.\n", 5);
        printColorful("2 -> Cadastrar contrato.\n", 5);
        printColorful("3 -> Acessar detalhes de um contrato.\n", 5);
        printColorful("4 -> Alterar um contrato.\n", 5);
        printColorful("5 -> Remover um contrato.\n", 5);
        printColorful("6 -> Voltar.\n", 1);
        
        printColorful("Escolha uma opção: ", 5);
        scanf("%d", &option);
        
        if(option < 1 || option > 6){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 6);
    cleanScreen();
    return option;
}

void contractManagerMenuChoose(){
    switch (contractManagerMenu())
    {
        case 1:
        findContractsByOwner(authUser->id);
        contractManagerMenuChoose();
        break;
        
        case 2:
        registerContractForm();
        contractManagerMenuChoose();
        break;
        
        case 3: {
            double contractId;
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerMenuChoose();
                return;
            }
            
            printContractById(contractId);
            contractManagerMenuChoose();
            break;
        }
        
        case 4:{
            double contractId;
            int contractStatus;
            
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerMenuChoose();
                return;
            }
            
            printColorful("Informe o novo status [1 - Ativo | 2 - Inativo | 3 - Aprovação pendente]: ", 3);
            scanf("%d", &contractStatus);
            
            changeContractStatus(contractId, contractStatus);
            contractManagerMenuChoose();
            break;
        }
        
        case 5: {
            double contractId;
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                contractManagerMenuChoose();
                return;
            }
            
            deleteContract(contractId);
            contractManagerMenuChoose();
            break;
        }
        
        case 6: {
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}