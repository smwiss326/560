#ifndef OPENHASH_H
#define OPENHASH_H
#include "LinkedList.h"


class OpenHash
{
public:
  OpenHash(int size);
  ~OpenHash();
  bool insert(int insertValue);
  void print();
  int hash(int a);

  bool find(int searchValue);
  bool deleteNode(int deleteValue);
private:
  int hashSize;
  List *topLevel;

};
#endif
