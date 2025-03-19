#ifndef CONTRACT_H
#define CONTRACT_H

typedef struct {
    double id;
    int contractStatus;
    double defaultRentalValue;
    int invoiceDueDate;
    char contractStartDate[11];
    char contractEndDate[11];
} Contract;

extern Contract *contracts;
extern int contractsLength;

void initContracts();
void freeContracts();

#endif