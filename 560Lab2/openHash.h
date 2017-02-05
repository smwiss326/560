#ifndef OPENHASH_H
#define OPENHASH_H
#include "LinkedList.h"


class OpenHash
{
public:
  OpenHash(int size);
  ~OpenHash();
  void insert(insertValue);
  void print();
  bool find(searchValue);
  bool deleteNode();
  
}
