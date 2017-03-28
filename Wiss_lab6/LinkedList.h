#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"

class List
{
private:
  Node* head;
  int size;
public:
  List();
  ~List();
  bool insert(Node* n_ptr);
  bool innerInsert(Node* head, Node* a);
  bool print();
  //
  bool isEmpty();
  void reverse();
  bool innerPrint(Node* n_ptr);
  Node* remove();
  Node*  innerRemove(Node* head, int a);
  void innerReverse( Node*& head);

};
#endif
