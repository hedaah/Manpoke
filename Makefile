all: bin/texte bin/sdl

bin/sdl : obj/main.o obj/sdl_aff.o 
	g++ -g obj/main.o  obj/sdl_aff.o -o bin/sdl -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

bin/texte: obj/dresseur.o obj/vect2D.o obj/monstre.o obj/personne.o obj/terrain.o obj/maintexte.o obj/wintxt.o
	g++ -g -Wall obj/dresseur.o obj/vect2D.o obj/monstre.o obj/personne.o obj/terrain.o obj/maintexte.o obj/wintxt.o -o bin/texte

obj/main.o : sdl2/main.cpp sdl2/sdl_aff.h
	g++ -g -o obj/main.o -Wall -c sdl2/main.cpp

obj/sdl_aff.o: sdl2/sdl_aff.h sdl2/sdl_aff.cpp
	g++ -g -o obj/sdl_aff.o -Wall -c sdl2/sdl_aff.cpp

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


clean:
	rm *.o
