#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/cleanScreen/cleanScreen.h"

// Services
#include "../../services/tenantService/tenantService.h"

void registerTenantForm(){
    Tenant newTenant;
    char password[100], confirmPassword[100];

    printColorful("\nPreencha os campos a seguir para registrar-se.\n", 3);

    cleanInputBuffer();
    printColorful("Nome Completo: ", 5);
    fgets(newTenant.name, 100, stdin);
    newTenant.name[strcspn(newTenant.name, "\n")] = 0;
    
    cleanInputBuffer();
    printColorful("Telefone para contato (Ex.: (13) 91234-5678): ", 5);
    fgets(newTenant.phone, 16, stdin);
    newTenant.phone[strcspn(newTenant.phone, "\n")] = 0;
    
    cleanInputBuffer();
    printColorful("E-mail (Ex.: inquilino@gmail.com): ", 5);
    fgets(newTenant.email, 255, stdin);
    newTenant.email[strcspn(newTenant.email, "\n")] = 0;

    cleanInputBuffer();
    printColorful("RG (Ex.: 11.111.111-1): ", 5);
    fgets(newTenant.rg, 13, stdin);
    newTenant.rg[strcspn(newTenant.rg, "\n")] = 0;

    cleanInputBuffer();
    printColorful("CPF (Ex.: 111.111.111-11): ", 5);
    fgets(newTenant.cpf, 15, stdin);
    newTenant.cpf[strcspn(newTenant.cpf, "\n")] = 0;

    cleanInputBuffer();
    printColorful("Data de Nascimento (Ex.: 01/01/2001: ", 5);
    fgets(newTenant.dateOfBirth, 11, stdin);
    newTenant.dateOfBirth[strcspn(newTenant.dateOfBirth, "\n")] = 0;
    
    do {
        cleanInputBuffer();
        printColorful("Senha: ", 5);
        fgets(password, 100, stdin);
        
        cleanInputBuffer();
        printColorful("Confirme a Senha: ", 5);
        fgets(confirmPassword, 100, stdin);

        if(strcmp(password, confirmPassword) != 0){
            cleanScreen();
            printColorful("\nAs senhas não coincidem. Informe novamente.\n\n", 4);
        }
    } while(strcmp(password, confirmPassword) != 0);
    strcpy(newTenant.password, password);
    newTenant.password[strcspn(newTenant.password, "\n")] = 0;

    cleanScreen();
    createTenant(newTenant);
}