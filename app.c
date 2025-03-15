#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char rg[13]; // PK
    char cpf[15];
    int tenantStatus;
    char dateOfBirth[11]; 
    char registrationDate[11];
} Tenant;

typedef struct {
    double id; // PK
    int propertyType;
    int occupancyStatus;
    char description[255];
    double marketValue;
    double rentalValue;
    double totalArea;
    double builtArea;
    int aptNumber;
    int numberBedrooms;
    int numberBathrooms;
    int numberSuites;
    int garageSpaces;
    int yearConstruction;
    char complement[100];
    char dateLastRenovation[11];
} Residence;

typedef struct {
    double id;
    int contractStatus;
    double defaultRentalValue;
    int invoiceDueDate;
    char contractStartDate[11];
    char contractEndDate[11];
} Contract;

void cleanScreen(){
    system("cls");
}

void startScreen(){
    system("figlet LeaseInsight");
    printColorful("Administração de locação de imóveis", 5);
    printColorful("Copyright © 2025 LeaseInsight. Todos os direitos reservados.", 5);
    printColorful("Desenvolvido por: Raphael e Ygor\n\n", 5);
}

void printColorful(char text[], int color) {    
    switch (color)
    {
        case 1:
        printf("\033[31m%s\033[0m\n", text); // Red
        break;
        
        case 2:
        printf("\033[32m%s\033[0m\n", text); // Green
        break;
        
        case 3:
        printf("\033[1;34m%s\033[0m\n", text); // Blue
        break;
        
        case 4:
        printf("\033[33m%s\033[0m\n", text); // Yellow
        break;
        
        case 5:
        printf("\033[90m%s\033[0m\n", text); // Gray
        break;
        
        default:
        printf("%s\n", text);
        break;
    }
}

void mainMenu(){
    printColorful("Seja bem-vindo(a), como posso ajudar? ", 3);
    printColorful("Exemplo de texto", 2);
    printColorful("Exemplo de texto", 3);
}

int main(){
    Tenant *tenants = (Tenant *) calloc(5, sizeof(Tenant));
    Residence *residences = (Residence *) calloc(5, sizeof(Residence));
    Contract *contracts = (Contract *) calloc(5, sizeof(Contract));
    
    cleanScreen();
    startScreen();
    
    mainMenu();
    
    return 0;
}