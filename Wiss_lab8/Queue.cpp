#include "Queue.h"


Queue ::Queue()
{
  head = nullptr;
  size = 0;
}
Queue ::~Queue()
{
  while(!isempty())
  {
    remove();
  }
}
bool Queue ::isempty()
{
  if(size == 0)
  {
    return true;
  }
  return false;
}
void Queue ::print()
{
  if(!head)
  {
    return;
  }
  else
  {
    Qnode* walker = head;
    std :: cout << walker->valueGet() << " ";
    while(walker->nextGet() != nullptr)
    {
      walker = walker->nextGet();
      std :: cout << walker->valueGet() << " ";
    }
    std :: cout << "\n";

  }
}
Qnode* Queue ::peek()
{
  return head;
}
int Queue ::sizeGet()
{
  return size;
}
void Queue ::add(Qnode* node)
{
  if(isempty())
  {
    head = node;
  }
  else
  {
    Qnode* walker = head;
    while(walker->nextGet())
    {
      walker = walker->nextGet();
    }
    walker->nextSet(node);
  }
  size++;
}
Qnode* Queue ::remove()
{
  Qnode* next = head->nextGet();
  Qnode* value = head;
  size --;
  head = next;
  return value;
}
