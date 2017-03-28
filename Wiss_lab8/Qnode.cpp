#include "Qnode.h"
// Lnode::Lnode(int value): value(value), rank(0), leftChild(nullptr), rightChild(nullptr)
// {
// }
Qnode ::Qnode()
{
  value = -1;
  next = nullptr;
}
Qnode ::Qnode(Lnode* leftistNode): next(nullptr),value(leftistNode->valueGet()), leftChild_l(leftistNode->leftGet()), rightChild_l(leftistNode->rightGet())
{
}
Qnode ::Qnode(Snode* SkewNode): next(nullptr),value(SkewNode->valueGet()), leftChild_s(SkewNode->leftGet()), rightChild_s(SkewNode->rightGet())
{
}
Lnode* Qnode ::leftGet_l()
{
return leftChild_l;
}
Lnode* Qnode ::rightGet_l()
{
  return rightChild_l;
}
Snode* Qnode ::leftGet_s()
{
  return leftChild_s;
}
Snode* Qnode ::rightGet_s()
{
  return rightChild_s;
}
void Qnode ::leftSet_l(Lnode* leftistNode)
{
  leftChild_l = leftistNode;
}
void Qnode ::rightSet_l(Lnode* leftistNode)
{
  leftChild_l = leftistNode;
}
void Qnode ::leftSet_s(Snode* SkewNode)
{
  leftChild_s = SkewNode;
}
void Qnode ::rightSet_s(Snode* SkewNode)
{
  leftChild_s = SkewNode;
}
int Qnode ::valueGet()
{
  return value;
}
void Qnode ::valueSet(int value)
{
  value = value;
}
Qnode* Qnode ::nextGet()
{
  return next;
}
void Qnode ::nextSet(Qnode* qnode)
{
  next = qnode;
}
