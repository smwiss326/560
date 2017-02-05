#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <string>


int main(){
  std:: ifstream fin("data.txt");
  List myList = List{};
  int integerValue;
  while(!fin.eof())
  {
    fin>>integerValue;
    myList.insert(integerValue);
  }
  myList.print();
  int option;
  int valueToremoveInsert;
  do {
    std::cout<<"..........................................................\n";

    std::cout<<"Please choose one of the following commands:\n";

    std::cout<<"1- insert\n";

    std::cout<<"2- delete\n";

    std::cout<<"3- reverse\n";

    std::cout<<"4- print\n";

    std::cout<<"5- exit \n";
    std::cin >> option;
    if(option == 1)
    {
      std::cout<<"Enter a value to insert:\n";
      std::cin>>valueToremoveInsert;
      myList.insert(valueToremoveInsert);
    }
    if(option == 2)
    {
      std::cout<<"Enter a value to remove:\n";
      std::cin>>valueToremoveInsert;
      myList.remove(valueToremoveInsert);
    }
    if(option == 3 )
    {
      myList.reverse();
    }
    if(option == 4)
    {
      std::cout<<"List:";
      myList.print();
    }
  } while(option <5);

}
