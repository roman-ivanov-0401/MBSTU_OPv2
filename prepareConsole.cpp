#include <windows.h>

void prepareConsole() {
	HWND hWindowConsole = GetConsoleWindow();
	RECT r;
	GetWindowRect(hWindowConsole, &r);
	MoveWindow(hWindowConsole, 0, 50, 1550, 800, TRUE);
}