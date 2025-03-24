#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/enums/enums.h"

// Entities
#include "../../entities/Contract/Contract.h"

// Services
#include "../dataPersistenceService/dataPersistenceService.h"
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"
#include "../residenceService/residenceService.h"
#include "../tenantService/tenantService.h"

void findAllContracts();
Contract *findContractById(int id);
void findContractsByOwner(int id);
void findContractsByTenant(int id);
void createContract(Contract contract); 
void changeContractStatus(int id, int status);
void deleteContract(int id); 

void printContract(Contract c);
void printContractById(int id);

void findAllContracts(){
	if(registeredContractsNumber == 0)
	return printColorful("Não há contratos registrados.\n", 4);
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		printContract(contracts[ii]);
	}
}

void findContractsByTenantRg(char tenantRg[]){
	if(registeredContractsNumber == 0)
	return printColorful("Não há contratos registrados.\n", 4);
	
	int contractsFound = 0;
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(strcmp(contracts[ii].tenant.rg, tenantRg) == 0){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	printColorful("Não foram encontrados contratos.\n", 4);
}

Contract *findContractById(int id){
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(contracts[ii].id == id){
			return &contracts[ii];
		}
	}
	
	return NULL;
}

void findContractsByStartDate(char startDate[], Contract *foundContracts){
	int aux = 0;
	for (int ii = 0; ii < registeredContractsNumber; ii++) {
		if (strcmp(contracts[ii].contractStartDate, startDate) == 0) {
			foundContracts[aux] = contracts[ii];
			aux++;
		}
	}
}

void findContractsByEndDate(char endDate[], Contract *foundContracts){
	int aux = 0;
	for (int ii = 0; ii < registeredContractsNumber; ii++) {
		if (strcmp(contracts[ii].contractEndDate, endDate) == 0) {
			foundContracts[aux] = contracts[ii];
			aux++;
		}
	}
}

int contractExistsById(int id){
	return findContractById(id) == NULL ? 0 : 1;
}

void createContract(Contract contract){
	if(contract.residence.occupancyStatus != 6){
		printColorful("Propriedade não disponível para locação.\n", 1);
		return;
	}
	
	if(findResidenceById(contract.residence.id) == NULL){
		printColorful("Propriedade não encontrada.\n", 1);
		return;
	}
	
	if(findTenantById(contract.tenant.id) == NULL){
		printColorful("Inquilino não encontrado.\n", 1);
		return;
	}
	
	contracts[registeredContractsNumber].id = registeredContractsNumber + 1;
	strcpy(contracts[registeredContractsNumber].contractStartDate, contract.contractStartDate);
	strcpy(contracts[registeredContractsNumber].contractEndDate, contract.contractEndDate);
	contracts[registeredContractsNumber].defaultRentalValue = contract.defaultRentalValue;
	contracts[registeredContractsNumber].contractStatus = contract.contractStatus;
	contracts[registeredContractsNumber].invoiceDueDate = contract.invoiceDueDate;
	contracts[registeredContractsNumber].residence = contract.residence;
	contracts[registeredContractsNumber].tenant = contract.tenant;
	registeredContractsNumber++;
	saveContractsData();
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou um contrato cuja propriedade é a de código %d, e inquilino de nome %s!\n", contract.residence.id, contract.tenant.name);
	printColorful(welcomeText, 2);
	
	if(registeredContractsNumber == contractsCurrentLimit)
	allocateMoreSpaceContract();
}

void deleteContract(int id){
	if(!contractExistsById(id)){
		printColorful("Contrato não encontrado.\n", 1);
		return;
	}
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(contracts[ii].id == id){			
			int indLastItemOfContracts = registeredContractsNumber-1;
			contracts[ii] = contracts[indLastItemOfContracts];
			registeredContractsNumber--;
			saveContractsData();
			printColorful("Contrato deletado com sucesso!\n", 2);
			return;
		}
	}
	
	return printColorful("Contrato não encontrado.\n", 1);
}

void printContract(Contract c){	
	printf("\nCódigo: %d\n", c.id);

	char contractStatusStr[100];
	getContractStatus(c.contractStatus, contractStatusStr);
	printf("Status: %s\n", contractStatusStr);
 
	printf("Valor do aluguel: %.2lf\n", c.defaultRentalValue);
	printf("Data de início: %s\n", c.contractStartDate);
	printf("Data de término: %s\n", c.contractEndDate);
	printf("Dia de vencimento da fatura: %d\n", c.invoiceDueDate);

	// Tenant
	printColorful("Inquilino:\n", 3);
	printf("   Código inquilino: %d\n", c.tenant.id);
	printf("   Status do inquilino: %d\n", c.tenant.tenantStatus);
	printf("   RG do inquilino: %s\n", c.tenant.rg);

	// Residence
	printColorful("Propriedade:\n", 3);
	printf("   Código da propriedade: %d\n", c.residence.id);
	printf("   Endereço da propriedade: %s, %d, %s, %s, %s, %s\n", c.residence.address.street, c.residence.address.number, c.residence.address.complement, c.residence.address.district, c.residence.address.city, c.residence.address.state);

	// Owner
	printColorful("Proprietário:\n", 3);
	printf("   Código do proprietário da propriedade: %d\n", c.residence.ownerId);
	
	printf("\n____\n");
}

void printContractById(int id){
	Contract *c = findContractById(id);
	
	if(c == NULL)
	return printColorful("Contrato não encontrado.\n", 1);
	
	printContract(*c);
}

void findContractsByOwner(int ownerId){
	int contractsFound = 0;
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(contracts[ii].residence.ownerId == ownerId){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	return printColorful("Não há contratos registrados.\n", 4);
}

void findContractsByTenant(int tenantId){
	int contractsFound = 0;
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(contracts[ii].tenant.id == tenantId){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	return printColorful("Não há contratos registrados.\n", 4);
}

int getContractsAmountByStartDate(char startDate[]){
	int contractsFound = 0;
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(strcmp(contracts[ii].contractStartDate, startDate) == 0){
			contractsFound++;
		}
	}
	
	return contractsFound;
}

int getContractsAmountByEndDate(char endDate[]){
	int contractsFound = 0;
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(strcmp(contracts[ii].contractEndDate, endDate) == 0){
			contractsFound++;
		}
	}
	
	return contractsFound;
}

void findContractsByStatus(int contractStatus){
	int contractsFound = 0;
	
	for (int ii = 0; ii < registeredContractsNumber; ii++){
		if(contracts[ii].contractStatus == contractStatus){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	return printColorful("Não foram encontrados contratos com esse status.\n", 4);
}

void changeContractStatus(int id, int newStatus){
	if(newStatus < 1 || newStatus > 3)
	return printColorful("Valor de status desconhecido.\n", 1);
	
	Contract *c = findContractById(id);
	
	if(c == NULL)
	return printColorful("Contrato não encontrado.\n", 1);
	
	c->contractStatus = newStatus;
	saveContractsData();
	
	printColorful("Contrato atualizado com sucesso!\n", 2);
}