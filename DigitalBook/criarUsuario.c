#include <stdio.h>
#include <string.h>

typedef struct {
	int codusuario, perfil, ativo;
	char usuario[21], senha[16];
}cadusuario;

int result;
FILE* arquivo;

int criarUsuario(char usuario[21], char senha[16], int perfil) {
	cadusuario user;

	user.codusuario = 1;
	user.perfil = 1;
	user.ativo = 1;
	strcpy_s(user.usuario, sizeof(user.usuario), usuario);
	strcpy_s(user.senha, sizeof(user.senha), senha);

	errno_t erro_arquivo = fopen_s(&arquivo, "login.dat", "ab");

	if (erro_arquivo) {
		printf("Falha ao criar arquivo de login");
		return 0;
	};

	fflush(stdin); //limpa o buffer do teclado
	result = fwrite(&user, sizeof(cadusuario), 1, arquivo);//grava arquivo em binario

	fclose(arquivo);
	return 1;
}