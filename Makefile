all: bin/texte 

bin/texte: obj/dresseur.o obj/vect2D.o obj/monstre.o obj/personne.o obj/terrain.o obj/maintexte.o obj/wintxt.o
	g++ -g -Wall obj/dresseur.o obj/vect2D.o obj/monstre.o obj/personne.o obj/terrain.o obj/maintexte.o obj/wintxt.o -o bin/texte

obj/dresseur.o: src/Dresseur.h src/Dresseur.cpp
	g++ -c -Wall src/Dresseur.cpp -o obj/dresseur.o

obj/vect2D.o: src/Vect2D.h src/Vect2D.cpp
	g++ -c -Wall src/Vect2D.cpp -o obj/vect2D.o

obj/monstre.o: src/monstre.h src/monstre.cpp
	g++ -c -Wall src/monstre.cpp -o obj/monstre.o

obj/personne.o: src/Personne.h src/Personne.cpp
	g++ -c -Wall src/Personne.cpp -o obj/personne.o

obj/terrain.o: src/Terrain.h src/Terrain.cpp
	g++ -c -Wall src/Terrain.cpp -o obj/terrain.o

obj/maintexte.o: src/maintexte.cpp
	g++ -c -Wall src/maintexte.cpp -o obj/maintexte.o

obj/wintxt.o: texte/WinTXT.cpp texte/WinTXT.h
	g++ -c -Wall texte/WinTXT.cpp -o obj/wintxt.o

bin/test: obj/Dresseur.o obj/Personne.o obj/Pokeball.o
	g++ -g obj/Dresseur.o obj/Personne.o obj/Pokeball.o -o bin/test
