/*******************************************************************************
 * OpenPAS (Open Portable Atomic-Chemistry Simulator)                          *
 * Copyright (C) 2026 Ronald Nidera                                            *
 * *
 * This program is free software: you can redistribute it and/or modify        *
 * it under the terms of the GNU General Public License as published by        *
 * the Free Software Foundation, either version 3 of the License, or           *
 * (at your option) any later version.                                         *
 * *
 * Any redistribution of this code MUST retain this copyright notice and       *
 * give credit to the original author: Ronald Nidera.                          *
 *******************************************************************************/

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