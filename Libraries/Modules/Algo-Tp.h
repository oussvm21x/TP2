//
// Created by abcd on 08/12/2023.
//

#ifndef TP2_ALGO_TP_H
#define TP2_ALGO_TP_H
#include "Modules.h"
#include "../LLC.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
Tindex Table ;

int Recherch_ANP(char filename[32], int cle , Tindex *Tab );
int Insertion_Anp(char filename[32] , TBenrg e , Tindex *Tab);
int Supression_Anp(char filename[32] , TBenrg e , Tindex *Tab);
int Suppression_Logique_Anp(char filename[32] , TBenrg e , Tindex *Tab);
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
    if (trouve == false ) {
        TB_Insertion(filename , e) ;
        TB_Ouvrire(&File , filename , 'A') ;
        i = TB_Entete(&File , 1) ;
        j = TB_Entete(&File , 2) ;
        index_Insertion(e.mat , i , j , Tab) ;
    }
    else
        printf("Matricule exist Deja \n") ;

}

int Supression_Anp(char filename[32] , TBenrg e , Tindex *Tab){
    int i , j ;
    TOF_B File ;
    TBBuffer buf ;
    bool trouve ;
    Rech_Dicho(e.mat ,&trouve , &i , Tab ) ;
    if (trouve) {
        TB_Supression(filename , e) ;
        index_suppression(e.mat , Tab) ;
    }
    else
        printf("Doesn't even exist \n");
    return 0 ;


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

int Suppression_Logique_Anp(char filename[32] , TBenrg e , Tindex *Tab){
    int i , j ;
    TOF_B File ;
    TBBuffer buf ;
    bool trouve ;
    Rech_Dicho(e.mat ,&trouve , &i , Tab ) ;
    if (trouve) {
        TB_Supression_Logique(filename , e);
        index_suppression_logique(e.mat , Tab);
    }
    else
        printf("Doesn't even exist \n");
    return 0 ;

}


int Suppression_Les_Soldats_par_fa(char filename[32] , Tindex *Tab , Tindex2 *Tab2){
    //NOTE SUR L'UTULISATION :
    // TU DOIT DABORD GENERER L'INDEX 2 ,
    // TELECHARGER L'INDEX 2
    // PUIS VOUS SUPPRIMER
    // SAUVGARDER L'INDEX 2;
    int fa ;
    int x , i  ;
    TBenrg e ;
    file f;
    Affichage_fa();
    printf("Slecetionner la force que vous voulez supprimer : ");
    scanf(" %i" , &fa);
    f = (*Tab2).tab[fa-1].fifo ;
    //Afficher_list(&f);
    while ( !fileVide(f) ){
        Defiler(&f , &x) ;
        e.mat = x ;
        Suppression_Logique_Anp(FILENAME_DATA , e , Tab);
    }


}

int Fragmenation_Anp(char filename[32] , char filename1[32] , char filename2[32] , char filename3[32] , char filename4[32] , char filename5[32] , char filename6[32] )
{
    printf("CC");
    TOF_B File , File1 ,File2 ,File3 ,File4 ,File5 ,File6  ;
    TBBuffer buf ,buf1 ,buf2 ,buf3 ,buf4 ,buf5 ,buf6 ;
    TBenrg e;
    int rm;
    int i=1 , i1=1 , i2=1 , i3=1 , i4=1 , i5=1 , i6=1 ;
    int j=0 , j1=0 , j2=0 , j3=0 , j4=0 , j5=0 , j6=0 ;
    int c1=0 , c2=0 , c3=0 , c4=0 , c5=0 , c6=0 ;
    TB_Ouvrire(&File1 , filename1 , 'N');
    TB_Ouvrire(&File2 , filename2 , 'N');
    TB_Ouvrire(&File3 , filename3 , 'N');
    TB_Ouvrire(&File4 , filename4 , 'N');
    TB_Ouvrire(&File5 , filename5 , 'N');
    TB_Ouvrire(&File6 , filename6 , 'N');
    TB_Ouvrire(&File , filename , 'A');


    while(i <= TB_Entete(&File , 1) ) {
        TB_LireDir(&File , i , &buf) ;
        for(j=0 ; j <= buf.nb ; j++) {
            e = buf.tab[j] ;
            rm = (int)buf.tab[j].rm[0] - 48 ;
            switch(rm){
                case 1 :
                    buf1.tab[j1] = buf.tab[j] ;
                    c1++ ;
                    j1++ ;
                    if( j1 > 1024){
                        buf1.nb = 1024 ;
                        TB_EcrireDir(&File1 ,i1, &buf1) ;
                        j1 = 0 ;
                        i1 = 1 ;
                    }

                    break ;
                case 2 :
                    buf2.tab[j2] = buf.tab[j] ;
                    c2++ ;
                    j2++ ;
                    if( j2 > 1024){
                        buf2.nb = 1024 ;
                        TB_EcrireDir(&File2 ,i2, &buf2) ;
                        j2 = 0 ;
                        i2 = 1 ;
                    }
                    break ;
                case 3 :
                    buf3.tab[j3] = buf.tab[j] ;
                    c3++;
                    j3++ ;
                    if( j3 > 1024){
                        buf3.nb = 1024 ;
                        TB_EcrireDir(&File3 ,i3, &buf3) ;
                        j3 = 0 ;
                        i3 = 1 ;
                    }

                    break ;
                case 4 :
                    buf4.tab[j4] = buf.tab[j] ;
                    c4++;
                    j4++ ;
                    if( j4 > 1024){
                        buf4.nb = 1024 ;
                        TB_EcrireDir(&File4 ,i4, &buf4) ;
                        j4 = 0 ;
                        i4 = 1 ;
                    }

                    break ;
                case 5 :
                    buf5.tab[j5] = buf.tab[j] ;
                    c5++;
                    j5++ ;
                    if( j5 > 1024){
                        buf5.nb = 1024 ;
                        TB_EcrireDir(&File5 ,i5, &buf5) ;
                        j5 = 0 ;
                        i5 = 1 ;
                    }

                    break ;
                case 6 :
                    buf6.tab[j6] = buf.tab[j] ;
                    c6++;
                    j6++ ;
                    if( j6 > 1024){
                        buf6.nb = 1024 ;
                        TB_EcrireDir(&File6 ,i6, &buf6) ;
                        j6 = 0 ;
                        i6 = 1 ;
                    }

                    break ;
            }
        }
        i++;
    }
    buf6.nb = j6-1 ;TB_EcrireDir(&File6 ,i6, &buf6) ;TB_Aff_Entete(&File6 , 1 , i6);TB_Aff_Entete(&File6 , 2 , c6);
    buf5.nb = j5-1 ;TB_EcrireDir(&File5 ,i5, &buf5) ;TB_Aff_Entete(&File5 , 1 , i5);TB_Aff_Entete(&File5 , 2 , c5);
    buf4.nb = j4-1 ;TB_EcrireDir(&File4 ,i4, &buf4) ;TB_Aff_Entete(&File4 , 1 , i4);TB_Aff_Entete(&File4 , 2 , c4);
    buf3.nb = j3-1 ;TB_EcrireDir(&File3 ,i3, &buf3) ;TB_Aff_Entete(&File3 , 1 , i3);TB_Aff_Entete(&File3 , 2 , c3);
    buf2.nb = j2-1 ;TB_EcrireDir(&File2 ,i2, &buf2) ;TB_Aff_Entete(&File2 , 1 , i2);TB_Aff_Entete(&File2 , 2 , c2);
    buf1.nb = j1-1 ;TB_EcrireDir(&File1 ,i1, &buf1) ;TB_Aff_Entete(&File1 , 1 , i1);TB_Aff_Entete(&File1 , 2 , c1);

    TB_Fermer(&File);
    TB_Fermer(&File1);
    TB_Fermer(&File2);
    TB_Fermer(&File3);
    TB_Fermer(&File4);
    TB_Fermer(&File5);
    TB_Fermer(&File6);

}
#endif //TP2_ALGO_TP_H
