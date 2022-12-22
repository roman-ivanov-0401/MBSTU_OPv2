#include <iostream>
#include <cstring>

#include "storage.service.h"
#include "table.ui.h"

using namespace std;

void generateFieldConfig(
	FieldConfig& fieldConfig,
	char data[FIELD_LENGTH],
	int width
) {
	strcpy_s(
		fieldConfig.data,
		strlen(data) + 1,
		data);
	int fieldHeigth = strlen(fieldConfig.data) / width;
	fieldConfig.width = width;
	fieldConfig.heigth = strlen(data) / fieldConfig.width + 1;

}

void generateRowConfig(
	RowConfig& rowConfig,
	char fields[QUANTITY_OF_FIELDS + 1][FIELD_LENGTH],
	int quantityOfFileds
	) {
	rowConfig.quantityOfFields = QUANTITY_OF_FIELDS + 1;
	int maxRowHeigth = 1;

	for (int i = 0; i < QUANTITY_OF_FIELDS + 1; i++) {
		generateFieldConfig(rowConfig.fieldConfigs[i], fields[i], FIELDS_WIDTHS[i]);

		if (rowConfig.fieldConfigs[i].heigth > maxRowHeigth) maxRowHeigth = rowConfig.fieldConfigs[i].heigth;
	}

	if (maxRowHeigth > 1) {
		for (int i = 0; i < QUANTITY_OF_FIELDS; i++) {
			rowConfig.fieldConfigs[i].heigth = maxRowHeigth;
		}
	}

	rowConfig.heigth = maxRowHeigth;
}

void generateTableConfig(
	TableConfig& config,
	Storage& storage
)
{
	config.quantityOfRows = storage.length;

	RowConfig headerConfig{};
	char valuesOfHeaderFields[QUANTITY_OF_FIELDS + 1][FIELD_LENGTH]{};
	strcpy_s(valuesOfHeaderFields[0], strlen("Id") + 1, "Id");
	for (int i = 1; i <= FIELD_FIFTH_SUBJECT_MARK + 1; i++) {
		char valueOfHeaderField[FIELD_LENGTH]{};
		getFieldName(i - 1, valueOfHeaderField);
		strcpy_s(
			valuesOfHeaderFields[i],
			strlen(valueOfHeaderField) + 1,
			valueOfHeaderField
			);
	}


	generateRowConfig(headerConfig, valuesOfHeaderFields, QUANTITY_OF_FIELDS);

	config.headerConfig = headerConfig;

	RowConfig* rowConfigs = new RowConfig[config.quantityOfRows];
	for (int i = 0; i < config.quantityOfRows; i++) {
		char valuesOfFields[QUANTITY_OF_FIELDS + 1][FIELD_LENGTH]{};
		_itoa_s(storage.entries[i]._id, valuesOfFields[0], 10);


		for (int j = 1; j <= QUANTITY_OF_FIELDS; j++) {
			strcpy_s(
				valuesOfFields[j],
				strlen(storage.entries[i].fields[j - 1].value) + 1,
				storage.entries[i].fields[j - 1].value
			);
		}

		generateRowConfig(
			rowConfigs[i],
			valuesOfFields,
			QUANTITY_OF_FIELDS);
	}
	config.rowConfigs = rowConfigs;
}