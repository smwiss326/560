#include "Lnode.h"

Lnode::Lnode(int value): value(value), rank(0), leftChild(nullptr), rightChild(nullptr)
{
}
void Lnode ::leftSet(Lnode* left)
{
  leftChild = left;
}
void Lnode ::rightSet(Lnode* right)
{
  rightChild = right;
}
int Lnode ::rankGet()
{
  return rank;
}
void Lnode ::rankSet(int rank)
{
  rank = rank;
}
void Lnode ::deleteRight()
{
  rightChild = nullptr;
}
void Lnode ::rankify()
{
  int temprank;
  if(!leftChild)
  {
    rank = 1;
  }
  else if (!rightChild)
  {
    rank = 1;
  }
  else
  {
    if (leftChild ->rankGet() > rightChild->rankGet())
    {
      temprank = rightChild->rankGet() + 1;
      rank = temprank;
    }
    else
    {
      temprank = leftChild ->rankGet() + 1;
      rank = temprank;
    }
  }
}
int Lnode ::valueGet()
{
  return value;
}
Lnode* Lnode ::rightGet()
{
  return rightChild;
}
Lnode* Lnode ::leftGet()
{
  return leftChild;
}
void Lnode ::valueSet(int value)
{
  value = value;
}
