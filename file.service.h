#pragma once
#include "storage.service.h"

const char TEXT_FILE_NAME[] = "database.txt";
const char BINARY_FILE_NAME[] = "database.bin";

void outputDatabaseToTextFile(Storage& storage);
void inputDatabaseFromTheTextFile(Storage& storage);
void createBinaryFileBasedOnText();
void inputDatabaseFromBinaryFile(Storage& storage);