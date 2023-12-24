#ifndef TOF_H_INCLUDED
#define TOF_H_INCLUDED

#define MAX 1024

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <string.h>
#include "TP2.h"

/*DECLARATION DE LA STRECTURE TOF*/
typedef struct {
    int i , j ;
    int cle;
    bool supprime;
} Tenrg;

typedef struct {
    Tenrg tab[MAX];
    int nb;
} Tbloc, Buffer;

typedef struct {
    int numBlocs;
    int cmptInsertion;
} Entete;

typedef struct {
    FILE *f;
    Entete entete;
} TOF;


/*REALISATION DE LA MACHINE ABSTRAITE*/
int Aff_Entete(TOF *File , int i , int n) {
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



int Ouvrire(TOF *File , char fileName[32] ,  char mode ) {
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
            Aff_Entete(File , 1 , 1) ;
            Aff_Entete(File , 2 , 1) ;
        }
    }
    if ((*File).f == NULL){
        printf("Error in opening the file") ;
        return 1 ;
    }
    printf("File opned successfully\n");
    return 0 ;
}


int Fermer (TOF *File) {
    fclose(File->f) ;

}

int LireDir(TOF *File , int numBloc , Buffer *buf) {
    fseek( File->f , sizeof(File->entete)+sizeof(Tbloc)*(numBloc-1) , SEEK_SET ) ;
    fread(buf, sizeof(Tbloc), 1, File->f);
    fflush(File->f) ;
    return 0 ;
}

int EcrireDir(TOF *File , int numBloc , Buffer *buf ) {
    fseek(File->f , sizeof(File->entete)+sizeof(Tbloc)*(numBloc-1) , SEEK_SET ) ;
    fwrite(buf, sizeof(Tbloc), 1, File->f);
    fflush(File->f) ;
    return 0 ;
}

