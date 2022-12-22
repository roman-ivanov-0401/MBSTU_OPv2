#include "createEntry.module.h"

#include "storage.service.h"

#include "input.ui.h"
#include "console.ui.h"
#include "createEntry.ui.h"
#include "table.ui.h"

void moduleCreateEntry(Storage& storage) {
	int position{};
	uiClearConsole();
	uiInputPosition(position, storage.length);
	Field entryFields[QUANTITY_OF_FIELDS]{};
	initFields(entryFields);
	uiClearConsole();
	uiEnterDataToCreateAnEntry(entryFields);
	uiClearConsole();
	addAEntryToStorage(storage, entryFields, position);
	uiDrawDatadase(storage);
	uiPauseConsole();
}