#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define tabs "\t\t\t\t     "
#define tamCampoUsuario 16
#define tamCampoSenha 13

typedef struct {
	int codusuario;
	char usuario[tamCampoUsuario], senha[tamCampoSenha];
	int perfil, ativo;
}structUsuario;

structUsuario usuarioEscolhido;
char _senha[tamCampoSenha],_senhaConfimacao[tamCampoSenha];

FILE* arquivo;
size_t fSize;
int incremento,nReg,caracteresNoCampo;

char concatenacao[60];
char codigoString[8];
int tempoMsg2=1600;

int receberCodigoAlterarSenha(){

    char *tempChar;
    int codigoInteiro=0;
    char tecla;

    mensagemAzul("Digite o código do usuário");
    printf("\033[J");
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

int solicitarNovaSenha(){
    char caractere;
    strcat(strcpy(concatenacao, "Digite uma nova senha para "),usuarioEscolhido.usuario);
    mensagemAzul(concatenacao);
    limparAbaixo();
    printf("%sSenha: ", tabs);
    // Recebe a senha
    caracteresNoCampo=0;
    caractere==NULL;
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
                _senha[caracteresNoCampo]=NULL;
                break;
            }else if ((int)caractere == 27) {// Quando apertado a tecla ESC
                return -1;
                break;
            }else if(caracteresNoCampo<tamCampoSenha-1){
                printf("*");
                _senha[caracteresNoCampo]=caractere;
                caracteresNoCampo++;
            }
        }
    }
    printf("\n%sConfirme a senha: ", tabs);
    // Recebe a confirmação da senha
    caracteresNoCampo=0;
    caractere==NULL;
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
                _senhaConfimacao[caracteresNoCampo]=NULL;
                break;
            }else if ((int)caractere == 27) {// Quando apertado a tecla ESC
                return -1;
                break;
            }else if(caracteresNoCampo<tamCampoSenha-1){
                printf("*");
                _senhaConfimacao[caracteresNoCampo]=caractere;
                caracteresNoCampo++;
            }
        }
    }
    if (strcmp(_senha,_senhaConfimacao)!=0) {
        return 1; // Senha não coincidem
    }
    return 0;
}

int alterarSenha(int _codigo){
    int codigoAlterar;
    int resultadoSalvar;
    int usuarioEncontrado;

    structUsuario* matrizUsuarios;

    structUsuario umUsuario;

    codigoAlterar = _codigo;

    usuarioEncontrado = 0;
    if(_codigo==0){

        while(1){
        codigoAlterar = receberCodigoAlterarSenha();

        if(codigoAlterar==-1){
            cancelarAlteracao();
            return -1;
        }else if(!usuarioEncontrado){
            avisoVermelho(" ");
            for (int i = 0; i < nReg; i++) {
                if (matrizUsuarios[i].codusuario == codigoAlterar) {
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
    }

    //abre o arquivo de login
	arquivo = fopen("usuarios.dat", "rb");
	if (arquivo == NULL) {
		avisoVermelho("Falha ao abrir arquivo de usuários");
		Sleep(tempoMsg2);
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
		Sleep(tempoMsg2);
		return -2;
	}

	//lê o arquivo e armazena na matrizUsuarios
	incremento = 0;
	while (fread(&umUsuario, sizeof(structUsuario), 1, arquivo) > 0) {
		matrizUsuarios[incremento] = umUsuario;
		incremento++;
	}
	fclose(arquivo);

	titulo("Alterar Senha");
	limparAbaixo();



	while(1){
        int senhaInvalida = solicitarNovaSenha();
        if(senhaInvalida==1){
            avisoVermelho("As senhas não coincidem, tente novamente");
        }else if(senhaInvalida==0){
            avisoVermelho(" ");
            break;
        }else if(senhaInvalida==-1){
            cadastroCancelado();
            return -1;
        }
    }

    resultadoSalvar =  salvarSenha();

}
int salvarSenha(int _codigo){
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

