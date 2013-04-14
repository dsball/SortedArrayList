//------------------------------------SortArrayList.cpp

#include "SortArrayList.h"

//initializes class data members
SortArrayList::SortArrayList()
{
	cout<<"Enter initial array size: ";
	while(!(cin>>maxEntries))
	{
		cout<<"invalid entry, try again: ";
		cin.sync();
		cin.clear();
	}
	
	workingArray = new ArrayEntry[maxEntries];
	if(!workingArray)
	{
		cout<<"Heap is full, exiting.";
		exit(0);
	}
	numEntries = 0;
}

void SortArrayList::sort()
{
	ArrayEntry temp;
	int j;
	int i;

	for(i = 1 ; i<numEntries ; i++)
	{
		temp = workingArray[i];
		j = i-1;
		while(temp.a < workingArray[j].a)
		{
			workingArray[j+1] = workingArray[j];
			j--;
		}
		workingArray[j+1] = temp;
	}
}

//Creates a temporary struct and prompts user for data members, returns pointer to struct
ArrayEntry* SortArrayList::makeEntry()
{
	ArrayEntry* tempEntry = nullptr;
	tempEntry = new ArrayEntry;
	if(!tempEntry)
	{
		cout<<"Failure in allocating memory.\n";
		exit(0);
	}

	cout<<"String 1: ";
	while(!(cin>>tempEntry->a))
	{
		cin.sync();
		cin.clear();
		cout<<"Invalid entry, try again:";
	}
	cout<<"String 2: ";
	while(!(cin>>tempEntry->b))
	{
		cin.sync();
		cin.clear();
		cout<<"Invalid entry, try again:";
	}
	cout<<"String 3: ";
	while(!(cin>>tempEntry->c))
	{
		cin.sync();
		cin.clear();
		cout<<"Invalid entry, try again:";
	}
	
	return tempEntry;
}

//Adds data struct from argument to tail of array.
SortArrayList& SortArrayList::operator+(ArrayEntry* tempEntry)
{
	if(findEntry((*tempEntry).a) == -1)
	{
		if(numEntries == maxEntries)
		{
			extend();
		}
		workingArray[numEntries] = *tempEntry;
		numEntries++;
		sort();
		cout<<"Added "<<workingArray[numEntries].a;
	}
	else
	{
		cout<<"That key value already exists in the list! Returning to menu. \n";
		pause();
	}
	return *this;
}

//Allows use of += operator to add a struct via operator+ overload
SortArrayList& SortArrayList::operator+=(ArrayEntry* tempEntry)
{
	*this = *this + tempEntry;
	return *this;
}

int SortArrayList::getCount()
{
	return numEntries;
}

void SortArrayList::emptyList()
{
	numEntries = 0;
}

int SortArrayList::findEntry(int findMe)
{
	unsigned int min = 0;
	unsigned int max = numEntries-1;
	int mid;
	if(!numEntries)
	{
		return -1;
	}
	while(max >= min)
	{
		mid = (max+min)/2;
		if(findMe < workingArray[mid].a)
		{
			max = mid-1;
		}
		else if(findMe > workingArray[mid].a)
		{
			min = mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//removes an item from the list
void SortArrayList::remSort(int delMe)
{
	unsigned int n = findEntry(delMe);
	if(!n)
	{
		cout<<"That entry doesn't exist!";
	}
	else
	{
		cout<<"Deleting "<<workingArray[n].a<<endl;
		while(n < numEntries-1 )
		{
			workingArray[n] = workingArray[n+1];
			n = n+1;
		}
		numEntries--;
		cout<<" Deleted.\n";
	}
}

//Doubles the size of the working array 
void SortArrayList::extend()
{
	unsigned int i = 0;
	ArrayEntry *tempArray = new ArrayEntry[maxEntries*2];
	if(!tempArray)
	{
		cout<<"Heap is full, exiting.";
		pause();
		exit(0);
	}
	for(i ; i<numEntries ; i++)
	{
		tempArray[i] = workingArray[i];
	}
	maxEntries *= 2;
	delete []workingArray;
	workingArray = tempArray;
	tempArray = nullptr;
}

//Overloads extraction operator to output array contents to ostream.
ostream& operator<<(ostream& outStream , const SortArrayList& inQueue)
{
	clearScreen();
	ArrayEntry* tempArray = inQueue.workingArray;
	outStream<<"Outputting list:\n";
	outStream<<left<<setw(5)<<" "<<setw(10)<<"a"<<setw(10)<<"b"<<setw(10)<<"c"<<endl;
	outStream<<"-----------------------------------\n";
	for(unsigned int i = 0; i<inQueue.numEntries ; i++)
	{
		outStream<<left<<setw(5)<<" "<<setw(10)<<tempArray[i].a<<setw(10)<<tempArray[i].b<<setw(10)<<tempArray[i].c<<endl;
	}
	return outStream;
}

SortArrayList::~SortArrayList()
{
	//de-allocates dynamically allocated memory
	cout<<"Releasing reserved memory...\n";
	delete[] workingArray;
	cout<<"Complete.\n";

	pause();
}
