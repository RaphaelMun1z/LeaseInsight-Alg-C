#include <stdio.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"

void signInForm(){
    char email[100], password[100];
    cleanInputBuffer();
    printColorful("\nOlá, preencha os campos a seguir para acessar o sistema.\n", 3);
    
    printColorful("E-mail: ", 5);
    fgets(email, 100, stdin);
    
    printColorful("Senha: ", 5);
    fgets(password, 100, stdin);
}