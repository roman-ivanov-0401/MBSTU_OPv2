#include <iostream>
#include <cstring>
#include "string.h"

using namespace std;

void enterString(String &str) {
	char cstr[256];
	cin.getline(cstr, 256);
	str.value = cstr;
	str.length = strlen(cstr);
}