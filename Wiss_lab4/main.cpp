
#include <iostream>
#include <fstream>
#include <string>
#include "ClosedHash.h"
#include <stdlib.h>
#include "openHash.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
using namespace std;

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

int main()
{
  int tableSize = 600011;
  long maxValue = 2147483467;
  int amount1 = floor(tableSize * .2);
  int amount2 = floor(tableSize * .3);
  int amount3 = floor(tableSize * .4);
  int amount4 = floor(tableSize * .5);
  int amount5 = floor(tableSize * .6);
  int amount6 = floor(tableSize * .7);
  int amount7 = floor(tableSize * .8);
  int amount8 = floor(tableSize * .9);
  float lf[8] = {.2,.3,.4,.5,.6,.7,.8,.9};

  int arrofAmts [8] = {amount1,amount2,amount3,amount4,amount5,amount6,amount7,amount8};
  Timer tO,tQ,tD;
  for (int j = 0; j < 8;j++)
  {
    double qTime = 0;
    double oTime = 0;
    double dTime = 0;
    for(int i = 0; i < 5; i++)
    {
      srand(time(NULL));
      OpenHash oHash =  OpenHash(tableSize);
      ClosedHash dHash =  ClosedHash(tableSize);
      ClosedHash qHash =  ClosedHash(tableSize);
      qHash.setType(1);
      dHash.setType(2);
      tO.start();
      for(int k = 0; k <arrofAmts[j]; k++)
      {
        oHash.insert(rand() % maxValue);
      }
      oTime += tO.stop();
      tQ.start();
      for(int k = 0; k <arrofAmts[j]; k++)
      {
        dHash.insert(rand() % maxValue);
      }
      dTime += tQ.stop();
      tD.start();
      for(int k = 0; k <arrofAmts[j]; k++)
      {
        qHash.insert(rand() % maxValue);
      }
      qTime += tD.stop();


    }
    
    std :: cout << "Load Factor: " << lf[j] <<endl;
    std :: cout << "Average OpenHashing Time: " << (oTime/5) << endl;
    std :: cout << "Average QuadHashing Time: " << (qTime/5) << endl;
    std :: cout << "Average DoubleHashing Time: " << (dTime/5) << endl;
    std :: cout << " -----------------------------------" << endl;


  }
}



/*
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
*/
