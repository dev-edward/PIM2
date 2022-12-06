#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "logo.h"

#define tabs "\t\t\t\t     "
#define tamanhoUsuario 16
#define tamanhoSenha 13

char _usuario[tamanhoUsuario];
char _senha[tamanhoSenha],_senhaConfimacao[tamanhoSenha];
int _perfil,_ativo,caracteresNoCampo;
char caractere;
char contatenacao[60];
char perfis[5][20];


typedef struct {
	int codusuario;
	char codinome[tamanhoUsuario], senha[tamanhoSenha];
	int perfil, ativo;
}cadastroUsuario;

FILE* arquivoUsuarios;

int solicitarUsuario(){
    mensagemAzul("Defina um codinome(máx. 15 caracteres)");
    limparAbaixo();
    printf("%sNovo usuário: ",tabs);
    //Recebe o codinome
    caracteresNoCampo=0;
    caractere==NULL;
    while (1) {
        if (kbhit) {
            caractere = getch();
            if ((int)caractere == 8) {// Quando pressionado a tecla backspace apaga o ultimo caractere
                if(caracteresNoCampo>0){
                    printf("\b");
                    printf("\033[K");
                    caracteresNoCampo--;
                }
            }else if ((int)caractere == 13) {// Sai do loop quando o usuário aperta a tecla enter
                _usuario[caracteresNoCampo]=NULL;
                break;
            }else if ((int)caractere == 27) {// Quando apertado a tecla ESC

                return -1;
                break;
            }else if(caracteresNoCampo<tamanhoUsuario-1){
                printf("%c",caractere);
                _usuario[caracteresNoCampo]=caractere;
                caracteresNoCampo++;
            }
        }
    }
    if((verificarUsuario(_usuario)) != 0) return 1;
    return 0;
}
int solicitarSenha(){
    mensagemAzul("Digite uma senha(máx. 12 caracteres)");
    limparAbaixo();
    printf("%sNovo usuário: ",tabs);
    printf("%s\n",_usuario);
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
            }else if(caracteresNoCampo<tamanhoSenha-1){
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
            }else if(caracteresNoCampo<tamanhoSenha-1){
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
int escolherPerfil(){
    int qtdSenha;
    int indicePerfil;
    char tecla;
    // Adiciona a lista de perfis
    strcpy(perfis[0],"Administrador");
    strcpy(perfis[1],"Gerente");
    strcpy(perfis[2],"Recursos Humanos");
    strcpy(perfis[3],"Financeiro");
    strcpy(perfis[4],"Recepção");
    mensagemAzul("Escolha um perfil para o usuário com as setas");
    limparAbaixo();
    printf("%sNovo usuário: ",tabs);
    printf("%s\n",_usuario);
    printf("%sSenha: ", tabs);
    qtdSenha=strlen(_senha);
    for(int i=0;i<qtdSenha;i++){
        printf("*");
    }
    printf("\n%sConfirme a senha: ", tabs);
    for(int i=0;i<qtdSenha;i++){
        printf("*");
    }
    printf("\n%sPerfil: ",tabs);
    indicePerfil = 0;
    printf("%s",perfis[indicePerfil]);
    tecla=NULL;
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if(((int)tecla==80) || ((int)tecla==72)){
                for(int i=0;i<strlen(perfis[indicePerfil]);i++){
                    printf("\b");
                }
                printf("\033[K");

                if((int)tecla==80)indicePerfil++;
                if((int)tecla==72)indicePerfil--;

                if(indicePerfil>4)indicePerfil=0; // Quando o índice do perfil ultrapassa o total volta para a posição inicial
                if(indicePerfil<0)indicePerfil=4; // Quando o índice do perfil é menor, passa a ser o último

                printf("%s",perfis[indicePerfil]);
            }else if((int)tecla==27)return -1;
        }
    }

    return indicePerfil+1; // Adiciona 1 ao indice pois nos arquivos o indice começa com 1
}
int estaAtivo(){
    int qtdSenha;
    char tecla;
    int ativo;
    mensagemAzul("Defina se o usuário está ativo com as setas");
    limparAbaixo();
    printf("%sNovo usuário: ",tabs);
    printf("%s\n",_usuario);
    printf("%sSenha: ", tabs);
    qtdSenha=strlen(_senha);
    for(int i=0;i<qtdSenha;i++){
        printf("*");
    }
    printf("\n%sConfirme a senha: ", tabs);
    for(int i=0;i<qtdSenha;i++){
        printf("*");
    }
    printf("\n%sPerfil: ",tabs);
    printf("%s\n",perfis[_perfil-1]);
    printf("%sAtivo? ",tabs);
    ativo=1;
    printf("Sim");
    tecla=NULL;
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if(((int)tecla==80) || ((int)tecla==72)){
                printf("\b\b\b\033[K");
                ativo==1?ativo--:ativo++;
                ativo?printf("Sim"):printf("Não");
            }else if((int)tecla==27)return -1;
        }
    }
    return ativo;
}
void cadastroCancelado(){
    avisoVermelho("Cadastro cancelado, voltando para o menu");
    Sleep(1600);
    avisoVermelho(" ");
    limparAbaixo();
}


