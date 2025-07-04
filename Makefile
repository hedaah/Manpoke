all: bin/texte bin/sdl

bin/sdl : obj/main.o obj/Image.o obj/Jeu.o obj/Vect2D.o obj/Personne.o obj/Dresseur.o obj/monstre.o obj/Terrain.o
	g++ obj/main.o obj/Image.o obj/Jeu.o obj/Vect2D.o obj/Personne.o obj/Dresseur.o obj/monstre.o obj/Terrain.o -o bin/sdl -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

obj/main.o : sdl2/main.cpp src/Jeu.h src/Jeu.cpp
	g++ -g -o obj/main.o -Wall -c sdl2/main.cpp

obj/Image.o : sdl2/Image.h sdl2/Image.cpp
	g++ -g -o obj/Image.o -Wall -c sdl2/Image.cpp

obj/Jeu.o : src/Jeu.h src/Jeu.cpp src/Dresseur.h src/monstre.h src/Terrain.h 
	g++ -g -o obj/Jeu.o -Wall -c src/Jeu.cpp

obj/Vect2D.o : src/Vect2D.h src/Vect2D.cpp
	g++ -g -o obj/Vect2D.o -Wall -c src/Vect2D.cpp

obj/Personne.o : src/Personne.h src/Personne.cpp src/Vect2D.h sdl2/Image.h
	g++ -g -o obj/Personne.o -Wall -c src/Personne.cpp

obj/Dresseur.o : src/Dresseur.h src/Dresseur.cpp src/Personne.h 
	g++ -g -o obj/Dresseur.o -Wall -c src/Dresseur.cpp

obj/monstre.o : src/monstre.h src/monstre.cpp src/Vect2D.h
	g++ -g -o obj/monstre.o -Wall -c src/monstre.cpp


obj/Terrain.o : src/Terrain.h src/Terrain.cpp
	g++ -g -o obj/Terrain.o -Wall -c src/Terrain.cpp


clean:
	rm obj/*.o
