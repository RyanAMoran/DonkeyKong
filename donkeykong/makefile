all:	main

main: main.o DonkeyKongGame.o Mario.o Object.o Floor.o Peach.o DonkeyKong.o Barrel.o Hammer.o Oil.o Fireball.o
	g++ -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf main.o DonkeyKongGame.o Mario.o Object.o Floor.o Peach.o DonkeyKong.o Barrel.o Hammer.o Oil.o Fireball.o -o main

main.o: main.cpp
	g++ -c main.cpp

DonkeyKongGame.o:  DonkeyKongGame.cpp
	g++ -c DonkeyKongGame.cpp

Object.o: Object.cpp
	g++ -c Object.cpp

Mario.o:   Mario.cpp
	g++ -c Mario.cpp

Floor.o: Floor.cpp
	g++ -c Floor.cpp

Peach.o: Peach.cpp
	g++ -c Peach.cpp

DonkeyKong.o: DonkeyKong.cpp
	g++ -c DonkeyKong.cpp

Barrel.o: Barrel.cpp
	g++ -c Barrel.cpp

Hammer.o: Hammer.cpp
	g++ -c Hammer.cpp

Oil.o: Oil.cpp
	g++ -c Oil.cpp

Fireball.o: Fireball.cpp
	g++ -c Fireball.cpp

clean:
	rm -f *.o main
