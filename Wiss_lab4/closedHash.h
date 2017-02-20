#ifndef ClosedHASH_H
#define ClosedHASH_H


class ClosedHash
{
public:
  ClosedHash(int size);
  ~ClosedHash();
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
