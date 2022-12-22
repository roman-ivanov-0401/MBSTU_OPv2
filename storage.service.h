#pragma once
const int FIELD_LENGTH = 256;
const int QUANTITY_OF_FIELDS = 15;

enum FIELD_NAMES {
	FIELD_SURNAME,
	FIELD_NAME,
	FIELD_MIDDLENAME,
	FIELD_COURSE,
	FIELD_YEAR_OF_BIRTH,
	FIELD_FIRST_SUBJECT_NAME,
	FIELD_FIRST_SUBJECT_MARK,
	FIELD_SECOND_SUBJECT_NAME,
	FIELD_SECOND_SUBJECT_MARK,
	FIELD_THIRD_SUBJECT_NAME,
	FIELD_THIRD_SUBJECT_MARK,
	FIELD_FOURTH_SUBJECT_NAME,
	FIELD_FOURTH_SUBJECT_MARK,
	FIELD_FIFTH_SUBJECT_NAME,
	FIELD_FIFTH_SUBJECT_MARK,
};
enum Types {
	NUMBER,
	STRING
};

struct Field {
	Types type;
	char value[FIELD_LENGTH];
};

struct Student
{
	int _id;
	Field fields[QUANTITY_OF_FIELDS];
};

struct Storage {
	Student *entries;
	int length;
};

void getFieldName(int, char [FIELD_LENGTH]);
void addAEntryToStorage(Storage&, Field [QUANTITY_OF_FIELDS], int);
void emptyStorage(Storage& storage);
Student* findEntryById(Storage& storage, int _id);
Student* findEntryByRequest(Storage& storage, Field request[QUANTITY_OF_FIELDS]);
void updateEntry(Storage& storage, int _id, Field fields[QUANTITY_OF_FIELDS]);
void initFields(Field fields[QUANTITY_OF_FIELDS]);
void deleteAnEntry(Storage& storage, int _id);