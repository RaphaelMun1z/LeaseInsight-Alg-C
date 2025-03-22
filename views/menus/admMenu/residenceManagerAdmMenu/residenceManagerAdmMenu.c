#include <stdio.h>
#include <conio.h>
#include <string.h>

// Utils
#include "../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../utils/printColorful/printColorful.h"
#include "../../../../utils/cleanInputBuffer/cleanInputBuffer.h"

// Entities
#include "../../../../entities/AuthUser/AuthUser.h"

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
        
        option = getch();
        option -= '0';
        
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
            double residenceId;
            printColorful("Informe o ID da residência: ", 3);
            scanf("%lf", &residenceId);
            
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
            double residenceId;

            double newRentalValue;
            int newOccupancyStatus;
            
            printColorful("Informe o ID da residencia: ", 3);
            scanf("%lf", &residenceId);
            
            if(!residenceExistsById(residenceId)){
                printColorful("Residencia não encontrada.\n\n", 1);
                residenceManagerAdmMenuChoose();
                return;
            }
            
            do {
                cleanInputBuffer();
                printColorful("\n[DICA] Caso não queira alterar o atributo, digite: '-1'.\n\n", 5);
                printColorful("Novo Valor de aluguel: ", 5);
                scanf("%lf", &newRentalValue);
                
                if(newRentalValue <= 0){
                    cleanScreen();
                    printColorful("\nO Campo 'Valor de aluguel' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (newRentalValue <= 0);

            do {
                cleanInputBuffer();
                printColorful("\n[DICA] Caso não queira alterar o atributo, digite: '-1'.\n\n", 5);
                printColorful("Status [1 - Ocupado | 2 - Livre | 3 - Saída pendente]: ", 5);
                scanf("%d", &newOccupancyStatus);
                
                if(newOccupancyStatus < 1 || newOccupancyStatus > 3){
                    cleanScreen();
                    printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (newOccupancyStatus < 1 || newOccupancyStatus > 3);
            
            changeResidenceDetails(residenceId, newRentalValue, newOccupancyStatus);
            residenceManagerAdmMenuChoose();
            break;
        }
        
        case 4: {
            double residenceId;
            printColorful("Informe o ID da residencia: ", 3);
            scanf("%lf", &residenceId);
            
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