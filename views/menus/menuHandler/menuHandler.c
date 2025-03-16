#include <stdio.h>

// Views
#include "../mainMenu/mainMenu.h"
#include "../homeMenu/homeMenu.h"

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
        homeMenuChoose();
        return 1;
    }else{
        return mainMenuChoose();
    }
}
