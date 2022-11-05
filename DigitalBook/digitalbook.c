#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include "login.h"
#include "criarUsuario.h"
#include "perfil.h"
#include "logo.h"

int main() {
	setlocale(LC_ALL, "Portuguese"); //Permite acentuação em português
	char usuario[21];
	char senha[16];
	int codusuario;
	int codperfil;
    char caractere;
    int i;
    int j;

    abertura();

    printf("Faça login para acessar o sistema.\n");
    while(1) {
        printf("Usuário: ");
        scanf("%20s", usuario); //Alternativa com sizeof(array1)
        if ((codusuario = l_usuario(usuario)) != 0 ) {
            printf("Senha: ");

            //recebe a senha de forma discreta
            i=0;
            while (i<16) {
                if (kbhit) {
                    caractere = getch();

                    system("cls");
                    cabecalho();
                    printf("Faça login para acessar o sistema.\n");
                    printf("Usuário: %s\n", usuario);
                    printf("Senha: ");

                    if ((int)caractere == 8) {
                        i--;
                    }

                    j=0;
                    while ( j <= i )
                    {
                        printf( "%c" , '*' ) ;
                        j++;
                    }
                    /* PAREI AQUI! */
                    if ((int)caractere == 8) {
                        continue;
                    }

                    if ((int)caractere == 13) {
                        senha[i]=NULL;
                        break; //sai do loop quando o usuário aperta a tecla enter
                    }

                    senha[i]=caractere;
                    i++;
                }
            }

            if ((codperfil = login(senha)) ) {
                cabecalho();
                printf("\033[0;32m");
                printf("Bem-vindo(a) %s\n", usuario);
                printf("\033[0m");
                break;
            }
            else {
                cabecalho();
                printf("\033[0;31m");
                printf("Senha incorreta! Tente novamente\n");
                printf("\033[0m");
            }
        }
        else
        {
            cabecalho();
            printf("\033[0;31m");
            printf("Usuário \"%s\" não existe! Entre com um usário válido.\n", usuario);
            printf("\033[0m");
        }
    }

	//system("pause");
	menu(codperfil);


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
