#include <stdio.h>
#include <string.h>

typedef struct {
	int codusuario, perfil, ativo;
	char usuario[21], senha[16];
}cadusuario;

int n=0; //variável temporária para o código de usuário
int result;
FILE* arquivo;

int criarUsuario(char usuario[21], char senha[16], int perfil) {
    n++;
	cadusuario user;
	user.codusuario = n;
	user.perfil = perfil;
	user.ativo = 1;
	strcpy(user.usuario, usuario);
	strcpy(user.senha, senha);

	arquivo = fopen("login.dat", "ab");

	if (arquivo==NULL) {
		printf("Falha ao criar arquivo de login");
		return 0;
	};

	fflush(stdin); //limpa o buffer do teclado
	result = fwrite(&user, sizeof(cadusuario), 1, arquivo);//grava arquivo em binario
	fclose(arquivo);

	return 1;
}
