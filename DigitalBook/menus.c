#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include "logo.h"
#include "digitalbook.h"
#define tabs "\t\t\t\t     "

typedef struct opcao{
    char texto[30]; //Texto da op  o com 30 caracteres no m ximo
    int posicao;
    struct opcao *proximo;
}Opcao;
typedef struct{
    Opcao *inicio;
    int tamanho;
}Opcoes;

void inserirOpcao(Opcoes *listaOpcoes,char texto[30]){

    Opcao *opcao,*novo = (Opcao*)malloc(sizeof(Opcao));
    strcpy(novo->texto,texto);
    novo->proximo = NULL;
    if(listaOpcoes->inicio == NULL)listaOpcoes->inicio = novo;
    else{
        opcao = listaOpcoes->inicio;
        while(opcao->proximo != NULL)opcao=opcao->proximo;
        opcao->proximo = novo;
    }
    listaOpcoes->tamanho++;
    novo->posicao = listaOpcoes->tamanho;

}

int j=1;
char tecla;

void listarOpcoes(Opcoes *opcoes){
    printf("\033[14;0H\033[K\033[J"); // Vai para a linha 14 limpa a linha e as linhas abaixo
    Opcao *inicio = opcoes->inicio;
    while(inicio!=NULL){
        printf("%s",tabs);
        if(j==inicio->posicao)printf("\033[5;7m");
        printf ("%d - %s", inicio->posicao, inicio->texto);
        printf("\033[m\n");
        inicio = inicio->proximo;
    }
    /*
    for(int i=0;i<5;i++){
        if(j==i)printf("\033[5;7m");
        printf("%d - %s\n",i+1,opcao[i]);
        printf("\033[m");
    }*/
}
int selecionarOpcao(Opcoes *opcoes){
    setlocale(LC_ALL, "Portuguese");
    tecla=NULL;
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if((int)tecla>=49 && (int)tecla<=opcoes->tamanho+48){
                j=tecla-'0';
                listarOpcoes(opcoes);
                Sleep(500);
                return j;
            }
            if((int)tecla==80)j++;
            if((int)tecla==72)j--;
            if(j>opcoes->tamanho)j=1;
            if(j<1)j=opcoes->tamanho;
            listarOpcoes(opcoes);
        }
    }
    return j;
}

int menuAdministrador(){

    Opcoes opcoesAdministrador;
    opcoesAdministrador.inicio = NULL;
    opcoesAdministrador.tamanho = 0;
    j=1;

    inserirOpcao(&opcoesAdministrador,"Criar Usuário");
    inserirOpcao(&opcoesAdministrador,"Consultar Usuários");
    inserirOpcao(&opcoesAdministrador,"Alterar Perfil de Usuários");
    inserirOpcao(&opcoesAdministrador,"Alterar Senha de Usuários");
    inserirOpcao(&opcoesAdministrador,"Alterar Minha Senha");
    inserirOpcao(&opcoesAdministrador,"Sair");

    listarOpcoes(&opcoesAdministrador);
    return selecionarOpcao(&opcoesAdministrador);
}
int menuGerente(){
    Opcoes opcoesGerente;
    opcoesGerente.inicio = NULL;
    opcoesGerente.tamanho = 0;
    j=1;

    inserirOpcao(&opcoesGerente,"Relatório de contratos");
    inserirOpcao(&opcoesGerente,"Total de funcionários");
    inserirOpcao(&opcoesGerente,"Despesas do mês atual");
    inserirOpcao(&opcoesGerente,"Receita no mês atual");
    inserirOpcao(&opcoesGerente,"Lucro no mês atual");
    inserirOpcao(&opcoesGerente,"Trocar de Senha");
    inserirOpcao(&opcoesGerente,"Sair");

    listarOpcoes(&opcoesGerente);
    return selecionarOpcao(&opcoesGerente);
}
int menuRH(){
    Opcoes opcoesRH;
    opcoesRH.inicio = NULL;
    opcoesRH.tamanho = 0;
    j=1;

    inserirOpcao(&opcoesRH,"Cadastrar Funcionário");
    inserirOpcao(&opcoesRH,"Consultar Funcionários");
    inserirOpcao(&opcoesRH,"Agendar Entrevista");
    inserirOpcao(&opcoesRH,"Listar Entrevistas");
    inserirOpcao(&opcoesRH,"Trocar de Senha");
    inserirOpcao(&opcoesRH,"Sair");

    listarOpcoes(&opcoesRH);
    return selecionarOpcao(&opcoesRH);
}
int menuFinanceiro(){
    Opcoes opcoesFinanceiro;
    opcoesFinanceiro.inicio = NULL;
    opcoesFinanceiro.tamanho = 0;
    j=1;

    inserirOpcao(&opcoesFinanceiro,"Cadastrar Despesa");
    inserirOpcao(&opcoesFinanceiro,"Cadastrar Receita");
    inserirOpcao(&opcoesFinanceiro,"Listar Despesas");
    inserirOpcao(&opcoesFinanceiro,"Listar Receitas");
    inserirOpcao(&opcoesFinanceiro,"Trocar de Senha");
    inserirOpcao(&opcoesFinanceiro,"Sair");

    listarOpcoes(&opcoesFinanceiro);
    return selecionarOpcao(&opcoesFinanceiro);
}
int menuRecepcao(){
    Opcoes opcoesRecepcao;
    opcoesRecepcao.inicio = NULL;
    opcoesRecepcao.tamanho = 0;
    j=1;

    inserirOpcao(&opcoesRecepcao,"Cadastrar Contato");
    inserirOpcao(&opcoesRecepcao,"Listar Contatos");
    inserirOpcao(&opcoesRecepcao,"Registrar Atendimento Externo");
    inserirOpcao(&opcoesRecepcao,"Listar Atendimentos Externos");
    inserirOpcao(&opcoesRecepcao,"Trocar de Senha");
    inserirOpcao(&opcoesRecepcao,"Sair");

    listarOpcoes(&opcoesRecepcao);
    return selecionarOpcao(&opcoesRecepcao);
}



/*
int menuCliente(){
    Opcoes opcoesCliente;
    opcoesCliente.inicio = NULL;
    opcoesCliente.tamanho = 0;

    inserirOpcao(&opcoesSuporte,"Solicitar Suporte");
    inserirOpcao(&opcoesSuporte,"Trocar de Senha");
    inserirOpcao(&opcoesSuporte,"Sair");

    listarOpcoes(&opcoesCliente);
    return selecionarOpcao(&opcoesCliente);
}
int menuSuporte(){
    Opcoes opcoesSuporte;
    opcoesSuporte.inicio = NULL;
    opcoesSuporte.tamanho = 0;

    inserirOpcao(&opcoesSuporte,"Verificar Solicita  es de Suporte");
    inserirOpcao(&opcoesSuporte,"Trocar de Senha");
    inserirOpcao(&opcoesSuporte,"Sair");

    listarOpcoes(&opcoesSuporte);
    return selecionarOpcao(&opcoesSuporte);
}
*/

