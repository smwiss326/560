
#ifndef LNODE_H
#define LNODE_H
/*
POINTER IMPLEMENTATION
*/
class Lnode
{
private:
  int rank;
  int value;
  Lnode* leftChild;
  Lnode* rightChild;
public:
  Lnode(int value);
  int rankGet();
  void valueSet(int value);
  void rankSet(int rank);
  int valueGet();
  void leftSet(Lnode* left);
  void rightSet(Lnode* right);
  Lnode* leftGet();
  Lnode* rightGet();
  void rankify();
  void deleteRight();
};
#endif
