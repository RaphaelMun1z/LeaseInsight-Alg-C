@echo off

gcc app.c ^
utils/printColorful/printColorful.c ^
utils/cleanScreen/cleanScreen.c ^
utils/cleanInputBuffer/cleanInputBuffer.c ^
utils/cancelOperation/cancelOperation.c ^
views/startScreen/startScreen.c ^
views/menus/menuHandler/menuHandler.c ^
views/menus/mainMenu/mainMenu.c ^
views/menus/tenantMenu/tenantMenu.c ^
views/menus/ownerMenu/ownerMenu.c ^
views/menus/admMenu/admMenu.c ^
views/menus/ownerMenu/residenceManagerMenu/residenceManagerMenu.c ^
views/menus/ownerMenu/contractManagerMenu/contractManagerMenu.c ^
views/menus/registerMenu/registerMenu.c ^
entities/GenericUser/GenericUser.c ^
entities/AuthUser/AuthUser.c ^
entities/Adm/Adm.c ^
entities/Tenant/Tenant.c ^
entities/Owner/Owner.c ^
entities/Residence/Residence.c ^
entities/Contract/Contract.c ^
controllers/registerController/registerController.c ^
controllers/signInController/signInController.c ^
controllers/registerContractController/registerContractController.c ^
controllers/registerResidenceController/registerResidenceController.c ^
services/stateManagerService/stateManagerService.c ^
services/userService/userService.c ^
services/admService/admService.c ^
services/tenantService/tenantService.c ^
services/ownerService/ownerService.c ^
services/contractService/contractService.c ^
services/residenceService/residenceService.c ^
services/authService/authService.c ^
-o application

echo Compilação concluída!

start ./application