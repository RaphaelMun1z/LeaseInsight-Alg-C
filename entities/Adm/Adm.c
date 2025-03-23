#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DTOs
#include "../../dtos/dtos.h"

// Services (test)
#include "../../services/admService/admService.h"

Adm *adms;
int registeredAdmsNumber = 0;
int admsCurrentLimit = 5;

void initAdms() {
    adms = (Adm *) calloc(5, sizeof(Adm));
    
    if (adms == NULL) {
        printf("[LOG] Erro ao alocar memória para 'Adms'!\n");
        return;
    }

    printf("[LOG] Memória padrão alocada para 'adms'\n");
}

void allocateSpaceAdmForFile(int numberOfAdms){
    registeredAdmsNumber = numberOfAdms;
    admsCurrentLimit = ((numberOfAdms / 5) + 1) * 5;
    
    adms = (Adm *) calloc(admsCurrentLimit, sizeof(Adm));
    
    if (adms == NULL) {
        printf("[LOG] Erro ao alocar memória para 'adms'!\n");
        return;
    }
    
    printf("[LOG] Memória alocada para 'adms' com base nos %d registros do arquivo!\n", numberOfAdms);
}

void allocateMoreSpaceAdm(){
    admsCurrentLimit += 5;
    
    Adm *temp = realloc(adms, sizeof(Adm) * admsCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'Adms'!\n");
        admsCurrentLimit -= 5;
        return;
    }
    
    adms = temp;
}

void freeAdms(){
    free(adms);
    adms = NULL;
}