#include <stdio.h>

// Views
#include "../mainMenu/mainMenu.h"
#include "../homeMenu/homeMenu.h"

// Services
#include "../../../services/stateManagerService/stateManagerService.h"

int redirectToMenu(){
    if(getAuthUser() != NULL){
        homeMenu();
        return 1;
    }else{
        return mainMenuChoose();
    }
}