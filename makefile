run:	main.o BinaryTree.o
	g++ -o run main.o BinaryTree.o

BinaryTree.o:BinaryTree.cpp BinaryTree.h
	g++ BinaryTree.cpp -c -g -Wall -std=c++11

main.o:	main.cpp BinaryTree.h
	g++ main.cpp -c -g -std=c++11 -Wall

clean:
	rm -f run main.o BinaryTree.o

rebuild:
	make clean
	make
