CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}

OBJECTS = src/parsing/parse_tiles.o src/tiles/four_side_item.o src/tiles/road.o src/tiles/city.o src/tiles/farm.o src/tiles/tile.o src/tiles/placed_tile.o src/players/player.o src/players/meeple.o src/tiles/tile_item.o src/tiles/cloister.o src/game/game.o src/game/tile_grid.o

EXEC1 = engine
EXEC2 = tests

DEPENDS = ${OBJECTS:.o=.d}
EXECS = ${EXEC1} ${EXEC2}

.PHONY : all clean

engine : ${EXEC1}

tests : ${EXEC2}

#############################################################

${EXEC1} : ${OBJECTS} src/main.o
	${CXX} ${CXXFLAGS} $^ -o $@

${EXEC2} : ${OBJECTS} src/parsing/__tests__/parse_tiles_test.o src/game/__tests__/tile_placement_test.o
	${CXX} ${CXXFLAGS} $^ -o $@

#############################################################

${OBJECTS} : ${MAKEFILE_NAME}

-include ${DEPENDS}

clean :
	rm -f *.d *.o ${EXECS}
