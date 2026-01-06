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


#ifndef ATOMS_H
#define ATOMS_H

#include "raylib.h"

typedef struct {
    Vector2 center;
    const char* element_symbol;
    const char* name;
} Element;

typedef struct {
    Vector2 center;
    float orbit_radius;
    float electron_angle;
    float orbit_speed;

    int electron_count;
    int proton_count;
    int neutron_count;
} Atom; // Capitalized for consistency

void update_particle(Atom *a, float delta);
void draw_particle(Atom *a);
void spawn_element(Atom *a, int id, Vector2 element_center);

#endif