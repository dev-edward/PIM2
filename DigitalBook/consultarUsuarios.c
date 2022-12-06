#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tabs "\t\t\t\t     "
#define tamCampoUsuario 16
#define tamCampoSenha 13
char perfis[5][20];

typedef struct {
	int codusuario;
	char usuario[tamCampoUsuario], senha[tamCampoSenha];
	int perfil, ativo;
}sUsuario;
sUsuario* vUsuarios;
sUsuario user;
FILE* arquivo;
size_t fSize;
int incremento,nReg;

int listarUsuarios(int _id){
    char intParaString[8]; // comporta até a casa de unidade de milhão

    // Adiciona a lista de perfis
    strcpy(perfis[0],"Administrador");
    strcpy(perfis[1],"Gerente");
    strcpy(perfis[2],"Recursos Humanos");
    strcpy(perfis[3],"Financeiro");
    strcpy(perfis[4],"Recepção");

	//abre o arquivo de login
	arquivo = fopen("usuarios.dat", "rb");
	if (arquivo == NULL) {
		avisoVermelho("%Falha ao abrir arquivo de usuários");
		Sleep(2000);
		return 0;
	};

	//calcula o tamanho do arquivo e a quantidade de registros
	{
		fseek(arquivo, 0L, SEEK_END);
		fSize = ftell(arquivo);
		nReg = fSize / sizeof(sUsuario);
		fseek(arquivo, 0L, SEEK_SET);
	}

    //Aloca na memória o mesmo tamanho do arquivo
	vUsuarios = (sUsuario*)malloc(fSize);
	if (vUsuarios == NULL) {
		printf("%sFalha ao alocar memória",tabs);
	}

	//lê o arquivo e armazena na matris vUsuarios
	incremento = 0;
	while (fread(&user, sizeof(sUsuario), 1, arquivo) > 0) {
		vUsuarios[incremento] = user;
		incremento++;
	}
	fclose(arquivo);

	titulo("Listar Usuários");
	limparAbaixo();
	mensagemAzul(" ");
    // Lista todos os usuários em uma tabela ASCII
    printf("%s  +--------+------------------+------------------+--------+\n",tabs);
    printf("%s  | Codigo |     Usuário      |      Perfil      | Ativo? |\n",tabs);
    printf("%s  +========+==================+==================+========+\n",tabs);
	for (int i = 0; i < nReg; i++) {
        int tamCodigo=8;
        int tamUsuario=18;
        int tamPerfil=18;
        int tamAtivo=8;


        printf("%s  |",tabs);
        sprintf(intParaString, "%d", vUsuarios[i].codusuario);// Converte o codigo em string
        centralizar(intParaString,tamCodigo);
        printf("|");
        centralizar(vUsuarios[i].usuario,tamUsuario);
        printf("|");
        centralizar(perfis[vUsuarios[i].perfil-1],tamPerfil);
        printf("|");
        centralizar(vUsuarios[i].ativo?"Sim":"Não",tamAtivo);
        printf("|\n");
	}
	printf("%s  |........|..................|..................|........|\n",tabs);
    voltar();
	return 0;
}

