/*******************************************************************************
 * OpenPAS (OpenSource Portable Atomic-Chemistry Simulator)                    *
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
	int resolution_choice = 0;
	bool is_safemode = false;

	printf("\n=============================================================\n");
	printf("Welcome to OpenPAS!\n");
	printf("OpenPAS v%.2f| (c) 2026 Ronald Nidera | Licensed under GPL v3\n", PROGRAM_VERSION);

	printf("\n Graphics modes: \n 1. Normal mode\n2. Safe mode (640x480 @ 60hz)\n");
	printf("Choice --> ");
	scanf("%i", &resolution_choice);

	if (resolution_choice == 2) {
		is_safemode = true;
	}

	printf("\n\n[ PROGRAM READY! ] .. Press [ENTER] twice.");
	while (getchar() != '\n');
	getchar();
	check_and_set(is_safemode);

	Atom a1 = {{990, 400}, 50.0f, 0.0f, 5.0f, 6, 6, 6};
	Atom a2 = {{250, 700}, 50.0f, 0.0f, 5.0f, 6, 7, 3};
											// E, P, N

	Atom atoms[MAX_ATOMS];
	unsigned int selected_id = 0;
	extern int atoms_count;

	printf("\nPress [END] to exit\n");
	printf("[!] Starting game loop...\n");
	
	while (!IsKeyPressed(KEY_END)) {
	Vector2 mouse_pos = GetMousePosition();		// while we are still in the game, keep fetching the current mouse position

		if (IsKeyPressed(KEY_F1)) {
			selected_id++;
			if (selected_id > CURRENTLY_ADDED_ATOMS) {
				selected_id = 0; 					// switch back to zero
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
			spawn_element(atoms, selected_id, GetMousePosition());
		}


		update_particle(&a1, GetFrameTime());
		update_particle(&a2, GetFrameTime());
		for (int i = 0; i < atoms_count; i++) { update_particle(&atoms[i], GetFrameTime()); }


		BeginDrawing();
		ClearBackground(DARKGRAY);

		DrawText(TextFormat("OpenPAS v%.2f\n", PROGRAM_VERSION), 0, 0, 17, RAYWHITE);
		DrawText(TextFormat("X: %i    Y: %i\n", (int)mouse_pos.x, (int)mouse_pos.y), 0, 25, 15, RAYWHITE);
		DrawText("(c) 2026 Ronald Nidera | Licensed under GPL v3", 0, 40, 15, DARKGREEN);
		DrawText(TextFormat("Current element: %i \n(By atomic number)\n", (int)selected_id), 0, 60, 15, RED);

		draw_proton(CENTER_X, CENTER_Y);
		draw_neutron(CENTER_X + 20, CENTER_Y);
		draw_electron(CENTER_X + 40, CENTER_Y);

		draw_particle(&a1);
		draw_particle(&a2);

		for (int i = 0; i < atoms_count; i++) { draw_particle(&atoms[i]); } // draw atoms
		draw_cursor((int)mouse_pos.x, (int)mouse_pos.y);	// draw the cursor, cast the flaot values so it does not get corrupted

		EndDrawing();
	}
	
	printf("[!] Ending game loop...\n");	// stop all game activity after this point
	CloseWindow();
	return 0;
}