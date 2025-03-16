@echo off

gcc app.c ^
utils/printColorful/printColorful.c ^
utils/cleanScreen/cleanScreen.c ^
utils/cleanInputBuffer/cleanInputBuffer.c ^
views/startScreen/startScreen.c ^
views/menus/mainMenu/mainMenu.c ^
entities/Tenant/Tenant.c ^
entities/Residence/Residence.c ^
entities/Contract/Contract.c ^
controllers/registerController/registerController.c ^
controllers/signInController/signInController.c ^
services/registerService/registerService.c ^
services/tenantService/tenantService.c ^
-o application

echo Compilação concluída!

start ./application