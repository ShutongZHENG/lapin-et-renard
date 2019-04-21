//
//  main.cpp
//  Projet
//
//  Created by 郑疏楠 on 17/04/2019.
//  Copyright © 2019 郑疏楠. All rights reserved.
//

#include <iostream>
#include "Coord.hpp"
#include "EnsCoord.hpp"
int main(){
    Coord c1 = nouvCoord(2,1);
    afficheEnsCoord(voisines(c1));
}
