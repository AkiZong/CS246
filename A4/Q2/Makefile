CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = flood
OBJECTS = cell.o controller.o game.o main.o textdisplay.o view.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
