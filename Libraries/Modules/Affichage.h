//
// Created by abcd on 09/12/2023.
//

#ifndef TP2_AFFICHAGE_H
#define TP2_AFFICHAGE_H
#include "Modules.h"

int Afficher_Soldat(TBenrg Soldat) {
    printf("_______________________________________\n");
    printf("Matricule : %i \n" , Soldat.mat) ;
    printf("Nom : %s \n" , Soldat.nom) ;
    printf("Prenom : %s \n" , Soldat.prenom) ;
    printf("Date de naissance : %s \n" ,Soldat.dn ) ;
    printf("Wilaya de naissance : %s \n" , Soldat.wn) ;
    printf("Groupe Sanguin : %s \n" , Soldat.GS) ;
    printf("Grade : %s \n" , Soldat.Grade) ;
    printf("Force : %s \n" ,  Soldat.fa) ;
    printf("Region Militaire : %s \n"  , Soldat.rm) ;
    printf("_______________________________________\n");
    return 0 ;
}

int Affichage_Anp(char filename[32]) {
    TOF_B File ;
    TBBuffer buf ;
    TB_Ouvrire(&File , filename , 'A') ;
    int i = 1 , j , NB , k = 0 ;
    NB = TB_Entete(&File , 1) ;

    while(i <= NB) {
        TB_LireDir(&File , 1 , &buf) ;
        j = 0 ;
        while (j <= buf.nb ) {
                if(buf.tab[j].eff != true ){
                    Afficher_Soldat(buf.tab[j]);
                }
                j++;
            }
            i++ ;
        }

    TB_Fermer(&File) ;
    return 0 ;

}



void Affichage_wilaya(){
    int i=0 ;
    for(i=0 ; i < 58 ; i++)
        printf("%i-%s \n" , wilayas[i].numero,  wilayas[i].nom);
}
void Affichage_grades(){
    int i=0 ;
    for(i=0 ; i<19 ;i++)
        printf("%i-%s \n" ,i+1, grades[i].nom);
}
void Affichage_fa(){
    int i=0 ;
    for(i=0 ; i<7 ;i++)
        printf("%s \n" , forceArmees[i]);
}
void Affichage_rm(){
    int i=0 ;
    for(i=0 ; i<6 ;i++)
        printf("%i-%s \n" ,i+1 ,regionsMilitaires[i].nom);

}
void Affichage_gs(){
    int i=0 ;
    for(i=0 ; i<7 ;i++)
        printf("%i-%s \n" ,i+1, groupesSanguins[i]);
}
#endif //TP2_AFFICHAGE_H
