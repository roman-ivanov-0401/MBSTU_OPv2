#include "updateEntry.module.h"

#include "storage.service.h"
#include "table.ui.h"
#include "updateEntry.ui.h"
#include "console.ui.h"
#include "input.ui.h"

void moduleUpdateEntry(Storage& storage) {
	uiClearConsole();
	uiUpdateEntryHearder();
	uiDrawDatadase(storage);
	int option{};
	uiEnterOption(option);
	if (option == 1) {
		Field request[QUANTITY_OF_FIELDS]{};
		initFields(request);
		uiClearConsole();
		uiEnterRequestForSearch(request);
		uiClearConsole();
		Student* foundStudent = findEntryByRequest(storage, request);

		if (foundStudent->_id != 0) {
			Field dataToUpdate[QUANTITY_OF_FIELDS]{};
			initFields(dataToUpdate);
			uiEnterDataToUpdateAnEntry(dataToUpdate);
			updateEntry(storage, foundStudent->_id, dataToUpdate);
		}
		else {
			uiNotFound();
		}
	}
	else {
		int _id{};
		uiClearConsole();
		uiEnterId(_id);
		Student * foundStudent = findEntryById(storage, _id);
		if (foundStudent->_id != 0) {
			Field dataToUpdate[QUANTITY_OF_FIELDS]{};
			initFields(dataToUpdate);
			uiClearConsole();
			uiEnterDataToUpdateAnEntry(dataToUpdate);
			updateEntry(storage, foundStudent->_id, dataToUpdate);
		}
		uiNotFound();
	}
	uiClearConsole();
	uiDrawDatadase(storage);
	uiPauseConsole();
}