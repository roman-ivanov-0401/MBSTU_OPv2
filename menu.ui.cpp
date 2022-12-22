#include <iostream>
#include <iomanip>
#include <windows.h>

#include "menu.ui.h"

#include "menu.module.h"

#include "input.ui.h"

using namespace std;

void uiEnterMenuOption(int& option) {
	int chosenPoint = option;
	char message[OUTPUT_LENGTH] = "Enter option: ";
	char errorMessage[OUTPUT_LENGTH] = "Wrong value. Try again: ";
	inputNumber(chosenPoint, message);
	while (
		chosenPoint < ENTER_INFORMATION_WITH_KEYBOARD ||
		chosenPoint > EXIT)
	{
		cout << "The option does not exits" << endl;
		inputNumber(chosenPoint, message);
	}
	option = chosenPoint;
}

void uiMenuOptions(
	int &option,

	MenuPoint menuPoints[QUANTITY_OF_MENU_POINTS]
) {

	system("cls");
	cout << "-----------------DATABASE MENU-----------------" << endl;

	for (int i = ENTER_INFORMATION_WITH_KEYBOARD - 1; i <= EXIT - 1; i++) {
		Sleep(10);
		cout << "[" << menuPoints[i].number << setw(1 + int(!bool((i + 1) / 10))) << "]" << "   " << menuPoints[i].name << endl;

	}
	uiEnterMenuOption(option);
}