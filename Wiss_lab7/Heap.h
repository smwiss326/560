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
	int max2gen(int index);
	void bubbleUpMin(int index);
	void bubbleUpMax(int index);
	void bubbleUp(int index);
	void getEntries();
	int getPep_pep(int index);
	int min2gen(int index);
	bool isPep_pep(int index, int potentialPep);
	void trickleDown(int index);
	void trickleDownMin(int index);
	void trickleDownMax(int index);
	int getParent(int index);
	int childOne(int index);
	void deleteMin();
	void deleteMax();
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
