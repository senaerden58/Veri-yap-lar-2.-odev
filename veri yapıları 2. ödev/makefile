all: compile bagla run

compile:
	g++ -I ./include/ -o ./lib/avl.o -c ./src/avl.cpp
	g++ -I ./include/ -o ./lib/yigit.o -c ./src/yigit.cpp
	g++ -I ./include/ -o ./lib/linkedList.o -c ./src/linkedList.cpp
	
bagla:
	g++ -I ./include/ -o ./bin/Test ./lib/avl.o ./lib/yigit.o ./lib/linkedList.o ./src/Test.cpp

run:
	./bin/Test
