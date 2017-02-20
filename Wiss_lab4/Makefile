lab3: main.o OpenHash.o ClosedHash.o LinkedList.o Node.o
	g++ -std=c++11 -g -Wall main.o OpenHash.o ClosedHash.o LinkedList.o Node.o -o lab4

main.o: main.cpp closedHash.h
	g++ -std=c++11 -g -Wall -c main.cpp

OpenHash.o: OpenHash.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

ClosedHash.o: closedHash.cpp
	g++ -g -Wall -std=c++11 -c closedHash.cpp
LinkedList.o: LinkedList.cpp
	g++ -g -Wall -std=c++11 -c LinkedList.cpp
Node.o: Node.cpp
	g++ -g -Wall -std=c++11 -c Node.cpp

clean:
	rm *.o lab3
	echo clean done
