#include "enterInformationWithKeyboard.module.h"

#include "storage.service.h"

#include "enterInformationWithKeyboard.ui.h"
#include "input.ui.h"
#include "console.ui.h"
#include "table.ui.h"


void moduleEnterInformationWithKeyboard(Storage& storage) {
	uiClearConsole();
	int numberOfEntries{};
	uiInputQuantityOfNewEntries(numberOfEntries);
	emptyStorage(storage);
	for (int i = 0; i < numberOfEntries; i++) {
		Field fieldsOfNewEnrty[QUANTITY_OF_FIELDS]{};
		initFields(fieldsOfNewEnrty);
		uiClearConsole();
		uiEnterDataToCreateAnEntry(fieldsOfNewEnrty);
		addAEntryToStorage(storage, fieldsOfNewEnrty, i);
	}
	uiClearConsole();

	uiDrawDatadase(storage);
	uiPauseConsole();
}