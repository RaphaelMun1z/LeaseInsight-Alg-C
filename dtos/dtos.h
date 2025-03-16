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
    char dateOfBirth[11]; 
    char registrationDate[11];
} Tenant;

typedef struct {
    char email[255];
    char password[100];
} TenantLogin;

typedef struct {
    double id;
    int userType; // 1 = ADM, 2 = OWNER, 3 = TENANT
} AuthUser;

#endif

