#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/cleanScreen/cleanScreen.h"
#include "../../utils/cancelOperation/cancelOperation.h"

// Entities
#include "../../entities/AuthUser/AuthUser.h"

// Services
#include "../../services/residenceService/residenceService.h"

void updateResidenceForm(double *newRentalValue, int *newOccupancyStatus, int *changeAddress, Address *newAddress){
    Residence newResidence;
    
    do {
        printColorful("\n[DICA] Para pular esse atributo, digite: '-1'.\n", 5);
        cleanInputBuffer();
        printColorful("Novo Valor de aluguel: ", 5);
        scanf("%lf", newRentalValue);

        if(*newRentalValue <= 0 && *newRentalValue != -1){
            cleanScreen();
            printColorful("\nO Campo 'Valor de aluguel' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (*newRentalValue <= 0 && *newRentalValue != -1);
    
    do {
        printColorful("\n[DICA] Para pular esse atributo, digite: '-1'.\n", 5);
        cleanInputBuffer();
        printColorful("Status [1 - Ocupado | 2 - Livre | 3 - Saída pendente]: ", 5);
        scanf("%d", newOccupancyStatus);
        
        if((*newOccupancyStatus < 1 || *newOccupancyStatus > 3) && *newRentalValue != -1){
            cleanScreen();
            printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while ((*newOccupancyStatus < 1 || *newOccupancyStatus > 3) && *newRentalValue != -1);

    do {
        cleanInputBuffer();
        printColorful("Gostaria de alterar o endereço? [1 - Sim | 0 - Não]: ", 5);
        scanf("%d", changeAddress);
        
        if(*changeAddress < 0 || *changeAddress > 1){
            cleanScreen();
            printColorful("\nO Campo é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (*changeAddress < 0 || *changeAddress > 1);

    if(*changeAddress == 0){
        return;
    }

    printColorful("Novo endereço: \n", 5);
    
    do {
        cleanInputBuffer();
        printColorful("Logradouro: ", 5);
        fgets(newAddress->street, 100, stdin);
        newAddress->street[strcspn(newAddress->street, "\n")] = 0;
        
        if(newAddress->street[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Logradouro' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newAddress->street[0] == '\0');
    
    do {
        cleanInputBuffer();
        printColorful("Número: ", 5);
        scanf("%d", &newAddress->number);
                
        if(newAddress->number < 1){
            cleanScreen();
            printColorful("\nO Campo 'Número' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newAddress->number < 1);
    
    cleanInputBuffer();
    printColorful("Complemento: ", 5);
    fgets(newAddress->complement, 100, stdin);
    newAddress->complement[strcspn(newAddress->complement, "\n")] = 0;

    do {
        cleanInputBuffer();
        printColorful("Bairro: ", 5);
        fgets(newAddress->district, 100, stdin);
        newAddress->district[strcspn(newAddress->district, "\n")] = 0;
                
        if(newAddress->district[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Bairro' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newAddress->district[0] == '\0');
    
    do {
        cleanInputBuffer();
        printColorful("Cidade: ", 5);
        fgets(newAddress->city, 100, stdin);
        newAddress->city[strcspn(newAddress->city, "\n")] = 0;
                
        if(newAddress->city[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Cidade' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newAddress->city[0] == '\0');

    do {
        cleanInputBuffer();
        printColorful("Estado: ", 5);
        fgets(newAddress->state, 100, stdin);
        newAddress->state[strcspn(newAddress->state, "\n")] = 0;
                
        if(newAddress->state[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Estado' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newAddress->state[0] == '\0');

    do {
        cleanInputBuffer();
        printColorful("CEP (Ex.: 38500-000): ", 5);
        fgets(newAddress->cep, 100, stdin);
        newAddress->cep[strcspn(newAddress->cep, "\n")] = 0;
                
        if(newAddress->cep[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'CEP' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newAddress->cep[0] == '\0');
}