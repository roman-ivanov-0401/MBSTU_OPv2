#include "outputDataOnDisplay.module.h"

#include "storage.service.h"

#include "table.ui.h"
#include "console.ui.h"

using namespace std;

void moduleOutputDataOnDisplay(Storage& storage) {
	uiClearConsole();
	uiDrawDatadase(storage);
	uiPauseConsole();
}