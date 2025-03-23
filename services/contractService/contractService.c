#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Contract/Contract.h"

// Services
#include "../dataPersistenceService/dataPersistenceService.h"
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"

void findAllContracts();
Contract *findContractById(int id);
void createContract(Contract contract); 
void deleteContract(int id); 

void printContract(Contract c);
void printContractById(int id);
void findContractsByOwner(int id);
void findContractsByTenant(int id);
void changeContractStatus(int id, int status);

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
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou um contrato cujo imóvel é o de código %d e inquilino de nome %s!\n", contract.residence.id, contract.tenant.name);
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
	printf("\nID: %d\n", c.id);
	printf("Status: ", c.contractStatus);
	if (c.contractStatus == 1) printColorful("Ativo\n", 2);
	else if (c.contractStatus == 2) printColorful("Inativo\n", 1);
	else if (c.contractStatus == 3) printColorful("Aprovação pendente\n", 4);
	else printColorful("Desconhecido\n", 5); 
	printf("Valor do aluguel: %.2lf\n", c.defaultRentalValue);
	printf("Data de início: %s\n", c.contractStartDate);
	printf("Data de término: %s\n", c.contractEndDate);
	printf("Dia de vencimento: %d\n", c.invoiceDueDate);
	printf("ID inquilino: %d\n", c.tenant.id);
	printf("ID proprietário do imóvel: %d\n", c.residence.ownerId);
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
			Contract c = contracts[ii];
			printf("\nID: %.0lf\n", c.id);
			printf("Status: ", c.contractStatus);
			if (c.contractStatus == 1) printColorful("Ativo\n", 2);
			else if (c.contractStatus == 2) printColorful("Inativo\n", 1);
			else if (c.contractStatus == 3) printColorful("Aprovação pendente\n", 4);
			else printColorful("Desconhecido\n", 5); 
			printf("Valor do aluguel: %.2lf\n", c.defaultRentalValue);
			printf("Data de início: %s\n", c.contractStartDate);
			printf("Data de término: %s\n", c.contractEndDate);
			printf("Dia de vencimento: %d\n", c.invoiceDueDate);
			printf("Status do inquilino: %d\n", c.tenant.tenantStatus);
			printf("RG do inquilino: %s\n", c.tenant.rg);
			printf("ID da residencia: %.0lf\n", c.residence.id);
			printf("ID do proprietário da residencia: %.0lf\n", c.residence.ownerId);
			printf("\n____\n");
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