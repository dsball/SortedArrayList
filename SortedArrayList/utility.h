/*------------------------------------utility.h
Purpose: provides general utility functions, headers, and generic using declarations.

--- Member Data ---
Name            Type           Description
-------------------------------------------------------------------------------------------
none

--- Functions ---
Name                            Return    Description; Parameter description
--------------------------------------------------------------------------------------------
clearScreen()                  void      replace system("CLS") with non-system function call
    no params

pause()                        void      replace system("PAUSE") with non-system function call
    no params

colorset()                     void      sets background and foreground color in console
    WORD    text color(0-15) + bgcolor((0-15)*16)

cursorpos                      void      move cursor to x y coord in console
	int     x coord 
	int     y coord

printFile(string)              void      opens a file and prints it with fileToString()
    string: relative path of file being printed

fileToString(ifstream &inFile)  void      stores an ifstream in a string and returns it
    ifstream&: ifstream to be read
*/

#ifndef _UTILITY_INTERFACE_
#define _UTILITY_INTERFACE_

#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<windows.h>
#include<stdio.h>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;
using std::setw;
using std::to_string;
using std::string;
using std::left;
using std::ostream;
using std::istream;

void pause();
bool printFile(string);
string fileToString(ifstream&);
void cursorpos( int, int);
void screensaver();
void colorset(WORD);
void clearScreen();

#endif