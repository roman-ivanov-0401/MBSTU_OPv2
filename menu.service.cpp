#include <cstring>

#include "menu.service.h"

#include "input.ui.h"

#include "menu.module.h"
#include "addInformationFromCreatedTextFile.module.h"
#include "convertTheContentsOfTheTextFileToABinary.module.h"
#include "convertTheDatabaseToATextFile.module.h"
#include "createEntry.module.h"
#include "deleteAEntry.module.h"
#include "enterInformationFromCreatedBinaryFile.module.h"
#include "enterInformationWithKeyboard.module.h"
#include "exit.module.h"
#include "outputDataOnDisplay.module.h"
#include "outputDataToFile.module.h"
#include "printDataSortedByAverageMark.module.h"
#include "sort.module.h"
#include "updateEntry.module.h"

void getMenuPoints(MenuPoint points[QUANTITY_OF_MENU_POINTS]) {
	char outputs[QUANTITY_OF_MENU_POINTS][OUTPUT_LENGTH]{};
	strcpy_s(outputs[0], strlen("Enter information with keybord") + 1, "Enter information with keybord");
	strcpy_s(outputs[1], strlen("Enter information from created text file") + 1, "Enter information from created text file");
	strcpy_s(outputs[2], strlen("Enter information from created binary file") + 1, "Enter information from created binary file");
	strcpy_s(outputs[3], strlen("Output data on display") + 1, "Output data on display");
	strcpy_s(outputs[4], strlen("Output data to file") + 1, "Output data to file");
	strcpy_s(outputs[5], strlen("Print data sorted by average mark") + 1, "Print data sorted by average mark");
	strcpy_s(outputs[6], strlen("Convert the database to a text file") + 1, "Convert the database to a text file");
	strcpy_s(outputs[7], strlen("Convert the contents of the text file to a binary") + 1, "Convert the contents of the text file to a binary");
	strcpy_s(outputs[8], strlen("Create a entry") + 1, "Create a entry");
	strcpy_s(outputs[9], strlen("Update a entry") + 1, "Update a entry");
	strcpy_s(outputs[10], strlen("Delete a entry") + 1, "Delete a entry");
	strcpy_s(outputs[11], strlen("Sort") + 1, "Sort");
	strcpy_s(outputs[12], strlen("Exit") + 1, "Exit");



	void (*modules[QUANTITY_OF_MENU_POINTS])(Storage & storage) {
		moduleEnterInformationWithKeyboard,
		moduleAddInformationFromCreatedTextFile,
		moduleEnterInformationFromCreatedBinaryFile,
		moduleOutputDataOnDisplay,
		moduleOutputDataToFile,
		modulePrintDataSortedByAverageMark,
		moduleConvertTheDatabaseToATextFile,
		moduleConvertTheContentsOfTheTextFileToABinary,
		moduleCreateEntry,
		moduleUpdateEntry,
		moduleDeleteAEntry,
		moduleSort,
		moduleExit
	};

	for (int i = 0; i < QUANTITY_OF_MENU_POINTS; i++) {
		points[i].number = i + 1;
		strcpy_s(points[i].name, outputs[i]);
		points[i].module = modules[i];
	}
}