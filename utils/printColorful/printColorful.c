#include <stdio.h>

void printColorful(char text[], int color) {    
    switch (color)
    {
        case 1:
        printf("\033[31m%s\033[0m", text); // Red
        break;
        
        case 2:
        printf("\033[32m%s\033[0m", text); // Green
        break;
        
        case 3:
        printf("\033[1;34m%s\033[0m", text); // Blue
        break;
        
        case 4:
        printf("\033[33m%s\033[0m", text); // Yellow
        break;
        
        case 5:
        printf("\033[90m%s\033[0m", text); // Gray
        break;
        
        default:
        printf("%s", text);
        break;
    }
}