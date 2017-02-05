#ifndef _NODE
#define _NODE


class Node
{
public:
  Node(int a);
  int valueGet();
  void valueSet(int a);
  Node* nextGet();
  void  nextSet(Node* n_ptr);
  Node* prevGet();
  void prevSet(Node* n_ptr);
private:
  int data;
  Node* nextN;
  Node* prevN;
};
#endif
