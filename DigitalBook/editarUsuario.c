#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "mensagens.h"
#define tabs "\t\t\t\t     "
#define tamCampoUsuario 16
#define tamCampoSenha 13


typedef struct {
	int codusuario;
	char usuario[tamCampoUsuario], senha[tamCampoSenha];
	int perfil, ativo;
}structUsuario;

structUsuario usuarioEscolhido;

FILE* arquivo;
size_t fSize;
int incremento,nReg,caracteresNoCampo;

char concatenacao[60];
char codigoString[8];
int tempoMsg=1600;

int receberCodigo(){

    char *tempChar;
    int codigoInteiro=0;
    char tecla;

    mensagemAzul("Digite o código do usuário");
	printf("%sCódigo: ",tabs);
	printf("\033[K");
    //Recebe o codigo
    caracteresNoCampo=0;
    tecla=NULL;
    while (1) {
        if (kbhit) {
            tecla = getch();
            if ((int)tecla == 8) {// Quando pressionado a tecla backspace apaga o ultimo caractere
                if(caracteresNoCampo>0){
                    printf("\b");
                    printf("\033[K");
                    caracteresNoCampo--;
                }
            }else if ((int)tecla == 13) {// Sai do loop quando o usuário aperta a tecla enter
                codigoString[caracteresNoCampo]=NULL;
                break;
            }else if ((int)tecla == 27) {// Quando apertado a tecla ESC
                return -1;
                break;
            }else if((caracteresNoCampo<7) && (tecla>='0' && tecla<='9')){
                printf("%c",tecla);
                codigoString[caracteresNoCampo]=tecla;
                caracteresNoCampo++;
            }
        }
    }
    codigoInteiro = strtol(codigoString, &tempChar, 10);
    return codigoInteiro;
}

