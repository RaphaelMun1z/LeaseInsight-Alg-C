#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/cleanScreen/cleanScreen.h"

void registerForm(){
    char nome[100], phone[16], email[100], password[100], confirmPassword[100];    
    cleanInputBuffer();
    printColorful("\nPreencha os campos a seguir para registrar-se.\n", 3);
    
    printColorful("Nome Completo: ", 5);
    fgets(nome, 100, stdin);
    
    printColorful("Telefone para contato (Ex.: (12) 91234-5678): ", 5);
    fgets(phone, 100, stdin);
    
    printColorful("E-mail: ", 5);
    fgets(email, 100, stdin);
    
    do {
        printColorful("Senha: ", 5);
        fgets(password, 100, stdin);
        
        printColorful("Confirme a Senha: ", 5);
        fgets(confirmPassword, 100, stdin);

        if(strcmp(password, confirmPassword) != 0){
            cleanScreen();
            printColorful("\nAs senhas não coincidem. Informe novamente.\n\n", 4);
        }
    } while(strcmp(password, confirmPassword) != 0);
}