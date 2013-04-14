#include "utility.h"

CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_SCREEN_BUFFER_INFO initconfig;

HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
WORD   index   = 0;


//replace system("PAUSE")
void pause()
{
	cout<<"Press Enter to continue...";
	cin.clear();
	cin.sync();
	cin.get();
}

//replace clearScreen()
void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };
	

	hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(hStdOut, (TCHAR) ' ', cellCount, homeCoords, &count)) 
	{
		return;
	}

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) 
	{
		return;
	}

	/* Move the cursor home */
	SetConsoleCursorPosition( hStdOut, homeCoords );
}

//opens a file and prints it with fileToString()
bool printFile(string inFile)
{
	ifstream splashFile;
	clearScreen();
	splashFile.open(inFile);
	if(splashFile.fail())
	{
		return false;
	}
	cout << fileToString(splashFile);
	splashFile.close();
	return true;
}

//stores an ifstream in a string and returns it
string fileToString(ifstream &inFile)
{
	string printMe = "";
	string temp;

	if(inFile)
	{
		while(inFile.good())
		{
			getline(inFile, temp);
			temp += "\n";
			printMe += temp;
		}
	}
	else
	{
		cout<<"No input detected!";
	}

	clearScreen();
	return printMe;

}

void colorset(WORD myColors)
{
	SetConsoleTextAttribute(hstdout, myColors );
}


void cursorpos( int x, int y )
{
    COORD p = { x, y };
    SetConsoleCursorPosition( hstdout, p );
}

void screensaver()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	

	int a = 1;
	int b = 5;
	int thresh = 0;
	int d = 0;
	int e = 0;
	int i = 0;
	bool aup = true;
	bool bup = true;

	while(true)
	{
		GetConsoleScreenBufferInfo (hstdout, &csbi);
		SMALL_RECT window = csbi.srWindow;
		short width = csbi.srWindow.Right-csbi.srWindow.Left;
		short height = csbi.srWindow.Bottom - csbi.srWindow.Top;
		if(a%3 == 0)
		{
			SetConsoleTextAttribute(hstdout, i );
		}


		cursorpos(a,b);
		Sleep(5);
		cout<<"+";
		if(aup == true && a<=(width))
		{
			if(a!=width)
			{
				a++;
			}
			else
			{
				aup = false;
				a--;
			}
		}
		else
		{
			if(a == 0)
			{
				aup = true;
				a++;
			}
			else
			{
				a--;
			}
		}
		if(bup == true && b<=height)
		{
			if(b!=height)
			{
				b++;
			}
			else
			{
				bup = false;
				b--;
			}
		}
		else
		{
			if(b == 0)
			{
				bup = true;
				b++;
			}
			else
			{
				b--;
			}
		}
		i++;
		if(i == 16) i = 0;
	}
}

