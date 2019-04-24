//
//  Grille.cpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG and Nicolas LANTRAN. All rights reserved.
//

#include "Grille.hpp"

void grilleVide(grille &g){
    g.nbLapin=0;
    g.nbRenard=0;
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            g.A[i][j].Ep=vide;
            g.A[i][j].C.lig=i;
            g.A[i][j].C.col=j;
        }
    }
}
void copieGrille(grille g1, grille &g2){
    g2=g1;
}
Animal getAnimal(grille g, Coord C){
    return g.A[getX(C)][getY(C)];
}
void setAnimal(grille &g, Animal a){
    g.A[getX(a.C)][getY(a.C)]=a;
}
void ChangeDeuxCases(grille &g,Animal a1,Animal a2){
    Coord transfert;
    transfert=coordAnimal(a2);
    changeCoordAnimal(a2, a1.C);
    g.A[getX(a1.C)][getY(a1.C)]=a2;
    changeCoordAnimal(a1, transfert);
    g.A[getX(transfert)][getY(transfert)]=a1;
    
}
void initialiseGrille(grille &g){
    Coord hasard;
    Animal a;
    grilleVide(g);
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            g.A[i][j].C.lig=i;
            g.A[i][j].C.lig=j;
            if (g.nbLapin <80 && g.nbRenard==0) {
                g.A[i][j]=creerAnimal(lapin, g.A[i][j].C);
                g.nbLapin++;
            }
            else{
                g.A[i][j]=creerAnimal(renard, g.A[i][j].C);
                g.nbRenard++;
            }
            
        }
    }
    for (int i=0; i<108; i++) {
        hasard.lig=NombreAleatoire(20);
        hasard.col=NombreAleatoire(20);
        a=getAnimal(g, hasard);
        ChangeDeuxCases(g, g.A[i/20][i%20], a);
    }
    
    
    
}
