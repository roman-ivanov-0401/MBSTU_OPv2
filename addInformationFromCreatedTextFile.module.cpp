#include <fstream>

#include "addInformationFromCreatedTextFile.module.h"
#include "file.service.h"
#include "storage.service.h"
#include "addInformationFromCreatedTextFile.ui.h"
#include "input.ui.h"
#include "console.ui.h"

using namespace std;

void moduleAddInformationFromCreatedTextFile(Storage& storage) {
	uiClearConsole();
	uiShowAddInformationFromCreatedTextFileHeader();
	inputDatabaseFromTheTextFile(storage);
	uiAddedSuccessfully();
	uiPauseConsole();
}