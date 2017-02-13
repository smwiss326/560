
#include <iostream>
#include <fstream>
#include <string>
#include "closedHash.h"

int main(){

  std:: ifstream fin("data.txt");
  int size;
  fin >> size;
  OpenHash myHash = OpenHash(size);
  int integerValue;
  int quadHash;
  std::cout<<"..........................................................\n";

  std::cout<<"Please choose one of the following commands:\n";

  std::cout<<"1- Quadratic\n";

  std::cout<<"2- Double hashing\n";

  std::cout<<"3- Exit\n";
  std:: cin >> quadHash;
  if (quadHash == 3)
  {
    return(0);
  }
  myHash.setType(quadHash);
  while(!fin.eof())
  {
    fin>>integerValue;
    myHash.insert(integerValue);
  }
  myHash.print();

  int option;
  int valueToremoveInsert;
  do {
    std::cout<<"..........................................................\n";

    std::cout<<"Please choose one of the following commands:\n";

    std::cout<<"1- insert\n";

    std::cout<<"2- delete\n";

    std::cout<<"3- print\n";

    std::cout<<"4- exit\n";

    std::cin >> option;
    if(option == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>valueToremoveInsert;
      myHash.insert(valueToremoveInsert);
    }
    if(option == 2)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>valueToremoveInsert;
      myHash.deleteNode(valueToremoveInsert);
    }
    if(option == 3)
    {
      std::cout<<"Hash Table:\n";
      myHash.print();
    }
  } while(option <4);

}
