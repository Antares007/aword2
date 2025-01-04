#include "Dependencies/Raylib/include/raylib.h"
int main2()
{
  SetTraceLogLevel(LOG_ERROR);
	InitWindow(720, 480, "Game");
	while (!WindowShouldClose())
	{
		// UpdateGame();
		BeginDrawing();
		ClearBackground(WHITE);
		// DrawGame();
		DrawRectangle(10, 10, 100, 100, RED);
		EndDrawing();
	}
	CloseWindow();
  return 0;
}
