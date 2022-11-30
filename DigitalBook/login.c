#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct {
	int codusuario, perfil, ativo;
	char usuario[21], senha[16];
}sUsuario;
sUsuario* vUsuarios;
FILE* arquivo;
size_t fSize;
sUsuario user;
int i, nReg;


int verificarUsuario(char usuario[21]) {
    char tabs[]="\t\t\t\t\t";

	//abre o arquivo de login
	arquivo = fopen("login.dat", "rb");
	if (arquivo == NULL) {
		printf("%sFalha ao abrir arquivo de login",tabs);
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
		printf("%sFalha ao alocar memória",tabs);
	}

	//lê o arquivo e armazena na matris vUsuarios
	i = 0;
	while (fread(&user, sizeof(sUsuario), 1, arquivo) > 0) {
		vUsuarios[i] = user;
		i++;
	}
	fclose(arquivo);

    //compara o usuário digitado com a lista de usuários
	for (i = 0; i < nReg; i++) {
		if (!strcmp(vUsuarios[i].usuario, usuario)) {
			user = vUsuarios[i];
			return 1;
		}
	}

	return 0;
}
int compararSenha(char senha[16]) {
    if (!strcmp(user.senha, senha)) {
        return 1;
    }
	return 0;
}
int login(sUsuario *usuarioLogado){
    char tabs[]="\t\t\t\t\t";
    int qtdAsteriscos;
    char campoUsuario[21];
    char campoSenha[16];
    char asteriscos[16];
    char caractere;

    while(1) {
        printf("%sUsuário: ",tabs);
        scanf("%s", campoUsuario);
        if ((verificarUsuario(campoUsuario)) != 0 ) {
            cabecalho();
            printf("\033[0;36m");
            printf("%sDigite sua senha.\n",tabs);
            printf("\033[0m");
            printf("%sUsuário: %s\n",tabs, campoUsuario);
            printf("%sSenha: ",tabs);
            //recebe a senha de forma discreta
            qtdAsteriscos=0;
            while (qtdAsteriscos<16) {
                if (kbhit) {
                    caractere = getch();
                    if ((int)caractere == 8) {
                        qtdAsteriscos--;
                    }else if ((int)caractere == 13) {
                        campoSenha[qtdAsteriscos]=NULL;
                        break; //sai do loop quando o usuário aperta a tecla enter
                    }else{
                        campoSenha[qtdAsteriscos]=caractere;
                        qtdAsteriscos++;
                    }
                    cabecalho();
                    printf("\033[0;36m");
                    printf("%sDigite sua senha.\n",tabs);
                    printf("\033[0m");
                    printf("%sUsuário: %s\n",tabs, campoUsuario);
                    printf("%sSenha: ",tabs);
                    strcpy(asteriscos,"***************");
                    asteriscos[qtdAsteriscos] = '\0';
                    printf("%s%s",tabs,asteriscos);
                }
            }

            if ((compararSenha(campoSenha)) ) {
                    usuarioLogado->codusuario = user.codusuario;
                    usuarioLogado->ativo = user.ativo;
                    usuarioLogado->perfil = user.perfil;
                    strcpy(usuarioLogado->usuario,user.usuario);
                    return 1;
                break;
            }
            else {
                cabecalho();
                printf("\033[0;31m");
                printf("%sSenha incorreta! Tente novamente\n",tabs);
                printf("\033[0m");
            }
        }
        else
        {
            cabecalho();
            printf("\033[0;31m");
            printf("%sUsuário \"%s\" não existe! Entre com um usário válido.\n",tabs, campoUsuario);
            printf("\033[0m");
        }
    }
    return 0;
}
