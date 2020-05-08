exe_file = zoo.out
CC = g++ -std=c++11 
OBJ = main.o game.o age.o zoo.o util.o animal.o tiger.o seaLion.o blackBear.o
SRC = $(OBJ:%.o=%.cpp)
HEADER = $(OBJ:%.o=%.hpp)

$(exe_file): $(SRC) $(HEADER)
		$(CC) -o $(exe_file) $(SRC)

main.hpp:

clean:
		rm -f *.out *.o $(exe_file)