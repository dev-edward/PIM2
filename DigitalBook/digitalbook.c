#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "testes.h"
#include "logo.h"
#include "login.h"
#include "menus.h"
#include "mensagens.h"
#include "criarUsuario.h"
#include "consultarUsuarios.h"
#include "editarUsuario.h"

#define tabs "\t\t\t\t     "
#define tamanhoUsuario 16
#define tamanhoSenha 13


typedef struct {
	int codusuario;
	char usuario[tamanhoUsuario], senha[tamanhoSenha];
	int perfil, ativo;
}UsuarioLogado;

char perfil[5][20];
int opcaoSelecionada;
int programaAberto=1,logado; //usados como boleano
UsuarioLogado Usuario;
char contatenacao[25];
int resultadoLogin;

void boasvindas(){
    char espacos[]="                                                 ";
    int metadeEspaco = (48-strlen(Usuario.usuario))/2;
    espacos[metadeEspaco] = '\0';
    printf("\033[9;0H\033[K\033[J");
    printf("\033[0;32m");
    printf("%s%sBem-vindo(a) %s\n",tabs,espacos,Usuario.usuario);
    printf("\033[0m");
}

int main() {
	setlocale(LC_ALL, "Portuguese"); //Permite acentua��o em portugu�s
    strcpy(perfil[0],"Administrador");
    strcpy(perfil[1],"Gerente");
    strcpy(perfil[2],"Recursos Humanos");
    strcpy(perfil[3],"Financeiro");
    strcpy(perfil[4],"Recep��o");

    //0teste();

    getch();
    while (programaAberto){

        if(resultadoLogin!=2){
            abertura();
            cabecalho();
        }

        resultadoLogin = login(&Usuario);
        if(resultadoLogin==1){
            logado = 1;
            avisoVermelho("Senha incorreta! Tente novamente");
            limparAbaixo();
        }
        //system("pause");

        while(logado){
            strcat(strcpy(contatenacao, "Menu "),perfil[Usuario.perfil-1]);
            titulo(contatenacao);
            boasvindas();
            printf("%s* Use as setas do teclado para selecionar uma op��o\n%s* Tecle enter para escolher a op��o selecionada.\n%s* Ou tecle o n�mero da op��o desejada\n\n",tabs,tabs,tabs);
            switch(Usuario.perfil){
                case 1:
                    opcaoSelecionada=menuAdministrador();
                    switch(opcaoSelecionada){
                        case 1: // perfil Administrador
                            criarUsuario();
                            break;
                        case 2:
                            listarUsuarios(0);
                            break;
                        case 3:
                            editarUsuario();
                            break;
                        case 4:
                            alterarSenha(0);
                            break;
                        case 5:
                            system("cls");
                            printf("Realizar Backup [CriarFun��o]");
                            system("pause");
                            break;
                        case 6:
                            alterarSenha(Usuario.codusuario);
                            break;
                        case 7: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 2: // perfil Gerente
                    opcaoSelecionada=menuGerente();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            system ("notepad teste.txt");
                            getch();
                            break;
                        case 2:
                            system("cls");
                            printf("Total de funcion�rios [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Despesas do m�s atual [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Receita no m�s atual [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Lucro no m�s atual [CriarFun��o]");
                            system("pause");
                            break;
                        case 6:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 7: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 3: // Perfil RH
                    opcaoSelecionada=menuRH();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Funcion�rio [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Consultar Funcion�rios [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Agendar Entrevista [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Entrevistas [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 4: // Perfil Financeiro
                    opcaoSelecionada=menuFinanceiro();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Despesa [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Cadastrar Receita [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Listar Despesas [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Receitas [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 5: // Perfil Recep��o
                    opcaoSelecionada=menuRecepcao();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Contato [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Listar Contatos [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Registrar Atendimento Externo [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Atendimentos Externos [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                default:
                    printf("Pefil n�o reconhecido");
                    getch();
                break;
            }

        }


        /***
        switch(Usuario.perfil){
            case 1: // perfil Administrador
                //titulo("Menu administrador");
                boasvindas();
                while(logado){
                    printf("%s* Use as setas do teclado para selecionar uma op��o\n%s* Tecle enter para escolher a op��o selecionada.\n%s* Ou tecle o n�mero da op��o desejada\n\n",tabs,tabs,tabs);
                    opcaoSelecionada=menuAdministrador();
                    switch(opcaoSelecionada){
                        case 1:
                            criarUsuario();

                            break;
                        case 2:
                            system("cls");
                            //printf("Consultar Usu�rios [CriarFun��o]");
                            printf("");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Alterar Perfil de Usu�rios [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Alterar Senha de Usu�rios [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Alterar Minha Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            case 2: // perfil Gerente
                //titulo("Menu gerente");
                while(logado){
                    opcaoSelecionada=menuGerente();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Relat�rio de contrato [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Total de funcion�rios [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Despesas do m�s atual [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Receita no m�s atual [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Lucro no m�s atual [CriarFun��o]");
                            system("pause");
                            break;
                        case 6:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 7: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            case 3: // Perfil RH
                //titulo("Menu RH");
                while(logado){
                    opcaoSelecionada=menuRH();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Funcion�rio [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Consultar Funcion�rios [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Agendar Entrevista [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Entrevistas [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            case 4: // Perfil Financeiro
                //titulo("Menu financeiro");
                while(logado){
                    opcaoSelecionada=menuFinanceiro();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Despesa [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Cadastrar Receita [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Listar Despesas [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Receitas [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            case 5: // Perfil Recep��o
                //titulo("Menu recep��o");
                while(logado){
                    opcaoSelecionada=menuRecepcao();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Contato [CriarFun��o]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Listar Contatos [CriarFun��o]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Registrar Atendimento Externo [CriarFun��o]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Atendimentos Externos [CriarFun��o]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFun��o]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("op��o n�o encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            default:
            printf("Pefil n�o reconhecido");
            getch();
            break;
        }
        ****/

    }
	return 0;
}
