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
    
    printColorful("\nPreencha os campos a seguir para registrar a residencia.", 3);
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
        printColorful("Tipo de imóvel [1 - Casa | 2 - Apartamento | 3 - Outros]: ", 5);
        scanf("%d", &newResidence.propertyType);
        
        if(cancelOperationWithInt(newResidence.propertyType)) return;
        
        if(newResidence.propertyType < 1 || newResidence.propertyType > 3){
            cleanScreen();
            printColorful("\nO Campo 'Tipo de imóvel' é obrigatório. Tente novamente.\n\n", 4);
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
    
    // Seta o proprietário
    newResidence.ownerId = authUser->id;

    cleanScreen();
    createResidence(newResidence);
}