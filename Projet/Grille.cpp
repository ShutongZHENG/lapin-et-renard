//
//  Grille.cpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG and Nicolas LANTRAN. All rights reserved.
//
#include <iostream>
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
     std::cout<<a1.C.lig<<","<<a1.C.col<<"-"<<a1.Ep<<" "<<a2.C.lig<<","<<a2.C.col<<"-"<<a2.Ep<<" ";
    changeCoordAnimal(a2, a1.C);
   
    g.A[getX(a1.C)][getY(a1.C)]=a2;
    changeCoordAnimal(a1, transfert);
    std::cout<<a1.C.lig<<","<<a1.C.col<<"-"<<a1.Ep<<" "<<a2.C.lig<<","<<a2.C.col<<"-"<<a2.Ep<<" "<<std::endl;
    g.A[getX(transfert)][getY(transfert)]=a1;
    
}
void initialiseGrille(grille &g){
    Coord hasard;
    Animal a;
    grilleVide(g);
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            g.A[i][j].C.lig=i;
            g.A[i][j].C.col=j;
            if (g.nbLapin <80 && g.nbRenard==0) {
                g.A[i][j]=creerAnimal(lapin, g.A[i][j].C);
                g.nbLapin++;
            }
            else if(g.nbLapin >=80 && g.nbRenard<28) {
                g.A[i][j]=creerAnimal(renard, g.A[i][j].C);
                g.nbRenard++;
            }
            
        }
    }
    for (int i=0; i<400; i++) {
        hasard.lig=NombreAleatoire(20);
        hasard.col=NombreAleatoire(20);
        a=getAnimal(g, hasard);
        std::cout<<hasard.lig<<","<<hasard.col<<"->"<<a.Ep<<" ";
        ChangeDeuxCases(g, g.A[i/20][i%20], a);
    }
}

EnsCoord voisinsVides(grille g, Coord c){
    EnsCoord EC;
    EC=nouvEnsCoord();
    EC=voisines(c);
    for(int i=0; i<EC.nbElts;i++){
        if(g.A[getX(EC.tab[i])][getY(EC.tab[i])].Ep!=vide){
            supprimeEC(EC, i+1);
            i--;
        }
           
    }
    return EC;
}
