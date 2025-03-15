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

void cleanInputBuffer() {
    while (getchar() != '\n');
}

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

void startScreen(){
    system("figlet LeaseInsight");
    printColorful("Administração de locação de imóveis\n", 5);
    printColorful("Copyright © 2025 LeaseInsight. Todos os direitos reservados.\n", 5);
    printColorful("Desenvolvido por: Raphael e Ygor\n\n", 5);
}

int mainMenu(){
    int option;
    do{
        printColorful("Como posso ajudar? \n", 3);
        printColorful("1 -> Gostaria de me registrar.\n", 5);
        printColorful("2 -> Gostaria de acessar o sistema.\n", 5);
        printColorful("3 -> Gostaria de sair do sistema.\n", 5);
        printColorful("Sua resposta: ", 0);
        scanf("%d", &option);
        
        if(option < 1 || option > 3){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        }
    } while(option < 1 || option > 3);
    return option;
}

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

void signInForm(){
    char email[100], password[100];
    printColorful("\nOlá, preencha os campos a seguir para acessar o sistema.\n", 3);
    printColorful("E-mail: ", 5);
    fgets(email, 100, stdin);
    
    printColorful("Senha: ", 5);
    fgets(password, 100, stdin);
}

int main(){
    /* Tenant *tenants = (Tenant *) calloc(5, sizeof(Tenant));
    Residence *residences = (Residence *) calloc(5, sizeof(Residence));
    Contract *contracts = (Contract *) calloc(5, sizeof(Contract)); */
    
    cleanScreen();
    startScreen();
    
    printColorful("Seja bem-vindo(a)!\n\n", 2);
    
    switch (mainMenu())
    {
        case 1:
        registerForm();
        break;
        
        case 2:
        signInForm();
        break;
        
        case 3:
        printColorful("\nAté mais!\n", 0);
        printColorful("Saindo...", 1);
        break;
        
        default:
        break;
    }
    
    return 0;
}