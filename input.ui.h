#pragma once
#include "storage.service.h"

const int OUTPUT_LENGTH = 256;

void inputString(char str[FIELD_LENGTH], char message[OUTPUT_LENGTH]);
void inputNumber(int& number, char message[OUTPUT_LENGTH]);
void inputNumberInRange(
	int& number,
	char message[OUTPUT_LENGTH],
	int min,
	int max
);
void uiEnterDataToCreateAnEntry(Field fields[QUANTITY_OF_FIELDS]);
void uiEnterRequestForSearch(Field request[QUANTITY_OF_FIELDS]);
void uiEnterDataToUpdateAnEntry(Field updates[QUANTITY_OF_FIELDS]);