@echo off

gcc app.c ^
utils/printColorful/printColorful.c ^
utils/cleanScreen/cleanScreen.c ^
utils/cleanInputBuffer/cleanInputBuffer.c ^
views/startScreen/startScreen.c ^
views/menus/menuHandler/menuHandler.c ^
views/menus/mainMenu/mainMenu.c ^
views/menus/tenantMenu/tenantMenu.c ^
views/menus/ownerMenu/ownerMenu.c ^
views/menus/registerMenu/registerMenu.c ^
entities/AuthUser/AuthUser.c ^
entities/Tenant/Tenant.c ^
entities/Owner/Owner.c ^
entities/Residence/Residence.c ^
entities/Contract/Contract.c ^
controllers/registerController/registerController.c ^
controllers/signInController/signInController.c ^
services/stateManagerService/stateManagerService.c ^
services/tenantService/tenantService.c ^
services/ownerService/ownerService.c ^
services/authService/authService.c ^
-o application

echo Compilação concluída!

start ./application