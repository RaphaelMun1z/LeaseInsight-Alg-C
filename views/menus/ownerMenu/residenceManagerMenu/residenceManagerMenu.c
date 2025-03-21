#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

// Controllers
#include "../../../../controllers/registerResidenceController/registerResidenceController.h"

// Services
#include "../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../services/residenceService/residenceService.h"

int residenceManagerMenu(){
    int option;
    do{
        printColorful("Gerenciando propriedades. Você pode: \n", 3);
        printColorful("1 -> Acessar minhas propriedades.\n", 5);
        printColorful("2 -> Cadastrar propriedade.\n", 5);
        printColorful("3 -> Acessar detalhes de uma propriedade.\n", 5);
        printColorful("4 -> Alterar uma propriedade.\n", 5);
        printColorful("5 -> Remover uma propriedade.\n", 5);
        printColorful("6 -> Voltar.\n", 1);
        
        option = getch();
        option -= '0';
        
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
        case 1:
        findResidencesByOwner(authUser->id);
        residenceManagerMenuChoose();
        break;
        
        case 2:
        registerResidenceForm();
        residenceManagerMenuChoose();
        break;
        
        case 3: {
            double residenceId;
            printColorful("Informe o ID da residência: ", 3);
            scanf("%lf", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            printResidenceById(residenceId);
            residenceManagerMenuChoose();
            break;
        }
        
        case 4:{
            double residenceId;
            int residenceStatus;
            
            printColorful("Informe o ID da residencia: ", 3);
            scanf("%lf", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            printColorful("Informe o novo status [1 - Ativo | 2 - Inativo | 3 - Aprovação pendente]: ", 3);
            scanf("%d", &residenceStatus);
            
            changeResidenceOccupancyStatus(residenceId, residenceStatus);
            residenceManagerMenuChoose();
            break;
        }
        
        case 5: {
            double residenceId;
            printColorful("Informe o ID da residencia: ", 3);
            scanf("%lf", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerMenuChoose();
                return;
            }
            
            deleteResidence(residenceId);
            residenceManagerMenuChoose();
            break;
        }

        case 6: {
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}