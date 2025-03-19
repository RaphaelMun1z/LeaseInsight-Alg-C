#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double id; // PK
    int propertyType;
    int occupancyStatus;
    char description[255];
    double marketValue;
    double rentalValue;
    double totalArea;
    double builtArea;
    int aptNumber;
    int numberBedrooms;
    int numberBathrooms;
    int numberSuites;
    int garageSpaces;
    int yearConstruction;
    char complement[100];
    char dateLastRenovation[11];
} Residence;

Residence *residences;
int residencesLength = 0;
int residencesCurrentLimit = 5;

void initResidences() {
    residences = (Residence *) calloc(5, sizeof(Residence));

    if (residences == NULL) {
        printf("[LOG] Erro ao alocar memória para 'residences'!\n");
    }
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