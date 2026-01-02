#include "raylib.h"

#include "../cursor.h"
void draw_cursor(int x, int y) {
	int size = 60;
	DrawLine(x, y, x + size, y, BLACK);
	DrawLine(x, y, x, y + size, BLACK);

	for (int i = -1; i < size * 1.25; i++) {
		DrawPixel(x + i, y + i, BLACK);
	}
}