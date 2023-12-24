//
// Created by abcd on 27/11/2023.
//

#ifndef TP2_TP2_H
#define TP2_TP2_H

#define MAX 1024
#include "TOF.h"
#include "../Data/Data.h"
#include "Indexs.h"

extern const char *FILENAME_DATA = "PERSONNEL-ANP_DZ.dat" ;
extern const char *FILENAME_INDEX = "MATRICULE_INDEX.idx" ;

typedef struct {
    int mat; //MATRICULE
    char nom[30];
    char prenom[30];
    char wn[20] ; //WILAYA DE NAISSANCE
    char GS[4] ; //GROUPE SANGUIN
    char Grade[32] ;
    char fa[55] ;  //FORCE ARMEE
    char rm[32]; // REGION MILITAIRE
    char dn[8] ;  //DATE DE NAISSANCE //ddmmyyyy
    bool eff ; //Pour la supression logique

} TBenrg;


typedef struct {
    TBenrg tab[MAX];
    int nb;
} TBbloc, TBBuffer;

typedef struct {
    int numBlocs;
    int cmptInsertion;
} TBEntete;

typedef struct {
    FILE *f;
    TBEntete entete;
} TOF_B;
int TB_Aff_Entete(TOF_B *File , int i , int n) {
    if (i == 1){
        (File->entete.numBlocs) = n ;
        fseek(File->f , 0 ,SEEK_SET ) ;
        fwrite(&File->entete.numBlocs ,1 , sizeof(int) , File->f );
    }
    else if (i == 2) {

        (File->entete.cmptInsertion) = n ;
        fseek(File->f , sizeof(int) ,SEEK_SET ) ;
        fwrite(&File->entete.cmptInsertion ,1 , sizeof(int) , File->f );
    }
    else {
        printf("The input is invalid") ;
        return 1 ;
    }
    return 0 ;
}



int TB_Ouvrire(TOF_B *File , char fileName[32] ,  char mode ) {
    if (mode != 'A' && mode != 'a' && mode != 'N' && mode != 'n'  )
    {
        printf("Error in accessing mode , try with 'A' for open an exesting file or 'N' for a new one ") ;
        return 1 ;
    }
    else {
        if(mode == 'A' || mode == 'a') {
            (*File).f = fopen(fileName , "rb+") ;
        }
        else if(mode == 'N' || mode == 'n') {
            (*File).f = fopen(fileName , "wb") ;
            TB_Aff_Entete(File , 1 , 1) ;
            TB_Aff_Entete(File , 2 , 1) ;
        }
    }
    if ((*File).f == NULL){
        printf("Error in opening the file") ;
        return 1 ;
    }
    printf("File opned successfully\n");
    return 0 ;
}


int TB_Fermer (TOF_B *File) {
    fclose(File->f) ;
    return 0 ;

}

int TB_LireDir(TOF_B *File , int numBloc , TBBuffer *buf) {
    fseek( File->f , sizeof(File->entete)+sizeof(TBbloc)*(numBloc-1) , SEEK_SET ) ;
    fread(buf, sizeof(TBbloc), 1, File->f);
    fflush(File->f) ;
    return 0 ;
}

int TB_EcrireDir(TOF_B *File , int numBloc , TBBuffer *buf ) {
    fseek(File->f , sizeof(File->entete)+sizeof(TBbloc)*(numBloc-1) , SEEK_SET ) ;
    fwrite(buf, sizeof(TBbloc), 1, File->f);
    fflush(File->f) ;
    return 0 ;
}

int TB_Entete(TOF_B *File ,int i) {
    if (i == 1) {
        fseek(File->f , 0 ,SEEK_SET ) ;
        fread(&File->entete.numBlocs, sizeof(int), 1, File->f);
        return File->entete.numBlocs ;
    }
    else if (i == 2) {
        fseek(File->f , sizeof(int) ,SEEK_SET ) ;
        fread(&File->entete.cmptInsertion, sizeof(int), 1, File->f);
        return File->entete.cmptInsertion ;
    }
    else {
        printf("The input is invalid") ;
        return 0 ;
    }
}


int TB_Alloc_Bloc(TOF_B *File) {
    int numLastBloc = TB_Entete( File , 1) + 1 ;
    TB_Aff_Entete(File , 1 , numLastBloc) ;
    return numLastBloc ;

}


