/*******************************************************************************
 * OpenPAS (Open Portable Atomic-Chemistry Simulator)                          *
 * OpenPAS (OpenSource Portable Atomic-Chemistry Simulator)                    *
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

const Atom ELEMENT_DEFAULTS[] = {
    // { {pos}, orbit, angle, speed, e, p, n }
    { {0,0}, 60.0f,  0.0f, 5.0f, 1, 1, 0   }, // 0: H
    { {0,0}, 60.0f,  0.0f, 5.0f, 2, 2, 2   }, // 1: He
    { {0,0}, 85.0f,  0.0f, 4.0f, 3, 3, 4   }, // 2: Li
    { {0,0}, 85.0f,  0.0f, 4.0f, 4, 4, 5   }, // 3: Be
    { {0,0}, 95.0f,  0.0f, 3.5f, 5, 5, 6   }, // 4: B
    { {0,0}, 95.0f,  0.0f, 3.5f, 6, 6, 6   }, // 5: C
    { {0,0}, 110.0f, 0.0f, 3.0f, 7, 7, 7   }, // 6: N
    { {0,0}, 110.0f, 0.0f, 3.0f, 8, 8, 8   }, // 7: O
    { {0,0}, 125.0f, 0.0f, 2.5f, 9, 9, 10  }, // 8: F
    { {0,0}, 125.0f, 0.0f, 2.5f, 10, 10, 10}, // 9: Ne
    { {0,0}, 145.0f, 0.0f, 2.2f, 11, 11, 12}, // 10: Na
    { {0,0}, 145.0f, 0.0f, 2.2f, 12, 12, 12}, // 11: Mg
    { {0,0}, 160.0f, 0.0f, 2.0f, 13, 13, 14}, // 12: Al
    { {0,0}, 160.0f, 0.0f, 2.0f, 14, 14, 14}, // 13: Si
    { {0,0}, 175.0f, 0.0f, 1.8f, 15, 15, 16}, // 14: P
    { {0,0}, 175.0f, 0.0f, 1.8f, 16, 16, 16}, // 15: S
    { {0,0}, 190.0f, 0.0f, 1.7f, 17, 17, 18}, // 16: Cl
    { {0,0}, 190.0f, 0.0f, 1.7f, 18, 18, 22}, // 17: Ar
    { {0,0}, 210.0f, 0.0f, 1.5f, 19, 19, 20}, // 18: K
    { {0,0}, 210.0f, 0.0f, 1.5f, 20, 20, 20}, // 19: Ca
    { {0,0}, 225.0f, 0.0f, 1.4f, 21, 21, 24}, // 20: Sc
    { {0,0}, 225.0f, 0.0f, 1.4f, 22, 22, 26}, // 21: Ti
    { {0,0}, 240.0f, 0.0f, 1.3f, 23, 23, 28}, // 22: V
    { {0,0}, 240.0f, 0.0f, 1.3f, 24, 24, 28}, // 23: Cr
    { {0,0}, 255.0f, 0.0f, 1.2f, 25, 25, 30}, // 24: Mn
    { {0,0}, 255.0f, 0.0f, 1.2f, 26, 26, 30}, // 25: Fe
    { {0,0}, 270.0f, 0.0f, 1.1f, 27, 27, 32}, // 26: Co
    { {0,0}, 270.0f, 0.0f, 1.1f, 28, 28, 31}, // 27: Ni
    { {0,0}, 285.0f, 0.0f, 1.0f, 29, 29, 35}, // 28: Cu
    { {0,0}, 285.0f, 0.0f, 1.0f, 30, 30, 35}, // 29: Zn
    { {0,0}, 300.0f, 0.0f, 0.9f, 31, 31, 39}, // 30: Ga
    { {0,0}, 300.0f, 0.0f, 0.9f, 32, 32, 41}, // 31: Ge
    { {0,0}, 315.0f, 0.0f, 0.8f, 33, 33, 42}, // 32: As
    { {0,0}, 315.0f, 0.0f, 0.8f, 34, 34, 45}, // 33: Se
    { {0,0}, 330.0f, 0.0f, 0.8f, 35, 35, 45}, // 34: Br
    { {0,0}, 330.0f, 0.0f, 0.8f, 36, 36, 48}, // 35: Kr
    { {0,0}, 345.0f, 0.0f, 0.7f, 37, 37, 48}, // 36: Rb
    { {0,0}, 345.0f, 0.0f, 0.7f, 38, 38, 50}, // 37: Sr
    { {0,0}, 360.0f, 0.0f, 0.7f, 39, 39, 50}, // 38: Y
    { {0,0}, 360.0f, 0.0f, 0.7f, 40, 40, 51}, // 39: Zr
    { {0,0}, 375.0f, 0.0f, 0.6f, 41, 41, 52}, // 40: Nb
    { {0,0}, 375.0f, 0.0f, 0.6f, 42, 42, 54}, // 41: Mo
    { {0,0}, 390.0f, 0.0f, 0.6f, 43, 43, 55}, // 42: Tc
    { {0,0}, 390.0f, 0.0f, 0.6f, 44, 44, 58}, // 43: Ru
    { {0,0}, 405.0f, 0.0f, 0.5f, 45, 45, 58}, // 44: Rh
    { {0,0}, 405.0f, 0.0f, 0.5f, 46, 46, 60}, // 45: Pd
    { {0,0}, 420.0f, 0.0f, 0.5f, 47, 47, 61}, // 46: Ag
    { {0,0}, 420.0f, 0.0f, 0.5f, 48, 48, 64}, // 47: Cd
    { {0,0}, 435.0f, 0.0f, 0.4f, 49, 49, 66}, // 48: In
    { {0,0}, 435.0f, 0.0f, 0.4f, 50, 50, 69}, // 49: Sn
    { {0,0}, 450.0f, 0.0f, 0.4f, 51, 51, 71}, // 50: Sb
    { {0,0}, 450.0f, 0.0f, 0.4f, 52, 52, 76}, // 51: Te
    { {0,0}, 465.0f, 0.0f, 0.3f, 53, 53, 74}, // 52: I
    { {0,0}, 465.0f, 0.0f, 0.3f, 54, 54, 77}, // 53: Xe
    { {0,0}, 480.0f, 0.0f, 0.3f, 55, 55, 78}, // 54: Cs
    { {0,0}, 480.0f, 0.0f, 0.3f, 56, 56, 81}, // 55: Ba
    { {0,0}, 495.0f, 0.0f, 0.3f, 57, 57, 82}, // 56: La
    { {0,0}, 495.0f, 0.0f, 0.3f, 58, 58, 82}, // 57: Ce
    { {0,0}, 510.0f, 0.0f, 0.2f, 59, 59, 82}, // 58: Pr
    { {0,0}, 510.0f, 0.0f, 0.2f, 60, 60, 84}, // 59: Nd
    { {0,0}, 525.0f, 0.0f, 0.2f, 61, 61, 84}, // 60: Pm
    { {0,0}, 525.0f, 0.0f, 0.2f, 62, 62, 88}, // 61: Sm
    { {0,0}, 540.0f, 0.0f, 0.2f, 63, 63, 89}, // 62: Eu
    { {0,0}, 540.0f, 0.0f, 0.2f, 64, 64, 93}, // 63: Gd
    { {0,0}, 555.0f, 0.0f, 0.2f, 65, 65, 94}, // 64: Tb
    { {0,0}, 555.0f, 0.0f, 0.2f, 66, 66, 97}, // 65: Dy
    { {0,0}, 570.0f, 0.0f, 0.1f, 67, 67, 98}, // 66: Ho
    { {0,0}, 570.0f, 0.0f, 0.1f, 68, 68, 99}, // 67: Er
    { {0,0}, 585.0f, 0.0f, 0.1f, 69, 69, 100}, // 68: Tm
    { {0,0}, 585.0f, 0.0f, 0.1f, 70, 70, 103}, // 69: Yb
    { {0,0}, 600.0f, 0.0f, 0.1f, 71, 71, 104}, // 70: Lu
    { {0,0}, 600.0f, 0.0f, 0.1f, 72, 72, 106}, // 71: Hf
    { {0,0}, 615.0f, 0.0f, 0.1f, 73, 73, 108}, // 72: Ta
    { {0,0}, 615.0f, 0.0f, 0.1f, 74, 74, 110}, // 73: W
    { {0,0}, 630.0f, 0.0f, 0.1f, 75, 75, 111}, // 74: Re
    { {0,0}, 630.0f, 0.0f, 0.1f, 76, 76, 114}, // 75: Os
    { {0,0}, 645.0f, 0.0f, 0.1f, 77, 77, 115}, // 76: Ir
    { {0,0}, 645.0f, 0.0f, 0.1f, 78, 78, 117}, // 77: Pt
    { {0,0}, 660.0f, 0.0f, 0.1f, 79, 79, 118}, // 78: Au
    { {0,0}, 660.0f, 0.0f, 0.1f, 80, 80, 121}, // 79: Hg
    { {0,0}, 675.0f, 0.0f, 0.1f, 81, 81, 123}, // 80: Tl
    { {0,0}, 675.0f, 0.0f, 0.1f, 82, 82, 125}, // 81: Pb
    { {0,0}, 690.0f, 0.0f, 0.1f, 83, 83, 126}, // 82: Bi
    { {0,0}, 690.0f, 0.0f, 0.1f, 84, 84, 125}, // 83: Po
    { {0,0}, 705.0f, 0.0f, 0.1f, 85, 85, 125}, // 84: At
    { {0,0}, 705.0f, 0.0f, 0.1f, 86, 86, 136}, // 85: Rn
    { {0,0}, 720.0f, 0.0f, 0.1f, 87, 87, 136}, // 86: Fr
    { {0,0}, 720.0f, 0.0f, 0.1f, 88, 88, 138}, // 87: Ra
    { {0,0}, 735.0f, 0.0f, 0.1f, 89, 89, 138}, // 88: Ac
    { {0,0}, 735.0f, 0.0f, 0.1f, 90, 90, 142}, // 89: Th
    { {0,0}, 750.0f, 0.0f, 0.1f, 91, 91, 140}, // 90: Pa
    { {0,0}, 750.0f, 0.0f, 0.1f, 92, 92, 146}, // 91: U
    { {0,0}, 765.0f, 0.0f, 0.1f, 93, 93, 144}, // 92: Np
    { {0,0}, 765.0f, 0.0f, 0.1f, 94, 94, 150}, // 93: Pu
    { {0,0}, 780.0f, 0.0f, 0.1f, 95, 95, 148}, // 94: Am
    { {0,0}, 780.0f, 0.0f, 0.1f, 96, 96, 151}, // 95: Cm
    { {0,0}, 795.0f, 0.0f, 0.1f, 97, 97, 150}, // 96: Bk
    { {0,0}, 795.0f, 0.0f, 0.1f, 98, 98, 153}, // 97: Cf
    { {0,0}, 810.0f, 0.0f, 0.1f, 99, 99, 153}, // 98: Es
    { {0,0}, 810.0f, 0.0f, 0.1f, 100, 100, 157}, // 99: Fm
    { {0,0}, 825.0f, 0.0f, 0.1f, 101, 101, 157}, // 100: Md
    { {0,0}, 825.0f, 0.0f, 0.1f, 102, 102, 157}, // 101: No
    { {0,0}, 840.0f, 0.0f, 0.1f, 103, 103, 159}, // 102: Lr
    { {0,0}, 840.0f, 0.0f, 0.1f, 104, 104, 163}, // 103: Rf
    { {0,0}, 855.0f, 0.0f, 0.1f, 105, 105, 163}, // 104: Db
    { {0,0}, 855.0f, 0.0f, 0.1f, 106, 106, 165}, // 105: Sg
    { {0,0}, 870.0f, 0.0f, 0.1f, 107, 107, 163}, // 106: Bh
    { {0,0}, 870.0f, 0.0f, 0.1f, 108, 108, 169}, // 107: Hs
    { {0,0}, 885.0f, 0.0f, 0.1f, 109, 109, 169}, // 108: Mt
    { {0,0}, 885.0f, 0.0f, 0.1f, 110, 110, 171}, // 109: Ds
    { {0,0}, 900.0f, 0.0f, 0.1f, 111, 111, 171}, // 110: Rg
    { {0,0}, 900.0f, 0.0f, 0.1f, 112, 112, 173}, // 111: Cn
    { {0,0}, 915.0f, 0.0f, 0.1f, 113, 113, 173}, // 112: Nh
    { {0,0}, 915.0f, 0.0f, 0.1f, 114, 114, 175}, // 113: Fl
    { {0,0}, 925.0f, 0.0f, 0.1f, 115, 115, 175}, // 114: Mc
    { {0,0}, 925.0f, 0.0f, 0.1f, 116, 116, 177}, // 115: Lv
    { {0,0}, 940.0f, 0.0f, 0.1f, 117, 117, 177}, // 116: Ts
    { {0,0}, 940.0f, 0.0f, 0.1f, 118, 118, 176}  // 117: Og
};

Atom atoms[100];
int atoms_count = 0;

void draw_particle_outline (int x, int y) {
    DrawCircleLines(x, y, PROTON_RAD + 1, BLACK);
}
void update_particle(Atom *a, float delta) {
    a->electron_angle += a->orbit_speed * delta;
    if (a->electron_angle > 2 * PI) a->electron_angle -= 2 * PI;
}

void draw_particle(Atom *a) {
int total_nucleus = a->proton_count + a->neutron_count;
    
    // For visibility and "pocketing", separation must be diameter.
    // Since PROTON_RAD is 10.0f, 20.0f makes them touch at the edge.
    float sep = (PROTON_RAD * 2.0f); 

    for (int i = 0; i < total_nucleus; i++) {
        float x = a->center.x;
        float y = a->center.y;

        if (i > 0) {
            // Hexagonal "Spiral" index to Axial coordinates
            // This fills the nucleus in a way that every particle sits 
            // at the convergence of 2 or 3 others.
            int layer = 0;
            int range = 0;
            while (i > 3 * layer * (layer + 1)) layer++;

            int side = (i - (3 * (layer - 1) * layer) - 1) / layer;
            int pos  = (i - (3 * (layer - 1) * layer) - 1) % layer;

            // Base angles for the 6 hexagonal directions
            float angle1 = side * (PI / 3.0f);
            float angle2 = (side + 2) * (PI / 3.0f);

            // Vector math to find the "Convergence Point"
            // This is the "Venn Diagram" logic: particle sits between neighbors
            float dx = cosf(angle1) * layer + cosf(angle2) * pos;
            float dy = sinf(angle1) * layer + sinf(angle2) * pos;

            x += dx * sep;
            y += dy * sep;
        }

        draw_particle_outline((int)x, (int)y);
        
        if (i < a->proton_count) {
            draw_proton((int)x, (int)y);
        } else {
            draw_neutron((int)x, (int)y);
        }
    }

    // --- Electrons (Standard Scale) ---
    DrawCircleLinesV(a->center, a->orbit_radius, Fade(GRAY, 0.4f)); 
    for (int count = 0; count < a->electron_count; count++) {
        float spacing = (2.0f * PI / a->electron_count) * count;
        float current_angle = a->electron_angle + spacing;

        Vector2 ePos = {
            a->center.x + cosf(current_angle) * a->orbit_radius,
            a->center.y + sinf(current_angle) * a->orbit_radius
        };
        draw_electron((int)ePos.x, (int)ePos.y);
    }
}

void spawn_element(Atom *a, int id, Vector2 element_center) {
    if (atoms_count >= MAX_ATOMS) { 
        printf("[ERR]: Cannot spawn more atoms, already reached the limit.\n if your computer can handle it... change MAX_ATOMS in config.h\n and recompile");
        return;
    }

    a[atoms_count] = ELEMENT_DEFAULTS[id];
    a[atoms_count].center = element_center;

    (atoms_count)++;
}