#include <iostream>
#include <iomanip>

#include "deleteAnEntry.ui.h"

#include "input.ui.h"

using namespace std;

void uiDeleteEntryHearder() {
	cout << "--- DELETE AN ENTRY ---" << endl;
}

void uiEnterOptionForDelete(int& option) {
	cout << "Choose mode of search" << endl;
	cout << setw(5) << "[1]" << "By query request" << endl;
	cout << setw(5) << "[2]" << "By id" << endl;
	char message[OUTPUT_LENGTH] = "Option: ";
	inputNumberInRange(option, message, 1, 2);
}

void uiNotFoundForDelete() {
	cout << "Entry not found...";
}

void uiEnterIdForDelete(int& _id) {
	char message[OUTPUT_LENGTH] = "Enter id: ";
	inputNumber(_id, message);
}