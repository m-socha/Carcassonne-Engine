CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

OBJECTS1 = src/main.o src/parsing/parse_tiles.o src/tiles/four_side_item.o src/tiles/road.o src/tiles/city.o src/tiles/farm.o src/tiles/tile.o

EXEC1 = carcassonne_engine

OBJECTS = ${OBJECTS1}
DEPENDS = ${OBJECTS:.o=.d}
EXECS = ${EXEC1}

.PHONY : all clean

all : ${EXECS}

#############################################################

${EXEC1} : ${OBJECTS1}
	${CXX} ${CXXFLAGS} $^ -o $@

#############################################################

${OBJECTS} : ${MAKEFILE_NAME}

-include ${DEPENDS}

clean :
	rm -f *.d *.o ${EXECS} ImplType
