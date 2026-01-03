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

#include "../cursor.h"
void draw_cursor(int x, int y) {
	int size = 60;
	DrawLine(x, y, x + size, y, WHITE);
	DrawLine(x, y, x, y + size, WHITE);

	for (int i = -1; i < size * 1.25; i++) {
		DrawPixel(x + i, y + i, WHITE);
	}
}