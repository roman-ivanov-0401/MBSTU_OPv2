#pragma once
#include "input.ui.h"
#include "storage.service.h"

const int FIELDS_WIDTHS[QUANTITY_OF_FIELDS + 1] =
{ 5, 11, 11, 10, 6, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

struct FieldConfig {
	char data[OUTPUT_LENGTH];
	int width;
	int heigth;
};

struct RowConfig
{
	FieldConfig fieldConfigs[QUANTITY_OF_FIELDS + 1];
	int quantityOfFields;
	int heigth;
};

struct TableConfig {
	RowConfig headerConfig;
	RowConfig* rowConfigs;
	int quantityOfRows;
};

void drawField(FieldConfig, bool, int);
void drawHorizontalDivider(RowConfig);
void drawRow(RowConfig);
void drawHeader(RowConfig);
void drawTable(TableConfig);
void uiDrawDatadase(Storage&);