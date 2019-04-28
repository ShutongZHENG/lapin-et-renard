# Le compilateur à utiliser
CXX = g++
# Les options du compilateur
CXXFLAGS = -Wall -std=c++11 -lMLV -g

# Les programmes principaux
# On donne le fichier cpp et la liste des fichiers .o qu'ils utilisent
main: main.cpp Coord.o EnsCoord.o Animal.o Grille.o
# Les différents composants
# on donne le fichier cpp ainsi que la liste des fichiers .hpp dont ils dépendent
Coord.o: Coord.cpp Coord.hpp
EnsCoord.o: EnsCoord.cpp EnsCoord.hpp Coord.hpp
Animal.o: Animal.cpp Animal.hpp  Coord.hpp
Grille.o: Grille.cpp Grille.hpp Animal.hpp EnsCoord.hpp
# Pour faire le ménage
clean:
	rm -f projet test *.o
