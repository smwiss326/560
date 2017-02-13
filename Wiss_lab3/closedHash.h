#ifndef OPENHASH_H
#define OPENHASH_H


class OpenHash
{
public:
  OpenHash(int size);
  ~OpenHash();
  bool insert(int insertValue);
  void print();
  int hash(int a, bool quadHash, int iter);
  void setType(int typeNo);
  bool find(int searchValue);
  bool deleteNode(int deleteValue);
private:
  int hashSize;
  bool quadHash;
  int *topLevel;
  bool* flags;

};
#endif
