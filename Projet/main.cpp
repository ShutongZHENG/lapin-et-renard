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
    srand(time(0)); //Définir la graine de temps
    Coord C1 = nouvCoord(0,0);
    afficheEnsCoord(voisines(C1));
    afficheCoord(randomEC(voisines(C1)));
    
       std::cout <<std::endl;
    
    Coord c1 = nouvCoord(2,1);
    Coord c2 = nouvCoord(3,4);
    Coord c3 = nouvCoord(0,0);
    // on construit un exemple d’ensemble
    EnsCoord exemple = nouvEnsCoord();
    ajouteEnsCoord(exemple, c1);
    ajouteEnsCoord(exemple, c2);
    ajouteEnsCoord(exemple, c3);
    afficheEnsCoord(exemple);
    // on ajoute encore un element
    std::cout << "ajout d’un element :" <<std::endl;
    ajouteEnsCoord (exemple, nouvCoord(4,0));
    afficheEnsCoord(exemple);
    supprimeEC(exemple,4);
        std::cout <<std::endl;
    afficheEnsCoord(exemple);
    
   
}
