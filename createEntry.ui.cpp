#include <iostream>
#include <cstring>

#include "createEntry.ui.h"

#include "input.ui.h"

using namespace std;

void uiInputPosition(int &position, int length) {
	cout << "--- CREATE AN NEW ENTRY ---" << endl;
	cout << "Enter position of new entry (1 - " << length + 1 << ")" << endl;
	char message[OUTPUT_LENGTH] = "Position: ";
	inputNumberInRange(position, message, 1, length + 1);
	position--;
}