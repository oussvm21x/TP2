//
// Created by abcd on 27/11/2023.
//

#ifndef TP2_MODULES_H
#define TP2_MODULES_H

#include "../TP2.h"
#include "../TOF.h"
#include "../Indexs.h"
#include <time.h>
#include "Affichage.h"
#include <conio.h>
#include "conio2.h"
#define MAX_M 999999
#define MIN_M 111111

// DÃ©claration des prototypes des fonctions
extern int gen_mat();
extern char* gen_name_alea();
extern char* gen_name_usuelle();
extern int isLeapYear(int year);
extern int getDaysInMonth(int month, int year);
extern char* gen_date();
extern char* gen_wilaya();
extern char* gen_gs();
extern char* gen_grade();
extern char* gen_force();
extern char* gen_rm();
extern int Generation_Soldat(TBenrg *Soldat);
extern int Generation_index(char filename[32], Tindex *Tab);
extern int Generation_Anp(int n, char filename[32], Tindex *Tab);


extern int Affichage_Anp(char filename[32]);
extern int Afficher_Soldat(TBenrg Soldat);
extern void Affichage_wilaya();
extern void Affichage_grades();
extern void Affichage_fa();
extern void Affichage_rm();
extern void Affichage_gs();


/////////////////////////////////////////////
//
// Created by abcd on 03/12/2023.
//


//
// Created by abcd on 27/11/2023.
//

//ICI VOUS TROUVER LES ALGORITHMES LES ALGRTHMES DE RECHERCHES
#include "Modules.h"
#include "../../Data/Data.h"

//MATRICULE :
int gen_mat() {
    int mat = ( rand() % (MAX_M - MIN_M + 1) ) + MIN_M;
    return mat;
}

//NOM & PRENOM
char* gen_name_alea() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyz";

    int size = rand() % 23 + 4;  // Vous pouvez ajuster la plage des tailles selon vos besoins
    char *name = (char*)malloc((size + 1) * sizeof(char));  // +1 pour le null-terminator

    if (name == NULL) {
        perror("Allocation de mÃ©moire a Ã©chouÃ©");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        int k = rand() % 26;
        name[i] = charset[k];
    }

    name[size] = '\0';  // Null-terminator

    return name;
}

//NOM & PRENOM REEL
char* gen_name_usuelle(){
    int i , j ;
    i = rand() % 60 ;
    j = rand() % 60 ;
    const char *prenom = names[i];
    const char *nomFamille = names[j];

    char *nomComplet = (char*)malloc(strlen(prenom) + strlen(nomFamille) + 1); // +2 pour l'espace et le caractÃ¨re nul
    sprintf(nomComplet, "%s %s", prenom, nomFamille);
    return  nomComplet ;
}
// DATE

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}
int getDaysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 31;
    }
}
char* gen_date() {
    char *date = (char*) malloc(9) ;
    int y , m , d ;
    y = rand() % (2005-1942) + 1942 ;
    m = rand() % (12) +1 ;
    d = getDaysInMonth(m , y ) ;
    d = d*1000000 + m*10000 + y ;
    sprintf(date , "%d" , d) ;
    return date ;
}

// WILAYA
char* gen_wilaya(){
    char *wilaya = (char*) malloc(21) ;
    int i = rand()%58 ;
    sprintf(wilaya , "%s" ,  wilayas[i].nom  );
    return wilaya ;

}

//GROUPE SANGIUINS
char* gen_gs(){
    char* gs = (char*) malloc(4) ;
    int i = rand()%8 ;
    sprintf(gs , "%s" ,  groupesSanguins[i] );
    return gs ;
}

//GRADE
char* gen_grade(){
    char* grade = (char*) malloc(33) ;
    int i = rand()%19 ;
    sprintf(grade , "%s" ,  grades[i].nom );
    return grade ;
}

//FORCE
char* gen_force(){
    char* force = (char*) malloc(55);
    int i = rand()%7 ;
    sprintf(force , "%s" , forceArmees[i]) ;
    return force;
}

