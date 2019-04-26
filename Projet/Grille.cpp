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
void afficheGrille(grille g){
    for (int i=0; i<20; i++) {
        for (int j =0; j<20; j++) {
            switch ( g.A[i][j].Ep) {
                case 0:
                    std::cout<<"0 ";
                    break;
                case 1:
                    std::cout<<"R ";
                    break;
                case 2:
                    std::cout<<"L ";
                    break;
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
void deplaceTousLapins(grille g1, grille &g2){
    copieGrille(g1, g2);
    EnsCoord EC_Lapin=nouvEnsCoord();
    EnsCoord EC_t=nouvEnsCoord();
    Coord C;
    int X,Y;
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            if(g1.A[i][j].Ep==lapin){
                ajouteEnsCoord(EC_Lapin, g1.A[i][j].C);
            }
        }
    }
    for (int i=0; i<EC_Lapin.nbElts; i++) {
        X=getX(EC_Lapin.tab[i]);
        Y=getY(EC_Lapin.tab[i]);
        EC_t=voisinsVides(g2,EC_Lapin.tab[i]);
        if (EC_t.nbElts==0) {
            C=EC_Lapin.tab[i];
        }else{
        C=randomEC(EC_t);
        }
    
        ChangeDeuxCases(g2, g2.A[X][Y], g2.A[getX(C)][getY(C)]);
    }
}
void deplaceTousRenards(grille g1, grille &g2);
