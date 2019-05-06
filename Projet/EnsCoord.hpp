//
//  EnsCoord.hpp
//  Projet
//
//  Created by Shutong ZHENG on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG. All rights reserved.
//

#ifndef EnsCoord_hpp
#define EnsCoord_hpp
#include "Coord.hpp"
#define MAXENSCOORD 400

struct EnsCoord{
    Coord tab[MAXENSCOORD];
    int nbElts;
    
};

void afficheEnsCoord(EnsCoord EC);
EnsCoord nouvEnsCoord();
void ajouteEnsCoord(EnsCoord &EC, Coord C);
int cardEC (EnsCoord EC);
EnsCoord voisines (Coord C);
int NombreAleatoire(int taille);
Coord randomEC(EnsCoord EC);
void supprimeEC(EnsCoord &EC,int Num);
#endif /* EnsCoord_hpp */

