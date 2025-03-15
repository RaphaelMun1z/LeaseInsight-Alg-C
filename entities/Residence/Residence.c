typedef struct {
    double id; // PK
    int propertyType;
    int occupancyStatus;
    char description[255];
    double marketValue;
    double rentalValue;
    double totalArea;
    double builtArea;
    int aptNumber;
    int numberBedrooms;
    int numberBathrooms;
    int numberSuites;
    int garageSpaces;
    int yearConstruction;
    char complement[100];
    char dateLastRenovation[11];
} Residence;