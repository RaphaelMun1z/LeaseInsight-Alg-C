#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/cleanScreen/cleanScreen.h"

// Services
#include "../../services/authService/authService.h"

void signInForm(){
    LoginCredentials credentials;

    printColorful("\nOlá, preencha os campos a seguir para acessar o sistema.\n", 3);
    
    do{
        cleanInputBuffer();
        printColorful("E-mail: ", 5);
        fgets(credentials.email, 13, stdin);
        credentials.email[strcspn(credentials.email, "\n")] = 0;
        
        if(credentials.email[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'E-mail' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (credentials.email[0] == '\0');
    
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
    signInUser(credentials);
}