# Please complete this Makefile as needed. You can study the Makefile in project 3 to get an idea of how to write Makefile.
# For each target, you need to list the prerequisites, then write the command to make that target
CC = g++
CFLAGS = --std=c++11 -Wall -c
LFLAGS = --std=c++11
SRC = src
OBJ = obj
DOC = doc
TEST = test

all: osm
	@echo "osm compiled"

osm: $(OBJ)/main.o $(OBJ)/osm.o
		$(CC) $(LFLAGS) $(OBJ)/main.o $(OBJ)/osm.o -o ./obj/osm

# Add target $(OBJ)/main.o here
$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/osm.hpp
		$(CC) $(CFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o
# Add target $(OBJ)/osm.o here
$(OBJ)/osm.o: $(SRC)/osm.cpp $(SRC)/osm.hpp
		$(CC) $(CFLAGS) $(SRC)/osm.cpp -o $(OBJ)/osm.o

.PHONY: clean doc test

# Add target doc here
doc:
		doxygen doxyfile

test:
	./test.sh

clean:
		rm -rf $(OBJ)/* osm $(DOC)/*
# Add clean here. You have to remove the project executable and any object code generated during compilation.

