#pragma once
#include "storage.service.h"

bool compareStudentsByField(Student student1, Student student2, int numberOfField, int mode);
int partOfSort(Storage& storage, int numberOfField, int left, int right, int mode);
void sortDatabase(Storage& storage, int numberOfField, int mode);
void sortDatabaseSE(Storage& storage, int numberOfField, int start, int end, int mode);
bool compareStrings(char str1[FIELD_LENGTH], char str2[FIELD_LENGTH]);