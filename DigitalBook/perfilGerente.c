#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "logo.h"

char opcao[5][30];
int j=0;
char tecla;

int listarOpcoes(){
    cabecalho();
    printf("Use as setas do teclado para selecionar uma op��o \nTecle enter para escolher a op��o selecionada\n");
    for(int i=0;i<5;i++){
        if(j==i)printf("\033[5;7m");
        printf("%d - %s\n",i+1,opcao[i]);
        printf("\033[m");
    }
}

int menuGerente(){
    setlocale(LC_ALL, "Portuguese");
    strcpy(opcao[0],"Relat�rio de contratos");
    strcpy(opcao[1],"Total de funcion�rios");
    strcpy(opcao[2],"Despesas do m�s atual");
    strcpy(opcao[3],"Receita no m�s atual");
    strcpy(opcao[4],"Lucro no m�s atual");

    listarOpcoes();
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if((int)tecla==80)j++;
            if((int)tecla==72)j--;
            if(j>=5)j=0;
            if(j<=-1)j=4;
            //printf("%d",j);
            //printf("%d\n",(int)tecla);
            listarOpcoes();
        }
    }
}