//REGION MILITAIRE
char* gen_rm(){
    char *rm = (char*) malloc(33) ;
    int i = rand()%6 ;
    sprintf(rm , "%s" , regionsMilitaires[i].nom) ;
    return rm ;
}


//
// Created by abcd on 03/12/2023.
//
int matricule(){
    int cle ;
    printf("Entrer le matricule : ") ;
    scanf(" %i" , &cle) ;
    while(cle < 111111 && cle > 999999){
                    clrscr();
                    textcolor(RED);printf("Errure ! \n") ;textcolor(WHITE);
                    printf("Please enter a number between 111111 and 999999 : ") ;
                    scanf(" %i" , &cle) ;
                }
    return cle ;
}

char* lireNom() {
    int size = rand() % 23 + 4;  // Vous pouvez ajuster la plage des tailles selon vos besoins
    char *name = (char*)malloc((size + 1) * sizeof(char));  // +1 pour le null-terminator
    if (name == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez le nom : ");
    scanf("%s", name);
    name[size] = '\0';  // Null-terminator

    return name;
}
char* lirePNom() {
    int size = rand() % 23 + 4;  // Vous pouvez ajuster la plage des tailles selon vos besoins
    char *name = (char*)malloc((size + 1) * sizeof(char));  // +1 pour le null-terminator
    if (name == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire.\n");
        exit(EXIT_FAILURE);
    }

    printf("Entrez le prenom : ");
    scanf("%s", name);
    name[size] = '\0';  // Null-terminator

    return name;
}

int estDateValide(int jour, int mois, int annee) {
    if(annee < 1942 && annee > 2005)
        return 0;
    if (mois < 1 || mois > 12 || jour < 1) {
        return 0; // Date invalide
    }
    int joursDansLeMois[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        joursDansLeMois[2] = 29; // Année bissextile, février a 29 jours
    }
    if (jour > joursDansLeMois[mois]) {
        return 0; // Date invalide
    }
    return 1;
}

// Fonction pour lire la date de naissance
char* lireDateNaissance() {
    int jour , mois , annee;
    char *date = (char*) malloc(9) ;
    printf("Entrez la date de naissance (jj/mm/aaaa) : ");
    scanf("%d/%d/%d", &jour, &mois, &annee);
    while( estDateValide(jour , mois , annee ) == 0 ){
        system("cls");
        printf("Errure !") ;
        printf("Entrez la date de naissance (jj mm aaaa) : ");
        scanf("%d %d %d", jour, mois, annee);
    }
    jour = jour*1000000 + mois*10000 + annee ;
    sprintf(date , " %d" , jour) ;
    return date ;

}


// WILAYA
char* lire_wilaya(){
    char *wilaya = (char*) malloc(21) ;
    system("cls");
    Affichage_wilaya();
    int i ;
    printf("Selectioner la wilaya : ");
    scanf(" %i" , &i) ;
    sprintf(wilaya , "%s" ,  wilayas[i-1].nom  );
    return wilaya ;

}

//GROUPE SANGIUINS
char* lire_gs(){
    char* gs = (char*) malloc(4) ;
    system("cls");
    Affichage_gs();
    int i ;
    printf("Selectioner le groupe sanguin : ");
    scanf(" %i" , &i) ;
    sprintf(gs , "%s" ,  groupesSanguins[i-1] );
    return gs ;
}

//GRADE
char* lire_grade(){
    char* grade = (char*) malloc(33) ;
    system("cls");
    Affichage_grades();
    int i ;
    printf("Selectionner le grade : ");
    scanf(" %i" , &i) ;
    sprintf(grade , "%s" ,  grades[i-1].nom );
    return grade ;
}

//FORCE
char* lire_force(){
    char* force = (char*) malloc(55);
    system("cls");
    Affichage_fa() ;
    int i ;
    printf("Selectionner la force : ");
    scanf(" %i" , &i) ;
    sprintf(force , "%s" , forceArmees[i-1]) ;
    return force;
}

//REGION MILITAIRE
char* lire_rm(){
    char *rm = (char*) malloc(33) ;
    int i ;
    system("cls");
    Affichage_rm();
    printf("Selectioner la region : ");
    scanf(" %i" , &i);
    sprintf(rm , "%s" , regionsMilitaires[i-1].nom) ;
    return rm ;
}

int Generation_Soldat_Manuellement(TBenrg *Soldat) {
    Soldat->mat = matricule() ;
    sprintf((Soldat->prenom) , "%s" ,  lirePNom()) ;
    sprintf((Soldat->nom) , "%s" ,  lireNom()) ;
    sprintf((Soldat->dn) , "%s" , lireDateNaissance()) ;
    sprintf((Soldat->wn) , "%s" , lire_wilaya()) ;
    sprintf((Soldat->GS) , "%s" , lire_gs()) ;
    sprintf((Soldat->Grade) , "%s" , lire_grade());
    sprintf((Soldat->fa) , "%s" , lire_force()) ;
    sprintf((Soldat->rm) , "%s" , lire_rm()) ;


    return 0 ;
}


//Generation d'un soldat manuellement

int Generation_Soldat(TBenrg *Soldat){
    Soldat->mat = gen_mat() ;
    sprintf((Soldat->prenom) , "%s" ,  gen_name_alea()) ;
    sprintf((Soldat->nom) , "%s" ,  gen_name_alea()) ;
    sprintf((Soldat->dn) , "%s" , gen_date()) ;
    sprintf((Soldat->wn) , "%s" , gen_wilaya()) ;
    sprintf((Soldat->GS) , "%s" , gen_gs()) ;
    sprintf((Soldat->Grade) , "%s" , gen_grade());
    sprintf((Soldat->fa) , "%s" , gen_force()) ;
    sprintf((Soldat->rm) , "%s" , gen_rm()) ;


}


int Generation_index(char filename[32] , Tindex *Tab) {
    //Declarations
    TOF_B File ;
    TBBuffer buf ;
    //Initialisation de la Table d'index
    index_init(Tab);
    //Ouvrir le fichier
    TB_Ouvrire(&File , filename , 'A') ;

    int i = 1 , j , NB , k = 0 ;
    NB = TB_Entete(&File , 1) ;
    while(i <= NB) {
        TB_LireDir(&File , 1 , &buf) ;
        j = 0 ;

        while (j <= buf.nb ) {
            (*Tab).tab[k].cle = buf.tab[j].mat ;
            (*Tab).tab[k].i = i ;
            (*Tab).tab[k].j = j ;
            j++;
            k++ ;
        }
        i++ ;
    }
    (*Tab).nbi = k ;
    TB_Fermer(&File) ;
    return 0 ;

}

int Generation_Anp(int n , char filename[32] ,Tindex *Tab ) { // CETTE FONTION CREER LE FICHIER DE ANP ET FICHIE RD4INDEX EN MEME TEMP
    srand((unsigned int)time(NULL));
    int i=1 , j=0 , k =0, t;
    TBBuffer buf ;
    TOF_B File ;
    TB_Ouvrire(&File , filename , 'N') ;
    TBenrg e ;
    index_init(Tab) ;
    while(k < n) {
        Generation_Soldat(&e);
        if(j==MAX){
            t = index_Insertion(e.mat ,i+1 , 0 , Tab ) ;
        }

        else{
            t = index_Insertion(e.mat ,i , j , Tab ) ;
        }

        if (t == 0 ) {
           if ( j < MAX ) {
            buf.tab[j] = e ;
            //printf("j : %i \n" , j);
            j++ ;

            }
            else {
                buf.nb = j - 1 ;
                TB_EcrireDir(&File , i , &buf) ;
                i++ ;
                buf.tab[0] = e ;
                j = 1;
            }
            printf("insertion soldat [%i]\n" , k+1);
            k++;

        }

    }
    buf.nb = j - 1 ;
    TB_EcrireDir(&File , i , &buf) ;
    TB_Aff_Entete(&File , 1 , i) ;
    TB_Aff_Entete(&File , 2 , n) ;
    TB_Fermer(&File) ;
    index_sauvgarde(FILENAME_INDEX , Tab ) ;
    return 0 ;
}



#endif //TP2_MODULES_H
