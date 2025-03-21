#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Residence/Residence.h"
#include "../../entities/AuthUser/AuthUser.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../ownerService/ownerService.h"

void printResidence(Residence r){
	printf("\nID: %.0lf\n", r.id);
	printf("Valor locação: R$%.2lf\n", r.rentalValue);
	int tipo = r.propertyType;
	printf("Tipo de imóvel: ");
	if (tipo == 1) printf("Casa\n");
	else if (tipo == 2) printf("Apartamento\n");
	else if (tipo == 3) printf("Outros\n");
	else printf("Inválido\n");
	printf("Status: ");
	int status = r.occupancyStatus;
	if (status == 1) printf("Ocupado\n");
	else if (status == 2) printf("Livre\n");
	else if (status == 3) printf("Saída pendente\n");
	else printf("Inválido\n");
	printf("\n____\n");
}

void findAllResidences(){
	if(residencesLength == 0)
	return printColorful("Não há residencias registradas.\n", 4);
	
	for (int ii = 0; ii < residencesLength; ii++){
		printResidence(residences[ii]);
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
	residences[residencesLength].ownerId = authUser->id;
	residencesLength++;
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou uma residencia!\n");
	printColorful(welcomeText, 2);
	
	if(residencesLength == residencesCurrentLimit)
	allocateMoreSpaceResidence();
}

void changeResidenceOccupancyStatus(double id, int status){
	
}

void findResidencesByOwner(double ownerId){
	int residencesFound = 0;
	for (int ii = 0; ii < residencesLength; ii++){
		if(residences[ii].ownerId == ownerId){
			residencesFound++;
			printResidence(residences[ii]);
		}
	}
	
	if(residencesFound == 0)
	return printColorful("Não há residencias registradas.\n", 4);
}