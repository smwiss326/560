#ifndef SNODE_H
#define SNODE_H
/*
POINTER IMPLEMENTATION
*/
class Snode
{
private:
  int rank;
  int value;
  Snode* leftChild;
  Snode* rightChild;
public:
  Snode(int value);
  int rankGet();
  int keyGet();
  void leftSet(Snode* left);
  void rightSet(Snode* right);
  Snode* leftGet();
  Snode* rightGet();
  int valueGet();
  void valueSet(int value);
  void rankSet(int value);
};
#endif
