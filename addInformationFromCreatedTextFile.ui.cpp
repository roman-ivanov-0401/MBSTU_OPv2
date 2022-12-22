#include <iostream>

#include "addInformationFromCreatedTextFile.ui.h"

using namespace std;

void uiAddedSuccessfully() {
	cout << "Database has been entered from text file successfully" << endl;
}

void uiShowAddInformationFromCreatedTextFileHeader() {
	cout << "--- ADD INFORMATION FROM CREATED TEXT FILE ---" << endl;
}

void uiErrorOpeningFile() {
	cout << "Wrong opening file" << endl;
}