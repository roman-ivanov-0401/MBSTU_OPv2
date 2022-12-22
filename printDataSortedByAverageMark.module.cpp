#include "printDataSortedByAverageMark.module.h"

#include "storage.service.h"

#include "printDataSortedByAverageMark.service.h"
#include "printDataSortedByAverageMark.ui.h"
#include "table.ui.h"
#include "console.ui.h"

void modulePrintDataSortedByAverageMark(Storage& storage) {
	uiClearConsole();
	uiShowPrintDataByAverageMarkHeader();
	Storage storageToSort = storage;
	int mode{};
	uiEnterMode(mode);
	uiClearConsole();
	sortDatabaseByAverageMark(storageToSort, mode);
	uiDrawDatadase(storageToSort);
	uiPauseConsole();
}