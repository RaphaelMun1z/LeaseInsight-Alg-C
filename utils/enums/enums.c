#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

void getResidenceType(int residenceType, char *residenceTypeStr){
    switch(residenceType){
        case 1:
        strcpy(residenceTypeStr, "Casa");
        break;
        case 2:
        strcpy(residenceTypeStr, "Condomínio");
        break;
        case 3:
        strcpy(residenceTypeStr, "Fazenda");
        break;
        case 4:
        strcpy(residenceTypeStr, "Galpão");
        break;
        case 5:
        strcpy(residenceTypeStr, "Apartamento Comercial");
        break;
        case 6:
        strcpy(residenceTypeStr, "Loja de Varejo");
        break;
        case 7:
        strcpy(residenceTypeStr, "Apartamento");
        break;
        case 8:
        strcpy(residenceTypeStr, "Terreno");
        break;
        default:
        strcpy(residenceTypeStr, "Tipo de propriedade não encontrado");
        break;
    }
    
}

void getResidenceOccupancyStatus(int residenceOccupancyStatus, char *residenceOccupancyStatusStr){
    switch(residenceOccupancyStatus){
        case 1:
        strcpy(residenceOccupancyStatusStr, "Ocupado");
        break;
        case 2:
        strcpy(residenceOccupancyStatusStr, "Pendente de Entrada");
        break;
        case 3:
        strcpy(residenceOccupancyStatusStr, "Pendente de Saída");
        break;
        case 4:
        strcpy(residenceOccupancyStatusStr, "Em Manutenção");
        break;
        case 5:
        strcpy(residenceOccupancyStatusStr, "Arrendado");
        break;
        case 6:
        strcpy(residenceOccupancyStatusStr, "Disponível");
        break;
        case 7:
        strcpy(residenceOccupancyStatusStr, "Reservado");
        break;
        default:
        strcpy(residenceOccupancyStatusStr, "Status de ocupação não encontrado");
        break;
    }
    
}

void getContractStatus(int contractStatus, char *contractStatusStr){
    switch(contractStatus){
        case 1:
        strcpy(contractStatusStr, "Ativo");
        break;
        case 2:
        strcpy(contractStatusStr, "Finalizado");
        break;
        case 3:
        strcpy(contractStatusStr, "Expirado");
        break;
        case 4:
        strcpy(contractStatusStr, "Pendente de Aprovação");
        break;
        case 5:
        strcpy(contractStatusStr, "Aprovado");
        break;
        case 6:
        strcpy(contractStatusStr, "Rejeitado");
        break;
        case 7:
        strcpy(contractStatusStr, "Em Revisão");
        break;
        case 8:
        strcpy(contractStatusStr, "Renovado");
        break;
        case 9:
        strcpy(contractStatusStr, "Cancelado");
        break;
        case 10:
        strcpy(contractStatusStr, "Suspenso");
        break;
        case 11:
        strcpy(contractStatusStr, "Em Negociação");
        break;
        case 12:
        strcpy(contractStatusStr, "Em Espera");
        break;
        default:
        strcpy(contractStatusStr, "Status de contrato não encontrado");
        break;
    }
}

void getTenantStatus(int tenantStatus, char *tenantStatusStr){
    switch(tenantStatus){
        case 1:
        strcpy(tenantStatusStr, "Ativo");
        break;
        case 2:
        strcpy(tenantStatusStr, "Inativo");
        break;
        case 3:
        strcpy(tenantStatusStr, "Pendente");
        break;
        default:
        strcpy(tenantStatusStr, "Status de inquilino não encontrado");
        break;
    }
}

void getResidenceTypeOptions(){
    printColorful("Qual o tipo de propriedade:\n", 5);
    printColorful("1 - Casa\n", 5);
    printColorful("2 - Condomínio\n", 5);
    printColorful("3 - Fazenda\n", 5);
    printColorful("4 - Galpão\n", 5);
    printColorful("5 - Apartamento Comercial\n", 5);
    printColorful("6 - Loja de Varejo\n", 5);
    printColorful("7 - Apartamento\n", 5);
    printColorful("8 - Terreno\n", 5);
}

void getResidenceOccupancyStatusOptions(){
    printColorful("Qual o status de ocupação:\n", 5);
    printColorful("1 - Ocupado\n", 5);
    printColorful("2 - Pendente de Entrada\n", 5);
    printColorful("3 - Pendente de Saída\n", 5);
    printColorful("4 - Em Manutenção\n", 5);
    printColorful("5 - Arrendado\n", 5);
    printColorful("6 - Disponível\n", 5);
    printColorful("7 - Reservado\n", 5);
}

void getContractStatusOptions(){
    printColorful("Qual o status do contrato:\n", 5);
    printColorful("1 - Ativo\n", 5);
    printColorful("2 - Finalizado\n", 5);
    printColorful("3 - Expirado\n", 5);
    printColorful("4 - Pendente de Aprovação\n", 5);
    printColorful("5 - Aprovado\n", 5);
    printColorful("6 - Rejeitado\n", 5);
    printColorful("7 - Em Revisão\n", 5);
    printColorful("8 - Renovado\n", 5);
    printColorful("9 - Cancelado\n", 5);
    printColorful("10 - Suspenso\n", 5);
    printColorful("11 - Em Negociação\n", 5);
    printColorful("12 - Em Espera\n", 5);
}

void getTenantStatusOptions(){
    printColorful("Qual o status do inquilino:\n", 5);
    printColorful("1 - Ativo\n", 5);
    printColorful("2 - Inativo\n", 5);
    printColorful("3 - Pendente\n", 5);
}