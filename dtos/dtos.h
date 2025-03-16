#ifndef DTOS_H
#define DTOS_H

typedef struct {
    char name[100];
    char phone[16];
    char email[255];
    char password[100];
    char rg[13]; // PK
    char cpf[15];
    int tenantStatus;
    char dateOfBirth[11]; 
    char registrationDate[11];
} Tenant;

typedef struct {
    char rg[13];
    char password[100];
} TenantLogin;

#endif

