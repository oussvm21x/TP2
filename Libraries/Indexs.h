//
// Created by abcd on 27/11/2023.
//
//We need to make some chnages in the tof, so we can deal with the main index structer
#ifndef TP2_INDEXS_H
#define TP2_INDEXS_H
#include "TP2.h"
#include "TOF.h"
#include "LLC.h"
#define MAX_I 200000

//INDEX PRIMAIRE


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
        if ( ((*TableIndex).tab[(*i)].cle == cle)  &&  ((*TableIndex).tab[(*i)].eff != true)  ){
            (*trouve) = true;

        }

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
            (*TableIndex).tab[k].eff = buf.tab[j].supprime ;
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
            buf.tab[j].supprime = (*TableIndex).tab[k].eff ;

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

int index_suppression_logique(int cle , Tindex *TableIndex){
    int i  ;
    bool trouve ;
    Rech_Dicho(cle , &trouve , &i , TableIndex ) ;
    if(trouve == true ) {
        (*TableIndex).tab[i].eff = true ;

    }
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


//INDEX SECONDAIRE ;


typedef struct {
    file fifo;
}Tcouple2;

typedef struct {
    Tcouple2 tab[7] ;
}Tindex2;

extern int index2_init(Tindex2 *Tab) ;
extern int index2_generation(char filename[32] , Tindex2 *Tab);
extern int index2_Rech(int region, file *Tete, Tindex2 *Tab);
extern int index2_suppression(int region , int mat ,Tindex2 *Tab);
extern int index2_Insertion(int region , int mat ,Tindex2 *Tab);


//index2 init
    int index2_init(Tindex2 *Tab){
    for(int i = 0 ; i < 6 ; i++){
        initfile(&((*Tab).tab[i].fifo)) ;
    }
    return 0 ;
}

int index2_generation(char filename[32] , Tindex2 *Tab) {
    index2_init(Tab) ;
    int i , j , rm ;
    TOF_B File ;
    TBBuffer buf ;
    TB_Ouvrire(&File , filename , 'A');
    for(i=1 ; i <= TB_Entete(&File , 1) ; i++){
        TB_LireDir(&File , i , &buf) ;
        for(j=0 ; j <= buf.nb ; j++){
            if(buf.tab[j].eff != true) {

                rm = (int)buf.tab[j].fa[0] - 48 - 1;
                insertionOrd(&((*Tab).tab[rm].fifo ) ,buf.tab[j].mat ) ;
            }
        }
    }
}

int index2_Rech(int region, file *Tete, Tindex2 *Tab){
    (*Tete) = ((*Tab).tab[region-1].fifo) ;
    return 0 ;
}

int index2_Insertion(int region , int mat ,Tindex2 *Tab){
    insertionOrd(&((*Tab).tab[region-1].fifo ) ,mat ) ;

}
int index2_suppression(int region , int mat ,Tindex2 *Tab){
    suppression(&((*Tab).tab[region-1].fifo ) ,mat ) ;
}

#endif //TP2_INDEXS_H
