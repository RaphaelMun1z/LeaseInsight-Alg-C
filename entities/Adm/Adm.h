#ifndef ADM_H
#define ADM_H

// DTOs
#include "../../dtos/dtos.h"

extern Adm *adms;
extern int registeredAdmsNumber;
extern int admsCurrentLimit;

void initAdms();
void allocateMoreSpaceAdm();
void deallocateSpaceAdm();
void allocateSpaceAdmForFile(int numberOfAdms);
void freeAdms();

#endif