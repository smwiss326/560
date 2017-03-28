
#include "Node.h"
#include "BST.h"
#include "Heap.h"
#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include <sys/time.h>
void BSTprogram(){
    std:: ifstream fin("data.txt");
    BST myTree = BST();
    int integerValue;
    while(!fin.eof())
    {
      fin>>integerValue;
      myTree.add(integerValue);
    }
    int option;
    int valueToremoveInsert;
    do {
      std::cout<<"..........................................................\n";

      std::cout<<"Please choose one of the following commands:\n";

      std::cout<<"1- Insert\n";

      std::cout<<"2- Delete\n";

      std::cout<<"3- Delete Min\n";

      std::cout<<"4- Delete Max\n";

      std::cout<<"5- Pre-order \n";
      std::cout<<"6- In-order \n";
      std::cout<<"7- Level-order \n";
      std::cout<<"8- Exit\n";


      std::cin >> option;
      if(option == 1)
      {
        std::cout<<"Enter a value to insert:\n";
        std::cin>> valueToremoveInsert;
        myTree.add(valueToremoveInsert);
      }
      if(option == 2)
      {
        std::cout<<"Enter a value to remove:\n";
        std::cin>>valueToremoveInsert;
        myTree.clearNode(valueToremoveInsert);
      }
      if(option == 3 )
      {
        myTree.deleteMin();
      }
      if(option == 4)
      {
        myTree.deleteMax();
      }
      if(option == 5)
      {
        std :: cout << "\nPRE\n";
        myTree.printTree("pre");
      }
      if(option == 6)
      {
        std :: cout << "\nIN\n";
        myTree.printTree("in");
      }
      if(option == 7)
      {
        std :: cout << "\nLEVEL\n";
        myTree.printTree("level");
      }
    } while(option <8);

}

void HeapProgram(){
    Heap myHeap = Heap(800);
    std:: ifstream fin("data.txt");
    int integerValue;
    while(fin>>integerValue)
    {
      myHeap.insert(integerValue);
    }
    myHeap.levelOrder();
    int option;
    int valueToremoveInsert;
    do {
      std::cout<<"..........................................................\n";

      std::cout<<"Please choose one of the following commands:\n";

      std::cout<<"1- Insert\n";

      std::cout<<"2- DeleteMin\n";

      std::cout<<"3- DeleteMax\n";

      std::cout<<"4- Remove\n";

      std::cout<<"5- LevelOrder\n";
      std::cout<<"6- Exit\n";



      std::cin >> option;
      if(option == 1)
      {
        std::cout<<"Enter a value to insert:\n";
        std::cin>> valueToremoveInsert;
        myHeap.insert(valueToremoveInsert);
      }
      if(option == 2)
      {

        myHeap.deleteMin();
      }
      if(option == 3 )
      {
        myHeap.deleteMax();
      }
      if(option == 4)
      {
        std::cout<<"Enter a value to remove:\n";
        std::cin>>valueToremoveInsert;
        myHeap.removeValue(valueToremoveInsert);
      }
      if(option == 5)
      {
        std :: cout << "\nPRE\n";
        myHeap.levelOrder();
      }
    } while(option <6);

}
int main()
{
  int option;
  int valueToremoveInsert;
  do
  {
    std::cout<<"..........................................................\n";

    std::cout<<"Please choose one of the following Options:\n";

    std::cout<<"1- BST\n";

    std::cout<<"2- Heap\n";

    std::cout<<"3- Exit\n";
    std::cin >> option;
    if(option == 1)
    {
      BSTprogram();
    }
    if(option == 2)
    {
      HeapProgram();
    }
  }
  while (option <3);
  return 0;
}
