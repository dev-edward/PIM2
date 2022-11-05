#include <locale.h>
#include "perfilGerente.h"

int menu(int perfil){
    setlocale(LC_ALL, "Portuguese");
    printf("Use as setas do teclado para selecionar uma opção \nTecle enter para escolher a opção selecionada\n");
    switch(perfil){
        case 1:
            menuGerente();
            break;
        case 2:
            printf("Perfil RH");

            break;
        case 3:
            printf("Perfil Recepчуo");

            break;
        case 4:
            printf("Perfil Administrador");

            break;
        case 5:
            printf("Perfil Financeiro");

            break;

    }


}
