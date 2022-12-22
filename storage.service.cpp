#include <iostream>
#include <ctime>
#include <cstring>

#include "storage.service.h"

using namespace std;

void getFieldName(int field, char str[FIELD_LENGTH]) {
	switch (field) {

	case FIELD_SURNAME:
		strcpy_s(str, strlen("Surname") + 1, "Surname");
		break;

	case FIELD_NAME:
		strcpy_s(str, strlen("Name") + 1, "Name");
		break;

	case FIELD_MIDDLENAME:
		strcpy_s(str, strlen("Middlename") + 1, "Middlename");
		break;

	case FIELD_YEAR_OF_BIRTH:
		strcpy_s(str, strlen("Year of birth") + 1, "Year of birth");
		break;

	case FIELD_COURSE:
		strcpy_s(str, strlen("Course") + 1, "Course");
		break;

	case FIELD_FIRST_SUBJECT_NAME:
		strcpy_s(str, strlen("First subject name") + 1, "First subject name");
		break;

	case FIELD_FIRST_SUBJECT_MARK:
		strcpy_s(str, strlen("First subject mark") + 1, "First subject mark");
		break;

	case FIELD_SECOND_SUBJECT_NAME:
		strcpy_s(str, strlen("Second subject name") + 1, "Second subject name");
		break;

	case FIELD_SECOND_SUBJECT_MARK:
		strcpy_s(str, strlen("Second subject mark") + 1, "Second subject mark");
		break;

	case FIELD_THIRD_SUBJECT_NAME:
		strcpy_s(str, strlen("Third subject name") + 1, "Third subject name");
		break;

	case FIELD_THIRD_SUBJECT_MARK:
		strcpy_s(str, strlen("Third subject mark") + 1, "Third subject mark");
		break;

	case FIELD_FOURTH_SUBJECT_NAME:
		strcpy_s(str, strlen("Fourth subject name") + 1, "Fourth subject name");
		break;

	case FIELD_FOURTH_SUBJECT_MARK:
		strcpy_s(str, strlen("Fourth subject mark") + 1, "Fourth subject mark");
		break;

	case FIELD_FIFTH_SUBJECT_NAME:
		strcpy_s(str, strlen("Fifth subject name") + 1, "Fifth subject name");
		break;

	case FIELD_FIFTH_SUBJECT_MARK:
		strcpy_s(str, strlen("Fifth subject mark") + 1, "Fifth subject mark");
		break;
	};
}

int generateId() {
	srand(time(NULL));
	return rand();
}

void initFields(Field fields[QUANTITY_OF_FIELDS]) {
	fields[0].type = STRING;
	fields[1].type = STRING;
	fields[2].type = STRING;
	fields[3].type = NUMBER;
	fields[4].type = NUMBER;
	fields[5].type = STRING;
	fields[6].type = NUMBER;
	fields[7].type = STRING;
	fields[8].type = NUMBER;
	fields[9].type = STRING;
	fields[10].type = NUMBER;
	fields[11].type = STRING;
	fields[12].type = NUMBER;
	fields[13].type = STRING;
	fields[14].type = NUMBER;
}

void addAEntryToStorage(
	Storage& storage,
	Field studentData[QUANTITY_OF_FIELDS],
	int position
) {

	Student* newEntries = new Student[storage.length + 1];
	bool isAdded = false;
	for (int i = 0; i < storage.length + 1; i++) {
		if (i == position) {
			newEntries[i]._id = generateId();
			memcpy_s(
				newEntries[i].fields,
				QUANTITY_OF_FIELDS * sizeof Field,
				studentData,
				QUANTITY_OF_FIELDS * sizeof Field
			);
			isAdded = true;

		}
		else if (isAdded) {
			newEntries[i] = storage.entries[i - 1];
		}
		else {
			newEntries[i] = storage.entries[i];
		}
	}
	if (storage.length > 0) {
		delete[] storage.entries;
	}
	storage.length++;
	storage.entries = newEntries;

}

void emptyStorage(Storage &storage) {
	if (storage.length > 0) {
		delete[] storage.entries;
		Student* newMemory = new Student[0];
		storage.entries = newMemory;
		storage.length = 0;
	}
}

bool compareFieldsForRequest(Field field1, Field field2) {
	return 
		!bool(strcmp(field1.value, field2.value))
		||
		!bool(strcmp(field1.value, ""));
}

Student* findEntryById(Storage& storage, int _id) {
	for (int i = 0; i < storage.length; i++) {
		if (storage.entries[i]._id == _id) return &storage.entries[i];
	}
	Student badResponse{};
	return &badResponse;
}

Student* findEntryByRequest(Storage& storage, Field request[QUANTITY_OF_FIELDS]) {
	for (int i = 0; i < storage.length; i++) {
		bool flag = true;
		for (int j = 0; j < QUANTITY_OF_FIELDS; j++) {
			if (!compareFieldsForRequest(request[j], storage.entries[i].fields[j])) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return &storage.entries[i];
		}
	}
	Student badResponse{};
	return &badResponse;
}

void updateEntry(Storage& storage, int _id, Field fields[QUANTITY_OF_FIELDS]) {
	for (int i = 0; i < storage.length; i++) {
		if (storage.entries[i]._id == _id) {
			for (int j = 0; j < QUANTITY_OF_FIELDS; j++) {
				if (fields[j].value != "") {
					strcpy_s(
						storage.entries[i].fields[j].value,
						strlen(fields[j].value) + 1,
						fields[j].value);
				}
			}
		}
	}
}

void deleteAnEntry(Storage& storage, int _id) {
	Student* newStore = new Student[storage.length - 1];
	bool isDeleted = false;

	for (int i = 0; i < storage.length; i++) {
		if (storage.entries[i]._id == _id) {
			isDeleted = true;
		}
		else if (isDeleted) {
			newStore[i - 1] = storage.entries[i];
		}
		else {
			newStore[i] = storage.entries[i];
		}
	}
	delete[] storage.entries;
	storage.entries = newStore;

	storage.length--;
}