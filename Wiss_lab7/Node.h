#ifndef _NODE
#define _NODE

class Node
{
public:
  Node(int a);
  int valueGet();
  void valueSet(int a);
  Node* rightGet();
  void  rightSet(Node* n_ptr);
  Node* leftGet();
  void  leftSet(Node* n_ptr);
  void  nextSet(Node* n_ptr);
  void  prevSet(Node* n_ptr);
  Node*  nextGet();
  Node*  prevGet();
private:
  int data;
  Node* leftN;
  Node* rightN;
  Node* nextN;
  Node* prevN;
};
#endif
