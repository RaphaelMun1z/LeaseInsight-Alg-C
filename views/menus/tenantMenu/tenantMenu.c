#include <stdio.h>
#include <string.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../utils/printColorful/printColorful.h"

// Entities
#include "../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"
#include "../../../services/contractService/contractService.h"
#include "../../../services/tenantService/tenantService.h"

int tenantMenu(){
    int option;
    do{
        char message[100], name[100];
        (getAuthUserName() != NULL) ? strcpy(name, getAuthUserName()) : strcpy(name, "Não foi possível carregar.");
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", name);
        printColorful(message, 3);
        printColorful("1 -> Sair da minha conta.\n", 6);
        printColorful("2 -> Acessar meus dados.\n", 5);
        printColorful("3 -> Acessar meus contratos.\n", 5);
        printColorful("4 -> Acessar detalhes de um contrato pelo código.\n", 5);
        printColorful("5 -> Cancelar um contrato.\n", 5);
        printColorful("6 -> Atualizar meu telefone.\n", 5);
        
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

void tenantMenuChoose(){
    switch (tenantMenu())
    {  
        case 1:
        logoutAuthUser();
        break;
        
        case 2:
        printTenant(*findTenantById(authUser->id));
        tenantMenuChoose();
        break;
        
        case 3:
        findContractsByTenant(authUser->id);
        tenantMenuChoose();
        break;
        
        case 4: {
            int contractId;
            printColorful("Informe o código do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                tenantMenuChoose();
                return;
            }
            
            if(!isTenantAssociatedToContract(authUser->id, contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                tenantMenuChoose();
                return;
            }
            
            printContractById(contractId);
            tenantMenuChoose();
            break;
        }
        
        case 5: {
            int contractId;
            printColorful("Informe o código do contrato: ", 3);
            scanf("%d", &contractId);
            
            if(!contractExistsById(contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                tenantMenuChoose();
                return;
            }
            
            if(!isTenantAssociatedToContract(authUser->id, contractId)){
                printColorful("Contrato não encontrado.\n\n", 1);
                tenantMenuChoose();
                return;
            }
            
            deleteContract(contractId);
            tenantMenuChoose();
            break;
        }
        
        case 6: {
            char newPhone[16];
            do {
                cleanInputBuffer();
                printColorful("Novo Telefone para contato (Ex.: (13) 91234-5678): ", 5);
                fgets(newPhone, 16, stdin);
                newPhone[strcspn(newPhone, "\n")] = 0;
                
                if(newPhone[0] == '\0'){
                    cleanScreen();
                    printColorful("\nO Campo 'Telefone' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (newPhone[0] == '\0');
            
            changeTenantPhone(authUser->id, newPhone);
            tenantMenuChoose();
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}