#include "raylib.h"
#include <stdio.h>

#include "modules/check-and-set.h"
#include "modules/cursor.h"
int main() {
	printf("Welcome to OpenPPS!\n");

	check_and_set();
	printf("\n[!] Starting game loop...\n");

	while (!IsKeyPressed(KEY_END)) {
	Vector2 mouse_pos = GetMousePosition();
		BeginDrawing();
		ClearBackground(WHITE);

		draw_cursor((int)mouse_pos.x, (int)mouse_pos.y);
		EndDrawing();
	}
	
	printf("[!] Ending game loop...\n");	
	CloseWindow();
	return 0;
}