
//STEPHEN WISS

#include "Heap.h"
Heap :: Heap(int size)
{
			entries = -1;
			heapArray = new int[size];
			for(int i = 0; i < size; i ++)
			heapArray[i] = -1;
}
void Heap :: insert(int value)
{
	if(entries == -1)
	{
		heapArray[0] = value;
		entries ++;
	}
	else
	{
		entries ++;
		heapArray[entries] = value;
		}
}
void Heap ::deleteMin()
{
	swap(0,entries);
	heapArray[entries] = -1;
	entries --;
	heapify();
}
void Heap ::deleteMax()
{
	int max = 0;
	int maxIndex;
	 for(int i = 0; i <= entries; i ++)
	 {
		 if( max < heapArray[i])
		 {
			  max = heapArray[i];
		 }
	 }
	 for(int i = 0; i <= entries; i ++)
	 {
		 if(heapArray[i] == max)
		 {
			 swap(i,entries);
			 heapArray[entries] = -1;
			 entries --;
			 heapify();
		 }
	 }
}
void Heap ::levelOrder()
{
	std :: cout<< "\nLEVEL ORDER\n";
	int curr_level = 0;
  int num_printed = 0;
  int num_to_print = 1;

  for(int i = 0; heapArray[i] != -1; i++){
    std::cout << heapArray[i] << " ";
    num_printed++;

    if(num_to_print == num_printed){
      std::cout << "\n";
      curr_level++;
      num_printed = 0;
      num_to_print = 1;
      for(int j = 0; j < curr_level; j++){
        num_to_print = num_to_print * 3;
      }
    }
    else if((i % 3 == 0) && (heapArray[i+1] != -1)){
      std::cout << "- ";
    }
	}
	std :: cout << "\n";
}
Heap :: Heap()
{
	entries = -1;
	heapArray = new int[200];
}
void Heap :: heapify()
{
	int lowLvl = entries;
	int startIndex = getParent(lowLvl);
	for (int i = startIndex; i >= 0; i --)
	{
		bottomUp(i);
	}
}
void Heap ::bottomUp(int currentLow)
{

	int smallChild = childOne(currentLow);

	if(heapArray[smallChild] == -1)	{return;}
	for(int i = 2; i <= 3 && heapArray[(3*currentLow) + i] != -1; i++){
	if(heapArray[smallChild] > heapArray[(3*currentLow) + i]){
		smallChild = (3*currentLow) + i;
		}
	}
	if(heapArray[currentLow] > heapArray[smallChild])
	{
		swap(smallChild, currentLow);
		bottomUp(smallChild);
	}
}
int Heap ::childThree(int index)
{
	int childindex= (index*3)+3;
	return childindex;
}
void Heap ::removeValue(int value)
{
	for(int i = 0; i <= entries; i ++)
	{
		if(heapArray[i] == value)
		{
			swap(i,entries);
			heapArray[entries] = -1;
			entries --;
			heapify();
		}
	}
}
void Heap :: swap(int a, int b)
{
	int t = heapArray[a];
	heapArray[a] = heapArray[b];
	heapArray[b] = t;
}
int Heap ::childOne(int index)
{
	int childindex= (index*3)+1;
	return childindex;
}
int Heap ::getParent(int index)
{
	int parentIndex = floor((index-1 ) / 3);
	return parentIndex;
}
void Heap :: printHeap()
{
	for (int i = 0; i < 20; i ++)
	{
		std:: cout << heapArray[i]<< "\n";
	}
}
