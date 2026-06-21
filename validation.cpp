#include <iostream>
#include "colors.h"
#include "validation.h"
#include <limits>
using namespace std;



//for input validation helper functions
int intValidation(string prompt) {
	int value;
	while (true) {
		cout << PASTEL_BROWN << prompt << PASTEL_BEIGE;
		if (cin >> value) {
			cout << RESET;
			return value;
		}
		else {
			cout << PASTEL_RED << "Invalid input!! Enter an integer" << RESET << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
double doubleValidation(string prompt) {
	double value;
	while (true) {
		cout << PASTEL_BROWN;
		cout << prompt << PASTEL_BEIGE;
		if (cin >> value) {
			cout << RESET;
			return value;
		}
		else {
			cout << PASTEL_RED << "Invalid input!! Enter a numeric value" << RESET << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}