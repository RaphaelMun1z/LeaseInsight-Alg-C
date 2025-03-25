#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../../../utils/enums/enums.h"
#include "../../../../utils/verifyInputContent/verifyInputContent.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Controllers
#include "../../../../controllers/registerResidenceController/registerResidenceController.h"
#include "../../../../controllers/updateResidenceController/updateResidenceController.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../services/residenceService/residenceService.h"

int residenceManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando propriedades. Você pode: \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Acessar minhas propriedades.\n", 5);
        printColorful("3 -> Cadastrar propriedade.\n", 5);
        printColorful("4 -> Acessar detalhes de uma propriedade.\n", 5);
        printColorful("5 -> Alterar uma propriedade.\n", 5);
        printColorful("6 -> Remover uma propriedade.\n", 5);
        
        printColorful("Escolha uma opção: ", 5);
        option = returnValidInt();
        
        if(option < 1 || option > 6){
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while(option < 1 || option > 6);
    cleanScreen();
    return option;
}

void residenceManagerMenuChoose(){
    switch (residenceManagerMenu())
    {
        case 1: {
            break;
        }
        
        case 2:
        findResidencesByOwner(authUser->id);
        residenceManagerMenuChoose();
        break;
        
        case 3:
        registerResidenceForm();
        residenceManagerMenuChoose();
        break;
        
        case 4: {
            int residenceId;
            printColorful("Informe o código da propriedade: ", 3);
            scanf("%d", &residenceId);
            
            if(!isResidenceAssociatedToOwner(residenceId, authUser->id)){
                printColorful("Propriedade não encontrada.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            printResidenceById(residenceId);
            residenceManagerMenuChoose();
            break;
        }
        
        case 5:{
            int residenceId;
            
            double newRentalValue;
            int newOccupancyStatus;
            int changeAddress;
            Address newAddress;
            
            printColorful("Informe o código da propriedade: ", 3);
            scanf("%d", &residenceId);
            
            if(!isResidenceAssociatedToOwner(residenceId, authUser->id)){
                printColorful("Propriedade não encontrada.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            updateResidenceForm(&newRentalValue, &newOccupancyStatus, &changeAddress, &newAddress);
            
            changeResidenceDetails(residenceId, newRentalValue, newOccupancyStatus, changeAddress, newAddress);
            residenceManagerMenuChoose();
            break;
        }
        
        case 6: {
            int residenceId;
            printColorful("Informe o código da propriedade: ", 3);
            scanf("%d", &residenceId);
            
            if(!isResidenceAssociatedToOwner(residenceId, authUser->id)){
                printColorful("Propriedade não encontrada.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            if(isResidenceAssociatedToAnyContract(residenceId)){
                printColorful("Propriedade não pode ser removida, pois está associada a um contrato.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            deleteResidence(residenceId);
            residenceManagerMenuChoose();
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}