
#include <iostream>
#include <stdlib.h>
#include "Game.h"

void ShowConsoleCursor(bool showFlag) {

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; 
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{   

	ShowConsoleCursor(false);

	Game mainObject;

	while (mainObject.isPlaying) {	

		chrono::steady_clock::time_point now = chrono::steady_clock::now();
		
		if(chrono::duration_cast<chrono::milliseconds>(now - mainObject.timer).count() >= 100) {

			COORD cursorPosition;
			cursorPosition.X = 0;
			cursorPosition.Y = 0;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);

			mainObject.printField();
			mainObject.updateDirection();
			mainObject.moveSnake();
			mainObject.timer = now;
		}
			
	}

	return 0;
} 
