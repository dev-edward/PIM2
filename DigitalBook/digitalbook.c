#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "login.h"
#include "criarUsuario.h"
#include "logo.h"
#include "menus.h"

typedef struct {
	int codusuario, perfil, ativo;
	char usuario[21], senha[16];
}UsuarioLogado;

char perfil[5][20];
int opcaoSelecionada;
int programaAberto=1,logado; //usados como boleano
UsuarioLogado Usuario;
char tabs[]="\t\t\t\t\t";
char temp[100];

void boasvindas(){
    printf("\033[0;32m");
    printf("%sBem-vindo(a) %s, seu perfil é: %s\n", Usuario.usuario,perfil[Usuario.perfil-1]);
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

    getch();
    while (programaAberto){
        abertura();
        cabecalho();
        printf("\033[0;36m");
        printf("%sInsira seu usuário\n",tabs);//Adicionar "Ou tecle ESC para sair do programa\n"
        printf("\033[0m");
        if(login(&Usuario)){
            logado = 1;
        }

        //system("pause");
        switch(Usuario.perfil){
            case 1: // perfil Administrador
                while(logado){
                    opcaoSelecionada=menuAdministrador();
                    switch(opcaoSelecionada){
                        case 1:
                            //criarUsuario();
                            printf("%sDigite o nome de usuário: edward",tabs);
                            printf("%sDigite uma senha: ********",tabs);
                            printf("%sConfirme a senha: *******",tabs);
                            printf("%sDefina o perfil: administrador",tabs);
                            printf("%sUsuario ativo: sim",tabs);
                            printf("%sConfirma o cadastro (s/n): s",tabs);
                            system("pause");
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
                            printf("Alterar Senha de Usu rios [CriarFunção]");
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
        }


    }

        /*  Criaçao de usuário de teste
        criarUsuario("edward","senha1",1);
        criarUsuario("debora","senha2",2);
        criarUsuario("carol","senha3",3);
        criarUsuario("caio","senha4",4);
        criarUsuario("washington","senha5",5);
        criarUsuario("sara","senha6",6);
        */
	return 0;
}
