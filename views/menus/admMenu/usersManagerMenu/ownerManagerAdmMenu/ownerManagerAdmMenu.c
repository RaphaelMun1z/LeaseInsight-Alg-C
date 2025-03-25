#include <stdio.h>
#include <string.h>

// Utils
#include "../../../../../utils/cleanScreen/cleanScreen.h"
#include "../../../../../utils/printColorful/printColorful.h"
#include "../../../../../utils/cleanInputBuffer/cleanInputBuffer.h"

// Services
#include "../../../../../services/stateManagerService/stateManagerService.h"
#include "../../../../../services/ownerService/ownerService.h"

int ownerManagerAdmMenu(){
    int option;
    do{
        printColorful("Gerenciando proprietários. Você pode: \n", 3);
        printColorful("1 -> Voltar.\n", 6);
        printColorful("2 -> Acessar todos proprietários.\n", 5);
        printColorful("3 -> Acessar detalhes de um proprietário.\n", 5);
        printColorful("4 -> Alterar um proprietários.\n", 5);
        printColorful("5 -> Remover um proprietários.\n", 5);
        
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

void ownerManagerAdmMenuChoose(){
    switch (ownerManagerAdmMenu())
    {
        case 1: {
            break;
        }

        case 2:
        findAllOwners();
        ownerManagerAdmMenuChoose();
        break;
        
        case 3: {
            int ownerId;
            printColorful("Informe o código do proprietário: ", 3);
            scanf("%d", &ownerId);
            
            Owner *o = findOwnerById(ownerId);
            
            if(o == NULL){
                printColorful("Proprietário não encontrado.\n\n", 1);
                ownerManagerAdmMenuChoose();
                return;
            }
            
            printOwnerById(ownerId);
            ownerManagerAdmMenuChoose();
            break;
        }
        
        case 4: {
            char newOwnerName[100];
            
            int ownerId;
            printColorful("Informe o código do proprietário: ", 3);
            scanf("%d", &ownerId);
            
            if(!ownerExistsById(ownerId)){
                printColorful("Proprietário não encontrado.\n\n", 1);
                ownerManagerAdmMenuChoose();
                return;
            }
            
            do {
                cleanInputBuffer();
                printColorful("\n[DICA] Caso não queira alterar o atributo, digite: '-1'.\n", 5);
                printColorful("Novo nome: ", 5);
                fgets(newOwnerName, 100, stdin);
                newOwnerName[strcspn(newOwnerName, "\n")] = 0;
                
                if(newOwnerName[0] == '\0'){
                    cleanScreen();
                    printColorful("\nO Campo 'Nome' é obrigatório. Tente novamente.\n\n", 4);
                }
            } while (newOwnerName[0] == '\0');
            
            changeOwnerDetails(ownerId, newOwnerName);
            ownerManagerAdmMenuChoose();
            break;
        }
        
        case 5:{
            int ownerId;
            printColorful("Informe o código do proprietário: ", 3);
            scanf("%d", &ownerId);
            
            deleteOwner(ownerId);
            ownerManagerAdmMenuChoose();
            break;
        }
        
        default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}