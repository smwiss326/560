lab6: main.o Heap.o
	g++ -std=c++11 -g -Wall  main.o  Heap.o -o lab7

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Heap.o: Heap.h Heap.cpp
	g++ -std=c++11 -g -Wall -c Heap.cpp

clean:
	rm *.o lab7
	echo clean done
