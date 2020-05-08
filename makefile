exe_file = zoo.out
CC = g++ -std=c++11 

$(exe_file): main.o game.o age.o
		$(CC) -o $(exe_file) main.o game.o age.o

main.o:	main.cpp
		$(CC) -c main.cpp

game.o:	game.cpp game.hpp
		$(CC) -c game.cpp

age.o:	age.cpp age.hpp
		$(CC) -c age.cpp

clean:
		rm -f *.out *.o $(exe_file)