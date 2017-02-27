
#include "Node.h"
#include "BST.h"
#include <iostream>
#include <fstream>
#include "LinkedList.h"
/*
int main()
{
  List myList = List{};
  Node* a =new Node(5);
  Node* b =new Node(6);
  Node* c =new Node(7);
  Node* d =new Node(8);
  Node* e =new Node(9);
  Node* f =new Node(0);
  myList.insert(a);
  myList.insert(b);
  myList.insert(c);
  myList.insert(d);
  myList.insert(e);
  myList.insert(f);
  //myList.remove();
  myList.print();
}
*/

int main(){
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
