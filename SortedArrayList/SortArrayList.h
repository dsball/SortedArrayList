/*------------------------------------utility.h-----------------------------------------------------
Purpose: provides general utility functions, headers, and generic using declarations.

**** Member Data ****
Name              Type             Description
____________________________________________________________________________________________________
workingArray      ArrayEntry*      pointer to array containing list
maxEntries        unsigned int     maximum size of working array
numEntries        unsigned int     number of cells filled in working array

**** Functions ****
Function Name      Return          Description 
  Parameter                          Description
____________________________________________________________________________________________________
SortArrayList      none            initializes member data

makeEntry          ArrayEntry*     creates a temporary entry structure to be added to the array

remSort            void            removes an entry from the list, maintains sorting
  int             integer value matching key (a) value of item to be deleted.

sort               void            sorts the list in ascending order

findEntry          int             finds the cell number containing the key and returns it.
  int                                integer value matching key (a) value of item to be located.

getCount           int             determines and returns the number of keys in the list

emptyList          void            resets list contents to 0

extend             void            doubles the size if the array

operator+()        SortArrayList&  Adds a new item and puts it in place using sort()
  ArrayEntry*                        struct to be added to array

operator+=         SortArrayList&  Uses operator+ to create operator += for array addition
  ArrayEntry*                        struct to be added to array 

operator<<         ostream&         Overloads extraction operator to print array.
  ostream&                            address of ostream handle
  SortArrayList&                      address of class containing list to be output

~SortArrayList      none            de-allocates dynamically assigned memory

---------------------------------------------------------------------------------------------------*/

#ifndef ARRAY_INTERFACE
#define ARRAY_INTERFACE

#include "utility.h"

struct ArrayEntry
{
	int a;
	int b;
	int c;
};

class SortArrayList
{
private:
	ArrayEntry* workingArray;
	unsigned int maxEntries;
	unsigned int numEntries;

public:
	SortArrayList(void);
	ArrayEntry* makeEntry();
	void remSort(int delMe);
	void sort();
	int findEntry(int findMe);
	int getCount();
	void emptyList();
	void extend();
	SortArrayList& operator+(ArrayEntry*);
	SortArrayList& operator+=(ArrayEntry*);
	friend ostream& operator<<(ostream& , const SortArrayList&);
	void displayList();
	~SortArrayList(void);
};

#endif