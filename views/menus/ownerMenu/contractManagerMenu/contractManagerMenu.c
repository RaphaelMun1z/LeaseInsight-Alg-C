#include <stdio.h>
#include <conio.h>
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
        
        option = getch();
        option -= '0';
        
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
        break;
        
        case 2:
        registerContractForm();
        break;
        
        case 3: {
            double contractId;
            printColorful("Informe o ID do contrato: ", 3);
            scanf("%lf", &contractId);
            printContractById(contractId);
            break;
        }
        
        case 4:
        printf("Opção 4\n");
        // Opção 4
        break;
        
        case 5:
        printf("Opção 5\n");
        // Opção 5
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}