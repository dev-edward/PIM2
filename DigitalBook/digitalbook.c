#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "login.h"
#include "criarUsuario.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); //Permite acentua��o em portugu�s
	char usuario[21];
	char senha[16];
	int codusuario;
	int codperfil;

	printf("Usu�rio: ");

	scanf_s("%20s", usuario, (unsigned)_countof(usuario)); //Alternativa com sizeof(array1)

	if (codusuario = l_usuario(&usuario)) {
		printf("Senha: ");

		scanf_s("%15s", senha, (unsigned)_countof(senha));
		if (codperfil = login(senha)) {
			printf("\nBem-vindo(a) %s\n", usuario);
		}
		else {
			printf("\nSenha incorreta");
		}
	}
	else
	{
		printf("Usu�rio \"%s\" n�o existe!", usuario);
	}

	//system("pause");

	//criarUsuario("edward","senha1",1);

	return 0;
}