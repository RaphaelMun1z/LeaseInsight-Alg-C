#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Owner/Owner.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"

void findAllOwners(){
    if(registeredOwnersNumber == 0)
    return printColorful("Não há proprietários registrados.\n", 4);
    
    for (int ii = 0; ii < registeredOwnersNumber; ii++){
        printf("\nNome: %s\n", owners[ii].name);
        printf("Telefone: %s\n", owners[ii].phone);
        printf("E-mail: %s\n", owners[ii].email);
        printf("\n____\n");
    }
}

Owner *findOwnerById(double id){
    for (int ii = 0; ii < registeredOwnersNumber; ii++){
        if(owners[ii].id == id){
            return &owners[ii];
        }
    }
    
    return NULL;
}

Owner *findOwnerByEmail(char email[]){
    for (int ii = 0; ii < registeredOwnersNumber; ii++){
        if(strcmp(owners[ii].email, email) == 0){
            return &owners[ii];
        }
    }
    
    return NULL;
}

void createOwner(Owner owner){
    if(findOwnerByEmail(owner.email) != NULL)
    return printColorful("Proprietário já cadastrado!\n", 1);
    
    owners[registeredOwnersNumber].id = registeredOwnersNumber + 1;
    strcpy(owners[registeredOwnersNumber].name, owner.name);
    strcpy(owners[registeredOwnersNumber].phone, owner.phone);
    strcpy(owners[registeredOwnersNumber].email, owner.email);
    strcpy(owners[registeredOwnersNumber].password, owner.password);
    registeredOwnersNumber++;
    
    char tempName[100];
    strncpy(tempName, owner.name, strcspn(owner.name, "\n"));
    tempName[strcspn(owner.name, "\n")] = '\0'; 
    
    char welcomeText[200];
    snprintf(welcomeText, sizeof(welcomeText), "\n%s, você foi registrado com sucesso, seja bem-vindo(a)!\n", tempName);
    printColorful(welcomeText, 2);
    
    if(registeredOwnersNumber == ownersCurrentLimit)
    allocateMoreSpaceOwner();
    
    LoginCredentials credentials;
    strcpy(credentials.email, owner.email);
    strcpy(credentials.password, owner.password);
    
    signInUser(credentials);
}