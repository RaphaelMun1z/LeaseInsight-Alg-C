#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../../utils/cancelOperation/cancelOperation.h"
#include "../../../../utils/verifyInputContent/verifyInputContent.h"

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
        printColorful("Gerenciando propriedades. Você pode: \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Acessar todas propriedades.\n", 5);
        printColorful("3 -> Acessar detalhes de uma propriedade.\n", 5);
        printColorful("4 -> Alterar uma propriedade.\n", 5);
        printColorful("5 -> Remover uma propriedade.\n", 5);
        
        printColorful("Escolha uma opção: ", 5);
        option = returnValidInt();
        
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
        case 1: {
            break;
        }

        case 2:
        findAllResidences();
        residenceManagerAdmMenuChoose();
        break;
        
        case 3: {
            int residenceId;
            printColorful("Informe o código da propriedade: ", 3);
            scanf("%d", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Propriedade não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            printResidenceById(residenceId);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        case 4:{
            int residenceId;

            double newRentalValue;
            int newOccupancyStatus;
            int changeAddress;
            Address newAddress;
            
            printColorful("Informe o código da propriedade: ", 3);
            scanf("%d", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Propriedade não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            updateResidenceForm(&newRentalValue, &newOccupancyStatus, &changeAddress, &newAddress);
            
            changeResidenceDetails(residenceId, newRentalValue, newOccupancyStatus, changeAddress, newAddress);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        case 5: {
            int residenceId;
            printColorful("Informe o código da propriedade: ", 3);
            scanf("%d", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Propriedade não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            deleteResidence(residenceId);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}