#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/GenericUser/GenericUser.h"
#include "../../entities/Owner/Owner.h"

// Services
#include "../dataPersistenceService/dataPersistenceService.h"
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../userService/userService.h"

void findAllOwners();
Owner *findOwnerById(int id);
Owner *findOwnerByEmail(char email[]);
void createOwner(Owner Owner);
void deleteOwner(int id); 

void printOwner(Owner o);
void printOwnerById(int id);
int ownerExistsById(int id);
void changeOwnerDetails(int id, char newName[]);

void findAllOwners(){
    if(registeredOwnersNumber == 0)
    return printColorful("Não há proprietários registrados.\n", 4);
    
    for (int ii = 0; ii < registeredOwnersNumber; ii++){
        printOwner(owners[ii]);
    }
}

Owner *findOwnerById(int id){
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
    if(userAlreadyRegistered(owner.email)) return;
    
    owners[registeredOwnersNumber].id = registeredUsersNumber + 1;
    strcpy(owners[registeredOwnersNumber].name, owner.name);
    strcpy(owners[registeredOwnersNumber].phone, owner.phone);
    strcpy(owners[registeredOwnersNumber].email, owner.email);
    strcpy(owners[registeredOwnersNumber].password, owner.password);
    registeredOwnersNumber++;
    registeredUsersNumber++;

    saveOwnersData();
    
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

void deleteOwner(int id){
    if(!ownerExistsById(id)){
        printColorful("Proprietário não encontrado.\n", 1);
        return;
    }
    
    for (int ii = 0; ii < registeredOwnersNumber; ii++){
        if(owners[ii].id == id){			
            int indLastItemOfOwners = registeredOwnersNumber-1;
            owners[ii] = owners[indLastItemOfOwners];
            registeredOwnersNumber--;
            saveOwnersData();
            printColorful("Proprietário deletado com sucesso!\n", 2);
            return;
        }
    }
    
    return printColorful("Proprietário não encontrado.\n", 1);
}

void printOwner(Owner o){
    printf("\nCódigo: %d", o.id);
    printf("\nNome: %s\n", o.name);
    printf("Telefone: %s\n", o.phone);
    printf("E-mail: %s\n", o.email);
    printf("\n____\n");
}

void printOwnerById(int id){
    Owner *o = findOwnerById(id);
    
    if(o == NULL)
    return printColorful("Proprietário não encontrado.\n", 1);
    
    printOwner(*o);
}

int ownerExistsById(int id){
    return findOwnerById(id) == NULL ? 0 : 1;
}

void changeOwnerDetails(int id, char newName[]){
    if(!ownerExistsById(id)){
        return printColorful("Proprietário não encontrado.\n", 1);
    }
    
    Owner *o = findOwnerById(id);
    if(!(strcmp(newName, "-1") == 0))
    strcpy(o->name, newName);
    saveOwnersData();
    
    printColorful("Proprietário atualizado com sucesso!\n", 2);
}