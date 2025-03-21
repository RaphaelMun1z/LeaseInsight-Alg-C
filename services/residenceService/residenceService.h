#ifndef RESIDENCE_SERVICE_H
#define RESIDENCE_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void printResidence(Residence r);
void findAllResidences();
Residence *findResidenceById(double id);
void changeResidenceOccupancyStatus(double id, int status);
void createResidence(Residence residence); 

void findResidencesByOwner(double id);

#endif