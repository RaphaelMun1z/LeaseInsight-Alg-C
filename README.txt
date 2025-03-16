=== Documentação ===

1. Como gerar o executável
2. Como executar o executável
3. [Opcional] Execução rápida.

____

1. Para gerar o executável do projeto, siga os seguintes passos:
1.1. Abra o CMD;
1.2. Acesse o diretório raíz do projeto;
1.3. Utilize o seguinte comando [copie os comandos da linha 12 até 25, de uma só vez, e cole no cmd]:
gcc app.c ^
utils/printColorful/printColorful.c ^
utils/cleanScreen/cleanScreen.c ^
utils/cleanInputBuffer/cleanInputBuffer.c ^
views/startScreen/startScreen.c ^
views/menus/mainMenu/mainMenu.c ^
views/menus/registerMenu/registerMenu.c ^
entities/Tenant/Tenant.c ^
entities/Residence/Residence.c ^
entities/Contract/Contract.c ^
controllers/registerController/registerController.c ^
controllers/signInController/signInController.c ^
services/registerService/registerService.c ^
services/tenantService/tenantService.c ^
-o application

3. Para executar via arquivo BAT, siga os seguintes passos:
3.1. Abra o CMD;
3.2. Acesse o diretório raíz do projeto;
3.3. Execute o comando: build.bat

____

2. Para executar o executável do projeto, siga os seguintes passos:
2.1. Abra o CMD;
2.2. Acesse o diretório raíz do projeto;
2.3. Utilize o seguinte comando: start ./application

____

Desenvolvido por:
- Raphael Muniz Varela
- Ygor Marangoni Sgarioni