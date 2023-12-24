#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED


int welcom(){
    system("cls");
    clrscr();
    system("color 00");
    showConsoleCursor(false);
    system("color 00");
    textbackground(BLACK);
    int i = 0;
    int maxColors = 6;
    int colors[] = {WHITE, LIGHTBLUE, BLUE, LIGHTCYAN , CYAN , LIGHTGRAY };
    int speed = 10;

    fflush(stdin);
    while(1)
    {
        if(kbhit())
        {
            getch();
            break;
        }

        gotoxy(1,1);
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  @@@@@@@@@@      @@        @@@@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@ @@@         @@@@@@@@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@       @@@@@@@@@@@           @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                 @@@@@         @@@@@              @@@@@@@            @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                    @@@@        @@@@                 @@@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@       @@@@@                  @@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@        @@       @@@@@@                   @@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                  @@@@@@@                  @@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                  @@@@@@@@@@@                          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                    @@@@@@@@@@@@@@@                    @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                      @@@@@@@@@@@@@@@@@                @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@            @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                               @@@@@@@@@@@@@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                                     @@@@@@@@@         @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                @@@@                    @@@@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@         @@@    @@@@                     @@@@@@        @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@                     @@@@     @@@@                     @@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@@      @@@@@@                   @@@@@         @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                  @@@@@@       @@@@@@                 @@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                @@@@@@@        @@@@@@@@@            @@@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@ @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@    @@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@\n\n");

        textcolor(BLUE);
        int w, h;
        getConsoleSize(&w, &h);
        gotoxy((w-strlen("TP  SFSD"))/2, wherey() + 2);
        printf("TP  SFSD");
        gotoxy((w-strlen("Appuyez sur une touche pour continuer ..."))/2, wherey() + 2);
        printf("Appuyez sur une touche pour continuer ...");
    }

    fflush(stdin);
    system("color 07");
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    system("cls");
    clrscr();
}

void bye(){
    system("cls");
    clrscr();
    system("color 00");

    showConsoleCursor(false);
    int i = 0;
    int maxColors = 6;
    int colors[] = {WHITE, LIGHTBLUE, BLUE, LIGHTCYAN , CYAN , LIGHTGRAY };
    int speed = 10;

    fflush(stdin);
    while(1)
    {
        if(kbhit())
        {
            getch();
            break;
        }

        gotoxy(1,1);
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                  @@@@@@@@@@      @@        @@@@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@             @@@@@@@@@@@@@@@@@@ @@@         @@@@@@@@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@@@@@@@@@           @@@@@@@       @@@@@@@@@@@           @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                 @@@@@         @@@@@              @@@@@@@            @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                    @@@@        @@@@                 @@@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@       @@@@@                  @@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@        @@       @@@@@@                   @@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                  @@@@@@@                  @@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                  @@@@@@@@@@@                          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                    @@@@@@@@@@@@@@@                    @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                      @@@@@@@@@@@@@@@@@                @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@@@@@@@@@@@@@@                         @@@@@@@@@@@@@@@@@@            @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@        @@@@@                               @@@@@@@@@@@@@@          @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@         @@@@                                     @@@@@@@@@         @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@                @@@@                    @@@@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@          @@@         @@@    @@@@                     @@@@@@        @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@@                     @@@@     @@@@                     @@@@@        @@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                    @@@@      @@@@@@                   @@@@@         @@@@@\n");
        textcolor(colors[i]);printf("\t\t     @@@@@                  @@@@@@       @@@@@@                 @@@@@           @@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t     @@@@@@                @@@@@@@        @@@@@@@@@            @@@@@@          @@@@@@@\n");
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@ @@@@@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@\n");Sleep(speed);i++;if(i%maxColors == 0)i=0;
        textcolor(colors[i]);printf("\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@    @@@@@@@@@@@@@@@@          @@@@@@@@@@@@@@@\n\n");

        textcolor(BLUE);
        printf("\t\t\t\t\tMerci pour l'utilisation du notre application\n\n");
        gotoxy(10,25);
        textcolor(CYAN);
        printf("\tRealise par :");

        textcolor(LIGHTCYAN);
        printf(" Khelifa Saadllah Oussama | Ticembal Lina     ");

        textcolor(CYAN);
        printf("Groupe :");

        textcolor(LIGHTCYAN);
        printf(" 05     ");

        textcolor(CYAN);
        printf("Section :");

        textcolor(LIGHTCYAN);
        printf(" B");

        textcolor(CYAN);
        printf("\n\t\t\t\t      Sous la supervision de :");

        textcolor(LIGHTCYAN);
        printf(" Monsieur Kermi Adel\n\n");



        textcolor(BLUE);
        printf("\t\t\t\t\t\tAppuyez sur une touche pour sortir ... ");
    }

    fflush(stdin);
    Sleep(5);
    textcolor(WHITE);
    continu();
    getch();
    clrscr();
    textbackground(0);
}


