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
    residences = (Residence *) calloc(5, sizeof(Residence));

    if (residences == NULL) {
        printf("[LOG] Erro ao alocar memória para 'residences'!\n");
        return;
    }

    printf("[LOG] Memória padrão alocada para 'residences'\n");
}

void allocateSpaceResidenceForFile(int numberOfResidences){
    registeredResidencesNumber = numberOfResidences;
    residencesCurrentLimit = ((numberOfResidences / 5) + 1) * 5;

    residences = (Residence *) calloc(residencesCurrentLimit, sizeof(Residence));
    
    if (residences == NULL) {
        printf("[LOG] Erro ao alocar memória para 'residences'!\n");
        return;
    }

    printf("[LOG] Memória alocada para 'residences' com base nos %d registros do arquivo!\n", numberOfResidences);
}

void allocateMoreSpaceResidence(){
    residencesCurrentLimit += 5;
    
    Residence *temp = realloc(residences, sizeof(Residence) * residencesCurrentLimit);
    if (temp == NULL){
        printf("[LOG] Erro ao realocar memória para 'residences'!\n");
        residencesCurrentLimit -= 5;
        return;
    }
    
    residences = temp;
}

void freeResidences(){
    free(residences);
    residences = NULL;
}