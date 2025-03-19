#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/GenericUser/GenericUser.h"
#include "../../entities/Adm/Adm.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../userService/userService.h"

void findAllAdms(){
    if(registeredAdmsNumber == 0)
    return printColorful("Não há administradores registrados.\n", 4);
    
    for (int ii = 0; ii < registeredAdmsNumber; ii++){
        printf("\nNome: %s\n", adms[ii].name);
        printf("E-mail: %s\n", adms[ii].email);
        printf("\n____\n");
    }
}

Adm *findAdmById(double id){
    for (int ii = 0; ii < registeredAdmsNumber; ii++){
        if(adms[ii].id == id){
            return &adms[ii];
        }
    }
    
    return NULL;
}

Adm *findAdmByEmail(char email[]){
    for (int ii = 0; ii < registeredAdmsNumber; ii++){
        if(strcmp(adms[ii].email, email) == 0){
            return &adms[ii];
        }
    }
    
    return NULL;
}

void createAdm(Adm adm){
    if(userAlreadyRegistered(adm.email)) return;
    
    adms[registeredAdmsNumber].id = registeredUsersNumber + 1;
    strcpy(adms[registeredAdmsNumber].name, adm.name);
    strcpy(adms[registeredAdmsNumber].email, adm.email);
    strcpy(adms[registeredAdmsNumber].password, adm.password);
    registeredAdmsNumber++;
    registeredUsersNumber++;
    
    if(registeredAdmsNumber == admsCurrentLimit)
    allocateMoreSpaceAdm();
}