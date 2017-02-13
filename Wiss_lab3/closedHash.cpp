//Stephen Wiss
//2524249


#include <iostream>
#include "closedHash.h"

OpenHash::OpenHash(int size)//constructor
{
  hashSize = size;
  topLevel = new int [hashSize];
  flags = new bool [size];
  for (int i = 0; i < size; i ++)
  {
    topLevel[i] = -1;
    flags[i] = false;
  }
}
OpenHash::~OpenHash()//de
{
  if(topLevel)
  {
    delete[] topLevel;
    delete[] flags;
  }
}
void OpenHash::print()//prints
{
  for(int i = 0; i <hashSize ;i++)
  {
    std::cout<< i;
    std::cout<< " : ";
    std::cout<< topLevel[i] << " flag = ";
    if(flags[i] == false)
      {
        std::cout << "False";
      }
    else
      {
        std::cout << "True";
      }
    std::cout<<"\n";
  }
}
void OpenHash::setType(int typeNo)//called in main to set type of hashTable
{
  if (typeNo == 1)
  {
    quadHash = true;
  }
  else if (typeNo == 2)
  {
    quadHash = false;
  }
}
bool OpenHash::find(int searchValue)//find function for insert and delete
{
  for(int iteration = 0; iteration <= hashSize; iteration++)
  {
    int index = hash(searchValue,quadHash, iteration);
    if(searchValue == topLevel[index])
    {
      return true;
    }
    else if(flags[index] == false && topLevel[index] == -1)
    {
      return false;
    }

  }
  return false;
}
int OpenHash::hash(int insertValue, bool quadHash, int iter) //method to determine hashing method
{
  if(quadHash == false) // double hashing
  {
    int p = 5;
    int hash1 = insertValue % hashSize;
    int hash2 = iter*(p - (insertValue % 5));
    int finalHash = (hash1+hash2) % hashSize;
    return finalHash;

  }
  else // quadratic hashing
  {
    int hash1 = insertValue % hashSize;
    int quadValue = iter*iter;
    int finalHash = (hash1 + quadValue) % hashSize;
    return finalHash;
  }

}
bool OpenHash::insert(int insertValue) // check for duplicates - insert into correct bucket dependant on hash method
{
  if( find(insertValue))
  {
    std::cout<<"Value already present in Table -  cannot insert\n";
    return false;
  }
    for(int iteration = 0; iteration <= hashSize; iteration++)
    {
      int index = hash(insertValue,quadHash,iteration);
      if(topLevel[index] == -1)
      {
        topLevel[index] = insertValue;
        return true;
      }
    }
    return false;
}

bool OpenHash::deleteNode(int deleteValue) // find and remove
{
  if(!find(deleteValue))
  {
    std::cout<<"value not in table\n";
    return false;
  }
  else
  {
    for(int iteration = 0; iteration <= hashSize; iteration++)
    {
      int index = hash(deleteValue,quadHash,iteration);
      if(topLevel[index] == deleteValue)
      {
        topLevel[index] = -1;
        flags[index] = true;
        std::cout<<"Flag set to true - Value successfully removed\n";
        return true;
      }
    }
  }
}
