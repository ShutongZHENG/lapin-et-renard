//
//  Grille.hpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG. All rights reserved.
//

#ifndef Grille_hpp
#define Grille_hpp
#include "Animal.hpp"
#include "EnsCoord.hpp"

struct grille{
    int nbLapin;
    int nbRenard;
    Animal A[20][20];
};

void grilleVide(grille &g);
void copieGrille(grille g1, grille &g2);
Animal getAnimal(grille g, Coord C);
void setAnimal(grille &g, Animal a);
void initialiseGrille(grille &g);
void ChangeDeuxCases(grille &g,Animal a1,Animal a2);
EnsCoord voisinsVides(grille g, Coord c);
EnsCoord voisinsLapin(grille g, Coord c);
void deplaceTousLapins(grille g1, grille &g2);
void deplaceTousRenards(grille g1, grille &g2);
void afficheGrille(grille g);
#endif /* Grille_hpp */
