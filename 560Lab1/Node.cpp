#include "Node.h"

Node::Node(int a): data(a), nextN(nullptr), prevN(nullptr)
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
Node* Node :: nextGet()
{
  return nextN;
}
void Node :: nextSet(Node* n_ptr)
{
  nextN = n_ptr;
}
void Node :: prevSet(Node* n_ptr)
{
  prevN = n_ptr;
}
Node* Node :: prevGet() 
{
  return prevN;
}
