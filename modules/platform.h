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


#ifndef PLATFORM_H
#define PLATFORM_H

#if defined(_WIN32)
    #define PLATFORM_NAME "Windows"
    #define IS_WINDOWS 1
#elif defined(__linux__)
    #define PLATFORM_NAME "Linux"
    #define IS_LINUX 1
#elif defined(__APPLE__)
    #define PLATFORM_NAME "macOS"
    #define IS_MACOS 1
#endif

#endif