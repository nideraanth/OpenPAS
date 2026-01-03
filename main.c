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

#include "modules/platform.h"
#include "modules/check-and-set.h"
#include "modules/cursor.h"

#include "modules/subatomic.h"

#include "config.h"
bool check_platform() {
	#ifdef __linux__ 
		printf("[!] Initial Linux check passed. [ Proceed ]\n");
		return true;
	#else 
		// If we are NOT on Linux, this code is "seen" instead
		printf("==============================================================\n");
		printf("[!] Warning: Non-Linux OS detected. Performance may vary.\n");
		printf("OpenPAS v0.07| (c) 2026 Ronald Nidera | Licensed under GPL v3\n\n");
		printf("==============================================================\n");
        printf("OpenPAS V0.07 is currently optimized for Linux (Ubuntu/Debian).\n");
        printf("Press [ENTER] TWICE to continue\n\n\n");

        while (getchar() != '\n');
        getchar();		// wait until a key is pressed (ENTER)
        return true;
    #endif
}

int main() {
	if (!check_platform()) { return 1; }	// check if we are on Linux, if not, go back to check_platform()'s else section

	printf("\n=============================================================\n");
	printf("Welcome to OpenPPS!\n");
	printf("OpenPAS v0.07| (c) 2026 Ronald Nidera | Licensed under GPL v3\n");

	check_and_set();
	printf("\n[!] Starting game loop...\n");

	while (!IsKeyPressed(KEY_END)) {
	Vector2 mouse_pos = GetMousePosition();		// while we are still in the game, keep fetching the current mouse position
		BeginDrawing();
		ClearBackground(DARKGRAY);

		draw_proton(CENTER_X, CENTER_Y);
		draw_neutron(CENTER_X + 20, CENTER_Y);
		draw_electron(CENTER_X + 40, CENTER_Y);
		draw_cursor((int)mouse_pos.x, (int)mouse_pos.y);	// draw the cursor, cast the flaot values so it does not get corrupted
		EndDrawing();
	}
	
	printf("[!] Ending game loop...\n");	// stop all game activity after this point
	CloseWindow();
	return 0;
}