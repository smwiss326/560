lab3: main.o ClosedHash.o
	g++ -std=c++11 -g -Wall main.o ClosedHash.o -o lab3

main.o: main.cpp closedHash.h
	g++ -std=c++11 -g -Wall -c main.cpp

ClosedHash.o: closedHash.cpp
	g++ -g -Wall -std=c++11 -c closedHash.cpp

clean:
	rm *.o lab3
	echo clean done
