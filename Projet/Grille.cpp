//
//  Grille.cpp
//  Projet
//
//  Created by Shutong ZHENG and Nicolas LANTRAN on 17/04/2019.
//  Copyright © 2019 Shutong ZHENG. All rights reserved.
//
#include <iostream>
#include "Grille.hpp"

#include <stdexcept>
#include "MLV.h"
using namespace mlv;
//void AfficheGraphie(grille g){
//    window_t fenetre( "Lapin & Renard", "Graphie", 640, 480 );
//    for (int i=0; i<20; i++) {
//        for (int j=0; j<20; j++) {
//            switch (g.A[i][j].Ep) {
//                case 0:
//                    fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::white );
//                    break;
//                case 1:
//                    fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::red );
//                    break;
//                case 2:
//                    fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::blue );
//                    break;
//                default:
//                    break;
//            }
//        }
//    }
//    fenetre.update();
//    fenetre.wait_milliseconds( 42 );
//}




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
 window_t fenetre( "Lapin & Renard", "Graphie", 640, 480 ); // cree la fenetre
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

EnsCoord voisinsLapin(grille g, Coord c){
    EnsCoord EC;
    EC=nouvEnsCoord();
    EC=voisines(c);
    for(int i=0; i<EC.nbElts;i++){
        if(g.A[getX(EC.tab[i])][getY(EC.tab[i])].Ep==vide||g.A[getX(EC.tab[i])][getY(EC.tab[i])].Ep==renard){
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
    // EC_t pour EnseCood_Voisins
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
        if (seReproduitAnimal(g2.A[getX(C)][getY(C)], EC_t.nbElts)) {
            g2.A[getX(C)][getY(C)]=creerAnimal(lapin, C);
            g2.nbLapin++;
        }
        ChangeDeuxCases(g2, g2.A[X][Y], g2.A[getX(C)][getY(C)]);

        /* update the infomation */
        for (int i=0; i<20; i++) {
            for (int j=0; j<20; j++) {
                switch (g2.A[i][j].Ep) {
                    case 0:
                        fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::white );
                        break;
                    case 1:
                        fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::red );
                        break;
                    case 2:
                        fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::blue );
                        break;
                    default:
                        break;
                }
            }
            fenetre.update();
            fenetre.wait_milliseconds( 42 );
        }
       
        
        
        
        
        
        
        
    }
    std::cout<<"nb_lapin:"<<g2.nbLapin<<std::endl;
}
void deplaceTousRenards(grille g1, grille &g2){
    std::string S;
    copieGrille(g1, g2);
    EnsCoord EC_Renard=nouvEnsCoord();
    EnsCoord EC_t=nouvEnsCoord();
    Coord C_lapin, C_vide;
    int X_lapin,Y_lapin;
    int X_renard,Y_renard;
    int X_vide,Y_vide;
    for (int i=0; i<20; i++) {
        for (int j=0; j<20; j++) {
            if(g1.A[i][j].Ep==renard){
                ajouteEnsCoord(EC_Renard, g1.A[i][j].C);
            }
        }
    }
    for (int i=0; i<EC_Renard.nbElts; i++) {
        X_renard=getX(EC_Renard.tab[i]);
        Y_renard=getY(EC_Renard.tab[i]);
        faimRenard(g2.A[X_renard][Y_renard]);
        EC_t= voisinsLapin(g2, EC_Renard.tab[i]);
        if (mortAnimal(g2.A[X_renard][Y_renard])) {
            g2.nbRenard--;
            g2.A[X_renard][Y_renard].Ep=vide;
        }else{
            while (EC_t.nbElts!=0 && g2.A[X_renard][Y_renard].FoodLapin!=10) {
                C_lapin=randomEC(EC_t);
                X_lapin=getX(C_lapin);
                Y_lapin=getY(C_lapin);
                mangeRenard(g2.A[X_renard][Y_renard]);
                g2.nbLapin--;
                if (seReproduitAnimal(g2.A[X_renard][Y_renard], 1)) {
                        g2.nbRenard++;
                        g2.A[X_lapin][Y_lapin]=creerAnimal(renard, g2.A[X_lapin][Y_lapin].C);
                    
                }else  {
                    g2.A[X_lapin][Y_lapin]=creerAnimal(vide, g2.A[X_lapin][Y_lapin].C);
        
                }
                ChangeDeuxCases(g2, g2.A[X_renard][Y_renard], g2.A[X_lapin][Y_lapin]);
                EC_Renard.tab[i]=nouvCoord(X_lapin, Y_lapin);
                EC_t= voisinsLapin(g2, EC_Renard.tab[i]);
            }
            EC_t=voisinsVides(g2, EC_Renard.tab[i]);
            C_vide=randomEC(EC_t);
            X_vide=getX(C_vide);
            Y_vide=getY(C_vide);
            ChangeDeuxCases(g2, g2.A[X_renard][Y_renard], g2.A[X_vide][Y_vide]);
            
        }
        
        
        /* update the infomation */
        for (int i=0; i<20; i++) {
            for (int j=0; j<20; j++) {
                switch (g2.A[i][j].Ep) {
                    case 0:
                        fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::white );
                        break;
                    case 1:
                        fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::red );
                        break;
                    case 2:
                        fenetre.draw_filled_rectangle ( {10*j, 10*i}, 9, 9, color::blue );
                        break;
                    default:
                        break;
                }
            }
        }
        fenetre.update();
        fenetre.wait_milliseconds( 42 );
        
        

    }
    std::cout<<"nb_lapin:"<<g2.nbLapin<<std::endl;
    std::cout<<"nb_renard:"<<g2.nbRenard<<std::endl;
    std::cout<<"Press biuton"<<std::endl;
    std::cin>>;
}
