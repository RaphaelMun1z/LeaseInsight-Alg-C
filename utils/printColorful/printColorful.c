#include <stdio.h>

void printColorful(char text[], int color) {    
    switch (color)
    {
        case 1:
        printf("\033[31m%s\033[0m", text); // Vermelho
        break;
        
        case 2:
        printf("\033[32m%s\033[0m", text); // Verde
        break;
        
        case 3:
        printf("\033[1;34m%s\033[0m", text); // Azul
        break;
        
        case 4:
        printf("\033[33m%s\033[0m", text); // Amarelo
        break;
        
        case 5:
        printf("\033[90m%s\033[0m", text); // Cinza
        break;

        case 6:
        printf("\033[38;5;208m%s\033[0m", text); // Laranja
        break;
        
        default:
        printf("%s", text);
        break;
    }
}