void continu(){

    printf("\n\n\n ");
    gotoxy(0,25);
    textbackground(LIGHTCYAN);
    textcolor(BLACK);
    printf("Clicker sur n'import quelle boton pour avancer ");
    textbackground(0);
}
void bienvenu(int x , int y ){
    char A[]="           ____ ___ _____ _   ___     _______ _   _ _   _              ",
         B[]="          | __ )_ _| ____| \\ | \\ \\   / / ____| \\ | | | | |             ",
         C[]="          |  _ \\| ||  _| |  \\| |\\ \\ / /|  _| |  \\| | | | |             ",
         D[]="          | |_) | || |___| |\\  | \\ V / | |___| |\\  | |_| |             ",
         E[]="          |____/___|_____|_| \\_|  \\_/  |_____|_| \\_|\\___/              ";

    textcolor(LIGHTCYAN);
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(A) ; i++){
    printf("%c" , A[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(B) ; i++){
        printf("%c" , B[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(C) ; i++){
        printf("%c" , C[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(D) ; i++){
        printf("%c" , D[i]);
    };gotoxy(x,y++);
    for(int i=0 ; i< strlen(E) ; i++){
        printf("%c" , E[i]);
    };gotoxy(x,y++);
    textcolor(0);
}
void chers(int x , int y ) {
    char A[]="                     ____ _   _ _____ ____  ____                       ",
         B[]="                    / ___| | | | ____|  _ \\/ ___|                      ",
         C[]="                   | |   | |_| |  _| | |_) \\___ \\                      ",
         D[]="                   | |___|  _  | |___|  _ < ___) |                     ",
         E[]="                    \\____|_| |_|_____|_| \\_\\____/                      ";

    textcolor(LIGHTCYAN);
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(A) ; i++){
    printf("%c" , A[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(B) ; i++){
        printf("%c" , B[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(C) ; i++){
        printf("%c" , C[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(D) ; i++){
        printf("%c" , D[i]);
    };gotoxy(x,y++);
    for(int i=0 ; i< strlen(E) ; i++){
        printf("%c" , E[i]);
    };gotoxy(x,y++);
    textcolor(0);
}

void user(int x , int y ) {
    char A[]="  _   _ _____ _   _ _     ___ ____    _  _____ _____ _   _ ____  _____ ",
         B[]=" | | | |_   _| | | | |   |_ _/ ___|  / \\|_   _| ____| | | |  _ \\| ____|",
         C[]=" | | | | | | | | | | |    | |\\___ \\ / _ \\ | | |  _| | | | | |_) |  _|  ",
         D[]=" | |_| | | | | |_| | |___ | | ___) / ___ \\| | | |___| |_| |  _ <| |___ ",
         E[]="  \\___/  |_|  \\___/|_____|___|____/_/   \\_\\_| |_____|\\___/|_| \\_\\_____|";

    textcolor(LIGHTCYAN);
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(A) ; i++){
    printf("%c" , A[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(B) ; i++){
        printf("%c" , B[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(C) ; i++){
        printf("%c" , C[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(D) ; i++){
        printf("%c" , D[i]);
    };gotoxy(x,y++);
    for(int i=0 ; i< strlen(E) ; i++){
        printf("%c" , E[i]);
    };gotoxy(x,y++);
    textcolor(0);
}

void esi() {
    char A[]="  _____ ____ ___ ";
    char B[]=" | ____/ ___|_ _|";
    char C[]=" |  _| \\___ \\| | ";
    char D[]=" | |___ ___) | | ";
    char E[]=" |_____|____/___|";
    int y = 2;
    int x = 2;
    textcolor(LIGHTCYAN);
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(A) ; i++){
    printf("%c" , A[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(B) ; i++){
        printf("%c" , B[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(C) ; i++){
        printf("%c" , C[i]);
    };
    gotoxy(x,y++);
    for(int i=0 ; i< strlen(D) ; i++){
        printf("%c" , D[i]);
    };gotoxy(x,y++);
    for(int i=0 ; i< strlen(E) ; i++){
        printf("%c" , E[i]);
    };gotoxy(x,y++);
    textcolor(0);
}



void armee(){
    textcolor(LIGHTCYAN);gotoxy(25, 3);printf("   |\\                |\\                |\\                |\\\n");
    textcolor(LIGHTCYAN);gotoxy(25, 4);printf("   || .---.          || .---.          || .---.          || .---.\n");
    textcolor(LIGHTCYAN);gotoxy(25, 5);printf("   ||/_____\\         ||/_____\\         ||/_____\\         ||/_____\\\n");
    textcolor(LIGHTCYAN);gotoxy(25, 6);printf("   ||( '.' )         ||( '.' )         ||( '.' )         ||( '.' )\n");
    textcolor(LIGHTCYAN);gotoxy(25, 7);printf("   || \\_-_/          || \\_-_/          || \\_-_/          || \\_-_/ \n");
    textcolor(LIGHTCYAN);gotoxy(25, 8);printf("   :-\"`'V'//-        :-\"`'V'//-        :-\"`'V'//-        :-\"`'V'//-\n");
    textcolor(LIGHTCYAN);gotoxy(25, 9);printf("  / ,   |// , `\\    / ,   |// , `\\    / ,   |// , `\\    / ,   |// , `\\\n");
    textcolor(LIGHTCYAN);gotoxy(25, 10);printf(" / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 11);printf("/_/||__//   || |  /_/||__//   || |  /_/||__//   || |  /_/||__//   || |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 12);printf("\\ \\/---|[]==|| |  \\ \\/---|[]==|| |  \\ \\/---|[]==|| |  \\ \\/---|[]==|| |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 13);printf(" \\/\\__/ |   \\| |   \\/\\__/ |   \\| |   \\/\\__/ |   \\| |   \\/\\__/ |   \\| |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 14);printf(" /\\|_   | Ll_\\ |   /|/_   | Ll_\\ |   /|/_   | Ll_\\ |   /|/_   | Ll_\\ |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 15);printf(" `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|\n");
    textcolor(LIGHTCYAN);gotoxy(25, 16);printf("    |   |   ||/       |   |   ||/       |   |   ||/       |   |   ||/\n");
    textcolor(LIGHTCYAN);gotoxy(25, 17);printf("    |   |   |         |   |   |         |   |   |         |   |   |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 18);printf("    |   |   |         |   |   |         |   |   |         |   |   |\n");
    textcolor(LIGHTCYAN);gotoxy(25, 19);printf("    L___l___J         L___l___J         L___l___J         L___l___J\n");
    textcolor(LIGHTCYAN);gotoxy(25, 20);printf("     |_ | _|           |_ | _|           |_ | _|           |_ | _|\n");
    textcolor(LIGHTCYAN);gotoxy(25, 21);printf(" (___|___)         (___|___)         (___|___)         (___|___)\n");
    textcolor(LIGHTCYAN);gotoxy(25, 22);printf("   ^^^ ^^^           ^^^ ^^^           ^^^ ^^^           ^^^ ^^^\n");
    Sleep(5);
    textcolor(BLACK);
    continu();
    getch();
    clrscr();
    textbackground(0);

    return 0;
}

void guns(){

    textcolor(LIGHTCYAN);gotoxy(10 , 9);printf(" +--^----------,--------,-----,--------^-,\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 10);printf(" | |||||||||   `--------'     |          O\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 11);printf(" `+---------------------------^----------|\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 12);printf("   `\\_,---------,---------,--------------'\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 13);printf("     / XXXXXX /'|       /'\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 14);printf("    / XXXXXX /  `\\    /'\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 15);printf("   / XXXXXX /`-------'\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 16);printf("  / XXXXXX /\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 17);printf(" / XXXXXX /\n");
    textcolor(LIGHTCYAN);gotoxy(10 , 18);printf("(________(\n");

    textcolor(LIGHTCYAN);gotoxy(60 , 7);printf("  (                                 _\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 8);printf("   )                               /=>\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 9);printf("  (  +____________________/\\/\\___ / /|\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 10);printf("   .'' ._____________'._____      / /|/\\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 11);printf("  : () :              :\\ ----\\|    \\ )\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 12);printf("   '..'______________.'0|----|      \\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 13);printf("                     0_0/____/        \\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 14);printf("                         |----    /----\\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 15);printf("                        || -\\\\ --|      \\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 16);printf("                        ||   || ||\\      \\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 17);printf("                         \\\\____// '|      \\\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 18);printf("Bang! Bang!                     .'/       |\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 19);printf("                               .:/        |\n");
    textcolor(LIGHTCYAN);gotoxy(60 , 20);printf("                               :/_________|\n");
    Sleep(5);
    textcolor(BLACK);
    continu();
    getch();
    clrscr();
    textbackground(0);

}

void introduction (){
    char A[] = "BIENVENU CHERS UTILISTEUR \n"  ;
    char B[] = "VOICI LA SOLUTION DU TP02 'Gestion de fichier d'ANP \n";
    char C[] = "Module : SFSD \n" ;
    char D[] = "Realiser Par : \n";
    char D1[]= "Khelifa Saadallah Oussama";
    char D2[]= "Tycembal Lyna \n";
    char E[] = "Pour voir le menu clicker un button \n";
    gotoxy(40 , 3);
    for(int i=0 ; i< strlen(A) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , A[i]);
        Sleep(5);
        textbackground(0);

    };
    printf("\n\n");
    gotoxy(27 , 6);
    for(int i=0 ; i< strlen(B) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , B[i]);
        Sleep(5);
        textbackground(0);

    };
    printf("\n\n");
    gotoxy(45, 9);
    for(int i=0 ; i< strlen(C) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , C[i]);
        Sleep(5);
        textbackground(0);
    };
    printf("\n\n");
    gotoxy(45 , 12);
    for(int i=0 ; i< strlen(D) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , D[i]);
        Sleep(5);
        textbackground(0);
    };
    gotoxy(40 , 15);
    for(int i=0 ; i< strlen(D1) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , D1[i]);
        Sleep(5);
        textbackground(0);
    };
    gotoxy(45 , 18);
    for(int i=0 ; i< strlen(D2) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , D2[i]);
        Sleep(5);
        textbackground(0);
    };
    gotoxy(35, 22 );
    for(int i=0 ; i< strlen(E) ; i++){
        textbackground(LIGHTCYAN);
        printf("%c" , E[i]);
        Sleep(5);
        textbackground(0);
    };

}


void salutation(){
    bienvenu(29,3);
    chers(30,9);
    user(28,15);
    Sleep(5);
    continu();
    getch();
    clrscr();
    textcolor(BLACK);
    textbackground(0);
}


void firstpage(){
    introduction();
    Sleep(5);
    continu();
    getch();
    clrscr();
    textcolor(WHITE);
    textbackground(0);
}


int MENUPRINCIPAL (){
    showConsoleCursor(false);
    clrscr();
    int c = 0;
    char ch ;
    textbackground(0);
        gotoxy(10,5);printf("---------------------------------------------------MENU--------------------------------------------- \n");
        gotoxy(5,6);if(c==1) ;printf("\t1- Chargement de l''index en MC a partir du fichier index TOF nomme  MATRICULE_INDEX.idx                 \n");
        gotoxy(5,7);if(c==2) ;printf("\t2- Sauvegarde de l''index dans MATRICULE_INDEX.idx                                                       \n");
        gotoxy(5,8);if(c==3) ;printf("\t3- Recherche d''un militaire par son matricule                                                           \n");
        gotoxy(5,9);if(c==4) ;printf("\t4- Insertion d''un nouvel enregistrement au fichier PERSONNEL-ANP_DZ.dat                                 \n");
        gotoxy(5,10);if(c==5) ;printf("\t5- Suppression d''un enregistrement donné par le matricule                                               \n");
        gotoxy(5,11);if(c==6) ;printf("\t6- Modification de la region militaire d''un enregistrement donne                                        \n");
        gotoxy(5,12);if(c==7) ;printf("\t7- Affichage ou consultation de tous militaires dont les matricules appartiennent a l'intervalle [M1, M2]\n");
        gotoxy(5,13);if(c==8) ;printf("\t8- Quitter                                                                                               \n");
do{
        ch = getch() ;

        if(ch==80){
            c = c%8+1 ;
            printf("%d",c);

        }
        if(ch==72){
            c = c - 1 ;
            if(c<1)
                c=8;
            printf("%d",c);

        }

        textbackground(0);

        gotoxy(10,5);printf("---------------------------------------------------MENU--------------------------------------------- \n");
        gotoxy(5,6);if(c==1){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t1- Chargement de l'index en MC a partir du fichier index TOF nomme  MATRICULE_INDEX.idx                  \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,7);if(c==2){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t2- Sauvegarde de l'index dans MATRICULE_INDEX.idx                                                        \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,8);if(c==3){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t3- Recherche d''un militaire par son matricule                                                           \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,9);if(c==4){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t4- Insertion d''un nouvel enregistrement au fichier PERSONNEL-ANP_DZ.dat                                 \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,10);if(c==5){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t5- Suppression d''un enregistrement donné par le matricule                                               \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,11);if(c==6){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t6- Modification de la region militaire d''un enregistrement donne                                        \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,12);if(c==7){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t7- Affichage ou consultation de tous militaires dont les matricules appartiennent a l'intervalle [M1, M2]\n");textbackground(0);textcolor(WHITE);
        gotoxy(5,13);if(c==8){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t8- Quitter                                                                                               \n");textbackground(0);textcolor(WHITE);






    }
    while(ch!=13);

    if ( ch == 13 )
        return c ;

    //Sleep(5);
    getch();
    clrscr();
    textcolor(WHITE);
    textbackground(0);
}

int MENUSECONDAIRE (){
    showConsoleCursor(false);
    clrscr();
    int c = 0;
    char ch ;
    textbackground(0);
        gotoxy(10,5);printf("----------------MENU---------------- \n");
        gotoxy(5,6);if(c==1) ;printf("\t1- modifier le champ nom                 \n");
        gotoxy(5,7);if(c==2) ;printf("\t2- modifier le champ prenom              \n");
        gotoxy(5,8);if(c==3) ;printf("\t3- modifier le champ date de naissance   \n");
        gotoxy(5,9);if(c==4) ;printf("\t4- modifier le champ wilaya de naissance \n");
        gotoxy(5,10);if(c==5) ;printf("\t5- modifier le champ groupe sanguin     \n");
        gotoxy(5,11);if(c==6) ;printf("\t6- modifier le champ grade              \n");
        gotoxy(5,12);if(c==7) ;printf("\t7- modifier le champ force armee        \n");
        gotoxy(5,13);if(c==8) ;printf("\t8- modifier le champ regiion militare   \n");
        gotoxy(5,14);if(c==9) ;printf("\t9- Quitter                              \n");
do{
        ch = getch() ;

        if(ch==80){
            c = c%9+1 ;
            printf("%d",c);

        }
        if(ch==72){
            c = c - 1 ;
            if(c<1)
                c=9;
            printf("%d",c);

        }

        textbackground(0);

        gotoxy(10,5);printf("----------------MENU---------------- \n");
        gotoxy(5,6);if(c==1){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t1- modifier le champ nom                 \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,7);if(c==2){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t2- modifier le champ prenom              \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,8);if(c==3){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t3- modifier le champ date de naissance   \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,9);if(c==4){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t4- modifier le champ wilaya de naissance \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,10);if(c==5){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t5- modifier le champ groupe sanguin     \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,11);if(c==6){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t6- modifier le champ grade              \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,12);if(c==7){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t7- modifier le champ force armee        \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,13);if(c==8){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t8- modifier le champ regiion militare   \n");textbackground(0);textcolor(WHITE);
        gotoxy(5,14);if(c==9){textbackground(LIGHTCYAN);textcolor(BLACK);}printf("\t9- Quitter                              \n"); textbackground(0);textcolor(WHITE);






    }
    while(ch!=13);

    if ( ch == 13 )
        return c ;

    //Sleep(5);
    getch();
    clrscr();
    textcolor(WHITE);
    textbackground(0);
}













#endif // GUI_H_INCLUDED
