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

void findAllTenants();
void createTenant(Tenant Tenant);
int findTenantByRg(char rg[]);