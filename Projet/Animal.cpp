//
//  Animal.cpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG and Nicolas LANTRAN. All rights reserved.
//

#include "Animal.hpp"
#include <cstdlib>
#include <ctime>
Animal creerAnimal(espece E,Coord c){
    Animal New;
    if (E == renard) {
        New.Ep=renard;
        New.C=c;
        New.FoodLapin=FoodInit;
    }
    else if (E==lapin){
        New.Ep=lapin;
        New.C=c;
    }else{
        New.Ep=vide;
        New.C=c;
    }
    return New;
}
Coord coordAnimal(Animal A){
    return A.C;
}
espece especeAnimal(Animal A){
    return A.Ep;
}
int nourritureRenard(Animal A){
    return A.FoodLapin;
}
bool estVide(Animal A){
    return A.Ep==vide;
}
void changeCoordAnimal(Animal &A,Coord c){
    A.C=c;
}
void mangeRenard(Animal &A){
    ++A.FoodLapin;
}
void faimRenard(Animal &A){
    --A.FoodLapin;
}
//une fonction hasard qui retourne un nombre réel au hasard entre 0 et 1
float hasard(){
    return float(rand())/float(RAND_MAX);
}
bool mortAnimal(Animal A){
    return A.FoodLapin==0;
}
bool seReproduitAnimal(Animal A, int NbFree){
    if (A.Ep==lapin) {
        if (NbFree==MinFreeBirthLapin||NbFree>MinFreeBirthLapin) {
            return hasard()<=ProbBirthLapin;
        }
        return false;
    }else{
        if (A.FoodLapin >= FoodReprod) {
            return hasard()<=ProbBirthRenard;
        }
        return false;

    }
}
