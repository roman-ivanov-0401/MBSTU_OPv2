#include <iostream>
#include "string.h"

using namespace std;



void inputNumberFieldOfEntry(int &number) {
	bool isNumber = true;
	String buffer{};
	do {
		enterString(buffer);
		for (int i = 0; i < buffer.length; i++) {
			if (buffer.value[i] < 48 || buffer.value[i] > 57) {
				isNumber = false;
				break;
			}
		}
	} while (!isNumber);
	number = atoi(buffer.value);
}

void inputStringFieldOfEntry() {

}