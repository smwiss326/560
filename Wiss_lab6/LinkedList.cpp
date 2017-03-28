

#include "LinkedList.h"
#include <iostream>



List:: List(): head(nullptr), size(0)
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
}


Node* List:: remove()
{
  if(head)
  {
    return innerRemove(head, head->valueGet());
  }
}
Node* List::innerRemove(Node* n_ptr, int a)
{
  if (!n_ptr) // base case
  {
    std:: cout << "Value not present in linked list\n";
    return 0;
  }
  if (n_ptr->valueGet() == a)
  {
    head = n_ptr->nextGet();
    return n_ptr;
  }
  if (n_ptr->nextGet() && n_ptr->nextGet()->valueGet() == a)
  {
    Node* temp = n_ptr->nextGet();
    n_ptr->nextSet( temp->nextGet() );
    delete temp;
    return n_ptr->nextGet();
  }
  return innerRemove(n_ptr->nextGet(),a);

}
bool List:: insert(Node* n_ptr)
{
  return innerInsert(head, n_ptr);
}

bool List:: innerInsert(Node* n_ptr, Node* a)
{
  if(n_ptr && head->valueGet() == a->valueGet())
  {
    return false; //base case
  }
  if(!n_ptr)
  {
    head = a;
    return true; // 1st position insert
  }
  else if(n_ptr->nextGet() == nullptr) //insert at end
  {

    a->prevSet(n_ptr);
    n_ptr->nextSet(a);
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
bool List:: isEmpty()
{
  return(size > 0);
}
