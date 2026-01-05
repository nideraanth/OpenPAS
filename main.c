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
#include "modules/atoms.h"

#include "config.h"
bool check_platform() {
	#ifdef __linux__ 
		printf("[!] Initial Linux check passed. [ Proceed ]\n");
		return true;
	#else 
		// If we are NOT on Linux, this code is "seen" instead
		printf("==============================================================\n");
		printf("[!] Warning: Non-Linux OS detected. Performance may vary.\n");
		printf("OpenPAS v%.2f| (c) 2026 Ronald Nidera | Licensed under GPL v3\n\n", PROGRAM_VERSION);
		printf("==============================================================\n");
        printf("OpenPAS V%.2f is currently optimized for Linux (Ubuntu/Debian).\nand Windows x86-64 with w64devkit\n", PROGRAM_VERSION);
        printf("Press [ENTER] TWICE to continue\n\n\n");

        while (getchar() != '\n');
        getchar();		// wait until a key is pressed (ENTER)
        return true;
    #endif
}

int main() {
	if (!check_platform()) { return 1; }	// check if we are on Linux, if not, go back to check_platform()'s else section

	printf("\n=============================================================\n");
	printf("Welcome to OpenPAS!\n");
	printf("OpenPAS v%.2f| (c) 2026 Ronald Nidera | Licensed under GPL v3\n", PROGRAM_VERSION);

	printf("\n\n[ PROGRAM READY! ] .. Press [ENTER] twice.");
	while (getchar() != '\n');
	getchar();


	check_and_set();
	Atom a1 = {{990, 400}, 50.0f, 0.0f, 5.0f, 3, 1, 1};
	Atom a2 = {{250, 700}, 50.0f, 0.0f, 5.0f, 3, 1, 1};
											// E, P, N
	printf("\nPress [END] to exit\n");
	printf("[!] Starting game loop...\n");
	
	while (!IsKeyPressed(KEY_END)) {
	Vector2 mouse_pos = GetMousePosition();		// while we are still in the game, keep fetching the current mouse position

		update_particle(&a1, GetFrameTime());
		update_particle(&a2, GetFrameTime());
		BeginDrawing();
		ClearBackground(DARKGRAY);

		DrawText(TextFormat("OpenPAS v%.2f", PROGRAM_VERSION), 0, 0, 20, RAYWHITE);
		draw_proton(CENTER_X, CENTER_Y);
		draw_neutron(CENTER_X + 20, CENTER_Y);
		draw_electron(CENTER_X + 40, CENTER_Y);

		draw_particle(&a1);
		draw_particle(&a2);
		draw_cursor((int)mouse_pos.x, (int)mouse_pos.y);	// draw the cursor, cast the flaot values so it does not get corrupted
		EndDrawing();
	}
	
	printf("[!] Ending game loop...\n");	// stop all game activity after this point
	CloseWindow();
	return 0;
}