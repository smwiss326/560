lab5: main.o Node.o BST.o LinkedList.o
	g++ -std=c++11 -g -Wall  main.o Node.o BST.o LinkedList.o  -o lab5

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

BST.o: BST.h BST.cpp
	g++ -std=c++11 -g -Wall -c BST.cpp
	
LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

clean:
	rm *.o lab5
	echo clean done
