#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Residence/Residence.h"
#include "../../entities/AuthUser/AuthUser.h"

// Services
#include "../dataPersistenceService/dataPersistenceService.h"
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../ownerService/ownerService.h"

void findAllResidences();
Residence *findResidenceById(double id);
void createResidence(Residence Residence); 
void deleteResidence(double id); 

void printResidence(Residence c);
void printResidenceById(double id);
void findResidencesByOwner(double id);
void changeResidenceOccupancyStatus(double id, int status);

void findAllResidences(){
	if(registeredResidencesNumber == 0)
	return printColorful("Não há residencias registradas.\n", 4);
	
	for (int ii = 0; ii < registeredResidencesNumber; ii++){
		printResidence(residences[ii]);
	}
}

Residence *findResidenceById(double id){
	for (int ii = 0; ii < registeredResidencesNumber; ii++){
		if(residences[ii].id == id){
			return &residences[ii];
		}
	}
	
	return NULL;
}

int residenceExistsById(double id){
	return findResidenceById(id) == NULL ? 0 : 1;
}

void createResidence(Residence residence){
	residences[registeredResidencesNumber].id = registeredResidencesNumber + 1;
	residences[registeredResidencesNumber].propertyType = residence.propertyType;
	residences[registeredResidencesNumber].occupancyStatus = residence.occupancyStatus;
	residences[registeredResidencesNumber].rentalValue = residence.rentalValue;
	residences[registeredResidencesNumber].ownerId = authUser->id;
	registeredResidencesNumber++;
	saveResidencesData();
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou uma residencia!\n");
	printColorful(welcomeText, 2);
	
	if(registeredResidencesNumber == residencesCurrentLimit)
	allocateMoreSpaceResidence();
}

void deleteResidence(double id){
	if(!residenceExistsById(id)){
		printColorful("Residencia não encontrado.\n", 1);
		return;
	}
	
	for (int ii = 0; ii < registeredResidencesNumber; ii++){
		if(residences[ii].id == id){
			int indLastItemOfResidences = registeredResidencesNumber-1;
			residences[ii] = residences[indLastItemOfResidences];
			registeredResidencesNumber--;
			saveResidencesData();
			printColorful("Residencia deletado com sucesso!\n", 2);
			return;
		}
	}
	
	return printColorful("Residencia não encontrada.\n", 1);
}

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

void printResidenceById(double id){
	Residence *r = findResidenceById(id);
	
	if(r == NULL)
	return printColorful("Residencia não encontrada.\n", 1);
	
	printResidence(*r);
}

void findResidencesByOwner(double ownerId){
	int residencesFound = 0;
	for (int ii = 0; ii < registeredResidencesNumber; ii++){
		if(residences[ii].ownerId == ownerId){
			residencesFound++;
			printResidence(residences[ii]);
		}
	}
	
	if(residencesFound == 0)
	return printColorful("Não há residencias registradas.\n", 4);
}

void changeResidenceOccupancyStatus(double id, int status){
	if(!residenceExistsById(id)){
		return printColorful("Residencia não encontrada.\n", 1);
	}
	
	Residence *r = findResidenceById(id);
	r->occupancyStatus = status;
	saveResidencesData();

	printColorful("Residencia atualizada com sucesso!\n", 2);
}

void changeResidenceDetails(double id, double newRentalValue, int newOccupancyStatus){
	if(!residenceExistsById(id)){
		return printColorful("Residencia não encontrada.\n", 1);
	}
	
	Residence *r = findResidenceById(id);
	if(newRentalValue != -1)
	r->rentalValue = newRentalValue;

	if(newOccupancyStatus != -1)
	r->occupancyStatus = newOccupancyStatus;

	saveResidencesData();
	
	printColorful("Residencia atualizada com sucesso!\n", 2);
}