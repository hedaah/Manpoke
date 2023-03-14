all: bin/Dresseur

bin/test: obj/Dresseur.o obj/Personne.o obj/Pokeball.o
	g++ -g obj/Dresseur.o obj/Personne.o obj/Pokeball.o -o bin/test

obj/Dresseur.o : src/Dresseur.cpp src/Personne.h src/Personne.h
	g++ -g -o  obj/mainTest.o -Wall -c src/Dresseur.cpp