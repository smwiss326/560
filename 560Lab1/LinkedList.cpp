

#include "LinkedList.h"
#include <iostream>



List:: List(): head(nullptr)
{

}

List:: ~List()
{
  Node* current = head;
  Node* temp;
  while (current != nullptr)
  {
    temp = current;
    current = current->nextGet();
    delete temp;
  }
  head = nullptr;
}
void List:: reverse()
{
  if(head == nullptr)
  {
    std :: cout<< " List is Empty\n";
    return;
  }
  if(head->nextGet() == nullptr)
  {
    std :: cout << "Single Item list\n";
    return;
  }
  else
  {
  Node* headpivot = head;
  innerReverse( head);
  }
}
void List:: innerReverse( Node*& head)
{
  if (!head) return;
  Node* remaining = head->nextGet();
  if(!remaining )return;
  innerReverse(remaining);
  head->nextGet()->nextSet(head);
  head->nextSet(nullptr);
  head = remaining;

/*  int currValue = head->valueGet();
  if(head->nextGet())
  {
    innerReverse(pivot, head->nextGet());
  }
  pivot->valueSet(currValue);
  pivot = pivot->nextGet();*/
}


bool List:: remove(int a)
{
    return innerRemove(head, a);
}
bool List::innerRemove(Node* n_ptr, int a)
{
  if (!n_ptr) // base case
  {
    std:: cout << "Value not present in linked list\n";
    return false;
  }
  if (n_ptr->valueGet() == a)
  {
    head = n_ptr->nextGet();
    return true;
  }
  if (n_ptr->nextGet() && n_ptr->nextGet()->valueGet() == a)
  {
    Node* temp = n_ptr->nextGet();
    n_ptr->nextSet( temp->nextGet() );
    delete temp;
    return true;
  }
  return innerRemove(n_ptr->nextGet(),a);

}
bool List:: insert(int a)
{
  return innerInsert(head, a);
}

bool List:: innerInsert(Node* n_ptr, int a)
{
  if(n_ptr && head->valueGet() == a)
  {
    return false; //base case
  }
  if(!n_ptr)
  {
    Node* newN = new Node(a);
    head = newN;
    return true; // 1st position insert
  }
  else if(n_ptr->nextGet() == nullptr) //insert at end
  {
    Node* newN = new Node(a);
    newN->prevSet(n_ptr);
    n_ptr->nextSet(newN);
    return true;
  }
  else
  {
    return innerInsert(n_ptr->nextGet(), a);
  }
}

bool List::print()
{
    return innerPrint(head);
}

bool List::innerPrint(Node* n_ptr)
{
    if(!n_ptr)//empty list case
    {
        return false;
    }

    std::cout << n_ptr->valueGet() << " "; //populated list

    if(n_ptr->nextGet())
    {
        return innerPrint(n_ptr->nextGet());
    }

    return true;
}
