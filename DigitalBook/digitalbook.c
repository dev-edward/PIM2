#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "logo.h"
#include "login.h"
#include "menus.h"
#include "mensagens.h"
#include "criarUsuario.h"
#include "consultarUsuarios.h"

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
/* descobrir o numero da tecla pressionada
    while(1){
        char tecla;
        if (kbhit) {
            tecla = getch();
            printf("%d\n",(int)tecla);
        }
    }
*/
/*
system ("notepad teste.txt"); // Abrir arquivo txt no bloco de notas
*/
/* testando funções
    getch();
    int teste = ultimoCodUsuario();
    printf("%d\n",teste);
*/
/* codigos de escape
//https://www.climagic.org/mirrors/VT100_Escape_Codes.html - consultar
    system("cls");
    printf("Teste linha 1\n");
    printf("Teste linha 2\n");
    printf("Teste linha 3\n");
    printf("Teste lin");
    getch();
    printf("\033[2;0H");
    getch();
    printf("\033[2K");
    getch();
    printf("xxx");
*/
/*
//135 colunas visíveis
for(int i=0;i<14;i++){
    printf("123456789 ");
}
*/
    getch();
    while (programaAberto){
        abertura();
        cabecalho();

        if(login(&Usuario)){
            char contatenacao[25];
            logado = 1;
            strcat(strcpy(contatenacao, "Menu "),perfil[Usuario.perfil-1]);
            titulo(contatenacao);
        }
        //system("pause");

        while(logado){
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
                break;
                case 2: // perfil Gerente
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
