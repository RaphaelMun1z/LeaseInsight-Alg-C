#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

int tenantMenu(){
    int option;
    do{
        char message[100], name[100];
        (getAuthUserName() != NULL) ? strcpy(name, getAuthUserName()) : strcpy(name, "Não foi possível carregar.");
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", name);
        printColorful(message, 3);
        printColorful("1 -> Gostaria de acessar meus contratos.\n", 5);
        printColorful("2 -> Gostaria de acessar detalhes de um contrato.\n", 5);
        printColorful("3 -> Gostaria de cancelar um contrato.\n", 5);
        printColorful("4 -> Gostaria de sair da minha conta.\n", 1);
        
        option = getch();
        option -= '0';
        
        if(option < 1 || option > 4){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 4);
    cleanScreen();
    return option;
}

void tenantMenuChoose(){
    switch (tenantMenu())
    {
        case 1:
        printf("Opção 1\n");
        // Opção 1
        break;
        
        case 2:
        printf("Opção 2\n");
        // Opção 2
        break;

        case 3:
        printf("Opção 3\n");
        // Opção 3
        break;
        
        case 4:
        logoutAuthUser();
        break;
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}