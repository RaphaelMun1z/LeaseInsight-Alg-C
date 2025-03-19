#include <stdio.h>

// Views
#include "../mainMenu/mainMenu.h"
#include "../tenantMenu/tenantMenu.h"
#include "../ownerMenu/ownerMenu.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

void initMenuHandler(){
    int notFinished = 1;
    do{
        notFinished = redirectToMenu();
    } while(notFinished);
}

int redirectToMenu(){
    if(getAuthUser() != NULL){
        AuthUser user = *getAuthUser();
        if(user.userType == 3){
            tenantMenuChoose();
        }else if(user.userType == 2){
            ownerMenuChoose();
        } else if(user.userType == 1){
            printf("teste\n");
        }
        return 1;
    }else{
        return mainMenuChoose();
    }
}
