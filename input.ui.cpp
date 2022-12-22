#include <iostream>
#include <iomanip>
#include <cstring>

#include "input.ui.h"

#include "errorMessages.ui.h"

#include "storage.service.h"

using namespace std;

void inputString(
	char str[FIELD_LENGTH],
	char message[OUTPUT_LENGTH]
) {
	cout << message;
	cin.getline(str, FIELD_LENGTH);
}

void inputNumber(
	int& number, 
	char message[OUTPUT_LENGTH]
) {
	char buffer[FIELD_LENGTH]{};
	bool isNumber{};
	cout << message;
	
	do {
		isNumber = true;
		cin.getline(buffer, FIELD_LENGTH);
		for (int i = 0; i < strlen(buffer); i++) {
			if (buffer[i] < 48 || buffer[i] > 57) {
				isNumber = false;
				break;
			}
		}
		if (!isNumber) {
			cout << NOT_A_NUMBER_ERROR_MESSAGE;
		}
	} while (!isNumber);

	number = atoi(buffer);
}

void inputNumberInRange(
	int& number,
	char message[OUTPUT_LENGTH],
	int min,
	int max
)
{
	inputNumber(number, message);
	while (number < min || number > max) {
		cout << NOT_A_NUMBER_IN_RANGE_ERROR_MESSAGE << endl;
		inputNumber(number, message);
	}
}

void inputNumberField(Field& field, int min, int max, char message[FIELD_LENGTH]) {
	int number{};
	inputNumberInRange(number, message, min, max);
	_itoa_s(number, field.value, 10);
}

void uiEnterDataToCreateAnEntry(Field fields[QUANTITY_OF_FIELDS]) {
	cout << "--- CREATE AN ENTRY ---" << endl;
	for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
		char message[OUTPUT_LENGTH] = "Enter ";
		char fieldName[FIELD_LENGTH]{};
		getFieldName(i, fieldName);
		fieldName[0] += 32;
		strcat_s(message, fieldName);
		strcat_s(message, ": ");
		if (fields[i].type == NUMBER) {
			if (i == 3) {
				inputNumberField(fields[i], 1, 6, message);
			}
			else if (i == 4) {
				inputNumberField(fields[i], 1903, 2022, message);

			}
			else if (i >= 6 && i % 2 == 0) {
				inputNumberField(fields[i], 1, 5, message);
			}
			else{
				inputNumberField(fields[i], _I16_MIN, _I16_MAX, message);
			}

		}
		else {
			inputString(fields[i].value, message);
		}
	}

}

void uiEnterDataToUpdateAnEntry(Field updates[QUANTITY_OF_FIELDS]) {
	for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
		char fieldName[FIELD_LENGTH]{};
		getFieldName(i, fieldName);
		fieldName[0] += 32;
		int option{};
		cout << "Do you want to update " << fieldName << "?" << endl;
		cout << setw(5) << "[1]" << " Yes" << endl;
		cout << setw(5) << "[2]" << " No" << endl;
		char message[OUTPUT_LENGTH] = "Enter option: ";
		char messageForField[OUTPUT_LENGTH] = "Enter value of the field: ";
		inputNumberInRange(option, message, 1, 2);
		if (option == 1) {
			if (updates[i].type == NUMBER) {
				if (i == 3) {
					inputNumberField(updates[i], 1, 6, messageForField);
				}
				else if (i == 4) {
					inputNumberField(updates[i], 1903, 2022, messageForField);

				}
				else if (i >= 6 && i % 2 == 0) {
					inputNumberField(updates[i], 1, 5, messageForField);
				}
				else {
					inputNumberField(updates[i], _I16_MIN, _I16_MAX, messageForField);
				}

			}
			else {
				inputString(updates[i].value, messageForField);
			}
		}
	}
}

void uiEnterRequestForSearch(Field request[QUANTITY_OF_FIELDS]) {
	for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
		char fieldName[FIELD_LENGTH]{};
		getFieldName(i, fieldName);
		fieldName[0] += 32;
		int option{};
		cout << "Do you want to add " << fieldName << " to the search request?" << endl;
		cout << setw(5) << "[1]" << " Yes" << endl;
		cout << setw(5) << "[2]" << " No" << endl;
		char message[OUTPUT_LENGTH] = "Enter option: ";
		char messageForField[OUTPUT_LENGTH] = "Enter value of the field: ";

		inputNumberInRange(option, message, 1, 2);
		if (option == 1) {
			if (request[i].type == NUMBER) {
				if (i == 3) {
					inputNumberField(request[i], 1, 6, messageForField);
				}
				else if (i == 4) {
					inputNumberField(request[i], 1903, 2022, messageForField);

				}
				else if (i >= 6 && i % 2 == 0) {
					inputNumberField(request[i], 1, 5, messageForField);
				}
				else {
					inputNumberField(request[i], _I16_MIN, _I16_MAX, messageForField);
				}

			}
			else {
				inputString(request[i].value, messageForField);
			}
		}
	}
}