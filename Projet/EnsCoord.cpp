//
//  EnsCoord.cpp
//  Projet
//
//  Created by 郑疏楠 on 17/04/2019.
//  Copyright © 2019 郑疏楠. All rights reserved.
//

#include "EnsCoord.hpp"
//afficheEC
void afficheEnsCoord(EnsCoord EC){
    for (int i=0; i<EC.nbElts; i++) {
        afficheCoord(EC.tab[i]);
    }
}

//  la fonction CreerEC 
EnsCoord nouvEnsCoord(){
    EnsCoord New;
    New.nbElts=0;
    return New;
}
//ajouteEC
void ajouteEnsCoord(EnsCoord &EC, Coord C){
    EC.nbElts++;
    EC.tab[EC.nbElts-1]=C;
}
//retourne le nombre d’éléments d’un ensemble de coor- données.
int cardEC (EnsCoord EC){
    return EC.nbElts;
}
/* retourne l’ensemble des coordonnées voisines de la coordonnée c */
EnsCoord voisines (Coord C){
    int X,Y,TAILLE;
    EnsCoord ECC;
    ECC=nouvEnsCoord();
    X=getX(C);
    Y=getY(C);
    TAILLE=20;
    for (int i=-1; i<2; i++) {
        if (X+i>=0 && X+i<TAILLE) {
            for (int j=-1; j<2; j++) {
                if (Y+j>=0 && Y+j <TAILLE) {
                    if(i!=0 || j!=0){
                    ECC.tab[ECC.nbElts].col=Y+i;
                    ECC.tab[ECC.nbElts].lig=X+j;
                        ECC.nbElts++;}
                }
            }
        }
       }
    return ECC;
    }
