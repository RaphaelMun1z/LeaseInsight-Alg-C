=== Documentação ===

1. Como gerar o executável
2. Como executar o executável

____

1. Para gerar o executável do projeto, siga os seguintes passos:
1.1. Abra o CMD;
1.2. Acesse o diretório raíz do projeto;
1.3. Utilize o seguinte comando: 
gcc app.c ^
utils/printColorful/printColorful.c ^
utils/cleanScreen/cleanScreen.c ^
utils/cleanInputBuffer/cleanInputBuffer.c ^
views/startScreen/startScreen.c ^
views/menus/mainMenu/mainMenu.c ^
entities/Tenant/Tenant.h ^
entities/Residence/Residence.h ^
entities/Contract/Contract.h ^
controllers/registerController/registerController.c ^
controllers/signInController/signInController.c ^
-o application

____

2. Para executar o executável do projeto, siga os seguintes passos:
2.1. Abra o CMD;
2.2. Acesse o diretório raíz do projeto;
2.3. Utilize o seguinte comando: start ./application

____

Desenvolvido por:
- Raphael Muniz Varela
- Ygor Marangoni Sgarioni