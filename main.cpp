#include "settings.h"
#include "menu.module.h"
#include "storage.service.h"

using namespace std;


int main() {
	Storage storage{};
	prepareConsole();
	moduleMenu(storage);
	return 0;
}