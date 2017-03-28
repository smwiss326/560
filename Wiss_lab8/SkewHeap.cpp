//STEPHEN WISS
//SkewHeap.hpp

#include "SkewHeap.h"
SkewHeap::SkewHeap()
{
	m_root = nullptr;
}
SkewHeap::~SkewHeap()
{
	deleteTree(m_root);
}
void SkewHeap :: deleteTree(Snode* root)
{
	if(root!= nullptr)
	{
		deleteTree(root->rightGet());
		deleteTree(root->leftGet());
		delete root;
	}
}
void SkewHeap::insert(int value) // public copy
{
	if(!m_root)
  {
    m_root =  new Snode(value);
  }
  else
  {
    Snode* temp = new Snode(value);
    m_root = mergeRoots(temp, m_root);
  }
}
/*
Algorithm in Lecture Notes
https://people.eecs.ku.edu/~mhajiarb/EECS560-L6-ConcatenatedQueues-S17.pdf
*/
Snode* SkewHeap ::mergeRoots( Snode* h1, Snode* h2)
{
  {
    if(h1 == nullptr) {return h2;}
    else if(h2 == nullptr) {return h1;}
    else
    {
      if(h1->valueGet() > h2->valueGet())
      {
        Snode* temp = h1;
        h1 = h2;
        h2 = temp;
      }
      Snode* temp = h1->rightGet();
      h1->rightSet(h1->leftGet());
      h1->leftSet( mergeRoots(temp,h2));
    }
    return h1;
  }
}
void SkewHeap ::swap(Snode*  s1, Snode* s2)
{
  Snode* temp = s1;
  s1 = s2;
  s2 = temp;
}
void SkewHeap::printTree(Snode* subTree, std :: string order)
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
			if(temp->leftGet_s())
			{
				// std::cout<<"herel";
				Qnode* tempLeft = new Qnode(temp->leftGet_s());
				printQueue->add(tempLeft);
			}
			if(temp->rightGet_s())
			{
				// std::cout<<"herer";
				Qnode* tempRight = new Qnode(temp->rightGet_s());
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
void SkewHeap::printTree(std ::string order)
{
	if(m_root == nullptr)
	{
		std::cout << "Tree is empty\n";
		return;
	}
	printTree(m_root, order);
}
void SkewHeap :: deleteMin()
{
	if(m_root)
  {
		Snode* min = m_root;
    m_root = mergeRoots(m_root ->leftGet(), m_root ->rightGet());
    delete min;
  }
}
