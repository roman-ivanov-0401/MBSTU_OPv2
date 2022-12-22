#include <iostream>

#include "enterInformationWithKeyboard.ui.h"

#include "input.ui.h"
#include "errorMessages.ui.h"

using namespace std;

void uiInputQuantityOfNewEntries(int& number) {
	char message[OUTPUT_LENGTH] = "Enter number of new entries: ";

	cout << "--- ENTER INFORMATION WITH KEYBOARD ---" << endl;

	inputNumber(number, message);
	while (number < 1) {
		cout << "Number must be natural" << endl;
		inputNumber(number, message);
	}
}
