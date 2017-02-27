//STEPHEN WISS
//BST.h
#ifndef BST_h
#define BST_h

#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
class BST
{
    //PRIVATE
	private:
	Node* m_root;//base node
	bool add(int value, Node* subtree);//adds element to specified subtree
	void deleteTree(Node subTree);//deleteTree
	int search(int value, Node* subTree);//returns the value from tree
	void printTree(Node* subTree, std :: string order);//prints tree in specified order
	Node* getMin(Node* n);
	Node* getMax(Node* n);
	Node* clearIndex(Node* subTree, int value);//clears value from tree and links nodes as needed
    //PUBLIC
	public:
	BST();//Constructor
	~BST();//Destructor
	bool add(int value);//public call to add
	int search(int value);//public call to search
	void printTree( std :: string order);//public call of printTree
 	Node* getMin();
	Node* getMax();
	void deleteMin();
	void deleteMax();
  void clearNode(int value);//calls clearindex
	void deleteTree(Node* root);

};
#endif
