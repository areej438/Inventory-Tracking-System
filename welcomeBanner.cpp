#include <iostream>
//#include <iomanip>
#include <windows.h>
#include "welcomeBaner.h"
#include "colors.h"
using namespace std;


void loadingMsg() {
	cout << endl;
	cout << endl; 
	cout << endl;
	cout << endl;
	cout <<PASTEL_YELLOW<<BOLD << endl;
	cout << "           -------------------------------------------------------------- "<< endl;
	cout << endl;
	cout << PASTEL_LAVENDER;
	cout <<"                      Loading Inventory Tracking System........      "<<  endl;
	cout << PASTEL_YELLOW << endl;
	cout  << "           -------------------------------------------------------------- " <<RESET<< endl;
	Sleep(3000);
	system("cls");
}

void welcomeBanner() {
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << PASTEL_YELLOW <<BOLD<< endl;
	cout << "                 ----------------------------------------------------" << endl;
	cout << PASTEL_LAVENDER << endl;
	cout  <<"                         Welcome to inventory tracking system" << endl;
	cout <<PASTEL_YELLOW<< endl;
	cout  << "                 ----------------------------------------------------" << RESET << endl;
	cout<< endl;
	//cout << setw(20) << "Project by : Areej Mehmood and Hiba Zahra" << endl; for spacing check waht i sthe problem 
	Sleep(3000);

}

void beforeMainmenuMsg() {
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << PASTEL_LAVENDER<< "                         Main Menu is loading...." <<RESET<< endl;
	Sleep(3000);
	system("cls");
}