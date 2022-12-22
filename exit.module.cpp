#include <stdlib.h>

#include "exit.module.h"

#include "storage.service.h"
#include "exit.ui.h"
#include "console.ui.h"

void moduleExit(Storage& storage) {
	int option{};
	uiClearConsole();
	uiDoYouReallyWantToExit(option);
	if (option == 1) {
		exit(0);
	}
}