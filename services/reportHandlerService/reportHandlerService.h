#ifndef REPORT_HANDLER_SERVICE_H
#define REPORT_HANDLER_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void generateContractsReport(Contract *selectedContracts, int itemsAmount, char dateFiltered[]);

#endif