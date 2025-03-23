#ifndef ADM_SERVICE_H
#define ADM_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllAdms();
Adm *findAdmById(int id);
Adm *findAdmByEmail(char email[]);
void createAdm(Adm adm);

#endif