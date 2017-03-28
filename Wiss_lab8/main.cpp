
#include "Lnode.h"
#include "LeftistHeap.h"
#include "Snode.h"
#include "SkewHeap.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "Queue.h"
#include "Qnode.h"

// int main()
// {
// Queue* myQueue = new Queue();
// Lnode* leftistNode0 = new Lnode(0);
// Lnode* leftistNode1 = new Lnode(1);
// Lnode* leftistNode2 = new Lnode(2);
// Lnode* leftistNode3 = new Lnode(3);
// Qnode* qnode1 = new Qnode(leftistNode0);
// Qnode* qnode2 = new Qnode(leftistNode1);
// Qnode* qnode3 = new Qnode(leftistNode2);
// Qnode* qnode4 = new Qnode(leftistNode3);
//
// myQueue->add(qnode1);
// myQueue->print();
// myQueue->add(qnode2);
// myQueue->print();
// myQueue->add(qnode3);
// myQueue->print();
// myQueue->add(qnode4);
// myQueue->print();
// myQueue->remove();
// myQueue->print();
// }
//
//

class Timer {
private:

				timeval startTime;
        timeval endTime;

public:

	void start(){
		gettimeofday(&startTime, NULL);
	}

	double stop(){
	        long seconds, nseconds;
		double duration;

		gettimeofday(&endTime, NULL);

		seconds  = endTime.tv_sec  - startTime.tv_sec;
		nseconds = endTime.tv_usec - startTime.tv_usec;

		duration = seconds + nseconds/1000000.0;

		return duration;
	}

	void printTime(double duration){
		printf("%5.6f seconds\n", duration);
	}
};
void logResults(double arr1[4][5],double arr2[4][5],double arr3[4][5],double arr4[4][5])
{
  double HousingArray[4];
	double SkewOp_BuildArray[2];

	HousingArray[0] = arr1[4][5];// leftbuild
	HousingArray[1] = arr2[4][5];// leftOp

	HousingArray[2] = arr3[4][5];//Skewbuild
	HousingArray[3] = arr4[4][5];//Skewop

  double Averagebuild_l[4];
	double Averageop_l[4];
	double Averagebuild_s[4];
	double Averageop_s[4];
for (int i = 0 ; i <4; i ++)
{
	double l_buildHolder = 0;
	double l_opHolder = 0;
	double s_buildHolder = 0;
	double s_opHolder = 0;
	for (int j = 0; j < 5; j ++)
	{
		l_buildHolder += arr1[i][j];
		l_opHolder += arr2[i][j];

		s_buildHolder += arr3[i][j];
		s_opHolder += arr4[i][j];
	}
	Averagebuild_l[i] = l_buildHolder/5;
	Averageop_l[i] = l_opHolder/5;
	Averagebuild_s[i] = s_buildHolder/5;
	Averageop_s[i] = s_opHolder/5;
	}
	std :: ofstream outfile("output.txt");
	outfile <<"\n\n\n***************************************\n\n\n";
	outfile <<"            TIMES: \n\n\n";
	outfile <<"Qty              " << "----50000----" <<
	 "----100000----" << "----200000----" << "----400000----"<<"\n\n\n";
		outfile << "Build times- Leftist "
						<<Averagebuild_l[0]
						<< "--- "
						<< Averagebuild_l[1]
						<< "---- "
						<< Averagebuild_l[2]
						<< "------ "
					  << Averagebuild_l[3]
						<<"\n\n\n";
		outfile << "   Op times- Leftist "
						<<Averageop_l[0]
						<< "--- "
						<< Averageop_l[1]
						<< "---- "
						<< Averageop_l[2]
						<< "------ "
						<< Averageop_l[3]
						<<"\n\n\n";
		outfile << "   Build times- Skew "
						<<Averagebuild_s[0]
						<< "--- "
						<< Averagebuild_s[1]
						<< "---- "
						<< Averagebuild_s[2]
						<< "------ "
						<< Averagebuild_s[3]
						<<"\n\n\n";
		outfile << "     Op times- Skew "
						<<Averageop_s[0]
						<< "--- "
						<< Averageop_s[1]
						<< "---- "
						<< Averageop_s[2]
						<< "------ "
						<< Averageop_s[3]
						<<"\n\n\n";

}
int timingTest()
{
 double skewbuildTime[4][5];
 double leftbuildTime[4][5];
 double SkewOptime[4][5];
 double leftOptime[4][5];

 double stopTime = 0.0;
 Timer timer;
 int* bigArrayofArrayLengths = new int[4];

 bigArrayofArrayLengths[0] = 50000;
 bigArrayofArrayLengths[1] = 100000;
 bigArrayofArrayLengths[2] = 200000;
 bigArrayofArrayLengths[3] = 400000;

   for(int i = 0; i < 4; i++)
   {
     int arrayLengththisIteration = bigArrayofArrayLengths[i];
     for(int j = 0; j< 5; j++)
     {
       srand(j);
       LeftistHeap* timeLeftistHeap =  new LeftistHeap();
       SkewHeap* timeSkewHeap =  new SkewHeap();

       int* bigArrayofNumbers  = new int[arrayLengththisIteration];

       for (int k = 0; k < arrayLengththisIteration; k++)
       {
           bigArrayofNumbers[k] = ( rand() % (4*arrayLengththisIteration) ) + 1;
       }
       std::cout << "SIZE  = " << bigArrayofArrayLengths[i] << "\n" << "SEED = " << j+1 << "\n"
       << "\nNUMBERS SUCCESSFULLY GENERATED\n" <<"\nINSERTING NEXT\n"
       <<"\n*************************************\n";
       timer.start();
       for (int l = 0; l < arrayLengththisIteration; l++)
       {
         timeLeftistHeap->insert(bigArrayofNumbers[l]);
       }
       leftbuildTime[i][j] = timer.stop();
       std::cout << "SIZE  = " << bigArrayofArrayLengths[i] << "\n" << "SEED = " << j+1 << "\n"
       << "\nLEFTISTHEAP SUCCESSFULLY GENERATED\n" <<"\nOPERATION TIMES NEXT\n"
       <<"\n*************************************\n";

       timer.start();
       for (int l = 0; l < arrayLengththisIteration; l++)
       {
         timeSkewHeap->insert(bigArrayofNumbers[l]);
       }
       skewbuildTime[i][j] = timer.stop();
       std::cout << "SIZE  = " << bigArrayofArrayLengths[i] << "\n" << "SEED = " << j+1 << "\n"
       << "\nSKEWHEAP SUCCESSFULLY GENERATED\n" <<"\nOPERATION TIMES NEXT\n"
       <<"\n*************************************\n";

       srand(j+5);
       timer.start();
       for(int m = 0; m < (arrayLengththisIteration*.10);m ++)
       {
         int op = (double) rand() / RAND_MAX;
         if(op < (.5))
         {
           timeLeftistHeap->deleteMin();
         }
         else
         {
           int insertValue = (rand() %(4*arrayLengththisIteration)+1);
           timeLeftistHeap->insert(insertValue);
         }
       }
       leftOptime[i][j] = timer.stop();
       std::cout<< "SIZE  = " << bigArrayofArrayLengths[i]  << "\n" << "SEED = " << j+1 << "\n"
       << "\nLEFTHEAP :" << (arrayLengththisIteration*.1) <<"\n"<< "OPERATIONS SUCCESSFULLY PERFORMED\n"
       <<"\n*************************************\n";

       timer.start();
       for(int m = 0; m < (arrayLengththisIteration*.10);m ++)
       {
         int op = (double) rand() / RAND_MAX;
         if(op < (.5))
         {
           timeSkewHeap->deleteMin();
         }
         else
         {
           int insertValue = (rand() %(4*arrayLengththisIteration)+1);
           timeSkewHeap->insert(insertValue);
         }
       }
       SkewOptime[i][j] = timer.stop();
       std::cout<< "SIZE  = " << bigArrayofArrayLengths[i] << "\n" << "SEED = " << j+1 << "\n"
       << "\nSKEWHEAP :" << (arrayLengththisIteration*.1) <<"\n"<<"OPERATIONS SUCCESSFULLY PERFORMED\n"
       <<"\n*************************************\n";
     }

   }
	 logResults(leftbuildTime,leftOptime, skewbuildTime, SkewOptime);
   return 0;
 }




