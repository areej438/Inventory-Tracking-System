// OOP-project.cpp, This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "welcomeBaner.h"
#include "mainMenu.h"
using namespace std;


int main()
{
	loadingMsg();
	welcomeBanner();
	beforeMainmenuMsg();
	welcomeBanner();
	mainMenu();
		
}
