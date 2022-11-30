#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "logo.h"

typedef struct {
	int codusuario, perfil, ativo;
	char codinome[21], senha[16];
}cadastroUsuario;

FILE* arquivoUsuarios;

/*  Criaçao de usuário de teste
    criarUsuario("edward","senha1",1);
    criarUsuario("debora","senha2",2);
    criarUsuario("carol","senha3",3);
    criarUsuario("caio","senha4",4);
    criarUsuario("washington","senha5",5);
    criarUsuario("sara","senha6",6);
*/


void criarUsuario(){
    int tamanhoUsuario = 8,tamanhoSenha=16;
    char _usuario[tamanhoUsuario];
    char _senha[16];
    int _perfil,_ativo,incremento,cancelarCadastro=0;
    char caracterePressionado;
    char espacos[]="                 ";

    cabecalho();
    titulo("Cadastro de usuário.");
    titulo("teste titulo.");
     titulo("Cadastro de usuário12.");
    titulo("titulo.");
    titulo("teste titulo de usuário102.");
    getch();
    printf("Novo usuário: ");
    fflush(stdin);
    fgets(_usuario,tamanhoUsuario,stdin);
/*
    // Receber usuario sem ultrapassar o limite de caracteres
    incremento=0;
    while (incremento<tamanhoUsuario) {
        if (kbhit) {
            caracterePressionado = getche();
            if ((int)caracterePressionado==13) { // Terminou de escrever o campo
                _usuario[incremento]=NULL;
                printf("\nPressionou Enter\n");
                break;
            }else if ((int)caracterePressionado==27) { // Cancela o cadastro
                cancelarCadastro=1;
                printf("\nPressionou Esc.\n");
                break;
            }else{
                _usuario[incremento] = caracterePressionado;
                incremento++;
            }
        }
    }
*/

/* Criptografando strings
    for(int i=0; mensagem[i] != '\0'; i++){
        x = mensagem[i];
        if((x >= 'a' && x <= 'z')&&(x >= 'A' && x <= 'Z')){
            x = x + rot;
            if(x>'z'){
                x = x - 'z' + 'a' -1;
            }
            mensagem[i] = x;
        }
    }
*/
/* Descriptografando strings
    for(int i=0; mensagem[i] != '\0'; i++){
        x = mensagem[i];
        if((x >= 'a' && x <= 'z')&&(x >= 'A' && x <= 'Z')){
            x = x + rot;
            if(x<'a'){
                x = x + 'z' - 'a' +1;
            }
            mensagem[i] = x;
        }
        mensagem[i] = x;
    }
*/



    printf("%s\n%c\n%c\n%c\n%c\n%c\n%c\n",_usuario,_usuario[0]+3,_usuario[1]+3,_usuario[2]+3,_usuario[3]+3,_usuario[4]+3,_usuario[5]+3);
    system("pause");


    if(cancelarCadastro){
        printf("Cadastro cancelado");
    }else{
        printf("Cadastrado");
        //salvarUsuario(_usuario, _senha, _perfil, _ativo);
    }
}
int ultimoCodUsuario(){//retorna a quantidade de usuários cadastrados, que seria o ultimo código de usuário atribuído

    size_t tamanhoArquivo;
    int numeroRegistros;

    arquivoUsuarios = fopen("usuarios.dat", "ab+"); // Abre o arquivo para leitura
	if (arquivoUsuarios == NULL) {
		// printf("Falha ao abrir arquivo de usuários");
		return -1; // Retorna -1 se não conseguir abrir o arquivo e então aborta a função
	};
	//calcula o tamanho do arquivo e a quantidade de registros
	{
		fseek(arquivoUsuarios, 0L, SEEK_END); // Desloca o ponteiro do arquivo no final dele
		tamanhoArquivo = ftell(arquivoUsuarios); // Retorna o tamanho do arquivo atravéz do ponteiro do arquivo
		numeroRegistros = tamanhoArquivo / sizeof(cadastroUsuario); // calcula o número de registros
		fseek(arquivoUsuarios, 0L, SEEK_SET); // Volta o ponteiro do arquivo para a posição inicial
	}

	return numeroRegistros;
}
int salvarUsuario(char _usuario[21], char _senha[16], int _perfil, int _ativo) { // Salva o usuário no arquivo usuarios.dat
    int elementosGravados,codusuario;
    //FILE* gravarArquivo;
	cadastroUsuario usuario;

	if((codusuario=ultimoCodUsuario())==-1){
        fclose(arquivoUsuarios);
        return -1; // Retorna -1 pois não conseguiu obter o ultimo codusuário
	}else{
        codusuario++;
        usuario.codusuario = codusuario;
        usuario.perfil = _perfil;
        usuario.ativo = _ativo;
        strcpy(usuario.codinome, _usuario);
        strcpy(usuario.senha, _senha);

        //gravarArquivo = fopen("usuarios.dat", "ab");
        /*
        if (gravarArquivo==NULL) {
            printf("Falha ao criar arquivo de usuarios\n");
            return 0;
        };
        */

        fflush(stdin); // Limpa o buffer do teclado
        elementosGravados = fwrite(&usuario, sizeof(cadastroUsuario), 1, arquivoUsuarios); // Grava arquivo em binario
        if (elementosGravados==1){ // Se a quantidade de elementos gravados for 1 significa que conseguiu armazenar o usuário no arquivo
            fclose(arquivoUsuarios); // Fecha o arquivo aberto
            return 0; // Retorna 0 pois o usuário foi cadastrado
        }else{
            fclose(arquivoUsuarios); // Fecha o arquivo aberto
            return -2; // Se a variável elementosGravados for diferente de 1 algo deu errado
        }

	}
}
