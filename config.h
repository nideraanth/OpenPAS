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

#ifndef CONFIG_H
#define CONFIG_H

#define PROGRAM_TITLE "OpenPAS"

#define DEFAULT_RESOLUTION_HORIZONTAL 1280
#define DEFAULT_RESOLUTION_VERTICAL 800

#define DEFAULT_TRACE_LOG_LEVEL LOG_WARNING
#define HIDE_CURSOR true
#define DEFAULT_FRAMERATE 60

// --- Physical Radii ---
#define PROTON_RAD 10.0f
#define NEUTRON_RAD 10.5f
#define ELECTRON_RAD 3.0f

// --- Magic Numbers replaced by Macros ---
#define PROTON_LABEL_SIZE 6      // Replaces the '6'
#define ELECTRON_LABEL_SIZE 2    // Replaces the '2'
#define PARTICLE_LABEL_OFFSET 1  // Replaces the '+1' and '-1' thickness/offset

// --- Fixed Label Sizes ---
// Set to 6 and 2 to match the hardcoded lines in your drawing module
#define PROTON_LABEL_SIZE 6
#define ELECTRON_LABEL_SIZE 2 

// --- Positioning Constants ---
#define PARTICLE_LABEL_OFFSET 1
#define TEXT_SIZE 20
#define CENTER_X (DEFAULT_RESOLUTION_HORIZONTAL / 2)
#define CENTER_Y (DEFAULT_RESOLUTION_VERTICAL / 2)

#endif