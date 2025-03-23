#ifndef RESIDENCE_SERVICE_H
#define RESIDENCE_SERVICE_H

// DTOs
#include "../../dtos/dtos.h"

void findAllResidences();
Residence *findResidenceById(int id);
void createResidence(Residence residence); 
void deleteResidence(int id); 

void printResidence(Residence r);
void printResidenceById(int id);
int residenceExistsById(int id);
void findResidencesByOwner(int id);
void changeResidenceOccupancyStatus(int id, int status);
void changeResidenceDetails(int id, double newRentalValue, int newOccupancyStatus, int changeAddress, Address newAddress);

#endif