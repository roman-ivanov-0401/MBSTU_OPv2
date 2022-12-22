#include <iostream>
#include <iomanip>

#include "printDataSortedByAverageMark.ui.h"

#include "input.ui.h"

using namespace std;

void uiShowPrintDataByAverageMarkHeader() {
	cout << "--- PRINT DATA BY AVERAGE MARK ---" << endl;
}

void uiEnterMode(int &mode) {
	cout << "Choose sort mode" << endl;
	cout << setw(5) << "[1]" << "Sort ascending" << endl;
	cout << setw(5) << "[2]" << "Sort descending" << endl;
	char message[OUTPUT_LENGTH] = "Mode #: ";
	inputNumberInRange(mode, message, 1, 2);
}