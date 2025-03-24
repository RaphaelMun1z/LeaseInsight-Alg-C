#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Residence/Residence.h"
#include "../../entities/AuthUser/AuthUser.h"
#include "../../entities/Contract/Contract.h"

// Services
#include "../dataPersistenceService/dataPersistenceService.h"
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../ownerService/ownerService.h"

void findAllResidences();
Residence *findResidenceById(int id);
void createResidence(Residence residence); 
void deleteResidence(int id); 
void printResidence(Residence r);
void printResidenceById(int id);
int residenceExistsById(int id);
void findResidencesByOwner(int id);
int hasContractAssociated(int residenceId);
void changeResidenceOccupancyStatus(int id, int status);
void changeResidenceDetails(int id, double newRentalValue, int newOccupancyStatus, int changeAddress, Address newAddress);

void findAllResidences(){
	if(registeredResidencesNumber == 0)
	return printColorful("Não há residencias registradas.\n", 4);
	
	for (int ii = 0; ii < registeredResidencesNumber; ii++){
		printResidence(residences[ii]);
	}
}

Residence *findResidenceById(int id){
	for (int ii = 0; ii < registeredResidencesNumber; ii++){
		if(residences[ii].id == id){
			return &residences[ii];
		}
	}
	
	return NULL;
}

int residenceExistsById(int id){
	return findResidenceById(id) == NULL ? 0 : 1;
}

void createResidence(Residence residence){
	residences[registeredResidencesNumber].id = registeredResidencesNumber + 1;
	residences[registeredResidencesNumber].propertyType = residence.propertyType;
	residences[registeredResidencesNumber].occupancyStatus = residence.occupancyStatus;
	residences[registeredResidencesNumber].rentalValue = residence.rentalValue;
	residences[registeredResidencesNumber].address = residence.address;
	residences[registeredResidencesNumber].ownerId = authUser->id;
	registeredResidencesNumber++;
	saveResidencesData();
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou uma residencia!\n");
	printColorful(welcomeText, 2);
	
	if(registeredResidencesNumber == residencesCurrentLimit)
	allocateMoreSpaceResidence();
}

void deleteResidence(int id){
	if(!residenceExistsById(id)){
		printColorful("Residencia não encontrado.\n", 1);
		return;
	}

	if(hasContractAssociated(id)){
		printColorful("Não é possível deletar uma residencia com contrato associado.\n", 1);
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
	printf("\nID: %d\n", r.id);
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
	printf("Proprietário: %s\n", findOwnerById(r.ownerId)->name);
	printf("Código do Proprietário: %d\n", r.ownerId);
	printf("Endereço: %s, %d, %s, %s, %s, %s\n", r.address.street, r.address.number, r.address.complement, r.address.district, r.address.city, r.address.state);
	printf("\n____\n");
}

void printResidenceById(int id){
	Residence *r = findResidenceById(id);
	
	if(r == NULL)
	return printColorful("Residencia não encontrada.\n", 1);
	
	printResidence(*r);
}

void findResidencesByOwner(int ownerId){
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

void changeResidenceOccupancyStatus(int id, int status){
	if(!residenceExistsById(id)){
		return printColorful("Residencia não encontrada.\n", 1);
	}
	
	Residence *r = findResidenceById(id);
	r->occupancyStatus = status;
	saveResidencesData();
	
	printColorful("Residencia atualizada com sucesso!\n", 2);
}

void changeResidenceDetails(int id, double newRentalValue, int newOccupancyStatus, int changeAddress, Address newAddress){
	if(!residenceExistsById(id)){
		return printColorful("Residencia não encontrada.\n", 1);
	}
	
	Residence *r = findResidenceById(id);
	if(newRentalValue != -1)
	r->rentalValue = newRentalValue;
	
	if(newOccupancyStatus != -1)
	r->occupancyStatus = newOccupancyStatus;
	
	if(changeAddress == 1)
	r->address = newAddress;
	
	saveResidencesData();
	
	printColorful("Residencia atualizada com sucesso!\n", 2);
}

int hasContractAssociated(int residenceId){
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(contracts[ii].residence.id == residenceId){
			return 1;
		}
	}
	
	return 0;
}