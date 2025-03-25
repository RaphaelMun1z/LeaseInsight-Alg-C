#include <stdio.h>
#include <string.h>

// Utils
#include "../../../utils/cleanScreen/cleanScreen.h"
#include "../../../utils/printColorful/printColorful.h"
#include "../../../utils/verifyInputContent/verifyInputContent.h"

// Entities
#include "../../../entities/AuthUser/AuthUser.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

// Views
#include "./usersManagerMenu/usersManagerMenu.h"
#include "./contractManagerAdmMenu/contractManagerAdmMenu.h"
#include "./residenceManagerAdmMenu/residenceManagerAdmMenu.h"

int admMenu()
{
    int option;
    do
    {
        char message[100], name[100];
        (getAuthUserName() != NULL) ? strcpy(name, getAuthUserName()) : strcpy(name, "Não foi possível carregar.");
        snprintf(message, sizeof(message), "\n%s, de que forma posso auxiliar? \n", name);
        printColorful(message, 3);
        printColorful("1 -> Sair da minha conta.\n", 6);
        printColorful("2 -> Gerenciar PROPRIEDADES.\n", 5);
        printColorful("3 -> Gerenciar CONTRATOS.\n", 5);
        printColorful("4 -> Gerenciar USUÁRIOS.\n", 5);

        printColorful("Escolha uma opção: ", 5);
        option = returnValidInt();
        if (option < 1 || option > 4)
        {
            cleanScreen();
            printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n", 4);
        }
    } while (option < 1 || option > 4);
    cleanScreen();
    return option;
}

void admMenuChoose()
{
    switch (admMenu())
    {
    case 1:
        logoutAuthUser();
        break;

    case 2:
        residenceManagerAdmMenuChoose();
        break;

    case 3:
        contractManagerAdmMenuChoose();
        break;

    case 4:
        usersManagerMenuChoose();
        break;

    default:
        cleanScreen();
        printColorful("\nAcredito que houve um engano, o valor informado não existe. Tente novamente.\n\n", 4);
        break;
    }
}