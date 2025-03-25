#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/cleanInputBuffer/cleanInputBuffer.h"
#include "../../utils/printColorful/printColorful.h"
#include "../../utils/cleanScreen/cleanScreen.h"
#include "../../utils/cancelOperation/cancelOperation.h"
#include "../../utils/enums/enums.h"

// Services
#include "../../services/contractService/contractService.h"
#include "../../services/tenantService/tenantService.h"
#include "../../services/residenceService/residenceService.h"

void registerContractForm(){
    Contract newContract;
    
    printColorful("\nPreencha os campos a seguir para registrar o contrato.", 3);
    printColorful("\n[DICA] Para cancelar operação, digite: 'Sair', ou '-1' em campos numéricos.\n\n", 5);
    
    do {
        cleanInputBuffer();
        printColorful("Data de início do contrato: ", 5);
        fgets(newContract.contractStartDate, 11, stdin);
        newContract.contractStartDate[strcspn(newContract.contractStartDate, "\n")] = 0;
        
        if(cancelOperationWithString(newContract.contractStartDate)) return;
        
        if(newContract.contractStartDate[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Data de início do contrato' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newContract.contractStartDate[0] == '\0');
    
    do {
        cleanInputBuffer();
        printColorful("Data de validade do contrato: ", 5);
        fgets(newContract.contractEndDate, 11, stdin);
        newContract.contractEndDate[strcspn(newContract.contractEndDate, "\n")] = 0;
        
        if(cancelOperationWithString(newContract.contractEndDate)) return;
        
        if(newContract.contractEndDate[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'Data de validade do contrato' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newContract.contractEndDate[0] == '\0');
    
    do {
        cleanInputBuffer();
        printColorful("Valor de locação: ", 5);
        scanf("%lf", &newContract.defaultRentalValue);
        
        if(cancelOperationWithInt(newContract.defaultRentalValue)) return;
        
        if(newContract.defaultRentalValue <= 0){
            cleanScreen();
            printColorful("\nO Campo 'Valor de locação' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newContract.defaultRentalValue <= 0);
    
    do {
        cleanInputBuffer();
        getContractStatusOptions();
        scanf("%d", &newContract.contractStatus);
        
        if(cancelOperationWithInt(newContract.contractStatus)) return;
        
        if(newContract.contractStatus < 1 || newContract.contractStatus > 12){
            cleanScreen();
            printColorful("\nO Campo 'Status' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newContract.contractStatus < 1 || newContract.contractStatus > 12);
    
    do {
        cleanInputBuffer();
        printColorful("Dia de vencimento da mensalidade: ", 5);
        scanf("%d", &newContract.invoiceDueDate);
        
        if(cancelOperationWithInt(newContract.invoiceDueDate)) return;
        
        if(newContract.invoiceDueDate < 1 || newContract.invoiceDueDate > 31){
            cleanScreen();
            printColorful("\nO Campo 'Dia de vencimento da mensalidade' é obrigatório. Tente novamente.\n\n", 4);
        }
    } while (newContract.invoiceDueDate < 1 || newContract.invoiceDueDate > 31);
    
    int propertyId;
    Residence *propertyFound = NULL;
    do {
        cleanInputBuffer();
        printColorful("Código da propriedade: ", 5);
        scanf("%d", &propertyId);
        
        if(cancelOperationWithInt(propertyId)) return;
        
        if(propertyId < 1){
            cleanScreen();
            printColorful("\nO Campo 'Código da propriedade' é obrigatório. Tente novamente.\n\n", 4);
        }else{
            propertyFound = findResidenceById(propertyId);
            if(propertyFound == NULL){
                cleanScreen();
                printColorful("\nO código informado é inválido. Tente novamente.\n", 4);
                printColorful("\n[DICA] Para cancelar operação, digite: '-1'\n\n", 5);
            }else if(propertyFound->occupancyStatus != 6){
                cleanScreen();
                printColorful("\nA propriedade informada não está disponível. Tente outra propriedade.\n", 4);
                printColorful("\n[DICA] Para cancelar operação, digite: '-1'\n\n", 5);
                propertyFound = NULL;
            }
        }
    } while (propertyId < 1 || propertyFound == NULL);
    newContract.residenceId = propertyId;

    char tenantRg[13];
    Tenant *tenantFound = NULL;
    do{
        cleanInputBuffer();
        printColorful("RG do Inquilino (Ex.: 11.111.111-1): ", 5);
        fgets(tenantRg, 13, stdin);
        tenantRg[strcspn(tenantRg, "\n")] = 0;
        
        if(cancelOperationWithString(tenantRg)) return;
        
        if(tenantRg[0] == '\0'){
            cleanScreen();
            printColorful("\nO Campo 'RG do Inquilino' é obrigatório. Tente novamente.\n\n", 4);
        }else{
            tenantFound = findTenantByRg(tenantRg);
            if(tenantFound == NULL){
                cleanScreen();
                printColorful("\nO RG informado é inválido. Tente novamente.\n", 4);
                printColorful("\n[DICA] Para cancelar operação, digite: '-1'\n\n", 5);
            }else if(tenantFound->tenantStatus != 1){
                cleanScreen();
                printColorful("\nO inquilino informado não está disponível. Tente outro inquilino.\n", 4);
                printColorful("\n[DICA] Para cancelar operação, digite: '-1'\n\n", 5);
                propertyFound = NULL;
            }
        }
    } while (tenantRg[0] == '\0' || tenantFound == NULL);
    newContract.tenantId = tenantFound->id;
    
    cleanScreen();
    createContract(newContract);
}