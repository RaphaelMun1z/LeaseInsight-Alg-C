#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../../utils/cancelOperation/cancelOperation.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Controllers
#include "../../../../controllers/updateResidenceController/updateResidenceController.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../services/residenceService/residenceService.h"

int residenceManagerAdmMenu(){
    int option;
    do{
        printColorful("Gerenciando residencias. Você pode: \n", 3);
        printColorful("1 -> Acessar todas residencias.\n", 5);
        printColorful("2 -> Acessar detalhes de uma residencia.\n", 5);
        printColorful("3 -> Alterar uma residencia.\n", 5);
        printColorful("4 -> Remover uma residencia.\n", 5);
        printColorful("5 -> Voltar.\n", 1);
        
        printColorful("Escolha uma opção: ", 5);
        scanf("%d", &option);
        
        if(option < 1 || option > 5){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 5);
    cleanScreen();
    return option;
}

void residenceManagerAdmMenuChoose(){
    switch (residenceManagerAdmMenu())
    {
        case 1:
        findAllResidences();
        residenceManagerAdmMenuChoose();
        break;
        
        case 2: {
            int residenceId;
            printColorful("Informe o ID da residência: ", 3);
            scanf("%d", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            printResidenceById(residenceId);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        case 3:{
            int residenceId;

            double newRentalValue;
            int newOccupancyStatus;
            int changeAddress;
            Address newAddress;
            
            printColorful("Informe o ID da residencia: ", 3);
            scanf("%d", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            updateResidenceForm(&newRentalValue, &newOccupancyStatus, &changeAddress, &newAddress);
            
            changeResidenceDetails(residenceId, newRentalValue, newOccupancyStatus, changeAddress, newAddress);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        case 4: {
            int residenceId;
            printColorful("Informe o ID da residencia: ", 3);
            scanf("%d", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            deleteResidence(residenceId);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        case 5: {
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}