/*  Criaçao de usuário de teste
    salvarUsuario("edward", "senha1", 1, 1);
    salvarUsuario("debora", "senha2", 2, 1);
    salvarUsuario("carol", "senha3", 3, 1);
    salvarUsuario("caio", "senha4", 4, 1);
    salvarUsuario("washington", "senha5", 5, 1);
    salvarUsuario("sara", "senha6", 6, 1);
*/
int criarUsuario(){

    titulo("Cadastro de usuário.");
    avisoVermelho(" ");

    // Validando usuário;
    while(1){
        int usuarioInvalido = solicitarUsuario();
        if(usuarioInvalido==1){
            strcat(strcat(strcpy(contatenacao, "\""),_usuario),"\" já está em uso, escolha outro nome de usuário");
            avisoVermelho(contatenacao);
        }else if(usuarioInvalido==0){
            avisoVermelho(" ");
            break;
        }else if(usuarioInvalido==-1){
            cadastroCancelado();
            return -1;
        }
    }
    while(1){
        int senhaInvalida = solicitarSenha();
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

    _perfil = escolherPerfil();
    if(_perfil==-1){
        cadastroCancelado();
        return -1;
    }
    _ativo = estaAtivo();
    if(_ativo==-1){
        cadastroCancelado();
        return -1;
    }


    mensagemAzul("Confirme os dados do cadastro");
    printf("\033[15;0H%s",tabs);// Reposiciona o cursor
    if(confirmacao()){
        if(salvarUsuario(_usuario, _senha, _perfil, _ativo)==0){
            avisoVerde("Cadastrado com sucesso! Voltando ao menu");
            Sleep(1600);
            avisoVerde(" ");
            limparAbaixo();
        }else{
            avisoVermelho("Ops algo deu errado, voltando ao menu");
            Sleep(1600);
            avisoVermelho(" ");
            limparAbaixo();
        }
    }else{
        cadastroCancelado();
    }


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
    //salvarUsuario(_usuario, _senha, _perfil, _ativo);


}
int ultimoCodUsuario(){//retorna a quantidade de usuários cadastrados, que seria o ultimo código de usuário atribuído

    size_t tamanhoArquivo;
    int numeroRegistros;

    arquivoUsuarios = fopen("usuarios.dat", "ab+"); // Abre o arquivo para leitura
	if (arquivoUsuarios == NULL) {
		 printf("Falha ao abrir arquivo de usuários");
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
int salvarUsuario(char _usuario[tamanhoUsuario], char _senha[tamanhoSenha], int _perfil, int _ativo) { // Salva o usuário no arquivo usuarios.dat
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
        elementosGravados = fwrite(&usuario, sizeof(cadastroUsuario), 1, arquivoUsuarios); // Grava arquivo em binario.
        fclose(arquivoUsuarios); // Fecha o arquivo aberto
        if (elementosGravados==1){ // Se a quantidade de elementos gravados for 1 significa que conseguiu armazenar o usuário no arquivo
            return 0; // Retorna 0 pois o usuário foi cadastrado
        }else{
            return -2; // Se a variável elementosGravados for diferente de 1 algo deu errado
        }

	}
}
