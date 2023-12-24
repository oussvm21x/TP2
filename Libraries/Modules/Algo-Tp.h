//
// Created by abcd on 08/12/2023.
//

#ifndef TP2_ALGO_TP_H
#define TP2_ALGO_TP_H
#include "Modules.h"
#include "../LLC.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))


int Recherch_ANP(char filename[32], int cle , Tindex *Tab );
int Insertion_Anp(char filename[32] , TBenrg e , Tindex *Tab);
int Supression_Anp(char filename[32] , TBenrg e , Tindex *Tab);
int Modification_RM(char filename[32] , int cle , Tindex *Tab);
int Modification_wilaya(char filename[32] , int cle, Tindex *Tab);
int Modification_grade(char filename[32] , int cle , Tindex *Tab);
int Modification_force(char filename[32] , int cle , Tindex *Tab);
int Modification_gs(char filename[32] , int cle , Tindex *Tab);
int Recherche_intervalle(char filename[32] , int cle1 , int cle2 , Tindex *Tab , file *Tete);


int Recherch_ANP(char filename[32], int cle , Tindex *Tab ) {
    int i , j ;
    TBenrg e ;
    TOF_B File ;
    TBBuffer buf ;
    bool trouve ;
    Rech_Dicho(cle ,&trouve , &i , Tab ) ;
    if ( !trouve )
        printf("Matricule n'exist pas \n");
    else {
        j = (*Tab).tab[i].j ;
        i = (*Tab).tab[i].i ;
        TB_Ouvrire(&File , filename , 'A') ;
        TB_LireDir(&File , i , &buf) ;
        e = buf.tab[j] ;
        Afficher_Soldat(e) ;
    }
    return 0 ;
}

int Insertion_Anp(char filename[32] , TBenrg e , Tindex *Tab) {
    int i , j;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(e.mat ,&i ,&trouve , Tab ) ;
    if (!trouve) {
        TB_Insertion(filename , e) ;
        TB_Ouvrire(&File , filename , 'A') ;
        i = TB_Entete(&File , 1) ;
        j = TB_Entete(&File , 2) ;
        index_Insertion(e.mat , i , j , Tab) ;
    }
    else
        printf("Matricule exist Deja") ;

}

int Supression_Anp(char filename[32] , TBenrg e , Tindex *Tab){
    int i , j;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf ;
    Rech_Dicho(e.mat ,&i ,&trouve , Tab ) ;
    if (trouve) {
        TB_Supression(filename , e) ;
        index_suppression(e.mat , Tab) ;
    }
    else
        printf("Doesn't even exist");

}

int Recherche_intervalle(char filename[32] , int cle1 , int cle2 , Tindex *Tab , file *Tete) {
    int i  , j , mi , ma;
    bool trouve ;
    file p ;
    TOF_B FILE ;
    mi = MIN(cle1 , cle2) ;
    ma = MAX(cle1 , cle2) ;
    TB_Ouvrire(&FILE , filename , 'A');
    for(i = mi ; i <= ma ; i++ ){
        Rech_Dicho(i , &trouve , &j , Tab )  ;
        if (trouve) {
            Recherch_ANP(filename , i , Tab ) ;
            insertionOrd(Tete , i) ;
        }
    }
}


#endif //TP2_ALGO_TP_H
