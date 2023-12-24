//
// Created by abcd on 09/12/2023.
//

#ifndef TP2_MODIFICATION_H
#define TP2_MODIFICATION_H
#include "Algo-Tp.h"

int Modification_RM(char filename[32] , int cle , Tindex *Tab) {
    int i , j , choix , k;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(cle ,&trouve ,&k, Tab) ;
    i = (*Tab).tab[k].i ;
    j = (*Tab).tab[k].j ;
    TB_Ouvrire(&File , filename , 'A') ;
    TB_LireDir(&File , i , &buf) ;
    Affichage_rm();
    printf("Selectioner la region : ") ;
    scanf(" %i" , &choix) ;
    sprintf(buf.tab[j].rm , "%s" , regionsMilitaires[choix-1].nom );
    TB_EcrireDir(&File , i , &buf) ;
    TB_Fermer(&File) ;

}

int Modification_wilaya(char filename[32] , int cle, Tindex *Tab) {
    int i , j , choix ,k;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(cle ,&trouve ,&k, Tab);
    i = (*Tab).tab[k].i ;
    j = (*Tab).tab[k].j ;
    TB_Ouvrire(&File , filename , 'A') ;
    TB_LireDir(&File , i , &buf) ;
    Affichage_wilaya();
    printf("Selectioner la wilaya : ") ;
    scanf(" %i" , &choix) ;
    sprintf(buf.tab[j].wn , "%s" , wilayas[choix-1].nom );
    TB_EcrireDir(&File , i , &buf) ;
    TB_Fermer(&File) ;

}

int Modification_grade(char filename[32] , int cle , Tindex *Tab) {
    int i , j , choix , k ;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(cle ,&trouve ,&k, Tab) ;
    i = (*Tab).tab[k].i ;
    j = (*Tab).tab[k].j ;
    TB_Ouvrire(&File , filename , 'A') ;
    TB_LireDir(&File , i , &buf) ;
    Affichage_grades();
    printf("Selectioner le grade : ") ;
    scanf(" %i" , &choix) ;
    sprintf(buf.tab[j].Grade , "%s" , grades[choix-1].nom);
    TB_EcrireDir(&File , i , &buf) ;
    TB_Fermer(&File) ;

}

int Modification_force(char filename[32] , int cle , Tindex *Tab) {
    int i , j , choix , k ;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(cle ,&trouve ,&k, Tab ) ;
    i = (*Tab).tab[k].i ;
    j = (*Tab).tab[k].j ;
    TB_Ouvrire(&File , filename , 'A') ;
    TB_LireDir(&File , i , &buf) ;
    Affichage_fa();
    printf("Selectioner la force : ") ;
    scanf(" %i" , &choix) ;
    sprintf(buf.tab[j].fa , "%s" , forceArmees[choix-1] );
    TB_EcrireDir(&File , i , &buf) ;
    TB_Fermer(&File) ;

}

int Modification_gs(char filename[32] , int cle , Tindex *Tab) {
    int i , j , k, choix ;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(cle ,&trouve ,&k, Tab) ;
    i = (*Tab).tab[k].i ;
    j = (*Tab).tab[k].j ;
    TB_Ouvrire(&File , filename , 'A') ;
    TB_LireDir(&File , i , &buf) ;
    Affichage_gs();
    printf("Selectioner le groupe sanguin  : ") ;
    scanf(" %i" , &choix) ;
    sprintf(buf.tab[j].GS , "%s" , groupesSanguins[choix-1] );
    TB_EcrireDir(&File , i , &buf) ;
    TB_Fermer(&File) ;

}

#endif //TP2_MODIFICATION_H
