CC=g++
CFLAGS=-c -w -g -std=c++14 -Wall -pedantic -Wno-long-long -O0 -ggdb
CLIBS=-std=c++14 -lncurses



all: doc matveale 

matveale: game_start.o ghoust_1.o ghoust_2.o ghoust_3.o main.o main_menu.o player.o 
	$(CC) game_start.o ghoust_1.o ghoust_2.o ghoust_3.o main.o main_menu.o player.o -o "matveale" $(CLIBS)

game_start.o: src/game_start.hpp src/game_start.cpp src/player.hpp src/ghoust_1.hpp src/ghoust_2.hpp src/ghoust_3.hpp src/father.hpp
	$(CC) $(CFLAGS) src/game_start.cpp -o $@

ghoust_1.o: src/ghoust_1.cpp src/ghoust_1.hpp src/father.hpp
	$(CC) $(CFLAGS) src/ghoust_1.cpp -o $@

ghoust_2.o: src/ghoust_2.cpp src/ghoust_2.hpp src/father.hpp
	$(CC) $(CFLAGS) src/ghoust_2.cpp -o $@

ghoust_3.o: src/ghoust_3.cpp src/ghoust_3.hpp src/father.hpp
	$(CC) $(CFLAGS) src/ghoust_3.cpp -o $@

main.o: src/main.cpp src/main_menu.hpp
	$(CC) $(CFLAGS) src/main.cpp -o $@

player.o: src/player.cpp src/player.hpp src/father.hpp
	$(CC) $(CFLAGS) src/player.cpp -o $@

main_menu.o: src/main_menu.cpp src/main_menu.hpp src/game_start.hpp
	$(CC) $(CFLAGS) src/main_menu.cpp -o $@

doc:
	doxygen doxygen.conf
	mv doc/html/* doc/
	rm -r doc/html

documentation: doc
	firefox doc/index.html

clean:
	rm -f *.o
	rm -f matveale
	rm -rf doc
	rm -rf *.dSYM

compile: doc matveale

run:  matveale
	./matveale
