#include "convertTheDatabaseToATextFile.module.h"

#include "storage.service.h"
#include "convertTheDatabaseToATextFile.ui.h"
#include "file.service.h"
#include "console.ui.h"

void moduleConvertTheDatabaseToATextFile(Storage& storage) {
	uiClearConsole();
	uiDrawConvertTheDatabaseToATextFileHeader();
	outputDatabaseToTextFile(storage);
	uiOutputSuccesully();
	uiPauseConsole();
}