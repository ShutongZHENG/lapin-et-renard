//
//  main.cpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG and Nicolas LANTRAN. All rights reserved.
//

#include <iostream>
#include "Grille.hpp"
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
    
   std::cout <<std::endl;
    grille g;
    initialiseGrille(g);
    afficheCoord(g.A[1][1].C);
    std::cout <<g.A[1][1].Ep<<std::endl;
    afficheCoord(g.A[15][15].C);
    std::cout <<g.A[15][15].Ep<<std::endl;
    ChangeDeuxCases(g,g.A[1][1],g.A[15][15]);
    afficheCoord(g.A[1][1].C);
    std::cout <<g.A[1][1].Ep<<std::endl;
    afficheCoord(g.A[15][15].C);
    std::cout <<g.A[15][15].Ep<<std::endl;
       std::cout <<std::endl;
    afficheEnsCoord(voisinsVides(g, nouvCoord(1,1)));
       std::cout <<std::endl;
    
    for (int i=0; i<20; i++) {
        for (int j =0; j<20; j++) {
            std::cout<< g.A[i][j].Ep<<" ";
        }
        std::cout<<std::endl;
    }
}
