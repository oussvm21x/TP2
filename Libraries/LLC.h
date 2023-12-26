//
// Created by abcd on 09/12/2023.
//

#ifndef TP2_LLC_H
#define TP2_LLC_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct Element {
    int value ;
    struct Element* next ;
}Element ;

typedef Element* Efile ;

typedef struct File
{
    Efile tete , Queue ;
}file ;


int value ( Efile f ){
    return f->value ;
}

Efile next ( Efile f ){
    return f->next ;
}

void Aff_ADR ( Efile f  , Efile q){
    f->next = q ;
}
void Aff_val ( Efile f   , int q){
    f->value = q ;
}

void initfile (file *f) {
    (*f).Queue = NULL ;
    (*f).tete = NULL ;
}

void Enfiler ( file *f , int x){
    Efile New ;
    New = malloc(sizeof(Element));
    Aff_ADR(New , NULL ) ;
    Aff_val(New , x ) ;

    if((*f).tete == NULL )
        (*f).tete = New ;
    else
        Aff_ADR((*f).Queue , New) ;
    (*f).Queue = New ;

}

void Defiler ( file *f , int *x ){

    Efile temp ;
    temp = (*f).tete ;
    *x = value(temp) ;

    if ( (*f).tete == (*f).Queue )
    {
        (*f).tete = NULL ;
        (*f).Queue = NULL ;
    }
    else {
        (*f).tete = next((*f).tete);
        free(temp);

    }

}
int teteDeFile ( file f ){
    return value( (f).tete ) ;
}

bool fileVide ( file f){
    if (!(f).tete)
        return true ;
    else
        return false ;
}

void CreerFile ( file *f , int n ){
    initfile(f) ;
    int x ;
    for(int i =0 ; i<n ;i++){
        printf("enter x :");scanf(" %d" , &x);
        Enfiler(f , x) ;
    }
}

void CreerFileAlea ( file *f , int n ){
    initfile(f) ;
    for(int i =0 ; i<n ;i++){
        Enfiler(f , rand()%10) ;
    }
}
void Afficher_list ( file *f ) {

    file R ;
    initfile(&R);
    int x , i= 1 ;

    while ( !fileVide(*f) ){
        Defiler(f , &x) ;
        printf("E[%d]: %d  ",i++ , x) ;
        Enfiler(&R , x);
    }
    while ( !fileVide(R) ){
        Defiler(&R , &x) ;
        Enfiler(f , x);
    }
    printf("\n");

}

bool recherche ( file f , int n ){
    file R ; initfile(&R);
    int x ;
    while ( !fileVide(f)){
        Defiler(&f , &x);
        if (x == n){
            return true ;
            break ;
        }
    }
    if ( fileVide(f))
        return false ;
}

void suppression ( file *f , int n ) {
    file R ;
    initfile(&R);
    int x  ; bool found = false ;
    while ( !fileVide(*f) ){

        Defiler(f , &x) ;
        if ( x != n || found) {
            Enfiler(&R , x);
        }
        else
            found = true ;
    }
    while ( !fileVide(R) ){
        Defiler(&R , &x) ;
        Enfiler(f , x);
    }
}

void insertionOrd (file *f , int n) {
    file R ;initfile(&R) ;
    int x  ;
    while ( !fileVide(*f) && teteDeFile(*f) < n ){
        Defiler(f , &x) ;
        Enfiler(&R , x) ;
    }
    Enfiler(&R , n) ;
    while ( !fileVide(*f) ){
        Defiler(f , &x) ;
        Enfiler(&R , x) ;
    }
    while ( !fileVide(R) ){
        Defiler(&R , &x) ;
        Enfiler(f , x);
    }
}
void insertionPos (file *f , int n , int p) {
    file R ;initfile(&R) ;
    int x , i=0 ;
    while ( !fileVide(*f) && i<p-1){
        Defiler(f , &x) ;
        Enfiler(&R , x) ;
        i++ ;
    }
    Enfiler(&R , n) ;
    while ( !fileVide(*f) ){
        Defiler(f , &x) ;
        Enfiler(&R , x) ;
    }
    while ( !fileVide(R) ){
        Defiler(&R , &x) ;
        Enfiler(f , x);
    }
}

void fusion (file *f1 , file *f2 , file *f3){
    initfile(f3) ;
    file R1 , R2 ;
    initfile(&R1) , initfile(&R2) ;
    int x ;
    while( !fileVide(*f2) && !fileVide(*f1)){
        if(teteDeFile(*f1) > teteDeFile(*f2)) {
            Defiler(f2 , &x);
            Enfiler(f3 , x);
            Enfiler(&R2 , x);
        }
        else {
            Defiler(f1 , &x);
            Enfiler(f3 , x);
            Enfiler(&R1 , x);
        }
    }
    while( !fileVide(*f1)){
        Defiler(f1 , &x);
        Enfiler(f3 , x);
        Enfiler(&R1 , x);
    }
    while( !fileVide(*f2) ){
        Defiler(f2 , &x);
        Enfiler(f3 , x);
        Enfiler(&R2 , x);

    }
}


#endif //TP2_LLC_H
