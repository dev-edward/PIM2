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
    char intParaString[8]; // comporta at� a casa de unidade de milh�o

    // Adiciona a lista de perfis
    strcpy(perfis[0],"Administrador");
    strcpy(perfis[1],"Gerente");
    strcpy(perfis[2],"Recursos Humanos");
    strcpy(perfis[3],"Financeiro");
    strcpy(perfis[4],"Recep��o");

	//abre o arquivo de login
	arquivo = fopen("usuarios.dat", "rb");
	if (arquivo == NULL) {
		avisoVermelho("%Falha ao abrir arquivo de usu�rios");
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

    //Aloca na mem�ria o mesmo tamanho do arquivo
	vUsuarios = (sUsuario*)malloc(fSize);
	if (vUsuarios == NULL) {
		printf("%sFalha ao alocar mem�ria",tabs);
	}

	//l� o arquivo e armazena na matris vUsuarios
	incremento = 0;
	while (fread(&user, sizeof(sUsuario), 1, arquivo) > 0) {
		vUsuarios[incremento] = user;
		incremento++;
	}
	fclose(arquivo);

	titulo("Listar Usu�rios");
	limparAbaixo();
	mensagemAzul(" ");
    // Lista todos os usu�rios em uma tabela ASCII
    printf("%s  +--------+------------------+------------------+--------+\n",tabs);
    printf("%s  | Codigo |     Usu�rio      |      Perfil      | Ativo? |\n",tabs);
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
        centralizar(vUsuarios[i].ativo?"Sim":"N�o",tamAtivo);
        printf("|\n");
	}
	printf("%s  |........|..................|..................|........|\n",tabs);
    voltar();
	return 0;
}

