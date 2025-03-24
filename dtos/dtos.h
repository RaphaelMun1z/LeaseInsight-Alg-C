#ifndef DTOS_H
#define DTOS_H

typedef struct {
    int id; // PK
    char name[100];
    char email[255]; // Unique
    char password[100];
} Adm;

typedef struct {
    int id; // PK
    char name[100];
    char phone[16];
    char email[255]; // Unique
    char password[100];
    char rg[13]; // Unique
    char cpf[15];
    int tenantStatus;
} Tenant;

typedef struct {
    char email[255];
    char password[100];
} LoginCredentials;

typedef struct {
    int number;
    char complement[100];
    char street[100];
    char district[100];
    char city[100];
    char state[100];
    char cep[10];
} Address;

typedef struct 
{
    int id;
    int propertyType; 
    int occupancyStatus;
    double rentalValue;
    int ownerId;
    Address address;
} Residence;

typedef struct Owner {
    int id; // PK
    char name[100];
    char phone[16];
    char email[255];
    char password[100];
} Owner;

typedef struct {
    int id;
    int userType; // 1 = ADM, 2 = OWNER, 3 = TENANT
} AuthUser;

typedef struct {
    int id;
    int userType; // 1 = ADM, 2 = OWNER, 3 = TENANT
    char name[100];
} AuthUserResponse;

typedef struct{
    int id;
    char contractStartDate[11];
    char contractEndDate[11];
    double defaultRentalValue;
    int contractStatus;
    int invoiceDueDate;
    int residenceId; // Residence
    int tenantId; // Tenant
} Contract;

#endif