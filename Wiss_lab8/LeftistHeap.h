//STEPHEN WISS
//LeftistHeap.h
#ifndef LeftistHeap_h
#define LeftistHeap_h

#include "Queue.h"
#include "Lnode.h"
#include <iostream>
#include <string>
class LeftistHeap
{
    //PRIVATE
	private:
	Lnode* m_root;//base node
	void deleteTree(Lnode subTree);//deleteTree
	void printTree(Lnode* subTree, std :: string order);//prints tree in specified order
    //PUBLIC
	public:
	LeftistHeap();//Constructor
	~LeftistHeap();//Destructor
	void insert(int value);//public call to add
	void printTree( std :: string order);//public call of printTree
	void deleteMin();
	void deleteTree(Lnode* root);
  Lnode* mergeRoots(Lnode* h1, Lnode* h2);
  void swap(Lnode* s1, Lnode* s2);
};
#endif
