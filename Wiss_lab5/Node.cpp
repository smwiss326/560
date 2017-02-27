#include "Node.h"

Node::Node(int a): data(a), leftN(nullptr), rightN(nullptr)
{
}
int Node :: valueGet()
{
  return data;
}
void Node :: valueSet(int a)
{
  data = a;
}
Node* Node :: rightGet()
{
  return rightN;
}
void Node :: rightSet(Node* n_ptr)
{
  rightN = n_ptr;
}
Node* Node :: leftGet()
{
  return leftN;
}
void Node :: leftSet(Node* n_ptr)
{
  leftN = n_ptr;
}
void Node :: nextSet(Node* n_ptr)
{
  nextN = n_ptr;
}
void Node :: prevSet(Node* n_ptr)
{
  prevN = n_ptr;
}
Node* Node :: nextGet()
{
  return nextN;
}
Node* Node :: prevGet()
{
  return prevN;
}
