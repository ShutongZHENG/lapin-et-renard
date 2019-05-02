//
//  Coord.hpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG. All rights reserved.
//

#ifndef COORD_HPP_INCLUDED
#define COORD_HPP_INCLUDED

struct Coord
{
    int lig;
    int col;
};

/////////////////////////////////////////////////////////////////////////////////
//                         Fonctions du type abstrait                          //
/////////////////////////////////////////////////////////////////////////////////

void creerCoord(Coord &C,int l, int c);
Coord nouvCoord(int l, int c);
int getX(Coord c);
int getY(Coord c);
bool egalCoord(Coord c1,Coord c2);
void afficheCoord(Coord C);
void testEgalCoord();
#endif
