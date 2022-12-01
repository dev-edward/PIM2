#define tabs "\t\t\t\t\t"

void titulo(char *_texto){
    //char tabs[]="\t\t\t\t\t";
    char espacos[]="                                                 ";
    char umEspaco='\0';
    int metadeEspaco = (53-strlen(_texto))/2;
    if(strlen(_texto)%2==0){
        umEspaco=' ';
    }
    espacos[metadeEspaco] = '\0';
    //printf("\033[4;36m");
    printf("\033[30;104m");
    printf("%s%s%s%s%c\n\n",tabs,espacos,_texto,espacos,umEspaco);
    printf("\033[0m");
}
void mensazul(char *_texto){
    //char tabs[]="\t\t\t\t\t";
    char espacos[]="                              ";
    char umEspaco="";
    int metadeEspaco = (51-strlen(_texto))/2;
    if(strlen(_texto)%2==0){
        umEspaco=' ';
    }
    espacos[metadeEspaco] = '\0';
    printf("\033[4;36m");
    printf("%s|%s%s%s%c|\n",tabs,espacos,_texto,espacos,umEspaco);
    printf("\033[0m");
}
