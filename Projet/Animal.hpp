//
//  Animal.hpp
//  Projet
//
//  Created by Shutong ZHENG on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp
#include "Coord.hpp"
#define FoodInit 5
#define MaxFood 10
#define FoodReprod 8
#define ProbBirthLapin 0.30
#define ProbBirthRenard 0.05
#define MinFreeBirthLapin 4

enum espece{vide,renard,lapin};
struct Animal{
    espece Ep;
    Coord C;
    int FoodLapin;
};

Animal creerAnimal(espece E,Coord c);
Coord coordAnimal(Animal A);
espece especeAnimal(Animal A);
int nourritureRenard(Animal A);
bool estVide(Animal A);
void changeCoordAnimal(Animal &A,Coord c);
void mangeRenard(Animal &A);
void faimRenard(Animal &A);
float hasard();
bool mortAnimal(Animal A);
bool seReproduitAnimal(Animal A, int NbFree);

#endif /* Animal_hpp */
