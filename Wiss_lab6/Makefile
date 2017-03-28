lab6: main.o Node.o BST.o Heap.o LinkedList.o
	g++ -std=c++11 -g -Wall  main.o Node.o BST.o Heap.o LinkedList.o  -o lab6

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

BST.o: BST.h BST.cpp
	g++ -std=c++11 -g -Wall -c BST.cpp

Heap.o: Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Heap.cpp

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

clean:
	rm *.o lab6
	echo clean done
