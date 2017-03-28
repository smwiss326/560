#include "Snode.h"

Snode::Snode(int value): value(value), rank(0), leftChild(nullptr), rightChild(nullptr)
{
}
void Snode ::leftSet(Snode* left)
{
  leftChild = left;
}
void Snode ::rightSet(Snode* right)
{
  rightChild = right;
}

int Snode ::valueGet()
{
  return value;
}
Snode* Snode ::rightGet()
{
  return rightChild;
}
Snode* Snode ::leftGet()
{
  return leftChild;
}
void Snode ::valueSet(int value)
{
  value = value;
}
