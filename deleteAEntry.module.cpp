#include "deleteAEntry.module.h"

#include "storage.service.h"

#include "deleteAnEntry.ui.h"
#include "console.ui.h"
#include "table.ui.h"
#include "input.ui.h"

void moduleDeleteAEntry(Storage& storage) {
	uiClearConsole();
	uiDeleteEntryHearder();
	uiDrawDatadase(storage);
	int option{};
	uiEnterOptionForDelete(option);
	if (option == 1) {
		Field request[QUANTITY_OF_FIELDS]{};
		initFields(request);
		uiClearConsole();
		uiEnterRequestForSearch(request);

		uiClearConsole();

		Student* foundStudent = findEntryByRequest(storage, request);

		if (foundStudent->_id != 0) {
			deleteAnEntry(storage, foundStudent->_id);
		}
		else {
			uiNotFoundForDelete();
			uiPauseConsole();
		}
	}
	else {
		int _id{};
		uiClearConsole();
		uiEnterIdForDelete(_id);
		Student* foundStudent = findEntryById(storage, _id);
		if (foundStudent->_id != 0)
			deleteAnEntry(storage, foundStudent->_id);
		else {
			uiNotFoundForDelete();
			uiPauseConsole();
		}
	}
	uiClearConsole();
	uiDrawDatadase(storage);
	uiPauseConsole();
}