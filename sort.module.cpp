#include "sort.module.h"

#include "storage.service.h"
#include "input.ui.h"
#include "sort.ui.h"
#include "sort.service.h"
#include "console.ui.h"
#include "table.service.h"


void moduleSort(Storage& storage) {
	uiClearConsole();
	int numberOfField{};
	uiShowSortHeader();
	uiEnterNumberOfField(numberOfField);
	uiClearConsole();
	int mode{};
	uiEnterModeOfSort(mode);
	sortDatabase(storage, numberOfField, mode);
	uiClearConsole();
	uiDrawDatadase(storage);
	uiPauseConsole();
}