void cancelarAlteracao(){
    avisoVermelho("Alteração cancelada, voltando para o menu");
    Sleep(tempoMsg);
    avisoVermelho(" ");
    limparAbaixo();
}
int editarUsuario(){
    char perfis[5][20];
    char intParaString[8];
    int tamCodigo=8;
    int tamUsuario=18;
    int tamPerfil=18;
    int tamAtivo=8;
    char tecla;
    int indicePerfil;
    int _ativo;
    int resultadoSalvar;

    structUsuario umUsuario;
    structUsuario* matrizUsuarios;

    int codigo;
    int usuarioEncontrado;

    // Adiciona a lista de perfis
    strcpy(perfis[0],"Administrador");
    strcpy(perfis[1],"Gerente");
    strcpy(perfis[2],"Recursos Humanos");
    strcpy(perfis[3],"Financeiro");
    strcpy(perfis[4],"Recepção");

    //abre o arquivo de login
	arquivo = fopen("usuarios.dat", "rb");
	if (arquivo == NULL) {
		avisoVermelho("Falha ao abrir arquivo de usuários");
		Sleep(tempoMsg);
		return -1;
	};

	//calcula o tamanho do arquivo e a quantidade de registros
	{
		fseek(arquivo, 0L, SEEK_END);
		fSize = ftell(arquivo);
		nReg = fSize / sizeof(structUsuario);
		fseek(arquivo, 0L, SEEK_SET);
	}

	 //Aloca na memória o mesmo tamanho do arquivo
	matrizUsuarios = (structUsuario*)malloc(fSize);
	if (matrizUsuarios == NULL) {
		avisoVermelho("Falha ao alocar memória");
		Sleep(tempoMsg);
		return -2;
	}

	//lê o arquivo e armazena na matrizUsuarios
	incremento = 0;
	while (fread(&umUsuario, sizeof(structUsuario), 1, arquivo) > 0) {
		matrizUsuarios[incremento] = umUsuario;
		incremento++;
	}
	fclose(arquivo);

	titulo("Alterar Perfil de Usuário");
	limparAbaixo();

    usuarioEncontrado = 0;
	// Validando usuário;
    while(1){
        codigo = receberCodigo();

        if(codigo==-1){
            cancelarAlteracao();
            return -1;
        }else if(!usuarioEncontrado){
            avisoVermelho(" ");
            for (int i = 0; i < nReg; i++) {
                if (matrizUsuarios[i].codusuario == codigo) {
                    usuarioEscolhido = matrizUsuarios[i];
                    usuarioEncontrado = 1;
                    break;
                }
            }
            if(usuarioEncontrado)break;

            strcat(strcat(strcpy(concatenacao, "Nenhum usuário com código "),codigoString)," encontrado");
            avisoVermelho(concatenacao);
        }
    }

    mensagemAzul("Escolha outro perfil com as setas | ESC para cancelar");
    printf("\033[12;0H"); // Reposiciona o cursor

    // Lista todos o usuário escolhido em uma tabela ASCII
    printf("\n%s  +--------+------------------+------------------+--------+\n",tabs);
    printf("%s  | Codigo |     Usuário      |      Perfil      | Ativo? |\n",tabs);
    printf("%s  +========+==================+==================+========+\n",tabs);
    printf("%s  |",tabs);
    sprintf(intParaString, "%d", usuarioEscolhido.codusuario);// Converte o codigo em string
    centralizar(intParaString,tamCodigo);
    printf("|");
    centralizar(usuarioEscolhido.usuario,tamUsuario);
    printf("|");
    printf("\033[5;93m");
    centralizar(perfis[usuarioEscolhido.perfil-1],tamPerfil);
    printf("\033[m");
    printf("|");
    centralizar(usuarioEscolhido.ativo?"Sim":"Não",tamAtivo);
    printf("|\n");
	printf("%s  |........|..................|..................|........|\n",tabs);

	indicePerfil=usuarioEscolhido.perfil-1;
	tecla=NULL;
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if(((int)tecla==80) || ((int)tecla==72)){
                printf("\033[16;69H"); // Move o cursor ate o campo perfil
                printf("\033[K");

                if((int)tecla==80)indicePerfil++;
                if((int)tecla==72)indicePerfil--;
                if(indicePerfil>4)indicePerfil=0; // Quando o índice do perfil ultrapassa o total volta para a posição inicial
                if(indicePerfil<0)indicePerfil=4; // Quando o índice do perfil é menor, passa a ser o último

                printf("\033[5;93m");
                centralizar(perfis[indicePerfil],tamPerfil);
                printf("\033[m");
                printf("|");
                centralizar(usuarioEscolhido.ativo?"Sim":"Não",tamAtivo);
                printf("|");
            }else if((int)tecla==27){
                cancelarAlteracao();
                return -1;
            }
        }
    }
    usuarioEscolhido.perfil = indicePerfil+1;

    mensagemAzul("Defina se esta ativo com as setas | ESC para cancelar");

    printf("\033[16;69H"); // Move o cursor ate o campo perfil
    printf("\033[K");
    centralizar(perfis[usuarioEscolhido.perfil-1],tamPerfil);
    printf("|");

    printf("\033[16;88H"); // Move o cursor ate o campo ativo
    printf("\033[5;93m");
    centralizar(usuarioEscolhido.ativo?"Sim":"Não",tamAtivo);
    printf("\033[m");
    printf("|");
    _ativo=usuarioEscolhido.ativo;
    tecla=NULL;
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if(((int)tecla==80) || ((int)tecla==72)){
                printf("\033[16;88H"); // Move o cursor ate o campo ativo
                printf("\033[K");

                _ativo==1?_ativo--:_ativo++;

                printf("\033[5;93m");
                centralizar(_ativo?"Sim":"Não",tamAtivo);
                printf("\033[m");
                printf("|");
            }else if((int)tecla==27)return -1;
        }
    }
    usuarioEscolhido.ativo = _ativo;
    printf("\033[16;88H"); // Move o cursor ate o campo ativo
    printf("\033[K");
    centralizar(usuarioEscolhido.ativo?"Sim":"Não",tamAtivo);
    printf("|\n");

    if(confirmacao()){
        resultadoSalvar = salvarAlteracoes(codigo);
        if(resultadoSalvar == 1){
            avisoVerde("Alterações salvas! Voltando ao menu");
            Sleep(tempoMsg);
            avisoVerde(" ");
            limparAbaixo();
        }else if(resultadoSalvar == -1){
            avisoVermelho("Ops algo deu errado, voltando ao menu");
            Sleep(tempoMsg);
            avisoVermelho(" ");
            limparAbaixo();
        }else if(resultadoSalvar == -2){
            avisoVermelho("Não foi possivel alterar esse usuário");
            Sleep(tempoMsg);
            avisoVermelho(" ");
            limparAbaixo();
        }
    }else{
        cancelarAlteracao();
    }
}
int salvarAlteracoes(int _codigo){
    int elementosGravados;
    structUsuario umUsuario;

    FILE* arquivoEditar;

    arquivoEditar = fopen("usuarios.dat", "rb+");
    //fseek(arquivoEditar, (_codigo-1)*(sizeof(structUsuario),SEEK_SET);

	while (1) {
        fread(&umUsuario, sizeof(structUsuario), 1, arquivoEditar);

		if(umUsuario.codusuario == _codigo){
            fflush(stdin); // Limpa o buffer do teclado

            fseek(arquivoEditar, -1*sizeof(structUsuario),SEEK_CUR);

            elementosGravados = fwrite(&usuarioEscolhido,sizeof(structUsuario),1,arquivoEditar); // Grava um usuário no arquivo na sua respectiva posição
            fclose(arquivoEditar); // Fecha o arquivo aberto
            if (elementosGravados==1){ // Conseguiu alterar o usuário
                return 1; // Retorna 0 pois o usuário foi alterado
            }else{
                return -1; // Algo deu errado na hora de alterar
            }
            break;
		}
	}
    fclose(arquivoEditar);
    return -2; // Não encontrou um usuário com o código indicado
}
