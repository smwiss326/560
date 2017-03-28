
#include "Qnode.h"
#include <iostream>
#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
  Qnode* head;
  int size;
public:
  Queue();
  ~Queue();
  bool isempty();
  void add(Qnode* qnode);
  Qnode* remove();
  int sizeGet();
  Qnode* peek();
  void print();
};
#endif
