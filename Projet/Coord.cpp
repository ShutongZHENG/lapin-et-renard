//
//  Coord.cpp
//  Projet
//
//  Created by 郑疏楠 on 17/04/2019.
//  Copyright © 2019 郑疏楠. All rights reserved.
//

#include <iostream>
#include "Coord.hpp"
/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) std::cout << "Test failed in file " << __FILE__ \
<< " line " << __LINE__ << ": " #test << std::endl


void creerCoord(Coord &C,int l, int c){
    C.col=c;
    C.lig=l;
}
Coord nouvCoord(int l, int c){
    Coord C;
    creerCoord(C, l, c);
    return C;
}
int getX(Coord c){
    return c.lig;
}

int getY(Coord c){
    return c.col;
}
bool egalCoord(Coord c1,Coord c2){
    bool res=false;
    if (c1.lig == c2.lig)
    {
        if (c1.col == c2.col)
        {
            res= true;
        }
    }
    return res;
}
void afficheCoord(Coord C){
    std::cout <<"("<<getX(C)<<","<<getY(C)<<")"<<std::endl;
}
//test

void testEgalCoord(){
    Coord c1,c2;
    c1=nouvCoord(2, 2);
    c2=nouvCoord(2, 2);
    ASSERT(egalCoord(c1, c2));
}
