lab2: main.o Node.o LinkedList.o OpenHash.o
	g++ -std=c++11 -g -Wall main.o Node.o LinkedList.o OpenHash.o -o lab2

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

DoubleLinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c DoubleLinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

OpenHash.o: OpenHash.h OpenHash.cpp
	g++ -g -Wall -std=c++11 -c OpenHash.cpp
clean:
	rm *.o lab2
	echo clean done
