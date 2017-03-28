
//STEPHEN WISS
#include "Heap.h"
Heap ::Heap(int size)
{
			entries = -1;
			heapArray = new int[size];
			for(int i = 0; i < size; i ++)
			heapArray[i] = -1;
}
void Heap ::insert(int value)
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
	 bubbleUp(entries);
}
void Heap ::getEntries()
{
	std ::cout << "Entries " <<entries << "\n";
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
	int max = 100;
 	for(int i = 0; i <= entries; i ++)
	 {
		 std ::cout<<max << " in loop -----";
		 std ::cout<<heapArray[max2gen(i)] << " max2gen in loop\n";
		 if( heapArray[max2gen(i)] > max || max == 100)
		 {
			  max = heapArray[max2gen(i)];
		 }
	 }
	 std ::cout<< max<<" out of loop\n";
	 removeValue(max);
}
void Heap ::levelOrder()
{
	std ::cout<< "\nLEVEL ORDER\n";
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
        num_to_print = num_to_print * 2;
      }
    }
    else if((i % 2 == 0) && (heapArray[i+1] != -1)){
      std::cout << "- ";
    }
	}
	std ::cout << "\n";
}
Heap ::Heap()
{
	entries = -1;
	heapArray = new int[200];
}
void Heap ::heapify()
{
	int lowLvl = entries;
	int startIndex = getParent(lowLvl);
	for (int i = startIndex; i >= 0; i --)
	{
		trickleDown(i);
	}
}
void Heap ::trickleDown(int index)
{
			int level = floor((log(index+1)/log(2)));

			if(level == 0)
			{
				trickleDownMin(index);
			}
			else if(level%2 == 0)
			{
				trickleDownMin(index);
			}
			else
			{
				trickleDownMax(index);
			}
}
void Heap ::trickleDownMin(int index)
{
	int smallChild = childOne(index);
	if(heapArray[smallChild] != -1)
	{
		int m = min2gen(index);
		if(isPep_pep(m, index))//grandchild to index
		{
			if (heapArray[m] < heapArray[index])
			{
				swap(index,m);
				if(heapArray[m] > heapArray[getParent(m)])
				{
					swap(m,getParent(m));
				}
				trickleDownMin(m);
			}
		}
		else //child to index
		{
			if(heapArray[m] < heapArray[index])
			{
				swap(m,index);
			}
		}
	}
}
int Heap ::min2gen(int index)
{
	int smallChild = childOne(index);
	if(heapArray[smallChild] != -1)
	{
		int min2gen = 100;
		for(int i = 1; i <=2 && heapArray[(2*index) + i]!= -1; i++) // find Min of 2 generations down from current index
		{
			int secondGen = (2* index) + i;
			if(heapArray[secondGen] < heapArray[min2gen] || heapArray[min2gen] == -1 )
			{
				min2gen = (2 * index) + i;
			}
			int smallChild2 = childOne(secondGen);
			if(heapArray[smallChild2] != -1)
			{
				for(int j = 1; j <=2 && heapArray[(2*secondGen) + j]!= -1; j++)
				{
					if(heapArray[(2*secondGen)+j] < heapArray[min2gen])
					{
						min2gen = (2 * secondGen) + j;
					}
				}
			}

		}
		return min2gen;
	}
}
int Heap ::max2gen(int index)
{
	int smallChild = childOne(index);
	if(heapArray[smallChild] != -1)
	{
		int max2gen = 100;
		for(int i = 1; i <=2 && heapArray[(2*index) + i]!= -1; i++) // find Min of 2 generations down from current index
		{
			int secondGen = (2* index) + i;
			if(heapArray[max2gen] < heapArray[secondGen]|| heapArray[max2gen] == -1 )
			{
				max2gen = secondGen;
			}
			int smallChild2 = childOne(secondGen);
			if(heapArray[smallChild2] != -1)
			{
				for(int j = 1; j <=2 && heapArray[(2*secondGen) + j]!= -1; j++)
				{
					if(heapArray[(2*secondGen)+j] > heapArray[max2gen])
					{
						max2gen = (2 * secondGen) + j;
					}
				}
			}
		}
		return max2gen;
	}
}
void Heap ::trickleDownMax(int index)
{
	int smallChild = childOne(index);
	if(heapArray[smallChild] != -1)
	{
		int m = max2gen(index);
		if(isPep_pep(m, index))//grandchild to index
		{
			if (heapArray[m] > heapArray[index])
			{
				swap(index,m);
				if(heapArray[m] < heapArray[getParent(m)])
				{
					swap(m,getParent(m));
				}
				trickleDownMax(m);
			}
		}
		else //child to index
		{
			if(heapArray[m] > heapArray[index])
			{
				swap(m,index);
			}
		}
	}
}
int Heap ::getPep_pep(int index)
{
	int parentIndex = getParent(index);
	return(getParent(parentIndex));
}
bool Heap ::isPep_pep(int index, int potentialPep)
{
	return (heapArray[getPep_pep(index)] == heapArray[potentialPep]);
}
void Heap::bubbleUp(int index)
{
  int indexParent = getParent(index);
  if(index % 2 == 0)
  {
    if(index > 1 && heapArray[index] > heapArray[indexParent])
    {
			swap(index,indexParent);
      bubbleUpMax(indexParent);
    }
    else
    {
      bubbleUpMin(index);
    }
  }
  else
  {
    if(index > 1 && heapArray[index] < heapArray[indexParent])
    {
      swap(index, indexParent);
      bubbleUpMin(indexParent);
    }
    else
    {
      bubbleUpMax(index);
    }
  }
}
void Heap ::bubbleUpMin(int index)
{
	if (getPep_pep(index) > 0)
	{
		if (heapArray[index] < heapArray[getParent(getParent(index))])
		{
			swap(index,getParent(getParent(index)));

			bubbleUpMin(getPep_pep(index));
		}
	}
}
void Heap ::bubbleUpMax(int index)
{
	if (getPep_pep(index) > 0)
	{
		if (heapArray[index] > heapArray[getParent(getParent(index))])
		{
			swap(index,getParent(getParent(index)));

			bubbleUpMax(getPep_pep(index));
		}
	}
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

void Heap ::swap(int a, int b)
{
	int t = heapArray[a];
	heapArray[a] = heapArray[b];
	heapArray[b] = t;
}
int Heap ::childOne(int index)
{
	int childindex= (index*2)+1;
	return childindex;
}
int Heap ::getParent(int index)
{
	int parentIndex = floor((index -1 ) / 2);
	return parentIndex;
}
void Heap ::printHeap()
{	std ::cout<< "\nHEAP ARRAY\n";
	for (int i = 0; i < 20; i ++)
	{
		std::cout << heapArray[i]<< "\n";
	}
}
