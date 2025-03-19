#ifndef DTOS_H
#define DTOS_H

typedef struct {
    double id; // PK
    char name[100];
    char phone[16]; // Unique
    char email[255]; // Unique
    char password[100];
    char rg[13]; // Unique
    char cpf[15]; // Unique
    int tenantStatus;
    char dateOfBirth[11]; //Desnecessário
    char registrationDate[11]; //Desnecessário
} Tenant;

typedef struct {
    char email[255];
    char password[100];
} LoginCredentials;

typedef struct {
    double id; // PK
    char name[100];
    char phone[16]; // Unique
    char email[255]; // Unique
    char password[100];
} Owner;

typedef struct {
    double id;
    int userType; // 1 = ADM, 2 = OWNER, 3 = TENANT
} AuthUser;

typedef struct {
    double id;
    int userType; // 1 = ADM, 2 = OWNER, 3 = TENANT
    char name[100];
} AuthUserResponse;

typedef struct 
{
    double id;
    int propertyType; 
    int occupancyStatus; 
    double rentalValue;
    // Address
    Owner owner;
} Residence;

typedef struct{
    double id;
    char contractStartDate[11];
    char contractEndDate[11];
    double defaultRentalValue;
    int contractStatus;
    int invoiceDueDate;
    Residence residence;
    Tenant tenant;
} Contract;

#endif