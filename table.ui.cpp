#include <iostream>

#include "table.ui.h"

#include "table.service.h"
#include "storage.service.h"

using namespace std;

void drawField(FieldConfig config, bool isFirst, int offset) {

	if (isFirst) {
		cout << "|";
	}
	for (int i = 0; i < config.width; i++) {
		if (
			(config.data[offset * config.width + i] >= 65
			&& config.data[offset * config.width + i] <= 90)
				||
			(config.data[offset * config.width + i] >= 97
			&& config.data[offset * config.width + i] <= 122)
				||
			(config.data[offset * config.width + i] >= 48
			&& config.data[offset * config.width + i] <= 57)) {
			cout << config.data[offset * config.width + i];
		}
		else {
			cout << " ";
		}
	}
	cout << "|";

}

void drawHorizontalDivider(RowConfig config) {
	int sumOfWidth{};
	for (int i = 0; i < config.quantityOfFields; i++) {
		sumOfWidth += config.fieldConfigs[i].width;
	}
	cout << " ";
	for (int i = 0; i < sumOfWidth + config.quantityOfFields - 1; i++) {
		cout << "-";
	}
	cout << endl;

}

void drawRow(RowConfig config) {

	for (int i = 0; i < config.heigth; i++) {
		for (int j = 0; j < config.quantityOfFields; j++) {
			drawField(config.fieldConfigs[j], j == 0, i);
		}
		cout << endl;
	}
	drawHorizontalDivider(config);
}

void drawHeader(RowConfig config) {
	drawHorizontalDivider(config);
	drawRow(config);
}

void drawTable(TableConfig config) {

	drawHeader(config.headerConfig);
	for (int i = 0; i < config.quantityOfRows; i++) {
		drawRow(config.rowConfigs[i]);
	}
}

void uiDrawDatadase(Storage& storage) {
	TableConfig tableConfig{};
	generateTableConfig(tableConfig, storage);

	drawTable(tableConfig);
}
