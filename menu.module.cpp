#include "menu.module.h"

#include "menu.service.h"

#include "menu.ui.h"

#include "storage.service.h"

void moduleMenu(Storage& storage) {
	MenuPoint menuPoints[QUANTITY_OF_MENU_POINTS];
	getMenuPoints(menuPoints);

	int option;
	do {
		uiMenuOptions(option, menuPoints);
		menuPoints[option - 1].module(storage);
		option = 0;
	} while (option >= ENTER_INFORMATION_WITH_KEYBOARD || option <= EXIT);
}