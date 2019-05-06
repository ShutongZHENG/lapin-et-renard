//
//  main.cpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG. All rights reserved.
//

#include <iostream>
#include "Grille.hpp"

int main(void){
    srand(time(0)); //Définir la graine de temps.
    std::cout <<std::endl;
    grille g;
    grille g2;
    // initialiser la grille;
    initialiseGrille(g);
    
    while (g2.nbLapin!=0 && g2.nbRenard!=0) {
         afficheGrille(g);
         deplaceTousLapins(g, g2);
         afficheGrille(g2);
         g=g2;
         deplaceTousRenards(g,g2);
         g=g2;
    }
    
    return 0;
}
