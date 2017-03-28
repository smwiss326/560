//STEPHEN WISS
//LeftistHeap.hpp

#include "LeftistHeap.h"
LeftistHeap::LeftistHeap()
{
	m_root = nullptr;
}
LeftistHeap::~LeftistHeap()
{
	deleteTree(m_root);
}
void LeftistHeap :: deleteTree(Lnode* root)
{
	if(root!= nullptr)
	{
		deleteTree(root->rightGet());
		deleteTree(root->leftGet());
		delete root;
	}
}
void LeftistHeap::insert(int value) // public copy
{
	if(!m_root)
  {
    m_root =  new Lnode(value);
  }
  else
  {
    Lnode* temp = new Lnode(value);
    m_root = mergeRoots(temp, m_root);
  }
}
/*
Algorithm in Lecture Notes
https://people.eecs.ku.edu/~mhajiarb/EECS560-L6-ConcatenatedQueues-S17.pdf
*/
Lnode* LeftistHeap ::mergeRoots( Lnode* h1, Lnode* h2)
{
	if(h1 == nullptr)
	 {
		 return h2;
	 }
	else if(h2 == nullptr)
	{
		return h1;
	}
	else if (h1->valueGet() > h2->valueGet())
	{
	  Lnode* temp = h1;
	  h1=h2;
	  h2 = temp;
	}

 h1->rightSet( mergeRoots(h1->rightGet(), h2));
// h1->rankify();
 if(h1->leftGet() == nullptr)
 {
   h1->leftSet( h1->rightGet());
   h1->deleteRight();
 }
 if(h1->leftGet() != nullptr && h1->rightGet() != nullptr)
 {
   if(h1->leftGet()->rankGet() < h1->rightGet()->rankGet())
   {
     Lnode* temp = h1->leftGet(); //swaps the left and right child
     h1->leftSet(h1->rightGet());
     h1->rightSet(temp);
   }
	 h1->rankify();
 }
 return h1;
}

void LeftistHeap ::swap(Lnode*  s1, Lnode* s2)
{
  Lnode* temp = s1;
  s1 = s2;
  s2 = temp;
}

void LeftistHeap::printTree(Lnode* subTree, std :: string order)
{
		if(order == "level")
		{
			Queue* printQueue = new Queue();
			Qnode* start = new Qnode(subTree);
			printQueue->add(start);
			while(!printQueue->isempty())
			{
			Qnode* temp = printQueue->peek();
			std :: cout << temp->valueGet() << " ";
				if(temp->leftGet_l())
				{
					Qnode* tempLeft = new Qnode(temp->leftGet_l());
					printQueue->add(tempLeft);
				}
				if(temp->rightGet_l())
				{
					Qnode* tempRight = new Qnode(temp->rightGet_l());
					printQueue->add(tempRight);
				}
				printQueue->remove();
			}
			std::cout<<"\n";
		}
		if(order =="pre")
		{
			if(subTree == nullptr)
			{
				return;
			}
      std::cout << subTree-> valueGet() <<"\n";
			printTree(subTree->leftGet(), order);
			printTree(subTree->rightGet(), order);
		}
		else if(order == "in")
		{
			if(subTree == nullptr)
			{
				 return;
			}
			printTree(subTree-> leftGet(), order);
      std::cout << subTree-> valueGet()<<"\n";
			printTree(subTree-> rightGet(), order);
		}
		else if(order =="post")
		{
			if(subTree == nullptr)
			{
				return;
			}
			printTree(subTree-> leftGet(), order);
			printTree(subTree-> rightGet(), order);
      std::cout << subTree-> valueGet() <<"\n";
		}
}
void LeftistHeap::printTree(std ::string order)
{
	if(m_root == nullptr)
	{
		std::cout << "Tree is empty\n";
		return;
	}
	printTree(m_root, order);
}
void LeftistHeap :: deleteMin()
{
	if(m_root)
  {
		Lnode* min = m_root;
    m_root = mergeRoots(m_root ->leftGet(), m_root ->rightGet());
    delete min;
  }
}
