#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../../utils/printColorful/printColorful.h"
#include "../../../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../../../utils/enums/enums.h"

// Services
#include "../../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../../services/tenantService/tenantService.h"

int tenantManagerAdmMenu(){
    int option;
    do{
        printColorful("Gerenciando inquilinos. Você pode: \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Acessar todos inquilinos.\n", 5);
        printColorful("3 -> Acessar detalhes de uma inquilino.\n", 5);
        printColorful("4 -> Alterar um inquilino.\n", 5);
        printColorful("5 -> Remover um inquilino.\n", 5);
        
        printColorful("Escolha uma opção: ", 5);
        scanf("%d", &option);
        
        if(option < 1 || option > 5){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 5);
    cleanScreen();
    return option;
}

void tenantManagerAdmMenuChoose(){
    switch (tenantManagerAdmMenu())
    {
        case 1: {
            break;
        }

        case 2:
        findAllTenants();
        tenantManagerAdmMenuChoose();
        break;
        
        case 3: {
            char tenantRg[100];
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;
            
            Tenant *t = findTenantByRg(tenantRg);
            
            if(t == NULL){
                printColorful("Inquilino não encontrado.\n\n", 1);
                tenantManagerAdmMenuChoose();
                return;
            }
            
            printTenantByRg(tenantRg);
            tenantManagerAdmMenuChoose();
            break;
        }
        
        case 4: {
            char tenantRg[100];
            int tenantStatus;
            
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;
            
            if(!tenantExistsByRg(tenantRg)){
                printColorful("Inquilino não encontrado.\n\n", 1);
                tenantManagerAdmMenuChoose();
                return;
            }
            
            do {
                printColorful("\n[DICA] Para pular esse atributo, digite: '-1'.\n", 5);
                cleanInputBuffer();
                getTenantStatusOptions();
                scanf("%d", &tenantStatus);
                
                if((tenantStatus < 1 || tenantStatus > 3) && tenantStatus != -1){
                    cleanScreen();
                    printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while ((tenantStatus < 1 || tenantStatus > 3) && tenantStatus != -1);
            
            changeTenantStatus(tenantRg, tenantStatus);
            tenantManagerAdmMenuChoose();
            break;
        }
        
        case 5:{
            char tenantRg[100];
            
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;

            if(!tenantExistsByRg(tenantRg)){
                printColorful("Inquilino não encontrado.\n\n", 1);
                tenantManagerAdmMenuChoose();
                return;
            }
            
            cleanInputBuffer();
            deleteTenant(tenantRg);
            tenantManagerAdmMenuChoose();
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}