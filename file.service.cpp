#include <fstream>
#include <iostream>

#include "file.service.h"

#include "storage.service.h"

using namespace std;

void outputEntryToTextFile(Student student, ofstream &fout) {
	fout << student._id;
	fout << "\n";
	for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
		fout << student.fields[i].type << " " << student.fields[i].value;
		fout << "\n";
	}
}

void outputDatabaseToTextFile(Storage &storage){
	ofstream fout(TEXT_FILE_NAME);
	if (fout.is_open()) {
		fout << storage.length;
		fout << "\n";
		for (int i = 0; i < storage.length; i++) {
			outputEntryToTextFile(storage.entries[i], fout);
		}
	}
	else {
		cout << "Wrong opening file" << endl;
	}
	fout.close();
}

void inputFieldFromTheTextFile(Field &field, ifstream& fin) {
	char typeStr[FIELD_LENGTH]{};
	fin >> typeStr;
	if (atoi(typeStr) == NUMBER) field.type = NUMBER;
	else field.type = STRING;
	fin.getline(field.value, FIELD_LENGTH);

}

void inputEntryFromTheTextFile(Student &student, ifstream &fin) {
	char _idStr[FIELD_LENGTH]{};
	fin >> _idStr;
	student._id = atoi(_idStr);
	for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
		inputFieldFromTheTextFile(student.fields[i], fin);
	}
}

void inputDatabaseFromTheTextFile(Storage &storage) {
	ifstream fin(TEXT_FILE_NAME);

	if (fin.is_open()) {
		char lengthStr[FIELD_LENGTH]{};
		fin >> lengthStr;

		emptyStorage(storage);
		storage.length = atoi(lengthStr);
		Student* newEntries = new Student[storage.length];
		storage.entries = newEntries;
		for (int i = 0; i < storage.length; i++) {
			if (!fin.eof()) {
				inputEntryFromTheTextFile(storage.entries[i], fin);
			}
		}
	}
	else {
		cout << "File does not exist!" << endl;
	}

	fin.close();
}

void createBinaryFileBasedOnText() {
	ofstream binfout(BINARY_FILE_NAME, ios::out | ios::binary);

	if (binfout.is_open()) {
			Storage tempStorage{};
			inputDatabaseFromTheTextFile(tempStorage);
			binfout.write((char*)&tempStorage.length, sizeof(tempStorage.length));
			for (int i = 0; i < tempStorage.length; i++) {
				//outputEntryToBinaryFile(tempStorage.entries[i], binfout);
				binfout.write((char*)&tempStorage.entries[i], sizeof(tempStorage.entries[i]));
			}
	}
	else {
		cout << "Error opening binary file" << endl;
	}

	binfout.close();
}

void inputDatabaseFromBinaryFile(Storage &storage) {
	ifstream binfin(BINARY_FILE_NAME, ios::in | ios::binary);
	binfin.read((char*)&storage.length, sizeof(storage.length));
	Student* newEntries = new Student[storage.length];
	delete[] storage.entries;
	storage.entries = newEntries;
	if (binfin.is_open()) {
		for (int i = 0; i < storage.length; i++) {
			binfin.read((char*)&storage.entries[i], sizeof(storage.entries[i]));
		}
	}
	else {
		cout << "Binary file does not exist" << endl;
	}
	binfin.close();
}