#ifndef ADM_SERVICE_H
#define ADM_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllAdms();
Adm *findAdmById(double id);
Adm *findAdmByEmail(char email[]);
void createAdm(Adm adm);

#endif