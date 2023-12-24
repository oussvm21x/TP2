#include "Libraries/Modules/Modules.h"
#include "Libraries/Modules/Algo-Tp.h"
#include "Libraries/Modules/Modification.h"
#include "Libraries/Modules/conio2.h"
#include "Libraries/Modules/guiTools.h"
#include "Libraries/Modules/gui.h"
#include<string.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>
#define FOREGROUND_WHITE 0x07
#define BACKGROUND_BLACK 0x00

    TBenrg e ;
    Tindex Tab ;
    TOF_B File ;
    file Tete ;



int main() {
    //Generation_Anp(1000 , FILENAME_DATA , &Tab);
    ProgrammePrincipale();
    return 0;
}

void ProgrammePrincipale(){
    int itteration , choix1 , choix2 , cle , cle2;
    itteration = 0 ;
    do{
        choix1 = MENUPRINCIPAL() ;
        while(itteration == 0 && choix1 != 1){
            printf("Tu doit telecharger la table d'index d'abord , s'il vous plais choisez 1 \n") ;
            printf("press any key to continue... \n");
            fflush(stdin) ;
            getchar();
            system("cls");
            choix1 = MENUPRINCIPAL() ;
        }
        itteration++ ;
        switch(choix1){
            case 1:
                system("cls");
                printf("Telechargement\n");
                index_Telechargement(FILENAME_INDEX , &Tab) ;
                printf("Telechargement finis \n");
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break ;

            case 2:

                system("cls");
                printf("Sauvgarde\n") ;
                index_sauvgarde(FILENAME_INDEX , &Tab) ;
                printf("Sauvgarde finis \n");
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break;

            case 3:
                system("cls");
                printf("Recherche  \n");
                printf("Entrer le nemuro de matricule : ") ;
                scanf(" %i" , &cle) ;
                while(cle < 111111 && cle > 999999){
                    clrscr();
                    textcolor(RED);printf("Errure ! \n") ;textcolor(WHITE);
                    printf("Please enter a number between 111111 and 999999 : ") ;
                    scanf(" %i" , &cle) ;
                }
                Recherch_ANP(FILENAME_DATA , cle , &Tab) ;
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break ;
            case 4 :
                system("cls");
                printf("Insertion \n");
                Generation_Soldat_Manuellement(&e) ;
                printf("Soldat generee");
                Insertion_Anp(FILENAME_DATA , e , &Tab) ;
                printf("Insertion finis \n");
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break ;
            case 5 :
                system("cls");
                printf("Suppression  \n");
                printf("Entrer le nemuro de matricule : ") ;
                scanf(" %i" , &cle) ;
                while(cle < 111111 && cle > 999999){
                    clrscr();
                    textcolor(RED);printf("Errure ! \n") ;textcolor(WHITE);
                    printf("Please enter a number between 111111 and 999999 : ") ;
                    scanf(" %i" , &cle) ;
                }
                Generation_Soldat(&e) ;
                e.mat = cle ;
                Supression_Anp(FILENAME_DATA , e , &Tab) ;
                printf("Suppression finis") ;
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break ;
            case 6 :
                system("cls");
                printf("Modification du region militaire\n") ;
                printf("Entrer le nemuro de matricule : ") ;
                scanf(" %i" , &cle) ;
                while(cle < 111111 && cle > 999999){
                    clrscr();
                    textcolor(RED);printf("Errure ! \n") ;textcolor(WHITE);
                    printf("Please enter a number between 111111 and 999999 : ") ;
                    scanf(" %i" , &cle) ;
                }
                Modification_RM(FILENAME_DATA , cle , &Tab) ;
                printf("Sauvgarde finis \n");
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break;
            case 7 :
                system("cls");
                printf("Recherche par intervalle\n") ;
                printf("Entrer le nemuro de matricule 1 : ") ;
                scanf(" %i" , &cle) ;
                while(cle < 111111 && cle > 999999 ){
                    clrscr();
                    textcolor(RED);printf("Errure ! \n") ;textcolor(WHITE);
                    printf("Please enter a number between 111111 and 999999 : ") ;
                    scanf(" %i" , &cle) ;
                }
                printf("Entrer le nemuro de matricule 2: ") ;
                scanf(" %i" , &cle2) ;
                while( (cle2 < 111111 && cle2 > 999999) ){
                    clrscr();
                    textcolor(RED);printf("Errure ! \n") ;textcolor(WHITE);
                    printf("Please enter a number between 111111 and 999999 : ") ;
                    scanf(" %i" , &cle2) ;
                }
                Recherche_intervalle(FILENAME_DATA , cle , cle2 , &Tab , &Tete );
                printf("Recherche intervalle finis \n");
                printf("press any key to continue... \n");
                fflush(stdin) ;
                getchar();
                system("cls");
                break;
            case 8 :
                index_sauvgarde(FILENAME_INDEX , &Tab) ;
                break ;
        }
    }
    while( choix1 > 0 && choix1 < 8);


}
