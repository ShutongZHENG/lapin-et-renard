//
//  Animal.hpp
//  Projet
//
//  Created by 郑疏楠 on 17/04/2019.
//  Copyright © 2019 郑疏楠. All rights reserved.
//

#ifndef Animal_hpp
#define Animal_hpp
#include "Coord.hpp"
enum espece{vide,renard,lapin};
struct Animal{
    espece Ep;
    Coord c;
    
};
Animal creerAnimal(espece E,Coord c);
Coord coordAnimal(Animal A);
espece especeAnimal(Animal A);
int nourritureRenard(Animal A);
bool estVide(Animal A);
void changeCoordAnimal(Animal &A,Coord C);
void mangeRenard(Animal &A);
void faimRenard(Animal &A);

#endif /* Animal_hpp */
