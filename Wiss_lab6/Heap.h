//STEPHEN WISS
//Heap.h
#ifndef HEAP_h
#define HEAP_h
#include <math.h>
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
class Heap
{
    //PRIVATE
	private:
	int* heapArray;
	int entries;
    //PUBLIC
	public:

	Heap(int size);
	Heap();
	int getParent(int index);
	int childOne(int index);
	void deleteMin();
	void deleteMax();
	int childThree(int index);
	void insert(int value);
	void levelOrder();
	void removeValue(int value);
	void swap(int a, int b);
	void print();
	void heapify();
	void bottomUp(int currentLow);
	void printHeap();
};
#endif
