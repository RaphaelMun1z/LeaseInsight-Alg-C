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
#include "../ownerService/ownerService.h"

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
		Tenant *t = findTenantById(contracts[ii].tenantId);
		
		if(strcmp(t->rg, tenantRg) == 0){
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
	Residence *r = findResidenceById(contract.residenceId);

	if(r == NULL){
		printColorful("Propriedade não encontrada.\n", 1);
		return;
	}

	if((*r).occupancyStatus != 6){
		printColorful("Propriedade não disponível para locação.\n", 1);
		return;
	}

	Tenant *t = findTenantById(contract.tenantId);
	
	if(t == NULL){
		printColorful("Inquilino não encontrado.\n", 1);
		return;
	}

	if((*t).tenantStatus != 1){
		printColorful("Conta de Inquilino não está ativa.\n", 1);
		return;
	}
	
	contracts[registeredContractsNumber].id = registeredContractsNumber + 1;
	strcpy(contracts[registeredContractsNumber].contractStartDate, contract.contractStartDate);
	strcpy(contracts[registeredContractsNumber].contractEndDate, contract.contractEndDate);
	contracts[registeredContractsNumber].defaultRentalValue = contract.defaultRentalValue;
	contracts[registeredContractsNumber].contractStatus = contract.contractStatus;
	contracts[registeredContractsNumber].invoiceDueDate = contract.invoiceDueDate;
	contracts[registeredContractsNumber].residenceId = contract.residenceId;
	contracts[registeredContractsNumber].tenantId = contract.tenantId;
	registeredContractsNumber++;
	saveContractsData();
	
	char welcomeText[200];
	snprintf(welcomeText, sizeof(welcomeText), "\nVocê registrou um contrato cuja propriedade está localizada em %s, %d, %s, %s, %s, %s, e inquilino de nome %s!\n", (*r).address.street, (*r).address.number, (*r).address.complement, (*r).address.district, (*r).address.city, (*r).address.state, (*t).name);
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

	return;

	// Tenant
	Tenant *t = findTenantById(c.tenantId);
	printColorful("Inquilino:\n", 3);
	printf("   Código inquilino: %d\n", (*t).id);
	printf("   Status do inquilino: %d\n", (*t).tenantStatus);
	printf("   RG do inquilino: %s\n", (*t).rg);
	
	// Residence
	Residence *r = findResidenceById(c.residenceId);
	printColorful("Propriedade:\n", 3);
	printf("   Código da propriedade: %d\n", (*r).id);
	printf("   Endereço da propriedade: %s, %d, %s, %s, %s, %s\n", (*r).address.street, (*r).address.number, (*r).address.complement, (*r).address.district, (*r).address.city, (*r).address.state);

	// Owner
	Owner *o = findOwnerById((*r).ownerId);
	printColorful("Proprietário:\n", 3);
	printf("   Código do proprietário da propriedade: %d\n", (*o).id);
	printf("   Nome do proprietário da propriedade: %s\n", (*o).name);
	
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
		Residence *r = findResidenceById(contracts[ii].residenceId);
		if((*r).ownerId == ownerId){
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
		if(contracts[ii].tenantId == tenantId){
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