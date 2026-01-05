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
void update_particle(Atom *a, float delta) {
    a->electron_angle += a->orbit_speed * delta;
    if (a->electron_angle > 2 * PI) a->electron_angle -= 2 * PI;
}

void draw_particle(Atom a) {
    for (int quant = 0; quant <= a.proton_count; quant++) {
        float offset_x = sinf(quant * 1.0f) * 5.0f;
        float offset_y = sinf(quant * 1.0f) * 5.0f;
        draw_proton((int)a.center.x, (int)a.center.y); 
    }
    // note: it is Fade(), not FADE() nor fade()
    DrawCircleLinesV(a.center, a.orbit_radius, Fade(GRAY, 0.3f)); // orbit path
                                                            // DrawCircleV(ePos, 4, BLUE); (REFERENCE)
    for (int count = 0; count < a.electron_count; count++) {
        float individual_angle = a.electron_angle + cosf(individual_angle) * a.orbit_radius;
        Vector2 electron_pos = {
            a.center.x + cosf(a.electron_angle) * a.orbit_radius,
            a.center.y + sinf(a.electron_angle) * a.orbit_radius
        };

        draw_electron((int)electron_pos.x, (int)electron_pos.y);
    }
}