#include <iostream>
#include <iomanip>

#include "sort.ui.h"

#include "storage.service.h"
#include "input.ui.h"

using namespace std;

void uiShowSortHeader() {
	cout << "--- SORT ---" << endl;
}

void uiEnterNumberOfField(int &number) {
	cout << "Select the field by which the database will be sorted" << endl;
	for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
		char fieldName[FIELD_LENGTH]{};
		getFieldName(i, fieldName);
		cout << "[" << setw(2) << i + 1 << "] " << fieldName << endl;
	}
	char message[OUTPUT_LENGTH] = "Option: ";
	inputNumberInRange(number, message, 1, QUANTITY_OF_FIELDS);
	number--;
}

void uiEnterModeOfSort(int &mode) {
	cout << "Choose sort mode" << endl;
	cout << setw(5) << "[1]" << "Sort ascending" << endl;
	cout << setw(5) << "[2]" << "Sort descending" << endl;
	char message[OUTPUT_LENGTH] = "Mode #: ";
	inputNumberInRange(mode, message, 1, 2);
}