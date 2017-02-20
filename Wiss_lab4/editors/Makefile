lab3: main.o OpenHash.o ClosedHash.o LinkedList.o Node.o
	g++ -std=c++11 -g -Wall main.o OpenHash.o ClosedHash.o LinkedList.o Node.o -o lab4

main.o: main.cpp closedHash.h
	g++ -std=c++11 -g -Wall -c main.cpp

OpenHash.o: openHash.cpp
	g++ -std=c++11 -g -Wall -c openHash.cpp

ClosedHash.o: closedHash.cpp
	g++ -g -Wall -std=c++11 -c closedHash.cpp
LinkedList.o: LinkedList.cpp
	g++ -g -Wall -std=c++11 -c LinkedList.cpp
Node.o: Node.cpp
	g++ -g -Wall -std=c++11 -c Node.cpp
tar:
	mkdir editors
	cp dot_vimrc Makefile simple.* editors/
	tar cvzf eecs678-editors-lab.tar.gz editors
	rm -rf editors
clean:
	rm *.o lab4
	echo clean done
