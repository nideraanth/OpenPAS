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

#include "../../config.h"
#include "../subatomic.h"

void draw_proton(int x, int y) {
    DrawCircle(x, y, PROTON_RAD, RED);
    // horizontal thick line
    DrawLine(x - PROTON_LABEL_SIZE, y, x + PROTON_LABEL_SIZE, y, BLACK);
    DrawLine(x - PROTON_LABEL_SIZE, y + PARTICLE_LABEL_OFFSET, x + PROTON_LABEL_SIZE, y + PARTICLE_LABEL_OFFSET, BLACK);
    // vertical thick line
    DrawLine(x + PARTICLE_LABEL_OFFSET, y - PROTON_LABEL_SIZE, x, y + PROTON_LABEL_SIZE, BLACK);
    DrawLine(x - PARTICLE_LABEL_OFFSET, y - PROTON_LABEL_SIZE, x, y + PROTON_LABEL_SIZE, BLACK);
}

void draw_neutron(int x, int y) {
    DrawCircle(x, y, NEUTRON_RAD, BLUE);
}

void draw_electron(int x, int y) {
    DrawCircle(x, y, ELECTRON_RAD, YELLOW);
    // horizontal thick line for minus sign
    DrawLine(x - ELECTRON_LABEL_SIZE, y, x + ELECTRON_LABEL_SIZE, y, BLACK);
    DrawLine(x - ELECTRON_LABEL_SIZE, y + PARTICLE_LABEL_OFFSET, x + ELECTRON_LABEL_SIZE, y + PARTICLE_LABEL_OFFSET, BLACK);
}