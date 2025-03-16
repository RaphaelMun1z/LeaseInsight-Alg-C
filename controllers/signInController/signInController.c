#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/cleanScreen/cleanScreen.h"

// Services
#include "../../services/tenantService/tenantService.h"

void signInForm(){
    TenantLogin credentials;

    printColorful("\nOlá, preencha os campos a seguir para acessar o sistema.\n", 3);
    
    do{
        cleanInputBuffer();
        printColorful("RG: ", 5);
        fgets(credentials.rg, 13, stdin);
        credentials.rg[strcspn(credentials.rg, "\n")] = 0;
        
        if(credentials.rg[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'RG' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (credentials.rg[0] == '\0');
    
    do{
        cleanInputBuffer();
        printColorful("Senha: ", 5);
        fgets(credentials.password, 100, stdin);
        credentials.password[strcspn(credentials.password, "\n")] = 0;

        if(credentials.password[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Senha' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (credentials.password[0] == '\0');

    cleanScreen();
    signInTenant(credentials);
}