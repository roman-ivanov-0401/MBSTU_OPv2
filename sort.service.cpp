#include <iostream>
#include <cstring>

#include "sort.service.h"

#include "storage.service.h"

using namespace std;

bool compareStrings(char str1[FIELD_LENGTH], char str2[FIELD_LENGTH]) {
	for (int i = 0; i < FIELD_LENGTH; i++) {
		if (tolower(str1[i]) > tolower(str2[i])) return true;
		if (tolower(str1[i]) < tolower(str2[i])) return false;
	}
	return false;
}

bool compareStudentsByField(Student student1, Student student2, int numberOfField, int mode) {

	if (student1.fields[numberOfField].type == NUMBER) {
		return
			mode == 1 ?
			atoi(student1.fields[numberOfField].value) > atoi(student2.fields[numberOfField].value) :
			atoi(student1.fields[numberOfField].value) < atoi(student2.fields[numberOfField].value);
	}
	else {
		return mode == 1 ?
			compareStrings(student1.fields[numberOfField].value, student2.fields[numberOfField].value) :
			compareStrings(student2.fields[numberOfField].value, student1.fields[numberOfField].value);
	}
}

int partOfSort(
	Storage& storage,
	int numberOfField,
	int left,
	int right,
	int mode
) 
{
	Student pivot = storage.entries[(left + right) / 2];
	while (left <= right) {
		while (compareStudentsByField(pivot, storage.entries[left], numberOfField, mode)) left++;
		while (compareStudentsByField(storage.entries[right], pivot, numberOfField, mode)) right--;
		if (left <= right) {
			Student temp = storage.entries[left];
			storage.entries[left] = storage.entries[right];
			storage.entries[right] = temp;
			left++;
			right--;
		}
	}
	return left;
	
}

void sortDatabase
(
	Storage& storage,
	int numberOfField,
	int mode
)
{
	sortDatabaseSE(storage, numberOfField, 0, storage.length - 1, mode);
}

void sortDatabaseSE
(
	Storage& storage,
	int numberOfField,
	int start,
	int end,
	int mode
) 
{
	if (start >= end) return;
	int rightStart = partOfSort(storage, numberOfField, start, end, mode);
	sortDatabaseSE(storage, numberOfField, start, rightStart - 1, mode);
	sortDatabaseSE(storage, numberOfField, rightStart, end, mode);
}