int TOF_Entete(TOF *File ,int i) {
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


int Alloc_Bloc(TOF *File) {
    int numLastBloc = TOF_Entete( File , 1) + 1 ;
    Aff_Entete(File , 1 , numLastBloc) ;
    return numLastBloc ;

}

/*REALISATION DES ALGORITHMES PRICIPALES*/

//FONCTION DE RECHERCHE
int TOF_Rech(char fileName[32], int cle, bool *Trouve, int *i, int *j) {
    // DECLARATION OF NECESSARY VARIABLES
    int bs, bi, inf, sup;
    bool stop = false;
    Buffer buf;
    TOF File;

    // BEGINNING OF THE MAIN ALGORITHM
    if (Ouvrire(&File, fileName, 'A') != 0) {
        return 1; // Failed to open the file.
    }

    bs = TOF_Entete(&File, 1);
    bi = 1;
    (*Trouve) = false;
    (*j) = 1;

    // IN THIS MODULE, WE'LL BE WORKING WITH THE DICHOTOMIC SEARCH

    // SEARCHING THE BLOCK NUMBER
    while (bi <= bs && stop == false && (*Trouve) == false) {
        *i = (bi + bs) / 2; // GO TO THE MIDDLE BLOCK
        if (LireDir(&File, *i, &buf) != 0) {
            Fermer(&File);
            return 2; // Error reading from the file.
        }

        if (buf.tab[0].cle <= cle && buf.tab[buf.nb].cle >= cle) {
            inf = 0;
            sup = buf.nb;
            while (inf <= sup && (*Trouve) == false) {
                *j = (sup + inf) / 2; // GO TO THE MIDDLE OF THE BLOCK

                if (buf.tab[*j].cle == cle) {
                    (*Trouve) = true;
                } else {
                    if (buf.tab[*j].cle < cle) {
                        inf = *j + 1;
                    } else {
                        sup = *j - 1;
                    }
                }
            }

            if (inf > sup) {
                *j = inf;
            }

            stop = true;
        } else if (buf.tab[0].cle > cle || buf.tab[buf.nb].cle < cle) {
            if (cle > buf.tab[buf.nb].cle) {
                bi = *i + 1;
            } else {
                bs = *i - 1;
            }
        }
    }

    if (bi > bs) {
        *i = bi; // WE ARE IN A NEW BLOCK
        *j = 0; // AT THE BEGINNING
    }

    Fermer(&File);
    return 0;
}

int TOF_Insertion(char fileName[32] , Tenrg e ) {
    // DECLARATION OF IMPORTANT VARIABELS
    TOF File ;
    bool trouve , stop ;
    int i , j ;
    Buffer buf ;
    Tenrg x ;

    // DEBUT DE L'ALGRITHME

    // WE'VE CALL SEARCH FUNC
    TOF_Rech(fileName  ,e.cle, &trouve , &i , &j ) ;
    if ( trouve == false ) { // IN THIS CASE WE MUST PUT THEM IN I-th BLOC  J-th POSITION
        Ouvrire(&File , fileName ,  'A') ;
        stop = false ;
        printf("%i , %i \n" , i , j) ;
        while ( stop == false && i <= TOF_Entete(&File , 1)) { //WE MUST MAKE SUR THAT WE ARE IN FILE'S BLOCS

            LireDir(&File , i , &buf) ;
            x = buf.tab[buf.nb] ;// GARDER LE DERNIER ENREG EN CAS DE DECALAGE
            int k = buf.nb ;
            while ( k > j ) {
                buf.tab[k] = buf.tab[k-1] ;
                k = k-1 ;
            }
            buf.tab[j] = e ; // INSERTION OF THE NEW ENREG

            // NOW WE NEED TO PUT AGAIN THE LAST ENREG X

            // CHECK IF IS STILL PLACE FOR X
            if(buf.nb+1 < MAX) {
                buf.nb = buf.nb+1 ;
                buf.tab[buf.nb] =  x ;
                EcrireDir(&File , i , &buf) ;
                stop = true ;
            }
            else {
                // IF WE DIDN'T FINED A PLACE FOR X IN THE CUURRENT BLOC
                // BAYNA NRO7O L LI MORAH HHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
                EcrireDir(&File , i , &buf) ;
                i ++ ;
                j = 0 ;
                e = x ;  // TO REAPET THE LOOP AND INSERT X IN THE NEXT BLOC'S FIRST POSITION
            }

        }

        if ( i > TOF_Entete(&File , 1 )){
        // IF WE DIDINT FIND A PLACE FOR X IN OUR BLOCS
        // FO9R HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
        // SAYI MNZIDCH HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
        // IN THIS CASE WE NEED TO ADD A NEW BLOC
            buf.tab[0] = e ;
            buf.nb= 0 ;
            EcrireDir(&File , i , &buf) ;
            Aff_Entete(&File , 1 , i) ;
        }

        // IF WE DON'T NEED A NEW BLOC
        Aff_Entete(&File , 2 ,TOF_Entete(&File , 2)+1) ;
        Fermer(&File) ;

    }
    return 0 ;
}

int TOF_Supression(char fileName[32] , Tenrg e ) {
    int i , j ;
    TOF File ;
    bool trouve ;
    Buffer buf ;

    //LET'S SEARCH FOR IT'S POSITION

    TOF_Rech(fileName , e.cle , &trouve , &i , &j ) ;
    if (trouve == true ) {
        Ouvrire(&File , fileName , 'A') ;
        LireDir(&File , i , &buf ) ;
        buf.tab[j].supprime = true  ;
        EcrireDir(&File , i , &buf ) ;
        Fermer(&File) ;
    }
}

int TOF_ChargementInit(char fileName[32] , int n ,float u ) {
    int i=1 , j=0 ;
    Buffer buf ;
    TOF File ;
    Ouvrire(&File , fileName , 'N') ;
    Tenrg e ;
    printf("Donner les cle en ordre croissante \n") ;
    for( int k=0 ; k<n ; k++) {
        printf("Enter a num : ") ;
        scanf(" %i" , &e.cle) ;
        printf("Enter la cle : ") ;
        scanf(" %i" , &e.cle);
        if ( j <= u*MAX ) {
            buf.tab[j] = e ;
            j++ ;
        }
        else {
            buf.nb = j - 1 ;
            EcrireDir(&File , i , &buf) ;
            i++ ;
            buf.tab[0] = e ;
            j = 1;
        }

    }
    buf.nb = j - 1 ;
    EcrireDir(&File , i , &buf) ;
    Aff_Entete(&File , 1 , i) ;
    Aff_Entete(&File , 2 , n) ;
    Fermer(&File) ;
    return 0 ;
}
 //u est le facteure de chargement initial
#endif
