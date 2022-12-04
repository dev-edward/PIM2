#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "logo.h"
#define tabs "\t\t\t\t     "
#define tamCampoUsuario 16
#define tamCampoSenha 13

//int tamCampoUsuario = 16, tamCampoSenha = 13;
typedef struct {
	int codusuario;
	char usuario[tamCampoUsuario], senha[tamCampoSenha];
	int perfil, ativo;
}sUsuario;
sUsuario* vUsuarios;
FILE* arquivo;
size_t fSize;
sUsuario user;
int i, nReg;

char contatenacao[60];

int verificarUsuario(char usuario[tamCampoUsuario]) {
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
int compararSenha(char senha[tamCampoSenha]) {
    if (strcmp(user.senha, senha)==0) {
        return 1; // Senha verdadeira
    }
	return 0;
}
int login(sUsuario *usuarioLogado){

    int caracteresNoCampo;
    char campoUsuario[tamCampoUsuario];
    char campoSenha[tamCampoSenha];
    char caractere;

    titulo("Tela de login");
    while(1) {
        mensagemAzul("Insira seu usuário");
        printf("%sUsuário: ",tabs);

        // Recebe o usuário sem deixar passar a quantidade de caracteres
        caracteresNoCampo=0;
        while (1) {
            if (kbhit) {
                caractere = getch();
                if ((int)caractere == 8) {//quando apertado backspace apaga o ultimo asterisco
                    if(caracteresNoCampo>0){
                        printf("\b");
                        printf("\033[K");
                        caracteresNoCampo--;
                    }
                }else if ((int)caractere == 13) {//sai do loop quando o usuário aperta a tecla enter
                    campoUsuario[caracteresNoCampo]=NULL;
                    break;
                }else if ((int)caractere == 27) {// Quando apertado a tecla ESC
                    return 0;
                    break;
                }else if(caracteresNoCampo<tamCampoUsuario-1){
                    printf("%c",caractere);
                    campoUsuario[caracteresNoCampo]=caractere;
                    caracteresNoCampo++;
                }
            }
        }


        if ((verificarUsuario(campoUsuario)) != 0 ) {
            avisoVermelho(" ");
            //printf("\033[7"); // Salva posição do cursor
            mensagemAzul("Digite sua senha");
            //printf("\033[8"); // Restaura posição do cursor
            limparAbaixo();
            printf("%sUsuário: %s\n",tabs, campoUsuario);
            printf("%sSenha: ",tabs);

            //recebe a senha de forma discreta
            caracteresNoCampo=0;
            while (1) {
                if (kbhit) {
                    caractere = getch();
                    if ((int)caractere == 8) {//quando apertado backspace apaga o ultimo asterisco
                        if(caracteresNoCampo>0){
                            printf("\b");
                            printf("\033[K");
                            caracteresNoCampo--;
                        }
                    }else if ((int)caractere == 13) {//sai do loop quando o usuário aperta a tecla enter
                        campoSenha[caracteresNoCampo]=NULL;
                        break;
                    }else if ((int)caractere == 27) {// Quando apertado a tecla ESC
                        return 0;
                        break;
                    }else if(caracteresNoCampo<tamCampoSenha-1){
                        printf("*");
                        campoSenha[caracteresNoCampo]=caractere;
                        caracteresNoCampo++;
                    }
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
                avisoVermelho("Senha incorreta! Tente novamente");
                limparAbaixo();
            }
        }
        else
        {
            strcat(strcat(strcpy(contatenacao, "Usuário \""),campoUsuario),"\" não existe! Entre com um usuário válido");
            avisoVermelho(contatenacao);
            limparAbaixo();
        }
    }
    return 0;
}
