//STEPHEN WISS
//SkewHeap.h
#ifndef SkewHeap_h
#define SkewHeap_h
#include "Queue.h"
#include "Snode.h"
#include <iostream>
#include <string>
class SkewHeap
{
    //PRIVATE
	private:
	Snode* m_root;//base node
	void deleteTree(Snode subTree);//deleteTree
	void printTree(Snode* subTree, std :: string order);//prints tree in specified order
    //PUBLIC
	public:
	SkewHeap();//Constructor
	~SkewHeap();//Destructor
	void insert(int value);//public call to add
	void printTree( std :: string order);//public call of printTree
	void deleteMin();
	void deleteTree(Snode* root);
  Snode* mergeRoots(Snode* h1, Snode* h2);
  void swap(Snode* s1, Snode* s2);
};
#endif
