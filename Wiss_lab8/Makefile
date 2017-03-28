lab8: main.o Lnode.o Snode.o Qnode.o LeftistHeap.o SkewHeap.o Queue.o
	g++ -std=c++11 -g -Wall  main.o Lnode.o LeftistHeap.o SkewHeap.o Snode.o Qnode.o Queue.cpp -o lab8

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

Lnode.o: Lnode.h Lnode.cpp
	g++ -std=c++11 -g -Wall -c Lnode.cpp

LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -std=c++11 -g -Wall -c LeftistHeap.cpp

SkewHeap.o: SkewHeap.h SkewHeap.cpp
		g++ -std=c++11 -g -Wall -c SkewHeap.cpp

Snode.o: Snode.h Snode.cpp
			g++ -std=c++11 -g -Wall -c Snode.cpp

Queue.o: Queue.h Queue.cpp
			g++ -std=c++11 -g -Wall -c Queue.cpp

Qnode.o: Qnode.h Qnode.cpp
			g++ -std=c++11 -g -Wall -c Qnode.cpp

clean:
	rm *.o lab8
	echo clean done
