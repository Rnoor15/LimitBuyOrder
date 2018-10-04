INCLUDE_DIRS = -I.
WARNINGS = -Wall -Werror
OBJECTS = main.o OrderQueue.o
CXX = g++
CPPFLAGS = -std=c++17 $(INCLUDE_DIRS) $(WARNINGS)

main : $(OBJECTS) 
	g++ -o main $(OBJECTS)

main.o : main.cpp

OrderQueue.o : OrderQueue.cpp OrderQueue.h

clean: 
	rm $(OBJECTS) main
