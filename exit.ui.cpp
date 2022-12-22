#include <iostream>

#include "exit.ui.h"

#include "input.ui.h"

using namespace std;

void uiDoYouReallyWantToExit(int &option) {
	cout << "--- EXIT ---" << endl;
	cout << "Do you really want to exit?" << endl;
	cout << "[1] Yes" << endl;
	cout << "[2] No" << endl;
	char message[OUTPUT_LENGTH] = "Enter option: ";
	inputNumberInRange(option, message, 1, 2);
}