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
	setlocale(LC_ALL, "Portuguese"); //Permite acentuação em português
    strcpy(perfil[0],"Administrador");
    strcpy(perfil[1],"Gerente");
    strcpy(perfil[2],"Recursos Humanos");
    strcpy(perfil[3],"Financeiro");
    strcpy(perfil[4],"Recepção");

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
            printf("%s* Use as setas do teclado para selecionar uma opção\n%s* Tecle enter para escolher a opção selecionada.\n%s* Ou tecle o número da opção desejada\n\n",tabs,tabs,tabs);
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
                            printf("Realizar Backup [CriarFunção]");
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
                            printf("opção não encontrada\n");
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
                            printf("Total de funcionários [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Despesas do mês atual [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Receita no mês atual [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Lucro no mês atual [CriarFunção]");
                            system("pause");
                            break;
                        case 6:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 7: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 3: // Perfil RH
                    opcaoSelecionada=menuRH();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Funcionário [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Consultar Funcionários [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Agendar Entrevista [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Entrevistas [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 4: // Perfil Financeiro
                    opcaoSelecionada=menuFinanceiro();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Despesa [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Cadastrar Receita [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Listar Despesas [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Receitas [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                case 5: // Perfil Recepção
                    opcaoSelecionada=menuRecepcao();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Contato [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Listar Contatos [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Registrar Atendimento Externo [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Atendimentos Externos [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
                            system("pause");
                            break;
                    }
                break;
                default:
                    printf("Pefil não reconhecido");
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
                    printf("%s* Use as setas do teclado para selecionar uma opção\n%s* Tecle enter para escolher a opção selecionada.\n%s* Ou tecle o número da opção desejada\n\n",tabs,tabs,tabs);
                    opcaoSelecionada=menuAdministrador();
                    switch(opcaoSelecionada){
                        case 1:
                            criarUsuario();

                            break;
                        case 2:
                            system("cls");
                            //printf("Consultar Usuários [CriarFunção]");
                            printf("");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Alterar Perfil de Usuários [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Alterar Senha de Usuários [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Alterar Minha Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
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
                            printf("Relatório de contrato [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Total de funcionários [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Despesas do mês atual [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Receita no mês atual [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Lucro no mês atual [CriarFunção]");
                            system("pause");
                            break;
                        case 6:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 7: // Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
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
                            printf("Cadastrar Funcionário [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Consultar Funcionários [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Agendar Entrevista [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Entrevistas [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
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
                            printf("Cadastrar Despesa [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Cadastrar Receita [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Listar Despesas [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Receitas [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            case 5: // Perfil Recepção
                //titulo("Menu recepção");
                while(logado){
                    opcaoSelecionada=menuRecepcao();
                    switch(opcaoSelecionada){
                        case 1:
                            system("cls");
                            printf("Cadastrar Contato [CriarFunção]");
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            printf("Listar Contatos [CriarFunção]");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            printf("Registrar Atendimento Externo [CriarFunção]");
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            printf("Listar Atendimentos Externos [CriarFunção]");
                            system("pause");
                            break;
                        case 5:
                            system("cls");
                            printf("Trocar de Senha [CriarFunção]");
                            system("pause");
                            break;
                        case 6: //Sair
                            logado = 0;
                            break;
                        default:
                            system("cls");
                            printf("opção não encontrada\n");
                            system("pause");
                            break;
                    }
                }
            break;
            default:
            printf("Pefil não reconhecido");
            getch();
            break;
        }
        ****/

    }
	return 0;
}
