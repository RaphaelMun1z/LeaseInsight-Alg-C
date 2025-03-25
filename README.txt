=== Documentação ===

1. Como gerar o executável
2. Como executar o executável
3. [Opcional] Execução rápida.
4. Usuários Cadastrados.
   4.1 Inquilinos
   4.2 Proprietários
____

1. Para gerar o executável do projeto, siga os seguintes passos:
1.1. Abra o CMD;
1.2. Acesse o diretório raíz do projeto;
1.3. Utilize o seguinte comando [copie os comandos da linha 13 até 56, de uma só vez, e cole no cmd]:
gcc app.c ^
utils/printColorful/printColorful.c ^
utils/cleanScreen/cleanScreen.c ^
utils/cleanInputBuffer/cleanInputBuffer.c ^
utils/verifyInputContent/verifyInputContent.c ^
utils/enums/enums.c ^
utils/cancelOperation/cancelOperation.c ^
views/startScreen/startScreen.c ^
views/menus/menuHandler/menuHandler.c ^
views/menus/mainMenu/mainMenu.c ^
views/menus/tenantMenu/tenantMenu.c ^
views/menus/ownerMenu/ownerMenu.c ^
views/menus/admMenu/admMenu.c ^
views/menus/admMenu/contractManagerAdmMenu/contractManagerAdmMenu.c ^
views/menus/admMenu/residenceManagerAdmMenu/residenceManagerAdmMenu.c ^
views/menus/admMenu/usersManagerMenu/usersManagerMenu.c ^
views/menus/admMenu/usersManagerMenu/tenantManagerAdmMenu/tenantManagerAdmMenu.c ^
views/menus/admMenu/usersManagerMenu/ownerManagerAdmMenu/ownerManagerAdmMenu.c ^
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
controllers/updateResidenceController/updateResidenceController.c ^
services/dataPersistenceService/dataPersistenceService.c ^
services/reportHandlerService/reportHandlerService.c ^
services/stateManagerService/stateManagerService.c ^
services/userService/userService.c ^
services/admService/admService.c ^
services/tenantService/tenantService.c ^
services/ownerService/ownerService.c ^
services/contractService/contractService.c ^
services/residenceService/residenceService.c ^
services/authService/authService.c ^
-o application

2. Para executar o executável do projeto, siga os seguintes passos:
2.1. Abra o CMD;
2.2. Acesse o diretório raíz do projeto;
2.3. Utilize o seguinte comando: start ./application

____

3. Para executar via arquivo BAT, siga os seguintes passos:
3.1. Abra o CMD;
3.2. Acesse o diretório raíz do projeto;
3.3. Execute o comando: build.bat

____

4. Usuários Cadastrados.

4.1 Inquilinos (Tenant)
Email: ana.silva@email.com
Senha: senha1234

Email: carlos.souza@email.com
Senha: senha@2025

Email: mariana.lima@email.com
Senha: abc@2025

Email: felipe.pinto@email.com
Senha: felipe@123

Email: larissa.reis@email.com
Senha: larissa456

Email: renato.costa@email.com
Senha: Renato_2025

Email: juliana.souza@email.com
Senha: juliana@2025

Email: tiago.moura@email.com
Senha: tiago@123

Email: beatriz.melo@email.com
Senha: beatriz@456

Email: eduardo.braga@email.com
Senha: eduardo@2025


4.2 Proprietários (Owners)
Email: joao.fernandes@email.com
Senha: Joao_2025

Email: camila.costa@email.com
Senha: camila@456

Email: rafael.dias@email.com
Senha: rafael@2025

Email: bruna.mota@email.com
Senha: bruna@123

Email: henrique.lima@email.com
Senha: henrique@789

Email: aline.pires@email.com
Senha: aline@2025

Email: leonardo.rocha@email.com
Senha: leo_2025

Email: fernanda.queiroz@email.com
Senha: fer@123

Email: diego.nunes@email.com
Senha: diego@456

Email: patricia.vieira@email.com
Senha: patricia@789

Desenvolvido por:
- Raphael Muniz Varela
- Ygor Marangoni Sgarioni