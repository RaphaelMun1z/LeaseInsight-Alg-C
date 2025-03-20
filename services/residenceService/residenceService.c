#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Residence/Residence.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../ownerService/ownerService.h"

void findAllResidences(){
	if(residencesLength == 0)
	return printColorful("Não há residencias registradas.\n", 4);
	
	for (int ii = 0; ii < residencesLength; ii++){
		printf("\nID: %.0lf\n", residences[ii].id);
		printf("Valor locação: R$%.2lf\n", residences[ii].rentalValue);
		int tipo = residences[ii].propertyType;
		printf("Tipo de imóvel: ");
		if (tipo == 1) printf("Casa\n");
		else if (tipo == 2) printf("Apartamento\n");
		else if (tipo == 3) printf("Outros\n");
		else printf("Inválido\n");
		printf("Status: ");
		int status = residences[ii].occupancyStatus;
		if (status == 1) printf("Ocupado\n");
		else if (status == 2) printf("Livre\n");
		else if (status == 3) printf("Saída pendente\n");
		else printf("Inválido\n");
		printf("\n____\n");
	}
}

// Falta limitar para os imoveis do owner
void findResidencesByOwner(double id){
	Owner *owner = findOwnerById(id);
	
	if(residencesLength == 0)
	return printColorful("Não há residencias registradas.\n", 4);
	
	if(owner == NULL)
	return printColorful("Proprietário não encontrado.\n", 4);
	
	for (int ii = 0; ii < residencesLength; ii++){
		printf("\nID: %.0lf\n", residences[ii].id);
		printf("Valor locação: R$%.2lf\n", residences[ii].rentalValue);
		int tipo = residences[ii].propertyType;
		printf("Tipo de imóvel: ");
		if (tipo == 1) printf("Casa\n");
		else if (tipo == 2) printf("Apartamento\n");
		else if (tipo == 3) printf("Outros\n");
		else printf("Inválido\n");
		printf("Status: ");
		int status = residences[ii].occupancyStatus;
		if (status == 1) printf("Ocupado\n");
		else if (status == 2) printf("Livre\n");
		else if (status == 3) printf("Saída pendente\n");
		else printf("Inválido\n");
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
