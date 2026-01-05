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


#include <stdio.h>
#include <math.h>
#include "raylib.h"

#include "../../config.h"
#include "../subatomic.h"
#include "../atoms.h"

const char* element_symbol[] = {
    "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
};

const char* name[] = {
    "Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen",
    "Oxygen", "Flurine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon",
    "Phosporus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium", "Scandium"
};
void draw_particle_outline (int x, int y) {
    DrawCircleLines(x, y, PROTON_RAD + 1, BLACK);
}
void update_particle(Atom *a, float delta) {
    a->electron_angle += a->orbit_speed * delta;
    if (a->electron_angle > 2 * PI) a->electron_angle -= 2 * PI;
}

void draw_particle(Atom *a) {
// protons here dude
    for (int i = 0; i < a->proton_count; i++) {
        // Use 2.4f (approx 137.5 degrees) for uniform distribution
        float px = a->center.x + sinf(i * 2.4f) * 10.0f; 
        float py = a->center.y + cosf(i * 2.4f) * 10.0f;

        draw_particle_outline((int)px, (int)py);
        draw_proton((int)px, (int)py);
    }

// neutrons here dude
    for (int i = 0; i < a->neutron_count; i++) {
        // Use an offset (+1.0) so neutrons fill the gaps
        float nx = a->center.x + sinf((i + 1.0f) * 2.4f) * 10.0f;
        float ny = a->center.y + cosf((i + 1.0f) * 2.4f) * 10.0f;

        draw_particle_outline((int)nx, (int)ny);
        draw_neutron((int)nx, (int)ny);
    }

    // electrons here
    DrawCircleLinesV(a->center, a->orbit_radius, Fade(GRAY, 0.4f)); // orbit path
                                                            // DrawCircleV(ePos, 4, BLUE); (REFERENCE)
    for (int count = 0; count < a->electron_count; count++) {
        float spacing = (2.0f * PI / a->electron_count) * count;
        float current_angle = a->electron_angle + spacing;

        Vector2 electron_pos = {
            a->center.x + cosf(current_angle) * a->orbit_radius,
            a->center.y + sinf(current_angle) * a->orbit_radius
        };

        draw_electron((int)electron_pos.x, (int)electron_pos.y);
    }
}