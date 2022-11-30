#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char notebook[24][150];
char banner[24][150];


int abertura(){
/*
    int i, j, n;
	system("cls");
    for (i = 0; i < 11; i++) {

        for (j = 0; j < 10; j++) {
            n = 10 * i + j;
            if (n > 108) break;
            printf("\033[%dm 0;%d  \033[m", n, n);
            printf("\033[1;%dm 1;%d \033[m", n, n);
            printf("\033[2;%dm 2;%d \033[m", n, n);
            printf("\033[2;%dm 3;%d \033[m", n, n);
            printf("\033[4;%dm 4;%d \033[m", n, n);
            printf("\033[5;%dm 5;%d \033[m", n, n);
            printf("\033[6;%dm 6;%d \033[m", n, n);
            printf("\033[7;%dm 7;%d \033[m", n, n);
            printf("\033[8;%dm 8;%d \033[m", n, n);
            printf("\033[9;%dm 9;%d \033[m", n, n);
            printf("\033[10;%dm 10;%d \033[m", n, n);
            printf("\033[11;%dm 11;%d \033[m", n, n);
            printf("\033[12;%dm 12;%d \033[m", n, n);
            printf("\033[13;%dm 13;%d \033[m", n, n);
            printf("\033[14;%dm 14;%d \033[m", n, n);
            printf("\033[15;%dm 15;%d \033[m", n, n);
            printf("\033[16;%dm 16;%d \033[m", n, n);
            printf("\033[17;%dm 17;%d \033[m", n, n);
            printf("\033[18;%dm 18;%d \033[m", n, n);
            printf("\033[19;%dm 19;%d \033[m", n, n);
            printf("\033[20;%dm 20;%d \033[m", n, n);
            printf("\033[21;%dm 21;%d \033[m", n, n);
            printf("\033[22;%dm 22;%d \033[m", n, n);
            printf("\033[23;%dm 23;%d \033[m", n, n);
            printf("\033[24;%dm 24;%d \033[m", n, n);
            printf("\033[25;%dm 25;%d \033[m", n, n);
            printf("\033[25;%dm 25;%d \033[m", n, n);
            printf("\033[26;%dm 26;%d \033[m", n, n);
            printf("\033[27;%dm 27;%d \033[m", n, n);
            printf("\033[28;%dm 28;%d \033[m", n, n);
            printf("\033[29;%dm 29;%d \033[m", n, n);
            printf("\033[30;%dm 30;%d \033[m", n, n);
            printf("\n");
        }

        printf("\n");
    }
	system("pause");
*/


    strcpy(notebook[0] ,"\033[m                                                                   ");
    strcpy(notebook[1] ,"\033[m         \033[m\033[2;1mB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B\033[m         ");
    strcpy(notebook[2] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::::::::::::::JJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[3] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::::::::::::JJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[4] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::::::::::JJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[5] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::::::::JJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[6] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::::::JJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[7] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::::JJJJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[8] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::::JJJJJJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[9] ,"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::::JJJJJJJJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[10],"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::::JJJJJJJJJJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[11],"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m::::::::::::JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[12],"\033[m         \033[m\033[2;1m@@7\033[m\033[5;36m.:::::::::JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJP\033[m\033[2;1m@@\033[m         ");
    strcpy(notebook[13],"\033[m         \033[m\033[2;1m@@&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&@@\033[m         ");
    strcpy(notebook[14],"\033[m        \033[m\033[2;0m.YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY.\033[m        ");
    strcpy(notebook[15],"\033[m        \033[m\033[2;1mB@GGBBPGBBGGBGGBGBGGBGBGGBGGGBGGPGGGPGBGGBGGPBGG\033[m\033[5;32m@\033[m\033[2;1m@B\033[m        ");
    strcpy(notebook[16],"\033[m       \033[m\033[2;1m#@5\033[m\033[1;0mY#G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##\033[m\033[2;1mG@#\033[m       ");
    strcpy(notebook[17],"\033[m     \033[m\033[2;1m.&@Y\033[m\033[1;0m5Y#G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G\033[m\033[2;1mY@&.\033[m     ");
    strcpy(notebook[18],"\033[m    \033[m\033[2;1m.&@Y\033[m\033[1;0m5Y#G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~Y##G~5\033[m\033[2;1mY@&.\033[m    ");
    strcpy(notebook[19],"\033[m   \033[m\033[2;1m.&@&\033[m\033[1;0m###GP###PB###P###BPPPPPPPPPPPPPPPPPPB###P###BP###GG##\033[m\033[2;1m#&@:\033[m   ");
    strcpy(notebook[20],"\033[m  \033[m\033[2;1m:@@@@@@@@@@@@@@@@@@@@@@@\033[m\033[2;7mY''''''''''''''Y\033[m\033[2;1m@@@@@@@@@@@@@@@@@@@@@@:\033[m  ");
    strcpy(notebook[21],"\033[m \033[m\033[2;1m~@@@@@@@@@@@@@@@@@@@@@@@@\033[m\033[2;7mJ~~~~~~~~~~~~~~J\033[m\033[2;1m@@@@@@@@@@@@@@@@@@@@@@@~\033[m ");
    strcpy(notebook[22],"\033[m \033[m\033[2;1m5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5");
    strcpy(notebook[23],"\033[m  \033[m\033[2;1m''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\033[m ");

    strcpy(banner[0] ,"");
    strcpy(banner[1] ,"");
    strcpy(banner[2] ,"");
    strcpy(banner[3] ,"\033[m\033[1;36m8888888b.  d8b          d8b 888             888                ");
    strcpy(banner[4] ,"\033[m\033[1;36m888   \"Y8b Y8P          Y8P 888             888                ");
    strcpy(banner[5] ,"\033[m\033[1;36m888    888                  888             888                ");
    strcpy(banner[6] ,"\033[m\033[1;36m888    888 888  .d88b.  888 888888  8888b.  888                ");
    strcpy(banner[7] ,"\033[m\033[1;36m888    888 888 d88P\"88b 888 888        \"88b 88\033[m\033[5;96m8                ");
    strcpy(banner[8] ,"\033[m\033[1;36m888    888 888 888  888 888 888    \033[m\033[5;96m.d888888 888                ");
    strcpy(banner[9] ,"\033[m\033[1;36m888  .d88P 888 Y88b 888 8\033[m\033[5;96m88 Y88b.  888  8\033[m\033[2;96m88 888                ");
    strcpy(banner[10],"\033[m\033[1;36m8888888P\"  8\033[m\033[5;96m88  \"Y88888 888  \033[m\033[2;96m\"Y888 \"Y888888 888                ");
    strcpy(banner[11],"\033[m\033[2;96m                    888                                        ");
    strcpy(banner[12],"\033[m\033[2;96m               Y8b d88P   \033[m\033[1;31m888888b.                     888     ");
    strcpy(banner[13],"\033[m\033[2;96m                \"Y88P\"  \033[m\033[1;31m  888  \"88b                    888     ");
    strcpy(banner[14],"                          \033[m\033[1;31m888  .88P                    888     ");
    strcpy(banner[15],"                          \033[m\033[1;31m8888888K.   .d88b.   .d88b.  888  888");
    strcpy(banner[16],"                          \033[m\033[1;31m888  \"Y88b d88\"\"88b d88\"\"88b 888 .88\033[m\033[5;91mP");
    strcpy(banner[17],"                          \033[m\033[1;31m888    888 888  888 888  \033[m\033[5;91m888 888888K ");
    strcpy(banner[18],"                          \033[m\033[1;31m888   d88P \033[m\033[5;91mY88..88P Y88..88P 8\033[m\033[2;91m88 \"88b");
    strcpy(banner[19],"                          \033[m\033[1;31m888888\033[m\033[5;91m8P\"   \"Y\033[m\033[2;91m88P\"   \"Y88P\"  888  888");
    /*strcpy(banner[20],"                                                                                                ");
    strcpy(banner[21],"                                                                                                ");
    strcpy(banner[22],"                                                                                                ");
    strcpy(banner[23],"                                                                                                ");
*/
    system("cls");
    for(int i=0;i<24;i++){
        Sleep(24);
        printf("%s%s\n",notebook[i],banner[i]);
    }

    if((int)getch()==27)exit(0);
}
int cabecalho(){
    char tabs[]="\t\t\t\t\t";
    system("cls");/*
    printf("\033[m\033[30;100m \033[m\033[1;104m   ___  _      _ _        _  \033[m\033[30;104m  ___           _     \033[m\033[30;100m \033[m\n");
    printf("\033[m\033[30;100m \033[m\033[1;104m  |   \\(_)__ _(_) |_ __ _| | \033[m\033[30;104m | _ ) ___  ___| |__  \033[m\033[30;100m \033[m\n");
    printf("\033[m\033[30;100m \033[m\033[1;104m  | |) | / _` | |  _/ _` | | \033[m\033[30;104m | _ \\/ _ \\/ _ \\ / /  \033[m\033[30;100m \033[m\n");
    printf("\033[m\033[30;100m \033[m\033[1;104m  |___/|_\\__, |_|\\__\\__,_|_| \033[m\033[30;104m |___/\\___/\\___/_\\_\\  \033[m\033[30;100m \033[m\n");
    printf("\033[m\033[30;100m \033[m\033[1;104m         |___/               \033[m\033[30;104m                      \033[m\033[30;100m \033[m\n");
*/

    printf("%s\033[m\033[30;100m \033[m\033[1;104m   ___  _      _ _        _    ___           _     \033[m\033[30;100m \033[m\n",tabs);
    printf("%s\033[m\033[30;100m \033[m\033[1;104m  |   \\(_)__ _(_) |_ __ _| |  | _ ) ___  ___| |__  \033[m\033[30;100m \033[m\n",tabs);
    printf("%s\033[m\033[30;100m \033[m\033[1;104m  | |) | / _` | |  _/ _` | |  | _ \\/ _ \\/ _ \\ / /  \033[m\033[30;100m \033[m\n",tabs);
    printf("%s\033[m\033[30;100m \033[m\033[1;104m  |___/|_\\__, |_|\\__\\__,_|_|  |___/\\___/\\___/_\\_\\  \033[m\033[30;100m \033[m\n",tabs);
    printf("%s\033[m\033[30;100m \033[m\033[1;104m         |___/                                     \033[m\033[30;100m \033[m\n",tabs);
}
void titulo(char *_texto){
    char tabs[]="\t\t\t\t\t";
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

