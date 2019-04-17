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