/////////////////////////////////////////////////////////////////////////////
/* TOF_B ALGORITHMS */
/*______________CREATION________________*/
int TB_Creation(char filename[32]) {
    TOF_B File ;
    TB_Ouvrire(&File , filename, 'N');
    TB_Aff_Entete(&File , 1 , 0 ) ;
    TB_Aff_Entete(&File , 2 , 0 ) ;
    TB_Fermer(&File) ;
    return 0 ;

}

/*______________RECHERCEH_______________*/
int TB_Recherch(char filename[32] , int cle , bool *Trouve ,int *i , int *j) {

    //DECLARATION
    TOF_B File ;
    TBBuffer buf;
    int Nb ; // Nombre des blocs
    //Ouvrire le fichier
    if (TB_Ouvrire(&File, filename, 'A') != 0) {
        return 1; // Failed to open the file.
    }
    //initialisation
    Nb = TB_Entete(&File , 1 ) ;
    (*i) = 1 ;
    (*Trouve) = false ;
    //MAIN LOOP
    while ((*i) <= Nb && (*Trouve) == false) {
        TB_LireDir(&File , (*i) , &buf) ;
        (*j) = 1 ;
        while((*j) <= buf.nb && (*Trouve)==false) {
            if(buf.tab[(*j)].mat == cle )
                (*Trouve) = true ;
            (*j)++;
        }
        if ( (*Trouve) == false )
            (*i)++ ;
    }
    TB_Fermer(&File) ;
    return 0 ;
}

/*______________Insertion______________*/
int TB_Insertion(char filename[32], TBenrg e ) {
    //Declaration
    TOF_B File ;
    TBBuffer buf ;
    bool Trouve ;
    int i , j , Nb ;
    //Recherche
    TB_Recherch(filename , e.mat , &Trouve , &i , &j ) ;
    if(Trouve == false ) {
        //Start Insertion
        TB_Ouvrire(&File,filename , 'A') ;
        Nb = TB_Entete(&File , 1) ;
        if ( Nb > 0 ){
            TB_LireDir(&File , Nb , &buf) ;
        }
        else {
            Nb = 1 ;
            TB_Aff_Entete(&File , 1 , Nb) ;
            buf.nb = 0  ;
        }
        if(buf.nb < MAX) {
            buf.nb ++ ;
            buf.tab[buf.nb] = e ;
            TB_EcrireDir(&File , Nb , &buf) ;
        }
        else {
            buf.nb = 1 ;
            buf.tab[1] = e ;
            TB_EcrireDir(&File , Nb+1 , &buf );
            TB_Aff_Entete(&File , 1 , Nb+1) ;
            TB_Aff_Entete(&File , 2 , buf.nb) ;
        }
        TB_Fermer(&File) ;
    }
    return 0 ;
}


/*_________________Supression____________________*/
int TB_Supression (char filename[32] , TBenrg e) {
    int i , j , Nb;
    bool trouve ;
    TOF_B File ;
    TBBuffer buf1 , buf2 ;

    TB_Recherch(filename , e.mat , &trouve , &i , &j) ;
    if(trouve) {
        TB_Ouvrire(&File,filename,'A') ;
        Nb = TB_Entete(&File , 1) ;
        if ( i != Nb) {
            TB_LireDir(&File , i , &buf1) ;
            TB_LireDir(&File , Nb , &buf2) ;
            buf1.tab[j] = buf2.tab[buf2.nb-1] ;
            buf2.nb-- ;
            TB_EcrireDir(&File , i , &buf1) ;
            if(buf2.nb > 0 ) {
                TB_EcrireDir(&File , Nb , &buf2) ;
            }
            else
                TB_Aff_Entete(&File , 1 , Nb-1) ;
        }
        else {
            TB_LireDir(&File , Nb , &buf1) ;
            buf1.tab[j] = buf1.tab[buf1.nb-1] ;
            buf1.nb -- ;
            if (buf1.nb > 0)
                TB_EcrireDir(&File , Nb , &buf1) ;
            else
                TB_Aff_Entete(&File , 1 , Nb-1) ;
        }

        TB_Aff_Entete(&File , 2 , TB_Entete(&File , 2) - 1 )  ;
        TB_Fermer(&File) ;

    }
    return 0 ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*_______________INDEXATION__________________*/

#endif //TP2_TP2_H
