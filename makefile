exe_file = zoo.out
CC = g++ -std=c++11 

$(exe_file): main.o game.o age.o zoo.o util.o animal.o
		$(CC) -o $(exe_file) main.o game.o age.o zoo.o util.o animal.o

main.o:	main.cpp
		$(CC) -c main.cpp

game.o:	game.cpp game.hpp
		$(CC) -c game.cpp

age.o:	age.cpp age.hpp
		$(CC) -c age.cpp

zoo.o:	zoo.cpp zoo.hpp
		$(CC) -c zoo.cpp

util.o:	util.cpp util.hpp
		$(CC) -c util.cpp

animal.o:	animal.cpp animal.hpp
		$(CC) -c animal.cpp

clean:
		rm -f *.out *.o $(exe_file)