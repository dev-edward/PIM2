#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int codusuario, perfil, ativo;
	char usuario[21], senha[16];
}sUsuario;
sUsuario* vUsuarios;
FILE* arquivo;
size_t fSize;
sUsuario user;
int i, nReg;

int l_usuario(char usuario[21]) {

	//abre o arquivo de login
	arquivo = fopen("login.dat", "rb");
	if (arquivo == NULL) {
		printf("Falha ao abrir arquivo de login");
		return 0;
	};

	//calcula o tamanho do arquivo e a quantidade de registros
	{
		fseek(arquivo, 0L, SEEK_END);
		fSize = ftell(arquivo);
		nReg = fSize / sizeof(sUsuario);
		fseek(arquivo, 0L, SEEK_SET);
	}

	vUsuarios = (sUsuario*)malloc(fSize); //Aloca na memória o mesmo tamanho do arquivo
	if (vUsuarios == NULL) {
		printf("Falha ao alocar memória");
	}

	//lê o arquivo e armazena na matris vUsuarios
	i = 0;
	while (fread(&user, sizeof(sUsuario), 1, arquivo) > 0) {
		vUsuarios[i] = user;
		i++;
	}
	fclose(arquivo);

	for (i = 0; i < nReg; i++) {
		if (!strcmp(vUsuarios[i].usuario, usuario)) {
			user = vUsuarios[i];
			return vUsuarios[i].codusuario;
		}
	}

	return 0;
};
int login(char senha[16]) {

	for (i = 0; i < nReg; i++) {
		if (!strcmp(user.senha, senha)) {
			return user.perfil;
		}
	}
	return 0;
};
