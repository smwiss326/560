#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class List
{
private:
  Node* head;

public:
  List();
  ~List();
  bool insert(int a);
  bool innerInsert(Node* head, int a);
  bool print();
  //
  void reverse();
  bool innerPrint(Node* n_ptr);
  bool remove(int a);
  bool  innerRemove(Node* head, int a);
  void innerReverse( Node*& head);

};
#endif