int main(){
    std:: ifstream fin("data.txt");
    LeftistHeap myTree = LeftistHeap();
    SkewHeap mySkew = SkewHeap();
    int integerValue;
    while(fin>>integerValue)
    {
      myTree.insert(integerValue);
      mySkew.insert(integerValue);
    }
    int option;
    int valueToremoveInsert;
    do {
      std::cout<<"..........................................................\n";

      std::cout<<"Please choose one of the following commands:\n";

      std::cout<<"1- Insert\n";

      std::cout<<"2- Delete Min\n";


      std::cout<<"3- Pre-order \n";
      std::cout<<"4- In-order \n";
      std::cout<<"5- Level-order \n";
      std::cout<<"6- Time-Comparison Test\n";
      std::cout<<"7- Exit\n";


      std::cin >> option;
      if(option == 1)
      {
        std::cout<<"Enter a value to insert:\n";
        std::cin>> valueToremoveInsert;
        myTree.insert(valueToremoveInsert);
        mySkew.insert(valueToremoveInsert);

      }
      // if(option == 2)
      // {
      //   std::cout<<"Enter a value to remove:\n";
      //   std::cin>>valueToremoveInsert;
      //   myTree.clearNode(valueToremoveInsert);
      // }
      if(option == 2 )
      {
        myTree.deleteMin();
        mySkew.deleteMin();
      }

      if(option == 3)
      {
        std :: cout << "\nPRE\n";
        myTree.printTree("pre");
        std::cout<<"..........................................................\n";

        mySkew.printTree("pre");

      }
      if(option == 4)
      {
        std :: cout << "\nIN\n";
        myTree.printTree("in");
        std::cout<<"..........................................................\n";

        mySkew.printTree("in");

      }
      if(option == 5)
      {
        std :: cout << "\nLEVEL\n";
        myTree.printTree("level");
        std::cout<<"..........................................................\n";
        mySkew.printTree("level");
      }
      if(option == 6)
      {
        timingTest();
      }
    } while(option <7);

}
