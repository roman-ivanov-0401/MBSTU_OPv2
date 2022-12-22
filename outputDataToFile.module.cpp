#include "outputDataToFile.module.h"

#include "storage.service.h"
#include "outputDataToFile.ui.h"
#include "console.ui.h"
#include "input.ui.h"
#include "file.service.h"

void moduleOutputDataToFile(Storage& storage) {
	uiClearConsole();
	Storage tempStorage{};
	int length{};
	emptyStorage(tempStorage);
	uiEnterQuantityOfEntriesToOutputTextFile(length);
	for (int i = 0; i < length; i++) {
		Field fieldsOfNewEnrty[QUANTITY_OF_FIELDS]{};
		initFields(fieldsOfNewEnrty);
		uiClearConsole();
		uiEnterDataToCreateAnEntry(fieldsOfNewEnrty);
		addAEntryToStorage(tempStorage, fieldsOfNewEnrty, i);
	}

	outputDatabaseToTextFile(tempStorage);
	delete[] tempStorage.entries;
	uiSuccessfullyOutput();
	uiPauseConsole();
}