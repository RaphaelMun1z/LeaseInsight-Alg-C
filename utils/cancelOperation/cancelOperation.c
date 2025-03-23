#include <stdio.h>
#include <string.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

int cancelOperationWithString(char value[]){
    if(strcasecmp(value, "sair") == 0){
        printColorful("\nCancelando operação...\n", 5);
        return 1;
    }
    return 0;
}

int cancelOperationWithInt(int value){
    if(value == -1){
        printColorful("\nCancelando operação...\n", 5);
        return 1;
    }
    return 0;
}

int cancelOperationWithDouble(double value){
    if(value == -1){
        printColorful("\nCancelando operação...\n", 5);
        return 1;
    }
    return 0;
}