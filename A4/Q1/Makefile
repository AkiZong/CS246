CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = a4q1
OBJECTS = Expression.o Integers.o Unary.o Binary.o main.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
