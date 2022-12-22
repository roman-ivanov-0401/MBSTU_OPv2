#include <iostream>
#include <iomanip>

#include "updateEntry.ui.h"

#include "input.ui.h"

using namespace std;

void uiUpdateEntryHearder() {
	cout << "--- UPDATE AN ENTRY ---" << endl;
}

void uiEnterOption(int &option) {
	cout << "Choose mode of search" << endl;
	cout << setw(5) << "[1]" << "By query request" << endl;
	cout << setw(5) << "[2]" << "By id" << endl;
	char message[OUTPUT_LENGTH] = "Option: ";
	inputNumberInRange(option, message, 1, 2);
}

void uiNotFound() {
	cout << "Entry not found...";
}

void uiEnterId(int &_id) {
	char message[OUTPUT_LENGTH] = "Enter id: ";
	inputNumber(_id, message);
}