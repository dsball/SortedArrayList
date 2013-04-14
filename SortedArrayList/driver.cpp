#include "utility.h"
#include "SortArrayList.h"
#include "menu.h"

int main()
{
	
	printFile("about.txt");
	pause();
	clearScreen();

	SortArrayList workingArray;
	int i;
	int choice = 0;
	int findMe;
	int delMe;
	Menu menuA;

	menuA.addItem("Add Entry");
	menuA.addItem("Remove Entry");
	menuA.addItem("Find Entry");
	menuA.addItem("Display List");
	menuA.addItem("Display Count");
	menuA.addItem("Empty List");
	menuA.addItem("Exit");


	while(choice!= 7)
	{
		choice = menuA.getChoice();
		switch(choice)
		{
			case 1:
				cout<<"Adding Entry:\n";
				workingArray += workingArray.makeEntry();
				break;
			case 2:
				cout<<"Remove an Entry:\n";
				cout<<"Enter the a value of the item you wish to delete: ";
				while(!(cin>>delMe))
				{
					cout<<"Input failure, try again:";
					cin.clear();
					cin.sync();
				}
				workingArray.remSort(delMe);
				pause();
				break;
			case 3:
				cout<<"Find an Entry:\n";
				cout<<"Enter the a value of the item you wish to locate: ";
				while(!(cin>>findMe))
				{
					cout<<"Input failure, try again:";
					cin.clear();
					cin.sync();
				}
				i = workingArray.findEntry(findMe);
				if(i > -1)
				{
					cout<<"The list member is in cell "<<i<<endl;
				}
				else
				{
					cout<<"That member is not in the list.\n";
				}
				pause();
				break;
			case 4:
				cout<<"Displaying List:\n";
				cout<<workingArray;
				pause();
				break;
			case 5:
				cout<<"There are ";
				colorset(0x0B);
				cout<<workingArray.getCount();
				colorset(0x07);
				cout<<" entries in the list.\n";
				pause();
				break;
			case 6:
				cout<<"Emptying List.\n";
				workingArray.emptyList();
				cout<<"List emptied!\n";
				pause();
				break;
			case 7:
				cout<<"Exiting Program...";
				break;
		}
	}

	printFile("goodbye.txt");
	pause();

	return 0;
}