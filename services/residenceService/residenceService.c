#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Residence/Residence.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"

void findAllResidences(){
	if(residencesLength == 0)
	return printColorful("Não há residencias registradas.\n", 4);

	for (int ii = 0; ii < residencesLength; ii++){
		printf("\nID: %.0lf\n", residences[ii].id);
		printf("Tipo: %d\n", residences[ii].propertyType);
		printf("Status: %.2lf\n", residences[ii].occupancyStatus);
		printf("Valor locação: %s\n", residences[ii].rentalValue);
		printf("\n____\n");
	}
}

Residence *findResidenceById(double id){
	for (int ii = 0; ii < residencesLength; ii++){
        if(residences[ii].id == id){
            return &residences[ii];
        }
    }
    
    return NULL;
}

void createResidence(Residence residence){
	residences[residencesLength].id = residencesLength + 1;
	residences[residencesLength].propertyType = residence.propertyType;
	residences[residencesLength].occupancyStatus = residence.occupancyStatus;
	residences[residencesLength].rentalValue = residence.rentalValue;
	residences[residencesLength].ownerId = residence.ownerId;
	residencesLength++;
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou uma residencia!\n");
	printColorful(welcomeText, 2);
	
	if(residencesLength == residencesCurrentLimit)
	allocateMoreSpaceResidence();
}

void changeResidenceOccupancyStatus(double id, int status){
	
}
