#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

// Entities
#include "../../entities/Contract/Contract.h"

// Services
#include "../stateManagerService/stateManagerService.h"
#include "../authService/authService.h"

void findAllContracts(){
	if(contractsLength == 0)
	return printColorful("Não há contratos registrados.\n", 4);
	
	for (int ii = 0; ii < contractsLength; ii++){
		printf("\nID: %.0lf\n", contracts[ii].id);
		printf("Status: ", contracts[ii].contractStatus);
		if (contracts[ii].contractStatus == 1) printColorful("Ativo\n", 2);
		else if (contracts[ii].contractStatus == 2) printColorful("Inativo\n", 1);
		else if (contracts[ii].contractStatus == 3) printColorful("Aprovação pendente\n", 4);
		else printColorful("Desconhecido\n", 5); 
		printf("Valor do aluguel: %.2lf\n", contracts[ii].defaultRentalValue);
		printf("Data de início: %s\n", contracts[ii].contractStartDate);
		printf("Data de término: %s\n", contracts[ii].contractEndDate);
		printf("Dia de vencimento: %d\n", contracts[ii].invoiceDueDate);
		printf("\n____\n");
	}
}

void findContractsByOwner(double ownerId){
	int contractsFound = 0;
	
	for (int ii = 0; ii < contractsLength; ii++){
		if(contracts[ii].residence->ownerId == ownerId){
			printf("\nID: %.0lf\n", contracts[ii].id);
			printf("Status: ", contracts[ii].contractStatus);
			if (contracts[ii].contractStatus == 1) printColorful("Ativo\n", 2);
			else if (contracts[ii].contractStatus == 2) printColorful("Inativo\n", 1);
			else if (contracts[ii].contractStatus == 3) printColorful("Aprovação pendente\n", 4);
			else printColorful("Desconhecido\n", 5); 
			printf("Valor do aluguel: %.2lf\n", contracts[ii].defaultRentalValue);
			printf("Data de início: %s\n", contracts[ii].contractStartDate);
			printf("Data de término: %s\n", contracts[ii].contractEndDate);
			printf("Dia de vencimento: %d\n", contracts[ii].invoiceDueDate);
			printf("Nome do Inquilino: %s\n", contracts[ii].tenant->name);
			printf("E-mail do Inquilino: %s\n", contracts[ii].tenant->email);
			printf("Código da propriedade: %.0lf\n", contracts[ii].residence->id);
			printf("\n____\n");
		}
	}
	
	if(contractsFound == 0)
	return printColorful("Não há contratos registrados.\n", 4);
}

Contract *findContractById(double id){
	
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

void changeContractStatus(double id, int status){
	
}
