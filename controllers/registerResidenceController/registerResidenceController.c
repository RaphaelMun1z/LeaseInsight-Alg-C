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

void registerResidenceForm(){
    Residence newResidence;

    printColorful("\nPreencha os campos a seguir para registrar a propriedade.", 3);
    printColorful("\n[DICA] Para cancelar operação, digite: 'Sair', ou '-1' em campos numéricos.\n\n", 5);
    
    do {
        cleanInputBuffer();
        printColorful("Valor de aluguel para essa locação: ", 5);
        scanf("%lf", &newResidence.rentalValue);
        
        if(cancelOperationWithInt(newResidence.rentalValue)) return;
        
        if(newResidence.rentalValue <= 0){
            cleanScreen();
            printColorful("\nO Campo 'Valor de aluguel para essa locação' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.rentalValue <= 0);
    
    do {
        cleanInputBuffer();
        printColorful("Tipo de propriedade [1 - Casa | 2 - Apartamento | 3 - Outros]: ", 5);
        scanf("%d", &newResidence.propertyType);
        
        if(cancelOperationWithInt(newResidence.propertyType)) return;
        
        if(newResidence.propertyType < 1 || newResidence.propertyType > 3){
            cleanScreen();
            printColorful("\nO Campo 'Tipo de propriedade' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.propertyType < 1 || newResidence.propertyType > 3);
    
    do {
        cleanInputBuffer();
        printColorful("Status [1 - Ocupado | 2 - Livre | 3 - Saída pendente]: ", 5);
        scanf("%d", &newResidence.occupancyStatus);
        
        if(cancelOperationWithInt(newResidence.occupancyStatus)) return;
        
        if(newResidence.occupancyStatus < 1 || newResidence.occupancyStatus > 3){
            cleanScreen();
            printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.occupancyStatus < 1 || newResidence.occupancyStatus > 3);
    
    printColorful("Endereço: \n", 5);
    
    do {
        cleanInputBuffer();
        printColorful("Logradouro: ", 5);
        fgets(newResidence.address.street, 100, stdin);
        newResidence.address.street[strcspn(newResidence.address.street, "\n")] = 0;
        
        if(cancelOperationWithString(newResidence.address.street)) return;
        
        if(newResidence.address.street[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Logradouro' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.address.street[0] == '\0');
    
    do {
        cleanInputBuffer();
        printColorful("Número: ", 5);
        scanf("%d", &newResidence.address.number);
        
        if(cancelOperationWithInt(newResidence.address.number)) return;
        
        if(newResidence.address.number < 1){
            cleanScreen();
            printColorful("\nO Campo 'Número' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.address.number < 1);
    
    cleanInputBuffer();
    printColorful("Complemento: ", 5);
    fgets(newResidence.address.complement, 100, stdin);
    newResidence.address.complement[strcspn(newResidence.address.complement, "\n")] = 0;
    if(cancelOperationWithString(newResidence.address.complement)) return;

    do {
        cleanInputBuffer();
        printColorful("Bairro: ", 5);
        fgets(newResidence.address.district, 100, stdin);
        newResidence.address.district[strcspn(newResidence.address.district, "\n")] = 0;
        
        if(cancelOperationWithString(newResidence.address.district)) return;
        
        if(newResidence.address.district[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Bairro' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.address.district[0] == '\0');
    
    do {
        cleanInputBuffer();
        printColorful("Cidade: ", 5);
        fgets(newResidence.address.city, 100, stdin);
        newResidence.address.city[strcspn(newResidence.address.city, "\n")] = 0;
        
        if(cancelOperationWithString(newResidence.address.city)) return;
        
        if(newResidence.address.city[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Cidade' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.address.city[0] == '\0');

    do {
        cleanInputBuffer();
        printColorful("Estado: ", 5);
        fgets(newResidence.address.state, 100, stdin);
        newResidence.address.state[strcspn(newResidence.address.state, "\n")] = 0;
        
        if(cancelOperationWithString(newResidence.address.state)) return;
        
        if(newResidence.address.state[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Estado' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.address.state[0] == '\0');

    do {
        cleanInputBuffer();
        printColorful("CEP (Ex.: 38500-000): ", 5);
        fgets(newResidence.address.cep, 100, stdin);
        newResidence.address.cep[strcspn(newResidence.address.cep, "\n")] = 0;
        
        if(cancelOperationWithString(newResidence.address.cep)) return;
        
        if(newResidence.address.cep[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'CEP' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newResidence.address.cep[0] == '\0');
    
    newResidence.ownerId = authUser->id;
    
    cleanScreen();
    createResidence(newResidence);
}