

#include "Heap.h"
#include <iostream>
#include <fstream>
#include <sys/time.h>

void HeapProgram(){
    Heap myHeap = Heap(800);
    std:: ifstream fin("data.txt");
    int integerValue;
    while(fin>>integerValue)
    {
      myHeap.insert(integerValue);
    }

    myHeap.heapify();
    myHeap.levelOrder();
    int option;
    int valueToremoveInsert;
    do {
      std::cout<<"..........................................................\n";

      std::cout<<"Please choose one of the following commands:\n";

      std::cout<<"1- Insert\n";

      std::cout<<"2- DeleteMin\n";

      std::cout<<"3- DeleteMax\n";

      std::cout<<"4- LevelOrder\n";

      std::cout<<"5- Exit\n";

      std::cin >> option;
      if(option == 1)
      {
        std::cout<<"Enter a value to insert:\n";
        std::cin>> valueToremoveInsert;
        myHeap.insert(valueToremoveInsert);
        myHeap.heapify();
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
        std :: cout << "\nPRE\n";
        myHeap.levelOrder();
      }
    } while(option <5);

}
int main()
{
  HeapProgram();
  return 0;
}
