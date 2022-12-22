#include <iostream>

#include "outputDataToFile.ui.h"
#include "input.ui.h"

using namespace std;

void uiEnterQuantityOfEntriesToOutputTextFile(int &quantity) {
	char message[OUTPUT_LENGTH] = "Enter number of entries: ";

	cout << "--- OUTPUT DATA TO FILE ---" << endl;

	inputNumber(quantity, message);
	while (quantity < 1) {
		cout << "Number must be natural" << endl;
		inputNumber(quantity, message);
	}
}

void uiSuccessfullyOutput() {
	cout << "Data have been successfully output to text file" << endl;
}
