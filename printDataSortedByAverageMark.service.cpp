#include <iostream>

#include "printDataSortedByAverageMark.service.h"

#include "storage.service.h"

using namespace std;


bool compareByAverageMark(Student student1, Student student2, int mode) {
	int sumsOfMarks[2]{};

	for (int i = 6; i < QUANTITY_OF_FIELDS; i += 2) {
		int mark1 = atoi(student1.fields[i].value);
		sumsOfMarks[0] += mark1;

		int mark2 = atoi(student2.fields[i].value);
		sumsOfMarks[1] += mark2;

	}
	
	return mode == 1 ? sumsOfMarks[0] > sumsOfMarks[1] : sumsOfMarks[0] < sumsOfMarks[1];
}

int partOfSortByAverageMark
(
	Storage& storage,
	int left,
	int right,
	int mode
) {
	Student pivot = storage.entries[(left + right) / 2];
	while (left <= right) {
		while (compareByAverageMark(pivot, storage.entries[left], mode)) left++;
		while (compareByAverageMark(storage.entries[right], pivot, mode)) right--;
		if (left <= right) {
			Student temp = storage.entries[left];
			storage.entries[left] = storage.entries[right];
			storage.entries[right] = temp;
			left++;
			right--;
		}
	}
	return left;
};

void sortDatabaseByAverageMark
(
	Storage& storage,
	int mode
)
{
	sortDatabaseByAverageMarkSE(storage, 0, storage.length - 1, mode);
}

void sortDatabaseByAverageMarkSE
(
	Storage& storage,
	int start,
	int end,
	int mode
)
{
	if (start >= end) return;
	int rightStart = partOfSortByAverageMark(storage, start, end, mode);
	sortDatabaseByAverageMarkSE(storage, start, rightStart - 1, mode);
	sortDatabaseByAverageMarkSE(storage, rightStart, end, mode);
}