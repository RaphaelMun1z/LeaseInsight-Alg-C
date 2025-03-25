#include <stdio.h>
#include <stdlib.h>

// DTOs
#include "../../dtos/dtos.h"

Residence *residences;
int registeredResidencesNumber = 0;
int residencesCurrentLimit;
const int residenceIncrementAmount = 5;

void initResidences() {
    residencesCurrentLimit = 15;
    residences = (Residence *) calloc(residencesCurrentLimit, sizeof(Residence));

    if (residences == NULL) {
        printf("[LOG] Erro ao alocar memória para 'residences'!\n");
        exit(1);
        return;
    }
}

void allocateSpaceResidenceForFile(int numberOfResidences){
    registeredResidencesNumber = numberOfResidences;
    residencesCurrentLimit = ((numberOfResidences / 5) + 1) * 5;

    residences = (Residence *) calloc(residencesCurrentLimit, sizeof(Residence));
    
    if (residences == NULL) {
        printf("[LOG] Erro ao alocar memória para 'residences'!\n");
        exit(1);
        return;
    }
}

void allocateMoreSpaceResidence(){
    residencesCurrentLimit += residenceIncrementAmount;
    
    Residence *temp = realloc(residences, sizeof(Residence) * residencesCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'residences'!\n");
        residencesCurrentLimit -= residenceIncrementAmount;
        return;
    }
    
    residences = temp;

    printf("[LOG] Espaço para mais propriedades alocado com sucesso!\n");
}

void freeResidences(){
    free(residences);
    residences = NULL;
}