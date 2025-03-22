#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../../utils/printColorful/printColorful.h"
#include "../../../../../utils/cleanInputBuffer/cleanInputBuffer.h"

// Entities
#include "../../../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../../services/tenantService/tenantService.h"

int tenantManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando inquilinos. Você pode: \n", 3);
        printColorful("1 -> Acessar todos inquilinos.\n", 5);
        printColorful("2 -> Acessar detalhes de uma inquilino.\n", 5);
        printColorful("3 -> Alterar um inquilino.\n", 5);
        printColorful("4 -> Remover um inquilino.\n", 5);
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

void tenantManagerMenuChoose(){
    switch (tenantManagerMenu())
    {
        case 1:
        findAllTenants();
        tenantManagerMenuChoose();
        break;
        
        case 2: {
            char tenantRg[100];
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;
            
            Tenant *t = findTenantByRg(tenantRg);
            
            if(t == NULL){
                printColorful("Inquilino não encontrado.\n\n", 1);
                tenantManagerMenuChoose();
                return;
            }
            
            printTenantByRg(tenantRg);
            tenantManagerMenuChoose();
            break;
        }
        
        case 3: {
            char tenantRg[100];
            int tenantStatus;
            
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;
            
            if(!tenantExistsByRg(tenantRg)){
                printColorful("Inquilino não encontrado.\n\n", 1);
                tenantManagerMenuChoose();
                return;
            }
            
            printColorful("Informe o novo status [1 - Ativo | 2 - Inativo | 3 - Suspenso]: ", 3);
            scanf("%d", &tenantStatus);
            
            changeTenantStatus(tenantRg, tenantStatus);
            tenantManagerMenuChoose();
            break;
        }
        
        case 4:{
            char tenantRg[100];
            
            cleanInputBuffer();
            printColorful("Informe o RG do inquilino: ", 3);
            fgets(tenantRg, 13, stdin);
            tenantRg[strcspn(tenantRg, "\n")] = 0;

            if(!tenantExistsByRg(tenantRg)){
                printColorful("Inquilino não encontrado.\n\n", 1);
                tenantManagerMenuChoose();
                return;
            }
            
            deleteTenant(tenantRg);
            tenantManagerMenuChoose();
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