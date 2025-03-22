#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Contract/Contract.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"

void findAllContracts();
Contract *findContractById(double id);
void createContract(Contract contract); 
void deleteContract(double id); 

void printContract(Contract c);
void printContractById(double id);
void findContractsByOwner(double id);
void findContractsByTenant(double id);
void changeContractStatus(double id, int status);

void findAllContracts(){
	if(contractsLength == 0)
	return printColorful("Não há contratos registrados.\n", 4);
	
	for (int ii = 0; ii < contractsLength; ii++){
		printContract(contracts[ii]);
	}
}

void findContractsByTenantRg(char tenantRg[]){
	if(contractsLength == 0)
	return printColorful("Não há contratos registrados.\n", 4);
	
	int contractsFound = 0;
	for (int ii = 0; ii < contractsLength; ii++){
		if(strcmp(contracts[ii].tenant->rg, tenantRg) == 0){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	printColorful("Não foram encontrados contratos.\n", 4);
}

Contract *findContractById(double id){
	for (int ii = 0; ii < contractsLength; ii++){
		if(contracts[ii].id == id){
			return &contracts[ii];
		}
	}
	
	return NULL;
}

int contractExistsById(double id){
	return findContractById(id) == NULL ? 0 : 1;
}

void createContract(Contract contract){
	contracts[contractsLength].id = contractsLength + 1;
	strcpy(contracts[contractsLength].contractStartDate, contract.contractStartDate);
	strcpy(contracts[contractsLength].contractEndDate, contract.contractEndDate);
	contracts[contractsLength].defaultRentalValue = contract.defaultRentalValue;
	contracts[contractsLength].contractStatus = contract.contractStatus;
	contracts[contractsLength].invoiceDueDate = contract.invoiceDueDate;
	contracts[contractsLength].residence = contract.residence;
	contracts[contractsLength].tenant = contract.tenant;
	contractsLength++;
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou um contrato cujo imóvel é o de código %0.lf, e inquilino de nome %s!\n", contract.residence->id, contract.tenant->name);
	printColorful(welcomeText, 2);
	
	if(contractsLength == contractsCurrentLimit)
	allocateMoreSpaceContract();
}

void deleteContract(double id){
	if(!contractExistsById(id)){
		printColorful("Contrato não encontrado.\n", 1);
		return;
	}
	
	for (int ii = 0; ii < contractsLength; ii++){
		if(contracts[ii].id == id){			
			int indLastItemOfContracts = contractsLength-1;
			contracts[ii] = contracts[indLastItemOfContracts];
			contractsLength--;
			printColorful("Contrato deletado com sucesso!\n", 2);
			return;
		}
	}
	
	return printColorful("Contrato não encontrado.\n", 1);
}

void printContract(Contract c){
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
	printf("\n____\n");
}

void printContractById(double id){
	Contract *c = findContractById(id);
	
	if(c == NULL)
	return printColorful("Contrato não encontrado.\n", 1);
	
	printContract(*c);
}

void findContractsByOwner(double ownerId){
	int contractsFound = 0;
	
	for (int ii = 0; ii < contractsLength; ii++){
		if(contracts[ii].residence->ownerId == ownerId){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	return printColorful("Não há contratos registrados.\n", 4);
}

void findContractsByTenant(double tenantId){
	int contractsFound = 0;
	
	for (int ii = 0; ii < contractsLength; ii++){
		if(contracts[ii].tenant->id == tenantId){
			contractsFound++;
			printContract(contracts[ii]);
		}
	}
	
	if(contractsFound == 0)
	return printColorful("Não há contratos registrados.\n", 4);
}

void changeContractStatus(double id, int newStatus){
	if(newStatus < 1 || newStatus > 3)
	return printColorful("Valor de status desconhecido.\n", 1);
	
	Contract *c = findContractById(id);
	
	if(c == NULL)
	return printColorful("Contrato não encontrado.\n", 1);
	
	c->contractStatus = newStatus;
	
	printColorful("Contrato atualizado com sucesso!\n", 2);
}