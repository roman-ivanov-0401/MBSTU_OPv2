#include "enterInformationFromCreatedBinaryFile.module.h"

#include "storage.service.h"
#include "file.service.h"
#include "enterInformationFromCreatedBinaryFile.ui.h"
#include "console.ui.h"


void moduleEnterInformationFromCreatedBinaryFile(Storage& storage) {
	uiClearConsole();
	uiShowEnterInformationFromCreatedBinaryFileHeader();
	inputDatabaseFromBinaryFile(storage);
	uiShowSuccessfullyEnterInformationFromCreatedBinaryFile();
	uiPauseConsole();
}