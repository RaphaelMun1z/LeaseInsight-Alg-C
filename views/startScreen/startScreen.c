#include <stdio.h>
#include <stdlib.h>

// Utils
#include "../../utils/printColorful/printColorful.h"

void startScreen(){
    printColorful("======================================\n", 3);
    printColorful("===========  ", 3);
    printColorful("LEASEINSIGHT", 3);
    printColorful("  ===========\n", 3);
    printColorful("======================================\n", 3);
    printColorful("Administração de locação de imóveis\n", 5);
    printColorful("Copyright © 2025 LeaseInsight. Todos os direitos reservados.\n", 5);
    printColorful("Desenvolvido por: Raphael e Ygor\n\n", 5);
}