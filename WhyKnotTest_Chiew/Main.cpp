#include "AllHeaderFile.h"

int main()
{
	//Adjust Console Size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1200, 900, TRUE); //set the size

	srand(time(NULL));
	GameSystem* gs = new GameSystem();

	delete gs; //free the memory

	return 0;
}