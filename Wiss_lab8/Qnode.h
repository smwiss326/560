#include "Lnode.h"
#include "Snode.h"

#ifndef QNODE_H
#define QNODE_H

class Qnode
{
private:

  Lnode* leftChild_l;
  Snode* rightChild_s;
  Lnode* rightChild_l;
  Snode* leftChild_s;
  Qnode* next;
  int value;

public:

  Qnode(Lnode* leftistNode);
  Qnode(Snode* SkewNode);
  Qnode();
  int valueGet();
  Qnode* nextGet();
  void valueSet(int value);
  void leftSet_l(Lnode* leftistNode);
  void leftSet_s(Snode* SkewNode);
  void rightSet_l(Lnode* leftistNode);


  Snode* leftGet_s();
  Snode* rightGet_s();

  Lnode* leftGet_l();
  Lnode* rightGet_l();


  void rightSet_s(Snode* SkewNode);
  void nextSet(Qnode* qnode);
};
#endif
