
//STEPHEN WISS
//BST.hpp

#include "BST.h"
BST::BST()
{
	m_root = nullptr;
	nodes = 0;
}
BST::~BST()
{
	deleteTree(m_root);
}
void BST :: deleteTree(Node* root)
{
	if(root!= nullptr)
	{
		deleteTree(root->rightGet());
		deleteTree(root->leftGet());
		delete root;
	}
}
bool BST::add(int value, Node* subtree) // private copy
{
	if(m_root == nullptr)
	{
		Node* newN = new Node(value);
    m_root = newN;
		nodes++;
    return true;
	}
	int tempValue = subtree->valueGet();
	Node* tempLeft = subtree->leftGet();
	Node* tempRight = subtree->rightGet();

  if(value < tempValue)
	{
		if(tempLeft == nullptr )
		{
			tempLeft = new Node(value);
			subtree->leftSet(tempLeft);

			return true;
		}

		add(value, tempLeft);


	}
        else if(value >= tempValue)
	{

		if(tempRight == nullptr)

		{
			tempRight = new Node(value);
			subtree->rightSet(tempRight);
			return true;
		}

		add(value, tempRight);

	}
	else
	{
		return false;
	}

}
bool BST::add(int value) // public copy
{
	return add(value, m_root);
}
int BST::search(int value, Node* subTree)
{

       if(subTree == nullptr)
       {
           std::cout<<"value not present in String"<<std::endl;
           int a;
           return a;
       }
       else if (value == subTree->valueGet())
       {
           //cout<<"got here"<<endl;
           return subTree->valueGet();
       }
       else if (value < subTree->valueGet())
       {

           return search(value,subTree->leftGet());
       }
       else
       {

           return search(value,subTree->rightGet());
       }
}
int BST::search(int value)
{
     return search(value, m_root);
}
void BST::printTree(Node* subTree, std :: string order)
{
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
void BST::printTree(std :: string order)
{
	if( order == "level")
	{
		List* qll = new List{};
		Node* tempHead = m_root;
		qll->insert(tempHead);
		while(!qll->isEmpty())
		{
			Node* temp = qll->remove();
			std::cout<< temp->valueGet()<<"\n";
			Node* rSubTree = temp->rightGet();
			Node* lSubTree = temp->leftGet();
			if(rSubTree)
			{
				qll->insert(rSubTree);
			}
			if(lSubTree)
			{
				qll->insert(lSubTree);
			}
		}
		return;
	}
	if(m_root == nullptr)
	{
		std::cout << "Tree is empty\n";
		return;
	}
	printTree(m_root, order);
	std::cout << "\n";
}

Node* BST :: getMin()
{
	return getMin(m_root);
}
Node* BST :: getMax()
{
	return getMax(m_root);
}
Node* BST :: getMax(Node* root)
{
	Node* temp = nullptr;
	if (root == nullptr)
	{
		return temp;
	}
	if (root->rightGet() == nullptr)
	{
		temp = root;
		return temp;
	}
	else
	{
		temp = root->rightGet();
		return getMax(temp);
	}
}
Node* BST :: getMin(Node* root)
{
	Node* temp = nullptr;
	if (root == nullptr)
	{
		return temp;
	}
	if (root->leftGet() == nullptr)
	{
		temp = root;
		return temp;
	}
	else
	{
		temp = root->leftGet();
		return getMin(temp);
	}
}

void BST ::clearNode(int value)
{
	if(m_root)
     clearIndex(m_root,value);
}
Node* BST ::clearIndex(Node* root, int value)
{
	    if(value == root->valueGet())
	    {
	        Node* temp = nullptr;
	        if(root->leftGet() == nullptr)
	        {
	            if(root->valueGet() == m_root->valueGet() && root->valueGet() == value)
	            {
	                temp = root->rightGet();
	                m_root = temp;
	                return temp;

	            }

	            temp = root->rightGet();
	            root = temp;
	            return temp;
	        }
	        else if(root->rightGet() == nullptr)
	        {
	            if(root->valueGet() == m_root->valueGet() && root->valueGet() == value)
	            {
	                temp = root->leftGet();
	                m_root = temp;
	                return temp;

	            }
	            temp = root->leftGet();
	            root = temp;
	            return temp;
	        }
	        else
	        {
	            int replacement = getMin(root->rightGet())->valueGet();
	            root->rightSet(clearIndex(root->rightGet(), replacement));
	            root->valueSet(replacement);
	        }
	    }
	    else if(value < root->valueGet() && root->leftGet())
	    {
	        root->leftSet(clearIndex(root->leftGet(),value));
	    }
			else if(value > root->valueGet() && root->rightGet())
	    {
	        root->rightSet(clearIndex(root->rightGet(),value));

	    }
	    return root;
}
void BST :: deleteMin()
{
	if(m_root)
		clearIndex(m_root,this->getMin()->valueGet());
}
void BST :: deleteMax()
{
	if(m_root)
		clearIndex(m_root,this->getMax()->valueGet());
}
