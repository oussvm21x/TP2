//
// Created by abcd on 27/11/2023.
//
//We need to make some chnages in the tof, so we can deal with the main index structer
#ifndef TP2_INDEXS_H
#define TP2_INDEXS_H
#include "TP2.h"
#include "TOF.h"
#define MAX_I 200000
typedef struct {
    int cle ;
    int i ;
    int j ;
    bool eff ;
}Tcouple;

typedef struct {
    Tcouple tab[200000] ;
    int nbi ; //Nombre d'elemnt dans l'index
}Tindex;
extern int index_init(Tindex *Tab) ;
extern int Rech_Dicho(int cle, bool *trouve, int *i, Tindex *TableIndex);
extern int index_Telechargement( char filename[32] , Tindex *TableIndex);
extern int index_sauvgarde (char filename[32] , Tindex *TableIndex);
extern int index_suppression(int cle , Tindex *TableIndex);
extern int index_Insertion(int cle , int i ,int j , Tindex *TableIndex) ;

int index_init(Tindex *Tab){
    Tab->nbi = 0;
}

int Rech_Dicho(int cle, bool *trouve, int *i, Tindex *TableIndex) {
    *trouve = false;
    int bs = (*TableIndex).nbi;
    int bi = 0;
    while( (bi <= bs ) & (*trouve)==false ) {
        (*i) = (bs+bi) / 2;
        if ( (*TableIndex).tab[(*i)].cle == cle)
            *trouve = true;
        else {
            if ( (*TableIndex).tab[(*i)].cle > cle)
                bs = (*i) - 1;
            else
                bi = (*i) + 1;

        }

    }
    if ( (*trouve) == false && bi > bs) {
        (*i) = bi;
    }
    return 0;
}


int index_Telechargement( char filename[32] , Tindex *TableIndex) { //Cette fonction telecharge la table d'index a partir de la MS
    //Declaration
    TOF File ;
    Buffer buf ;
    int i , j , k, Nb;
    //Ouvrire le fichier d'index
    if ( Ouvrire(&File, filename , 'A') != 0 )
        return 1 ;
    k = 0 ;
    i = 1 ;
    Nb = TOF_Entete(&File , 1) ;
    while ( i <= Nb ) {
        LireDir(&File , 1 , &buf) ;
        j = 0 ;
        while ( j <= buf.nb){
            (*TableIndex).tab[k].cle = buf.tab[j].cle ;
            (*TableIndex).tab[k].i = buf.tab[j].i ;
            (*TableIndex).tab[k].j = buf.tab[j].j ;
            j++ ;
            k++ ;
        }
        i++ ;
    }
    (*TableIndex).nbi = k ;
    Fermer((&File)) ;
    return 0 ;
}

int index_sauvgarde (char filename[32] , Tindex *TableIndex) { //Cette fonction sauvgarde la table d'index
    //Declaration                                      //dans un fichier en Mc
    TOF File ;
    Buffer buf ;
    int i = 1, j , Nb;
    Nb = (*TableIndex).nbi ;
    //Ouvrire le fichier d'index
    if ( Ouvrire(&File, filename , 'N') != 0 )
        return 1 ;
    j = 0 ;
    //On va utuliser la meme logique que le chargement initial
    for( int k=0 ; k<Nb; k++) {

        if ( j <= MAX ) {
            buf.tab[j].cle = (*TableIndex).tab[k].cle ;
            buf.tab[j].i = (*TableIndex).tab[k].i;
            buf.tab[j].j = (*TableIndex).tab[k].j;
            j++ ;
        }
        else {
            buf.nb = j - 1 ;
            EcrireDir(&File , i , &buf) ;
            i++ ;
            buf.tab[0].cle = (*TableIndex).tab[k].cle ;
            buf.tab[0].i = (*TableIndex).tab[k].i;
            buf.tab[0].j = (*TableIndex).tab[k].j;
            j = 1;
        }
    }
    buf.nb = j - 1 ;
    EcrireDir(&File , i , &buf) ;
    Aff_Entete(&File , 1 , i) ;
    Aff_Entete(&File , 2 , (*TableIndex).nbi) ;
    //printf("nbi :%i" , TableIndex.nbi);
    Fermer(&File) ;
    return 0 ;

}

int index_suppression(int cle , Tindex *TableIndex){
    int i  ;
    bool trouve ;
    Rech_Dicho(cle , &trouve , &i , TableIndex ) ;
    if(trouve == true ) {
        while( i < (*TableIndex).nbi - 1 ) {
            (*TableIndex).tab[i] = (*TableIndex).tab[i+1] ;
            i++;
        }
    }
    (*TableIndex).nbi-- ;
    return 0 ;
}

int index_Insertion(int cle , int i ,int j , Tindex *TableIndex) {
    bool trouve;
    int k , p;
    //printf("Tab.nbi : %i \n" ,(*TableIndex).nbi ) ;
    Rech_Dicho(cle, &trouve, &p, TableIndex);
    if (!trouve) {
        k = (*TableIndex).nbi;
        //printf("k : %i \n" , k );
        while (k > p) {
            (*TableIndex).tab[k] = (*TableIndex).tab[k - 1];
            k--;
        }
        (*TableIndex).tab[k].cle = cle;
        (*TableIndex).tab[k].j = j;
        (*TableIndex).tab[k].i = i;

        (*TableIndex).nbi++;
        return 0;
    }
    else
        return 1 ;
}


//SAUVGARDE //TELECHARGEMENT /
//SUPRESSION //INSERTION /

#endif //TP2_INDEXS_H
