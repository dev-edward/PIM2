#include <stdio.h>
#include <conio.h>
#define tabs "\t\t\t\t     "

void titulo(char *_texto){
    char espacos[]="                                                 ";
    char umEspaco='\0';
    int metadeEspaco = (61-strlen(_texto))/2;
    if(strlen(_texto)%2==0){
        umEspaco=' ';
    }
    espacos[metadeEspaco] = '\0';
    //printf("\033[4;36m");
    //printf("\033[7;105m");
    //printf("\033[7;0H\033[K\033[J");
    printf("\033[7;0H\033[K");
    printf("%s",tabs);
    printf("\033[30;107m");
    printf("%s%s%s%c\n\n",espacos,_texto,espacos,umEspaco);
    printf("\033[0m");

}
void mensagemAzul(char *_texto){
    //printf("\033[10;0H\033[K\033[J");
    printf("\033[10;0H\033[K");
    printf("\033[0;36m");
    printf("%s%s\n",tabs,_texto);
    printf("\033[0m");
}
void avisoVermelho(char *_texto){
    char espacos[]="                                                 ";
    int metadeEspaco = (61-strlen(_texto))/2;
    if(metadeEspaco>=0){
        espacos[metadeEspaco] = '\0';
    }else{
        espacos[0] = '\0';
    }
    //printf("\033[9;0H\033[K\033[J");
    printf("\033[9;0H\033[K");
    printf("\033[0;31m");
    printf("%s%s%s\n",tabs,espacos,_texto);
    printf("\033[0m");

}
void limparAbaixo(){
    printf("\033[J");
}
int confirmacao(){
    char espacos[]="                          ";
    char tecla;
    int confirmar;
    confirmar=1;
    printf("\033[5;7m");
    printf("\n\n%s%sConfirmar%s",tabs,espacos,espacos);
    printf("\033[0m");
    printf("\n%s%sCancelar %s",tabs,espacos,espacos);

    tecla=NULL;
    while((int)tecla!=13){
        if (kbhit) {
            tecla = getch();
            if(((int)tecla==80) || ((int)tecla==72)){
                printf("\033[2A\033[K");
                confirmar==1?confirmar--:confirmar++;
                if(confirmar)printf("\033[5;7m");
                printf("\n%s%sConfirmar%s",tabs,espacos,espacos);
                printf("\033[0m");
                if(!confirmar)printf("\033[5;7m");
                printf("\n%s%sCancelar %s",tabs,espacos,espacos);
                printf("\033[0m");
            }
        }
    }
    return confirmar;
}
