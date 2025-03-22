#ifndef RESIDENCE_SERVICE_H
#define RESIDENCE_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllResidences();
Residence *findResidenceById(double id);
void createResidence(Residence residence); 
void deleteResidence(double id); 

void printResidence(Residence r);
void printResidenceById(double id);
int residenceExistsById(double id);
void findResidencesByOwner(double id);
void changeResidenceOccupancyStatus(double id, int status);
void changeResidenceDetails(double id, double newRentalValue, int newOccupancyStatus);

#endif