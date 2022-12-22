#include "convertTheContentsOfTheTextFileToABinary.module.h"

#include "storage.service.h"
#include "console.ui.h"
#include "file.service.h"
#include "convertTheContentsOfTheTextFileToABinary.ui.h"

void moduleConvertTheContentsOfTheTextFileToABinary(Storage& storage) {
	uiClearConsole();
	uiShowConvertTheContentsOfTheTextFileToABinaryHeader();
	createBinaryFileBasedOnText();
	uiSuccessfullyConvertTheContentsOfTheTextFileToABinary();
	uiPauseConsole();
}