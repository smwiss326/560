#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "openHash.h"

OpenHash::OpenHash(int size)
{
  hashSize = size;
  topLevel = new List [hashSize];
}
OpenHash::~OpenHash()
{
  if(topLevel)
  {
    delete[] topLevel;
  }
}
void OpenHash::print()
{
  for(int i = 0; i <hashSize ;i++)
  {
    std::cout<< i;
    std::cout<< ":";
    topLevel[i].print();
    std::cout<<"\n";
  }
}
bool OpenHash::find(int searchValue)
{
  int bucket = hash(searchValue);
  return(topLevel[bucket].find(searchValue));
}
int OpenHash::hash(int insertValue)
{
  return (insertValue% hashSize);
}
bool OpenHash::insert(int insertValue)
{
  int bucket = hash(insertValue);
  if(!find(insertValue))
  {
    return(topLevel[bucket].insert(insertValue));
  }
}

bool OpenHash::deleteNode(int deleteValue)
{
  int bucket = hash(deleteValue);
  return(topLevel[bucket].remove(deleteValue));
}
