//
//  EnsCoord.hpp
//  Projet
//
//  Created by 郑疏楠 on 17/04/2019.
//  Copyright © 2019 郑疏楠. All rights reserved.
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
#endif /* EnsCoord_hpp */
