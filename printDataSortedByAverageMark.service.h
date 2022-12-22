#pragma once
#include "storage.service.h"

bool compareByAverageMark(Student student1, Student student2, int mode);
int partOfSortByAverageMark(Storage& storage, int left, int right, int mode);
void sortDatabaseByAverageMark(Storage& storage, int mode);
void sortDatabaseByAverageMarkSE(Storage& storage, int start, int end, int mode);