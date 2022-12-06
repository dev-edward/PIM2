void teste(){
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
    /*
        //Converter inteiro para string
        int var =1234567;//575133346
        char int_str[8];
        sprintf(int_str, "%d", var);
        var =3;
        sprintf(int_str, "%d", var);
        printf("Var: %s\n", int_str);
        printf("tam: %d", strlen(int_str));
    */
    /*
        char str[30] = "1234567890b";
        char *ptr;
        int ret;

       ret = strtol(str, &ptr, 10);
       printf("The number(unsigned long integer) is %ld\n", ret);
       printf("String part is |%s|", ptr);
    */
}
